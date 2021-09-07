// Copyright (C) 2021  Lian Studer
// See the LICENSE file for more information.

#define XHK_DEBUG
#define _GNU_SOURCE
 
// Locales
// -------------------
#define XK_MISCELLANY
#define XK_XKB_KEYS
#define XK_LATIN1
#define XK_LATIN2
#define XK_LATIN3
#define XK_LATIN4
// -------------------

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>
#include <signal.h>
#include <string.h>

#include <xcb/xcb.h>
#include <xcb/xcb_event.h>
#include <xcb/xcb_keysyms.h>
#include <xcb/xproto.h>
#include <X11/keysymdef.h>

#include "xhk.h"
#include "util.h"
#include "types.h"
#include "../config.h"

bool running = false;
bool grabbed = false;

xcb_connection_t *dpy;
xcb_window_t root;
xcb_key_symbols_t *syms;

int main(int argc, char **argv) {
    parse_args(&argc, argv);
    signal_handlers();

    xhk_setup();
    grab_keybd();
    running = true;


    xcb_generic_event_t *event;
    xcb_flush(dpy);

    while (running) {

        ASSERT(!xcb_connection_has_error(dpy));

        while ((event = xcb_poll_for_event(dpy)) != NULL) {
            PUTS("Received X event");
            uint8_t event_type = XCB_EVENT_RESPONSE_TYPE(event);
            switch (event_type) {
                case XCB_KEY_PRESS:
                case XCB_KEY_RELEASE:
                    PRINTF("Event: %u\n", event_type);
                    break;
            }
            free(event);
        }
    }

    stop_daemon();
    ungrab_keybd();
    return EXIT_SUCCESS;
}

void parse_args(int *argc, char **argv) {
    int option;
    while((option = getopt((*argc), argv, ":h")) != -1)
    {
        switch(option)
        {
        case 'h':
            printf(
                "\nxhk v%s \n\n"
                "Copyright (C) 2021 Lian Studer\n"
                "xhk comes with ABSOLUTELY NO WARRANTY. This is free software,\n"
                "and you are welcome to redistribute it under the conditions\n"
                "of the GNU General Public License version 2.\n\n", 
            VERSION);
            exit(EXIT_SUCCESS);
            break;
        case '?':
            printf("Unknown option %c. See 'xhk -h' for help.\n", option);
            exit(EXIT_FAILURE);
            break;
        }
    }
}

void xhk_setup() {
    int screen_idx;
    dpy = xcb_connect(NULL, &screen_idx);
    ASSERT(!xcb_connection_has_error(dpy));
    PUTS("Connected to X server");

    xcb_screen_t *sc = NULL;
    xcb_screen_iterator_t iter = xcb_setup_roots_iterator(xcb_get_setup(dpy));
    for (; iter.rem; xcb_screen_next(&iter), screen_idx--) {
        if (screen_idx != 0)
            continue;
        sc = iter.data;
        break;
    }

    ASSERT(sc != NULL);
    root = sc->root;
    PUTS("Aquired screen from X server");

    syms = xcb_key_symbols_alloc(dpy);
    PUTS("Allocated X11 keysyms");
}

void stop_daemon() {
    xcb_flush(dpy);
    xcb_key_symbols_free(syms);
    xcb_disconnect(dpy);
    PUTS("Connection to X server closed");
}

void signal_handlers() {
    signal(SIGTERM, interrupt);
    signal(SIGINT, interrupt);
    signal(SIGHUP, interrupt);
}

void interrupt(int sig) {
    switch(sig) {
        case SIGTERM:
        case SIGINT:
        case SIGHUP:
            running = false;
            PRINTF("%s: Terminating\n", signal_abbrv(sig));
            break;
        default:
            PRINTF("%s(%i): Ignoring\n", signal_abbrv(sig), sig);
            break;
    }
}

char *signal_abbrv(int sig) {
    switch(sig) {
        case 15: // SIGTERM
            return "SIGTERM";
        case 2: // SIGINT
            return "SIGINT";
        case 1: // SIGHUP
            return "SIGHUP";
        default:
            return "UNDEF";

    }
}

void grab_keybd() {

    xcb_void_cookie_t cookie;
    
    for (int i = 0; i < COUNT(hotkeys); i++) {
        
        PRINTF("Grabbing keys - Modifiers: %i; Keysym: %i\n", hotkeys[i].modifiers, hotkeys[i].keysym);
        
        cookie = xcb_grab_key_checked(dpy, true, root, hotkeys[i].modifiers, 
        SYMTOKEY(hotkeys[i].keysym), XCB_GRAB_MODE_ASYNC, XCB_GRAB_MODE_ASYNC);
        
        xcb_generic_error_t *err;
        err = xcb_request_check(dpy, cookie);
        if (err != NULL) {
            if (err->error_code == XCB_ACCESS)
                xhk_err("Keycombination is already grabbed.");
            else
                xhk_err("Error: %u\n", err->error_code);
        }
    }

    grabbed = true;
    PUTS("Grabbed keybindings");
}

void ungrab_keybd() {
    xcb_ungrab_key(dpy, XCB_GRAB_ANY, root, XCB_BUTTON_MASK_ANY);
    xcb_flush(dpy);
    grabbed = false;
    PUTS("Ungrabbed keybindings");
}

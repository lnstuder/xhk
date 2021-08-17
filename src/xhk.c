// xhk X11 hotkey daemon
// Copyright (C) 2021  Lian Studer

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 
// as published by the Free Software Foundation;

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this program; if not, you can find the full license text in the LICENSE file.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <syslog.h>
#include <getopt.h>
#include <stdbool.h>

#include <xcb/xcb.h>
#include <xcb/xcb_event.h>
#include <xcb/xcb_keysyms.h>
#include <xcb/xproto.h>

#include "xhk.h"
#include "types.h"

// User configuration
#include "../config.h"

xcb_connection_t *con;
xcb_window_t root;
xcb_key_symbols_t *symbols;

bool running, reload;

int main(int argc, char **argv)
{
    signal(SIGHUP, interrupt);
    signal(SIGINT, interrupt);

    // Parse command line arguments
    parse_args(&argc, argv);

    setup();
    grab();
    running = true;
    syslog(LOG_NOTICE, "Started daemon");

    // fs_set descriptors;

    // xcb_generic_event_t *event;
    xcb_flush(con);

    // while (running)
    // {
    //     // FD_ZERO(&descriptors);
	// 	// FD_SET(fd, &descriptors);

	// 	// if (select(fd + 1, &descriptors, NULL, NULL, NULL) > 0) {
	// 		while ((event = xcb_poll_for_event(con)) != NULL) {
	// 			uint8_t event_type = XCB_EVENT_RESPONSE_TYPE(event);
	// 			switch (event_type) {
	// 				case XCB_KEY_PRESS:
	// 				case XCB_KEY_RELEASE:
	// 				case XCB_BUTTON_PRESS:
	// 				case XCB_BUTTON_RELEASE:
	// 					keyboard_event_callback(event, event_type);
	// 					break;

	// 				default:
	// 					printf("received event %u\n", event_type);
	// 					break;
	// 			}
	// 			free(event);
	// 		}
	// 	// }
    // }

    xcb_ungrab_key(con, XCB_GRAB_ANY, root, XCB_BUTTON_MASK_ANY);
    xcb_flush(con);

    closelog();
    xcb_disconnect(con);
    return EXIT_SUCCESS;
}

void parse_args(int *argc, char **argv)
{
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

void setup()
{
    int screen_idx;
    con = xcb_connect(NULL, &screen_idx);
    if (xcb_connection_has_error(con))
        exit(EXIT_FAILURE);
    xcb_screen_t *screen = NULL;
    xcb_screen_iterator_t iter = xcb_setup_roots_iterator(xcb_get_setup(con));
    for (; iter.rem; xcb_screen_next(&iter), screen_idx--) {
        if (screen_idx == 0) {
            screen = iter.data;
            break;
        }
    }

    if (screen == NULL)
        exit(EXIT_FAILURE);
    
    root = screen->root;
    symbols = xcb_key_symbols_alloc(con);

    openlog("xhk", LOG_PID, LOG_DAEMON);
}

void interrupt(int sig)
{
    if (sig == SIGHUP)
        reload = true;
    else if (sig == SIGTERM)
        running = false;
}

void grab() 
{
    // xcb_generic_error_t *err;
    for (int i = 0; i < sizeof(hotkeys) / sizeof(hotkey_t); i++)
    {
        printf("%d\n", hotkeys[i].keysym);
        xcb_keycode_t keycode;
        // keycode = xcb_key_symbols_get_keysym(symbols, hotkeys[i].keysym);
        // err = xcb_request_check(con, xcb_grab_key_checked(con, true, root, hotkeys[i].modfield, keycode, XCB_GRAB_MODE_ASYNC, XCB_GRAB_MODE_SYNC));
        // if (err != NULL)
        // {
        //     printf("ERROR COULD NOT GRAB");
        // }
        // free(err);
    }
    xcb_flush(con);
}

void keyboard_event_callback(xcb_generic_event_t *event, uint8_t event_type)
{
    syslog(LOG_NOTICE, "KEY EVENT");
    // Event handler for key/button events
}


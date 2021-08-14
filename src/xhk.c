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

#include "xhk.h"

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

#include "types.h"

// User configuration
#include "../config.h"

xcb_connection_t *con;
bool running;

int main(int argc, char **argv)
{
    sigaction(SIGHUP, interrupt)

    // Parse command line arguments
    parse_args(&argc, argv);
    running = true;

    int fd = xcb_get_file_descriptor(con);
    fs_set descriptors;

    xcb_generic_event_t *event;
    xcb_flush(con);

    while (running)
    {
        FD_ZERO(&descriptors);
		FD_SET(fd, &descriptors);

		if (select(fd + 1, &descriptors, NULL, NULL, NULL) > 0) {
			while ((event = xcb_poll_for_event(con)) != NULL) {
				uint8_t event_type = XCB_EVENT_RESPONSE_TYPE(event);
				switch (event_type) {
					case XCB_KEY_PRESS:
					case XCB_KEY_RELEASE:
					case XCB_BUTTON_PRESS:
					case XCB_BUTTON_RELEASE:
						key_button_event(event, event_type);
						break;

					default:
						printf("received event %u\n", event_type);
						break;
				}
				free(event);
			}
		}
    }

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
            exit(0);
            break;
        case '?':
            printf("Unknown option %c. See 'xhk -h' for help.\n", option);
            exit(1);
            break;
        }
    }
}

void setup()
{
    con = xcb_connect(NULL, NULL);
    xcb_screen_t *screen = xcb_setup_root
}

void interrupt(int sig)
{
    if (sig == SIGHUP)
        reload = true;
    else if (sig == SIGTERM)
        running = false;
}

void key_button_event(xcb_generic_event_t event, uint8_t event_type)
{
    // Event handler for key/button events
}

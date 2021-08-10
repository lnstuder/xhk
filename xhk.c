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
#include <getopt.h>

#include <xcb/xcb.h>


/* TODO:
 * receive keystrokes
 * hotkeys / key combinations
 * run as a daemon
 * configure hotkeys and actions with chainscript / config files
 *
*/

void setup_daemon()
{
    printf("Setting up xhk daemon...\n");
}

void parse_args(int *argc, char **argv)
{
    int option;
    while((option = getopt((*argc), argv, ":hd")) != -1)
    {
        switch(option)
        {
        case 'h':
            print_info();
            break;
        case 'd':
            setup_daemon();
            break;
        case '?':
            printf("Unknown option %c. See 'xhk -h' for help.\n", option);
            break;
        }
    }
}

int main(int argc, char **argv)
{
    parse_args(&argc, argv);
    return 0;
}

void print_info()
{
    printf(
        "\nxhk v%s \n\n"
        "Copyright (C) 2021 Lian Studer\n"
        "xhk comes with ABSOLUTELY NO WARRANTY. This is free software,\n"
        "and you are welcome to redistribute it under the conditions\n"
        "of the GNU General Public License version 2.\n\n", 
    VERSION);
}

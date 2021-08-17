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

#ifndef XHK_XHK_H
#define XHK_XHK_H

void parse_args(int *, char **);
void setup();
void interrupt(int);
void grab();
void keyboard_event_callback(xcb_generic_event_t *, uint8_t);
xcb_keycode_t *keycodes_from_keysym(xcb_keysym_t);

#endif
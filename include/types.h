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

#ifndef XHK_TYPES_H
#define XHK_TYPES_H

typedef struct hotkey_t {
    uint16_t modfield;
    xcb_keysym_t keysym;
    uint8_t event_type;
    void (*routine)();
} hotkey_t;

#endif

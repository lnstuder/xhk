// Copyright (C) 2021  Lian Studer
// See the LICENSE file for more information.

#ifndef XHK_TYPES_H
#define XHK_TYPES_H

struct hotkey_t {
    uint16_t modifier;
    xcb_keysym_t keysym;
};

#endif
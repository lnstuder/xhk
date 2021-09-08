// Copyright (C) 2021  Lian Studer
// See the LICENSE file for more information.

#ifndef XHK_TYPES_H
#define XHK_TYPES_H

typedef struct {
    uint16_t modifiers;
    xcb_keysym_t keysym;
    int (*proc)();
} hotkey_t;

#endif

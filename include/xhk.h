// Copyright (C) 2021  Lian Studer
// See the LICENSE file for more information.

#ifndef XHK_XHK_H
#define XHK_XHK_H

void parse_args(int *, char **);
void xhk_setup();
void stop_daemon();
void signal_handlers();
void interrupt(int);
char *signal_abbrv(int);
void grab_keybd();
void ungrab_keybd();
void keypress_event(xcb_key_press_event_t *);
hotkey_t *find_hotkey(xcb_keysym_t, uint16_t);

#endif

// Copyright (C) 2021  Lian Studer
// See the LICENSE file for more information.

#ifndef XHK_XHK_H
#define XHK_XHK_H

void parse_args(int *, char **);
void xhk_setup();
void stop_daemon();
void signal_handlers();
void interrupt(int);
void grab_keybd();
void ungrab_keybd();

#endif
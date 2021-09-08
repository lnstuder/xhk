// Copyright (C) 2021  Lian Studer
// See the LICENSE file for more information.

#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void xhk_err(char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    exit(EXIT_FAILURE);
}

void xhk_warn(char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
}

void execute_hk_proc(int (*proc)()) {
    if ((*proc)() != 0) {
        xhk_err("Could not execute procedure");
    } else {
        PUTS("Successfully executed hotkey procedure");
    }
}

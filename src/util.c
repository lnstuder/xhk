// Copyright (C) 2021  Lian Studer
// See the LICENSE file for more information.

#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void xcb_err(char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    exit(EXIT_FAILURE);
}

void xcb_warn(char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
}
// Copyright (C) 2021  Lian Studer
// See the LICENSE file for more information.

#ifndef XHK_UTIL_H
#define XHK_UTIL_H

#ifdef XHK_DEBUG


#include <assert.h>

#define PUTS(x)          puts(x)
#define PRINTF(...)      printf(__VA_ARGS__)
#define ASSERT(x)        assert(x)

#else


#define PUTS(x)          ((void)0)
#define PRINTF(x)        ((void)0)
#define ASSERT(x)        ((void)0)


#endif

#define COUNT(x)         (sizeof(x) / sizeof(*x))
#define SYMTOKEY(x)      *xcb_key_symbols_get_keycode(syms, x)

void xhk_err(char *fmt, ...);
void xhk_warn(char *fmt, ...);
void execute_hk_proc(int (*proc)(void));

#endif

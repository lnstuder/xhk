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

#endif
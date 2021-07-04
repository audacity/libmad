/* detect_fpm.h. */
/*
 * libmad - MPEG audio decoder library
 * Copyright (C) 2000-2001 Robert Leslie
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 * $Id: acconfig.h,v 1.2 2001-10-21 22:26:32 dmazzoni Exp $
 */

#ifndef _DETECT_FPM_H_
#define _DETECT_FPM_H_

#if defined(__amd64__) || defined(__x86_64__) || defined(_M_X64) || defined(__arm64__) || defined(__aarch64__) || defined(__ppc64__) || defined(__mips64) || defined(_M_ARM64)
#   define FPM_64BIT
#elif defined(__i386__) || defined(i386) || defined(_M_IX86) || defined(_X86_) || defined(__THW_INTEL)
#   define FPM_INTEL
#elif defined(arm) || defined(__arm__) || defined(ARM) || defined(_ARM_)
#   define FPM_ARM
#elif defined(__PPC__) || defined(__powerpc__) || defined(__powerpc) || defined(___M_PPC)
#   define FPM_PPC
#elif defined(mips) || defined(__mips__) || defined(MIPS) || defined(_MIPS_)
#   define FPM_MIPS
#else
#   define FPM_DEFAULT
#endif

/* The size of `int', as computed by sizeof. */
/* The case is that some of the CMake generators won't the propper int size detection */
/* This will fail horribly on 16 bit CPUs */

#define SIZEOF_INT 4

#endif

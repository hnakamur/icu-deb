/*
******************************************************************************
*                                                                            *
* Copyright (C) 2001-2001, International Business Machines                   *
*                Corporation and others. All Rights Reserved.                *
*                                                                            *
******************************************************************************
*   file name:  uclean.h
*   encoding:   US-ASCII
*   tab size:   8 (not used)
*   indentation:4
*
*   created on: 2001July05
*   created by: George Rhoten
*/

#ifndef __UCLEAN_H__
#define __UCLEAN_H__

#include "unicode/utypes.h"

/**
 * Clean up the system resources, such as allocated memory or open files,
 * used in all ICU libraries. This will free/delete all memory owned by the
 * ICU libraries, and return them to their original load state. All open ICU
 * items (collators, resource bundles, converters, etc.) must be closed before
 * calling this function, otherwise ICU may not free its allocated memory
 * (e.g. close your converters and resource bundles before calling this
 * function). Generally, this function should be called once just before
 * an application exits. For applications that dynamically load and unload
 * the ICU libraries (relatively uncommon), u_cleanup() should be called
 * just before the library unload.
 * <p>
 * u_cleanup() is not thread safe.  All other threads should stop using ICU
 * before calling this function.
 * <p>
 * Any open ICU items will be left in an undefined state by u_cleanup(),
 * and any subsequent attempt to use such an item will give unpredictable
 * results.
 * <p>
 * After calling u_cleanup(), an application may continue to use ICU by
 * creating an ICU C++ object or opening new items (converters, collators,
 * etc.) and using them.  An application must use ICU from one single
 * thread before allowing other threads or processes from using ICU.  This
 * is so that the ICU libraries can reinitialize in a thread safe manner.
 * <p>
 * The use of u_cleanup() just before an application terminates is optional,
 * but it should be called only once for performance reasons. The primary
 * benefit is to eliminate reports of memory or resource leaks originating
 * in ICU code from the results generated by heap analysis tools.
 * <p>
 * <strong>Use this function with great care!</strong>
 * </p>
 *
 * @draft ICU 2.0
 */
U_CAPI void U_EXPORT2 
u_cleanup(void);

#endif

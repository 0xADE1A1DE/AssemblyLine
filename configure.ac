#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([assemblyline],[1.0.5],[yval@cs.adelaide.edu.au])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR([src/assemblyline.c])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_PROG_CC
# uses latest c-standard
AC_PROG_CC_STDC
AC_PROG_INSTALL
AM_PROG_AR
AC_PROG_LN_S


#defines LIBTOOL variable
LT_INIT

# Checks for header files.
AC_CHECK_HEADERS([fcntl.h inttypes.h stdint.h stdlib.h string.h strings.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_SIZE_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_MMAP
AC_CHECK_FUNCS([munmap strchr strstr strtol strtoul])

AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])

AC_CONFIG_FILES([
                 Makefile
                 ])
AC_OUTPUT

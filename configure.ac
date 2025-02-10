#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([assemblyline],[1.4.0],[yval@cs.adelaide.edu.au])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR([src/assemblyline.c])
AC_CONFIG_AUX_DIR([build-aux])

# for the Test-Anything Protocol (TAP)
AC_REQUIRE_AUX_FILE([tap-driver.sh])

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
AC_CHECK_HEADERS([fcntl.h inttypes.h stdint.h stdlib.h string.h strings.h unistd.h time.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_SIZE_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T



# completion --start--
# bash
AC_ARG_WITH([bash-completion-dir],
            AS_HELP_STRING([--with-bash-completion-dir[=PATH]],
                           [Install the bash auto-completion script in this directory. @<:@default=yes@:>@]),
                           [],
                           [with_bash_completion_dir=yes])

if test "x$with_bash_completion_dir" = "xyes"; then
    PKG_CHECK_MODULES([BASH_COMPLETION], [bash-completion >= 2.0],
        [BASH_COMPLETION_DIR="`pkg-config --variable=completionsdir bash-completion`"],
        [BASH_COMPLETION_DIR="$datadir/bash-completion/completions"])
else
    BASH_COMPLETION_DIR="$with_bash_completion_dir"
fi
AC_SUBST([BASH_COMPLETION_DIR])
AM_CONDITIONAL([ENABLE_BASH_COMPLETION],[test "x$with_bash_completion_dir" != "xno"])
# end bash
# start zsh
AC_ARG_WITH([zsh-completion-dir],
            AS_HELP_STRING([--with-zsh-completion-dir[=PATH]],
                           [Install the zsh auto-completion script in this directory. @<:@default=yes@:>@]),
                           [],
                           [with_zsh_completion_dir=yes])

if test "x$with_zsh_completion_dir" = "xyes"; then
    ZSH_COMPLETION_DIR="$datadir/zsh/site-functions"
else
    ZSH_COMPLETION_DIR="$with_zsh_completion_dir"
fi
AC_SUBST([ZSH_COMPLETION_DIR])
AM_CONDITIONAL([ENABLE_ZSH_COMPLETION],[test "x$with_zsh_completion_dir" != "xno"])
# end zsh
# completion --end--

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_MMAP
AC_CHECK_FUNCS([munmap strchr strstr strtol strtoul rand])

AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])

AC_CONFIG_FILES([
                 Makefile
                 assemblyline.pc
                 ])
AC_OUTPUT

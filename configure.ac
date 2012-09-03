#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
AC_PREREQ(2.61)
AC_INIT(libneo4j, 0.1, wes@skeweredrook.com)
AC_CONFIG_SRCDIR([src/libneo4j.c])
AC_CONFIG_HEADER([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LIBTOOL

# Checks for libraries.
AC_CHECK_LIB([json],[json])
AC_CHECK_LIB([check],[srunner_create])

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stddef.h stdlib.h string.h])
AC_CHECK_HEADERS([json/json.h])
AC_CHECK_HEADERS([check.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AM_INIT_AUTOMAKE([foreign])

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 test/Makefile])
AC_OUTPUT

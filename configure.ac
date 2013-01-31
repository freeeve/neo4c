#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
AC_PREREQ(2.61)
AC_INIT(libneo4c, 0.1, wes@skeweredrook.com)
AC_CONFIG_SRCDIR([src])
AC_CONFIG_HEADER([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LIBTOOL

# Checks for libraries.
AC_CHECK_LIB([json-c],[json-c])
AC_CHECK_LIB([curl],[curl_easy_init])

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stddef.h stdlib.h string.h])
AC_CHECK_HEADERS([json-c/json.h])
AC_CHECK_HEADERS([curl/curl.h])

#### unit testing with Check
AC_ARG_ENABLE([tests], AS_HELP_STRING([--enable-tests],[enable building of tests @<:@default=no@:>@]))
AM_CONDITIONAL([TESTS], [test "x$enable_tests" != "xno"])

if test "x$enable_tests" != "xno"
then
  # NOTE: this first stanza is largely superflous, but will assist if
  #	we choose to move away from Check at some point in the future
  #	(or use multiple test frameworks)
  AC_ARG_WITH(check,
    AS_HELP_STRING([--with-check],
      [use Check for unit testing @<:@default=yes@:>@]),
      [case "${withval}" in
        yes) check=true ;;
        no)  check=false ;;
        *)   AC_MSG_ERROR([bad value ${withval} for --with-check]) ;;
      esac],
      [check=false])

  AM_CONDITIONAL(CHECK, test x"$check" = "xtrue")

    if test "x$check" = "xtrue"; then
      PKG_CHECK_MODULES([CHECK], [check >= 0.9.4],
        [AC_MSG_ERROR([Could not find the Check library required to build test suite for mod_auth_cas])]
      )
      BUILD_TESTS="yes"
      AC_SUBST(BUILD_TESTS)
    fi

    AC_ARG_ENABLE([runtests], AS_HELP_STRING([--enable-runtests],[enable running of tests @<:@default=no@:>@]))
    AM_CONDITIONAL([RUNTESTS], [test "x$enable_runtests" != "xno"])
fi

# Checks for typedefs, structures, and compiler characteristics.
AC_PROG_CC_C99

# Checks for library functions.
AM_INIT_AUTOMAKE([foreign])

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 test/Makefile])
AC_OUTPUT

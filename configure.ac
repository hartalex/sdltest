#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([sdltest], [0.0.1], [alex@hartcode.com])
AM_INIT_AUTOMAKE([subdir-objects])

AC_DEFINE([LOG_LEVEL], [1], [Sets the logging level, 0:debug 1:info 2:warn: 3:error ])

AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([src/config.hpp])

AC_CONFIG_FILES([src/makefile])
AC_LANG([C++])
# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_RANLIB


# Checks for libraries.
AC_CHECK_LIB([SDL2],[SDL_CreateWindow],,AC_MSG_ERROR(Couldn't find library libSDL2))

# Checks for header files.
AC_CHECK_HEADERS([cstdlib],,AC_MSG_ERROR(Missing header))

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

AC_SUBST([async_exec])
AC_CONFIG_FILES([makefile])

AC_OUTPUT

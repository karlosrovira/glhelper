#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([glhelper], [0.1], [gm.domato@gmail.com])
AC_CONFIG_SRCDIR([test/test_global.c])
AC_CONFIG_HEADERS([config.h])

# Initialize automake.
AM_INIT_AUTOMAKE 

# Checks for programs.
AC_PROG_CC
AC_PROG_RANLIB

# Checks for libraries.

dnl Get the pkg-config definitions for libGL.  We include a fallback
dnl path for GL implementation that don't provide a .pc file
PKG_CHECK_MODULES(GL, [gl], [], [
		  AC_CHECK_HEADER([GL/gl.h],
		  		  [],
		  		  AC_MSG_ERROR([GL not found]))
		  AC_CHECK_LIB([GL],
			       [glBegin],
			       [GL_LIBS=-lGL],
			       AC_MSG_ERROR([GL required]))
		  ])


dnl Include a fallback path for GLEW for the moment while not all distros
dnl have picked up the .pc file.
PKG_CHECK_MODULES(GLEW, [glew], [], [
		  AC_CHECK_HEADER([GL/glew.h],
		  [],
		  AC_MSG_ERROR([GLEW required]))
		  AC_CHECK_LIB([GLEW],
			       [glewInit],
			       [],
			       AC_MSG_ERROR([GLEW required]))
		  ])

PKG_CHECK_MODULES(SDL2, [sdl2], [AC_DEFINE([HAVE_SDL], [1], [Define if SDL2 is available.])], [])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_TYPE_OFF_T
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC

# Create output.
AC_CONFIG_FILES([Makefile
                 src/Makefile
                 test/Makefile])

AC_OUTPUT

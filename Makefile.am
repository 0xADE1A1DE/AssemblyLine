SUBDIRS = src test tools
# run 'make check' from projects' root to have libassemblyline being compiled on change
# check_LTLIBRARIES = libassemblyline.la
EXTRA_DIST =
ACLOCAL_AMFLAGS = -I m4 --install

# this ensures, that the lib is rebuild (if necessary) on make check
lib_LTLIBRARIES = libassemblyline.la
libassemblyline_la_SOURCES =
libassemblyline_la_LIBADD = src/libassemblyline.la


CLEANFILES = config.h~ \
			 configure~ \
			 assemblyline-*.tar.gz

distclean-local:
	rm -rf autom4te.cache/


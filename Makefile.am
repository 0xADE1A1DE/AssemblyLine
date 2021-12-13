## Copyright 2021 University of Adelaide

## Licensed under the Apache License, Version 2.0 (the "License");
## you may not use this file except in compliance with the License.
## You may obtain a copy of the License at

##    http://www.apache.org/licenses/LICENSE-2.0

## Unless required by applicable law or agreed to in writing, software
## distributed under the License is distributed on an "AS IS" BASIS,
## WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
## See the License for the specific language governing permissions and
## limitations under the License.


SUBDIRS = src tools test
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

# from  7.3 https://www.gnu.org/software/libtool/manual/html_node/Versioning.html#Versioning
# -version-info accepts ‘current[:revision[:age]]’

# 1. If the library SOURCE CODE has changed at all  since the last update:                    revision++       
# 2. If ANY INTERFACES have been ADDED              since the last public release: current++, revision=0, age++.
# 3. If ANY INTERFACES have been REMOVED or CHANGED since the last public release: current++, revision=0, age=0.

# Hints
# 1. Programs using the previous version may use the new version as drop-in replacement, and programs using the new version can also work with the previous one. In other words, no recompiling nor relinking is needed. In this case, bump revision only, don’t touch current nor age.
# 2. Programs using the previous version may use the new version as drop-in replacement, but programs using the new version may use APIs not present in the previous one. In other words, a program linking against the new version may fail with “unresolved symbols” if linking against the old version at runtime: set revision to 0, bump current and age.
# 3. Programs may need to be changed, recompiled, and relinked in order to use the new version. Bump current, set revision and age to 0.

# in short, if only patch from configure.ac is bumped, bump the middle number below. If more is changed, read the above
libassemblyline_la_LDFLAGS = -version-info 1:5:0

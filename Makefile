CC=gcc
SOURCES=main.c
LIBS=libtextonly.c libheadersonly.c liblinksonly.c
LIBARGS=-fpic -shared
LIBBUILD=libhtmlconvert.so
LIBINCLUDE=-Lhtmlconvert
OUTARG=-o
BINBUILD=seekhtml

all: buildlib buildbin

buildlib:
	$(CC) $(LIBARGS) $(LIBS) $(OUTARG) $(LIBBUILD)

buildbin:
	$(CC) $(SOURCES) $(LIBINCLUDE) $(OUTARG) $(BINBUILD)

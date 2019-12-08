EXEEXT = .test
check_PROGRAMS = LIFO

LIFO_SOURCES = LIFO.c
LIFO_LDADD = ../LIFO.o

TESTS_ENVIRONMENT =
TEST_EXTENSIONS = .test

TEST_LOG_DRIVER = env AM_TAP_AWK='$(AWK)' $(SHELL)\
                    $(top_srcdir)/build-aux/tap-driver.sh

TESTS = LIFO.test
EXTRA_DIST = $(TESTS)

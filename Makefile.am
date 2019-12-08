bin_PROGRAMS = myedit
myedit_SOURCES = LIFO.c main.c
myedit_LDADD = -lcurses

SUBDIRS = tests

TESTS_ENVIRONMENT =
TEST_LOG_COMPILE = $(SHELL)
TEST_LOG_DRIVER = env AM_TAP_AWK='$(AWK)' $(SHELL) $(top_srcdir)/tap-driver.sh

EXTRA_DIST = Makefile.dist $(TESTS)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += editor.c \
    load.c \
    save.c \
    s.c \
    showclassified.c \
    show.c \
    text/plb.c \

    shownum.c \
    text/cursors.c \
    text/append_line.c \
    text/create_text.c \
    text/process_forward_extra_option.c \
    text/process_forward.c \
    text/remove_all.c \
    text/tracer.c

HEADERS += common.h \
    text/text.h \
    text/_text.h
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += s.c \
    showclassified.c \
    text/plb.c \
    text/append_line.c \
    text/process_forward.c \
    text/cursors.c \
    text/tracer.c \
    text/delete_line.c \
    text/remove_all.c \
    main.c \
    text/create_text.c \
    load.c \
    show.c \



HEADERS += common.h \
    text/text.h \
    text/_text.h \

QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

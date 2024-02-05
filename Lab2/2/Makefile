##
# Project Title
#
# @file
# @version 0.1

CC = gcc
CFLAGS = -Wall -O2 -pedantic
SRC_DIR = src
OUT_FILE = printer
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)


all: $(OUT_FILE)

$(OUT_FILE): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	rm -f $(SRCS:.c=.o)

run: all
	./$(OUT_FILE)

val : all
	valgrind ./$(OUT_FILE)

clean:
	rm -f $(OBJS) $(OUT_FILE)


.PHONY: all clean

# end

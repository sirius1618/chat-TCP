CC = gcc
CFLAGS = -Wall -Wextra -I../include -g   
TARGET = servidor

SRC_DIR = .
INC_DIR = ../include

SRCS = main.c \
       config_servidor.c \
       config_socket.c \
       inicialzando_server.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

distclean: clean
	rm -f $(TARGET)

.PHONY: all clean distclean
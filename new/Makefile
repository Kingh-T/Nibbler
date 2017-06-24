CC = g++
CFLAGS = -fPIC -Wall -Werror -Wextra -02 -g
LDFLAGS = -shared
RM = rm -f
TARGET_LIB = libSDL.so

SRCS = *.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all
all: ${TARGET_LIB}

$(TARGET_LIB): $(OBJS)
	$(CC) ${LDFLAGS} -o $@ $^

$(SRCS:.cpp=.d):%.d:%.cpp
	$(CC) $(CFLAGS) -MM $< >$@

include $(SRCS:.cpp=.d)

.PHONY: clean
clean:
	-${RM} ${TARGET_LIB} ${OBJS} ${SRCS:.cpp=.d}

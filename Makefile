CC     := gcc
CFLAGS := -std=gnu99 -Wall -Wextra -Werror


all: main.c
	$(CC) $(CFLAGS) $^ -o output

.PHONY: astyle clean
astyle:
	astyle --options=.astylerc main.c

clean:
	@rm -f output

-include $(DEPS)

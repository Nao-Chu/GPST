cpp = gcc

src = $(wildcard *.c)
target = $(patsubst %.c,%,$(src))

myArgs = -Wall -g -std=c11
ALL:$(target)


%:%.c 
	$(cpp) $< -o $@ $(myArgs)

clean:
	-rm -rf $(target)

.PHONY: clean ALL


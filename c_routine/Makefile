cpp = gcc
src = $(shell find -name "*.c")
target = $(src:%.c=%)
myArgs = -Wall -g -std=c11

ALL:$(target)
%:%.c 
	$(cpp) $< -o $@ $(myArgs)

clean:
	-rm -rf $(target)


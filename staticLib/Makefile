cpp = gcc
prom = main.c
target = target
deps = $(shell find inc -name "*.h")
src  = $(shell find src -name "*.c")
obj  = $(src:%.c=%.o)
myArgs = -Wall -g
libName = lib/libMyc.a

ALL = $(target)
$(target) : $(libName) 
	$(cpp) $(prom) $< -o $(target) $(myArgs)

$(libName) : $(obj)
	ar rcs $@ $^

%.o : %.c $(deps)
	$(cpp) -c $< -o $@ $(myArgs)

clean:
	-rm -rf $(obj) $(ALL) $(libName)


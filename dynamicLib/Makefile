cpp = gcc
prom = main.c
target = target
deps = $(shell find inc -name "*.h")
src  = $(shell find src -name "*.c")
obj  = $(src:%.c=%.o)
myArgs = -Wall -g
libName = lib/libMyc.so
lib = -l Myc -L ./lib

ALL = $(target)
$(target) : $(libName) 
	$(cpp) $(prom) -o $(target) $(myArgs) $(lib)  

$(libName) : $(obj)
	$(cpp) -shared -o $@ $^ 

%.o : %.c $(deps)
	$(cpp) -c $< -o $@ $(myArgs) -fPIC

clean:
	-rm -rf $(obj) $(ALL) $(libName)


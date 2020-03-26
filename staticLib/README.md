```makefile
1. gcc -c add.c -o add.o
2. ar rcs libName.a add.o sub.o
3. gcc main.c libName.a -o main
```



Makefile

```makefile
c = gcc
prom = main.c
target = target
deps = $(shell find inc -name "*.h")
src  = $(shell find src -name "*.c")
obj  = $(src:%.c=%.o)
myArgs = -Wall -g
libName = lib/libMyc.a

ALL = $(target)
$(target) : $(libName) 
	$(c) $(prom) $< -o $(target) $(myArgs)

$(libName) : $(obj)
	ar rcs $@ $^

%.o : %.c $(deps)
	$(c) -c $< -o $@ $(myArgs)

clean:
	-rm -rf $(obj) $(ALL) $(libName)
```


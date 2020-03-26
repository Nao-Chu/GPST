```makefile
1. gcc -c add.c -o add.o -fPIC
2. gcc -shared -o libName.so add.o sub.o
3. gcc main.c -o main -lName -L ./lib
```



Makefile

```makefile
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
```



动态链接器

```
1. export LD_LIBRARY_PATH=动态库路径
2. 将1的方法写入.bashrc
3. 把动态库拷贝到/lib目录
4. 把动态库绝对路径写入 /etc/ld.so.conf 
   然后执行 sudo ldconfig -v
```


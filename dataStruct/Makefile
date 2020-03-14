cpp = g++
prom = $(shell $1) 
src = $(prom:=.cpp)
obj = $(src:.cpp=.o)

$(prom): $(obj)
	$(cpp) -o $(prom) $(obj) -std=c++11 
	rm -f $(obj)

.o:.cpp 
	$(cpp) -c $< -o $@

cpp = g++
prom = main
deps = $(shell find ./ -name "*.h")
src = $(shell find ./ -name "*.cpp")
obj = $(src:%.cpp=%.o)

$(prom): $(obj)
	$(cpp) -o $(prom) $(obj)

%.o: %.cpp $(deps)
	$(cpp) -c $< -o $@

clean:
	rm -rf $(obj) $(prom)

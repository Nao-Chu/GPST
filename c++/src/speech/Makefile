cpp = g++
prom = main
deps = $(shell find ./ -name "*.h")
src = $(shell find ./ -name "*.cpp")
obj = $(src:%.cpp=%.o)
std = c++11

$(prom): $(obj)
	$(cpp) -o $(prom) $(obj) -std=$(std)

%.o: %.cpp $(deps)
	$(cpp) -c $< -o $@

clean:
	rm -rf $(obj) $(prom)

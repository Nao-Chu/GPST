cpp = g++
src = $(shell find -name "*.cpp")
target = $(src:%.cpp=%)
myArgs = -Wall -g -std=c++11

ALL:$(target)
%:%.c 
	$(cpp) $< -o $@ $(myArgs)

clean:
	-rm -rf $(target)


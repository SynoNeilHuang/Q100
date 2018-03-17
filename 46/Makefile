CXX=g++

src = $(wildcard *.cpp)
obj = $(src:%.cpp=%.o)
CXXFLAGS := -O3 -std=c++11

.PHONY: all clean

deps := $(src:%.cpp=.%.o.d)

all: exe

exe: $(obj)
	$(CXX) $(CXXFLAGS) -o exe $(src:%.cpp=%.o)

%.o: %.cpp
	$(CXX) -o $@ $(CXXFLAGS) -c -MMD -MF .$@.d $<

clean:
	$(RM) $(obj) $(deps) exe

-include $(deps)

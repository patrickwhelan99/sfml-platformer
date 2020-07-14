CXX = g++
src = $(wildcard src/*.cpp)
obj = $(src:.cpp=.o)
dep = $(obj:.o=.d)  # one dependency file for each source

CXXFLAGS = -Wall -Iinclude
LDFLAGS = -lsfml-system -lsfml-graphics -lsfml-window

game: $(obj)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS) -g

-include $(dep)   # include all dep files in the makefile

# rule to generate a dep file by using the C preprocessor
# (see man cpp for details on the -MM and -MT options)
%.d: %.cpp
	@$(CPP) $(CXXFLAGS) $< -MM -MT $(@:.d=.o) >$@



.PHONY: clean

clean: cleandep
	rm -f $(obj) game

.PHONY: cleandep

cleandep:
	rm -f $(dep)

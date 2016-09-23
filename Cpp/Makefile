COMPILER=g++ -std=c++11
CPPFLAGS = $(shell pkg-config --cflags opencv)
LDLIBS = $(shell pkg-config --libs opencv)

main : main.cpp
	$(COMPILER) $(GNUSTD11) $(CPPFLAGS) $(LDLIBS) -o $@ $<


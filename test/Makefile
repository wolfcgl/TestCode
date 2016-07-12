include ../Makefile.param

CC=g++

CFLAGS 		+= -std=c++11
CXXFLAGS 	+= -std=c++11

CFLAGS 		+= -I$(TOPDIR)/include
CXXFLAGS 	+= -I$(TOPDIR)/include

CFLAGS 		+= -D_UNIT_TEST_
CXXFLAGS 	+= -D_UNIT_TEST_

SRC  := $(TOPDIR)/test/test_geometric.cpp
OBJ  := $(SRC:%.cpp=%.o)

TARGETS := testPoint


all: $(TARGETS)

$(TARGETS): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGETS)
	rm -f $(OBJ)

CC=g++
CFLAGS 		+= -g
CXXFLAGS 	+= -g
CFLAGS 		+= -std=c++11
CXXFLAGS 	+= -std=c++11

SRC  := $(wildcard ./region.cpp)
SRC  += $(wildcard ./region_manager.cpp)
#SRC  += $(wildcard ./main.cpp)
SRC  += $(wildcard ./testTank.cpp)
OBJ  := $(SRC:%.cpp=%.o)

#TARGETS := testRegion
TARGETS := testTank

all: $(TARGETS)

$(TARGETS): $(OBJ)
	$(CC) $(CFLAGS) -lncurses -o $@ $^

clean:
	rm -f $(TARGETS)
	rm -f $(OBJ)

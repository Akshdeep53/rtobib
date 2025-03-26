.RECIPEPREFIX = >
CXX = g++
CXXFLAGS = -I include/
SRC = $(wildcard src/*.cpp)
OUT = rtobib

all: $(OUT)

$(OUT): $(SRC)
> $(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

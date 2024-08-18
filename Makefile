CXX = g++
INCLUDE_PATH = include
LIB_PATH = /usr/local/lib
BIN_PATH = bin
SRC_PATH = src
TARGET = $(BIN_PATH)/Heaven_LTNC
SRCS = $(SRC_PATH)/main.cpp $(SRC_PATH)/game.cpp $(SRC_PATH)/menu.cpp $(SRC_PATH)/object.cpp

CXXFLAGS = -I$(INCLUDE_PATH) -I/usr/local/include/SDL2 -std=c++11 -Wall
LDFLAGS = -L$(LIB_PATH) -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS) $(LDFLAGS)

clean:
	rm -f $(TARGET)

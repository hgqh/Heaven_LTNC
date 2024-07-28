
CXX = g++
INCLUDE_PATH = .
SDL2_INCLUDE_PATH = /usr/local/include/SDL2
LIB_PATH = /usr/local/lib
BIN_PATH = binanddll
TARGET = $(BIN_PATH)/main
SRCS = main.cpp game.cpp

CXXFLAGS = -I$(INCLUDE_PATH) -I$(SDL2_INCLUDE_PATH) -std=c++11 -Wall

LDFLAGS = -L$(LIB_PATH) -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS) $(LDFLAGS)

clean:
	rm -f $(TARGET)

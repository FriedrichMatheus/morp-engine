SRC=./src/
SRCS := $(wildcard $(SRC)*.cpp)
OBJS := $(SRCS:.cpp=.o)

CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = build/game_engine

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) -lSDL2 -lSDL2_image

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run:
	./$(TARGET)

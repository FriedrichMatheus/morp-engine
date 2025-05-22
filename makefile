SRC=./src/
BUILD := build/
OBJDIR := $(BUILD)obj/
SRCS := $(wildcard $(SRC)*.cpp)
OBJS := $(patsubst $(SRC)%.cpp, $(OBJDIR)%.o, $(SRCS))

CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET := $(BUILD)game_engine

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) -lSDL2 -lSDL2_image

$(OBJDIR)%.o: $(SRC)%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -rf $(OBJDIR) $(TARGET)

run:
	./$(TARGET)

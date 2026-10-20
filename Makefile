CXX ?= g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
TARGET = adapter_demo

SRCS = src/main.cpp src/LegacyJsonService.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all run clean

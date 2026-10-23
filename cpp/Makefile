CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude
LEGACY   := src/LegacyPaymentGateway.cpp

all: build/demo

build/demo: src/main.cpp $(LEGACY) | build
	$(CXX) $(CXXFLAGS) $^ -o $@

build/test: tests/test_adapter.cpp $(LEGACY) | build
	$(CXX) $(CXXFLAGS) $^ -o $@

build:
	mkdir -p build

run: build/demo
	./build/demo

test: build/test
	./build/test

clean:
	rm -rf build

.PHONY: all run test clean

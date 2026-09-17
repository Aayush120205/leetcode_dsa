CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra

.PHONY: test check all clean

all: test check

# Unit tests for the shared utilities and the solutions built on top of them.
test:
	$(CXX) $(CXXFLAGS) -o build/test_utils tests/test_utils.cpp
	./build/test_utils

# Syntax check for every solution file.
check:
	./scripts/check_solutions.sh

test check: | build

build:
	mkdir -p build

clean:
	rm -rf build

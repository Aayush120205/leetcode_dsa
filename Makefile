CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -O1 -g
BUILD_DIR := build
SOURCES := $(wildcard tests/*.cpp)
OBJECTS := $(patsubst tests/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
BINARY := $(BUILD_DIR)/run_tests

.PHONY: test coverage clean

test: $(BINARY)
	./$(BINARY)

$(BINARY): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: tests/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Line coverage of the solution files, reported per source file with gcov.
coverage: clean
	$(MAKE) test CXXFLAGS="$(CXXFLAGS) --coverage" LDFLAGS="--coverage"
	gcov -o $(BUILD_DIR) $(BUILD_DIR)/*.gcda > /dev/null
	mv *.gcov $(BUILD_DIR)/
	@echo
	@python3 scripts/coverage_report.py $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

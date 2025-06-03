BUILD_DIR = build
SOURCE_DIR = src
TEST_DIR = tests
CFLAGS = -g -Wall -Wextra -Wpedantic -Isrc
LIBS = -lgtest_main -lgtest -lpthread

all: main

main: $(BUILD_DIR)/main.o $(BUILD_DIR)/test.o
		clang++ -o $(BUILD_DIR)/main $(BUILD_DIR)/main.o $(BUILD_DIR)/test.o $(LIBS)

$(BUILD_DIR)/main.o: $(SOURCE_DIR)/main.cpp
		clang++ -c $(CFLAGS) $(SOURCE_DIR)/main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/test.o: $(TEST_DIR)/test.cpp
		clang++ -c $(CFLAGS) $(TEST_DIR)/test.cpp -o $(BUILD_DIR)/test.o

clean:
		rm -f $(BUILD_DIR)/main $(BUILD_DIR)/*.o 

.PHONY: all clean
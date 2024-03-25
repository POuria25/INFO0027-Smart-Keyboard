CC=gcc
PROG=smartkeyboard

SRC_DIR := ./src
BUILD_DIR := ./build

# Do not remove any flags here (you may add -g for debugging)
CFLAGS := -Wall -pedantic -std=c99 -lm
LDFLAGS := -lm

SRC_FILES := $(shell find $(SRC_DIR) -type f -name '*.c')
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))


$(PROG): $(OBJ_FILES)
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(shell dirname $@)
	$(CC) -c $< -o $@ $(CFLAGS)

tests: $(PROG)
	#./smartkeyboard stations.txt complete Mar
	./smartkeyboard stations.txt suggest Li

valgrind:
	valgrind --track-origins=yes --leak-check=full ./$(PROG) stations.txt suggest Li

gdb:
	gdb ./smartkeyboard stations.txt complete Li



memory_sanitizer:
	clang -fsanitize=memory -fno-omit-frame-pointer -g -o $(PROG) $(SRC_FILES) $(CFLAGS) $(LDFLAGS)

.PHONY: clean 

clean:
	rm -rf $(BUILD_DIR) $(PROG)

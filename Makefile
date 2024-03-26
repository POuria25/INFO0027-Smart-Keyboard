CC=gcc
PROG=smartkeyboard

SRC_DIR := ./src
BUILD_DIR := ./build

# Do not remove any flags here (you may add -g for debugging)
CFLAGS := -g -Wall -pedantic -std=c99 -lm
LDFLAGS :=-g -lm

SRC_FILES := $(shell find $(SRC_DIR) -type f -name '*.c')
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))


$(PROG): $(OBJ_FILES)
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(shell dirname $@)
	$(CC) -c $< -o $@ $(CFLAGS)

tests: $(PROG)
	./smartkeyboard stations.txt complete Mar
	./smartkeyboard stations.txt suggest Mar
	./smartkeyboard stations.txt complete Bruxe
	./smartkeyboard stations.txt suggest Br
	./smartkeyboard stations.txt complete De
	./smartkeyboard stations.txt suggest De
	./smartkeyboard stations.txt complete Hei
	./smartkeyboard stations.txt suggest Hei
	./smartkeyboard stations.txt complete Vi
	./smartkeyboard stations.txt suggest Vi
	./smartkeyboard stations.txt complete Si
	./smartkeyboard stations.txt suggest Si
	./smartkeyboard stations.txt complete Vo
	./smartkeyboard stations.txt suggest Vo
	./smartkeyboard stations.txt complete La
	./smartkeyboard stations.txt suggest La
valgrind:
	valgrind --track-origins=yes --leak-check=full ./$(PROG) stations.txt suggest Li

gdb:
	gdb ./smartkeyboard stations.txt complete Li



memory_sanitizer:
	clang -fsanitize=memory -fno-omit-frame-pointer -g -o $(PROG) $(SRC_FILES) $(CFLAGS) $(LDFLAGS)

tar:
	tar -czvf S-192865.tar.gz $(SRC_DIR) $(BUILD_DIR) Makefile

.PHONY: clean

clean:
	rm -rf $(BUILD_DIR) $(PROG)

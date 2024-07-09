CC=gcc
PROG=smartkeyboard

SRC_DIR := ./src
BUILD_DIR := ./build

# Do not remove any flags here (you may add -g for debugging)
CFLAGS := -g3 --pedantic -Wall -pedantic -std=c99 -lm
LDFLAGS :=-g -lm

SRC_FILES := $(shell find $(SRC_DIR) -type f -name '*.c')
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))


$(PROG): $(OBJ_FILES)
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(shell dirname $@)
	$(CC) -c $< -o $@ $(CFLAGS)

tests: $(PROG)
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./smartkeyboard stations.txt complete An
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./smartkeyboard stations.txt suggest Anvers
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./smartkeyboard stations.txt suggest Anvers-
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./smartkeyboard stations.txt complete Balegem-
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./smartkeyboard stations.txt suggest Balegem
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./smartkeyboard stations.txt suggest Baasrode-Zuid
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./smartkeyboard stations.txt complete Bruxe
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./smartkeyboard stations.txt complete Bas-
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./smartkeyboard stations.txt suggest Braine
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./smartkeyboard stations.txt suggest Braine-
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./smartkeyboard stations.txt suggest Br
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./smartkeyboard stations.txt complete De
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./smartkeyboard stations.txt suggest De
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./smartkeyboard stations.txt complete Hei
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./smartkeyboard stations.txt suggest Hei
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./smartkeyboard stations.txt complete Vi
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./smartkeyboard stations.txt suggest Vi
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./smartkeyboard stations.txt complete Si
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./smartkeyboard stations.txt suggest Si
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./smartkeyboard stations.txt complete Vo
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./smartkeyboard stations.txt suggest Vo
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./smartkeyboard stations.txt complete La
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./smartkeyboard stations.txt suggest La
valgrind:
	valgrind --track-origins=yes --leak-check=full ./$(PROG) stations.txt suggest Li

gdb:
	gdb ./smartkeyboard stations.txt complete Li



memory_sanitizer:
	clang -fsanitize=memory -fno-omit-frame-pointer -g -o $(PROG) $(SRC_FILES) $(CFLAGS) $(LDFLAGS)

tar:
	tar -czvf S-192865.tar.gz $(SRC_DIR) $(BUILD_DIR) Makefile report.pdf

.PHONY: clean

clean:
	rm -rf $(BUILD_DIR) $(PROG)

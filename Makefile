CC=gcc
PROG=smartkeyboard

SRC_DIR := ./src
BUILD_DIR := ./build

# Do not remove any flags here (you may add -g for debugging)
CFLAGS := -Wall -pedantic -std=c99 
LDFLAGS := -lm

SRC_FILES := $(shell find $(SRC_DIR) -type f -name '*.c')
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))


$(PROG): $(OBJ_FILES)
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(shell dirname $@)
	$(CC) -c $< -o $@ $(CFLAGS)

tests: $(PROG)
	./smartkeyboard stations.txt complete Li
	# other tests...

submission: $(SRC_DIR)/smartkeyboard.c $(SRC_DIR)/tst.c $(SRC_DIR)/stations.c $(SRC_DIR)/tst.h $(SRC_DIR)/stations.h report.pdf
	tar -cvzf submission.tar.gz $^ Makefile

.PHONY: clean 

clean:
	rm -r $(BUILD_DIR)/*

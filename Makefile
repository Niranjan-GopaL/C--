CC     = gcc
CFLAGS = -O3


# Directories and Files
SRC_DIR    = src
OBJ_DIR    = obj

SRC_FILES  = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES  = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
INPUT_FILE = $(SRC_FILES)/input.txt


TARGET     = myprogram

# compilations
all: $(TARGET)

$(OBJ_DIR)/interpreter.o: $(SRC_DIR)/interpreter.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/variable.o: $(SRC_DIR)/variable.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/print.o: $(SRC_DIR)/print.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/condition.o: $(SRC_DIR)/condition.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/arithmetic.o: $(SRC_DIR)/arithmetic.c
	$(CC) $(CFLAGS) -c $< -o $@

# Linking
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@


# Run tests in ONE COMMAND --> make run_tests
cmm: $(TARGET)
	./$(TARGET)

# Clean up
clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)
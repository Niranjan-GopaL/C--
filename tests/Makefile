CC = gcc
CFLAGS =  -I../include


# Directories and Files
SRCDIR  = ../src
TESTDIR = ./.
OBJDIR  = ../obj

TEST_SOURCES     = $(wildcard $(TESTDIR)/*.c)
TEST_OBJECTS     = $(patsubst $(TESTDIR)/%.c, $(OBJDIR)/%.o, $(TEST_SOURCES))
FUNCTION_SOURCES = $(wildcard $(SRCDIR)/*.c)



TEST_EXECUTABLE = test

all: $(TEST_EXECUTABLE)


$(OBJDIR)/%.o: $(TESTDIR)/%.c $(FUNCTION_SOURCES)
	$(CC) $(CFLAGS) -c $< -o $@


# Linking
$(TEST_EXECUTABLE): $(TEST_OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@


# Run tests in ONE COMMAND --> make run_tests
run_tests: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)


# Clean up
clean:
	rm -rf $(OBJDIR)/*.o $(TEST_EXECUTABLE)
CC = g++

CFLAGS = -g -Wall

INCLUDES = -Iinclude

LIBS = -lSDL

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
DEP_DIR = dep

#make sure the folder exist, if not create them
dummy_build_folder := $(shell mkdir -p $(BIN_DIR) $(OBJ_DIR) $(DEP_DIR))

SRCS = $(wildcard $(SRC_DIR)/*.cpp)

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

DEPS = $(OBJS:$(OBJ_DIR)/%.o=$(DEP_DIR)/%.d)

TARGET = $(BIN_DIR)/cavestory

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

-include $(DEPS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(DEP_DIR)/%.d: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) $< -MM -MT $(@:$(DEP_DIR)/%.d=$(OBJ_DIR)/%.o) > $@

clean:
	$(RM) $(OBJS) $(DEPS) $(TARGET)

run:
	./$(TARGET)

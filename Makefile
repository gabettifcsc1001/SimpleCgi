CC      = g++
CFLAGS  = -g -MMD -MP -Wall -O
LDFLAGS =
LIBS    =
INCLUDE = -I ./include
SRC_DIR = ./src
OBJ_DIR = ./build
SOURCES = $(shell ls $(SRC_DIR)/*.cpp)
OBJS    = $(subst $(SRC_DIR),$(OBJ_DIR), $(SOURCES:.cpp=.o))
TARGET  = simple_cgi
DEPENDS = $(OBJS:.o=.d)
OUTPUT  = simple.cgi

all: $(TARGET)

$(TARGET): $(OBJS) $(LIBS)
		$(CC) -o $(OUTPUT) $(OBJS) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
		@if [ ! -d $(OBJ_DIR) ]; \
			then echo "mkdir -p $(OBJ_DIR)"; mkdir -p $(OBJ_DIR); \
		fi
		$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
		$(RM) $(OBJS) $(TARGET) $(DEPENDS) $(OUTPUT)

-include $(DEPENDS)

.PHONY: all clean

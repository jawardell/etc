SRC_DIR = ./src_files
INC_DIR = ./inc_files
OBJ_DIR = ./obj_files
BIN_DIR = ./bin_files

CC = g++
_OBJS = algo.o timer.o 
OBJS = $(patsubst %, $(OBJ_DIR)/%, $(_OBJS))
_SRCS = $(patsubst %.o, %.cpp, $(_OBJS))
SRCS = $(patsubst %, $(SRC_DIR)/%, $(_SRCS))
CFLAGS = -g -I$(INC_DIR)
LDFLAGS = -lm 

all: $(BIN_DIR)/algo

$(BIN_DIR)/app: $(OBJS) 
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

dependencies:  $(SRCS)
	$(CC) -I$(INC_DIR) -MM $^ | sed '/^.*.o:/ s#^#$(OBJ_DIR)/#' > $@

include dependencies

# TARGETS       := 
CC            := gcc
CFLAGS        := -Wall #-pg
SOURCE_DIR    := src
SRCS          := $(addsuffix .c, $(TARGETS))
BUILD_DIR     := build
OBJS          := $(SRCS:.c=.o)
PATH_OBJS     := $(addprefix $(BUILD_DIR)/, $(OBJS))
INCLUDE_DIR   := $(SOURCE_DIR)/include
INCLUDE_PATHS := -I$(INCLUDE_DIR)

.PHONY: all
all: $(TARGETS)

$(TARGETS): $(PATH_OBJS)
	@$(CC) $(INCLUDE_PATHS) $(CFLAGS) $< -o $(BUILD_DIR)/$@
	@echo "[done]" $@

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c $(INCLUDE_DIR)/$(HDRS) | $(BUILD_DIR)
	@$(CC) $(INCLUDE_PATHS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	@mkdir -p $@

.PHONY: clean
clean:
	@rm -f $(BUILD_DIR)/*.o
	@echo "[done]" $@

.PHONY: distclean
distclean:
	@rm -rf $(BUILD_DIR)
	@echo "[done]" $@

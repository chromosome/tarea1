# TARGETS       := 
CC            := gcc
CFLAGS        := -Wall -g
SOURCE_DIR    := src
SRCS          := $(addsuffix .c, $(TARGETS))
BUILD_DIR     := bin
OBJS          := $(SRCS:.c=.o)
PATH_OBJS     := $(addprefix $(BUILD_DIR)/, $(OBJS)) # $(BUILD_DIR)/%.o
# HDRS          := common.h sorting.h matrix.h matrix_mult.h utils.h
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
	@mkdir -p bin

.PHONY: clean
clean:
	@rm -f $(BUILD_DIR)/*.o
	@echo "[done]"

.PHONY: distclean
distclean:
	@rm -rf $(BUILD_DIR)
	@echo "[done]"

# .PHONY: distclean
# distclean:
# 	@rm -rfv $(BUILD_DIR)
# 	@echo distclean

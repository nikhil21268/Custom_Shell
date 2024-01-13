TARGETS=my_trial cat_trial_copy date_copy mkdir_copy rm_copy ls_trial_2
CC_C=$(CROSS_TOOL)gcc
#CFLAGS=-Wall -g -std=c99 
CFLAGS=-g -pthread
all: clean $(TARGETS)
$(TARGETS):
	$(CC_C) $(CFLAGS) $@.c -o $@
clean:
	rm -f $(TARGETS)
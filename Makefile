# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Targets
TARGETS = broken.bin conflict openssl_conflict

# Default target
all: $(TARGETS)

openssl_conflict: openssl_conflict.c
	$(CC) $(CFLAGS) -o $@ $< -lcrypto

# Pattern rule to compile .c files into executables
%: %.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean up build files
clean:
	rm -f $(TARGETS)

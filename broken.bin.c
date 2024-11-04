#include <stdio.h>
#include <unistd.h>

#define test_file "./.config"

int main() {
	if (access(test_file, F_OK) == 0) {
		printf("OK\n");
	} else {
		printf("Segmentation fault (core dumped)\n");
	}
}

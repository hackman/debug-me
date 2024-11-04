#include <stdio.h>
#include <stdlib.h>

// Custom free function that doesn't match malloc's behavior, causing a conflict
void my_free(void *ptr) {
    // Do nothing or perform some conflicting operation
    printf("Custom free function called.\n");
}

int main() {
    // Allocate memory using standard malloc
    char *buffer = (char *)malloc(100);

    // Simulate some operations
    if (buffer) {
        snprintf(buffer, 100, "Hello, ltrace!");
        printf("%s\n", buffer);
    }

    // Call custom free function instead of standard free (conflict)
    my_free(buffer);

    return 0;
}


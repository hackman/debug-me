#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

// Custom SHA256 function that conflicts with OpenSSL's SHA256
static unsigned char * custom_SHA256(const unsigned char *data, size_t len, unsigned char *hash) {
    printf("Custom SHA256 function called.\n");
    // Simulate hashing (just fills with dummy data for illustration)
    memset(hash, 'A', SHA256_DIGEST_LENGTH);
	return hash;
}

int main() {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    const char *input = "Hello, OpenSSL!";

    // Define a flag to choose which function to call
    int use_custom = 1;

    // Call either OpenSSL SHA256 or the custom function based on a condition
    if (use_custom) {
        custom_SHA256((const unsigned char *)input, strlen(input), hash);
    } else {
        SHA256((const unsigned char *)input, strlen(input), hash);
    }

    // Display the resulting hash in hexadecimal format
    printf("Hash: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}

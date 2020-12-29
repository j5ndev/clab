#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

// Signatures of functions defined later
int validateInput(int, char **);
uintmax_t factorial(uintmax_t);

// Entrypoint
int main( int argc, char *argv[] )  {
    uintmax_t value = validateInput(argc, argv);
    printf("Input value: %lu\n", value);
    uintmax_t result = factorial(value);
    printf("     Result: %lu\n", result);
    return 0;
}

// Calculate factorial
uintmax_t factorial(uintmax_t value) {
    if (value < 2) {
        return 1;
    }
    uintmax_t counter = value;
    uintmax_t result = value;
    while (counter > 1) {
        result = result * (counter - 1);
        counter--;
    }
    return result;
}

// Validate input parameters
int validateInput(int argc, char *argv[]) {
    if (argc != 2) {
        puts("One argument expected.");
        exit(1);
    }
    if (argv[1][0] == '-') {
        puts("Negative integers are not allowed.");
        exit(1);
    }
    uintmax_t value = strtoumax(argv[1], NULL, 10);

    return value;
}

#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Signatures of functions defined later
uintmax_t factorial(uintmax_t);
struct Validation {
   bool isValid;
   char  message[50];
};
struct Validation validateInput(int, char **);

// Entrypoint
int main( int argc, char *argv[] )  {
    // Validate input and exit if invalid
    // TODO: additioanl validation checks, for example integer size
    struct Validation check = validateInput(argc, argv);
    if (check.isValid == false) {
        puts(check.message);
        exit(1);
    }

    // Convert input to integer
    int value = atoi(argv[1]);

    // Report input and calculated result
    printf("Input value: %i\n", value);
    uintmax_t result = factorial(value);
    printf("     Result: %li\n", result);

    return 0;
}

// Calculate factorial
uintmax_t factorial(uintmax_t value) {
    if (value < 2) {
        return 1;
    }
    uintmax_t counter = value -1;
    uintmax_t result = value;
    while (counter > 1) {
        result = result * counter;
        counter--;
    }
    return result;
}

// Validate input parameters
struct Validation validateInput(int argc, char *argv[]) {
    if (argc != 2) {
        return (struct Validation) {
            .message="One argument expected.",
            .isValid=false,
        };
    }
    if (argv[1][0] == '-') {
        return (struct Validation){
            .message="Negative integers are not allowed.",
            .isValid=false,
        };
    }
    return (struct Validation) {
        .message="All systems operational",
        .isValid=true,
    };
}


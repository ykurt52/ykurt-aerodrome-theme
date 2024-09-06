#include "testheader.h"

#define testBIN     (0b000111010101)
#define testHEX     (0x0012323)
#define testOCT     (062626)
#define testDEC     (1278361)

// Global variables
int globalVar = 42;
const double gravity = 9.8;
volatile int sensorValue = 0;

uint32_t yunutest;


jmp_buf env;

int main() {
    // Basic data types
    int a = 10;
    float b = 3.14f;
    double c = 2.71828;
    char d = 'A';
    bool e = true;

    // Extended data types
    uint8_t u8 = 255;
    int16_t s16 = -12345;
    U32 u32 = 1234567890;
    ulong ul = 9876543210UL;

    // String operations
    char str1[] = "Hello, World!";
    char str2[20];
    strcpy(str2, "C Programming");
    stringOperations();

    // Array usage
    int arr[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        printf("Array element: %d\n", arr[i]);
    }

    // Pointer and dynamic memory allocation
    int *ptr = &a;
    int *dynamicArray = (int *)malloc(5 * sizeof(int));
    if (dynamicArray) {
        for (int i = 0; i < 5; i++) {
            dynamicArray[i] = i * 10;
        }
        free(dynamicArray);
    }

    // Struct and union usage
    Point p1 = {10, 20, .info.z = 5.5f};
    Data data = {.i = 10};

    // Enum and bit fields usage
    Weekday today = WEDNESDAY;
    BitFlags flags = {1, 0, 3};

    // Function pointer and inline function usage
    FuncPtr funcPtr = printMessage;
    funcPtr(a);
    int result = multiply(5, 4);

    // Recursive function and variable arguments
    recursiveFunction(5);
    variableArgumentsExample("Test: %d, %f, %s\n", a, b, str1);

    // Longjmp and setjmp example
    if (setjmp(env) == 0) {
        longjmpExample();
    } else {
        printf("Returned from longjmp\n");
    }

    // File operations
    fileOperations();

    // Math operations and random number generation
    double sqrtValue = sqrt(16.0);
    srand(time(NULL));
    int randomValue = rand() % 100;

    // Memory manipulation functions
    memset(arr, 0, sizeof(arr));
    memcpy(str2, str1, strlen(str1) + 1);

    // Ternary operator, switch-case, and goto
    int maxVal = (a > b) ? a : (int)b;

    switch (today) {
        case MONDAY:
            printf("Today is Monday\n");
            break;
        case WEDNESDAY:
            printf("Today is Wednesday\n");
            break;
        default:
            printf("Another day\n");
            break;
    }

    if (maxVal > 50) goto label_end;

    label_end:
    printf("Program end.\n");

    return 0;
}

// Simple function definition
void printMessage(void) {
    printf("Hello from printMessage function!\n");
}

// Recursive function example
void recursiveFunction(int n) {
    if (n > 0) {
        printf("Recursion: %d\n", n);
        recursiveFunction(n - 1);
    }
}

// Variable arguments usage
void variableArgumentsExample(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

// Longjmp and setjmp usage
void longjmpExample(void) {
    printf("Calling longjmp...\n");
    longjmp(env, 1);
}

// String operations example
void stringOperations(void) {
    char s1[] = "Hello";
    char s2[20];
    strcpy(s2, s1);
    strcat(s2, " World");
    printf("Concatenated String: %s\n", s2);

    if (strcmp(s1, s2) != 0) {
        printf("Strings are not equal\n");
    }

    char *found = strchr(s2, 'W');
    if (found) {
        printf("Character 'W' found in string\n");
    }
}

// File operations example
void fileOperations(void) {
    FILE *file = fopen("example.txt", "w");
    if (file) {
        fprintf(file, "Writing to a file.\n");
        fclose(file);
    }

    file = fopen("example.txt", "r");
    if (file) {
        char buffer[50];
        fgets(buffer, sizeof(buffer), file);
        printf("Read from file: %s\n", buffer);
        fclose(file);
    }
}

// Signal handling example
void signalHandler(int signum) {
    printf("Received signal %d\n", signum);
    exit(signum);
}

// Error handling example
void errorHandlingExample(void) {
    FILE *file = fopen("nonexistent.txt", "r");
    if (!file) {
        perror("Error opening file");
        return;
    }
}

// Complex number operations example
void complexNumberOperations(void) {
    double complex z1 = 1.0 + 2.0*I;
    double complex z2 = 1.0 - 2.0*I;
    double complex result = z1 * z2;
    printf("Complex number multiplication: %.2f + %.2fi\n", creal(result), cimag(result));
}

// Memory management example
void memoryManagement(void) {
    int *array = calloc(5, sizeof(int));
    if (array) {
        for (int i = 0; i < 5; i++) {
            array[i] = i;
        }
        free(array);
    }
}

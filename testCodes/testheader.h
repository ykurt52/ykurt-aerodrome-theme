// all_features.h

#ifndef __TESTHEADER_H__
#define __TESTHEADER_H__

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <assert.h>
#include <complex.h>
#include <ctype.h>

// Macro definitions and conditional compilation
#define PI 3.14159
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#if defined(DEBUG)
    #define LOG(msg) printf("DEBUG: %s\n", msg)
#else
    #define LOG(msg)
#endif

// Typedefs
typedef unsigned long ulong;
typedef uint32_t U32;
typedef int (*CompareFunc)(int, int);

// Enum definition
typedef enum {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
} Weekday;

// Struct definition
typedef struct {
    int x;
    int y;
    union {
        float z;
        char label[10];
    } info;
} Point;

// Union definition
typedef union {
    int i;
    float f;
    char str[20];
} Data;

// Bit fields definition
typedef struct {
    unsigned int flag1 : 1;
    unsigned int flag2 : 1;
    unsigned int flag3 : 2;
} BitFlags;

// Function declarations
void printMessage(void);
void recursiveFunction(int n);
void variableArgumentsExample(const char *fmt, ...);
void longjmpExample(void);
int  compareInts(int a, int b);
void stringOperations(void);
void fileOperations(void);
void signalHandler(int signum);
void errorHandlingExample(void);
void complexNumberOperations(void);
void memoryManagement(void);

// Inline function definition
inline int multiply(int a, int b) {
    return a * b;
}

// Global variable declaration
extern int globalVar;
extern const double gravity;
extern volatile int sensorValue;

#endif // __TESTHEADER_H__

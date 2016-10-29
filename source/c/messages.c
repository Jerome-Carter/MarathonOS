#include "headers/vga.h"

void info(const char* message) {
    print("INFO: ");
    print(message);
    print("\n");
}

void warning(const char* message) {
    print("WARNING: ");
    print(message);
    print("\n");
}

void error(const char* message) {
    print("ERROR: ");
    print(message);
    print("\n");
}

void halt(const char* message) {
    print("\nFATAL: ");
    print(message);
    print("\n");
    info("System halted");
}

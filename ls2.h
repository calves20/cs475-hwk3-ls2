#ifndef LS2_H_INCLUDED
#define LS2_H_INCLUDED
// Author @Curtis Alves

#include "stack.h" // Ensure this path is correct and points to your stack implementation

// Constants for readability
#define TRUE 1
#define FALSE 0
#define INDENT "    " // Used for indentation in printing

// Function declarations relevant to the ls2 program

/**
 * Recursively lists files and directories starting from basePath.
 * In mode 1, prints all files and directories with sizes.
 * In mode 2, if matchPattern is provided, prints files that match the pattern.
 * 
 * @param basePath The starting directory path for listing.
 * @param matchPattern The pattern to match file names against (NULL if not used in mode 1).
 * @param depth Current depth in the directory tree for indentation.
 * @param mode Operation mode: 1 for full listing, 2 for pattern matching.
 * @param pathStack Stack used for collecting paths in mode 2.
 */
void listFilesRecursively(const char *basePath, const char *matchPattern, int depth, int mode, stack_t *pathStack);

#endif // LS2_H_INCLUDED

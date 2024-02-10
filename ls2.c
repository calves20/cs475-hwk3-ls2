#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "ls2.h" // Include the header for ls2 program declarations
// Author @Curtis Alves
void listFilesRecursively(const char *basePath, const char *matchPattern, int depth, int mode, stack_t *pathStack) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    char path[1024];

    if (!(dir = opendir(basePath))) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;

        snprintf(path, sizeof(path), "%s/%s", basePath, entry->d_name);
        if (lstat(path, &statbuf) == -1) continue;

        // Mode 1: Print all files and directories with indentation
        if (mode == 1) {
            printf("%*s%s", depth * 4, "", entry->d_name); // Indentation
            if (S_ISDIR(statbuf.st_mode)) {
                printf("/ (directory)\n");
                listFilesRecursively(path, matchPattern, depth + 1, mode, pathStack);
            } else if (S_ISREG(statbuf.st_mode)) {
                printf(" (%lld bytes)\n", (long long) statbuf.st_size);
            }
        } 
        // Mode 2: Filter by exact match pattern and utilize the stack
        else if (mode == 2 && strcmp(entry->d_name, matchPattern) == 0) {
            
            push(pathStack, strdup(path)); // Store a copy of the path in the stack for later use
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        printf("Usage: %s <path> [exact-match-pattern]\n", argv[0]);
        return EXIT_FAILURE;
    }

    stack_t *pathStack = initStack(); // Initialize the stack
    int mode = (argc == 3) ? 2 : 1; // Mode determination based on argument count

    listFilesRecursively(argv[1], argc == 3 ? argv[2] : NULL, 0, mode, pathStack);

    // For Mode 2, you may want to process the stack further
    if (mode == 2) {
        printStack(pathStack); // function needs to be implemented in stack operations
    }

    freeStack(pathStack); // Ensure to free the stack and its contents to avoid memory leaks

    return EXIT_SUCCESS;
}

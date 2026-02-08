#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    struct stat buf;
    
    // NOTE: Make sure a file named "1.3.c" exists in the folder
    // or change this string to a file that actually exists.
    const char *filename = "1.3.c";

    if (stat(filename, &buf) == 0) {
        printf("Total size of the file '%s' is: %ld bytes\n", filename, buf.st_size);
    } else {
        printf("Error: Could not read file stats (File may not exist).\n");
    }

    return 0;
}

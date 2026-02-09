#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int fd;
    char wbuf[] = "Hello World";
    char rbuf[100] = {0}; // Initialize buffer with nulls for safety

    // Step 5: Open the file with Read/Write permissions. 
    // O_CREAT creates the file if it doesn't exist. 
    // O_TRUNC clears the file if it already exists.
    // 0644 gives read/write permission to owner, read to others.
    fd = open("temp.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);

    if (fd < 0) {
        perror("Error opening file");
        exit(1);
    }

    // Step 6: Write data into the file
    int write_sz = write(fd, wbuf, strlen(wbuf));
    printf("Written %d bytes to the file.\n", write_sz);

    // Step 7: Move file pointer to the beginning (SEEK_SET = 0)
    lseek(fd, 0, SEEK_SET);

    // Step 8: Read data from the file
    int read_sz = read(fd, rbuf, sizeof(rbuf));
    
    // Step 9: Display the read content
    printf("Read content from file: %s\n", rbuf);

    // Step 10: Close the file
    close(fd);

    return 0;
}

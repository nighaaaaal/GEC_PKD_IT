#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    char * myfifo = "/tmp/myfifo";

    // Create the FIFO (Named Pipe)
    mkfifo(myfifo, 0666);

    printf("Sender: Writing to pipe...\n");
    // Open in Write mode
    fd = open(myfifo, O_WRONLY);
    
    // Write message
    char msg[] = "Hello from Sender!";
    write(fd, msg, strlen(msg)+1);
    
    printf("Sender: Message sent: %s\n", msg);
    
    close(fd);
    return 0;
}

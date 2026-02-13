#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char * myfifo = "/tmp/myfifo";
    char buf[100];

    printf("Receiver: Waiting for data...\n");
    // Open in Read mode
    fd = open(myfifo, O_RDONLY);
    
    // Read message
    read(fd, buf, 100);
    
    printf("Receiver: Message received: %s\n", buf);
    
    close(fd);
    return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    
    pid = getpid();
    printf("I am in exproc. PID = %d\n", pid);
    
    return 0;
}

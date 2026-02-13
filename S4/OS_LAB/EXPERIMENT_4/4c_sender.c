#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Step 1: Create structure
struct msg_buffer {
    long msg_type;
    char msg_text[100];
} message;

int main() {
    key_t key;
    int msgid;

    // Step 2: Generate Key
    key = ftok("progfile", 65);

    // Step 3: Create Message Queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    message.msg_type = 1;

    // Step 5: Get message
    printf("Write Data : ");
    fgets(message.msg_text, 100, stdin);

    // Step 6: Send message
    msgsnd(msgid, &message, sizeof(message), 0);

    // Step 7: Print
    printf("Data send is : %s\n", message.msg_text);

    return 0;
}

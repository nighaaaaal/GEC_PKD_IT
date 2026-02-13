#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
} message;

int main() {
    key_t key;
    int msgid;

    // Step 2: Generate Key
    key = ftok("progfile", 65);

    // Step 3: Open Queue
    msgid = msgget(key, 0666 | IPC_CREAT);

    // Step 4: Receive message
    msgrcv(msgid, &message, sizeof(message), 1, 0);

    // Step 5: Print
    printf("Data Received is : %s\n", message.msg_text);

    // Step 6: Remove Queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
// Note: Create a dummy file named 'progfile' in the same folder before running.

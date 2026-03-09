#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct BLOCK {
    int size;
    int isallocated;
    int pallocated;
    int psize;
    int frag;
} block[MAX];

int main() {
    int nb, np, p_size[MAX];

    printf("Enter the no: of blocks\n");
    scanf("%d", &nb);

    printf("Enter the size of the blocks\n");
    for (int i = 0; i < nb; i++) {
        printf("Block%d: ", i);
        scanf("%d", &block[i].size);
        if (block[i].size < 0) {
            printf("Invalid Input\n");
            exit(0);
        }
        block[i].isallocated = 0;
        block[i].pallocated = -1; 
        block[i].psize = 0;
        block[i].frag = block[i].size;
    }

    printf("Enter the no: of processes\n");
    scanf("%d", &np);

    printf("Enter the size of the processes\n");
    for (int i = 0; i < np; i++) {
        printf("Process%d: ", i);
        scanf("%d", &p_size[i]);
        if (p_size[i] < 0) {
            printf("Invalid Input\n");
            exit(0);
        }
    }

    // Allocation logic: Best Fit
    for (int i = 0; i < np; i++) {
        int best_idx = -1;
        for (int j = 0; j < nb; j++) {
            if (block[j].isallocated == 0 && block[j].size >= p_size[i]) {
                if (best_idx == -1 || block[j].size < block[best_idx].size) {
                    best_idx = j;
                }
            }
        }
        
        if (best_idx != -1) {
            block[best_idx].isallocated = 1;
            block[best_idx].pallocated = i;
            block[best_idx].psize = p_size[i];
            block[best_idx].frag = block[best_idx].size - p_size[i];
            printf("Process%d is allocated to block%d\n", i, best_idx);
        }
    }

    // Display Output
    printf("\nBlock\tIsallocated\tProcess_allocated\tBlockSize\tPSize\tFragment\n");
    for (int i = 0; i < nb; i++) {
        printf("%d\t%d\t\t", i, block[i].isallocated);
        if (block[i].isallocated == 1)
            printf("%d\t\t\t", block[i].pallocated);
        else
            printf("-\t\t\t");
        
        printf("%d\t\t%d\t%d\n", block[i].size, block[i].psize, block[i].frag);
    }

    return 0;
}

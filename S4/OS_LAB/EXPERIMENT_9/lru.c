#include <stdio.h>
#include <stdlib.h>

int main() {
    int frames_count, pages_count, page_faults = 0;

    printf("Enter number of frames: ");
    scanf("%d", &frames_count);
    if (frames_count <= 0) { printf("Invalid Input\n"); exit(0); }

    printf("Enter number of pages: ");
    scanf("%d", &pages_count);
    if (pages_count < 0) { printf("Invalid Input\n"); exit(0); }

    int pages[pages_count], frames[frames_count], last_used[frames_count];

    printf("Enter the page reference string: ");
    for (int i = 0; i < pages_count; i++) {
        scanf("%d", &pages[i]);
        if (pages[i] < 0) { printf("Invalid Input\n"); exit(0); }
    }

    // Initialize frames and last_used to -1
    for (int i = 0; i < frames_count; i++) {
        frames[i] = -1;
        last_used[i] = -1;
    }

    // Allocate pages (LRU)
    for (int i = 0; i < pages_count; i++) {
        int is_hit = 0;
        int lru_index = 0, minimum_time = i;

        // Check for hit and update last used time
        for (int j = 0; j < frames_count; j++) {
            if (frames[j] == pages[i]) {
                is_hit = 1;
                last_used[j] = i; 
                break;
            }
        }

        // If miss, find LRU and replace
        if (is_hit == 0) {
            for (int j = 0; j < frames_count; j++) {
                if (frames[j] == -1) { 
                    lru_index = j; 
                    break; 
                }
                if (last_used[j] < minimum_time) {
                    minimum_time = last_used[j];
                    lru_index = j;
                }
            }
            frames[lru_index] = pages[i];
            last_used[lru_index] = i;
            page_faults++;
        }
    }

    printf("Total Page Faults (LRU) = %d\n", page_faults);
    return 0;
}

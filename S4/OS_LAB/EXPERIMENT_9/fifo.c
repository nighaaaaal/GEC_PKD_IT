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

    int pages[pages_count], frames[frames_count];

    printf("Enter the page reference string: ");
    for (int i = 0; i < pages_count; i++) {
        scanf("%d", &pages[i]);
        if (pages[i] < 0) { printf("Invalid Input\n"); exit(0); }
    }

    // Step 5: Initialize frames to -1
    for (int i = 0; i < frames_count; i++) {
        frames[i] = -1;
    }

    // Step 6: Allocate pages (FIFO)
    int next_frame_to_replace = 0;
    for (int i = 0; i < pages_count; i++) {
        int is_hit = 0;

        // Check for hit
        for (int j = 0; j < frames_count; j++) {
            if (frames[j] == pages[i]) {
                is_hit = 1;
                break;
            }
        }

        // If miss, replace using FIFO
        if (is_hit == 0) {
            frames[next_frame_to_replace] = pages[i];
            next_frame_to_replace = (next_frame_to_replace + 1) % frames_count;
            page_faults++;
        }
    }

    // Step 7: Display page faults
    printf("Total Page Faults (FIFO) = %d\n", page_faults);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    int frames_count, pages_count, page_faults = 0;

    printf("Enter number of frames: ");
    scanf("%d", &frames_count);
    if (frames_count <= 0) { printf("Invalid Input\n"); exit(0); }

    printf("Enter number of pages: ");
    scanf("%d", &pages_count);

    int pages[pages_count], frames[frames_count];

    printf("Enter the page reference string: ");
    for (int i = 0; i < pages_count; i++) {
        scanf("%d", &pages[i]);
        if (pages[i] < 0) { printf("Invalid Input\n"); exit(0); }
    }

    for (int i = 0; i < frames_count; i++) {
        frames[i] = -1;
    }

    // Allocate pages (Optimal)
    for (int i = 0; i < pages_count; i++) {
        int is_hit = 0;

        for (int j = 0; j < frames_count; j++) {
            if (frames[j] == pages[i]) {
                is_hit = 1;
                break;
            }
        }

        if (is_hit == 0) {
            int optimal_index = -1;
            int farthest = i;

            for (int j = 0; j < frames_count; j++) {
                if (frames[j] == -1) {
                    optimal_index = j;
                    break;
                }
                int next_use = -1;
                for (int k = i + 1; k < pages_count; k++) {
                    if (frames[j] == pages[k]) {
                        next_use = k;
                        break;
                    }
                }
                if (next_use == -1) { // Page never used again
                    optimal_index = j;
                    break;
                }
                if (next_use > farthest) {
                    farthest = next_use;
                    optimal_index = j;
                }
            }
            frames[optimal_index] = pages[i];
            page_faults++;
        }
    }

    printf("Total Page Faults (Optimal) = %d\n", page_faults);
    return 0;
}

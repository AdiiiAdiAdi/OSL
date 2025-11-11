#include <stdio.h>
#include <stdlib.h>

int search(int key, int frame[], int size) {   //key is the current page, frame is the list, size is capacity
    for (int i = 0; i < size; i++) {
        if (frame[i] == key)
            return 1;  //found
    }
    return 0;  //not found
}

int main() {
    int pages[50], frames[10];
    int n, capacity;
    int front = 0, rear = 0;  
    int pageFault = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter frame capacity: ");
    scanf("%d", &capacity);

   
    for (int i = 0; i < capacity; i++)
        frames[i] = -1;   

    printf("\nFIFO Page Replacement Process:\n");

//get the current page
    for (int i = 0; i < n; i++) {
        int current_page = pages[i];


        if (!search(current_page, frames, capacity)) {
        pageFault++;

            //FIFO
            if (rear < capacity) {
                frames[rear] = current_page;
                rear++;
            } else {
                
                frames[front] = current_page;
                front = (front + 1) % capacity;
            }

            

            //print
            printf("Page %d -> ", current_page);
            for (int k = 0; k < capacity; k++) {
                if (frames[k] != -1)
                    printf("%d ", frames[k]);
                else
                    printf("- ");
            }
            printf("\n");
        } else {
            
            printf("Page %d -> No page fault\n", current_page);
        }
    }

    printf("\nTotal Page Faults = %d\n", pageFault);

    return 0;
}


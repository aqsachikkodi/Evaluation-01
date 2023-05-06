#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[10], i;
    FILE *fp;

    // Open file for writing
    fp = fopen("numbers.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    // Write 10 numbers to file
    printf("Enter 10 numbers:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
        fprintf(fp, "%d ", arr[i]);
    }

    // Close file
    fclose(fp);

    // Open file for reading
    fp = fopen("numbers.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    // Read numbers from file and store in array
    for (i = 0; i < 10; i++) {
        fscanf(fp, "%d", &arr[i]);
    }

    // Close file
    fclose(fp);

    // Sort array
    bubbleSort(arr, 10);

    // Open file for writing
    fp = fopen("sorted_numbers.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    // Write sorted numbers to file
    for (i = 0; i < 10; i++) {
        fprintf(fp, "%d ", arr[i]);
    }

    // Close file
    fclose(fp);

    printf("Numbers have been sorted and saved to file 'sorted_numbers.txt'.\n");

    return 0;
}





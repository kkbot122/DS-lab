#include <stdio.h>

void selectionsort(int arr[], int n) {
    int i, j, temp;

    for(i=0; i<n-1; i++){
        int min_idx = i;
        for(j = i+1; j<n; j++){
            if(arr[j]< arr[min_idx]){
                min_idx = j;
            }    
        }
        temp = arr[j];
        arr[j] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {
    int arr[] = {6, 3, 5, 2, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionsort(arr, n);

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

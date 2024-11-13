#include <stdio.h>

void bubblesortRecursion(int arr[], int n){

    if(n == 1){
        return;
    }
    
    for(int i = 0; i < n-1; i++){
        if(arr[i] > arr[i+1]){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp; 
        }
    }

    bubblesortRecursion(arr, n-1);
}

int main() {
    int arr[] = {6, 3, 5, 2, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubblesortRecursion(arr, n);


    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

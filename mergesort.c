#include <stdio.h>

void merge(int a[], int b[], int m, int n){

    int i,j,k;
    i=j=k=0;
    int c[100];
    
    while (i<m && j<n)
    {
        if(a[i]<b[j]){
            c[k]=a[i];
            k++;
            i++;
        }
        else{
            c[k] = b[j];
            k++;
            j++;
        }
    }
    while (i<m)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j<n)
    {
        c[k] = b[j];
        k++;
        j++;
    }


    printf("Sorted array: ");
    for (int i = 0; i < m+n; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");
}

void mergeinone(int a[], int low, int mid, int high) {
    int i = low; 
    int j = mid + 1;
    int k = 0;
    int c[high - low + 1];

    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        c[k] = a[i];
        i++;
        k++;
    }

    while (j <= high) {
        c[k] = a[j];
        j++;
        k++;
    }

    for (i = low, k = 0; i <= high; i++, k++) {
        a[i] = c[k];
    }
}

void mergesort(int a[], int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        mergesort(a, low, mid);
        mergesort(a, mid+1, high);

        mergeinone(a, low, mid, high);
    }
}
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergesort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
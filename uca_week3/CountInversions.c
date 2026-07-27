#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right, int *count) {
    int *tempArr = (int *)malloc((right - left + 1) * sizeof(int));

    int i = left;
    int j = mid + 1;
    int pos = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            tempArr[pos++] = arr[i++];
        } else {
            *count += (mid - i + 1);
            tempArr[pos++] = arr[j++];
        }
    }

    while (i <= mid) {
        tempArr[pos++] = arr[i++];
    }

    while (j <= right) {
        tempArr[pos++] = arr[j++];
    }

    for (int k = left; k <= right; k++) {
        arr[k] = tempArr[k - left];
    }

    free(tempArr);
}

void mergeSort(int arr[], int left, int right, int *count) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, count);
    mergeSort(arr, mid + 1, right, count);

    merge(arr, left, mid, right, count);
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;

    mergeSort(arr, 0, n - 1, &count);

    printf("%d", count);

    free(arr);
    return 0;
}
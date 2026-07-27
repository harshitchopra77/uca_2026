#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right) {
    int *tempArr = (int *)malloc((right - left + 1) * sizeof(int));

    int i = left;
    int j = mid + 1;
    int pos = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            tempArr[pos++] = arr[i++];
        } else {
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

void countPairs(int arr[], int left, int mid, int right, int *pairs) {
    int ptr = mid + 1;

    for (int idx = left; idx <= mid; idx++) {
        while (ptr <= right && arr[idx] > 2LL * arr[ptr]) {
            ptr++;
        }
        *pairs += ptr - (mid + 1);
    }
}

void mergeSort(int arr[], int left, int right, int *pairs) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, pairs);
    mergeSort(arr, mid + 1, right, pairs);

    countPairs(arr, left, mid, right, pairs);
    merge(arr, left, mid, right);
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int pairs = 0;
    mergeSort(arr, 0, n - 1, &pairs);

    printf("total pairs %d", pairs);

    free(arr);
    return 0;
}
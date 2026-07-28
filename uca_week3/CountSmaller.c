#include<stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int index;
} pair;

void merge(pair *arr, int *res, int s,int mid,int e){
    pair *temp = (pair*)malloc((e-s+1) * sizeof(pair));

    int l = s;
    int r = mid + 1;
    int k = 0;

    int rightCount = 0;

    while (l <= mid && r <= e) {
        if (arr[r].val < arr[l].val) {
            temp[k++] = arr[r++];
            rightCount++;
        } else {
            res[arr[l].index] += rightCount;
            temp[k++] = arr[l++];
        }
    }

    while (l <= mid) {
        res[arr[l].index] += rightCount;
        temp[k++] = arr[l++];
    }
    while (r <= e) {
        temp[k++] = arr[r++];
    }
    for (int i = s; i <= e; i++) {
        arr[i] = temp[i - s];
    }

    free(temp);
}

void mergeSort(pair *arr, int *res, int s, int e) {
    if (s>=e){
        return;
    }
    int mid =s+(e-s)/2;
    mergeSort(arr, res, s, mid);
    mergeSort(arr, res, mid + 1, e);
    merge(arr, res, s, mid, e);
}

void CountSmallNumSelf(pair *arr ,int *res,int n){
    mergeSort(arr,res,0,n-1);
}

int main(){
    int n;
    scanf("%d",&n);
    pair *arr = (pair*)malloc(n*sizeof(pair));
    for(int i =0 ; i<n ; i++){
        scanf("%d", &arr[i].val);
        arr[i].index = i;
    }

    int *res = (int*)calloc(n,sizeof(int));

    CountSmallNumSelf(arr,res,n);
    for(int i = 0 ; i<n ; i++){
        printf("%d ",res[i]);
    }
    free(res);
    free(arr);
}
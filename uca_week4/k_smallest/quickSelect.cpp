#include <bits/stdc++.h>

using namespace std;

int pivot( int s, int e) {
    int pivotIndex = s + rand() % (e - s + 1);
    return pivotIndex;
}

int partition(vector<int>& arr, int s, int e) {
    int pivotIndex = pivot(s, e);
    swap(arr[pivotIndex], arr[e]);
    int pivotValue = arr[e];
    int i = s;
    for (int j = s; j < e; j++) {
        if (arr[j] <= pivotValue) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[e]);
    return i;  
}


void quickSelect(vector<int>& arr, int s, int e, int k) {
    if (s >= e)
        return;
    int p = partition(arr, s, e);
    int count = p - s + 1;
    if (count == k) {
        return;
    }
    else if (k < count) {
        quickSelect(arr, s, p - 1, k);
    }
    else {
        quickSelect(arr, p + 1, e, k - count);
    }
}


vector<int> smallestK(vector<int> arr, int k) {
    quickSelect(arr, 0, arr.size() - 1, k);
    vector<int> result;
    for (int i = 0; i < k; i++)
        result.push_back(arr[i]);
    return result;
}


int main() {
    srand(time(0));
    vector<int> arr = {
        10, 3, 5, 7, 2, 8, 1, 9, 6, 4
    };
    int k = 5;
    vector<int> ans = smallestK(arr, k);
    cout << "Smallest " << k << " elements:\n";
    for (int x : ans)
        cout << x << " ";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr,int n,int i){
    int lar=i;
    int l=i*2+1;
    int r=i*2+2;

    if(l<n && arr[l]>arr[lar]) lar=l;
    if(r<n && arr[r]>arr[lar]) lar=r;

    if(lar!=i){
        swap(arr[lar],arr[i]);
        heapify(arr,n,lar);
    }

}

void heapsort(vector<int>& arr,int n){

    for(int i=n/2 -1 ;i>=0;i--){
        heapify(arr,n,i);
    }

    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

int main(){
    int n;
    cout<<"enter size of array: ";
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cout<<"enter the element: ";
        cin>>arr[i];
    }

    heapsort(arr,n);

    cout<<"the sorted array: ";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

}
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr={1, 2, 3, 4, 1, 2, 4, 1, 2, 3, 4, 3, 3};

    int num=0;
    for(int b=0;b<32;b++){

        int count=0;
        for(int num:arr){
            if(num & (1<<b)){
                count++;
            }
        }
        if(count%3!=0){
            num=num|(1<<b);
        }
    }
    cout<<num;
}
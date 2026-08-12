#include <bits/stdc++.h>
using namespace std;

void setzero(vector<vector<int>>& matrix,int m,int n){\
    bool rowcheck=false;
    bool colcheck=false;
    for(int i=0;i<m;i++){
        if(matrix[i][0]==0){
            colcheck=true;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(matrix[0][i]==0){
            rowcheck=true;
            break;
        }
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(matrix[i][j]==0){
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(matrix[i][0]==0 || matrix[0][j]==0){
                matrix[i][j]=0;
            }
        }
    }

    if(rowcheck){
        for(int i=0;i<n;i++){
            matrix[0][i]=0;
        }
    }
    if(colcheck){
        for(int i=0;i<m;i++){
            matrix[i][0]=0;
        }
    }
}

void print(vector<vector<int>>& matrix,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int m,n;
    cout<<"enter dimensions: ";
    cin>>m>>n;
    vector<vector<int>> matrix(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<"enter the "<<i<<" "<<j<<" element";
            cin>>matrix[i][j];
        }
    }

    setzero(matrix,m,n);
    print(matrix,m,n);
}
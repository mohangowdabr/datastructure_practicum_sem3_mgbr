#include<iostream>
using namespace std;

int main(){
    int m,n;
    cout<<"Enter number of rows: ";
    cin>>m;
    cout<<"Enter number of columns: ";
    cin>>n;

    int arr2[m][n];

    cout<<"Enter elements:"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr2[i][j];
        }
    }

    cout<<"Array elements:"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<"arr2["<<i<<"]["<<j<<"] = "<<arr2[i][j]<<endl;
        }
    }

    int row,column,newValue;
    cout<<"Enter row: ";
    cin>>row;
    cout<<"Enter column: ";
    cin>>column;
    cout<<"Enter new value: ";
    cin>>newValue;

    arr2[row][column]=newValue;

    cout<<"Updated array:"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
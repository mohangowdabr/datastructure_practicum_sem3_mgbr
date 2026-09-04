#include<iostream>
using namespace std;
int main(){
    int m,n;
    cout<<"Enter the number of ROWS: ";
    cin>>m;
    cout<<"Enter the number of COLUMNS: ";
    cin>>n;
    int arr2[m][n];
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr2[i][j];
        }
    }
    cout<<"Array elements are :"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<"arr2["<<i<<"]["<<j<<"] = "<<arr2[i][j]<<endl;
        }
    }
    int row,column,newValue;
    cout<<"Enter the ROW: ";
    cin>>row;
    cout<<"Enter the COLUMN: ";
    cin>>column;
    cout<<"Enter new VALUE: ";
    cin>>newValue;

    arr2[row][column]=newValue;

    cout<<"Updated array Will be:"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

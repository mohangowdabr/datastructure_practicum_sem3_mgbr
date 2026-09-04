#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of an array: ";
    cin>>n;
    int arr1[n];
    cout<<"Enter "<<n<<" Elements : ";
    for(int i=0; i<n; i++){
        cin>>arr1[i];
    }
    cout<<"Array : ";
    for(int i=0; i<n; i++){
        cout<<arr1[i]<<" " << endl;
    }
    cout<<"Enter index  to modify: ";
    int index;
    cin>>index;
    cout<<"Enter value to modify: ";
    int value;
    cin>>value;
    arr1[index]=value;
    cout<<"Modified Array : ";
    for(int i=0; i<n; i++){
        cout<<arr1[i]<<" " << endl;
    }
    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    int n;

   
    cout << "Enter the size of array: ";
    cin >> n;

    int arr1[n];

  
    cout << "Enter " << n << " elements:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    
    cout << "\nOriginal Array:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }

   
    int index, newValue;

    cout << "\n\nEnter index to modify: ";
    cin >> index;

    cout << "Enter new value: ";
    cin >> newValue;

    arr1[index] = newValue;

   
    cout << "\nModified Array:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }

    return 0;
}
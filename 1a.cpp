#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Size: ";
    cin >> n;
    int arr[n];
    
    // Input
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    // Display
    cout << "Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    // Modify
    int idx, val;
    cout << "\nIndex: ";
    cin >> idx;
    cout << "New value: ";
    cin >> val;
    arr[idx] = val;
    
    // Display modified
    cout << "Modified: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    return 0;
}

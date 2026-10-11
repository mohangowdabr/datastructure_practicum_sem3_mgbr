#include <iostream>
using namespace std;
int main() {
    int n;
     int arr1[n];
     int key;
    bool found = false;
    cout << "Enter number of elements:\n ";
    cin >> n;
    cout << "Enter elements: \n";
    for (int i = 0; i < n; i++){
        cin >> arr1[i];
    }
    cout << "Enter element to search: \n";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr1[i] == key) {
            cout << "Element found at position  \n" << i + 1 << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Element not found \n" << endl;
    }
    return 0;
}

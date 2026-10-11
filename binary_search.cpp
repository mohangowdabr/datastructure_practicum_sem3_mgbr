// #include <iostream>
// using namespace std;
// int main() {
//     int n, arr[100], key;
//     bool found = false;
//     cout << "Enter number of elements: ";
//     cin >> n;
//     cout << "Enter elements in sorted order: ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     cout << "Enter element to search: ";
//     cin >> key;
//     int low = 0;
//     int high = n - 1;
//     while (low <= high) {
//         int mid = (low + high) / 2;
//         if (arr[mid] == key) {
//             cout << "Element found at position " << mid + 1 << endl;
//             found = true;
//             break;
//         }
//         else if (key < arr[mid]) {
//             high = mid - 1;
//         }
//         else {
//             low = mid + 1;
//         }
//     }
//     if (!found) {
//         cout << "Element not found" << endl;
//     }
//     return 0;
// }
#include <iostream>
using namespace std;

int main() {
    int n, arr[100], key;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> key;

    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            cout << "Element found at position " << mid + 1 << endl;
            return 0;
        }

        if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    cout << "Element not found" << endl;
    return 0;
}
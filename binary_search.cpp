Binary Search
#include <iostream>
using namespace std;
int main()
{
 int n, arr[100], key;
 int low, high, mid;
 int comparisons = 0, found = 0;
 cout << "Enter number of elements: ";
 cin >> n;
 if (n < 1 || n > 100)
 {
 cout << "Invalid number of elements!";
 return 0;
 }
 cout << "Enter array elements in ascending order:"
 << endl;
 for (int i = 0; i < n; i++)
 {
 cin >> arr[i];
 }
 for (int i = 0; i < n - 1; i++)
 {
 if (arr[i] > arr[i + 1])
 {
 cout << "Array must be sorted!";
 return 0;
 }
 }
 cout << "Enter element to search: ";
 cin >> key;
 low = 0;
 high = n - 1;
 while (low <= high)
 {
 mid = low + (high - low) / 2;
 comparisons++;
 if (arr[mid] == key)
 {
 found = 1;
 break;
 }
 else if (key < arr[mid])
 {
 high = mid - 1;
 }
 else
 {
 low = mid + 1;
 }
 }
 if (found == 1)
 {
 cout << "Element found!" << endl;
 cout << "Position: " << mid + 1 << endl;
 }
 else
 {
 cout << "Element not found!" << endl;
 }
 cout << "Number of comparisons: "
 << comparisons << endl;
 return 0;
}

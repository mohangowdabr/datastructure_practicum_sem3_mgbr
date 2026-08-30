#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Rows & Columns: ";
    cin >> m >> n;
    int arr[m][n];
    
    // Input
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    // Display
    cout << "Matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
    
    // Modify
    int r, c, val;
    cin >> r >> c >> val;
    arr[r][c] = val;
    
    // Display modified
    cout << "Modified:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
    
    return 0;
}

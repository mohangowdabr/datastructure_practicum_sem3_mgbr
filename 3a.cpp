#include <iostream>
using namespace std;

void hanoi(int n, char from, char aux, char to) {
    if (n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << "\n";
        return;
    }
    
    // Move n-1 disks from 'from' to 'aux' using 'to'
    hanoi(n - 1, from, to, aux);
    
    // Move largest disk from 'from' to 'to'
    cout << "Move disk " << n << " from " << from << " to " << to << "\n";
    
    // Move n-1 disks from 'aux' to 'to' using 'from'
    hanoi(n - 1, aux, from, to);
}

int main() {
    int n;
    cout << "Disks: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Invalid!\n";
        return 0;
    }
    
    cout << "Steps:\n";
    hanoi(n, 'A', 'B', 'C');
    
    return 0;
}

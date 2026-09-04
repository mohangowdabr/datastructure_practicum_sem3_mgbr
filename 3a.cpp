#include <iostream>
using namespace std;
void towerOfHanoi(int n, char source, char destination, char auxiliary)
{
	if (n == 0)
		return;
	towerOfHanoi(n - 1, source, auxiliary, destination);
	cout << "Move disk " << n << " from " << source << " to " << destination << endl;
	towerOfHanoi(n - 1, auxiliary, destination, source);
}
int main(){

	int n;
	cout << "Enter disks: ";
	cin >> n;
	if (n <= 0)
	{
		cout << "Must be > 0" << endl;
		return 0;
	}
	cout << "\nSolution:\n"; 
	towerOfHanoi(n, 'A', 'C', 'B');
	cout << "\nTotal moves: " << (1LL << n) - 1 << endl;
	return 0;
}



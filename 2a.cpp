#include <iostream>
using namespace std;
int main()
{
	const int capacity = 5;
	string history[capacity];
	int top = -1;
	int choice;
	string page;
	do
	{
		cout << "\n1. Visit a page\n2. Back\n3. Current page\n4. History\n5. Exit\n";
		cout << "Choice: ";
		cin >> choice;
		cin.ignore();  
		switch (choice)
		{
		case 1:
			if (top == capacity - 1)
				cout << "History full.\n";
			else
			{
				cout << "Enter page: ";
				getline(cin, page); 
				history[++top] = page;
				cout << "Page visited.\n";
			}
			break;

		case 2:
			if (top <= -1)
				cout << "No previous page.\n";
			else
			{
				cout << "Going back from " << history[top] << ".\n";
				--top;
				if(top >= 0)
					cout << "Current: " << history[top] << "\n";
			}
			break;

		case 3:
			if (top == -1)
				cout << "History empty.\n";
			else
				cout << "Current: " << history[top] << "\n";
			break;

		case 4:
			if (top == -1)
				cout << "History empty.\n";
			else
			{
				for (int i = top; i >= 0; i--)
					cout << history[i] << '\n';
			}
			break;

		case 5:
			cout << "Exit.\n";
			break;

		default:
			cout << "Invalid.\n";
		}
	} while (choice != 5);

	return 0;
}


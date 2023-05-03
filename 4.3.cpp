#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod1, char aux_rod2)
{
	if (n == 0)
		return;
	if (n == 1)
	{
		cout << "\n Move disk " << n << " from rod " << from_rod << " to rod " << to_rod;
		return;
	}

	towerOfHanoi(n - 2, from_rod, aux_rod1, aux_rod2, to_rod);
	cout << "\n Move disk " << n - 1 << " from rod " << from_rod << " to rod " << aux_rod2;

	cout << "\n Move disk " << n << " from rod " << from_rod << " to rod " << to_rod;

	cout << "\n Move disk " << n - 1 << " from rod " << aux_rod2 << " to rod " << to_rod;

	towerOfHanoi(n - 2, aux_rod1, to_rod, from_rod, aux_rod2);
}

int main()
{
	int n;
	cout << "Enter no. of disks : ";
	cin >> n;
	towerOfHanoi(n, 'A', 'D', 'B', 'C');
	return 0;
}

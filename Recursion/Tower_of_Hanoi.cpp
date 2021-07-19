#include <iostream>

using namespace std;

void tower_of_hanoi(int n, char src, char aux, char dst) {
	
	if (n == 1) {
		cout << "Move disk 1 from " <<  src << " rod to " << dst << " rod\n";
		return;
	}

	tower_of_hanoi(n - 1, src, dst, aux);

	cout << "Move disk " << n << " from " << src << " rod to " << dst << " rod\n";

	tower_of_hanoi(n - 1, aux, src, dst);
} // end of tower_of_hanoi(int, char, char, char)

int main() {
	
	int number_of_disks;
	cout << "Enter the number of disks: ";
	cin >> number_of_disks;
	
	cout << "\n";
	tower_of_hanoi(number_of_disks, 'A', 'B', 'C');

	return 0;
} // end of main()

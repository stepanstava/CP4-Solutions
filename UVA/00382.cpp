// 382 Perfection
#include <iostream>
#include <iomanip> 

using namespace std;

void run_case(int n) {

	int sum = 1;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			sum += i;
		}
	}

	cout << setw(5) << n << "  ";

	if (n == 1)
	{
		cout << "DEFICIENT\n";
	}
	else if (sum == n) {
		cout << "PERFECT\n";
	}
	else if (sum > n) {
		cout << "ABUNDANT\n";
	}
	else {
		cout << "DEFICIENT\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cout << "PERFECTION OUTPUT\n";
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		run_case(n);
		cout << flush;
	}
	cout << "END OF OUTPUT\n";
	return 0;
}

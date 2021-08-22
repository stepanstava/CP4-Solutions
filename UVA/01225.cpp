// 1225 Digit Counting
#include <iostream>

using namespace std;

void run_case(int tc) {
	int n;
	int digits[15] = { 0 };
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int digit = i;

		while (digit > 0) {
			digits[digit % 10] += 1;
			digit /= 10;
		}
	}

	for (int i = 0; i < 10; i++) {
		cout << digits[i];
		if (i != 9) {
			cout << " ";
		}
		else {
			cout << "\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ttc;
	cin >> ttc;
	for (int tc = 1; tc <= ttc; tc++) {
		run_case(tc);
		cout << flush;
	}
	return 0;
}

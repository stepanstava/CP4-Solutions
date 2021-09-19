// 10656 Maximum Sum (II)
#include <iostream>

using namespace std;

void run_case(int n) {
	bool noOutput = true;
	bool isFirst = true;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num > 0) {
			if (!isFirst) {
				cout << " ";
			}
			cout << num;
			noOutput = false;
			isFirst = false;
		}
	}

	if (noOutput) {
		cout << 0;
	}

	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		run_case(n);
		cout << flush;
	}

	return 0;
}

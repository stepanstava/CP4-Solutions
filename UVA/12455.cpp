// 12455 Bars
#include <iostream>

using namespace std;

void run_case(int tc) {
	int n, p;
	cin >> n >> p;

	int tmp;
	int nums[25];
	for (int i = 0; i < p; i++) {
		cin >> tmp;
		nums[i] = tmp;
	}

	bool found = false;
	for (int i = 0; i < (1 << p); ++i) {
		int sum = 0;
		for (int j = 0; j < p; ++j) {
			if (i & (1 << j)) {
				sum += nums[j];
			}
		}
		if (sum == n) {
			found = true;
			break;
		}
	}

	if (found) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
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

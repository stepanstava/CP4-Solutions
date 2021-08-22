// 729 The Hamming Distance Problem
#include <iostream>
#include <vector>

using namespace std;

int n, h;
vector<int> nums(16);

void backtrack(int i, int ones) {
	if (i == n && ones == h) {
		for (int i = 0; i < n; i++) {
			cout << nums[i];
		}
		cout << "\n";
		return;
	}

	if (i == n) {
		return;
	}

	nums[i] = 0;
	backtrack(i + 1, ones);

	if (ones < h) {
		nums[i] = 1;
		backtrack(i + 1, ones + 1);
	}
}

void run_case() {
	cin >> n >> h;

	backtrack(0, 0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ttc;
	cin >> ttc;
	for (int tc = 1; tc <= ttc; tc++) {
		run_case();
		cout << flush;
		if (tc != ttc) {
			cout << "\n";
		}
	}
	return 0;
}

// 11369 Shopaholic
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int x, int y) {
	return x > y;
}

void run_case(int tc) {
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end(), comp);

	int maxSave = 0;
	for (int i = 2; i < n; i += 3) {
		maxSave += nums[i];
	}

	cout << maxSave << "\n";
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

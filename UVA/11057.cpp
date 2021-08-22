// 11057 Exact Sum
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void run_case(int n) {
	vector<int> nums(n);
	int targetSum;

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());

	cin >> targetSum;

	int l = 0;
	int r = n - 1;
	int priceX, priceY;
	int diffMin = INT_MAX;
	while (l < r) {
		int sum = nums[l] + nums[r];

		if (sum == targetSum) {
			int diff = nums[r] - nums[l];
			if (diff < diffMin) {
				diffMin = diff;
				priceX = nums[l];
				priceY = nums[r];
				l++;
				r--;
			}
		}
		else if (sum < targetSum) {
			l++;
		}
		else {
			r--;
		}
	}
	cout << "Peter should buy books whose prices are " << priceX << " and " << priceY << ".\n\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while (cin >> n) {
		if (cin.eof()) {
			break;
		}

		run_case(n);
		cout << flush;
	}

	return 0;
}

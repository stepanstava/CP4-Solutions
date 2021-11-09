// 108 Maximum Sum
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

void run_case(int n) {
	vector<vector<int>> nums(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> nums[i][j];
			if (j > 0) {
				nums[i][j] += nums[i][j - 1];	// pre-processing
			}
		}
	}

	int maxSubSum = INT_MIN;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int subSum = 0;
			for (int row = 0; row < n; row++) {
				if (i > 0) {
					subSum += nums[row][j] - nums[row][i - 1];
				}
				else {
					subSum += nums[row][j];
				}

				if (subSum < 0) {
					subSum = 0;
				}
				maxSubSum = max(maxSubSum, subSum);
			}
		}
	}

	cout << maxSubSum << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while (cin >> n) {
		run_case(n);
		cout << flush;
	}


	return 0;
}

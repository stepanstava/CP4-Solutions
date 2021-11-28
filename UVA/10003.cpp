// Cutting Sticks
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

int l, n;
int nums[55], memo[55][55];

int dp(int begin, int end) {
	if (begin + 1 == end) {
		return 0;
	}

	if (memo[begin][end] != -1) {
		return memo[begin][end];
	}

	int cost = INT_MAX;
	for (int i = begin + 1; i < end; i++) {
		int leftSide = dp(begin, i);
		int rightSide = dp(i, end);

		cost = min(cost, leftSide + rightSide + (nums[end] - nums[begin]));
		memo[begin][end] = cost;
	}

	return cost;
}


void run_case() {
	memset(memo, -1, sizeof memo);

	cin >> n;
	nums[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	nums[n + 1] = l;

	cout << "The minimum cutting is " << dp(0, n + 1) << ".\n";

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> l) {
		if (l == 0) {
			break;
		}
		run_case();
		cout << flush;
	}
	return 0;
}

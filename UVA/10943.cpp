// 10943 How do you add?
#include <iostream>
#include <cstring>

using namespace std;

int n, k;
int memo[105][105];

int dp(int n_left, int k_used) {
	if (n_left == 0 && k_used == k) {
		return 1;
	}
	if (n_left < 0 || k_used == k) {
		return 0;
	}

	if (memo[n_left][k_used] != -1) {
		return memo[n_left][k_used];
	}

	int ways = 0;
	for (int i = 0; i <= n; i++) {
		ways = (ways + dp(n_left - i, k_used + 1)) % 1000000;
		memo[n_left][k_used] = ways;
	}
	return ways;
}


void run_case() {
	memset(memo, -1, sizeof memo);

	int ans = dp(n, 0);
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n >> k) {
		if (n == 0 && k == 0) {
			break;
		}
		run_case();
		cout << flush;
	}
	return 0;
}

// 674 Coin Change
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int coins_num = 5;
const int cents = 7500;
int coins[coins_num] = { 1, 5, 10, 25, 50 };
int memo[coins_num][cents];

int solve(int type, int left) {
	if (left == 0) {
		return 1;
	}

	if (left < 0) {
		return 0;
	}

	if (type == coins_num) {
		return 0;
	}

	int &ans = memo[type][left];

	if (ans != -1) {
		return ans;
	}

	return ans = solve(type + 1, left) + solve(type, left - coins[type]);
}

void run_case(int n) {
	int solutions = solve(0, n);
	cout << solutions << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(memo, -1, sizeof memo);

	int n;
	while (cin >> n) {
		run_case(n);
		cout << flush;
	}

	return 0;
}

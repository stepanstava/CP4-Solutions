// 10130 SuperSale
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> price(1005);
vector<int> weight(1005);
vector<vector<int>> memo(1005, vector<int>(35));

int dp(int i, int carryLeft) {
	if (i == n) {	
		return 0;
	}

	if (carryLeft == 0) { 
		return 0;
	}

	int& res = memo[i][carryLeft];

	if (res != -1) {
		return res;	// computed before
	}
	
	if (weight[i] > carryLeft) {
		return res = dp(i + 1, carryLeft); // can't take, next item
	}
	int skips = dp(i + 1, carryLeft); // skips
	int takes = price[i] + dp(i + 1, carryLeft - weight[i]); // takes

	return res = max(skips, takes);
}


void run_case(int tc) {
	// clear memo
	fill(memo.begin(), memo.end(), vector<int>(35, -1));

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> price[i] >> weight[i];
	}

	int persons, carry;
	cin >> persons;
	int max = 0;
	for (int i = 0; i < persons; i++) {
		cin >> carry;
		max += dp(0, carry);
	}
	cout << max << "\n";
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


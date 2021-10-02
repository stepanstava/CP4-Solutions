// 11450 Wedding Shopping
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<vector<int>> garments(205, vector<int>(25));
int money, customers;

int backtracking(int cost, int i) {
	if (cost > money) {
		return INT_MIN; // pruning
	}

	if (i == customers) {
		return cost;
	}

	int ans = INT_MIN;
	for (int j = 1; j <= garments[i][0]; j++) {
		int garmet = garments[i][j];
		int total = backtracking(cost + garmet, i + 1);
		ans = max(ans, total);
	}
	return ans;
}

void run_case(int tc) {
	cin >> money >> customers;

	int k;
	for (int i = 0; i < customers; i++) {
		cin >> k;
		garments[i][0] = k;
		for (int j = 1; j <= k; j++) {
			cin >> garments[i][j];
		}
	}
	
	int max = backtracking(0, 0);
	if (max < 0) {
		cout << "no solution\n";
	}
	else {
		cout << max << "\n";
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

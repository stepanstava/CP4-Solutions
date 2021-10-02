// 11450 Wedding Shopping
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> garments(25, vector<int>(25));
vector<vector<bool>> reachable(25, vector<bool>(205));
int money, customers;

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

	// clear table
	fill(reachable.begin(), reachable.end(), vector<bool>(205));

	// initial values (base cases)
	for (int j = 1; j <= garments[0][0]; j++) {
		int left = money - garments[0][j];
		if (left >= 0) {
			reachable[0][left] = true;
		}
	}

	int m;
	for (int g = 1; g < customers; g++) {
		for (m = 0; m <= money; m++) {
			if (reachable[g - 1][m]) {
				for (int j = 1; j <= garments[g][0]; j++) {
					int left = m - garments[g][j];
					if (left >= 0) {
						reachable[g][left] = true;
					}
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= money; i++) {
		if (reachable[customers - 1][i]) {
			ans = money - i;
			break;
		}
	}

	if (ans == 0) {
		cout << "no solution\n";
	}
	else {
		cout << ans << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("io.txt", "r", stdin);

	int ttc;
	cin >> ttc;
	for (int tc = 1; tc <= ttc; tc++) {
		run_case(tc);
		cout << flush;
	}
	return 0;
}

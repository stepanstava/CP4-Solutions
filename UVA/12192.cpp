// 12192 Grapevine
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void run_case(int n, int m) {
	vector<vector<int>> nums(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> nums[i][j];
		}
	}

	int q;
	cin >> q;
	
	int l, u;
	for (int i = 0; i < q; i++) {
		cin >> l >> u;

		int maxSize = 0;
		for (int j = 0; j < n; j++) {
			auto lBound = lower_bound(nums[j].begin(), nums[j].end(), l);
			int lBoundIdx = lBound - nums[j].begin();

			for (int x = maxSize; x < n; x++) {
				if (n <= j + x || m <= lBoundIdx + x || u < nums[j + x][lBoundIdx + x]) {
					break;
				}
				maxSize = max(maxSize, x + 1);
			}
			
		}
		cout << maxSize << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) {
			break;
		}
		run_case(n, m);
		cout << "-\n";
		cout << flush;
	}
	return 0;
}

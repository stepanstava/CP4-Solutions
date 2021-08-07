// 11742 Social Constraints
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void run_case(int n, int m) {
	int a, b, c;
	vector<int> aV(m);
	vector<int> bV(m);
	vector<int> cV(m);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		aV[i] = a;
		bV[i] = b;
		cV[i] = c;
	}
	
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		nums[i] = i;
	}
	int perm = 0;
	do {
		bool seatCondition = true;
		for (int i = 0; i < m && seatCondition; i++) {
			int posA = nums[aV[i]];
			int posB = nums[bV[i]];

			int space = abs(posA - posB);

			if (cV[i] > 0) {
				seatCondition = space <= cV[i];
			}
			else {
				seatCondition = space >= abs(cV[i]);
			}
		}
		if (seatCondition) {
			perm++;
		}

	} while (next_permutation(nums.begin(), nums.end()));

	cout << perm << "\n";
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
		cout << flush;
	}
	return 0;
}

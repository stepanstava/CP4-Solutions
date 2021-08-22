// 12032 The Monkey and the Oiled Bamboo
#include <iostream>
#include <vector>

using namespace std;

bool canReach(int k, vector<int>& rungs) {
	for (int i = 1; i < rungs.size(); i++) {
		int jump = rungs[i] - rungs[i - 1];
		if (jump == k) {
			k--;
			continue;
		}

		if (jump > k) {
			return false;
		}
	}
	return true;
}


void run_case(int tc) {
	int n;
	cin >> n;

	vector<int> rungs(n + 1);
	rungs[0] = 0;
	for (int i = 1; i < n + 1; i++) {
		cin >> rungs[i];
	}

	int low = 1, high = rungs[rungs.size() - 1];
	int minK = 0;
	while (low <= high) {
		int middle = (low + high) / 2;
		if (canReach(middle, rungs)) {
			minK = middle;
			high = middle - 1;
		}
		else {
			low = middle + 1;
		}
	}
	cout << "Case " << tc << ": "<< minK << "\n";
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

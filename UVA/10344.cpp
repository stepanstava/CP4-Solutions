// 10344 23 Out of 5
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums(5);

bool backtrack(int i, int sum) {
	if (i == 5) {
		return sum == 23;
	}

	bool plus = backtrack(i + 1, sum + nums[i]);
	bool minus = backtrack(i + 1, sum - nums[i]);
	bool multi = backtrack(i + 1, sum * nums[i]);

	return plus || minus || multi;
}

void run_case() {
	sort(nums.begin(), nums.end());

	bool isPossible = false;
	do {
		if (backtrack(1, nums[0])) {
			isPossible = true;
			break;
		}
	} while (next_permutation(nums.begin(), nums.end()));

	if (isPossible) {
		cout << "Possible\n";
	}
	else {
		cout << "Impossible\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		bool allZeros = true;
		for (int i = 0; i < 5; i++) {
			cin >> nums[i];

			if (nums[i] != 0) {
				allZeros = false;
			}
		}
		if (allZeros) {
			break;
		}

		run_case();
		cout << flush;
	}
	return 0;
}

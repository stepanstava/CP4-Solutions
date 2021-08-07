// 10487 Closest Sums
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <climits>

using namespace std;

void run_case(int n) {
	int num;
	vector<int> setInt;

	while (n--) {
		cin >> num;
		setInt.push_back(num);
	}
	sort(setInt.begin(), setInt.end());

	int m, query;
	cin >> m;
	while (m--) {
		cin >> query;

		int left = 0;
		int right = setInt.size() - 1;
		int minDiff = INT_MAX;
		int closestSum;
		while (left < right) {
			int sum = setInt[left] + setInt[right];
			int diff = query - sum;
			int absDiff = abs(diff);
			if (absDiff < minDiff) {
				minDiff = absDiff;
				closestSum = sum;
			}

			if (diff <= 0) {
				right--;
			}
			else {
				left++;
			}
		}
		cout << "Closest sum to " << query << " is " << closestSum << "." << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("io.txt", "r", stdin);

	int n;
	int count = 1;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		cout << "Case " << count << ":\n";
		run_case(n);
		count++;
		cout << flush;
	}
	return 0;
}

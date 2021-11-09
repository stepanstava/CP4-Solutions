// 10684 The jackpot
#include <iostream>
#include <algorithm>

using namespace std;

void run_case(int n) {
	int maxSum = -1001;
	int sum = 0;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		sum += num;

		if (sum < 0) {
			sum = 0;
		}

		maxSum = max(sum, maxSum);
	}

	if (maxSum > 0) {
		cout << "The maximum winning streak is " << maxSum << ".\n";
	}
	else 
	{
		cout << "Losing streak.\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		run_case(n);
		cout << flush;
	
	}
	return 0;
}

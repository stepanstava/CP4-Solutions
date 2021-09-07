// 11264 Coin Collector
#include <iostream>
#include <vector>

using namespace std;

void run_case(int tc) {
	int n;
	cin >> n;
	
	vector<int> coins(n);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	int withdraw = 0;
	int diffCoins = 1;
	for (int i = 0; i < n - 1; i++) {
		int sum = withdraw + coins[i];
		if (sum < coins[i + 1]) {
			withdraw = sum;
			diffCoins++;
		}
	}

	cout << diffCoins << "\n";
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

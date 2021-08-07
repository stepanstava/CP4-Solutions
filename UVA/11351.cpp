// 11351 Last Man Standing
#include <iostream>
#include <vector>
using namespace std;

int josephus(int n, int k) {
	if (n == 1) {
		return 0;
	}
	else {
		return (josephus(n - 1, k) + k) % n;
	}
}

void run_case(int tc) {
	int n, k;
	cin >> n >> k;

	cout << josephus(n, k) + 1 << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("io.txt", "r", stdin);

	int ttc;
	cin >> ttc;
	for (int tc = 1; tc <= ttc; tc++) {
		cout << "Case " << tc << ": ";
		run_case(tc);
		cout << flush;
	}
	return 0;
}

/*


*/
// 11849 CD
#include <iostream>
#include <unordered_map>

using namespace std;

void run_case(int &n, int &m) {
	int x;
	unordered_map<int, bool> cds;
	for (int i = 0; i < n; i++) {
		cin >> x;
		cds[x] = true;
	}

	int same = 0;
	for (int i = 0; i < m; i++) {
		cin >> x;
		if (cds[x]) {
			same++;
		}
	}

	cout << same << "\n";
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}

		run_case(n, m);

		cout << flush;
	}

	return 0;
}

// 11348 Exhibition
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <iomanip>
#include <set>

using namespace std;

void run_case(int tc) {
	int n, m, x;
	cin >> n;

	unordered_map<int, int> map;
	vector<set<int>> res(n);
	for (int i = 0; i < n; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> x;
			if (res[i].find(x) == res[i].end()) {
				res[i].insert(x);
				map[x] += 1;
			}
		}
	}

	vector<int> playersUnique(n);
	int uniqueTot = 0;
	for (int i = 0; i < n; i++) {
		for (auto stamp : res[i]) {
			if (map[stamp] == 1) {
				playersUnique[i] += 1;
				uniqueTot++;
			}
		}
	}

	cout << "Case " << tc << ":";
	cout << setprecision(6) << fixed;

	for (int i = 0; i < n; i++) {
		cout << " " << playersUnique[i] * 100.0 / uniqueTot << "%";
	}

	cout << "\n";
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ttc;
	cin >> ttc;

	for (int i = 1; i <= ttc; i++) {
		run_case(i);
		cout << flush;
	}
	return 0;
}

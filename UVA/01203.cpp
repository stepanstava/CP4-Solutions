// 1203 Argus
#include <iostream>
#include <string>
#include <utility>
#include <queue>

using namespace std;

void run_case() {
	string r;
	int id, interval;
	priority_queue<pair<pair<int, int>, int>> q;
	while (true) {
		cin >> r;
		if (r == "#") {
			break;
		}
		cin >> id >> interval;

		pair<int, int> p = make_pair(-interval, -id);
		q.push(make_pair(p, -interval));
	}

	int k;
	cin >> k;

	for (int i = 0; i < k; i++) {
		auto t = q.top();
		q.pop();
		cout << -t.first.second << '\n';
		t.first.first += t.second;
		q.push(t);
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("io.txt", "r", stdin);

	run_case();

	return 0;
}

// 12390 Distributing Ballot Boxes
#include <iostream>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

typedef tuple<double, int, int> tdii;

void run_case(int n, int b) {
	priority_queue<tdii> que;

	int s;
	for (int i = 0; i < n; i++) {
		cin >> s;

		tdii c = { (double)s, 1, s };
		que.push(c);
	}

	int extraB = b - n;
	for (int i = 0; i < extraB; i++) {
		auto top = que.top();
		que.pop();

		double size = (double)get<2>(top);
		int boxes = get<1>(top) + 1;
		get<0>(top) = size / boxes;
		get<1>(top) = boxes;

		que.push(top);
	}

	cout << (int)ceil(get<0>(que.top())) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, b;
	while (cin >> n >> b) {
		if (n == -1 && b == -1) {
			break;
		}

		run_case(n, b);
		cout << flush;
	}
	return 0;
}

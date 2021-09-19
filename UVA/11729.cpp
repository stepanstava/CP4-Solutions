// 11729 - Commando War
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct soldier {
	int b, j;
};

bool comp(soldier x, soldier y) {
	return x.j > y.j;
}

void run_case(int n, int tc) {
	vector<soldier> soldiers(n);
	for (int i = 0; i < n; i++) {
		soldier s;
		cin >> s.b;
		cin >> s.j;
		soldiers[i] = s;
	}

	sort(soldiers.begin(), soldiers.end(), comp);

	int minTime = 0;
	int prevBrief = 0;
	for (int i = 0; i < n; i++) {
		minTime = max(minTime, prevBrief + soldiers[i].b + soldiers[i].j);
		prevBrief += soldiers[i].b;
	}

	cout << "Case " << tc << ": " << minTime << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int tc = 1;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		run_case(n, tc);
		tc++;
		cout << flush;
	}

	return 0;
}

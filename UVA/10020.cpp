// 10020 Minimal coverage
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct interval {
	int l, r;
};

bool comp(interval x, interval y) {
	if (x.l == y.l) {
		return x.r > y.r;
	}
	else {
		return x.l < y.l;
	}
}

void run_case(int tc) {
	int m, l, r;
	cin >> m;

	vector<interval> intervals;
	while (cin >> l >> r) {
		if (l == 0 && r == 0) {
			break;
		}

		interval i;
		i.l = l;
		i.r = r;
		intervals.push_back(i);
	}

	sort(intervals.begin(), intervals.end(), comp);

	vector<interval> minIntervals;
	int covered = 0;
	bool isPossible = true;
	for (int i = 0; i < intervals.size() && isPossible; i++) {
		if (covered >= m) {
			break;
		}

		if (covered >= intervals[i].r) {
			continue;
		}

		if (covered >= intervals[i].l) {
			int rNext = 0;
			int iNext = 0;
			for (int j = i; j < intervals.size(); j++) {
				if (covered < intervals[j].l) {
					break;
				}

				if (rNext < intervals[j].r) {
					rNext = intervals[j].r;
					iNext = j;
				}
			};
			covered = rNext;
			i = iNext;
			minIntervals.push_back(intervals[i]);
		}
		else {
			isPossible = false;
		}
	}

	if (!isPossible || covered < m) {
		cout << 0 << "\n";
	}
	else {
		cout << minIntervals.size() << "\n";
		for (interval i : minIntervals) {
			cout << i.l << " " << i.r << "\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ttc;
	cin >> ttc;
	for (int tc = 1; tc <= ttc; tc++) {
		run_case(tc);

		if (tc != ttc) {
			cout << "\n";
		}

		cout << flush;
	}
	return 0;
}

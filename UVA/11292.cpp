// 11292 The Dragon of Loowater
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void run_case(int h, int k) {
	vector<int> heads(h);
	vector<int> knights(k);

	for (int i = 0; i < h; i++) {
		cin >> heads[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> knights[i];
	}


	sort(heads.begin(), heads.end());
	sort(knights.begin(), knights.end());

	int hIdx = 0, kIdx = 0, cost = 0;
	while (hIdx < h && kIdx < k) {
		if (heads[hIdx] <= knights[kIdx]) {
			cost += knights[kIdx];
			hIdx++;
			kIdx++;
		} 
		else {
			kIdx++;
		}
	}

	if (hIdx == h) {
		cout << cost;
	}
	else {
		cout << "Loowater is doomed!";
	}

	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("io.txt", "r", stdin);

	int h, k;
	while (cin >> h >> k) {
		if (h == 0 && k == 0) {
			break;
		}
		run_case(h, k);
		cout << flush;
	}

	return 0;
}

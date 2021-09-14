// 10382 Watering Grass
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

struct sprinkle {
	int x, radius;
	double l, r;
};

const double EPS = 1e-9;

bool comp(sprinkle a, sprinkle b) {
	if (a.l == b.l) {
		return a.r > b.r;
	}
	return a.l < b.l;
}

void run_case(int n, int l, int w) {
	vector<sprinkle> sprinkles;
	
	int x, r;
	for (int i = 0; i < n; i++) {
		cin >> x >> r;
		sprinkle s;
		s.radius = r;
		s.x = x;

		if (r * 2 >= w) {
			// converts circles and horizonal strips into intervals
			double d_x = sqrt((double)r * r - (w / 2.0) * (w / 2.0));
			s.l = x - d_x;
			s.r = x + d_x;
			sprinkles.push_back(s);
		}	
	}

	sort(sprinkles.begin(), sprinkles.end(), comp);

	double covered = 0.0;
	int sprinklersCount = 0;
	bool isPossible = true;
	for (int i = 0; i < sprinkles.size() && isPossible; i++) {
		if (covered > l) {
			break;
		}

		if (sprinkles[i].r <= covered + EPS) {
			continue;
		}

		if (sprinkles[i].l <= covered + EPS) {
			double rNext = 0.0;
			int iNext = 0;
			for (int j = i; j < sprinkles.size(); j++) {
				if (sprinkles[j].l > covered + EPS) {
					break;
				}

				if (sprinkles[j].r > rNext) {
					rNext = sprinkles[j].r;
					iNext = j;
				}
			}
			sprinklersCount++;
			covered = rNext;
			i = iNext;
		}
		else {
			isPossible = false;
		}
	}

	if (!isPossible || covered < l) {
		cout << -1 << "\n";
	}
	else {
		cout << sprinklersCount << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l, w;
	while (cin >> n >> l >> w) {
		if (cin.eof()) {
			break;
		}
		run_case(n, l, w);
		cout << flush;
	}

	return 0;
}


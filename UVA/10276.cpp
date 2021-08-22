// 10276 Hanoi Tower Troubles Again!

// Iterative
#include <iostream>
#include <cmath>

using namespace std;

void run_case(int n) {
	int pegs[55] = { 0 };

	int tmp, sr;
	int balls = 1;
	bool maxFound = false;
	while (!maxFound) {
		for (int i = 0; i < n; i++) {
			if (pegs[i] == 0) {
				pegs[i] = balls;
				balls++;
				break;
			}

			tmp = pegs[i] + balls;
			sr = (int)sqrt(tmp);
			if (sr * sr == tmp) {
				pegs[i] = balls;
				balls++;
				break;
			}

			if (i == n - 1) {
				balls--;
				maxFound = true;
			}
		}
	}

	cout << balls << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ttc, n;
	cin >> ttc;
	for (int tc = 1; tc <= ttc; tc++) {
		cin >> n;
		run_case(n);
		cout << flush;
	}
	return 0;
}


// Recursive
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int n;
int maxBalls = 0;

bool canBePlaced(int prev, int balls) {
	int tmp = prev + balls;
	double sr = (int)sqrt(tmp);
	return sr * sr == tmp;
}

void traverse(int balls, vector<int> pegs) {
	for (int i = 0; i < n; i++) {
		if (pegs[i] == 0) {
			pegs[i] = balls;
			balls++;
			return traverse(balls, pegs);
		}

		if (canBePlaced(pegs[i], balls)) {
			pegs[i] = balls;
			balls++;
			return traverse(balls, pegs);
		}

	}
	maxBalls = max(maxBalls, balls);
}

void run_case() {
	maxBalls = 0;
	vector<int> pegs(55, 0);
	int balls = 1;

	traverse(balls, pegs);
	maxBalls--;
	cout << maxBalls << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ttc;
	cin >> ttc;
	for (int tc = 1; tc <= ttc; tc++) {
		cin >> n;
		run_case();
		cout << flush;
	}
	return 0;
}

// 735 Dart-a-Mania
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

set<int> points;

void run_case(int n) {
	int perm = 0, comb = 0;
	int score;
	bool taken[65][65][65] = { false };

	for (auto& a : points) {
		for (auto& b : points) {
			for (auto& c : points) {
				score = a + b + c;

				if (n == score) {
					perm++;

					vector<int> scoreArr = { a, b, c };
					sort(scoreArr.begin(), scoreArr.end());

					if (!taken[scoreArr[0]][scoreArr[1]][scoreArr[2]]) {
						taken[scoreArr[0]][scoreArr[1]][scoreArr[2]] = true;
						comb++;
					}
				}
			}
		}
	}

	if (comb > 0) {
		cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << comb << ".\n";
		cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << perm << ".\n";
	}
	else {
		cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS.\n";
	}
	cout << "**********************************************************************\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("io.txt", "r", stdin);

	points.insert(0);
	points.insert(50);
	int val;
	for (int i = 1; i <= 20; i++) {
		points.insert(i);
		points.insert(i * 2);
		points.insert(i * 3);
	}

	int n;
	while (cin >> n) {
		if (n <= 0) {
			break;
		}
		run_case(n);
		cout << flush;
	}

	cout << "END OF OUTPUT\n";
	return 0;
}


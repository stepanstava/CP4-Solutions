//// 441 Lotto
#include <iostream>
#include <vector>

using namespace std;

void run_case(int k) {
	vector<int> s(k);
	// input
	int num;
	for (int i = 0; i < k; i++) {
		cin >> num;
		s[i] = num;
	}

	for (int a = 0; a < k - 5; a++) {
		for (int b = a + 1; b < k - 4; b++) {
			for (int c = b + 1; c < k - 3; c++) {
				for (int d = c + 1; d < k - 2; d++) {
					for (int e = d + 1; e < k - 1; e++) {
						for (int f = e + 1; f < k; f++) {
							cout << s[a] << " " << s[b] << " " << s[c] << " " << s[d] << " " << s[e] << " " << s[f] << "\n";
						}
					}
				}
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	bool isFirst = true;
	while (cin >> k) {
		if (k == 0) {
			break;
		}

		if (!isFirst) {
			cout << "\n";
		}
		isFirst = false;

		run_case(k);
		cout << flush;
	}

	return 0;
}

// 11203 Can you decide it for ME?
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void run_case(int tc) {
	string line;
	cin >> line;

	int x = 0, y = 0, z = 0;
	int m = 0, e = 0;
	bool isTheorem = true;
	for (char ch : line) {
		char c = tolower(ch);
		if (!(c == '?' || c == 'e' || c == 'm')) {
			isTheorem = false;
			break;
		}

		if (c == 'e') {
			e++;
			if (e > 1) {
				isTheorem = false;
				break;
			}
			continue;
		}

		if (c == 'm') {
			m++;
			if (m > 1) {
				isTheorem = false;
				break;
			}
			continue;
		}

		if (m == 0 && e == 0) {
			x++;
		}
		else if (m > 0 && e == 0) {
			y++;
		}
		else {
			z++;
		}
	}

	if (isTheorem && x >= 1 && y >= 1 && z >= 2 && y == (z - x)) {
		cout << "theorem" << "\n";
	}
	else {
		cout << "no-theorem" << "\n";
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i++) {
		run_case(i);
		cout << flush;
	}
	return 0;
}

// 725 Division
#include <iostream>
#include <string>

using namespace std;

bool hasUniqueDigit(string n) {
	for (int i = 0; i < 10; i++) {
		auto found = n.find(n[i], i + 1);
		if (found != string::npos) {
			return false;
		}
	}
	return true;
}

void run_case(int n) {
	bool hasSolution = false;
	for (int i = 1234; i <= 98765 / n; i++) {
		if (i % n != 0) {
			continue;
		}
		string divider = to_string(i / n);
		if (divider.size() < 4) {
			continue;
		}
		string num = to_string(i);
		if (divider.size() == 4) {
			divider = "0" + divider;
		}
		if (num.size() == 4) {
			num = "0" + num;
		}

		if (!hasUniqueDigit(num + divider)) {
			continue;
		}

		cout << num << " / " << divider << " = " << n << "\n";
		hasSolution = true;
	}
	if (!hasSolution) {
		cout << "There are no solutions for " << n << "." << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	bool isFirst = true;
	while (cin >> tc) {
		if (tc == 0) {
			break;
		}

		if (!isFirst) {
			cout << "\n";
		}
		else {
			isFirst = false;
		}

		run_case(tc);
		cout << flush;
	}
	return 0;
}

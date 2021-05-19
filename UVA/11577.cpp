// 11577 Letter Frequency
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void run_case(int tc) {
	string line;
	getline(cin, line);

	int ascii[150] = { 0 };
	int max = 0;
	for (char c : line) {
		if (!isalpha(c)) {
			continue;
		}

		char idx = tolower(c);
		ascii[idx] += 1;

		if (ascii[idx] > max) {
			max++;
		}
	}

	for (int i = 'a'; i <= 'z'; i++) {
		if (ascii[i] == max) {
			cout << (char)i;
		}
	}
	cout << "\n";
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	cin.get();

	for (int i = 1; i <= tc; i++) {
		run_case(i);
		cout << flush;
	}
	return 0;
}

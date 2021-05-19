// What's The Frequency, Kenneth?
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void run_case() {
	string line;
	while (getline(cin, line)) {
		int ascii[125] = { 0 };
		int max = 0;

		for (char c : line) {
			if (!isalpha(c)) {
				continue;
			}

			ascii[c] += 1;
			if (ascii[c] > max) {
				max = ascii[c];
			}
		}

		for (int i = 'A'; i <= 'Z'; i++) {
			if (ascii[i] == max) {
				cout << (char)i;
			}
		}

		for (int i = 'a'; i <= 'z'; i++) {
			if (ascii[i] == max) {
				cout << (char)i;
			}
		}

		cout << " " << max << "\n";
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	run_case();
	
	return 0;
}

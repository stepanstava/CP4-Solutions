// 10260 Soundex
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<char, int> MAP = {
	{ 'B', 1 },
	{ 'F', 1 },
	{ 'P', 1 },
	{ 'V', 1 },
	{ 'C', 2 },
	{ 'G', 2 },
	{ 'J', 2 },
	{ 'K', 2 },
	{ 'Q', 2 },
	{ 'S', 2 },
	{ 'X', 2 },
	{ 'Z', 2 },
	{ 'D', 3 },
	{ 'T', 3 },
	{ 'L', 4 },
	{ 'M', 5 },
	{ 'N', 5 },
	{ 'R', 6 }
};

void run_case(string &line) {
	int preVal = 0;
	for (char c : line) {
		if (!MAP[c]) {
			preVal = 0;
			continue;
		}

		int val = MAP[c];
		if (val == preVal) {
			continue;
		}
		else {
			preVal = 0;
		}

		preVal = val;
		cout << val;
	}
	cout << '\n';
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string line;

	while (getline(cin, line)) {
		run_case(line);
		cout << flush;
	}
	return 0;
}

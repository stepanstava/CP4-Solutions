// 1368 DNA Consensus String
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

const int UPPER_DIFF = 65;

void run_case(int tc) {
	int cases, length;
	cin >> cases >> length;

	string line;
	vector<string> lines(cases);
	for (int i = 0; i < cases; i++) {
		cin >> line;
		lines[i] = line;
	}

	int totalDiff = 0;
	for (int i = 0; i < length; i++) {
		int diff = 0;
		int map[30] = { 0 };
		for (int j = 0; j < cases; j++) {
			int idx = lines[j][i] - UPPER_DIFF;
			map[idx] += 1;
			
			if (map[idx] > diff) {
				diff ++;
			}
		}

		for (int x = 0; x < 30; x++) {
			if (map[x] == diff) {
				cout << (char)(x + UPPER_DIFF);
				goto jump;
			}
		}

	jump:
		totalDiff += cases - diff;
	}
	cout << "\n";
	cout << totalDiff << "\n";
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

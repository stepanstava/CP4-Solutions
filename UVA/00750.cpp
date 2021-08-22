// 750 8 Queens Chess Problem
#include <iostream>

using namespace std;

int rows[8], x, y, solutions;

bool canPlace(int row, int col) {
	for (int i = 0; i < col; i++) {
		if (rows[i] == row) {
			return false;
		}
		if (abs(rows[i] - row) == abs(i - col)) {
			return false;
		}
	}
	return true;
}

void backtrack(int col) {
	if (col == 8 && rows[y] == x) {
		cout << (solutions < 10 ? " " : "") << solutions++ << "      ";
		for (int i = 0; i < 8; i++) {
			cout << rows[i] + 1;
			if (i != 7) {
				cout << " ";
			}
			else {
				cout << "\n";
			}
		}
	}

	for (int row = 0; row < 8; row++) {
		if (row != x && col == y) {
			continue;
		}

		if (canPlace(row, col)) {
			rows[col] = row;
			backtrack(col + 1);
		}
	}
}

void run_case(int tc) {
	cin >> x >> y;
	x--;
	y--;

	backtrack(0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ttc;
	cin >> ttc;
	for (int tc = 1; tc <= ttc; tc++) {
		// clears variables;
		solutions = 1;
		rows[8] = { 0 };

		cout << "SOLN       COLUMN\n";
		cout << " #      1 2 3 4 5 6 7 8\n\n";

		run_case(tc);
		if (tc != ttc) {
			cout << "\n";
		}

		cout << flush;
	}
	return 0;
}

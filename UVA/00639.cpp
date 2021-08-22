// 639 Don’t Get Rooked
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int n;
int maxRooks = 0;
vector<string> board(4);

bool canBePlaced(int row, int col, vector<string>& board) {
	int cell;
	// up
	for (int i = row - 1; i >= 0; i--) {
		cell = board[i][col];
		if (cell == 'X') {
			break;
		}
		if (cell == 'R') {
			return false;
		}
	}
	// down
	for (int i = row + 1; i < n; i++) {
		cell = board[i][col];
		if (cell == 'X') {
			break;
		}
		if (cell == 'R') {
			return false;
		}
	}
	// left
	for (int i = col + 1; i < n; i++) {
		cell = board[row][i];
		if (cell == 'X') {
			break;
		}
		if (cell == 'R') {
			return false;
		}
	}
	// right
	for (int i = col - 1; i >= 0; i--) {
		cell = board[row][i];
		if (cell == 'X') {
			break;
		}
		if (cell == 'R') {
			return false;
		}
	}
	return true;
}

void traverse(int rooks) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == '.' && canBePlaced(i, j, board)) {
				board[i][j] = 'R';
				traverse(rooks + 1);
				board[i][j] = '.';
			}
		}
	}
	maxRooks = max(maxRooks, rooks);
}

void run_case(int n) {
	maxRooks = 0;
	
	for (int i = 0; i < n; i++) {
		string line;
		getline(cin, line);
		board[i] = line;
	}
	traverse(0);

	cout << maxRooks << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (cin >> n) {
		cin.ignore();
		if (n == 0) {
			break;
		}
		run_case(n);
		cout << flush;
	}

	return 0;
}

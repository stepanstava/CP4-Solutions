// 10813 Traditional BINGO
#include <cstdio>
#include <vector>
using namespace std;

bool isWinning(vector<vector<bool>> card);
void markMatch(vector<vector<int>>& numCard, vector<vector<bool>>& matchCard, int col, int& num);

int main() {
	int cards;
	scanf("%d", &cards);
	while (cards--) {

		// bingo card
		vector<vector<int>> numCard(5, vector<int>(5));
		int cardNum;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (i == 2 && j == 2) {
					continue;
				}
				scanf("%d", &cardNum);
				numCard[i][j] = cardNum;
			}
		}

		int matchNum;
		bool hasWinning = false;
		vector<vector<bool>> matchCard(5, vector<bool>(5, false));
		for (int i = 0; i < 75; i++) {
			scanf("%d", &matchNum);

			if (hasWinning) {
				continue;
			}

			if (matchNum < 16) {
				markMatch(numCard, matchCard, 0, matchNum);
			}
			else if (matchNum < 31) {
				markMatch(numCard, matchCard, 1, matchNum);
			}
			else if (matchNum < 46) {
				markMatch(numCard, matchCard, 2, matchNum);
			}
			else if (matchNum < 61) {
				markMatch(numCard, matchCard, 3, matchNum);
			} 
			else {
				markMatch(numCard, matchCard, 4, matchNum);
			}

			if (i > 4) {
				hasWinning = isWinning(matchCard);

				if (hasWinning) {
					printf("BINGO after %d numbers announced\n", i + 1);
				}
			}
		}
	}
	return 0;
}

void markMatch(vector<vector<int>> &numCard, vector<vector<bool>>& matchCard, int col, int& num) {
	bool hasMatch = false;
	for (int i = 0; i < 5; i++) {
		if (numCard[i][col] == num) {
			matchCard[i][col] = true;
		}
	}

	if (!hasMatch && col == 2) {
		matchCard[2][2] = true;
	}
}

bool isWinning(vector<vector<bool>> card) {
	bool isWinning = false;

	// checks rows
	for (int i = 0; i < 5; i++) {
		if (card[i][0] && card[i][1] && card[i][2] && card[i][3] && card[i][4]) {
			return true;
		}
	}

	// checks collumns
	for (int i = 0; i < 5; i++) {
		if (card[0][i] && card[1][i] && card[2][i] && card[3][i] && card[4][i]) {
			return true;
		}
	}

	// checks diagonals
	if (card[0][0] && card[1][1] && card[2][2] && card[3][3] && card[4][4]) {
		return true;
	}
	if (card[0][4] && card[1][3] && card[2][2] && card[3][1] && card[4][0]) {
		return true;
	}

	return false;
}
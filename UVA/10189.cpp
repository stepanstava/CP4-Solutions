#include <cstdio>
#include <vector>
using namespace std;


struct {
	int dx;
	int dy;
} dir[] = { {-1,-1,},{-1,0,},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };

void updateBoard(vector<vector<int>>& board, int& x, int& y);
void printBoard(vector<vector<int>>& board, int& n, int& m);

int main()
{
	int n, m, count = 1;
	while (scanf("%d %d\n", &n, &m), n || m)
	{
		vector<vector<int>> board(n, vector<int>(m)); // init to 0
		char c;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%c", &c);

				if (c == '*') {
					board[i][j] = -1;
					updateBoard(board, i, j);
				}
			}
			scanf("\n");
		}

		// print board
		if (count > 1) {
			printf("\n");
		}
		printf("Field #%d:\n", count++);
		printBoard(board, n, m);
		
	}
}

void updateBoard(vector<vector<int>>& board, int &x, int &y) {
	int xSize = board.size();
	int ySize = board[0].size();

	for (int i = 0; i < 8; i++) {
		int posx = dir[i].dx + x;
		int posy = dir[i].dy + y;

		if (posx < 0 || posy < 0) {
			continue;
		}

		if (posx < xSize && posy < ySize)  {
			if (board[posx][posy] == -1) {
				continue;
			}
			board[posx][posy] += 1;
		}
	}
}

void printBoard(vector<vector<int>>& board, int &n, int &m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == -1) {
				printf("*");
			}
			else {
				printf("%d", board[i][j]);
			}
		}
		printf("\n");
	}
}
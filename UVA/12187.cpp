// 12187 Brothers
#include <cstdio>
#include <vector>

using namespace std;

struct {
	int dx;
	int dy;
} dir[] = { {0,1},{1,0,},{0,-1},{-1,0} };

int main() {
	freopen("io.txt", "r", stdin);
	int heirs, x, y, battles;
	while (scanf("%d %d %d %d", &heirs, &x, &y, &battles), heirs || x || y || battles) {
		// reads field
		vector<vector<int>> field(x, vector<int>(y));
		
		int n;
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				scanf("%d", &n);
				field[i][j] = n;
			}
		}

		// battles
		for (int b = 0; b < battles; b++) {
			vector<vector<int>> afterBattle(x, vector<int>(y, -1));
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					// check neigbours
					for (int z = 0; z < 4; z++) {
						int posX = dir[z].dx + i;
						int posY = dir[z].dy + j;

						if (posX < 0 || posY < 0) {
							continue;
						}

						if (posX < x && posY < y) {
							int attacker = field[i][j];
							int enemy = attacker != heirs - 1 ? attacker + 1 : 0;
							if (field[posX][posY] == enemy) {
								afterBattle[posX][posY] = attacker;
							}
						}
					}
				}
			}
			// copy afterBattle to field
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					if (afterBattle[i][j] != -1) {
						field[i][j] = afterBattle[i][j];
					}
				}
			}
		}

		// print field
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				printf("%d", field[i][j]);
				if (j != y - 1) {
					printf(" ");
				}
			}
			printf("\n");
		}
	}
	return 0;
}
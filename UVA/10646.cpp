// 10646 What is the Card?
#include <cstdio>
using namespace std;

int main()
{
	int tc, count = 1;
	scanf("%d\n", &tc);
	while (tc--) {
		// read cards
		char pile1[26][2];
		char pile2[26][2];
		char card[4];
		for (int i = 0; i < 52; i++) {
			scanf("%s", card);
			if (i < 26) {
				pile1[i][0] = card[0];
				pile1[i][1] = card[1];
			}
			else {
				pile2[i - 26][0] = card[0];
				pile2[i - 26][1] = card[1];
			}
		}

		// 3x steps
		int y = 0, away = 0;
		for (int i = 0; i < 3; i++) {
			int x = pile2[25 - away][0] < 64 ? pile2[25 - away][0] - 48 : 10;
			y += x;
			away += 1 + 10 - x;
		}

		// final card
		int pos = y >= 26 - away ? y + away : y;
		printf("Case %d: ", count++);
		if (pos > 26) {
			printf("%c%c\n", pile2[pos - 26 - 1][0], pile2[pos - 26 - 1][1]);
		}
		else {
			printf("%c%c\n", pile1[pos][0], pile1[pos][1]);
		}
	}
	return 0;
}
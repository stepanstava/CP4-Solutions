// 11459 Snakes and Ladders
#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
	int tc, players, obs, rolls;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d %d", &players, &obs, &rolls);

		vector<int> playersPos(players, 1);
		unordered_map<int, int> map;

		// snakes and ladders
		int x, y;
		for (int i = 0; i < obs; i++) {
			scanf("%d %d", &x, &y);
			map[x] = y;
		}

		// rolls
		int r;
		bool isWinner = false;
		for (int i = 0; i < rolls; i++) {
			scanf("%d", &r);
			int player = i % players;

			if (isWinner) {
				continue; // has to continue reading roll rows
			}
			
			int pos = playersPos[player] + r;
			if (map[pos]) {
				pos = map[pos];
			}
			playersPos[player] = pos;

			if (pos == 100) {
				isWinner = true;
			}
		}

		// results
		for (int i = 0; i < players; i++) {
			printf("Position of player %d is %d.\n", i + 1, playersPos[i]);
		}
	}

	return 0;
}

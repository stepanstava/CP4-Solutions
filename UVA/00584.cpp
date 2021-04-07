// 584 Bowling
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	while (true)
	{
		// reads input row
		char s[50] = { 0 };
		scanf("%[^\n]\n", s);
		if (s[0] == 'G') {
			break;
		}

		// tranforms input row to ints
		vector<int> scores;
		for (char c : s) {
			if (c == '\0') {
				break;
			}
			if (c == ' ') {
				continue;
			}
			if (c == 'X') {
				scores.push_back(10);
			}
			else if (c == '/') {
				scores.push_back(10 - scores[scores.size() - 1]);
			}
			else {
				scores.push_back(c - '0');
			}
		}

		// calculates score
		int score = 0, frames = 0;
		for (int i = 0, size = scores.size(); i < size; i++) {
			if (frames == 10) {
				break;
			}

			if (scores[i] == 10) {
				// strike = 10 + next two rolls
				score += 10 + scores[i + 1] + scores[i + 2];
				frames++;
			}
			else if (scores[i] + scores[i + 1] == 10) {
				// spare = 10 + next roll
				score += 10 + scores[i + 2];
				i++;
				frames++;
			}
			else {
				score += scores[i] + scores[i + 1];
				i++;
				frames++;
			}
		}
		printf("%d\n", score);
	}
}
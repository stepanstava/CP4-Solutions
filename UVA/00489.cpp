// 489 Hangman Judge
#include <cstdio>
using namespace std;

int main()
{
	int round;
	while (scanf("%d\n", &round), round != -1) {
		bool solution[26], guessed[26];
		char c;
		int chars = 0, correct = 0, mistakes = 0;
		// counts unique chars in the solution
		while (scanf("%c", &c), c != '\n') {
			if (!solution[c - 97]) {
				solution[c - 97] = true;
				chars++;
			}
		}

		// counts unique guesses
		bool isWinner = false;
		while (scanf("%c", &c), c != '\n') {
			if (guessed[c - 97]) {
				continue;
			}
			else {
				guessed[c - 97] = true;
			}

			if (solution[c - 97]) {
				correct++;
			}
			else {
				mistakes++;
			}

			if (!isWinner && correct == chars && mistakes < 7) {
				isWinner = true;
			}
		}

		printf("Round %d\n", round);
		if (isWinner) {
			printf("You win.\n");
		}
		else if (mistakes < 7) {
			printf("You chickened out.\n");
		}
		 else {
			printf("You lose.\n");
		}
	}
	return 0;
}

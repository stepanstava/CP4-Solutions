//// 10424 Love Calculator
#include <cstdio>
using namespace std;

int getCharScore(char& c);
int getDigitSum(int num);

int main() {
	while (true) {
		char n1[30] = { 0 };
		char n2[30] = { 0 };
		if (scanf("%[^\n]\n%[^\n]\n", &n1, &n2) == EOF) {
			break;
		}

		int n1Score = 0;
		int n2Score = 0;
		for (int i = 0; i < 25; i++) {
			n1Score += getCharScore(n1[i]);
			n2Score += getCharScore(n2[i]);
		}

		int sum1 = getDigitSum(n1Score);
		int sum2 = getDigitSum(n2Score);

		double sum = sum1 > sum2 ? sum2 / (double)sum1 : sum1 / (double)sum2;
		printf("%.2f %%\n", sum * 100);
	}
	return 0;
}

int getCharScore(char& c) {
	if (c >= 97 && c <= 122) {
		return c - 96;
	}
	if (c >= 65 && c <= 90) {
		return c - 64;
	}
	return 0;
}

int getDigitSum(int num) {
	int sum = 0;
	while (num > 0) {
		sum += num % 10;
		num /= 10;
	}
	return sum <= 9 ? sum : getDigitSum(sum);
}

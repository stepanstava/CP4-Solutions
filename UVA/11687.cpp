// 11687 - Digits
#include <cstdio>
using namespace std;

int numberOfDigits(int n);

int main()
{
	int n;
	bool shouldContinue = true;
	while (shouldContinue) { //!zapsat

		int digits = 0;
		char c, prevC;
		while (scanf("%c", &c), c != '\n') {
			if (c == 'E') {
				shouldContinue = false;
				break;
			}
			digits++;
			prevC = c;
		}
		if (!shouldContinue) {
			break;
		}

		scanf("\n");

		if (digits == 1 && prevC == '1') {
			printf("1\n");
			continue;
		}

		int ans = 2;
		while (digits != 1) {
			digits = numberOfDigits(digits);
			ans++;
		}
		printf("%d\n", ans);
	}


	return 0;

}

int numberOfDigits(int n)
{
	int digits = 1;
	while (n >= 10) {
		n /= 10;
		digits++;
	}
	return digits;
}

//11078 Open Credit System
//int main()
//{
//
//	int TC;
//
//	scanf("%d", &TC);
//	while (TC--) {
//		int n;
//		scanf("%d", &n); //students
//
//
//		for (int i = 0; i < n; i++) {
//			int s;
//			scanf("%d", &s);
//		}
//	}
//
//	return 0;
//}
// 344 Roman Digititis
#include <cstdio>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n), n) {
		int i = 0, v = 0, x = 0, l = 0, c = 0;

		for (int j = 1; j <= n; j++) {
			int num = j;

			while (num != 0) {
				if (num == 100) {
					c++;
					num -= 100;
				}
				else if (num >= 90) {
					c++;
					x++;
					num -= 90;
				}
				else if (num >= 50) {
					l++;
					num -= 50;
				}
				else if (num >= 40) {
					x++;
					l++;
					num -= 40;
				}
				else if (num >= 10) {
					x++;
					num -= 10;
				}
				else if (num >= 9) {
					x++;
					i++;
					num -= 9;
				}
				else if (num >= 5) {
					v++;
					num -= 5;
				} 
				else if (num >= 4) {
					v++;
					i++;
					num -= 4;
				}
				else {
					i++;
					num -= 1;
				}
			}
		}
		printf("%d: %d i, %d v, %d x, %d l, %d c\n", n, i, v, x, l, c);
	}
	return 0;
}


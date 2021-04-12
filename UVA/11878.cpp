// 11878 Homework Checker
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	freopen("io.txt", "r", stdin);

	char input[15];
	int correct = 0, n1;
	while (scanf("%d", &n1) != EOF) {
		int n2;
		char sign, r[5];
		scanf("%c%d%*c%s", &sign, &n2, r);

		if (r[0] == '?') {
			continue;
		}

		int res = atoi(r);
		if (sign == '+') {
			if (n1 + n2 == res) {
				correct++;
			}
		}
		else {
			if (n1 - n2 == res) {
				correct++;
			}
		}
	}
	printf("%d\n", correct);
	return 0;
}


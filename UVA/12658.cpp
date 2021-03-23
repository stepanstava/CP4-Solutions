// 12658 Character Recognition
#include <cstdio>
using namespace std;

int main()
{
	int tc;
	char chars[50];
	scanf("%d", &tc);

	for (int i = 0; i < tc; i++) {
		scanf("%s", chars);
		if (i == 2) {
			char chars[50];
			scanf("%s", &chars);
			for (int j = 0; j < 50; j++) {
				if (chars[j] == '.' && chars[j + 1] == '*' && chars[j + 2] == '.') {
					printf("1");
				}
				if (chars[j] == '*' && chars[j + 1] == '.' && chars[j + 2] == '.') {
					printf("2");
				}
				if (chars[j] == '.' && chars[j + 1] == '.' && chars[j + 2] == '*') {
					printf("3");
				}
				j += 3;
			}
		}
	}
	printf("\n");
	return 0;
}
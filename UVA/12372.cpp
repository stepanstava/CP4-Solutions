// 12372 Packing for Holiday
#include <iostream>
using namespace std;

int main()
{
	int TC, l, w, h, i = 1;
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d %d %d", &l, &w, &h);

		printf("Case %d: ", i++);
		if (l <= 20 && w <= 20 && h <= 20) {
			printf("good\n");
		}
		else {
			printf("bad\n");
		}
	}
	return 0;
}
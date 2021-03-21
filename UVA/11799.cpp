// 11799 - Horror Dash
#include <cstdio>
using namespace std;

int main()
{
	int TC, n, max = 0, count = 1;
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d", &n);
		int c;
		for (int i = 0; i < n; i++) {
			scanf("%d", &c);
			if (c > max) max = c;
		}
		printf("Case %d: %d\n", count++, max);
		max = 0;
	}
	return 0;
}
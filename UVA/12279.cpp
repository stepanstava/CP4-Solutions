// 12279 Emoogle Balance
#include <cstdio>
using namespace std;

int main()
{
	int TC, count = 1;
	while (scanf("%d", &TC), TC) {
		int n, res = 0;
		for (int i = TC; i >= 1; i--) {
			scanf("%d", &n);
			if (n == 0) res--;
			else res++;
		}
		printf("Case %d: %d\n", count++, res);
	}
	return 0;
}
// 696 How Many Knights
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int m, n;
	while (scanf("%d %d", &m, &n), m || n)
	{
		int ans;
		int x = min(n, m);
		int y = max(n, m);

		if (x == 1) {
			ans = y;
		}
		else if (x == 2) {
			ans = 4 * (y / 4) + 2 * min(2, y % 4);
		}
		else {
			ans = ceil(x * y / 2.0);
		}
		printf("%d knights may be placed on a %d row %d column board.\n", ans, m, n);
	}
	return 0;
}
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int tc, m, n;
	char piece;
	scanf("%d\n", &tc);
	while (tc--) {
		scanf("%c %d %d\n", &piece, &m, &n);

		int res = 0;
		if (piece == 'r') {
			// diagonals
			res = min(m, n);
		}
		else if (piece == 'k') {
			// one squere color
			res = ceil(m * n / 2.0);
		}
		else if (piece == 'Q') {
			// one queen take one column and one row
			res = min(m, n);;
		}
		else {
			// kings
			// m/2 on row, one column space, ...
			res = ceil(m / 2.0) * ceil(n / 2.0);
		}
		printf("%d\n", res);
	}
	return 0;
}
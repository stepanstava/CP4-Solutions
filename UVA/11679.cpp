//// 11679 Sub-prime
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int b, n;
	while (scanf("%d %d", &b, &n), b != 0 && n != 0)
	{
		vector<int> banks(b);
		int r;
		for (int i = 0; i < b; i++)
		{
			scanf("%d", &r);
			banks[i] = r;
		}

		int d, c, v;
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d %d", &d, &c, &v);
			banks[d - 1] -= v;
			banks[c - 1] += v;
		}

		bool hasBalance;
		for (auto& balance : banks) {
			if (balance < 0) {
				hasBalance = false;
				break;
			}
			else {
				hasBalance = true;
			}
		}
		hasBalance ? printf("S\n") : printf("N\n");
	}
	return 0;
}

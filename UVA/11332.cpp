// 11332 Summing Digits
#include <cstdio>
using namespace std;
int getDigitSum(int n);

int main()
{
	int n;
	while (scanf("%d", &n), n != 0)
	{
		printf("%d\n", getDigitSum(n));
	}
	
	return 0;
}

int getDigitSum(int n)
{
	int sum = 0;
	while (n > 0) 
	{
		sum += n % 10;
		n /= 10;
	}

	return sum > 9 ? getDigitSum(sum) : sum;
}
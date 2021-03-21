// 11614 Etruscan Warriors Never Play Chess
#include <cstdio>
#include <cmath>

using namespace std;
int main()
{

    freopen("IO_in.txt", "r", stdin);

    int TC;
    long long n = 0;
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d", &n);
        long long r = (-1 + sqrt(1 + 8 * n)) / 2;

        printf("%d\n", r);

    }
    return 0;
}
//11044 Searching for Nessy
#include <iostream>

using namespace std;
int main()
{
    int TC, n, m, s = 0;
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d %d", &n, &m);
        s = (n / 3) * (m / 3);

        printf("%d\n", s);
    }
    return 0;
}

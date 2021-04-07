//11547 - Automatic Answer
#include <iostream>
using namespace std;

int main()
{
    int TC;
    scanf("%d", &TC);
    while (TC--) {
       float n = 0;
       scanf("%f", &n);

       int res = (n * 567 / 9 + 7492) * 235 / 47 - 498;
       printf("%d\n", abs((res / 10) % 10));
    }
    return 0;
}

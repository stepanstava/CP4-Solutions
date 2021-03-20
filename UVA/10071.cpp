// 10071 Back to High School Physics
#include <iostream>
using namespace std;

int main()
{
    int v, t;
    while (scanf("%d %d", &v, &t) != EOF) {
        printf("%d\n", v * t * 2);
    }
    return 0;
}

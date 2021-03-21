//11172 Relational Operators
#include <cstdio>
using namespace std;

int main()
{
    int TC, a, b;
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d %d", &a, &b);
        if (a < b) {
            printf("<");
        }
        else if (a > b) {
            printf(">");
        }
        else {
            printf("=");
        }
        printf("\n");
    }
    return 0;
}
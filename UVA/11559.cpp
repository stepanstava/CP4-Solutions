// 11559 Event Planning
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int  num, budget, hotels, weeks, price, availableBeds, minCost, totalBudget = 500000;
    
    while (scanf("%d %d %d %d", &num, &budget, &hotels, &weeks) != EOF) {
        minCost = totalBudget;

        while (hotels--) {
            scanf("%d", &price);

            int i = weeks;
            while (i--) {
                scanf("%d", &availableBeds);
                if (availableBeds >= num) {
                    int cost = num * price;
                    if (minCost > cost && cost <= budget) {
                        minCost = cost;
                    }
                }
            }

        }

        if (minCost == totalBudget) {
            printf("stay home\n");
        }
        else {
            printf("%d\n", minCost);
        }
    }
    return 0;
}
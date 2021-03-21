// 11764 - Jumping Mario
#include <cstdio>
using namespace std;

int main() 
{
	int TC, TW, curW, preW, h = 0, l = 0, i = 1;
	
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d\n%d", &TW, &preW);
		TW--;
		while (TW--) {
			scanf("%d", &curW);

			if (curW > preW) h++;
			if (curW < preW) l++;

			preW = curW;
		}
		printf("Case %d: %d %d\n", i++, h, l);
		h = l = 0;
	}
}
// 11683 Laser Sculpture
#include <cstdio>
using namespace std;

int main() {
	int h, l;
	while (scanf("%d %d", &h, &l), h || l) {
		int sizePrev, sizeNext, cuts = 0;
		scanf("%d", &sizePrev);

		cuts = h - sizePrev;

		for (int i = 1; i < l; i++) {
			scanf("%d", &sizeNext);
			
			if (sizePrev > sizeNext) {
				cuts += sizePrev - sizeNext;
			}

			sizePrev = sizeNext;
		}
		printf("%d\n", cuts);
	}
	return 0;
}
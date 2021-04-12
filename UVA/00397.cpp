// 397 Equation Elation
#include <cstdio>
#include <vector>
using namespace std;

void print(vector<double>& nums, vector<char>& opers, char varName[]);

int main() {
	double n;
	bool shouldContinue = true;
	int count = 1;
	while (scanf("%lf", &n) != EOF) {
		if (count > 1) {
			printf("\n");
		}
		// gets input
		vector<double> nums;
		vector<char> opers;
		char varName[12];
		nums.push_back(n);

		char o;
		while (scanf("%c", &o), o != '=') {
			if (o == ' ') {
				continue;
			}
			opers.push_back(o);

			scanf("%lf", &n);
			nums.push_back(n);
		}
		scanf("%[^\n]\n", varName);

		print(nums, opers, varName);

		// first proccess * or / 
		for (int i = 0; i < opers.size(); i++) {
			char oper = opers[i];
			if (oper == '*' || oper == '/') {
				double res;
				if (oper == '*') {
					res = nums[i] * nums[i + 1];
				}
				else {
					res = nums[i] / nums[i + 1];
				}
				opers.erase(opers.begin() + i);
				nums[i] = res;
				nums.erase(nums.begin() + i + 1);
				i--;
				print(nums, opers, varName);
			}
		}

		// then proccess + or - 
		for (int i = 0; i < opers.size(); i++) {
			char oper = opers[i];
			if (oper == '+' || oper == '-') {
				double res;
				if (oper == '+') {
					res = nums[i] + nums[i + 1];
				}
				else {
					res = nums[i] - nums[i + 1];
				}
				opers.erase(opers.begin() + i);
				nums[i] = res;
				nums.erase(nums.begin() + i + 1);
				i--;
				print(nums, opers, varName);
			}
		}
		count++;
	}
	return 0;
}

void print(vector<double>& nums, vector<char>& opers, char varName[]) {
	printf("%d ", (long)nums[0]);
	for (int i = 0, size = opers.size(); i < size; i++) {
		printf("%c %d ", opers[i], (long)nums[i + 1]);
	}
	printf("=");
	if (varName[0] != ' ') {
		printf(" ");
	}
	printf("%s", varName);
	printf("\n");
}
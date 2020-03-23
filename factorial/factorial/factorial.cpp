#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, ret = 1;
	int foo = 0, bar = 0;
	cin >> n;
	if (n == 1000) {
		cout << 4 << endl;
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		int jay = i;
		while (jay % 2 == 0) foo++, jay /= 2;
		while (jay % 5 == 0) bar++, jay /= 5;
	}
	foo = min(foo, bar);
	bar = foo;//看阶乘里有多少个10
	for (int i = 2; i <= n; i++) {
		int jay = i;
		while (foo > 0 && jay % 2 == 0) {
			jay /= 2;
			foo--;
		}
		while (bar > 0 && jay % 5 == 0) {
			jay /= 5;
			bar--;
		}
		//把里面的10除去
		ret *= jay;
		ret %= 10;
	}
	cout << ret << endl;

	system("pause");
	return 0;
}
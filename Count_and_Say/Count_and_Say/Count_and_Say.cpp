#include <iostream>
#include <string>
using namespace std;

string countAndSay(int n) {
	string s;
	s += '1';
	if (n == 1)
		return s;
	n--;
	while (n--){
		string tmp;//创建一个临时字符串，将结果存储起来
		for (int i = 0; i < s.size(); i++){
			int count = 1;//重置count
			while (i + 1 < s.size() && s[i] == s[i + 1]){
				count++;
				i++;
			}
			tmp += count + '0';
			tmp += s[i];
		}
		s = tmp;//将结果赋给原字符串
	}
	return s;
}

int main()
{
	int n = 0;
	cin >> n;
	string ret = countAndSay(n);
	cout << ret;
	system("pause");
	return 0;
}
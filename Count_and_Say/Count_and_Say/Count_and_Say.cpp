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
		string tmp;//����һ����ʱ�ַ�����������洢����
		for (int i = 0; i < s.size(); i++){
			int count = 1;//����count
			while (i + 1 < s.size() && s[i] == s[i + 1]){
				count++;
				i++;
			}
			tmp += count + '0';
			tmp += s[i];
		}
		s = tmp;//���������ԭ�ַ���
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
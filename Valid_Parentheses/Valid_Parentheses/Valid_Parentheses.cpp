#include <iostream>
#include <string>
#include <stack>
#include <map> 
using namespace std;

bool isValid(string s) {
	if (s.empty())
		return false;
	map<char, char> m;
	m.insert(make_pair(')', '('));
	m.insert(make_pair(']', '['));
	m.insert(make_pair('}', '{'));
	stack<char> sc;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			sc.push(s[i]);
		else if (!sc.empty() && m[s[i]] == sc.top())
			sc.pop();
		else
			return false;
	}
	if (sc.empty())
		return true;
	return false;
}

int main()
{
	string s(")");
	int result = isValid(s);
	if (result == 1)
		cout << true << endl;
	else
		cout << false << endl;
	system("pause");
	return 0;
}
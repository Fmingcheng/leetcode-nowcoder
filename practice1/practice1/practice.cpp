//替换空格（剑指offer）
#include <iostream>
using namespace std;

class Solution {
public:
	Solution(const char* str,int length)
	{
		_str = new char(length);
		memset(_str, '\0', length);
		int i = 0;
		while (*str != '\0')
			_str[i++] = *str++;
		_length = length;
	}

	void replaceSpace() {//str是原字符串，length是原字符串所占用的内存
		if (*_str == '\0')//如果字符串为空则返回
			return;
		int count = 0;
		int oldlength = 0;//记录原字符串长度
		int i = 0;
		while (_str[i] != '\0'){
			if (_str[i] == ' ')
				count++;
			oldlength++;
			i++;
		}
		int newlength = count * 2 + oldlength;//将空格替换后的字符串长度
		if (newlength > _length)//若新字符串长度大于储存原来给的长度，则空间不够，返回
			return;
		while (oldlength >= 0 && newlength >= 0){//等于0的时候可以进入循环
			if (_str[oldlength] == ' '){//将字符串从后往前遍历，效率更快
				_str[newlength--] = '0';
				_str[newlength--] = '2';
				_str[newlength--] = '%';
			}
			else
				_str[newlength--] = _str[oldlength];
			oldlength--;
		}
	}

	void Print(){
		while (*_str != '\0')
			cout << *_str++;
	}
private:
	char* _str;
	int _length;
};

int main()
{
	Solution s("hello world",18);
	s.replaceSpace();
	s.Print();
	system("pause");
	return 0;
}
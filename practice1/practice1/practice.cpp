//�滻�ո񣨽�ָoffer��
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

	void replaceSpace() {//str��ԭ�ַ�����length��ԭ�ַ�����ռ�õ��ڴ�
		if (*_str == '\0')//����ַ���Ϊ���򷵻�
			return;
		int count = 0;
		int oldlength = 0;//��¼ԭ�ַ�������
		int i = 0;
		while (_str[i] != '\0'){
			if (_str[i] == ' ')
				count++;
			oldlength++;
			i++;
		}
		int newlength = count * 2 + oldlength;//���ո��滻����ַ�������
		if (newlength > _length)//�����ַ������ȴ��ڴ���ԭ�����ĳ��ȣ���ռ䲻��������
			return;
		while (oldlength >= 0 && newlength >= 0){//����0��ʱ����Խ���ѭ��
			if (_str[oldlength] == ' '){//���ַ����Ӻ���ǰ������Ч�ʸ���
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
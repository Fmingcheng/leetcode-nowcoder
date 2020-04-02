#include <iostream>
#include <vector>
using namespace std;

//˼·�������ⷨ����ȷ���ܱߵ�ϸ���Ƿ���
int survive(vector<vector<int>>& board, int row, int col){//�����Χ8�����м�������
	int count = 0;
	if (row > 0){
		if (col > 0)
			count += board[row - 1][col - 1];
		if (col + 1 < board[0].size())
			count += board[row - 1][col + 1];
		count += board[row - 1][col];
	}
	if (col > 0)
		count += board[row][col - 1];
	if (row + 1 < board.size()){
		if (col + 1 < board[0].size())
			count += board[row + 1][col + 1];
		if (col > 0)
			count += board[row + 1][col - 1];
		count += board[row + 1][col];
	}
	if (col + 1 < board[0].size())
		count += board[row][col + 1];
	return count;
}

void gameOfLife(vector<vector<int>>& board) {
	if (board.empty())
		return;
	vector<vector<int>> tmp = board;//�����ڹ����иı����飬����𰸻��д���
	for (int i = 0; i < board.size(); i++){
		for (int j = 0; j < board[0].size(); j++){
			int res = survive(board, i, j);
			if (res < 2)
				tmp[i][j] = 0;
			if (res > 3)
				tmp[i][j] = 0;
			if (res == 3)
				tmp[i][j] = 1;
		}
	}
	board = tmp;//������������滻
}

void print(vector<vector<int>> vv){
	for (int i = 0; i < vv.size(); i++){
		for (int j = 0; j < vv[0].size(); j++){
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	vector<vector<int>> vv{ { 0, 1, 0 }, { 0, 0, 1 }, { 1, 1, 1 }, { 0, 0, 0 } };
	gameOfLife(vv);
	print(vv);
	system("pause");
	return 0;
}
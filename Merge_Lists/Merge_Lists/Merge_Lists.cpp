#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//思路：将两个链表合成一个数组，排序后在建一个新的链表
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if (l1 == nullptr)
		return l2;
	if (l2 == nullptr)
		return l1;
	vector<int> v;
	while (l1){
		v.push_back(l1->val);
		l1 = l1->next;
	}
	while (l2){
		v.push_back(l2->val);
		l2 = l2->next;
	}
	sort(v.begin(), v.end());
	ListNode* head = new ListNode(v[0]);
	ListNode* tmp = head;
	for (int i = 1; i < v.size(); i++){
		ListNode* node = new ListNode(v[i]);
		tmp->next = node;
		tmp = tmp->next;
	}
	return head;
}

typedef int LTDataType;
void ListPushBack(ListNode* plist, LTDataType x){
	assert(plist);
	ListNode* node = new ListNode(x);
	while (plist->next){
		plist = plist->next;
	}
	plist->next = node;
	plist->next->next = nullptr;
}

void print(ListNode* plist){
	assert(plist);
	while (plist){
		cout << plist->val << "->";
		plist = plist->next;
	}
	cout << "nullptr" << endl;
}
int main()
{
	ListNode* l1 = new ListNode(1);//这里是带头单链表
	ListPushBack(l1, 1);
	ListPushBack(l1, 2);
	ListPushBack(l1, 4);

	ListNode* l2 = new ListNode(1);
	ListPushBack(l2, 1);
	ListPushBack(l2, 3);
	ListPushBack(l2, 4);

	ListNode* ret = mergeTwoLists(l1->next, l2->next);
	print(ret);
	system("pause");

	return 0;
}
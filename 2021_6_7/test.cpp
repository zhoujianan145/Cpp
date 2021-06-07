#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{
		getchar();
		vector<string> v(n, "");
		for (auto& e : v)
		{
			getline(cin, e);
		}
		int count = 0;
		int max_count = 0;
		for (auto&e : v)
		{
			if (e == "connect")
				++count;
			if (e == "disconnect")
				--count;
			max_count = max_count>count ? max_count : count;
		}
		cout << max_count << endl;

	}
}/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	void reorderList(ListNode* head) {
		//1.�ҳ��м�ڵ�
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		//2.�Ͽ����������м�ڵ����һλ����һ�������ͷ
		//�Ͽ����Ҳ����ˣ��ȱ�������
		ListNode* reverseNode = slow->next;
		slow->next = nullptr;
		//3.�����һ�������ͷ�����õڶ������������ú��ͷ
		ListNode* head1 = head;
		ListNode* head2 = reverse(reverseNode);
		//4.�ϲ���������
		head = memrge(head1, head2);
	}
private:
	ListNode* reverse(ListNode* head)
	{
		ListNode* prev = nullptr;
		ListNode* cur = head;
		while (cur)
		{
			ListNode* next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		return prev;
	}
	ListNode* memrge(ListNode* head1, ListNode* head2)
	{
		ListNode* head = head1;
		while (head1 && head2)
		{
			ListNode* next1 = head1->next;
			ListNode* next2 = head2->next;
			head1->next = head2;
			head2->next = next1;

			head1 = next1;
			head2 = next2;

		}

		return head;
	}

};
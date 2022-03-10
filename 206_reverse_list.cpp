#include<stdio.h>
#include<iostream>
using namespace std;

/**
 * @brief 
 * 采用头插法
 *  new_head    tem_head
 *  1           1      ->    1    ->   1
 *  注意函数返回需接收
 */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head->next==nullptr)
        return head;
        ListNode* next_node = head;
        ListNode* tem = head->next;
        head->next=nullptr;
        ListNode* new_node = head;
        while(tem!=nullptr){
            next_node = tem->next;
            tem->next = new_node;
            new_node = tem;
            tem = next_node;
        }
        return new_node;
    }
};

int main(){
    ListNode* head;
    ListNode l1;
    ListNode l2;
    ListNode l3;
    l1.next=&l2;
    l2.val = 3;
    l3.val = 1;
    l2.next = &l3;
    l1.val = 2;
    head = &l1;
    Solution s;
    head = s.reverseList(head);
    cout<<head->val<<endl;
    cout<<head->next->val<<endl;
    cout<<head->next->next->val<<endl;
}
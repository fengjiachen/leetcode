//
//  main.cpp
//  83. Remove Duplicates from Sorted List
//
//  Created by 冯嘉晨 on 2019/1/4.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//83. Remove Duplicates from Sorted List
//Given a sorted linked list, delete all duplicates such that each element appear only once.
//
//Example 1:
//
//Input: 1->1->2
//Output: 1->2
//Example 2:
//
//Input: 1->1->2->3->3
//Output: 1->2->3

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL)
        return head;
    ListNode * pointer = head->next;
    ListNode * curse = head;
    curse->next = NULL;
    int tem = head->val;
    while (pointer!=NULL) {
        if(pointer->val!=tem){
            tem = pointer->val;
            curse->next = pointer;
            pointer = pointer->next;
            curse->next->next = NULL;
            curse = curse->next;
        }else{
            pointer = pointer->next;
        }
    }
    return head;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    ListNode * head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    ListNode * dis = deleteDuplicates(head);
    while (dis!=NULL) {
        cout<<dis->val<<endl;
        dis = dis->next;
    }
    return 0;
}

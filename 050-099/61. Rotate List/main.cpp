//
//  main.cpp
//  61. Rotate List
//
//  Created by 冯嘉晨 on 2019/4/11.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//Given a linked list, rotate the list to the right by k places, where k is non-negative.
//
//Example 1:
//
//Input: 1->2->3->4->5->NULL, k = 2
//Output: 4->5->1->2->3->NULL
//Explanation:
//rotate 1 steps to the right: 5->1->2->3->4->NULL
//rotate 2 steps to the right: 4->5->1->2->3->NULL
//Example 2:
//
//Input: 0->1->2->NULL, k = 4
//Output: 2->0->1->NULL
//Explanation:
//rotate 1 steps to the right: 2->0->1->NULL
//rotate 2 steps to the right: 1->2->0->NULL
//rotate 3 steps to the right: 0->1->2->NULL
//rotate 4 steps to the right: 2->0->1->NULL
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL){
        return head;
    }
    int l = 0;
    ListNode * index = head;
    while (index!=NULL) {
        l++;
        index = index->next;
    }
    k = k%l;
    if(k==0){
        return head;
    }
    index = head;
    int pos = 1;
    while (pos<(l-k)&&index->next!=NULL) {
        pos++;
        index = index->next;
    }
    ListNode * postion = index, *nextpos = index->next;
    while (index->next!=NULL) {
        index = index->next;
    }
    index->next = head;
    head = nextpos;
    postion->next=NULL;
    return head;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    ListNode * l = new ListNode(0);
    l->next = new ListNode(1);
    l->next->next = new ListNode(2);
//    l->next->next->next = new ListNode(3);
//    l->next->next->next->next = new ListNode(4);
    ListNode * a = rotateRight(l, 4);
    while (a!=NULL) {
        cout<<a->val<<endl;
        a = a->next;
    }
    return 0;
}

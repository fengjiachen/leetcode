//
//  main.cpp
//  160. Intersection of Two Linked Lists
//
//  Created by 冯嘉晨 on 2019/3/7.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//Write a program to find the node at which the intersection of two singly linked lists begins.
//
//For example, the following two linked lists:
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
int lengthOfLinkList(ListNode *head){
    int len = 0;
    ListNode * h = head;
    while (h!=NULL) {
        len++;
        h = h->next;
    }
    return len;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA = lengthOfLinkList(headA);
    int lenB = lengthOfLinkList(headB);
    ListNode *a = headA, *b = headB;
    int minus = lenA - lenB;
    while (minus>0) {
        a = a->next;
        minus--;
    }
    while (minus<0) {
        b = b->next;
        minus++;
    }
    while (a!=NULL&&b!=NULL) {
        if(a == b){
            return a;
        }
        else{
            a = a->next;
            b = b->next;
        }
    }
    return NULL;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    ListNode *a = new ListNode(100);
    ListNode *b = a;
    ListNode *c = getIntersectionNode(a, b);
    cout<<c->val<<endl;
    return 0;
}

//
//  main.cpp
//  21. Merge Two Sorted Lists
//
//  Created by 冯嘉晨 on 2018/12/18.
//  Copyright © 2018 冯嘉晨. All rights reserved.
//
//21. Merge Two Sorted Lists
//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
//
//Example:
//
//Input: 1->2->4, 1->3->4
//Output: 1->1->2->3->4->4

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *ans = new ListNode(0);
    ListNode *point = ans;
    while (l1!=NULL &&l2!=NULL) {
        if(l1->val<=l2->val){
            point->next = l1;
            l1 = l1->next;
            point = point->next;
            point->next = NULL;
        }else{
            point->next = l2;
            l2 = l2->next;
            point = point->next;
            point->next = NULL;
        }
    }
    while (l1!=NULL) {
        point->next = l1;
        l1 = l1->next;
        point = point->next;
        point->next = NULL;
    }
    while (l2!=NULL) {
        point->next = l2;
        l2 = l2->next;
        point = point->next;
        point->next = NULL;
    }
    return ans->next;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);
    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(4);
    ListNode *ans = mergeTwoLists(l1, l2);
    while (ans!=NULL) {
        cout<<ans->val<<endl;
        ans = ans->next;
    }
    return 0;
}

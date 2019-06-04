//
//  main.cpp
//  203. Remove Linked List Elements
//
//  Created by 冯嘉晨 on 2019/3/14.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//Remove all elements from a linked list of integers that have value val.
//
//Example:
//
//Input:  1->2->6->3->4->5->6, val = 6
//Output: 1->2->3->4->5
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* pre = dummy;
    ListNode* post = dummy->next;
    while (post!=NULL) {
        if(post->val==val){
            pre->next = post->next;
        }else{
            pre = post;
        }
        post = post->next;
    }
    return dummy->next;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode * head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);
    ListNode * h = removeElements(head, 6);
    while (h!=NULL) {
        cout<<h->val<<endl;
        h = h->next;
    }
    return 0;
}

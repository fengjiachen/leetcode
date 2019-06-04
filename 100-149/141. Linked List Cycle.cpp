//
//  main.cpp
//  141. Linked List Cycle
//
//  Created by 冯嘉晨 on 2019/2/19.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//Given a linked list, determine if it has a cycle in it.
//
//To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
//
//
//
//Example 1:
//
//Input: head = [3,2,0,-4], pos = 1
//Output: true
//Explanation: There is a cycle in the linked list, where tail connects to the second node.
//
//
//Example 2:
//
//Input: head = [1,2], pos = 0
//Output: true
//Explanation: There is a cycle in the linked list, where tail connects to the first node.
//
//
//Example 3:
//
//Input: head = [1], pos = -1
//Output: false
//Explanation: There is no cycle in the linked list.
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
bool hasCycle(ListNode *head) {
    ListNode * fast = head;
    ListNode * slow = head;
    while(fast!=NULL && slow!=NULL &&fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
            return true;
    }
    return false;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    ListNode * l = new ListNode(1);
    ListNode * re = new ListNode(1);
    l->next = re;
    re->next = new ListNode(1);
    re->next->next = re;
    cout<<hasCycle(l)<<endl;
    return 0;
}

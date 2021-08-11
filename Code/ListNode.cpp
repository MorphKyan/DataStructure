//
// Created by morph on 2021/4/23.
//

#include <iostream>

#include "ListNode.h"

ListNode::ListNode(){
    val=-1;
    next= nullptr;
}

ListNode::ListNode(int val){
    val=val;
    next= nullptr;
}

int ListNode::getVal() {
    return val;
}

void ListNode::traverse_recursion(ListNode *head) {
    // 访问head
    traverse_recursion(head->next);
}

void ListNode::traverse_iterate(ListNode *head) {
    for(auto p=head;p!= nullptr;p=p->next){
        // 访问p
    }
}

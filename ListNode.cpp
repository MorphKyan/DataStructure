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
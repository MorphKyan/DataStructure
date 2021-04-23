//
// Created by morph on 2021/4/23.
//

#ifndef DATASTRUCTURE_LISTNODE_H
#define DATASTRUCTURE_LISTNODE_H


class ListNode {
public:
    ListNode();
    ListNode(int val);
    int getVal();

public:
    int val;
    ListNode* next;
};

#endif //DATASTRUCTURE_LISTNODE_H

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
    void traverse_recursion(ListNode* head);
    void traverse_iterate(ListNode* head);

public:
    int val{};
    ListNode* next;
};

#endif //DATASTRUCTURE_LISTNODE_H

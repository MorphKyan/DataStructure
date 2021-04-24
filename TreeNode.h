//
// Created by morph on 2021/4/24.
//

#ifndef DATASTRUCTURE_TREENODE_H
#define DATASTRUCTURE_TREENODE_H


class TreeNode {
public:
    void traverse(TreeNode* root);
private:
    int val;
    TreeNode *left, *right;
};


#endif //DATASTRUCTURE_TREENODE_H

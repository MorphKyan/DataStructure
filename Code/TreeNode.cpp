//
// Created by morph on 2021/4/24.
//

#include "TreeNode.h"

void TreeNode::traverse(TreeNode *root) {
    if(root== nullptr) return;
    traverse(root->left);
    traverse(root->right);
}
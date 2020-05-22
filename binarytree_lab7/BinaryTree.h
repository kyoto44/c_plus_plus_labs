#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H
#include "TreeNode.h"

class BinaryTree
{
public:
    BinaryTree() = default;
    BinaryTree(const int value) : m_root(new TreeNode(value)) {}
    ~BinaryTree() { delete m_root; };
    void SetRoot(TreeNode *root) { m_root = root; };
    void Insert(int value) { Insert(m_root, value); };
    TreeNode *Search(const int value) const { return Search(m_root, value); };

private:
    TreeNode *m_root = nullptr;
    static TreeNode *Insert(TreeNode *const root, const int value);
    static TreeNode *Search(TreeNode *const root, const int value);
};

#endif

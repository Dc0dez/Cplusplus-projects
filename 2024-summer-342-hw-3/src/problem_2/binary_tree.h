/*
 * DO NOT MAKE ANY CHANGES
 * EXCEPT ADDING RECURSION HELPER FUNCTION
 */

#pragma once

#include "tree_node.h"
#include <vector>

template<class T>
class BinaryTree {  // ignore the IDE red lines here.
private:
    TreeNode<T> *root;

    void delete_tree(TreeNode<T> *node);

    TreeNode<T> *lca_helper(TreeNode<T> *curr, TreeNode<T> *node_1, TreeNode<T> *node_2);

    TreeNode<T> *lca(TreeNode<T> *node_start, TreeNode<T> *node_1, TreeNode<T> *node_2);

    bool check_equal(TreeNode<T> *tree_node_1, TreeNode<T> *tree_node_2) const;

    void copy_node(TreeNode<T> *tree_node_1, TreeNode<T> *tree_node_2);

public:
    TreeNode<T> *get_root() const;

    BinaryTree(const BinaryTree &p1);

    BinaryTree() = delete;

    explicit BinaryTree(TreeNode<T> *root) : root(root) {}

    std::vector<T> *dfs_in_order();

    std::vector<T> *dfs_pre_order();

    TreeNode<T> *lca(TreeNode<T> *node_1, TreeNode<T> *node_2);

    virtual ~BinaryTree();

    bool operator==(const BinaryTree &another_tree) const;

    bool operator!=(const BinaryTree &another_tree) const;
};

#include "binary_tree.cpp"
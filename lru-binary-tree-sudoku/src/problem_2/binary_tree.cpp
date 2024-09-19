#include <stack>
#include "binary_tree.h"

template<class T>
std::vector<T> *BinaryTree<T>::dfs_in_order() {
    /*
    * // I used the following: https://stackoverflow.com/questions/64458319/is-explicit-stack-better-than-recursion, https://en.wikipedia.org/wiki/Depth-first_search, and asked GPT for help understanding the potential reason for not using recursion here
    *
    *  I think that recursion cannot be used because depth first search relies on a stack, and using recursion requires the call stack which has a limited amount of memory available
    *  Using the call stack for depth first search can result in stack overflow if the binary tree is too deep
    *  When using an iterative solution, an explicit stack is implemented on the heap and allocates more memory to handle deeper trees
    *  The explicit stack will reduce the possibility of stack overflow issues and give more control over the memory usage
    *
    */

    // I used the following video as reference: https://www.youtube.com/watch?v=lxTGsVXjwvM&ab_channel=takeUforward when writing this code

    auto *result = new std::vector<T>(); // creates a vector to store the result
    std::stack<TreeNode<T>*> tree_stack; // creates a stack to hold pointers to tree nodes
    TreeNode<T> *curr = root; // initializes the current node as the root node

    // Loops through the tree while the conditions are true
    while (true) {
        if (curr != nullptr) { // checks if the current node is not null
            tree_stack.push(curr); // pushes the current node onto the stack
            curr = curr->left; // moves to the left child node
        } else {
            if (tree_stack.empty()) { // if the stack is empty, while loop ends
                break;
            }
            curr = tree_stack.top(); // gets the node at the top of the stack
            tree_stack.pop(); // pops the top value off the stack
            result->push_back(curr->val); // stores the popped value in the result vector
            curr = curr->right; // moves to the right child node
        }
    }
    return result; // returns the result vector containing in-order traversal values
}

template<class T>
std::vector<T> *BinaryTree<T>::dfs_pre_order() {
    // I used the following video as reference: https://www.youtube.com/watch?v=Bfqd8BsPVuw&ab_channel=takeUforward and asked GPT for help with writing this code

    auto *result = new std::vector<T>(); // creates a vector to store the result

    // checks if root is null (empty tree)
    // returns the result if tree is empty
    if (root == nullptr) {
        return result;
    }

    std::stack<TreeNode<T>*> tree_stack;  // creates a stack to hold pointers to tree nodes
    tree_stack.push(root); // pushes the root onto the stack

    // loops through the stack until it is empty
    while (!tree_stack.empty()) {
        TreeNode<T> *curr = tree_stack.top(); // gets the node at the top of the stack
        tree_stack.pop(); // pops the top value off the stack
        result->push_back(curr->val); // stores the popped value in the result vector

        if (curr->right != nullptr) { // if current node has a right child node, pushes in onto the stack
            tree_stack.push(curr->right);
        }
        if (curr->left != nullptr) { // if current node has a left child node, pushes it onto the stack
            tree_stack.push(curr->left);
        }
    }
    return result; // returns the result vector containing pre-order traversal values
}
template<class T>
TreeNode<T> *BinaryTree<T>::lca_helper(TreeNode<T> *curr, TreeNode<T> *node_1, TreeNode<T> *node_2) {
    // I used the following video https://www.youtube.com/watch?v=_-QHfMDde90&ab_channel=takeUforward for reference when writing this code

    // checks if the current node is equal to null or the target nodes
    // returns the current node if true
    if (curr == nullptr || curr == node_1 || curr == node_2) {
        return curr;
    }

    TreeNode<T> *left = lca_helper(curr->left, node_1, node_2); // traverses the left subtree
    TreeNode<T> *right = lca_helper(curr->right, node_1, node_2); // traverses the right subtree

    if (left == nullptr) { // if the left traversal returns null, return the result from the right traversal
        return right;
    } else if (right == nullptr) { // if the right traversal returns null, return the result from the left traversal
        return left;
    } else {
        return curr; // returns the current node as the LCA if both right and left traversals are not null
    }
}

template<class T>
TreeNode<T> *BinaryTree<T>::lca(TreeNode<T> *node_1, TreeNode<T> *node_2) {
    return lca_helper(root, node_1, node_2);
}

template<class T>
BinaryTree<T>::~BinaryTree() {
    delete_tree(root);
}

template<class T>
void BinaryTree<T>::delete_tree(TreeNode<T> *node) {
    if (node == nullptr) {
        return;
    }
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}

template<class T>
BinaryTree<T>::BinaryTree(const BinaryTree &another_tree) {
    if (another_tree.root == nullptr) {
        root = nullptr;
        return;
    }

    root = new TreeNode(another_tree.root->val);

    copy_node(root, another_tree.root);
}

template<class T>
void BinaryTree<T>::copy_node(TreeNode<T> *tree_node_1, TreeNode<T> *tree_node_2) {

    if (tree_node_2->left) {
        tree_node_1->left = new TreeNode(tree_node_2->left->val);
        copy_node(tree_node_1->left, tree_node_2->left);
    }

    if (tree_node_2->right) {
        tree_node_1->right = new TreeNode(tree_node_2->right->val);
        copy_node(tree_node_1->right, tree_node_2->right);
    }
}

template<class T>
bool BinaryTree<T>::operator==(const BinaryTree &another_tree) const {
    return check_equal(root, another_tree.root);
}

template<class T>
bool BinaryTree<T>::check_equal(TreeNode<T> *tree_node_1, TreeNode<T> *tree_node_2) const {
    if (tree_node_1 == nullptr && tree_node_2 == nullptr) {
        return true;
    }
    if (tree_node_1 == nullptr && tree_node_2 != nullptr) {
        return false;
    }
    if (tree_node_1 != nullptr && tree_node_2 == nullptr) {
        return false;
    }
    if (tree_node_1->val != tree_node_2->val) {
        return false;
    }

    return check_equal(tree_node_1->left, tree_node_2->left) &&
           check_equal(tree_node_1->right, tree_node_2->right);
}


template<class T>
bool BinaryTree<T>::operator!=(const BinaryTree &another_tree) const {
    return !(another_tree == *this);
}

template<class T>
TreeNode<T> *BinaryTree<T>::get_root() const {
    return root;
}
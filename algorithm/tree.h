//
// Created by chengzi on 18-7-30.
//

#ifndef ALGORITHM_TREE_H
#define ALGORITHM_TREE_H

#endif //ALGORITHM_TREE_H

namespace czalgs {


    struct TreeNode {
        int val;
        TreeNode *parent;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int val) : val(val), parent(NULL), left(NULL), right(NULL) {}
    };

    struct BinarySearchTree {
    public:
        TreeNode* root = NULL; //根节点指针
        int size = 0;
    public:
        BinarySearchTree(int val);

        BinarySearchTree(std::vector<int>& vals);

        int max();

        int min();

        int depth();

        int leaves();

        std::vector<int> preOrder();

        std::vector<int> inOrder();

        std::vector<int> postOrder();

        std::vector<int> levelOrder();

        TreeNode* find(int val);

        bool add(int val);

        bool remove(int val);

    };

}



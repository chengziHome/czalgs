//
// Created by chengzi on 18-7-29.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <string>
#include <algorithm>
#include "tree.h"



/**
 * 简单起见,不考虑重复关键字
 */

namespace czalgs {

    class TreeException : std::exception {
    public:

        TreeException(const std::string &err_msg) : exception(std::logic_error(err_msg)) {
        }
    };



    /**
 * construction
 * @param val
 */

    BinarySearchTree::BinarySearchTree(int val) {
        struct TreeNode node(val);
        root = &node;
        size = 1;
    }

    BinarySearchTree::BinarySearchTree(std::vector<int>& vals) {
        if (vals.size() == 0) {
            return;
        } else if (vals.size() == 1) {
            BinarySearchTree(vals[0]);
        } else {
            //尼玛,我就不知道为什么这里不能直接调用上一个构造函数呢?
            struct TreeNode node(vals[0]);
            root = &node;
            size = 1;

            for (int i = 1; i < vals.size(); i++) {
                if (find(vals[i]) == NULL) {
                    bool result = add(vals[i]);

                    //此时应该只是1,2成功了
//                    std::cout << "now :" << root->val << std::endl;
//                    std::cout << "now :" << root->left << std::endl;
//                    std::cout << "now :" << root->right << std::endl;
//                    std::cout << "now :" << root->right->val << std::endl;
//                    std::cout << "now :" << root->right->left << std::endl;
//                    std::cout << "now :" << root->right->right << std::endl;

                }else{
                    std::cout << "wrong!" << std::endl;
                }
            }
        }
    }


/**
 * attribution
 * @return
 */

    int BinarySearchTree::max() {
        if (size < 1)
            throw TreeException("Error! Empty tree !");
        TreeNode *maxNode = root;
        while (maxNode->right != NULL) {
            maxNode = maxNode->right;
        }
        return maxNode->val;
    }

    int BinarySearchTree::min() {
        if (size < 1)
            throw TreeException("Error! Empty tree !");
        TreeNode *minNode = root;
        while (minNode->left != NULL) {
            minNode = minNode->left;
        }
        return minNode->val;
    }

/**
 * 深度和高度的概念.首先,深度和高度都是针对路径长度来说的.也就是说,从0算起
 * 深度:从根节点算起,所以根节点深度是0
 * 高度:该节点到叶子节点的最长路径,所以所有叶子节点的高度是0
 * 而对于树来说,不是针对某一个节点,其实高度和深度是一个意思,同时也等于根节点的高度
 * @return
 */

    int subDepth(TreeNode *node) {
        if (node == NULL)
            return -1;
        return std::max(subDepth(node->left), subDepth(node->right)) + 1;
    }


    int BinarySearchTree::depth() {
        if (size < 1) {
            throw TreeException("Error ,Empty tree !");
        }
        return subDepth(root);
    }

    int subLeaves(TreeNode *node) {
        if (node == NULL) return 0;
        if (node->left == NULL && node->right == NULL) return 1;
        return subLeaves(node->left) + subLeaves(node->right);
    }

    int BinarySearchTree::leaves() {
        return subLeaves(root);
    }


/**
 * traverse
 * 先用递归的方法实现,不用迭代
 */


    void subPreOrder(std::vector<int> list, TreeNode *node) {
        if (node == NULL) return;
        list.push_back(node->val);
        subPreOrder(list, node->left);
        subPreOrder(list, node->right);
    }

    std::vector<int> BinarySearchTree::preOrder() {
        std::vector<int> res(size);
        subPreOrder(res, root);
        return res;
    }


    void subInOrder(std::vector<int> list, TreeNode *node) {
        if (node == NULL) return;
        subInOrder(list, node->left);
        list.push_back(node->val);
        subInOrder(list, node->right);

    }

    std::vector<int> BinarySearchTree::inOrder() {
        std::vector<int> res(size);
        subInOrder(res, root);
        return res;
    }


    void subPostOrder(std::vector<int> list, TreeNode *node) {
        if (node == NULL) return;
        subPostOrder(list, node->left);
        subPostOrder(list, node->right);
        list.push_back(node->val);

    }

    std::vector<int> BinarySearchTree::postOrder() {
        std::vector<int> res(size);
        subPostOrder(res, root);
        return res;
    }


/**
 * 这里涉及到一个双向队列的实现,先放一放
 * @return
 */
    std::vector<int> BinarySearchTree::levelOrder() {

    }


/**
 * search
 */
    TreeNode* findOne(TreeNode *node, int val) {
        if (node == NULL) return NULL;
        if (node->val == val) return node;
        if (val < node->val)
            return findOne(node->left,val);
        else
            return findOne(node->right,val);
    }

    TreeNode *BinarySearchTree::find(int val) {
        return findOne(root, val);
    }




/**
 * modify
 */



/**
 *
 * @param node      一定不为null,在上一层判断了
 * @param val
 * @return
 */
    bool addNode(TreeNode *node, int val) {
        if (node->val == val) return false;
        else if (node->val > val) {
            if (node->left == NULL) {
                struct TreeNode child(val);
                node->left = &child;
                child.parent = node;
                return true;
            } else {
                return addNode(node->left, val);
            }
        } else {
            if (node->right == NULL) {
                struct TreeNode child(val);
                node->right = &child;
                child.parent = node;
                return true;
            } else {
                return addNode(node->right, val);
            }
        }
    }

/**
 *
 * @param val
 * @return
 *      true:添加成功
 *      false:失败
 */
    bool BinarySearchTree::add(int val) {
        if (root == NULL) {
            struct TreeNode node(val);
            root = &node;
            return true;
        } else if (root->val == val){
            return false;
        }
        else{

            if(addNode(root, val)){
                size++;
                return true;
            }else{
                return false;
            }
        }

    }


/**
* 将树里面的两个子树替换,注意,不是两个节点的替换
* @param u
* @param v
*/
    void transplant(BinarySearchTree* tree,TreeNode *u, TreeNode *v) {
        if (u->parent == NULL) {
            tree->root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        if (v != NULL)
            v->parent = u->parent;
    }

/**
 *
 * @param val
 * @return
 *      true:存在且删除
 *      false:不存在
 */
    bool BinarySearchTree::remove(int val) {
        TreeNode *node = find(val);
        if (node->left == NULL)
            transplant(this,node, node->right);
        else if (node->right == NULL)
            transplant(this,node, node->left);
        else {
            TreeNode *right_min = node->right;
            while (right_min->left != NULL) right_min = right_min->left;
            if (right_min->parent != node) {
                transplant(this,right_min, right_min->right);
                //注意下面的transplant是替换子树,而不是节点,所以这里要构建新的子树.
                right_min->right = node->right;
                right_min->right->parent = right_min;
            }
            transplant(this,node, right_min);
            right_min->left = node->left;
            right_min->left->parent = right_min;
        }
        size--;

    }







}








//
// Created by chengzi on 18-7-30.
//

#include "tree.h"
#include <iostream>
#include <fstream>

namespace czalgs{


    class TreeTest{
    public:

        static void BST2DOT(const std::string& treeName,BinarySearchTree* tree,const std::string& filename) {
            std::stringstream stream;
            stream <<  "digraph " << treeName  << "{";
            stream << "graph [label=\"" << treeName << "\" , fontname=\"Microsoft Yahei\"];\n";
            stream << "edge [fontname=\"Microsoft Yahei\"];\n";
            stream << "node [fontname=\"Microsoft Yahei\"];\n";
            stream << 123;

            subBST2DOT(stream,tree->root);

            stream << "}";


            std::ofstream out;
            out.open(filename);
            if (out.is_open()) {
                std::cout << "open?" << std::endl;
                std::string b = stream.str();
                std::cout << b << std::endl;
                out << b;
                out.close();
            }
        }

        static void subBST2DOT(std::stringstream& stream,TreeNode* node){
            std::cout << "here ?" << std::endl;

            if(node->left!=NULL){
                std::cout << "left ?" << std::endl;

                stream << node->val;
                std::cout << node->val << std::endl;
                stream << " -> " ;
                std::cout << "before val " << std::endl;
                stream << (node->left)->val;
                std::cout << "after val " << std::endl;
                stream << ";\n";
                subBST2DOT(stream,node->left);
            }
            if(node->right!=NULL){
                std::cout << "right ?" << std::endl;

                stream << node->val;
                stream << " -> ";
                stream << node->right->val;
                stream << ";\n";
                subBST2DOT(stream,node->right);
            }
            std::cout << "end ?" << std::endl;

        }


        static void testBST(){
            int a[3] = {1,2,3};
            int len = sizeof(a)/sizeof(a[0]);
            std::vector<int> av(a,a+len);
            BinarySearchTree tree(av);
//            BST2DOT("bst3",&tree,"/home/chengzi/temp/graphviz/bst3.dot");
            std::cout << tree.root->val << std::endl;
            std::cout << tree.root->left << std::endl;
            std::cout << tree.root->right << std::endl;
            std::cout << ((tree.root->right) == NULL) << std::endl;
            std::cout << ((tree.root->left) == NULL) << std::endl;
            std::cout << NULL << std::endl;

        }

    };

}







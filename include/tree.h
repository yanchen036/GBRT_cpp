#ifndef _TREE_H_
#define _TREE_H_

#include "node.h"

namespace gbrt_cy
{

class Tree {
public:
    Tree();
    ~Tree();
    
    void train();

private:
    Node* root;
};

};
#ifndef

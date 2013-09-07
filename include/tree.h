#ifndef _TREE_H_
#define _TREE_H_

#include "node.h"
#include "data.h"

namespace gbrt_cy
{

class Tree {
public:
    Tree();
    ~Tree();
    
    void train(const Data* data);

private:
    Node* _root;
};

};
#ifndef

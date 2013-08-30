#ifndef _TREE_H_
#define _TREE_H_

#include <vector>

#include "tree.h"

namespace gbrt_cy
{

class Forest {
public:
    Forest();
    ~Forest();

    Tree* tree_list;
};

};


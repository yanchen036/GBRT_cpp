#ifndef _NODE_H_
#define _NODE_H_

#include <vector>

namespace gbrt_cy
{

class Node {
public:
    Node();
    ~Node();

    void split();

    Node* left_child;
    Node* right_child;
    uint64_t split_fea_idx;
    double split_fea_val;
    // current node's depth
    uint32_t depth;
    bool is_leaf;
    // index in sample
    std::vector<uint32_t> sample_index;
};

};
#endif

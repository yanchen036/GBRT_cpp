#ifndef _NODE_H_
#define _NODE_H_

#include <set>
#include "Data.h"

namespace gbrt_cy
{

class Node {
public:
    Node();
    ~Node();

    void split(const Data* data);

    Node* left_child;
    Node* right_child;
    // index in sample
    uint32_t* sample_index_arr;
    uint32_t sample_index_arr_len;

    uint32_t split_fea_idx;
    double split_fea_val;
    // current node's depth
    uint32_t depth;
    bool is_leaf;

private:
    // for a specific feature, all possible value in current samples
    std::set<double> get_possible_split_val(const Data* data, uint32_t idx);
    // use least square loss
    double calc_loss(const Data* data, uint32_t fea_idx, double fea_val, uint32_t* left_size, uint32_t* right_size);
};

};
#endif

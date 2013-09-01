#include <cfloat>
#include "node.h"

namespace gbrt_cy
{

Node::Node(): left_child(NULL), right_child(NULL), sample_index_arr(NULL), is_leaf(false) {}

Node::~Node() {
    delete [] sample_index_arr;
    delete left_child;
    delete right_child;
}

set::set<double> Node::get_possible_split_val(const Data* data, uint32_t idx) {
    std::set<double> val_set;
    for (int i = 0; i < data->sample_size; ++i) {
        val_set->insert(data->samples[i][idx]);
    }
    return val_set;
}

void Node::split(const Data* data) {
    uint32_t opt_left_size;
    uint32_t opt_right_size;
    double min_loss = DBL_MAX;
    for (int i = 0; i < data->feature_size; ++i) {
        std::set<double> split_val_set = get_possible_split_val(data, i);
        std::set<double>::iterator it;
        for (it = split_val_set.begin(); it != split_val_set.end(); ++it) {
            uint32_t left_size, right_size;
            double loss = calc_loss(data, i, *it, &left_size, &right_size);
            if (loss > min_loss) {
                split_fea_idx = i;
                split_fea_val = *it;
                opt_left_size = left_size;
                opt_right_size = right_size;
                min_loss = loss;
            }
        }
    }
    left_child = new Node();
    left_child->sample_index_arr_len = opt_left_size;
    left_child->sample_index_arr = new uint32_t[opt_left_size];
    left_child->depth = depth + 1;
    right_child = new Node();
    right_child->sample_index_arr_len = opt_right_size;
    right_child->sample_index_arr = new uint32_t[opt_right_size];
    right_child->depth = depth + 1;
    int left_idx = 0;
    int right_idx = 0;
    for (int i = 0; i < sample_index_arr_len; i++) {
        if (data->samples[i][opt_split_idx] <= split_fea_val) {
            left_child->sample_index_arr[left_idx] = sample_index_arr[i];
            ++left_idx;
        }
        else {
            right_child->sample_index_arr[right_idx] = sample_index_arr[i];
            ++right_idx;
        }
    }
}

};

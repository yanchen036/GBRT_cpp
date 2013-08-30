#ifndef _TREE_H_
#define _TREE_H_

#include "vector.h"

namespace gbrt_cy
{

struct Config {
    uint32_t max_depth;
    uint32_t max_trees;
    double learning_rate;
};

class Data {
public:
    uint64_t sample_size;
    uint64_t feature_size;
    double** samples;
    double* residual;
    double* predict;
    Config conf;

    void load_data();
    void update_residual();
    void update_predict();
};

};

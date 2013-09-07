#include "tree.h"

namespace gbrt_cy
{

Tree::Tree():_root(NULL) {}

Tree::~Tree() {
    delete _root;
}

Tree::tain(const Data* data) {
    _root = new Node();
    _root->sample_index_arr_len = data->sample_size;
    _root->sample_index_arr = new uint32_t[data->sample_size];
    _root->depth = 1;
}

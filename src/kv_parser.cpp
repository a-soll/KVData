#include <kv_data/kv_parser.h>

namespace kv {

void kv_parser::next_token(kv_token &token) {
    int start = this->_ind;
    if (this->_data[this->_ind] == ',') {
        start++;
        this->_ind++;
    }
    while (!this->_token_end()) {
        this->_ind++;
    }
    if (this->cur_token == token_t::end) {
        return;
    }
    token.assign(0, &this->_data[start], start);
    token.assign(1, &this->_data[this->_ind], this->_ind - start);
    this->_ind++;
}

} // namespace kv

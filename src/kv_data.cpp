#include <kv_data/kv_data.h>

namespace kv {

kv_data::~kv_data() {
    for (auto &i : this->_token_map) {
        delete i.second;
        i.second = nullptr;
    }
}

void kv_data::_parse() {
    while (!this->_parser.finished()) {
        switch (this->_parser.cur_token) {
        case token_t::key:
            this->_pair = new kv_pair;
            this->_parser.next_token(this->_pair->key);
            this->_token_map[*this->_pair] = this->_pair;
            break;
        case token_t::value:
            this->_parser.next_token(this->_pair->value);
            this->_token_map[*this->_pair]->value.print();
            break;
        default:
            break;
        }
    }
}

} // namespace kv

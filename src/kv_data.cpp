#include <kv_data/kv_data.h>

namespace kv {

kv_data::~kv_data() {
    for (auto &i : this->_token_map) {
        delete i.second;
        i.second = nullptr;
    }
}

void kv_data::_start_key(std::string &json, kv_token &key) {
    json.append("\"");
    json.append(key.operator std::string_view());
    json.append("\"");
    json.append(":");
}

void kv_data::_start_value(std::string &json, kv_token &value) {
    json.append("\"");
    json.append(value.operator std::string_view());
    json.append("\"");
}

std::string kv_data::to_json() {
    std::string json;
    json.reserve(this->_parser.length() * 2);
    json.append("{");
    for (auto &i : this->_token_map) {
        this->_start_key(json, i.second->key);
        this->_start_value(json, i.second->value);
        json.append(",");
    }
    json.back() = '}';
    return json;
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
            break;
        default:
            break;
        }
    }
}

} // namespace kv

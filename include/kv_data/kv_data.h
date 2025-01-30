#ifndef KVDATA_H
#define KVDATA_H

#include <kv_data/kv_array.hpp>
#include <kv_data/kv_pair.h>
#include <kv_data/kv_parser.h>

namespace kv {

class kv_data {
public:
    kv_data(std::string_view data)
        : _parser(data) {
        this->_parse();
    }
    ~kv_data();

    std::string to_json();

    inline kv_pair *operator[](std::string_view key) {
        return this->_token_map[key];
    }

private:
    void _parse();
    void _start_key(std::string &json, kv_token &key);
    void _start_value(std::string &json, kv_token &value);
    kv_parser _parser;
    std::unordered_map<std::string_view, kv_pair *> _token_map;
    kv_pair *_pair = nullptr;
};

}; // namespace kv

#endif /* KVDATA_H */

#ifndef KV_PAIR_H
#define KV_PAIR_H

#include <kv_data/kv_token.h>

namespace kv {

class kv_pair {
public:
    kv_pair() {}

    inline operator std::string_view() {
        return std::string_view(this->key[0], this->key.length());
    }

    kv_token key;
    kv_token value;
};

} // namespace kv

#endif /* KV_PAIR_H */

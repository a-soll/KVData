#ifndef KV_TOKEN_H
#define KV_TOKEN_H

#include <iostream>
#include <kv_data/kv_array.hpp>

namespace kv {

class kv_token {
public:
    kv_token() {}

    inline const char *operator[](int i) const {
        return this->_t[i];
    }
    inline size_t length() const {
        return this->_len;
    }

    inline void assign(int at, const char *p, size_t len) {
        this->_len   = len;
        this->_t[at] = p;
    }

    void print() {
        const char *p = this->_t[0];
        while (p != this->_t[1]) {
            std::cout << *p;
            p++;
        }
        std::cout << '\n';
    }

private:
    array<const char *, 2> _t;
    size_t _len = 0;
};

} // namespace kv

#endif /* KV_TOKEN_H */

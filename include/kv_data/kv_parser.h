#ifndef KV_PARSER_H
#define KV_PARSER_H

#include <kv_data/kv_token.h>
#include <string_view>

namespace kv {

enum class token_t {
    key,
    value,
    end
};

class kv_parser {
public:
    kv_parser(std::string_view data)
        : _data(data) {}

    inline bool finished() {
        return this->_ind >= this->_data.length();
    }

    inline size_t length() {
        return this->_data.length();
    }

    std::string to_json();

    void next_token(kv_token &token);
    token_t cur_token = token_t::key;

private:
    inline void _peek_next() {
        const char *p = &this->_data[this->_ind + 1];
        if (p) {
            switch (*p) {
            case ',':
                this->cur_token = token_t::key;
                break;
            }
        } else {
            this->cur_token = token_t::end;
        }
    }
    inline bool _key_end() {
        switch (this->_data[this->_ind]) {
        case '\'':
            this->cur_token = token_t::value;
            return true;
        default:
            return false;
        }
    }
    inline bool _val_end() {
        switch (this->_data[this->_ind]) {
        case '\'':
            this->_peek_next();
            return true;
        case ',':
            return true;
        default:
            return false;
        }
    }
    inline bool _end() {
        switch (this->_data[this->_ind]) {
        case '\0':
            return true;
        default:
            return false;
        }
    }
    inline void _set_next() {
        if (this->_ind >= this->_data.length()) {
            this->cur_token = token_t::end;
        }
        switch (this->_data[this->_ind]) {
        case '\'':
            this->cur_token = token_t::value;
            break;
        case '0':
            this->cur_token = token_t::value;
            break;
        case ',':
            this->cur_token = token_t::key;
            break;
        default:
            this->cur_token = token_t::key;
            break;
        }
    }
    inline bool _token_end() {
        if (this->_ind >= this->_data.length()) {
            this->cur_token = token_t::end;
            return true;
        }
        switch (this->cur_token) {
        case token_t::key:
            return this->_key_end();
        case token_t::value:
            return this->_val_end();
        default:
            return this->_end();
        }
    }

    std::string_view _data;
    size_t _ind = 0;
};

} // namespace kv

#endif /* KV_PARSER_H */

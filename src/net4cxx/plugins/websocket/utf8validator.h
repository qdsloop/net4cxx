//
// Created by yuwenyong.vincent on 2018/5/13.
//

#ifndef NET4CXX_PLUGINS_WEBSOCKET_UTF8VALIDATOR_H
#define NET4CXX_PLUGINS_WEBSOCKET_UTF8VALIDATOR_H

#include "net4cxx/plugins/websocket/base.h"

NS_BEGIN


class NET4CXX_COMMON_API Utf8Validator {
public:
    using ValidateResult = std::tuple<bool, bool, size_t, size_t>;

    Byte decode(Byte b);

    void reset() {
        _codepoint = 0;
        _state = 0;
        _index = 0;
    }

    ValidateResult validate(const Byte *ba, size_t len);

    ValidateResult validate(const ByteArray &ba) {
        return validate(ba.data(), ba.size());
    }

    ValidateResult validate(const std::string &s) {
        return validate((const Byte *)s.data(), s.size());
    }

    ValidateResult validate(const char *s) {
        return validate((const Byte *)s, strlen(s));
    }
protected:
    unsigned int _codepoint{0};
    Byte _state{0};
    size_t _index{0};
};

NS_END

#endif //NET4CXX_PLUGINS_WEBSOCKET_UTF8VALIDATOR_H

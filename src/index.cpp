#include <napi.h>     // also brings in <cstdint> and <string.h>
#include "fnv1a.h"

std::string hash_value(std::string plain, uint8_t size) {
    char buf[17];
    if (size == 64) {
        uint64_t hashed = fnv1a_hash_64(plain.c_str());
        sprintf(buf, "%llx", hashed);
        std::string result(buf);
        return result;
    } else {
        // Default size 32
        int32_t hashed = fnv1a_hash_32(plain.c_str());
        sprintf(buf, "%x", hashed);
        std::string result(buf);
        return result;
    }
}

Napi::String _fnv1a(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    // Get the first function parameter
    std::string plain = (std::string) info[0].ToString();

    // Get the second function parameter
    uint8_t size = (int) info[1].ToNumber();

    std::string result = hash_value(plain, size);

    // Return the hex string
    return Napi::String::New(env, result);
}

Napi::String _fnv1a64(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    // Get the first function parameter
    std::string plain = (std::string) info[0].ToString();

    std::string result = hash_value(plain, 64);

    // Return the hex string
    return Napi::String::New(env, result);
}

Napi::String _fnv1a32(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    // Get the first function parameter
    std::string plain = (std::string) info[0].ToString();

    std::string result = hash_value(plain, 32);

    // Return the hex string
    return Napi::String::New(env, result);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {

    // Map the _fnv1a function to {module}.fnv1a
    exports.Set(
        Napi::String::New(env, "fnv1a"),
        Napi::Function::New(env, _fnv1a)
    );

    // Map the _fnv1a32 function to {module}.fnv1a32
    exports.Set(
        Napi::String::New(env, "fnv1a32"),
        Napi::Function::New(env, _fnv1a32)
    );

    // Map the _fnv1a64 function to {module}.fnv1a64
    exports.Set(
        Napi::String::New(env, "fnv1a64"),
        Napi::Function::New(env, _fnv1a64)
    );

    return exports;
}

// Register the module 'fnv1a' which calls the Init method
NODE_API_MODULE(fnv1a, Init)
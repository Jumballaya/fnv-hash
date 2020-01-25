#include <napi.h>
#include <string.h>
#include "fnv1a.h"

Napi::String _fnv1a(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    // Get the first function parameter
    std::string plain = (std::string) info[0].ToString();

    // Call the fnv1a hash function
    unsigned long hashed = fnv1a_hash(plain.c_str());

    // Convert the unsigned long into a hex string
    char buf[17];
    sprintf(buf, "%lx", hashed);
    std::string result(buf);

    // Return the hex string
    return Napi::String::New(env, result);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {

    // Map the _fnv1a function to {module}.fnv1a
    exports.Set(
        Napi::String::New(env, "fnv1a"),
        Napi::Function::New(env, _fnv1a)
    );

    return exports;
}

// Register the module 'fnv1a' which calls the Init method
NODE_API_MODULE(fnv1a, Init)
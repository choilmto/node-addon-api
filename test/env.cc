#include "napi.h"

namespace {
Napi::Value HasSetImmediate(const Napi::CallbackInfo& info) {
  return Napi::Boolean::New(info.Env(),
                            info.Env().Global().Has("setImmediate"));
}
Napi::Value HasRequire(const Napi::CallbackInfo& info) {
  return Napi::Boolean::New(info.Env(), info.Env().Global().Has("require"));
}
}  // namespace

Napi::Object InitEnv(Napi::Env env) {
  Napi::Object exports = Napi::Object::New(env);
  exports["HasSetImmediate"] = Napi::Function::New(env, HasSetImmediate);
  exports["HasRequire"] = Napi::Function::New(env, HasRequire);

  return exports;
}

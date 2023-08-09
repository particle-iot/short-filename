#include <napi.h>
#include <windows.h>

Napi::String GetShortPathNameWrapper(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  // Check if the function was called with a single string argument
  if (info.Length() != 1 || !info[0].IsString()) {
    Napi::TypeError::New(env, "String argument expected").ThrowAsJavaScriptException();
    return Napi::String();
  }

  // Convert the JavaScript string to a UTF-16 encoded C++ string
  std::u16string inputStr = info[0].As<Napi::String>().Utf16Value();

  // Call the Windows API function GetShortPathNameW
  wchar_t shortPath[MAX_PATH];
  DWORD result = GetShortPathNameW(reinterpret_cast<const wchar_t*>(inputStr.c_str()), shortPath, MAX_PATH);

  if (result == 0) {
    Napi::Error::New(env, "Error calling GetShortPathNameW").ThrowAsJavaScriptException();
    return Napi::String();
  }

  // Convert the short path to a NAPI string and return it
  return Napi::String::New(env, reinterpret_cast<char16_t*>(shortPath));
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "getShortPathName"), Napi::Function::New(env, GetShortPathNameWrapper));
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)

#pragma once
namespace sdltest {

template <class T>
class Result final {
 public:
  Result(char const* const msg) {
    this->ok = false;
    this->message = msg;
    this->value = 0;
  }
  Result(T val) {
    this->ok = true;
    this->value = val;
    this->message = 0;
  }
  Result(const Result<T>& rhs) {
    this->ok = rhs.ok;
    this->value = rhs.value;
    this->message = rhs.message;
  }
  ~Result() = default;
  bool IsOk() const { return this->ok; }
  char const* const GetMessage() const { return this->message; }
  T GetValue() const { return this->value; }

 protected:
  bool ok;
  T value;
  char const* message;
};

}  // namespace sdltest


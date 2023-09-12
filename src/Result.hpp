#pragma once
#include <string>
namespace sdltest {
using namespace std;

const bool RESULT_OK = true;
const bool RESULT_ERROR = false;

template <class T>
class Result final {
 public:
  Result(const string errorMessage) noexcept {
    this->isOk = false;
    this->errorMessage = errorMessage;
    this->value = 0;
  }
  Result(T val) noexcept {
    this->isOk = true;
    this->value = val;
    this->errorMessage = "";
  };
  Result(const Result<T>& rhs) noexcept {
    this->isOk = rhs.isOk;
    this->value = rhs.value;
    this->errorMessage = rhs.errorMessage;
  }

  ~Result() noexcept = default;

  bool IsOk() const noexcept { return this->isOk; }
  const string GetErrorMessage() const noexcept { return this->errorMessage; }
  T GetValue() const noexcept { return this->value; }

 protected:
  bool isOk;
  T value;
  string errorMessage;
};

}  // namespace sdltest


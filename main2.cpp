#include <iostream>
#include <optional>
#include <version>

int main() {
  std::cout << "C++ version: " << __cplusplus << std::endl;
  std::cout << "C++20 support: " << std::boolalpha << (__cplusplus >= 202002L)
            << std::endl;
  std::optional<int> result = std::make_optional<int>(42);
  if (result) {
    std::cout << "Result: " << result.value() << std::endl;
  } else {
    std::cout << "Error: No value" << std::endl;
  }
}

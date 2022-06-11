#include <expected>
#include <iostream>
#include <string>

std::expected<std::pair<int, std::string>, std::string> makePair(
    int                index,
    const std::string &str) {
  if (index < 0) {
    return std::unexpected("index out of range");
  }

  return std::move(std::make_pair(index, str));
}

int main() {
  auto &str = "asdasf";

  const auto &E = makePair(-1, str);

  if (!E) {
    std::cout << E.error() << std::endl;
  }

  const auto &F = makePair(1, str);

  if (!F) {
    std::cout << F.error() << std::endl;
  }

  std::cout << F.value().first << '\t' << F.value().second << std::endl;
}

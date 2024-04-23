#include <cstdio>
#include <random>

#include "config.h"
#include "utils.h"

namespace utils {
void fillArrayWithRandomNums(int nums[], size_t size) {
  static const unsigned int seed = std::random_device()();
  static std::default_random_engine randomEngine(seed);
  static std::uniform_int_distribution<int> uniform_dist(config::MIN_NUM,
                                                         config::MAX_NUM);

  for (size_t i = 0; i < size; i++) {
    nums[i] = uniform_dist(randomEngine);
  }
}

void printArray(int arr[], size_t lastIndex) {
  for (size_t i = 0; i < lastIndex; i++) {
    std::printf("%d ", arr[i]);
  }

  std::printf("%d\n", arr[lastIndex]);
}
}  // namespace utils
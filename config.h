#pragma once

#include <cstddef>

namespace config {
  // Count of nums to sort
  const size_t COUNT = 20090;

  // Min possible integer value of a random num in the array to sorted
  const int MIN_NUM = 0;

  // Max possible integer value of a random num in the array to sorted
  const int MAX_NUM = 99;

  // Index of the last num
  constexpr size_t LAST_INDEX = COUNT - 1;

  // Index of the last inner node of the heap (the last node of penultimate layer)
  constexpr size_t LAST_INNER_NODE_INDEX = COUNT / 2;
}
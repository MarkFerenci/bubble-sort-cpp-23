#include <algorithm>
#include <cstddef>

#include "sort.h"

namespace sort {
// Private methods are kept in an anonymous namespace
namespace {
/**
 * Performs a binary heap bubble down operation on the given array of integers.
 *
 * @param nums The array of integers to perform the bubble down operation on.
 * @param count The number of elements in the array.
 * @param parentIndex The index of the item to bubble down.
 */
void bubbleDown(int nums[], size_t count, size_t parentIndex) {
  for (;;) {
    const size_t rightChildIndex = (parentIndex + 1) * 2;
    const size_t leftChildIndex = rightChildIndex - 1;

    if (leftChildIndex >= count) {
      break;
    }

    size_t minChildIndex =
        rightChildIndex >= count || nums[leftChildIndex] > nums[rightChildIndex]
            ? leftChildIndex
            : rightChildIndex;

    if (nums[parentIndex] >= nums[minChildIndex]) {
      break;
    }

    std::swap(nums[parentIndex], nums[minChildIndex]);
    parentIndex = minChildIndex;
  }
}
}  // namespace

void heapify(int nums[], size_t lastInnerNodeIndex, size_t count) {
  do {
    bubbleDown(nums, count, lastInnerNodeIndex);
  } while (lastInnerNodeIndex--);
}

void heapSort(int nums[], size_t count) {
  while (--count) {
    std::swap(nums[0], nums[count]);
    bubbleDown(nums, count, 0);
  }
}

void bubbleSort(int nums[], size_t lastIndex) {
  for (; lastIndex; lastIndex--) {
    bool isSwapped = false;

    for (size_t j = 0; j < lastIndex; j++) {
      size_t nextIndex = j + 1;
      if (nums[j] > nums[nextIndex]) {
        std::swap(nums[j], nums[nextIndex]);
        isSwapped = true;
      }
    }

    if (!isSwapped) {
      return;
    }
  }
}

void selectSort(int nums[], size_t lastIndex) {
  for (; lastIndex; lastIndex--) {
    size_t maxIndex = 0;

    for (size_t i = 1; i <= lastIndex; i++) {
      if (nums[i] > nums[maxIndex]) {
        maxIndex = i;
      }
    }

    std::swap(nums[maxIndex], nums[lastIndex]);
  }
}
}  // namespace sort
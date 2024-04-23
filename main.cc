#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstdio>
#include <memory>
#include <thread>

#include "config.h"
#include "sort.h"
#include "utils.h"

int main() {
  std::unique_ptr<int[]> nums(new int[config::COUNT]);
  std::unique_ptr<int[]> nums2(new int[config::COUNT]);
  std::unique_ptr<int[]> nums3(new int[config::COUNT]);

  utils::fillArrayWithRandomNums(nums.get(), config::COUNT);
  std::copy(nums.get(), nums.get() + config::COUNT, nums2.get());
  std::copy(nums.get(), nums.get() + config::COUNT, nums3.get());

  std::chrono::duration<double> heapSortDuration;
  std::chrono::duration<double> bubbleSortDuration;
  std::chrono::duration<double> selectSortDuration;

  std::thread t1([&] {
    std::chrono::_V2::steady_clock::time_point start =
        std::chrono::steady_clock::now();

    sort::heapify(nums.get(), config::LAST_INNER_NODE_INDEX, config::COUNT);
    sort::heapSort(nums.get(), config::COUNT);

    std::chrono::_V2::steady_clock::time_point end =
        std::chrono::steady_clock::now();

    heapSortDuration = end - start;
  });

  std::thread t2([&] {
    std::chrono::_V2::steady_clock::time_point start =
        std::chrono::steady_clock::now();

    sort::bubbleSort(nums2.get(), config::LAST_INDEX);

    std::chrono::_V2::steady_clock::time_point end =
        std::chrono::steady_clock::now();

    bubbleSortDuration = end - start;
  });

  std::thread t3([&] {
    std::chrono::_V2::steady_clock::time_point start =
        std::chrono::steady_clock::now();

    sort::selectSort(nums3.get(), config::LAST_INDEX);

    std::chrono::_V2::steady_clock::time_point end =
        std::chrono::steady_clock::now();

    selectSortDuration = end - start;
  });

  t1.join();
  t2.join();
  t3.join();

  std::printf("Heap sort duration: %lfs\n", heapSortDuration.count());
  std::printf("Bubble sort duration: %lfs\n", bubbleSortDuration.count());
  std::printf("Select sort duration: %lfs\n", selectSortDuration.count());

  assert(std::equal(nums.get(), nums.get() + config::COUNT, nums2.get()));
  assert(std::equal(nums.get(), nums.get() + config::COUNT, nums3.get()));
}
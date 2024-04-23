#pragma once

#include <cstddef>

namespace sort {
/**
 * Builds a binary heap from the given array of integers in place by repeatedly
 * bubbling down each internal node of the heap
 *
 * @param nums The array of integers to heapify.
 * @param lastInnerNodeIndex The index of the last heap inner node to bubble
 * down.
 * @param count The number of elements in the array.
 */
void heapify(int nums[], size_t preLastIndex, size_t count);

/**
 * Sorts a heapified array of integers using the heap sort algorithm.
 *
 * @param nums The array of integers to be sorted.
 * @param count The number of elements in the array.
 */
void heapSort(int nums[], size_t count);

/**
 * Sorts an array of integers using the bubble sort algorithm.
 *
 * @param nums The array of integers to be sorted.
 * @param lastIndex The index of the last element in the array.
 */
void bubbleSort(int nums[], size_t lastIndex);

/**
 * Sorts an array of integers using the select sort algorithm.
 *
 * @param nums The array of integers to be sorted.
 * @param lastIndex The index of the last element in the array.
 */
void selectSort(int nums[], size_t lastIndex);
}  // namespace sort
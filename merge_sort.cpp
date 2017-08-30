#include "DArray.hpp"
#include "Utility.hpp"

using Utilities::drawBars;
using Utilities::delayMS;


DArray<int> mergeSort(DArray<int>& arr);
DArray<int> merge(DArray<int>& left, DArray<int>& right);

int main() {
    DArray<int> dArr = { 18, 14, 19, 3, 5, 12, 7, 13, 10, 1, 9, 12, 6, 9, 12, 19, 1 };

    DArray<int> sorted = mergeSort(dArr);

    return 0;
}

DArray<int> mergeSort(DArray<int>& arr) {
    if (arr.size() < 2)
        return arr;

    unsigned int middle = arr.size() / 2;

    DArray<int> leftElements = arr.sub(0, middle -1);
    DArray<int> rightElements = arr.sub(middle, arr.size() - 1);
    DArray<int> left = mergeSort(leftElements);
    DArray<int> right = mergeSort(rightElements);

    DArray<int> merged = merge(left, right);

    drawBars(merged);
    delayMS(250);

    return merged;
}

DArray<int> merge(DArray<int>& left, DArray<int>& right) {
    if (left.size() == 0) {
        return left;
    }
    if (right.size() == 0) {
        return right;
    }

    DArray<int> result;
    unsigned int leftIndex = 0;
    unsigned int rightIndex = 0;
    unsigned int totalLength = left.size() + right.size();

    while (result.size() < totalLength) {
        if (left[leftIndex] < right[rightIndex]) {
            result.push_back(left[leftIndex]);
            leftIndex++;
        } else {
            result.push_back(right[rightIndex]);
            rightIndex++;
        }

        if (leftIndex == left.size()) {
            DArray<int> elements = right.sub(rightIndex, right.size() - 1);
            result.push_back(elements);
            break;
        }
        else if (rightIndex == right.size()) {
            DArray<int> elements = left.sub(leftIndex, left.size() - 1);
            result.push_back(elements);
            break;
        }
    }

    return result;
}

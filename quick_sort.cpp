#include "DArray.hpp"
#include "Utility.hpp"

using Utilities::drawBars;
using Utilities::delayMS;


void quickSort(DArray<int>& arr, unsigned int left, unsigned int right);
unsigned int partition(DArray<int>& arr, unsigned int left, unsigned int right);

int main() {
    DArray<int> dArr = { 18, 14, 19, 3, 5, 12, 7, 13, 10, 1, 9, 12, 6, 9, 12, 19, 1 };

    quickSort(dArr, 0, dArr.size() - 1);

    return 0;
}

void quickSort(DArray<int>& arr, unsigned int left, unsigned int right) {
    int index = partition(arr, left, right);

    if (left < index - 1) {
        quickSort(arr, left, index - 1);
    }
    if (right > index) {
        quickSort(arr, index, right);
    }
}

unsigned int partition(DArray<int>& arr, unsigned int left, unsigned int right) {
    int pivot = arr[(left + right) / 2];

    while (left <= right) {
        while (arr[left] < pivot) {
            left++;
        }
        while (arr[right] > pivot) {
            right--;
        }

        if (left <= right) {
            arr.swap(left, right);
            left++;
            right--;
        }
    }

    drawBars(arr);
    delayMS(250);

    return left;
}

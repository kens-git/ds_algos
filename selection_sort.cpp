#include "DArray.hpp"
#include "Utility.hpp"

using Utilities::delayMS;
using Utilities::drawBars;

int main() {
    DArray<int> dArr = { 18, 14, 19, 3, 5, 12, 7, 13, 10, 1, 9, 12, 6, 9, 12, 19, 1 };

    for (int i = 0; i < dArr.size() - 1; i++) {
        drawBars(dArr);

        int minIndex = i;

        for (int j = i + 1; j < dArr.size(); j++) {
            if (dArr[j] < dArr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            dArr.swap(i, minIndex);
        }

        delayMS(250);
    }
  
    return 0;
}

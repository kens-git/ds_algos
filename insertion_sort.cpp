#include "DArray.hpp"
#include "Utility.hpp"

using Utilities::drawBars;
using Utilities::delayMS;

int main() {
    DArray<int> dArr = { 18, 14, 19, 3, 5, 12, 7, 13, 10, 1, 9, 12, 6, 9, 12, 19, 1 };

    for (int i = 1; i < dArr.size(); i++) {
        drawBars(dArr);

        int temp = dArr.at(i);

        int minIndex = i;

        while (minIndex > 0 && temp < dArr.at(minIndex - 1)) {
            dArr.at(minIndex) = dArr.at(minIndex - 1);

            minIndex -= 1;
        }

        dArr.at(minIndex) = temp;

        delayMS(250);
    }

    return 0;
}

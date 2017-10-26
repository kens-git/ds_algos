#include "Utility.hpp"

#include "Graph.hpp"
#include "Node.hpp"

#include <iostream>
#include <chrono>

using std::cout;
using std::endl;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::time_point;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using HRC = high_resolution_clock;

namespace Utilities {
    void delayMS(unsigned int millis) {
        HRC::time_point start = HRC::now();
        do {
            // Wait...
        } while (duration_cast<milliseconds>(HRC::now() - start).count() < millis);
    }

    void drawBars(const DArray<int>& arr) {
        for (int i = 0; i < maxBarSize; i++) { // Loop through each row
            for (int j = 0; j < arr.size(); j++) { // Loop through each column
                if (arr.at(j) >= i + 1) {
                    cout << "x";
                } else {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
}

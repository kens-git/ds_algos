#pragma once

#include "DArray.hpp"

namespace Utilities {
  const unsigned int maxBarSize = 20;
  
  void drawBars(const DArray<int>& arr);

  void delayMS(unsigned int millis);
}

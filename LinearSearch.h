#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include <vector>

int recursiveLinearS(const std::vector<int>& vec, int target, int index) {
    if (index < 0) return -1;  // Target not found
    if (vec[index] == target) return index;  // Found the last occurrence
    return recursiveLinearS(vec, target, index - 1);
}

#endif

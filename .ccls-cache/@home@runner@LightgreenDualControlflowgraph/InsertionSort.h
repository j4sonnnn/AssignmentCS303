#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <vector>
#include "Queue.h"

void insertionSortQ(Queue<int>& queue) {
    std::vector<int> tempVector;

    // Transfer elements from the queue to the vector
    while (!queue.empty()) {
        tempVector.push_back(queue.front());
        queue.pop();
    }

    // Perform insertion sort on the vector
    for (size_t i = 1; i < tempVector.size(); ++i) {
        int key = tempVector[i];
        int j = i - 1;

        while (j >= 0 && tempVector[j] > key) {
            tempVector[j + 1] = tempVector[j];
            j--;
        }
        tempVector[j + 1] = key;
    }

    // Transfer sorted elements back to the queue
    for (int value : tempVector) {
        queue.push(value);
    }
}

#endif

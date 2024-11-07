#include <iostream>
#include <vector>
#include "Queue.h"
#include "LinearSearch.h"
#include "InsertionSort.h"

int main() {
    //  Instantiate queue and push 10 values
    Queue<int> queue;
    for (int i = 1; i <= 10; ++i) {
        queue.push(i);
    }

    //  Display elements after pushing 10 values
    std::cout << "Queue elements after pushing 10 values: ";
    queue.display();

    //  Move the front element to the rear and display the result
    queue.move_to_rear();
    std::cout << "Queue after move_to_rear: ";
    queue.display();

    //  Use recursive linear search on a vector to find the last occurrence of a target
    std::vector<int> vec = {1, 2, 3, 4, 2, 5, 2, 6, 8};
    int target = 2;
    int lastIndex = recursiveLinearS(vec, target, vec.size() - 1);

    std::cout << "Last occurrence of " << target << " is at index " << lastIndex << std::endl;

    //  Sort the queue using insertion sort
    Queue<int> unsortedQueue;
    unsortedQueue.push(3);
    unsortedQueue.push(1);
    unsortedQueue.push(4);
    unsortedQueue.push(1);
    unsortedQueue.push(5);

    std::cout << "Unsorted Queue: ";
    unsortedQueue.display();

    insertionSortQ(unsortedQueue);
    std::cout << "Sorted Queue: ";
    unsortedQueue.display();

    return 0;
}

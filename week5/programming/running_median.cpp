#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> maxHeap;

priority_queue<int, vector<int>, greater<int>> minHeap;

void insert(int num) {
    if (maxHeap.empty() || num <= maxHeap.top()) {
        maxHeap.push(num);
    } else {
        minHeap.push(num);
    }

    if (maxHeap.size() > minHeap.size() + 1) {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    else if (minHeap.size() > maxHeap.size() + 1) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
}

float getMedian() {
    if (maxHeap.size() == minHeap.size()) {
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }

    if (maxHeap.size() > minHeap.size()) {
        return maxHeap.top();
    }

    return minHeap.top();
}

int main() {
    insert(5);
    insert(2);
    insert(10);
    insert(4);
    insert(3);

    
    cout << "Median: " << getMedian() << endl;

    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

class RunningMedian {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
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
            return (maxHeap.top() + minHeap.top()) / 2.0f;
        }

        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }

        return minHeap.top();
    }
};

int main() {
    RunningMedian median;

    median.insert(5);
    cout << median.getMedian() << endl; 

    median.insert(2);
    cout << median.getMedian() << endl; 

    median.insert(10);
    cout << median.getMedian() << endl; 
    median.insert(4);
    cout << median.getMedian() << endl; 

    median.insert(3);
    cout << median.getMedian() << endl; 

    return 0;
}
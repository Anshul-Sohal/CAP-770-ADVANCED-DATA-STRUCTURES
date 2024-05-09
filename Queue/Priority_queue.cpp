#include <iostream>
#include <queue>
using namespace std;
int main() {
    priority_queue<int> pq;
    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);
    cout << "Elements in the priority queue:" << endl;
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    priority_queue<int, vector<int>, greater<int>> pq_min;
    pq_min.push(30);
    pq_min.push(10);
    pq_min.push(50);
    pq_min.push(20);
    cout << "Elements in the min priority queue:" << endl;
    while (!pq_min.empty()) {
        cout << pq_min.top() << " ";
        pq_min.pop();
    }
    cout << endl;
    return 0;
}

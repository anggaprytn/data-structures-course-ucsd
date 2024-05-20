#include <iostream>
#include <vector>
#include <deque>

using std::cin;
using std::cout;
using std::vector;
using std::deque;

void max_sliding_window(vector<int> const & A, int w) {
    deque<int> deq;
    for (int i = 0; i < A.size(); ++i) {
        // Remove elements not within the sliding window
        if (!deq.empty() && deq.front() == i - w) {
            deq.pop_front();
        }
        
        // Remove elements smaller than the current element
        while (!deq.empty() && A[deq.back()] <= A[i]) {
            deq.pop_back();
        }
        
        // Add the current element at the back of the deque
        deq.push_back(i);
        
        // The front of the deque is the largest element in the current window
        if (i >= w - 1) {
            cout << A[deq.front()] << " ";
        }
    }
}

int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window(A, w);

    return 0;
}

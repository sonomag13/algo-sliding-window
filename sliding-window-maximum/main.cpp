// 239. Sliding Window Maximum
// Hard

#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> maxima;
    multiset<int> windows;

    for (int i = 0; i < nums.size(); ++i) {
        windows.insert(nums[i]);

        if (i + 1 >= k) {
            /**
             * - we do not need to compute the maximum when i + 1 < k since a window with the size of k has not formed
             * - the end of window (which is a multiset) is the maximum
             * - once we've got the maximum, we need to pop the value on the left boundary, i.e. arr[i + 1 - k]. In the
             *   next iteration, we insert a new element into the window, and the size of window is just k.
             * - Since it is multi-set, we cannot directly pop arr[i + 1 - k] since we just want to pop one and keep the
             *   rest. In these case, we need to call a function called equal_range().
             */

            maxima.push_back(*windows.rbegin());  // use rbegin = the last element in the window, i.e. the maximum
            pair<multiset<int>::iterator, multiset<int>::iterator> range = windows.equal_range(nums[i + 1 - k]);
            windows.erase(range.first);
        }
    }

    return maxima;
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> maxima = maxSlidingWindow(arr, k);

    return 0;
}

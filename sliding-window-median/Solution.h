#include <set>
#include <vector>

using namespace std; 

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        
        vector<double> medians; 

        if (k == 0) {
            return medians; 
        }

        // initislize the multiset with the range of [nums.begin(), nums.begin() + k)
        multiset<int> window(nums.begin(), nums.begin() + k);

        // mid points to the left median if k is even; and median for odd k; 
        multiset<int>::iterator mid = next(window.begin(), (k - 1) / 2); 

        int size = nums.size();

        for (int i = k; i <= size; ++i) {
            /**
             * oddly enough i <= size(); when i == nums.size(), the window covers 
             * the indices [size - 1 - k, size - 1]
             */
            // int midVal = *mid; 

            if (k % 2 == 0) {
                medians.push_back((static_cast<double>(*mid) + static_cast<double>(*next(mid, 1))) / 2.0);
            }
            else {
                medians.push_back(static_cast<double>(*mid)); 
            }

            if (i == size) {
                break;  // there is no more values to add into the window
            }

            // we need to handle the effect of inserting and deleting an element on mid pointer
            int val = nums[i]; 
            window.insert(val);

            if (val < *mid) {
                --mid; 
            }

            int valToRemove = nums[i - k]; 
            if (valToRemove <= *mid) {
                ++mid; 
            }

            window.erase(window.equal_range(valToRemove).first); 
        }

        return medians; 
    }
};
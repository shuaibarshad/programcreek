#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//
// Rotate an array of n elements to the right by k steps.
//
// For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] 
// is rotated to [5,6,7,1,2,3,4]. How many different ways do you 
// know to solve this problem?
//

// We can create a new array and then copy elements to the new array
void rotate_array(std::vector<int>& nums, int k)
{
    // adjust k so that it is smaller than array size
    int n = nums.size();
    k %= n;

    std::vector<int> buf;
    for (int i = 0; i < nums.size(); ++i) {
        int si = (i+n-k) % n;
        buf.push_back(nums[si]);
    }

    //for (int i = 0; i < k; ++i) {
    //    buf.push_back(nums[n-k+i]);
    //}
    //for (int i = k; i < n; ++i) {
    //    buf.push_back(nums[i-k]);
    //}

    for (int i = 0; i < n; ++i) {
        nums[i] = buf[i];
    }
}


template<class T>
void print(const std::vector<T>& v)
{
    for (int i = 0; i < v.size(); ++i) {
        if (i > 0)
            std::cout << ", ";
        std::cout << v[i];
    }
    std::cout << "\n";
}


int main(int argc, char* argv[])
{
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    print(nums);
    rotate_array(nums, 3);
    print(nums);

    return 0;
}


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

template<class T>
void print(const std::vector<T>& v)
{
    for (int i = 0; i < v.size(); ++i) {
        if (i > 0) {
            std::cout << ", ";
        }
        std::cout << v[i];
    }
    std::cout << "\n";
}


// This solution is like a bubble sort
void rotate(std::vector<int>& nums, int k)
{
	k = k % nums.size();
	for (int i = 0; i < k; ++i) {
	    for (int j = nums.size()-1; j > 0; --j) {
            std::swap(nums[j-1], nums[j]);
        }
    }
}


int main(int argc, char* argv[])
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    print(v);
    rotate(v, 3);
    print(v);

    return 0;
}


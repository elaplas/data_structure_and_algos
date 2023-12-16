#include <iostream>
#include <vector>

using namespace std;

/***
 * Problem: given an array and its median, rearrange the array in a way that the elements 
 * smaller than median (first partition) appear before those elements that are equal to the median 
 * (second partition), and the elements equal to the median come after those elements that are bigger
 * than the median. 
 * 
 * Solution: (three pointer technique + swapping technique)
 * 
 * 1- Define three pointers i, j, k and assume that the elements smaller than median 
 * locate in the range [0, i), and the elements equal to the median locate in the
 * range [i, j), and finally the elements bigger than the median locate in the range
 * (k, len(arr)]. The elements in the range [0, j] are not sorted yet. 
 * 
 * 2- Try to come up with a logic to put each element in its corresponding range
 * 
*/

void swap(int& x, int& y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

void threeWayPartitioning(vector<int>& nums, int mid) {

    int i=0;
    int j=0;
    int k = nums.size()-1;
    while (j < k)
    {
        if (nums[j] < mid)
        {
            swap(nums[i], nums[j]);
            ++i;
            // j is incremented since we know that either i and j are 
            // pointing to the same element or j is ahead of i because 
            // elements equal to the median are already encountered. Therefore, in 
            // both cases we dont need to recheck the already swapped element in the 
            // next iteration
            ++j; 
        }
        else if(nums[j] > mid)
        {
            swap(nums[j], nums[k]);
            --k;
            // we need to recheck the already swapped element in j position
            // because we move only in the forward direction 
        }
        else
        {
            // If equal to the median
            ++j;
        }
    }
 }

 int main()
 {
    vector<int> nums = {1,5,3,2,3,1,8};
    threeWayPartitioning(nums, 3);
    for ( auto el: nums){
        cout<<el<<"\n";
    }
    return 0;
 }
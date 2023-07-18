// half part will be always sorted in rotated sorted array
// to decide which half is sorted compare first element with mid element
// after this decide the region of existence of target and apply binary search
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &nums, int s, int e, int x)
{
    if (s > e)
        return -1;
    int m = s + (e - s) / 2;
    if (nums[m] == x)
        return m;
    if (nums[s] <= nums[m])          // to decide which half is sorted compare first element with mid element
    {
        if (nums[s] <= x && x < nums[m])   // after this decide the region of existence of target and apply binary search
            return solve(nums, s, m - 1, x);
        else
            return solve(nums, m + 1, e, x);
    }
    else
    {
        if (nums[e] >= x && x > nums[m])
            return solve(nums, m + 1, e, x);
        else
            return solve(nums, s, m - 1, x);
    }
}
int search(vector<int> &nums, int target)
{
    int n = nums.size();
    return solve(nums, 0, n - 1, target);
}
int main()
{
    vector<int>nums = {4,5,6,7,0,1,2};
    int x = 0;
    cout<<search(nums,x);
    
}
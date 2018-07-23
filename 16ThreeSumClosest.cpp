#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
    vector<int> arr(nums);
    int len = arr.size();
    if (len < 3)
        return -1;
    sort(arr.begin(), arr.end());
    int closestSum = arr[0] + arr[1] + arr[2];
    if (closestSum >= target)
        return closestSum;
    for (int i = 0; i+2 < len; i++)
    {
        int sum = arr[i] + arr[i+1] + arr[i+2];
        if (sum > target)
        {
            if (abs(sum - target) < abs(closestSum - target))
                closestSum = sum;
                
            return closestSum;
        }

        int left = i+1;
        int right = len-1;
        while (left < right)
        {
            int sum = arr[i] + arr[left] + arr[right];
            if (sum == target)
                return target;
            if (abs(sum - target) < abs(closestSum - target))
                closestSum = sum;
            if (sum < target)
                left++;
            if (sum > target)
                right--;
        }
    }

    return closestSum;
}


int main()
{
    vector<int> nums1{-1, -1, 1, 1, 3};
    cout << threeSumClosest(nums1, 1) << endl;
    return 0;
}

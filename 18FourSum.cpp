#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int len = nums.size();
    vector<vector<int>> ret;
    if (len < 4)
        return ret;

    vector<int> arr(nums);
    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < len-3; i++)
    {
        if (i > 0 && arr[i] == arr[i-1]) continue;
        for (int j = i+1; j < len-2; j++)
        {
            if (j > i+1 && arr[j] == arr[j-1]) continue;
            int l = j+1;
            int r = len - 1;
            while (l < r)
            {
                if (arr[i] + arr[j] + arr[l] + arr[r] == target)
                {
                    vector<int> tmp{arr[i], arr[j], arr[l], arr[r]};
                    ret.push_back(tmp);
                    while (l <= r && arr[l] == arr[l+1]) l++;
                    while (l <= r && arr[r] == arr[r-1]) r--;
                    l++;
                    r--;
                }

                if (arr[i] + arr[j] + arr[l] + arr[r]  < target)
                    l++;
                if (arr[i] + arr[j] + arr[l] + arr[r]  > target)
                    r--;
            }
        }
    }

    return ret;
}

int main()
{
    vector<int> nums{1, 0, -1, 0, 2, -2};
    vector<vector<int>> ret = fourSum(nums, 0);
    for (auto v : ret)
    {
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << endl;
    }
    return 0;
}
                

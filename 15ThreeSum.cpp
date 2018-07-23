#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<int> arr(nums);
    sort(arr.begin(), arr.end());
    int len = arr.size();
    vector<vector<int>> result;
    if (len < 3)
        return result;

    for (int i = 0; i < len; i++)
    {
        if (arr[i] > 0)
            break;

        if (i > 0 && arr[i] == arr[i-1]) continue;

        int residual = -arr[i];

        int l = i+1;
        int r = len-1;
        while (l < r)
        {
            if (arr[l] + arr[r] == residual)
            {
                result.push_back({arr[i], arr[l], arr[r]});
            
                while (l < r && arr[l] == arr[l+1]) l++;
                while (l < r && arr[r] == arr[r-1]) r--;
            }

            if (arr[l] + arr[r] < residual)
                l++;               
             else
                r--;
        }
    }

    return result;
}

int main()
{
    vector<int> nums1{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = threeSum(nums1);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }

    return 0;
}    

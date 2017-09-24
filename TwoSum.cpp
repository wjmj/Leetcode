#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    vector<int> twoSum (vector<int>& nums, int target){
        int count = nums.size();
        for (int i = 0;i < count; i++){
            for (int j = i+1; j < count;j++){
                if (nums[i] + nums[j] == target) {
                    vector<int> res;
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
    }
};
int main()
{
    Solution m;
    int n[] = {2, 7, 11, 15};
    vector<int> nums(n, n+4);
    int target = 9;
    vector<int> res = m.twoSum(nums, target);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
    return 0;
}


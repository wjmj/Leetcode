#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        const int MAX = 10;
        int nums[MAX];
        for (int i = 0;i < MAX;i++)
            nums[i] = 0;

        bool flag = x >= 0 ? true : false;
        int mx = x >= 0 ? x : -x;
        int k = 0;
        while (mx)
        {
            nums[k++] = mx%10;
            mx /= 10;
        }

        long long t = 0;
        for (int i = 0; i < k; i++)
        {
            t = 10 * t + nums[i];
        }

        if (t > INT_MAX || t < INT_MIN)
            return 0;

        else
            return flag ? t : -t;


    }
};

int main()
{
    Solution m;

    cout << m.reverse(123) << endl;

    cout << m.reverse(-123) << endl;

    cout << m.reverse(100) << endl;

    cout << m.reverse(10) << endl;
    return 0;
}


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        bool even = ((len1+len2)%2 == 0);
        int i = 0;
        int j = 0;
        int k = 0;
        int m = (len1+len2+1)/2;
        int a = 0, b = 0;
        bool flag;
        while (i < len1 && j < len2 && k < m)
        {
            if (nums1[i] > nums2[j])
            {
                    flag = false;
                    j++;
            }
            else
            {
                flag = true;
                i++;
            }
            k++;
        }

        if (k == m)
        {
            if (flag)
            {
                a = nums1[i-1];
            }
            else
                a = nums2[j-1];
        }
        else if (i < len1)
        {
            i += m-k-1;
            a = nums1[i];
            i++;
        }
        else
        {
            j += m-k-1;
            a = nums2[j];
            j++;
        }


        if (even)
        {
            if (i < len1 && j < len2)
            {
                b = nums1[i] < nums2[j] ? nums1[i] : nums2[j];
            }
            else if (i < len1)
            {
                b = nums1[i];
            }
            else
                b = nums2[j];
        }

        if (even) return (a+b)/2.0;
        return a*1.0;
    }
};

int main()
{
    Solution m;
    int n1[] = {1,3};
    int n2[] = {2};
    vector<int> nums1(n1, n1+2);
    vector<int> nums2(n2, n2+1);
    cout << m.findMedianSortedArrays(nums1, nums2) << endl;

    int n3[] = {1,2};
    int n4[] = {3,4};
    vector<int> nums3(n3, n3+2);
    vector<int> nums4(n4, n4+2);
    cout << m.findMedianSortedArrays(nums3, nums4) << endl;

    int n6[] = {2,3};
    vector<int> nums5;
    vector<int> nums6(n6, n6+2);
    cout << m.findMedianSortedArrays(nums5, nums6) << endl;

    return 0;
}


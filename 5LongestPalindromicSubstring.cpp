#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len == 1)
            return s;

        bool flag[1000][1000] = {false};

        int k = 0;
        while (k < len)
        {
            for (int i = 0; (i < len) && ((i+k) < len); i++)
            {
                if (k == 0)
                    flag[i][i+k] = true;
                else if (k == 1)
                {
                    if (s[i] == s[i+k])
                        flag[i][i+k] = true;
                    else
                        flag[i][i+k] = false;
                }
                else if (s[i] != s[i+k])
                    flag[i][i+k] = false;
                else
                    flag[i][i+k] = flag[i+1][i+k-1];
            }
            k++;
        }

        int j = len-1;
        while (j > -1)
        {
            for (int i = 0; (i < len) && ((i+j)<len); i++)
            {
                if (flag[i][i+j])
                    return s.substr(i, j+1);
            }
            j--;
        }
    }

};

int main()
{

    Solution m;

    string s1("babad");
    cout << m.longestPalindrome(s1) << endl;

    string s2("cbbd");
    cout << m.longestPalindrome(s2)  << endl;

    string s3("babaddtattarrattatddetartrateedredividerb");
    cout << m.longestPalindrome(s3) << endl;

    return 0;
}


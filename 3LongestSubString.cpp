#include <iostream>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "")return 0;
        int length = 0;

        int m = 0;
        int sbegin = 0;
        int flag = 0;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = sbegin; j < i; j++)
            {
                if (s[j] == s[i])
                {
                    if (m > length)
                        length = m;
                    sbegin = j + 1;
                    m = i - sbegin + 1;
                    flag = 1;
                    break;
                }
            }
            if (flag)
            {
                flag = 0;
                continue;
            }
            m++;
        }
        if (m > length) length = m;
        return length;
    }
};
int main()
{
    Solution m;
    string str1("dvdf");
    cout << m.lengthOfLongestSubstring(str1) << endl;
    string str2("a");
    cout << m.lengthOfLongestSubstring(str2)<<endl;
    string str3("");
    cout << m.lengthOfLongestSubstring(str3)<<endl;
    string str4("abcabcbb");
    cout << m.lengthOfLongestSubstring(str4)<<endl;
    string str5("bbbbb");
    cout << m.lengthOfLongestSubstring(str5)<<endl;
    string str6("pwwkew");
    cout << m.lengthOfLongestSubstring(str6)<<endl;
    string str7("au");
    cout << m.lengthOfLongestSubstring(str7)<<endl;
    return 0;
}


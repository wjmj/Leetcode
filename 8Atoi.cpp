#include <iostream>
#include <string>
#include <cctype>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        string s = str;
        s.erase(0, s.find_first_not_of(" "));
        if (s.compare("") == 0)
            return 0;
        bool flag = true;
        switch (s[0])
        {
        case '+':
        case '-':
            if (s[0] == '-')
                flag = false;
            if (s.length() < 2)
                return 0;
            if (!isdigit(s[1]))
                return 0;
            s = s.substr(1);
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            break;
        default:
            return 0;
        }
        long long res = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (!isdigit(s[i]))
                break;
            res = res * 10 + s[i] - '0';
            if (res > INT_MAX && flag)
                return INT_MAX;
            if (res > INT_MAX && !flag)
                return INT_MIN;

        }
        if (!flag)
            res = -res;
        if (res > INT_MAX)
            return INT_MAX;
        if (res < INT_MIN)
            return INT_MIN;
        return res;
    }
};

int main()
{
    Solution m;

    cout << m.myAtoi("") << endl;
    cout << m.myAtoi("  ") << endl;
    cout << m.myAtoi("+123") << endl;
    cout << m.myAtoi("-123") << endl;
    cout << m.myAtoi("as123") << endl;
    cout << m.myAtoi("-123as") << endl;
    cout << m.myAtoi("  +123dd") << endl;
    cout << m.myAtoi("2222222222") << endl;
    cout << m.myAtoi("-2345678901") << endl;
    cout << m.myAtoi("9223372036854775809") << endl;
    return 0;
}


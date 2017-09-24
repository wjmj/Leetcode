#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int mx = x, ml = len(x);
        while (true)
        {
            if (ml == 1)
                return true;
            if (first_digit(mx) != mx%10)
                return false;

            int factor = 1;
            for (int i = 0; i < ml-1; i++)
                factor *= 10;
            mx = mx%factor;
            mx /= 10;
            ml -= 2;
            if (ml == 0 || mx == 0)
                return true;
            int t = len(mx);
            if (ml > t)
            {

                for (int i = 0; i < (ml-t); i++)
                {
                    if (mx % 10 != 0)
                        return false;
                    mx /= 10;
                }
                ml = len(mx);
            }
        }
    }

private:
    int len(int x)
    {
        if (x == 0)
            return 1;

        int mx = x;
        int len = 0;
        while (mx)
        {
            mx = mx/10;
            len++;
        }
        return len;
    }
    int first_digit(int x)
    {
        int mx = x;
        while (mx > 9)
            mx /= 10;

        return mx;
    }

};

int main()
{
    Solution m;

    cout << std::boolalpha << m.isPalindrome(-123) << endl;
    cout << m.isPalindrome(-121) << endl;
    cout << m.isPalindrome(121) <<endl;
    cout << m.isPalindrome(0) <<endl;
    cout << m.isPalindrome(1) << endl;
    cout << m.isPalindrome(1234) << endl;
    cout << m.isPalindrome(110) << endl;
    cout << m.isPalindrome(11) << endl;
    cout << m.isPalindrome(1000021) << endl;
    cout << m.isPalindrome(1001) << endl;
    cout << m.isPalindrome(9999) << endl;
    cout << m.isPalindrome(1000110001) << endl;
    return 0;
}


#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (s.length() == 0 || s.length() < numRows || numRows == 1)
            return s;

        int i = 0, j = 0, k = 0;
        int len = s.length();

        string res("");

        char **str = new char*[numRows];
        for (int row = 0; row < numRows; row++)
        {
            str[row] = new char[len];
        }

        for (int row = 0; row < numRows; row++)
        {
            for (int col = 0; col < len; col++)
                str[row][col] = '\0';
        }

        while (k < len)
        {
            for (; (i < numRows) && (k < len); i++)
            {
                str[i][j] = s[k];
                k++;
            }
            j++;
            i = numRows - 2;
            for (; (i > 0) && (k < len); i--)
            {
                str[i][j] = s[k];
                j++;
                k++;
            }
        }


        for (int row = 0; row < numRows; row++)
        {
            for (int col = 0; col < len; col++)
            {
                if (str[row][col] != '\0')
                    res += str[row][col];
            }
        }

        return res;

    }
};

int main()
{
    Solution m;

    string s1("PAYPALISHIRING");
    cout << m.convert(s1, 3) << endl;

    cout << m.convert(s1, 1) << endl;

    cout << m.convert(s1, 2) << endl;

    string s2("");
    cout << m.convert(s2, 1) << endl;

    string s3("ab");
    cout << m.convert(s3, 3) << endl;

    return 0;
}


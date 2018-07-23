#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

void combinations(string &digits, unordered_map<char, string> &dict, string curStr, int k, vector<string> &result)
{
    string str = dict[digits[k]];
    int len = str.size();
    if (k == digits.size() - 1)
    {
        for (int i = 0; i < len; i++)
        {
            result.push_back(curStr + str[i]);
        }

        return;
    }

    for (int i = 0; i < len; i++)
        combinations(digits, dict, curStr+str[i], k+1, result);
}  

vector<string> letterCombinations(string digits)
{
    unordered_map<char, string> dict{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    string curStr;
    vector<string> result;

    combinations(digits, dict, curStr, 0, result);

    return result;
}

int main()
{
    string str1("23");
    vector<string> res1 = letterCombinations(str1);
    for (int i = 0; i < res1.size(); i++)
        cout << res1[i] << endl;

    return 0;
}

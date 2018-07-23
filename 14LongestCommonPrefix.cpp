#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    int strNum = strs.size();
    if (strNum <= 1)
        return string("");

    int minLen = strs[0].size();
    for (int i = 1; i < strNum; i++)
        if (strs[i].size() < minLen)
            minLen = strs[i].size();

    int end = 0;
    for (int i = 0; i < minLen; i++)
    {
        char ch = strs[0][i];
        for (int j = 1; j < strNum; j++)
            if (strs[j][i] != ch)
                return strs[0].substr(0, end);
        end++;
    }

    return strs[0].substr(0, minLen);
}

static void test(const char* testName, vector<string> &strs, string expected)
{
    cout << testName << " begins: ";
    string result = longestCommonPrefix(strs);
    if (result == expected)
        cout << "passed" << endl;
    else
        cout << "failed" << endl;
}

static void test1()
{
    vector<string> strs{"flower", "flow", "flight"};
    string result("fl");
    test("test1", strs, result);
}

static void test2()
{
    vector<string> strs{"dog", "racecar", "car"};
    string result("");
    test("test2", strs, result);
}

int main()
{
    test1();
    test2();
 
    return 0;
}

#include <iostream>
#include <unordered_map>

using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> words{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int len = s.size();
    int result = 0;
    for (int i = 0; i < len; ++i)
    {
        if (i < len-1 && words[s[i]] < words[s[i+1]])
            result -= words[s[i]];
        else
            result += words[s[i]];
    }

    return result;    
}

static void test(const char* testName, string s, int expected)
{
    cout << testName << " begins: ";
    int result = romanToInt(s);
    if (result == expected)
        cout << "passed" << endl;
    else
        cout << "failed" << endl;
}

static void test1()
{
    string s("III");
    int expected = 3;
    test("test1", s, expected);
}

static void test2()
{
    string s("IV");
    test("test2", s, 4);
}

static void test3()
{
    string s("IX");
    test("test3", s, 9);
}

static void test4()
{
    string s("LVIII");
    test("test4", s, 58);
}

static void test5()
{
    string s("MCMXCIV");
    test("test5", s, 1994);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}

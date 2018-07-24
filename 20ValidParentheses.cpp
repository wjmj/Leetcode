#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s)
{
    if (s.empty())
        return true;

    stack<char> st;
    for (char c : s)
    {
        switch (c)
        {
            case '(':
            case '[':
            case '{':
                st.push(c);
                break;
            case ')':
                if (st.empty() ||  st.top() != '(')
                    return false;
                st.pop();
                break;
            case ']':
                if (st.empty() || st.top() != '[')
                    return false;
                st.pop();
                break;
            case '}':
                if (st.empty() || st.top() != '{')
                    return false;
                st.pop();
                break;
            default:
                return false;
        }
    }

    if (st.empty())
        return true;

    return false;
}

static void test(const char *testName, string s, bool expected)
{
    cout << testName << " begins: ";
    bool result = isValid(s);
    if (result == expected)
        cout << "passed" << endl;
    else
        cout << "failed" << endl;
}

static void test1()
{
    string s("()");
    bool expected = true;
    test("test1", s, expected);
}

static void test2()
{
    string s("()[]{}");
    test("test2", s, true);
}

static void test3()
{
    string s("(]");
    test("test3", s, false);
}

static void test4()
{
    string s("([)]");
    test("test4", s, false);
}

static void test5()
{
    string s("{[]}");
    test("test5", s, true);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
}

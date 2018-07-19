#include <iostream>
#include <string>

using namespace std;

string intToRoman(int num)
{
    string words = "IVXLCDM";
    int k = 0;
    string result;
    while (num)
    {
        int x = num % 10;
        switch (x)
        {
            case 1:
                result = words[k] + result;
                break;
            case 2:
                result = words[k] + (words[k] + result);
                break;
            case 3:
                result = words[k] + (words[k] + (words[k] + result));
                break;
            case 4:
                result = words[k] + (words[k+1] + result);
                break;
            case 5:
                result = words[k+1] + result;
                break;
            case 6:
                result = words[k+1] + (words[k] + result);
                break;
            case 7:
                result = words[k+1] + (words[k] + (words[k] + result));
                break;
            case 8:
                result = words[k+1] + (words[k] + (words[k] + (words[k] + result)));
                break;
            case 9:
                result = words[k] + (words[k+2] + result);
                break;
            default:
                break;
        }

        num /= 10;
        k += 2;

    }

    return result;
}

static void test(const char *testName, int num, string expected)
{
    cout << testName << " begins: ";
    string result = intToRoman(num);
    if (result == expected)
        cout << "passed." << endl;
    else
        cout << "failed" << endl;
}

static void test1()
{
    int num = 3;
    string expected("III");
    test("test1", num, expected);
}

static void test2()
{
    int num = 4;
    string expected("IV");
    test("test2", num, expected);
}

static void test3()
{
    int num = 9;
    string expected("IX");
    test("test3", num, expected);
}

static void test4()
{
    int num = 58;
    string expected("LVIII");
    test("test4", num, expected);
}

static void test5()
{
    int num = 1994;
    string expected("MCMXCIV");
    test("test5", num, expected);
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

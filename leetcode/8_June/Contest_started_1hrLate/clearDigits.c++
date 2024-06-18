#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
string clearDigits(string s)
{
    string res = "";
    for (size_t i = 0; i < s.size(); i++)
    {
        if (!isdigit(s[i]))
        {
            res += s[i];
        }

        else
        {
            res.pop_back();
        }
    }
    return res;
}
string ClearDigits(std::string s) {
        while (true) {
            size_t digitPos = s.find_first_of("0123456789");
            if (digitPos == std::string::npos) break;

            size_t nonDigitPos = std::string::npos;
            for (size_t i = digitPos; i-- > 0; ) {
                if (!std::isdigit(s[i])) {
                    nonDigitPos = i;
                    break;
                }
            }

            if (nonDigitPos != std::string::npos) {
                s.erase(nonDigitPos, 1);
                s.erase(digitPos - 1, 1);
            } else {
                s.erase(digitPos, 1);
            }
        }

        return s;
    }


int main()
{
    string s = "ab3";
    cout << ClearDigits(s);

    return 0;
}
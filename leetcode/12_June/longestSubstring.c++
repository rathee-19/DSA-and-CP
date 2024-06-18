#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
int lengthOfLongestSubstring(string s)
{
    int count = 0;
    int ans = 0;
    int hash[256] = {0};

    for (int i = 0; i < s.size(); i++)
    {

        if (hash[s[i]] == 00)
        {

            count++;

            ans = max(count, ans);
            
        }
        else
        {
            ans = max(count, ans);

            while (s[i] != s[i - count])
            {
                hash[s[i - count]]--;
                count--;
            }
        }
        hash[s[i]]++;
    }

    return ans;
}
int main()
{
    string s = "dvdf";
    int ans = lengthOfLongestSubstring(s);
    cout << ans << endl;
    return 0;
}
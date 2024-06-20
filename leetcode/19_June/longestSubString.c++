#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int count = 0;
    int ans = 0;
    int hash [256];
     fill(begin(hash), end(hash), -1); // Initialize all elements to -1
    
    int start =0;
    for (int i = 0; i < s.size(); i++) {

        if (hash[s[i]] >start) {
            start = hash[s[i]] +1;
           
        }
        
        hash[s[i]] = i;
            cout << hash[s[i]] << " " << start << " " <<i << endl;
        ans = max(ans, i - start + 1);
    }

    return ans;
}
int main(){
    string s = "abba";
    int ans = lengthOfLongestSubstring(s);
    cout << ans << endl;

    return 0;
}
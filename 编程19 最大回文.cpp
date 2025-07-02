#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

string longestPalindrome(string s) {
    int n = s.length();
    if (n == 0) return "";

    vector<vector<bool> > dp(n, vector<bool>(n, false));
    int start = 0, maxLength = 1;

    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; ++i)
        dp[i][i] = true;

    // Check for substring of length 2
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    // Check for lengths greater than 2
    for (int length = 3; length <= n; ++length) {
        for (int i = 0; i < n - length + 1; ++i) {
            int j = i + length - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                if (length > maxLength) {
                    start = i;
                    maxLength = length;
                }
            }
        }
    }

    return s.substr(start, maxLength);
}

int main() {
    string s;
    cin >> s;
    cout << longestPalindrome(s) << endl;
    return 0;
}

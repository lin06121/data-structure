#include <iostream>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int maxLength = 0;
    int left = 0;
    
    for (int right = 0; right < s.length(); right++) {
        for (int k = left; k < right; k++) {
            if (s[k] == s[right]) {
                left = k + 1; // Move the left boundary
                break;
            }
        }
        maxLength = max(maxLength, right - left + 1); // Update max length
    }
    
    return maxLength;
}

int main() {
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}


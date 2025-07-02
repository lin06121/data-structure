#include <iostream>
#include <string>
using namespace std;

int Count_substring(string t, string p) {
    // Convert all characters in t to lowercase
    for(int i = 0; i < t.length(); i++) {
        if('A' <= t[i] && t[i] <= 'Z') 
            t[i] = char(t[i] - 'A' + 'a');
    }

    int n = p.length();
    int count1 = 0;

    // Search for the substring p in t
    for(int i = 0; i <= t.length() - n; i++) {
        bool flag = true;

        for(int j = 0; j < n; j++) {
            if(t[i + j] != p[j]) {
                flag = false;
                break;
            }
        }

        if(flag) 
            count1++;
    }

    return count1;
}

int main() {
    string t, p;
    getline(cin, t);
    getline(cin, p);
    cout << Count_substring(t, p) << endl;
    return 0;
}

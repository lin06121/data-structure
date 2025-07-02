#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
bool compare(const string &s1, const string &s2) {
    return s1 > s2;  
}

int main() {
    int n;
    cin >> n;  

    
    vector<string> strings(n);

    
    cin.ignore();  
    for (int i = 0; i < n; i++) {
        getline(cin, strings[i]);  
    }

    char ch;
    cin >> ch;  
    
    for (int i = 0; i < n; i++) {
        string new_str = "";
        for (int j=0;j<strings[i].size();j++) {
            if (strings[i][j] != ch) {  
                new_str += strings[i][j];
            }
        }
        strings[i] = new_str;  
    }

    
    for (int l = 0; l < n; ++l) {
        int r = l;
        
        for (int k = l + 1; k < n; ++k) {
            if (compare(strings[k], strings[r])) { 
                r = k;  
            }
        }

        
        if (r != l) {
            swap(strings[l], strings[r]);
        }
    }

    
    for (int i = 0; i < n; i++) {
        cout << strings[i] << endl;
    }

    return 0;
}




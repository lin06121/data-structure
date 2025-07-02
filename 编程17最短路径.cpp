#include <iostream>
#include <algorithm>
using namespace std;

int bestroud(int a[100][100], int i, int j);

int main() {
    int n;
    cin >> n;
    int a[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> a[i][j];
        }
    }

    int maxVal = 0;
    for (int j = 0; j < n; j++) {
        int road = bestroud(a, n-1, j);
        if (road > maxVal) {
            maxVal = road;
        }
    }

    cout << maxVal << endl;

    return 0;
}

int bestroud(int a[100][100], int i, int j) {
    if (i == 0) {
        return a[i][j];
    } else if (j == 0) {
        return a[i][j] + bestroud(a, i - 1, j);
    } else if (j == i) {
        return a[i][j] + bestroud(a, i - 1, j - 1);
    } else {
        return a[i][j] + max(bestroud(a, i - 1, j), bestroud(a, i - 1, j - 1));
    }
}

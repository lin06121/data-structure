
#include <iostream>
#include <cstring>

void qsort(void *a[], int l, int r, bool(*comp)(void*, void*)) {
    void* p;
    int i = l, j = r;
    void* mid = a[(l + r) / 2];
    do {
        while (comp(a[i], mid)) i++;
        while (comp(mid, a[j])) j--;
        if (i <= j) {
            p = a[i]; a[i] = a[j]; a[j] = p;
            i++; j--;
        }
    } while (i <= j);
    if (l < j) qsort(a, l, j, comp);
    if (i < r) qsort(a, i, r, comp);
}

bool comp(void *s1, void *s2) {
    return strcmp((char*)s1, (char*)s2) < 0;
}

int main() {
    char *a[] = {"z", "a", "b", "c"};
    qsort((void**)a, 0, 3, comp); // Corrected the range to 0 to 3
    for (int i = 0; i <= 3; i++) { // Corrected the loop condition
        std::cout << a[i] << " ";
    }
    return 0;
}

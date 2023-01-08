#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    unsigned long long n = 0;
    long long temp = 0;
    vector<long long> vec;

    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &temp);
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());

    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &temp);
        if (binary_search(vec.begin(), vec.end(), temp)) { printf("1\n"); }
        else { printf("0\n"); }
    }

    return 0;
}
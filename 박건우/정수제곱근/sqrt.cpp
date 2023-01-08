#include <iostream>

using namespace std;

typedef unsigned long long ULL;

bool checkSqrt(ULL n, ULL sqrtn) {
    if (n <= sqrtn * sqrtn) {
        return true;
    }
    else {
        return false;
    }
}

ULL searchSqrt(ULL n) {
    ULL e = 0;
    ULL s = 0;
    ULL mid = 0;
    ULL ans = 0;

    s = 0;
    e = n / 2;

    while (s <= e) {
        mid = (s + e) / 2;
        if (checkSqrt(n, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }

    return ans;
}

int main() {
    ULL n = 0;
    cin >> n;
    cout << "n: " << n << "\n";
    cout << "sqrt(n): " << searchSqrt(n) << "\n";

    return 0;
}
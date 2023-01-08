#include <iostream>

using namespace std;

long long bSearch(long long x, long long y, long long start, long long end) {
    long long z = y * 100 / x + 1;
    long long ans = 0;

    if (z >= 100) {
        return -1;
    }

    while (start <= end) {
        long long mid = (start + end) / 2;
        long long tmpZ = (y + mid) * 100 / (x + mid);
        if (z <= tmpZ) {
            end = mid - 1;
            ans = mid;
        }
        else { start = mid + 1; }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    long long x, y = 0;
    cin >> x >> y;
    cout << bSearch(x, y, 1, y);

    return 0;
}
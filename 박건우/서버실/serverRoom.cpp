#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ull;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int map[1001][1001];

    ull left = 0, right = 0, sum = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            sum += map[i][j];
            if (map[i][j] > right) { right = map[i][j]; }
        }

    while (left + 1 < right) {
        ull mid = (left + right) / 2;
        ull cnt = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cnt += mid > map[i][j] ? map[i][j] : mid;
            }
        if (((double) cnt / sum) >= 0.5) {
            right = mid;
        }
        else { left = mid; }
    }

    cout << right;
    return 0;
}

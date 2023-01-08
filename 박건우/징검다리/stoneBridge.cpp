#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// int solution(vector<int> stones, int k) {
//     int s = 0;
//     int e = 0;
//     int mid = 0;
//
//     s = 1;
//     e = *max_element(stones.begin(), stones.end());
//
//     while (s != e) {
//         mid = (s + e) / 2;
//         int cnt = 0;
//
//         for (int i=0;i<stones.size();i++) {
//             if (cnt < k) {
//                 if (i <= mid) {
//                     cnt++;
//                 }
//                 else {
//                     cnt = 0;
//                 }
//             }
//         }
//
//         if (cnt >= k) {
//             e = mid;
//         }
//         else if (cnt < k) {
//             s = mid + 1;
//         }
//     }
//
//     return s;
// }

int solution(vector<int> stones, int k) {
    int s = 0;
    int e = 0;
    int mid = 0;

    s = 1;
    e = *max_element(stones.begin(), stones.end());

    while (s != e) {
        mid = (s + e) / 2;
        int cnt = 0;
        int Max = 0;
        for (int i = 0; i < stones.size(); i++) {
            if (stones[i] <= mid) { // if dead stone
                cnt++;
            }
            else {
                Max = max(Max, cnt);
                cnt = 0;
            }
        }
        cnt = max(Max, cnt);

        if (cnt >= k) {
            e = mid;
        }
        else if (cnt < k) {
            s = mid + 1;
        }
    }

    return s;
}

int main() {
    vector<int> arr = {2, 4, 5, 3, 2, 4, 4, 2, 5, 1};
    int k = 3;
    printf("%d", solution(arr, k));
}
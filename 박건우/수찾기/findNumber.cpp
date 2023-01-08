#include <iostream>
#include <vector>

using namespace std;

inline bool bSearch(vector<long long> vec, unsigned long long start, unsigned long long end, long long value) {
    if (start > end) {
        return false;
    }

    unsigned long long mid = (start + end) >> 1;

    if (vec[mid] == value) {
        return true;
    }

    else {
        if (mid < value) {
            return bSearch(vec, mid + 1, end, value);
        }
        else {
            return bSearch(vec, start, mid - 1, value);
        }
    }
}

inline unsigned long long division(std::vector<long long> &vec, unsigned long long start, unsigned long long end) {
    long long pivot = vec[((unsigned long long) ((start + end) >> 1))];
    unsigned long long i = start;
    unsigned long long j = end;

    while (i < j) {
        while (vec[i] < pivot && i <= end)
            i++;
        while (vec[j] > pivot && j >= start)
            j--;
        swap(vec[i], vec[j]);
    }

    return i;
}

inline void quickSort(std::vector<long long> &vec, unsigned long long start, unsigned long long end) {
    if (start < end) {
        unsigned long long pivotIdx = division(vec, start, end);
        quickSort(vec, start, pivotIdx);
        quickSort(vec, pivotIdx + 1, end);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = 0;
    long long temp = 0;
    vector<long long> vector1;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        vector1.push_back(temp);
    }
    quickSort(vector1, 0, vector1.size() - 1);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (bSearch(vector1, 0, vector1.size() - 1, temp)) { cout << "1" << endl; }
        else { cout << "0" << endl; }
    }

    return 0;
}
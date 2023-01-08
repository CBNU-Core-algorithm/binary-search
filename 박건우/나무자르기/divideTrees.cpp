#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
unsigned int bSearch(vector<T> vec, unsigned long long start, unsigned long long end, unsigned long long value)
{
    if (start > end)
    {
        return 0;
    }
    unsigned long long mid = (start + end) / 2;
    // cout << "mid: " << mid << endl;

    unsigned long long answer = 0;
    for (int i : vec)
    {
        if (i > mid)
        {
            answer += i - mid;
            // cout << "answer: " << answer << endl;
        }
    }

    if (answer == value)
    {
        return mid;
    }
    else if (answer < value)
    {
        return bSearch(vec, start, mid - 1, value);
    }
    else
    {
        return bSearch(vec, mid + 1, end, value);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned int n = 0;
    unsigned int m = 0;
    vector<unsigned int> vec;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        unsigned int temp = 0;
        cin >> temp;
        vec.push_back(temp);
    }
    std::sort(vec.begin(), vec.end());

    cout << bSearch(vec, 0, 2000000000, m);

    return 0;
}
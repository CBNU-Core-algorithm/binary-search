//https://algorfati.tistory.com/139
#include <iostream>
#include <vector>
#include <map>

using namespace std;

template <typename T>
map<T,T> getPartialSum(vector<T> vec, int size) {
    map<T, T> sum_map;
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int sum = 0;

            for (int k = 1; k <= i; k++) {
                if (j+k-1 < size) {
                    sum += vec[j + k - 1];
                } else {
                    sum += vec[j + k - 1 - size];
                }
            }

            sum_map[sum] += 1;
        }
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += vec[i];
    }
    sum_map[sum] = 1;

    return sum_map;
}

int main() {
    ios_base::sync_with_stdio (false);
    cin.tie(0);
    cout.tie(0);

    int pizaa = 0;
    int m = 0;
    int n = 0;

    vector<unsigned int> pizzaA;
    vector<unsigned int> pizzaB;

    cin >> pizaa;
    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        unsigned int temp = 0;
        cin >> temp;
        pizzaA.push_back(temp);
    }
    for (int j = 0; j < n; j++) {
        unsigned int temp = 0;
        cin >> temp;
        pizzaB.push_back(temp);
    }

    auto a_sum = getPartialSum(pizzaA, pizzaA.size());
    cout << "A's All Partial Sums: ";
    for(auto n: a_sum) { cout << n.first << " "; }
    cout << endl;
    for(auto n: a_sum) { cout << n.second << " "; }
    cout << endl;
    auto b_sum = getPartialSum(pizzaB, pizzaB.size());
    cout << "B's All Partial Sums: ";
    for(auto n: b_sum) { cout << n.first << " "; }
    cout << endl;
    for(auto n: b_sum) { cout << n.second<< " "; }
    cout << endl;

    unsigned int answer = a_sum[pizaa] + b_sum[pizaa];
    for (unsigned int i = 1; i < pizaa; i++) {
        if (a_sum[i] > 0 && b_sum[pizaa - i] > 0) {
            answer += (a_sum[i] * b_sum[pizaa - i]);
        }
    }
    cout << "answer: " << answer << endl;

    return 0;
}
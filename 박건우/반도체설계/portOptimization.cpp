#include <iostream>
#include <vector>

using namespace std;

int find(vector<int> vec, int start, int end, int portNum) {
    int mid = 0;

    while (start < end) {
        mid = (start + end) / 2;
        if (vec[mid] < portNum) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return start;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    cin >> n;

    vector<int> vec;
    int portNum = 0;
    int idxNum = 0;

    cin >> portNum;
    vec.push_back(portNum);

    int oio = 0;
    for(int i=0;i<n-1;i++) {
        cin >> portNum;

        if (portNum > vec[idxNum]) {
            vec.push_back(portNum);
            idxNum++;
        }
        else {
            vec[find(vec,0,vec.size()-1,portNum)] = portNum;
        }

        cout << "In Vector" << "\n";
        for(int i=0;i<idxNum;i++) { cout << vec[idxNum] << " "; }
        cout << "\n";
    }

    cout << vec.size();

    return 0;
}
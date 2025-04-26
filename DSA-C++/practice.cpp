#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    arr.erase(arr.begin() + 2, arr.end() - 1);
    arr.insert(arr.begin() + 2, 1);
    cout << arr.back();
    for (int num : arr) {
        cout << num << " ";
    }
}
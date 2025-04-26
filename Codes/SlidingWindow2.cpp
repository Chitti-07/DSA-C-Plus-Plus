#include <iostream>
#include <vector>
using namespace std;

//[4, 3, 2, 6, 8, 3, 1, 4, 7 ,9, 6, 5], target = 15
class Solution{
public:
    int SmallestSubArraySum(vector<int> &arr, int target) {
        int SubArrayCount = 9999999;
        int Wstart = 0;
        int sum = 0;
        for (int Wend = 0; Wend < arr.size(); Wend++) {
            sum += arr[Wend];
            while (sum >= target) {
                SubArrayCount = min(SubArrayCount, Wend - Wstart + 1);
                sum -= arr[Wstart];
                Wstart++;
            }
        }
        return SubArrayCount;
    }
};

int main() {
    vector<int> arr = {4, 3, 2, 6, 8, 3, 1, 4, 7 ,9, 6, 5};
    Solution obj;
    cout << obj.SmallestSubArraySum(arr, 15);
}
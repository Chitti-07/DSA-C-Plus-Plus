#include <iostream>
#include <vector>
using namespace std;

//[1, 12, -5, -6, 50, 3], k = 4
class Solution {
public:
    float MaxAvgSubArray(vector<int> &arr, int k) {
        float MaxAvg = 0;
        float CurrAvg = 0;

        int CurrSum = 0;
        int Wstart = 0;

        for (int Wend = 0; Wend < arr.size(); Wend++) {
            CurrSum += arr[Wend];
            if (Wend >= k - 1) {
                CurrAvg = (float)CurrSum/k;
                MaxAvg = max(MaxAvg, CurrAvg);
                CurrSum -= arr[Wend - (k - 1)];
            }
        }
        return MaxAvg;
    }
};

int main() {
    vector<int> arr = {1, 12, -5, -6, 50, 3};
    Solution obj;
    cout << obj.MaxAvgSubArray(arr, 4);
    
}
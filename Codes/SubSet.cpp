// #include <iostream>
// #include <vector>
// using namespace std;



// void subsets(vector<vector<int>> &res, vector<int> &sub, vector<int> nums, int ind) {

//     if (ind == nums.size()) {
//         res.push_back(sub);
//         return;
//     }

//     sub.push_back(nums[ind]);
//     subsets(res, sub, nums, ind+1);
//     sub.pop_back();
//     subsets(res, sub, nums, ind+1);

// }

// vector<vector<int>> subsets(vector<int>& nums) {
//     vector<vector<int>> res;
//     vector<int>sub;
//     subsets(res, sub, nums, 0);
//     return res;
// }

// int main() {
//     vector<int> nums = {1, 2, 3};
//     vector<vector<int>> res = subsets(nums);
//     for (auto var : res) {
//         for (auto elem : var) {
//             cout << elem << " ";
//         }
//         cout << endl;
//     }
// }


// #include <vector>
// #include <cmath>

// std::vector<int> generateBinaryPath(int n) {
//     std::vector<int> result;
//     if (n <= 0) return {0};
    
//     // Start with 0
//     result.push_back(0);
//     result.push_back(1);
    
//     // For n > 1, build the sequence recursively
//     for (int k = 2; k <= n; ++k) {
//         int size = result.size();
//         // Mirror the existing sequence
//         for (int i = size - 1; i >= 0; --i) {
//             result.push_back(result[i] | (1 << (k - 1)));
//         }
//     }
    
//     return result;
// }


// #include <iostream>

// int main() {
//     int n = 3;
//     auto sequence = generateBinaryPath(n);
//     for (int num : sequence) {
//         std::cout << num << " ";
//     }
//     // Possible output: 0 1 3 2 6 7 5 4
//     return 0;
// }

// #include <bits/stdc++.h>
// #include <iostream>
// #include <string>
// using namespace std;

// int main () {
// 	int n;
// 	cin >> n;
// 	vector<string> s(n);
// 	for (int i = 0; i < n; i++) {
// 		cin >> s[i];
// 	}

// 	for (int i = 0; i < n; i++) {
// 		string n = s[i];
// 		if (n.length() > 10) {

// 			int cnt = 0;
// 			for (int i = 1; n[i+2]; i++) {
// 				cnt++
// 			}
// 			n += s[i][0] + to_string(cnt) + s[i][cnt+1];
// 		}
// 		cout << n << endl;
// 	}
// }

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	string s;
	cin >> s;

	if (s[0] >= 'a' && s[0] <= 'z') {
		s[0] = toupper(s[0]);
	}
	cout << s;
    return 0;
}
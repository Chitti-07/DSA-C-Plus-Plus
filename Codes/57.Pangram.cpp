#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        bool checkIfPangram(string sentence) {
            unordered_map<char, int>mp;
            for (char ch : sentence) {
                mp[ch-'a']++;
            }
    
            for (auto &var : mp) {
                if(var.second == 0) {
                    return false;
                }
            }
        }
    };
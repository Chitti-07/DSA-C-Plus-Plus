// You are given a 2D integer array logs where each logs[i] = [birthi, deathi] indicates the birth and 
// death years of the ith person.
// The population of some year x is the number of people alive during that year. The ith person is 
// counted in year x's population if x is in the inclusive range [birthi, deathi - 1]. Note that the person is not counted in the year that they die.

// Return the earliest year with the maximum population.

 

// Example 1:

// Input: logs = [[1993,1999],[2000,2010]]
// Output: 1993
// Explanation: The maximum population is 1, and 1993 is the earliest year with this population.
// Example 2:

// Input: logs = [[1950,1961],[1960,1971],[1970,1981]]
// Output: 1960
// Explanation: 
// The maximum population is 2, and it had happened in years 1960 and 1970.
// The earlier year between them is 1960.


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
    	vector<int> p(101, 0);

    	for (int i = 0; i < logs.size(); i++) {
    		p[logs[i][0]-1950]++;
    		p[logs[i][1]-1950]--;
    	}

    	for (int i = 1; i < 101; i++) {
    		p[i] += p[i-1];
    	}

    	int max = 0;
    	int maxY = 1950;

    	for (int i = 0; i < 101; i++) {
    		if (p[i] > max) {
    			max = p[i];
    			maxY += i;
    		}
    	}


        return maxY;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> logs = {
        {1950,1961},{1960,1971}, {1970,1981}
    };

    int result = sol.maximumPopulation(logs);
    cout << "Maximum population year: " << result << endl;

    return 0;
}


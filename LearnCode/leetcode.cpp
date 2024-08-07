#if 0
#include <iostream>
#include <string>
#include<vector>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int kt = nums.size();
        double maxa = 0;
        for (int i = 0; i < kt - k; i++) {
            double sum = 0;
            for (int j = i; j < i + k; j++) {
                sum += nums[j];
            }
            maxa = max(maxa, sum);
        }

        return maxa / k;
    }
};
int main() {
    Solution sol;
    std::vector<int> nums = { 1, 12, -5, -6, 50, 3 };
    int k = 4;
    std::cout << "Max average of subarray: " << sol.findMaxAverage(nums, k) << std::endl;
    return 0;
}
#endif


#if 0

#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int size = grid.size();
        int rt = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; i < size; j++) {
                int count = 0;
                for (int t = 0; t < size; t++) {
                    if (grid[i][t] == grid[t][j])
                        count++;
                }
                if (count == size) rt++;

            }
        }
        return rt;
    }
};

int main() {

    vector<vector<int>> grid = { {3, 2, 1},{1, 7, 6},{2, 7, 7} };
    Solution solution;
    int result = solution.equalPairs(grid);
    std::cout << "Number of equal pairs: " << result << std::endl;
    return 0;
}

#endif


#if 0 tribonacci
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        vector<int> arr(n);
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 1;
        for (int i = 3; i < n; i++) arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];


        return arr[n - 1] + arr[n - 2] + arr[n - 3];
    }
};
#endif
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

// dp[i][j]
// p - n  = S, p+n = Sum n = Sum - p
// p - (Sum - p) = S
// 2p - Sum = S
// p = Sum + S / 2;
// dp[i][j] : How many ways of sum is j of last i element
int findTargetSumWaysDP(vector<int>& nums, int S) {
    int Sum(0);
    for (const auto& val : nums) {
	Sum += val;
    }
    if (S > Sum) return 0;
    if ((S + Sum) % 2 != 0) return 0;

    int target = (Sum + S) >> 1;
    vector<int> dp(target+1, 0);

    dp.at(0) = 1;
    for (int i = 1 ; i <= nums.size() ; ++i) {
	for (int j = target ; j >= nums.at(i-1) ; --j) {
	    dp.at(j) += dp.at(j - nums.at(i-1));
	}
    }
    return dp.at(target);
}

int main() {
    vector<int> input = {1, 1, 1, 1, 1};
    cout << findTargetSumWaysDP(input, 3) << endl;
    return 0;
}

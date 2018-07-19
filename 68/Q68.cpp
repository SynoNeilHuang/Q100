#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::max;
int deleteAndEarn(vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<int> numRecord(10001, 0);
    int maxValue(0);
    for (const auto& val : nums) {
	maxValue = max(maxValue, val);
	++numRecord[val];
    }

    if (maxValue == 0)
	return 0;
    if (maxValue == 1)
	return 1* numRecord.at(1);

    vector<int> dp(maxValue+1, 0);
    dp.at(0) = 0;
    dp.at(1) = numRecord.at(1);
    dp.at(2) = max(2 * numRecord.at(2), numRecord.at(1));
    for (int i = 3 ; i <= maxValue ; ++i) {
	dp.at(i) = max(i * numRecord.at(i) + dp.at(i-2), (i-1) * numRecord.at(i-1) + dp.at(i-3));
    }
    return dp.at(maxValue);
}

int main() {
    //vector<int> input = {10,8,4,2,1,3,4,8,2,9,10,4,8,5,9,1,5,1,6,8,1,1,6,7,8,9,1,7,6,8,4,5,4,1,5,9,8,6,10,6,4,3,8,4,10,8,8,10,6,4,4,4,9,6,9,10,7,1,5,3,4,4,8,1,1,2,1,4,1,1,4,9,4,7,1,5,1,10,3,5,10,3,10,2,1,10,4,1,1,4,1,2,10,9,7,10,1,2,7,5};
    vector<int> input = {3,3,3,4,2};
    cout << deleteAndEarn(input) << endl;
}

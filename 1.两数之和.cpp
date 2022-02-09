/*
 * @lc app=leetcode.cn id=1 lang=cpp
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int n = 0 ; n < nums.size(); n++){
            if( nums[n] > target) continue;
            for(int i = 0 ; i < nums.size(); i++){
                if( i == n) continue;
                if(nums[n]+nums[i]==target){
                    vector<int> a = {n,i};
                    return a;
                }
            }
        }
    }
};
// @lc code=end


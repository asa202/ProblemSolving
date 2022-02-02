class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int idx1 = 0;
        int idx2 = 0;
        int sum = nums[0];
        int length = INT_MAX;
        while(idx1 < nums.size() && idx2 < nums.size()){
            if(sum < target){
                idx2++;
                if(idx2 < nums.size()) sum+=nums[idx2];
            }else{
                if(idx2-idx1+1 < length){
                    length = idx2-idx1+1;
                }
                sum-=nums[idx1];
                idx1++;
            }
        }
        return length == INT_MAX? 0:length;
    }
};
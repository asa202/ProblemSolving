class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<bool> tracker(nums.size()+1,false);
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++){
            if(tracker[nums[i]]){
                ret.push_back(nums[i]);
            }else{
                tracker[nums[i]] = true;
            }
        }
        return ret;
    }
};
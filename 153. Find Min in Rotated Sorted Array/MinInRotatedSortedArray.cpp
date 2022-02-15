class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()<=2){
            if(nums.size()==1) return nums[0];
            else return nums[0] < nums[1]? nums[0]: nums[1];
        }
        int start = 0;
        int end = nums.size()-1;
        int mid = (start+end)/2;
        if(nums[start]<=nums[end]){
            return nums[start];
        }
        while(start < end){
            if(mid > 0 && mid < nums.size()-1 && nums[mid] < nums[mid-1] && nums[mid+1] > nums[mid]){
                return nums[mid];
            }else if(start == mid && mid == end){
                return nums[mid];
            }else if(nums[mid] > nums[end]){
                start = mid+1;
            }else{
                end = mid-1;
            }
            mid  = (start+end)/2;
        }
        return nums[mid];
    }
};
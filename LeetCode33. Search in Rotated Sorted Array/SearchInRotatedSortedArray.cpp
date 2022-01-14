class Solution {
public:
    //dont know what happened but missed a way optimal solution , we can neglect half depending on the values
    //beacuse all numbers are unique
    int binarySearch(vector<int> & nums, int target, int min,int max){
        int mid = (min+max)/2;
        int start = min;
        int end = max;
        while(start<=end){
            if(nums[mid] == target){
                return mid;
            } 
            else if(nums[mid]>target){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
            mid = (start+end)/2;
        }
        return -1;
    }
    int findZeroIndex(vector<int> &nums, int target){
        //have to find in logn time so use binary to find the peak
        //as it is rotated their is only two possibility
        //1.either it didn't rotate then the first and last element will b in increasing order
        //2. otherwise, the first element will be greater than the last
        int left = 0;
        int right = nums.size()-1;
        if(left+right == 1){
            return nums[left]<nums[right]? left:right;
        }
        else if(nums[left] <= nums[right]){
            return 0;
        }else{
            //we will use binary search to find the peak
            // we are hundred percent that their is a peak as we have eliminated the
            //other two cases: with all equal elements(not happening one of the constraints) and last element               //being the peak but still first element
            //can be the peak
            while(left<right){
                int mid = (left+right)/2;
                //cout<<left<<" "<<right<<endl;
                if(nums[mid] == target){
                    return mid;
                }
                else if(nums[mid]>nums[left] && nums[mid]>nums[right]){
                   if(nums[mid] > nums[mid+1]){
                       return mid+1;
                   }else{
                       left = mid+1;
                   }
                }else if(nums[mid]<nums[left] && nums[mid]<nums[right]){
                    if(nums[mid] < nums[mid-1]){
                        return mid;
                    }else{
                        right = mid - 1;
                    }
                }else{
                    return nums[left] <nums[right]? left:right;
                }
            }
            return -1;
        }
    }
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int zeroIdx =  findZeroIndex(nums, target);
        if(nums[zeroIdx] == target){
            return zeroIdx;
        }
        int ret = -1;
        if(zeroIdx == 0){
            ret = binarySearch(nums,target,zeroIdx,end);
        }else{
            ret = binarySearch(nums,target,zeroIdx,end);
            if(ret!=-1){
                return ret;
            }
            ret = binarySearch(nums,target,0,zeroIdx-1);
        }
        return ret;
    }
};
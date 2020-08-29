class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int len=nums.size();
        if(len<3){return res;}
        for(int i=0;i<len;i++){
            int tar=nums[i];
            if(tar>0){break;}
            if(i>0&&tar==nums[i-1]){continue;}
            int left=i+1,right=len-1;
            int two=0-tar;
            while(left<right){
                int sum=nums[left]+nums[right];
                if(sum>two){
                    right--;
                }else if(sum<two){
                    left++;
                }else{
                    res.push_back({tar,nums[left],nums[right]});
                    // has relationship with line 9
                    while(left<right&&nums[left]==nums[left+1]){left++;}
                    while(left<right&&nums[right]==nums[right-1]){right--;}
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};
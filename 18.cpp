class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size()<4){return res;}
        std::sort(nums.begin(),nums.end());
        int l,r,i,j,iv,jv,lv,rv,len=nums.size();
        for(i=0;i<len-3;i++){
            iv=nums[i];
            if(i>0&&iv==nums[i-1]){continue;}
            for(j=i+1;j<len-2;j++){
                jv=nums[j];
                if(j>i+1&&jv==nums[j-1]){continue;}
                l=j+1;r=len-1;
                while(l<r){
                    lv=nums[l];rv=nums[r];
                    int sum=iv+jv+lv+rv;
                    if(target==sum){
                        res.push_back({iv,jv,lv,rv});
                        while(l<r&&nums[l]==lv){l++;}
                        while(l<r&&nums[r]==rv){r--;}
                    }else if(target<sum){
                        r--;
                    }else{
                        l++;
                    }
                }
            }
        }
    return res;
    }
};
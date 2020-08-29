class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3){return 0;}
        std::sort(nums.begin(),nums.end());
        int close=nums[0]+nums[1]+nums[2];
        int i,l,r,len=nums.size(),tmp;
        for(i=0;i<len-2;i++){
            l=i+1;
            r=len-1;
            while(l<r){
                tmp=nums[i]+nums[l]+nums[r];
                close=abs(target-close)>abs(target-tmp)?tmp:close;
                if(tmp>target){r--;}
                else if(tmp<target){l++;}
                else{return tmp;}
            }
        }
        return close;
    }
};
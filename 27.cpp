class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index=-1,tmp;
        for(int i=0;i<nums.size();i++){
            tmp =nums[i];
            if(tmp!=val){
                index++;
                if(index!=i){
                    nums[index]=tmp;
                }
            }
        }
        return index+1;
    }
};

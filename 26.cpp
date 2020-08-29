class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //vector<int>::iterator it=nums.begin();
        //vector<int>::iterator end=nums.end();
        int tmp,index=0,same=0,move=0,it=0,end=nums.size();
        while(it!=end){
            tmp=nums[it];
            it++;
            while(it!=end){
                move++;
                if(nums[it]==tmp){
                    same++;
                    it++;
                }else{
                    if(index<same){
                        nums[index+1]=nums[it];
                        same=move;
                    }else{
                        same++;
                    }
                    index++;
                    break;
                }
            }
        }
        //if(index!=nums.size()){
        //    nums.resize(index+1);
        //}
        return end==0?0:index+1;
    }
};
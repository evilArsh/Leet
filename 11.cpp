class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()<2){return 0;}
        int hl=0,hr=height.size()-1,maxNum=0;
        while(hl<hr){
            int t=min(height[hr],height[hl])*(hr-hl);
            if(t>maxNum){maxNum=t;}
            height[hl]<height[hr]?hl++:hr--;
        }
        return maxNum;
    }
};

static auto io_sync_off = [](){
ios::sync_with_stdio(false);
cin.tie(nullptr);
return nullptr;
}();
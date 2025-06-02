class Solution {
public:
    int count(int n){
        return n * (n+1) / 2;
    }
    
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        if(n <= 1) return n;
        
        int candies = 0;
        int up = 0, down = 0;
        int old_slope = 0, new_slope;
        
        for(int i = 1; i < n; ++i){
            if(ratings[i] > ratings[i-1]){
                new_slope = 1;
            }else if(ratings[i] == ratings[i-1]){
                new_slope = 0;
            }else{
                new_slope = -1;
            }
            
            if((old_slope >0 && new_slope == 0) ||
              (old_slope < 0 && new_slope >= 0)){
                candies += count(up) + count(down) + max(up, down);
                up = down = 0;
            }
            
            if(new_slope > 0){
                ++up;
            }else if(new_slope < 0){
                ++down;
            }else{
                //new_slope == 0
                ++candies;
            }
            
            old_slope = new_slope;
        }
        
        candies += count(up) + count(down) + max(up, down) + 1;
        
        return candies;
    }
};
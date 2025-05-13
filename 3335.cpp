class Solution {
public:
const int MOD = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        vector<long long> count(26,0);

        for (char c: s){
            count [c - 'a']++;
        }

        for (int step =0; step <t; ++step){
            vector<long long> new_count(26, 0);

            for(int i =0; i<25; ++i){
                new_count [i+1]= count[i];
            }

            new_count[0]=(new_count[0]+count[25])%MOD;
            new_count[1]=(new_count[1]+count[25])%MOD;

            count = new_count;
        }
        long long result =0;
        for(int i=0; i<26; ++i){
            result = (result +count[i])%MOD;
        }
        return static_cast<int> (result);
        
    }
};
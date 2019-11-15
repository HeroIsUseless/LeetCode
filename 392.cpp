

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_n=s.length(), t_n=t.length();
        if(s_n == 0) return true;
        int s_i=0, t_i=0;
        while(t_i < t_n){
            if(s[s_i] == t[t_i]){
                s_i++;
                if(s_i == s_n) return true;
            }
            t_i++;
        }
        return false;
    }
};


#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector< vector<int> > dp(word1.length(), vector<int>(word2.length(), 0));
        if(word1[0] != word2[0]) dp[0][0] = 1;
        for(int i=0; i<word1.length(); i++){
            for(int j=0; j<word2.length(); j++){
                int a = db[i][j-1]+1;
                int b = db[i-1][j-1]+1;
                int c = (word1[i] == word2[j])?db[i-1][j-1]:db[i-1][j-1]+1;
                db[i][j] = min(a,b,c);
            }
        } 
        return db[word1.length()-1][word2.length()-1];        
    }
};
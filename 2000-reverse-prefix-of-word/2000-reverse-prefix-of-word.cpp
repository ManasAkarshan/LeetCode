class Solution {
public:
    void rev(string &s, int i, int j){
        while(i<=j){
            swap(s[i], s[j]);
            i++; j--;
        }
    }
    string reversePrefix(string word, char ch) {
        for(int i=0; i<word.size(); i++){
            if(word[i] == ch){
                rev(word, 0, i);
                break;
            }
        }
        return word;
    }
};
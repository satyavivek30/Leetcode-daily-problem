class Solution {
public:
    bool closeStrings(std::string word1, std::string word2) {

        std::vector<int>freqmap1(26,0);
        std::vector<int>freqmap2(26,0);

        for (char c: word1){
            freqmap1[c - 'a']++;
        }
        for(char c : word2){
            freqmap2[c-'a']++;
        }
        for(int i = 0; i < 26; i++){
            if((freqmap1[i] == 0 && freqmap2[i] != 0) || (freqmap1[i] != 0 && freqmap2[i]==0)){
                return false;
            }
        }
        std::sort(freqmap1.begin(), freqmap1.end());
        std::sort(freqmap2.begin(), freqmap2.end());

        for (int i = 0; i < 26; i++){
            if (freqmap1[i] != freqmap2[i]){
                return false;
            }
        }
        return true;
    }
};

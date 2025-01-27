class Solution {
public:
    string longestWord(vector<string>& words) {

        sort(words.begin(), words.end());

        unordered_set<string> validWords;
        string longestValidWord = "";


        for (string& currentWord : words) {

            if (currentWord.length() == 1 ||
                validWords.find(currentWord.substr(
                    0, currentWord.length() - 1)) != validWords.end()) {
                validWords.insert(currentWord);

                if (longestValidWord.length() < currentWord.length()) {
                    longestValidWord = currentWord;
                }
            }
        }

        return longestValidWord;
    }
};
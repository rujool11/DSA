// Leetcode 126. Word Ladder

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        dict.erase(beginWord); // delete start word if it exists

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word == endWord) return steps;

            for (int i=0; i<word.size(); i++) {
                int originalChar = word[i];

                for (char x='a'; x <= 'z'; x++) {
                    word[i] = x;
                    if (dict.find(word)!=dict.end()) {
                        dict.erase(word);
                        q.push({word, steps+1});
                    }
                }

                word[i] = originalChar;
            }

        }

        return 0;
    }
};
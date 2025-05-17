// UPVOTE IF THIS CODE HELPS
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
    for (char ch : s) {
        freqMap[ch]++;
    }

    // Step 2: Create buckets where index = frequency
    int maxFreq = s.length();
    vector<vector<char>> buckets(maxFreq + 1);
    for (auto& [ch, freq] : freqMap) {
        buckets[freq].push_back(ch);
    }

    // Step 3: Build result from highest frequency to lowest
    string result;
    for (int freq = maxFreq; freq > 0; --freq) {
        for (char ch : buckets[freq]) {
            result.append(freq, ch);  // Append 'ch' freq times
        }
    }

    return result;
    }
};
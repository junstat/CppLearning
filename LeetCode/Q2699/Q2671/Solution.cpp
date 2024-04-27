#include <vector>

using namespace std;

class FrequencyTracker {
public:
    FrequencyTracker() {
        freq.resize(100001);
        count.resize(100001);
    }

    void add(int number) {
        freq[count[number]]--;
        count[number]++;
        freq[count[number]]++;
    }

    void deleteOne(int number) {
        if (count[number] > 0) {
            freq[count[number]]--;
            count[number]--;
            freq[count[number]]++;
        }
    }

    bool hasFrequency(int frequency) {
        return freq[frequency] >= 1;
    }

    vector<int> freq;
    vector<int> count;
};
//  Time: O(nlogn) where n is the number of cards in the hand
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        map<int, int> freq;

        for(int card: hand){
            freq[card]++;
        }

        while(!freq.empty()){
            int start = freq.begin()->first;
            for(int card = start; card < start+groupSize; card++){
                if(freq.find(card) == freq.end()) return false;
                freq[card]--;
                if(freq[card] == 0) freq.erase(card);
            }
        }
        return true;
    }
};
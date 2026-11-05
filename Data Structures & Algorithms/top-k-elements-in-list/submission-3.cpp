class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter{};
        // Get frequency of the nums
        for(const auto num : nums) counter[num]++;

        // Create custom data container
        struct Freq {
            int data;
            int counter;

            // Overload < op for container sorting
            bool operator<(const Freq& other) const {
                if(counter != other.counter) 
                    return counter < other.counter;
                return data < other.data;
            }
        };

        // Create priority queue (max heap) of the struct
        priority_queue<Freq> max_queue;
        for(const auto& [num, freq] : counter) {
            // Add all freq data to the max heap
            max_queue.push({.data=num, .counter=freq});
        }

        // Create result container by taking the first 'k' values
        vector<int> res{};
        for(int i=0; i<k; i++) {
            res.push_back(max_queue.top().data);
            max_queue.pop();
        }

        return res;
    }
};

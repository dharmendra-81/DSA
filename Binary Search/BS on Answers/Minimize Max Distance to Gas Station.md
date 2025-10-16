We have a **horizontal** number line. On that number line, we have gas **stations** at positions stations[0], stations[1], ..., stations[n-1]. Now, we add **k** more gas stations so that **d**, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of d. Find the answer **exactly** to 2 decimal places.  
**Note**: **`stations`** is in a **strictly increasing** order.

---
#### Brute Force
```cpp
class Solution {
public:
    double minMaxDist(vector<int>& stations, int K) {
        int n = stations.size();
        vector<int> howMany(n - 1, 0);

        for (int gasStations = 1; gasStations <= K; gasStations++) {
            int maxInd = -1;
            double maxSection = -1.0;

            for (int i = 0; i < n - 1; i++) {
                double diff = stations[i + 1] - stations[i];
                double sectionLength = diff / (howMany[i] + 1.0);

                if (sectionLength > maxSection) {
                    maxSection = sectionLength;
                    maxInd = i;
                }
            }

            howMany[maxInd]++;
        }

        double maxAns = 0.0;
        for (int i = 0; i < n - 1; i++) {
            double diff = stations[i + 1] - stations[i];
            double sectionLength = diff / (howMany[i] + 1.0);
            maxAns = max(maxAns, sectionLength);
        }

        return maxAns;
    }
};
//`O(K * N)`
```

#### Better
```cpp
class Solution {
public:
    double minMaxDist(vector<int>& stations, int K) {
        int n = stations.size();
        vector<int> howMany(n - 1, 0);

        // Max heap: pair<max section length, index>
        priority_queue<pair<long double, int>> pq;
		 //insert the first n-1 elements into pq with respective distance values:
        for (int i = 0; i < n - 1; i++) {
            long double dist = stations[i + 1] - stations[i];
            pq.push({dist, i});
        }
		//Pick and place k gas stations:
        for (int gasStations = 1; gasStations <= K; gasStations++) {
            auto tp = pq.top(); pq.pop();
            int secInd = tp.second;
			//insert the current gas station:
            howMany[secInd]++;

            long double dist = stations[secInd + 1] - stations[secInd];
            long double newSectionLength = dist / (howMany[secInd] + 1.0);

            pq.push({newSectionLength, secInd});
        }

        return pq.top().first; 
    }
};
//O(K log N)

```

#### Optimal
```cpp
int numberOfGasStationsRequired(long double dist, vector<int> &stations) {
    int n = stations.size();
    int cnt = 0;

    for (int i = 1; i < n; i++) {
        long double gap = stations[i] - stations[i - 1];
        cnt += floor(gap / dist); // Number of stations needed in this segment
    }

    return cnt;
}

class Solution {
public:
    double minMaxDist(vector<int>& stations, int K) {
        int n = stations.size();
        long double low = 0;
        long double high = 0;

        // Find maximum distance between consecutive stations
        for (int i = 0; i < n - 1; i++) {
            high = max(high, (long double)(stations[i + 1] - stations[i]));
        }

        // Binary search for minimum possible max distance
        long double diff = 1e-6;
        while (high - low > diff) {
            long double mid = (low + high) / 2.0;
            int cnt = numberOfGasStationsRequired(mid, stations);

            if (cnt > K) {
                low = mid;
            } else {
                high = mid;
            }
        }

        return high;
    }
};
//O(N log(max_dist / diff))

```
class Solution {
public:
    long long maxSum(vector<vector<int>>& units) {
        int m = units.size(); // number of devices
        int n = units[0].size(); // number of units in each device

        vector<long long> a(m), b(m), d(m);
        long long base = 0; //if we remove the minimum from each device, this is the sum of the remaining units

        for (int i = 0; i < m; i++) {
            long long mn1 = LLONG_MAX, mn2 = LLONG_MAX;

            for (int x : units[i]) {
                if (x < mn1) {
                    mn2 = mn1;
                    mn1 = x;
                } else if (x < mn2) {
                    mn2 = x;
                }
            }

            a[i] = mn1;

            if (n == 1)
                b[i] = 0;          // removing the only unit empties device
            else
                b[i] = mn2;

            d[i] = b[i] - a[i];
            base += a[i];
        }

        vector<pair<long long,long long>> arr;
        for (int i = 0; i < m; i++)
            arr.push_back({a[i], d[i]});

        sort(arr.begin(), arr.end());

        vector<long long> suf(m + 1, 0);
        for (int i = m - 1; i >= 0; i--)
            suf[i] = suf[i + 1] + arr[i].second;

        unordered_map<long long, long long> bestForA;

        long long prefBest = LLONG_MIN;

        int i = 0;
        while (i < m) {
            int j = i;

            while (j < m && arr[j].first == arr[i].first)
                j++;

            long long val = arr[i].first;

            // all devices with minimum >= val
            long long K = val + suf[i];

            prefBest = max(prefBest, K);
            bestForA[val] = prefBest;

            i = j;
        }

        long long ans = 0;

        for (int k = 0; k < m; k++) {
            ans = max(ans,
                      base - b[k] + bestForA[a[k]]);
        }

        return ans;
    }
};
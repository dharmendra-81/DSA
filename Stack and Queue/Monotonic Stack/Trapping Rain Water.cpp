// using two arrays
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int trapped = 0;
        vector<int> prefixMax(n);
        vector<int> suffixMax(n);
        
        prefixMax[0] = height[0];
        for(int i = 1; i < n; i++)
            prefixMax[i] = max(prefixMax[i-1], height[i]);

        suffixMax[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--)
            suffixMax[i] = max(suffixMax[i+1], height[i]);
        
        for(int i = 0; i < n; i++){
            if(height[i] < prefixMax[i] && height[i] < suffixMax[i])
                trapped += min(prefixMax[i], suffixMax[i]) - height[i];
        }

        return trapped;
    }
};

// using two pointers
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int trapped = 0;
        int leftMax = 0, rightMax = 0;
        int left = 0, right = n-1;

        while(left < right){
            if(height[left] <= height[right]){
                if(leftMax > height[left]) 
                    trapped += leftMax - height[left];
                else leftMax = height[left];
                left++;
            }
            else{
                if(rightMax > height[right])
                    trapped += rightMax - height[right];
                else rightMax = height[right];
                right--;
            }
        }

        return trapped;
    }
};
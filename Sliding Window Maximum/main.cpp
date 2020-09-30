#include <deque>
#include <vector>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        int size = nums.size();
        int loop = 0;
        for (loop = 0; loop < k; loop++)
        {
            while (!q.empty() && nums[loop] >= nums[q.back()])
                q.pop_back();

            q.push_back(loop);
        }
        

        for (; loop < size; loop++)
        {
            ans.push_back(nums[q.front()]) ;
			// check if max element is out of range pop it 
             while(!q.empty() && q.front()<=loop-k)
                q.pop_front() ;
            
			
            while(!q.empty() && nums[loop]>=nums[q.back()])
                q.pop_back() ;
            
            q.push_back(loop) ;
        }
        
        ans.push_back(nums[q.front()]);
        return ans;
    }
};
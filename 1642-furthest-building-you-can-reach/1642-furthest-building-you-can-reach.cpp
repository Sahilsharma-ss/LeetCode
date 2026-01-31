class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {

        int ind = 0;
        int n = heights.size();

        priority_queue<int> pq;

        while(ind < n-1)
        {
            int diff = heights[ind+1] - heights[ind];

            if(diff <= 0) {
                ind++;
                continue;
            }

            bricks -= diff;
            pq.push(diff);

            // if bricks exceeded replace largest with ladder
            if(bricks < 0) {
                if(ladders == 0) break;

                bricks += pq.top();
                pq.pop();
                ladders--;
            }

            ind++;
        }

        return ind;
    }
};

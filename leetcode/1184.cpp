class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        int sum = 0;
        for (int x:distance) sum += x;
        
        int D = 0;
        for (int i=start; i!=destination; i = (i+1)%n){
            D += distance[i];
        }
        
        return min(D, sum-D);
    }
};

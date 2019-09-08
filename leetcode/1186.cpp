class Solution {
public:    
    int maximumSum(vector<int>& a) {
        if (a.size()==1) return a[0];
        
        int ans = max({a[0], a[0]+a[1], a[1]});
        
        int A = max(a[1], a[0]+a[1]), B = a[0];
        
        for (int i=2; i<a.size(); i++){
            int x = a[i];
            
            B = max(B+x, A);
            A = max(A+x, x);
            
            ans = max(ans, A);
            ans = max(ans, B);
        }
        
        return ans;
    }
};

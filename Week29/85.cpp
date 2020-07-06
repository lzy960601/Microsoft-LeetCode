class Solution {
public:

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() <= 0 || matrix[0].size() <= 0) return 0;
        vector< int > this_line, last_line, left, right;
        stack< int > s;

        int ans = 0, n = matrix.size(), m = matrix[0].size();

        this_line.clear(); last_line.clear(); left.clear(); right.clear();

        for(int i = 0; i < m; ++ i) last_line.push_back(0), left.push_back(0), right.push_back(0);
        
        for(int i = 0; i < n; ++ i)
        {
            this_line.clear();
            for(int j = 0; j < m; ++ j)
                if(matrix[i][j] == '0') this_line.push_back(0);
                else this_line.push_back( last_line[j] + 1 );
            last_line = this_line;
            
            while(!s.empty()) s.pop();
            for(int j = 0; j < m; ++ j)
            {
                while( !s.empty() && this_line[s.top()] >= this_line[j] ) s.pop();
                if(!s.empty()) left[j] = s.top(); else left[j] = -1;
                s.push(j);
            }

            while(!s.empty()) s.pop();
            for(int j = m - 1; j >= 0; -- j)
            {
                while( !s.empty() && this_line[s.top()] >= this_line[j] ) s.pop();
                if(!s.empty()) right[j] = s.top(); else right[j] = m;
                s.push(j);
            }

            for(int j = 0; j < m; ++ j)
                ans = max(ans, this_line[j] * (right[j] - left[j] - 1));
        }
        return ans;
    }
};

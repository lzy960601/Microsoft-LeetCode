class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> s[1000005]; 
        int cnt = 0; 
        s[cnt].clear();
        formula = "(" + formula + ")";
        int len = formula.length(), index = 0;
        string name = "";
        while(index < len)
        {
            char c = formula[index];
            if(c == '(')
            {
                ++ cnt; s[cnt].clear();
                name = ""; ++ index;
                continue;
            }
            if(c == ')')
            {
                map<string, int> tmp = s[cnt]; -- cnt;
                int value = 0; ++ index;
                while(index < len && formula[index] >= '0' && formula[index] <= '9')
                {
                    value = value * 10 + formula[index] - 48;
                    ++ index;
                } 
                value = max(value, 1); name = "";
                for(auto &iter : tmp) s[cnt][iter.first] += (iter.second) * value;
                continue;
            }
            if(c >= '0' && c <= '9')
            {
                int value = 0;
                while(index < len && formula[index] >= '0' && formula[index] <= '9')
                {
                    value = value * 10 + formula[index] - 48;
                    ++ index;
                }
                value = max(value, 1);
                s[cnt][name] += value;
                continue;
            }
            if(c >= 'A' && c <= 'Z')
            {
                name = ""; name += c; ++ index;
                while(index < len && formula[index] >= 'a' && formula[index] <= 'z') 
                    name += formula[index ++];
                if(formula[index] < '0' || formula[index] > '9') s[cnt][name] += 1;
                continue;
            }
        }

        assert(cnt == 0);

        vector< pair<string, int> > ans; ans.clear();
        for(auto &iter : s[cnt]) ans.push_back(make_pair(iter.first, iter.second));
        sort(ans.begin(), ans.end());
        string ret = "";
        for(auto iter : ans) ret += (iter.first + (iter.second > 1 ? to_string(iter.second) : ""));
        return ret; 
    }
};

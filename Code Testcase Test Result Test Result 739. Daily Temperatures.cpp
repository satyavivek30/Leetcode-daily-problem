// c++ implementation
 vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();
        stack<pair<int, int>>s;
        vector<int>res(n, 0);

        for (int i = 0; i < n; i++){
            int currTemp = temperatures[i];

            while (!s.empty() && currTemp > s.top().first){
                auto[stackTemp, stackInd] = s.top();
                res[stackInd] = i - stackInd;
                s.pop();
            }
            s.push({currTemp, i});
        }
        return res;
        
    }

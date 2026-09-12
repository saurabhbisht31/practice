class Solution {
public:

    struct Node {
        long long score = 0;
        vector<int> idxs;
        bool calculated = false;
    };

    vector<pair<vector<int>, int>> temp;
    vector<int> nextidx;
    vector<vector<Node>> t;

    int n;


    Node solve(int i, int k) {

        if(i >= n || k == 0) {
            return Node();
        }

        if(t[i][k].calculated) {
            return t[i][k];
        }


        Node skip = solve(i + 1, k);


        int weight = temp[i].first[2];
        int idx = temp[i].second;

        int j = nextidx[i];

        Node afterTake = solve(j, k - 1);

        Node take;

        take.score = weight + afterTake.score;

     
        take.idxs = afterTake.idxs;

        take.idxs.push_back(idx);
        sort(take.idxs.begin(), take.idxs.end());


     
        Node result;

        if(take.score > skip.score) {

            result = take;

        }
        else if(take.score < skip.score) {

            result = skip;

        }
        else {

            if(take.idxs < skip.idxs) {
                result = take;
            }
            else {
                result = skip;
            }
        }

        result.calculated = true;

        return t[i][k] = result;
    }


    int getNext(int endpoint) {

        int low = 0;
        int high = n - 1;

        int result = n;

        while(low <= high) {

            int mid = low + (high - low) / 2;
            if(temp[mid].first[0] > endpoint) {

                result = mid;
                high = mid - 1;

            }
            else {

                low = mid + 1;
            }
        }

        return result;
    }


    vector<int> maximumWeight(vector<vector<int>>& intervals) {

      
        temp.clear();
        nextidx.clear();

        n = intervals.size();


        for(int i = 0; i < n; i++) {

            temp.push_back({
                intervals[i],
                i
            });
        }


        sort(temp.begin(), temp.end());


        nextidx.resize(n);

        for(int i = 0; i < n; i++) {

            int endpoint = temp[i].first[1];

            nextidx[i] = getNext(endpoint);
        }

        int k = 4;

        t.assign(n + 1, vector<Node>(k + 1));


   
        Node ans = solve(0, k);


      
        sort(ans.idxs.begin(), ans.idxs.end());

        return ans.idxs;
    }
};
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {

        int n = transactions.size();

        vector<string> name(n), city(n);
        vector<int> time(n), amount(n);

        for(int i = 0; i < n; i++) {

            string s = transactions[i];

            int pos1 = s.find(',');
            int pos2 = s.find(',', pos1 + 1);
            int pos3 = s.find(',', pos2 + 1);

            name[i] = s.substr(0, pos1);

            time[i] = stoi(s.substr(pos1 + 1, pos2 - pos1 - 1));

            amount[i] = stoi(s.substr(pos2 + 1, pos3 - pos2 - 1));

            city[i] = s.substr(pos3 + 1);
        }

        vector<bool> invalid(n, false);

        for(int i = 0; i < n; i++) {

            if(amount[i] > 1000) {
                invalid[i] = true;
            }

            for(int j = i + 1; j < n; j++) {

                if(name[i] == name[j] &&
                   city[i] != city[j] &&
                   abs(time[i] - time[j]) <= 60) {

                    invalid[i] = true;
                    invalid[j] = true;
                }
            }
        }

        vector<string> ans;

        for(int i = 0; i < n; i++) {
            if(invalid[i]) {
                ans.push_back(transactions[i]);
            }
        }

        return ans;
    }
};
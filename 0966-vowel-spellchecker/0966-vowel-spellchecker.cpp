class Solution {
public:
    string convert(string s){
        string t = "";
        for(auto c : s){
            c = tolower(c);
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                t += '*';
            }else{
                t += c;
            }
        }
        return t;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int n = wordlist.size();
        int m = queries.size();
        vector<string>answer(m,"");
        unordered_set<string>st1;
        unordered_map<string,string>st2,st3;
        for(auto word : wordlist){
            st1.insert(word);
            string nw = "";
            for(auto c : word){
                nw += tolower(c);
            }
            if(st2.find(nw) == st2.end()) st2[nw] = word;
            string st = convert(word);
            if(st3.find(st) == st3.end()) st3[st] = word;
        }
        for(int i = 0; i < m; i++){
            string q = queries[i];
            if(st1.find(q) != st1.end()){
                answer[i] = q;
                continue;
            }

            string nw = "";
            for(auto c : q){
                nw += tolower(c);
            }
            if(st2.find(nw) != st2.end()){
                answer[i] = st2[nw];
                continue;
            }

            string st = convert(q);
            if(st3.find(st) != st3.end()){
                answer[i] = st3[st];
                continue;
            }
        }
        return answer;
    }
};
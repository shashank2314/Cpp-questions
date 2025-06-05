class Solution {
public:
vector<int> parent;
    int find(int a){
        if(a==parent[a]){
            return a;
        }
        return parent[a] = find(parent[a]);
    }
    void dounion(int a,int b){
        int pa = find(a);
        int pb = find(b);
        if(pa!=pb){
            if(pa<pb){
                parent[pb] = pa;
            }
            else{
                parent[pa] = pb;
            }
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        for(int i=0;i<26;i++){
            parent[i] = i;
        }
        int n = s1.size();
        for(int i=0;i<n;i++){
            dounion(s1[i]-'a',s2[i]-'a');
        }
        string ans = "";
        int n2 = baseStr.size();
        for(int i=0;i<n2;i++){
            char c = 'a';
            ans+=(c + find(baseStr[i]-'a'));
        }
        return ans;
    }
};
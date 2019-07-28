#include<bits/stdc++.h>
using namespace std;

int ans;

void dfs(vector<vector<char> > &v,vector<vector<bool> > &isVisited,int r,int c,int maxR,int maxC){
    if(r<0||r>=maxR||c<0||c>=maxC||v[r][c]!='W'||isVisited[r][c])return;
    isVisited[r][c]=true;
    ans++;
    for(int a_i=-1;a_i<=1;a_i++)
        for(int b_i=-1;b_i<=1;b_i++)dfs(v,isVisited,r+a_i,c+b_i,maxR,maxC);
}

int main(){
    int testCase,a_i,b_i,r,c;
    cin>>testCase;
    string st;
    getline(cin,st);
    getline(cin,st);
    vector<vector<char> > v;
    while(testCase--){
            v.clear();
        while(getline(cin,st)){
            if(st[0]=='\0'){
                break;
            }
            if(st[0]=='W'||st[0]=='L'){
                int l=st.size();
                vector<char> v1(l);
                for(a_i=0;a_i<l;a_i++)v1[a_i]=st[a_i];
                v.push_back(v1);
            }
            else{
                istringstream is(st);
                int ara[2];
                a_i=0;
                while(is>>st){
                    stringstream ss;
                    ss<<st;
                    ss>>ara[a_i++];
                }
                ans=0;
                int r=v.size(),c=v[0].size();
                vector<vector<bool> > isVisited(r,vector<bool> (c,false));
                dfs(v,isVisited,ara[0]-1,ara[1]-1,r,c);
                cout<<ans<<endl;
            }
        }
        if(testCase)cout<<endl;
    }
}

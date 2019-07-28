#include<bits/stdc++.h>
using namespace std;

int main(){
    int a_i,b_i,b1,b2,temp,l,r;
    long long d1,d2;
    char ch;
    string st1,st2,st;
    while(cin>>st){
        cin>>b1>>b2;
        d1=0;
        l=st.size()-1;
        for(int a_i=0;a_i<=l;a_i++){
                if(st[l-a_i]>'9'){
                    temp=st[l-a_i]-'A'+10;
                }
                else temp=st[l-a_i]-'0';
                //cout<<temp<<endl;
            d1+=temp*(llround)(pow(b1,a_i));
        }
        //cout<<d1<<endl;
    stringstream ss;
    st2="";
    ss<<d1;
    st=ss.str();
    l=st.size()-1;
    if(d1>=llround(pow(b2,7))){
       cout<<"  ERROR"<<endl;
       continue;
    }
    for(a_i=6;a_i>=0;a_i--){
            d2=llround(pow(b2,a_i));

            temp=d1/d2;
            d1%=d2;
            if(temp>9){
                ch=(char) temp+ 65-10;
            }
            else ch=(char)(temp+48);
                st2+=ch;
    }
    //reverse(st2.begin(),st2.end());
    //cout<<st2<<endl;
    l=st2.size()-1;
    for(a_i=0;a_i<l;a_i++){
        if(st2[a_i]=='0')cout<<" ";
        else break;
    }
    for(;a_i<=l;a_i++)cout<<st2[a_i];
    cout<<endl;
}
}

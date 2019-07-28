#include<bits/stdc++.h>
using namespace std;

bool is;

void addEdge( vector < int > *graph, int n1, int n2 ){
    graph[ n1 ].push_back( n2 );
    graph[ n2 ].push_back( n1 );
}

void check( vector < int > *graph, vector < char > &c, char pre, int n ){
    //cout<<c[ n ]<<" ";
    if(!is)return;
    if( pre == c[ n ] ){
            is=false;
            return;
    }
    if( c[ n ] != '_' ) return;
//cout<<"a";
    if( pre == 'B' ) c[ n ] = 'W';
    else c[ n ] = 'B';
    for( int x : graph[n] ){
        check( graph, c, c[n], x );
    }
}

int main(){
    int noOfNodes, noOfEdges, a_i, n1, n2, b_i;
    while(cin>>noOfNodes){
        if(noOfNodes==0)break;
        vector < int > graph[noOfNodes];
        vector<char> c(noOfNodes,'_');
        cin>>noOfEdges;
        while(noOfEdges--){
            cin>>n1>>n2;
            addEdge( graph, n1, n2 );

    }

    is = true;
    //c[0] = 'B';
    check( graph, c, 'W', 0 );
    if(!is)cout<<"NOT BICOLORABLE."<<endl;
    else cout<<"BICOLORABLE."<<endl;
}
}

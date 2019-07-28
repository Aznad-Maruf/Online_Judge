#include<bits/stdc++.h>
using namespace std;

vector < vector < int > > graph;
vector < int > v;

void addEdge( int n1, int n2 ){
    graph[n1].push_back( n2 );
}

int maxiNodes( int n, int k ){
    //if( graph[n].empty() ) return 1;
    int s=graph[n].size();
    if( s < k ) return 1;

    int temp=0;
    for( int x : graph[n] ){
        temp+=maxiNodes( x );
    }
    return k;
}

int main(){
    int testCase, a_i, b_i, n, noOfNodes, k, temp, n1, n2;
    cin>>testCase;
    while( testCase-- ){
        cin>>noOfNodes>>k;
        graph.resize( noOfNodes+1 );
        v.resize( noOfNodes+1 );
        temp=noOfNodes-1;
        while( temp-- ){
            cin>>n1>>n2;
            addEdge( n1, n2 );
        }
        cout<<maxiNodes( 1, k )<<endl;
    }
}

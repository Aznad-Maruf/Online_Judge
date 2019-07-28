#include<bits/stdc++.h>
using namespace std;

map < string, int > mp;
map < int, string > mp2;
vector < vector < int > > graph;
vector < bool > isVisited;
vector < int > v;
stack < int > stk;
vector < int > inDegree;
priority_queue < int, vector < int > , greater < int >   > pq;

/*
void dfs( int n ){
    int a_i, b_i, temp, cu, tp;

    stk.push( n );
    isVisited[n] = true;
    while( !stk.empty() ){
        cu = stk.top();
        stk.pop();
        for( int x : graph[cu] ){
            if( !isVisited[x] ){
                isVisited[x] = true;
                dfs( x );
            }
        }
        v.push_back( cu );
        //cout<<mp2[cu]<<endl;
    }

}
*/

void topoSort(){
    int a_i, b_i, n, temp, cu;

    while( !pq.empty() ){
        cu = pq.top();
        pq.pop();
        for( int x : graph[cu] ){
            inDegree[x]--;
            if( inDegree[x] == 0 ) pq.push( x );
        }
        v.push_back( cu );
    }
}

void addEdge( int n1, int n2 ){
    graph[n1].push_back( n2 );
}

int main(){
    int noOfNodes, noOfEdges, a_i, n1, n2, testCase, a_t=0;
    string st, st1, st2;
    while( cin>>noOfNodes ){

    graph.resize( noOfNodes+1 );
    isVisited.resize( noOfNodes+1, false );
    inDegree.resize( noOfNodes+1, 0 );

    a_i=0, n1=noOfNodes;
    while( n1-- ){
            cin>>st;
            mp[st]=++a_i;
            mp2[a_i]=st;
    }
    cin>>noOfEdges;
    while( noOfEdges-- ){
        cin>>st1>>st2;
        addEdge( mp[st1], mp[st2] );
        inDegree[mp[st2]]++;
    }

    for( a_i=1; a_i<=noOfNodes; a_i++ ) if( inDegree[a_i]==0 ) pq.push(a_i);

    topoSort();

    //Case #1: Dilbert should drink beverages in this order:
    cout<<"Case #"<<++a_t<<": Dilbert should drink beverages in this order: ";
    for( a_i=0; a_i<noOfNodes; a_i++ ){
            cout<<mp2[v[a_i]];
            if( a_i==noOfNodes-1 ) cout<<".";
            else cout<<" ";
    }
    cout<<endl<<endl;

    mp.clear();
    mp2.clear();
    graph.clear();
    isVisited.clear();
    inDegree.clear();
    v.clear();

    }

}

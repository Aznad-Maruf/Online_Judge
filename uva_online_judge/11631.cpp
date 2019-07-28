#include<bits/stdc++.h>
using namespace std;

void addEdge(vector < pair < int, int > > *graph, int n1, int n2, int w ){
    graph[n1].push_back(make_pair( w, n2 ));
    graph[n2].push_back(make_pair( w, n1 ));
}

void mst( vector < pair < int, int > > *graph, int & w2, int noOfNodes ){
//cout<<"a"<<endl;
    int a_i, b_i, tV=0,cuN,temp,w1;
    priority_queue < pair < int, int > , vector < pair < int, int > > , greater < pair < int, int > > > pq ;
    pq.push(make_pair( 0,0));
    vector < int > w(noOfNodes, INT_MAX);
    vector< bool> is ( noOfNodes, false);
    while(!pq.empty() ){
            //cout<<"b"<<endl;
        cuN=pq.top().second;
        //cout<<cuN<<"c"<<endl;
        if(is[ cuN ]){
                pq.pop();
        continue;
        }
        w2+=pq.top().first;
        pq.pop();
        is[cuN]=true;
        for( auto x : graph[cuN] ){
            //if( is[x.second] )continue;
            pq.push(x);
        }
    }
}

int main(){
    int noOfNodes, noOfEdges, a_i, b_i, n, w, n1, n2 ,w1,w2;
    while(cin>>noOfNodes){
        cin>>noOfEdges;
        if(noOfNodes==0)break;
        vector < pair < int, int > > graph[ noOfNodes ] ; /// first one is weight, second one is node;
        w1=w2=0;
        while( noOfEdges-- ){
                cin>>n1>>n2>>w;
                w1+=w;
            addEdge( graph, n1, n2, w );
        }

        mst( graph, w2 ,noOfNodes );
        cout<<w1-w2<<endl;
    }

}

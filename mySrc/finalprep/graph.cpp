#include <streamio>

using namespace std;

int main(){
    return 0;
}

#if 0

//printing
Graph g = graph_by_file(argv[1])'
for(int v = 0; v < V(g); ++v){
    cout << "V[" << v << "]: ";
    for(gnode w = g->adj[v].next; w; w = w->next){
        cout << w->item  << " ";
        (w->next == nullptr) ? (cout << endl) : (cout << "-> ");
    }
}

//Computing the degree of V
int degree(graph g, int v){
    if(!validVertex(g, v)) return -1;
    int deg = 0;
    //degree는 adj 리스트에 몇개가 있는지 세는 것.
    for(gnode w = g->adj[v].next; w; w = w->next, deg++);
    return deg;
}

//그래프의 degree는 vertxex의 degree중 최대.
int degree(graph g){
    int max = 0;
    for(int v = 0; v < V(g); ++v){
        int deg = degree(g, v);
        if(deg > max) max = deg;
    }
    return max;
}

double degree_average(graph g){
    int return 2.0* E(g) / V(g);
    // 2E / V 로 생각하자. V당 edge의 수를 세는 것. E 하나는 두 V가 공유하니까 곱 2
}



#endif

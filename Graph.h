/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <list>
#include <limits>
#include <cmath>
#include "MutablePriorityQueue.h"

using namespace std;

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;

#define INF std::numeric_limits<double>::max()

/************************* Vertex  **************************/

template <class T>
class Vertex {
	T info;						// content of the vertex
	vector<Edge<T> > adj;		// outgoing edges
	
	double dist = 0;
	Vertex<T> *path = NULL;
	int queueIndex = 0; 		// required by MutablePriorityQueue

	bool visited = false;		// auxiliary field
	bool processing = false;	// auxiliary field

	void addEdge(Vertex<T> *dest, double w);

public:
	Vertex(T in);
	T getInfo() const;
	double getDist() const;
	Vertex *getPath() const;

	bool operator<(Vertex<T> & vertex) const; // // required by MutablePriorityQueue
	friend class Graph<T>;
	friend class MutablePriorityQueue<Vertex<T>>;
};


template <class T>
Vertex<T>::Vertex(T in): info(in) {}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
template <class T>
void Vertex<T>::addEdge(Vertex<T> *d, double w) {
	adj.push_back(Edge<T>(d, w));
}

template <class T>
bool Vertex<T>::operator<(Vertex<T> & vertex) const {
	return this->dist < vertex.dist;
}

template <class T>
T Vertex<T>::getInfo() const {
	return this->info;
}

template <class T>
double Vertex<T>::getDist() const {
	return this->dist;
}

template <class T>
Vertex<T> *Vertex<T>::getPath() const {
	return this->path;
}

/********************** Edge  ****************************/

template <class T>
class Edge {
	Vertex<T> * dest;      // destination vertex
	double weight;         // edge weight
public:
	Edge(Vertex<T> *d, double w);
	friend class Graph<T>;
	friend class Vertex<T>;
};

template <class T>
Edge<T>::Edge(Vertex<T> *d, double w): dest(d), weight(w) {}


/*************************** Graph  **************************/

template <class T>
class Graph {
	vector<Vertex<T> *> vertexSet;    // vertex set
    vector<vector<double>> dist; //distance matrix
    vector<vector<Vertex<T>*>> pred; // vertex matrix

public:
	Vertex<T> *findVertex(const T &in) const;
	bool addVertex(const T &in);
	bool addEdge(const T &sourc, const T &dest, double w);
	int getNumVertex() const;
	vector<Vertex<T> *> getVertexSet() const;

	// Fp05 - single source
	void unweightedShortestPath(const T &s);    //TODO...
	void dijkstraShortestPath(const T &s);      //TODO...
	void bellmanFordShortestPath(const T &s);   //TODO...
	vector<T> getPathTo(const T &dest) const;   //TODO...

	// Fp05 - all pairs
	void floydWarshallShortestPath();   //TODO...
	vector<T> getfloydWarshallPath(const T &origin, const T &dest) const;   //TODO...

};

template <class T>
int Graph<T>::getNumVertex() const {
	return vertexSet.size();
}

template <class T>
vector<Vertex<T> *> Graph<T>::getVertexSet() const {
	return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
template <class T>
Vertex<T> * Graph<T>::findVertex(const T &in) const {
	for (auto v : vertexSet)
		if (v->info == in)
			return v;
	return NULL;
}

/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
template <class T>
bool Graph<T>::addVertex(const T &in) {
	if ( findVertex(in) != NULL)
		return false;
	vertexSet.push_back(new Vertex<T>(in));
	return true;
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w) {
	auto v1 = findVertex(sourc);
	auto v2 = findVertex(dest);
	if (v1 == NULL || v2 == NULL)
		return false;
	v1->addEdge(v2,w);
	return true;
}


/**************** Single Source Shortest Path algorithms ************/

template<class T>
void Graph<T>::unweightedShortestPath(const T &orig) {
	Vertex <T> *src = findVertex(orig);

	for(auto vert : vertexSet){
	    vert->dist = INT32_MAX;
	    vert->path = NULL;
	}

	src->dist = 0;
	queue<Vertex<T>*> Q;
	Q.push(src);
	Vertex<T>*v;

	while(!Q.empty()){
	    v = Q.front();
	    Q.pop();
        auto it = v->adj.begin();
        while (it != v->adj.end()) {
            if ((*it).dest->dist == INT32_MAX) {
                Q.push((*it).dest);
                (*it).dest->dist = v->dist + 1;
                (*it).dest->path = v;
            }
            it++;
        }
	}
}


template<class T>
void Graph<T>::dijkstraShortestPath(const T &origin) {
    for (auto ver : vertexSet) {
        ver->dist = WINT_MAX;
        ver->path = NULL;
    }

    Vertex<T> *src = findVertex(origin);
    Vertex<T> *v;
    src->dist = 0;
    MutablePriorityQueue<Vertex<T>> Q;
    Q.insert(src);

    while(!Q.empty()){
        v = Q.extractMin();
        auto it = v->adj.begin();
        while(it != v->adj.end()){
            if((*it).dest->dist > v->dist + (*it).weight){
                (*it).dest->dist = v->dist + (*it).weight;
                (*it).dest->path = v;
                if(!Q.inQueue((*it).dest))
                    Q.insert((*it).dest);
                else
                    Q.decreaseKey((*it).dest);
            }
            it++;
        }
    }
}


template<class T>
void Graph<T>::bellmanFordShortestPath(const T &orig) {
    for (auto ver : vertexSet) {
        ver->dist = WINT_MAX;
        ver->path = NULL;
    }
    Vertex<T>*src  = findVertex(orig);
    src->dist = 0;
    for(int i = 1;i < vertexSet.size()-1;i++)
    {
        for( auto v: vertexSet)
        {
            for(Edge<T> edge : v->adj)
            {
                if(edge.dest->getDist() > v->dist + edge.weight)
                {
                    edge.dest->dist = v->dist + edge.weight;
                    edge.dest->path = v;
                }
            }
        }
    }
}


template<class T>
vector<T> Graph<T>::getPathTo(const T &dest) const{
    vector<T> res;

    Vertex<T> *v = findVertex(dest);
    res.insert(res.begin(), v->info);

    do {
        v = v->path;
        res.insert(res.begin(), v->info);
    } while (v->path != NULL);

    return res;
}



/**************** All Pairs Shortest Path  ***************/

template<class T>
void Graph<T>::floydWarshallShortestPath() {
    dist.clear();
    dist = vector<vector<double>>(vertexSet.size(), vector<double>(vertexSet.size(), INT64_MAX));
    pred.clear();
    pred = vector<vector<Vertex<T>*>>(vertexSet.size(), vector<Vertex<T>*>(vertexSet.size(), NULL));

    int index1 = 0,index2 = 0;
    for(auto vertex1:vertexSet){
        for(auto vertex2:vertexSet){
            if(index1 == index2)
                dist[index1][index2] = 0;
            else
                for(auto edge: vertex1->adj)
                    if(edge.dest->info == vertex2->info){
                    dist[index1][index2] = edge.weight;
                    pred[index1][index2] = vertex1;
                    }
            index2++;
        }
        index1++;
        index2 = 0;
    }



    for(int i = 0;i<vertexSet.size();i++){
        int index1 = 0,index2 = 0;
        for(auto vertex1:vertexSet){
            for(auto vertex2:vertexSet){
                if(dist[index1][index2] > dist[index1][i] + dist[i][index2]){
                    dist[index1][index2] = dist[index1][i] + dist[i][index2];
                    pred[index1][index2] = pred[i][index2];
                }
                index2++;
            }
            index1++;
            index2 = 0;
        }
    }
}

template<class T>
vector<T> Graph<T>::getfloydWarshallPath(const T &orig, const T &dest) const{
	vector<T> res;
	int origIndex,destIndex;
	for(int i = 0 ;i<vertexSet.size();i++){
        if (vertexSet.at(i)->info == orig)
            origIndex = i;
        else if (vertexSet.at(i)->info == dest)
            destIndex = i;
	}
    while (pred[origIndex][destIndex] != vertexSet[origIndex]) {
        res.emplace(res.begin(), pred[origIndex][destIndex]->info);
        for (int i = 0; i < vertexSet.size(); i++) {
            if (vertexSet.at(i)->info == pred[origIndex][destIndex]->info) {
                destIndex = i;
                break;
            }
        }
    }
    res.push_back(dest);
    res.insert(res.begin(), orig);

    return res;
}


#endif /* GRAPH_H_ */

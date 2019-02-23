// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own, along with
// comments on every function and on complex code sections.
// TODO: write comment header for this file; remove this comment

#include "Trailblazer.h"
#include "queue.h"
#include "priorityqueue.h"
using namespace std;

static const double SUFFICIENT_DIFFERENCE = 0.2;

Path breadthFirstSearch(const RoadGraph& graph, RoadNode* start, RoadNode* end) {
    Queue<Path> q;
    Path vec;
    Set <RoadNode*> visited;
    vec.add(start);
    q.enqueue(vec);
    while(!q.isEmpty()){
        Path path=q.dequeue();
        RoadNode* v=path[path.size()-1];
        if (!visited.contains(v)){
            visited.add(v);
            v->setColor(Color::GREEN);
            if (v==end&&v!=start){
                return path;
            }
            Set <RoadNode*> Neighbor= graph.neighborsOf(v);
            for (RoadNode* i:Neighbor){
                if(!visited.contains(i)){
                    i->setColor(Color::YELLOW);
                    Path newpath=path;
                    newpath.add(i);
                    q.enqueue(newpath);
                }
            }
        }
    }
    return{};
}

Path dijkstrasAlgorithm(const RoadGraph& graph, RoadNode* start, RoadNode* end) {
    PriorityQueue<Path> q;
    Path vec;
    Set <RoadNode*> visited;
    vec.add(start);
    q.enqueue(vec,0);
    while(!q.isEmpty()){
        double cost=q.peekPriority();
        Path path=q.dequeue();
        RoadNode* v=path[path.size()-1];
        if (!visited.contains(v)){
            visited.add(v);
            v->setColor(Color::GREEN);
            if (v==end&&v!=start){
                return path;
            }
            Set <RoadNode*> Neighbor= graph.neighborsOf(v);
            for (RoadNode* i:Neighbor){
                if(!visited.contains(i)){
                    i->setColor(Color::YELLOW);
                    Path newpath=path;
                    newpath.add(i);
                    double newcost=graph.edgeBetween(v,i)->cost()+cost;
                    q.enqueue(newpath,newcost);
                }
            }
        }
    }
    return{};
}

double heuristic(const RoadGraph& graph, RoadNode* start, RoadNode* end){
    double cost=graph.crowFlyDistanceBetween(start,end);
    double speed=graph.maxRoadSpeed();
    double time=cost/speed;
    return time;
}

Path aStar(const RoadGraph& graph, RoadNode* start, RoadNode* end) {
    PriorityQueue<Path> q;
    Path vec;
    Set <RoadNode*> visited;
    vec.add(start);
    q.enqueue(vec,0);
    while(!q.isEmpty()){
        Path path=q.dequeue();
        RoadNode* v=path[path.size()-1];
        if (!visited.contains(v)){
            visited.add(v);
            v->setColor(Color::GREEN);
            if (v==end&&v!=start){
                return path;
            }
            Set <RoadNode*> Neighbor= graph.neighborsOf(v);
            for (RoadNode* i:Neighbor){
                if(!visited.contains(i)){
                    i->setColor(Color::YELLOW);
                    Path newpath=path;
                    newpath.add(i);
                    double newcost=graph.edgeBetween(v,i)->cost()+heuristic(graph,i,end);
                    q.enqueue(newpath,newcost);
                }
            }
        }
    }
    return{};
}

Path alternativeRoute(const RoadGraph& graph, RoadNode* start, RoadNode* end) {
    PriorityQueue<Path> q;
    Path vec;
    Set <RoadNode*> visited;
    vec.add(start);
    q.enqueue(vec,0);
    Path result;
    while(!q.isEmpty()){
        Path path=q.dequeue();
        RoadNode* v=path[path.size()-1];
        if (!visited.contains(v)){
            visited.add(v);
            v->setColor(Color::GREEN);
            if (v==end&&v!=start&&result.size()==0){
                result=path;
            }
            else if(v==end&&v!=start){
                int diff;
                Path test=path;

                }
            }
            Set <RoadNode*> Neighbor= graph.neighborsOf(v);
            for (RoadNode* i:Neighbor){
                if(!visited.contains(i)){
                    i->setColor(Color::YELLOW);
                    Path newpath=path;
                    newpath.add(i);
                    double newcost=graph.edgeBetween(v,i)->cost()+heuristic(graph,i,end);
                    q.enqueue(newpath,newcost);
                }
            }
        }
    }
    return{};
}


# CAL Project 1

## How to compile and run

### Option 1: CLion

Open the folder ParkingSpotsSearcher with Clion, than build and run.

### Option 2: CMake

#### CMake CLI

![Cmake](/images/cmake.png)
Insert the ParkingSpotsSearcher folder as source and ParkingSpotsSearcher/build/ as build folder.
After that go into the ParkingSpotsSearcher/build/ folder, run make, than run the ParkingSpotsSearcher executable.

```bash
cd ParkingSpotsSearcher/build/
make
./parkingSpotsSearcher
```

#### CMake command line

You can compile the code with cmake.
Go to the ParkingSpotsSearcher folder than run cmake.

```bash
cd ParkingSpotsSearcher
mmkdir build
cmake build
```

After compiled just use make than run the executable.

```bash
cd build # from ParkingSpotsSearcher folder
make
./ParkingSpotsSearcher
```

### Theme 1: Searching for a parking spot

In a city, there is a lot of parking spaces: Places on road (parking machines) or garages. The parking value changes from place to place.

In this work, you should implement a system that helps a driver in the search of parking place. A driver wants to go to a specific place (movies, schools, shopping mall...) and want to park his car. It should be calculated the route that allows the driver to go from where he is at to a parking place, and from the car to the destiny (walking).

The parking place could be the closest to the destiny or the cheapest (within a maximum distance to the destiny or to a metro station), it should be a driver's choice. Consider that the driver might want to fill up the car tank before parking, and the route should consider that.

Assess the graph connectivity, to avoid that parking places are in inaccesible zones from the origin point.

Consider the possibility to use real maps, extracted from OpenStreetMaps (www.openstreetmap.org), finding in the map, address and points of interest.

## The project

Let's assume that walking distance has more weight than than the driving distance. 
Walking distance weight = driving distance weight * C.

Let's assume that we have weighted, directed graph G. Nodes of the graph are labeled as none(n), parking spot(p) and gas_station(s). Edges are weighted by distance, nodes labeled as p contains parking spots cost information.

Nodes of graph G are named: G1, G2 ... Gn
n - number of nodes.


### Situation A: no need for visit the gas station. 

For x,y <= n:

We are searching for the shortest path from Gx to Gy where one of nodes labeled as p has to be visited.


Let's assume two copies of graph G: A and B.

Graph A has nodes A1, A2 ... An.
Graph B has nodes B1, B2 ... Bn and weights multiplied by the coefficient C.

Each node of graph A with the label p has 0 weight edge to corresponding graph B node.

Now we can find the shortest path from Ax to By by any shortest path alhorithm.

### Situation B: gas station has to be visited.

Observation: gas station has to be visited first.

Now let's assume three copies of graph G: A, B and C.

Graph C has nodes C1, C2 ... Cn and weights multiplied by the coefficient C.

Each node of graph A with the label s has 0 weight edge to coresponding graph B node.
Each node of graph B with the label p has 0 weight edge to coresponding graph C node.

Now we can find the shortest path from Ax to Cy by any shortest path alhorithm.

### Situation C: cost and maximum distance.

Two options:

1. (simple one) Different problem. We don't care about distance. The cost is specified by the price of the parking spot.   
Run Dijkstra to find nodes with max distance and choose the cheapest parking spot.

2. (to consider) Metro stations, buses, fuel cost etc.
a) Run modified Dijkstra on the highest level graph (look situation A or B) to find all nodes with max distance (include public transport edges with the distance 0) and replace weights by cost of parking spots and public transport. Replace all other edges (in highest level graph) weights by infinite cost(MAX_INT).
b) Change each distance (lower level graphs) to the fuel price cost.

Each node of graph A with the label p has 0 weight edge to corresponding graph B node.
# cal

## Portuguese

### Theme 1: A procura de um lugar para estacionar

Numa cidade, existem diversos locais de estacionamento público: lugares em estrada (parquímetro) ou garagens. O valor do estacionamento varia de local para local.

Neste trabalho, pretende-se implementar um sistema que auxilie um automobilista na procura de um lugar de estacionamento. Um automobilista pretende ir a um local específico (cinema, escola, shopping,...) e quer estacionar o seu automóvel. Deve ser calculado o itinerário que permita ao automobilista ir do local onde se encontra ao estacionamento (de automóvel) e do estacionamento ao local de destino (a pé).

O local de estacionamento proposto pode ser o mais perto do destino ou o mais barato (dentro de uma distância máxima ao destino ou a uma estação de metro), de acordo com a escolha do automobilista. Considere também que o automobilista pode querer abastecer o seu automóvel antes de estacionar, pelo que o trajecto indicado deve considerar este facto.

Avalie a conectividade do grafo, a fim de evitar que locais de estacionamento se encontrem em zonas inacessíveis a partir do ponto de origem do automobilista.

Considere a possibilidade de utilizar mapas reais, extraídos do OpenStreetMaps (www.openstreetmap.org), localizando, no mapa, endereços e pontos de interesse.

## English

### Theme 1: Searching for a parking spot

In a city, there is a lot of parking spaces: Places on road (parking machines) or garages. The parking value changes from place to place.

In this work, you should implement a system that helps a driver in the search of parking place. A driver wants to go to a specific place (movies, schools, shopping mall...) and want to park his car. It should be calculated the route that allows the driver to go from where he is at to a parking place, and from the car to the destiny (walking).

The parking place could be the closest to the destiny or the cheapest (within a maximum distance to the destiny or to a metro station), it should be a driver's choice. Consider that the driver might want to fill up the car tank before parking, and the route should consider that.

Assess the graph connectivity, to avoid that parking places are in inaccesible zones from the origin point.

Consider the possibility to use real maps, extracted from OpenStreetMaps (www.openstreetmap.org), finding in the map, address and points of interest.

## The project

Lets assume that walking distance has more weight than than the driving distance. 
Walking distance weight = driving distance weight * C.

Lets assume that we have weighted, directed graph G.
Nodes of the graph are labeled as none(n), parking spot(p) and gas_station(s).

### Situation A: no need for visit the gas station. 

We are searching for the shortest path from Gx to Gy where one of nodes labeled as p has to be visited.

Lets assume two copies of graph G: A and B.

Graph A has nodes A1, A2 ... An.
Graph B has nodes B1, B2 ... Bn and weights multiplied by the coefficient C.

Each node of graph A with the label p has 0 weight edge to coresponding graph B node.

Now we can find the shortest path from Ax to By.

### Situation B: gas station has to be visited.

Observation: gas station has to be visited first.
Now lets assume three copies of graph G: A, B and C.

Each node of graph A with the label s has 0 weight edge to coresponding graph B node.
Each node of graph B with the label p has 0 weight edge to coresponding graph C node.

Now we can find the shortest path from Ax to Cy.

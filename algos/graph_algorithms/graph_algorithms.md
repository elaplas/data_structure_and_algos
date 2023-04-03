# Graph

A graph data structure is used to represent and manipulate the relations b/w objects, people and any things. A graph usually contains

- Nodes that can store different information e.g. the name, age, address and etc of a person. 

- Edges that show the relations b/w nodes e.g. an edge b/w two nodes representing two persons may show if they already met each others. An edge may store a value or information e.g. how many times two persons already met each others. 

- Neighbors (adjacency or adjacent nodes) that are the connecting nodes of a node e.g. if persons "a", "b" are connected to person "c" in a graph, the persons "a" and "b" are the neighbors of "c".

## Example applications of graph
- Showing the relations b/w persons
- Representing the connectivity b/w cities and how far each city is from the other one
- Managing the dependencies b/w packages in a building tool/system

## Graph implementation
- Implemented as a adjacency matrix where the rows and columns represent the nodes. If a node is connected to another node (there is edge b/w them), the corresponding element in the matrix is set to 1 otherwise to 0. The elements on the diagonal are all zeros unless the nodes would have edges starting from themselves and ending to themselves. Each edge shows up twice in the matrix.

- Using two maps "nodes" and "edges" to store the connectivity and the edge information respectively e.g. nodes[node_i] = [node_1, node_2, ..., node_n] , edges[(node_i, node_j)] = data

- Defining a node type that consists of the information about the node and its neighboring nodes (children). The addition and removal of the node and their edges can be managed through a separate class. 

## Traversal algos
- Deep first search (iterative approach) which requires a stack data structure to store the previously visited nodes sequentially. If all connecting nodes of a node are visited and there are no other exploring possibilities, then we should take the stored nodes from the stack to continue exploring. 

- Deep first search (recursive approach) which doesn't need a stack data structure because the stack storage is provided by the system

- Breadth first search which explores the connecting nodes of each node first using a queue data structure
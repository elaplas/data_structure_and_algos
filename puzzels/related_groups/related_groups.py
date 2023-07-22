
'''
/**
 * input (a matrix of string showing relations b/w people. People are symbolized by indices)
 * output: number of groups that have direct or indirect relations for example if '0' is related to '1',
 *  and '1' is related to '2', then '0' and '2' are indirectly related
 *
 * input: [ "11000", "11100", "01100", "00010", "00001"]
 * output: three related groups: {[0,1,2], [3], [4]}
 *
 * input: [ "10000", "01000", "00100", "00010", "00001"]
 * output: five groups: {[0], [1], [2], [3], [4]}
 *
 */

'''


'''
The idea: The relations between people can be imagined as a graph (nodes are people and the relations are edges).
If we traverse the graph starting from each node and store the visited nodes, then we can figure out all related 
people and consequently also the number of groups. 

The graph can be represented as a matrix, so we can directly use the input (list of strings)
we use deep first search for traversing the graph

'''


def related_groups(list_str):
    visited = set()
    related_groups = []
    for i in range(len(list_str)):
        res = []
        DFS(list_str, visited, i, res)
        if len(res):
            related_groups.append(res)
    return related_groups

def DFS(graph, visited, node, res):
    
    # In DFS the current node is added to the result at the end of function
    # but in this case we need to add it in the beginning of the function
    # to avoid adding redundant groups
    if node not in visited:
        visited.add(node)
        res.append(node)

    # Get neighbors or edges
    neighbors = [] 
    for col in range(len(graph)):
        if graph[node][col] == '1':
            neighbors.append(col)
    
    for neighbor in neighbors:
        if neighbor not in visited:
            DFS(graph, visited, neighbor, res)


list_strs = ["11000", "11100", "01100", "00010", "00001"]
res = related_groups(list_strs)
print(res)


list_strs =[ "10000", "01000", "00100", "00010", "00001"]
res = related_groups(list_strs)
print(res)


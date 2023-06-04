
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


def related_groups(list_strs):
    
    res = []
    visited = set()
    for node in range(len(list_strs)):
        res_i = dfs(node, list_strs, visited)
        if len(res_i):
            res.append(res_i)

    return len(res), res

def get_neighbors(node, list_strs):
    
    neighbors = []
    row = list_strs[node]
    for i in range(len(row)):
        if i != node and row[i] == '1':
            neighbors.append(i)
    
    return neighbors

def dfs(node, list_strs, visited):

    related_nodes = []
    if node not in visited:
        related_nodes.append(node)
        visited.add(node)
    
    neighbors = get_neighbors(node, list_strs)

    for neighbor in neighbors:
        if neighbor not in visited:
            res = dfs(neighbor, list_strs, visited)
            for el in res:
                related_nodes.append(el)

    return related_nodes


list_strs = ["11000", "11100", "01100", "00010", "00001"]
res = related_groups(list_strs)
print(res)


list_strs =[ "10000", "01000", "00100", "00010", "00001"]
res = related_groups(list_strs)
print(res)


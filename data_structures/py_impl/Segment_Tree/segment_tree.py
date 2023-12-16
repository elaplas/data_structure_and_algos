
"""
Segment tree is a data structure that enables querying in a range in time complexity O(logn)

Problem: Finding the minimum in any range of array [-1, 2, 4, 0] takes O(n) by traversing through
the range. Can we improve the run-time of the traversal? The actual problem is to construct 
a segment tree, query and update it. 


Solution: From the given array a segment tree is built where finding the minimum in a given range needs to 
traverse only through the height of the tree, which is logn. Below the left tree contains minimums in the
ranges shown on the right tree. 


             -1                         [0,3]                
          /       \                    /     \  
        -1         0                [0,1]    [2,3]
        /  \      /  \              /   \     /   \
      -1    2    4    0        [0,0]  [1,1] [2,2] [3,3]


"""
import math


class SegmentTree:
    def __init__(self, arr):
        self.arr = arr
        self.tree_size = 2*len(arr) + 1
        self.segment_tree = [float('inf') for _ in range(self.tree_size)]
        self.construct_tree(0, len(self.arr)-1, 0)

    
    def construct_tree(self, start_range, end_range, pos_node):

        if start_range==end_range:
            self.segment_tree[pos_node] = self.arr[start_range]
            return 

        left_pos_node = pos_node*2 + 1
        right_pos_node = pos_node*2 + 2 
        mid_range = (start_range + end_range)//2
        self.construct_tree(start_range, mid_range, left_pos_node)
        self.construct_tree(mid_range+1, end_range, right_pos_node)
        self.segment_tree[pos_node] = min(self.segment_tree[left_pos_node], self.segment_tree[right_pos_node])


    def query_segment(self, start_query, end_query):
        return self.query_segment_helper(start_query, end_query, 0, len(self.arr)-1, 0)


    def query_segment_helper(self, start_query, end_query, start_range, end_range, pose_node):

        if end_query < start_range or start_query > end_range:
            return float('inf')

        if start_range >= start_query and end_range <= end_query:
            return self.segment_tree[pose_node]

        mid_range = (start_range + end_range)//2 
        pose_node_left = pose_node*2+1 
        pose_node_right = pose_node*2+2

        left_result = self.query_segment_helper(start_query, end_query, start_range, mid_range, pose_node_left) 
        right_result = self.query_segment_helper(start_query, end_query, mid_range+1, end_range, pose_node_right) 
        return min(left_result, right_result)

    def update(self, arr_index, val):
        # Update array
        self.arr[arr_index] = val
        # Calculate respective tree index
        start_range = 0
        end_range = len(self.arr)-1
        tree_index = 0
        while start_range != end_range:
            mid = (start_range+end_range)//2
            if arr_index <= mid:
                tree_index = tree_index*2+1
                end_range = mid
            else:
                tree_index = tree_index*2+2
                start_range = mid+1
        # Update tree
        self.segment_tree[tree_index] = val
        parent_node = (tree_index-1)//2
        while parent_node >= 0:
            if self.segment_tree[parent_node] > val:
                self.segment_tree[parent_node] = val
            parent_node = (parent_node-1)//2



arr = [-1, 2, 4, 0]
segment_tree = SegmentTree(arr)
print(segment_tree.segment_tree)
res = segment_tree.query_segment(1,3)
print(res)
segment_tree.update(2, -10)
print(segment_tree.segment_tree)
res = segment_tree.query_segment(1,3)
print(res)
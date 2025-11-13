# PROBLEM TITLE 
Write a Program to Implement A* Search. 

---

# OBJECTIVE OF THE PROGRAM 
To implement the A* search algorithm and use it to solve a pathfinding problem in a grid, demonstrating the efficiency of informed search strategies. 

---

# DESCRIPTION 
A* search is an informed search algorithm that uses both the cost to reach the node (g) and a heuristic estimate of the cost to reach the goal (h). The algorithm expands the node with the lowest estimated total cost f(n) = g(n) + h(n). A* is optimal and complete when the heuristic used is admissible (never overestimates the cost). 

---

# ALGORITHM  
1. Initialize the open list with the start node. 
2. Loop until the open list is empty: 
        a. Select the node with the lowest f(n) value. 
        b. If this node is the goal, reconstruct the path and return it. 
        c. Otherwise, generate the node's neighbors and calculate their g, h, 
        and f values. 
        d. Add the neighbors to the open list if they have not been visited or if 
        a lower-cost path to the node is found. 
3. If the open list is empty and no solution is found, return failure.
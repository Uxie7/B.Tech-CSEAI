# PROBLEM TITLE 
Solve the 8-Puzzle Problem Using Best-First Search.

---

# OBJECTIVE OF THE PROGRAM 
To implement the Best-First Search algorithm to solve the 8-puzzle problem and 
understand heuristic-driven search strategies. 

---

# DESCRIPTION 
- The 8-puzzle is a classic problem in AI, where the goal is to move tiles on a 3x3 grid to achieve a specific configuration. Best-First Search selects the most promising node based on a heuristic function (h(n)), exploring nodes with the 
lowest heuristic cost first. 

---

# ALGORITHM  
1. Initialize the open list with the start node. 
2. Loop until the open list is empty: 
        a. Select the node with the lowest heuristic value. 
        b. If this node is the goal, reconstruct the path and return it. 
        c. Otherwise, generate the node's neighbors by sliding tiles. 
        d. Add the neighbors to the open list based on their heuristic values. 
3. If the open list is empty and no solution is found, return failure.
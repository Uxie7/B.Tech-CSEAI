# PROBLEM TITLE 
Write a Program to Implement Depth-First Search (for Water Jug Problem). 

---

# OBJECTIVE OF THE PROGRAM 
To implement the Depth-First Search (DFS) algorithm to solve the Water Jug Problem, where the goal is to measure a specific amount of water using two jugs of different capacities. 

---

# DESCRIPTION 
Depth-First Search (DFS) is an uninformed search algorithm that explores as far as possible along a branch before backtracking. It's useful for problems with deep solutions but doesn't guarantee the shortest path. 

---

# ALGORITHM  
1. Start with the initial state (empty jugs). 
2. Mark the current node as visited and explore its unvisited neighbours 
recursively. 
3. If a goal state is reached (desired amount of water), return the solution. 
4. If no solution is found, backtrack to explore other paths.
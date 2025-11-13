# PROBLEM TITLE 
Write a Program to Implement Breadth-First Search (for Tic-Tac-Toe Problem). 

---

# OBJECTIVE OF THE PROGRAM 
To implement the Breadth-First Search (BFS) algorithm and use it to explore the state space of the Tic-Tac-Toe problem. 

---

# DESCRIPTION 
Breadth-First Search (BFS) is an uninformed search algorithm that explores the state space level by level. It is particularly useful in scenarios where the solution is not too deep from the initial state, as it guarantees the shortest path to the goal. 

---

# ALGORITHM  
1. Initialize the BFS queue with the initial state. 
2. Loop until the queue is empty: 
        a. Dequeue the front node. 
        b. If the node represents a goal state, return the solution. 
        c. Otherwise, enqueue all possible child nodes (next states). 
3. If the queue is empty and no solution is found, return failure.
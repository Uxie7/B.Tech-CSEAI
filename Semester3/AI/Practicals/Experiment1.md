# PROBLEM TITLE 
Implement a Simple Reflex Agent and a Model-Based Reflex Agent in a Simulated Environment 

---

# OBJECTIVE OF THE PROGRAM 
To understand the basic principles of intelligent agents by implementing a simple reflex agent and a model-based reflex agent in a simulated environment. 

---

# DESCRIPTION 
An intelligent agent perceives its environment through sensors and acts upon it through actuators. A simple reflex agent selects actions based on the current percept, ignoring the rest of the percept history. In contrast, a model-based reflex agent maintains an internal state to keep track of the world and make decisions based on the current state and percept. 

---

# ALGORITHM  

Simple Reflex Agent: 
1. Initialize the agent with a set of condition-action rules. 
2. Observe the current percept. 
3. Apply the rule that matches the current percept. 
4. Execute the corresponding action. 


Model-Based Reflex Agent: 
1. Initialize the agent with a set of condition-action rules and an internal state. 
2. Observe the current percept. 
3. Update the internal state based on the percept. 
4. Apply the rule that matches the current state. 
5. Execute the corresponding action.
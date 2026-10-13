# UNIT II — Knowledge-Based Recommendation

---

## Sections

1. [Knowledge Representation and Reasoning (KRR)](#1-knowledge-representation-and-reasoning-krr)
2. [Constraint-Based Recommenders](#2-constraint-based-recommenders)
3. [Case-Based Recommenders](#3-case-based-recommenders)
4. [Difference between constraint-based and case-based recommenders](#4-difference-between-constraint-based-and-case-based-recommenders)

---

## 1. Knowledge Representation and Reasoning (KRR)

### Definition

Knowledge Representation and Reasoning (KRR) is the process of representing information about a domain in a structured form and applying logical rules or reasoning techniques to derive conclusions and make recommendations.

In a recommender system, KRR represents information about users, products, their attributes, relationships, and requirements to identify suitable items.

### Components

- **Knowledge representation:** Stores domain knowledge in a structured form, such as facts, rules, ontologies, or constraints.
- **Reasoning:** Applies rules and logical operations to the stored knowledge to infer new information or determine suitable recommendations.
- **Recommendation generation:** Uses the conclusions drawn through reasoning to recommend items that meet the user's requirements.

### Types of knowledge representation

| Type | Explanation | Example |
|---|---|---|
| Facts | Store known information about objects. | A laptop has 16 GB RAM. |
| Rules | Express conditions and their consequences. | IF budget is below ₹60,000, THEN exclude laptops above ₹60,000. |
| Ontologies | Define concepts and relationships within a domain. | A gaming laptop is a type of laptop. |
| Constraints | Specify conditions that a recommended item must satisfy. | Battery life must be at least 8 hours. |

### Working of KRR in a recommender system

```text
User requirements and domain knowledge
Budget, preferences, item attributes, rules
                  ↓
Knowledge representation
Facts, rules, relationships, constraints
                  ↓
Reasoning engine
Applies rules and checks requirements
                  ↓
Recommended items
Items that satisfy the requirements
```

### Example

Suppose a user wants a laptop with a budget of ₹70,000, at least 16 GB RAM, and a minimum battery life of 8 hours.

The system stores the specifications of available laptops and applies the user's requirements as rules. A laptop priced at ₹65,000 with 16 GB RAM and 10-hour battery life satisfies all three conditions and can be recommended.

### Advantages

- Makes recommendations based on explicit requirements.
- Can explain why an item satisfies the user's needs.
- Works even when historical ratings are unavailable.
- Supports complex requirements and domain-specific rules.

### Limitations

- Requires domain knowledge to be collected and maintained.
- Designing rules and relationships can be time-consuming.
- Incomplete or outdated knowledge can produce poor recommendations.

**Exam point:** Knowledge representation specifies what the system knows; reasoning specifies how the system uses that knowledge to reach conclusions.

---

## 2. Constraint-Based Recommenders

### Definition

A constraint-based recommender system recommends items by matching the user's explicitly stated requirements with predefined constraints on item attributes. It uses domain knowledge and logical rules to eliminate items that do not satisfy the specified conditions.

It is particularly useful when users have specific requirements, such as a price limit, minimum performance, preferred location, or required features.

### Important concepts

1. **Constraints:** Conditions that items must satisfy or preferably satisfy.
    - **Hard constraints:** Mandatory conditions. An item violating a hard constraint is rejected.
    - **Soft constraints:** Desirable conditions. An item violating a soft constraint may still be recommended, but usually receives a lower preference score.
2. **User requirements:** The needs or conditions provided by the user.
3. **Item database:** Stores item attributes, such as price, specifications, category, and availability.
4. **Constraint evaluation:** Checks whether each item satisfies the user's conditions.
5. **Recommendation ranking:** Orders the eligible items according to soft constraints, preferences, or other ranking criteria.

### Architecture / working

```text
User specifies requirements
            ↓
Translate requirements into constraints
            ↓
Evaluate items against hard constraints
            ↓
Rank eligible items using soft constraints
            ↓
Recommend suitable items
```

### Step-by-step example

**Problem:** A user wants to purchase a laptop with these requirements:

- Budget: at most ₹70,000
- RAM: at least 16 GB
- Battery life: at least 8 hours

The system has the following laptop database:

| Laptop | Price | RAM | Battery | Result |
|---|---|---|---|---|
| A | ₹65,000 | 16 GB | 10 hours | Eligible |
| B | ₹75,000 | 16 GB | 10 hours | Rejected |
| C | ₹60,000 | 8 GB | 12 hours | Rejected |
| D | ₹68,000 | 16 GB | 7 hours | Rejected |

**Step 1: Define the constraints.**

$$
\begin{aligned}
\text{Price} &\leq 70{,}000\\
\text{RAM} &\geq 16\text{ GB}\\
\text{Battery} &\geq 8\text{ hours}
\end{aligned}
$$

**Step 2: Evaluate each item.**

- Laptop A satisfies all three constraints.
- Laptop B violates the budget constraint.
- Laptop C violates the RAM constraint.
- Laptop D violates the battery constraint.

**Step 3: Generate recommendations.**

Only Laptop A satisfies all mandatory requirements, so it is recommended.

### Advantages

1. **Suitable for first-time users:** Recommendations do not require previous ratings or purchase history.
2. **Handles specific needs:** Users can define detailed requirements.
3. **Transparent recommendations:** The system can explain why an item qualifies or gets rejected.
4. **Reduces irrelevant results:** Hard constraints eliminate unsuitable items.
5. **Useful for complex products:** Works well for cars, laptops, houses, financial products, and travel planning.

### Limitations

1. **Knowledge acquisition:** Domain experts may be needed to define valid constraints.
2. **Limited flexibility:** Strict constraints can eliminate otherwise useful alternatives.
3. **No suitable match:** The system may return no recommendations if requirements are too restrictive.
4. **Maintenance overhead:** Constraints and item information must be updated as products and user needs change.

### Applications

- Laptop and smartphone selection
- Real estate recommendation
- Car purchasing
- Travel and hotel planning
- Financial product selection

**Exam point:** A constraint-based recommender primarily checks whether items satisfy explicitly specified requirements. It does not necessarily learn a user's preferences from historical ratings.

---

## 3. Case-Based Recommenders

### Definition

A case-based recommender system recommends items by identifying previously solved cases that are similar to the user's current problem and adapting their solutions to suit the current requirements.

A case generally consists of a problem description, its relevant attributes, and a solution or outcome.

Instead of relying exclusively on predefined constraints, the system uses experience from earlier cases to solve new recommendation problems.

### Components of a case

A case may contain:

- **Problem description:** The original user's requirements.
- **Attributes:** Relevant characteristics of the problem.
- **Solution:** The item or decision that was recommended.
- **Outcome or feedback:** Whether the solution worked well, when such information is available.

For example, a previous laptop-purchasing case might contain a budget of ₹60,000, a requirement for 16 GB RAM, and the laptop ultimately selected.

### The four R's of case-based reasoning

The most important concept for exams is the 4R cycle.

1. **Retrieve:** Find previous cases similar to the current user's requirements using attributes or similarity measures.
2. **Reuse:** Use the solution from the retrieved case, adapting it when necessary for the current user.
3. **Revise:** Evaluate the proposed solution and modify it if it does not adequately satisfy the current requirements.
4. **Retain:** Store the successful new case in the case base so that it can help solve similar problems in the future.

The cycle is commonly written as:

**Retrieve → Reuse → Revise → Retain**

### Working of a case-based recommender

1. The user submits a new recommendation problem.
2. The system compares the new problem with previously stored cases.
3. It retrieves the most similar cases.
4. The solutions of those cases are reused or adapted.
5. The proposed recommendation is evaluated and revised if required.
6. The new case and its outcome may be retained for future use.

### Step-by-step example

**Problem:** A user wants a laptop for programming with a budget of ₹65,000 and at least 16 GB RAM.

The system has two previous cases:

| Case | Budget | RAM | Previous solution |
|---|---|---|---|
| Case 1 | ₹60,000 | 16 GB | Laptop P |
| Case 2 | ₹90,000 | 32 GB | Laptop Q |

**Step 1: Retrieve.**

The system compares the current requirements with stored cases. Case 1 is more similar because its budget and RAM requirements are closer to the new problem.

**Step 2: Reuse.**

The system considers Laptop P as a starting recommendation.

**Step 3: Revise.**

It checks whether Laptop P is still available and whether its specifications satisfy the current user's needs. If not, it adapts the recommendation to a more suitable model.

**Step 4: Retain.**

After receiving feedback about the final recommendation, the system stores the new case and its outcome for possible future reuse.

**Note:** This example illustrates the process; it does not assume that Laptop P is actually available or that the user accepted it.

### Similarity measurement

A case-based recommender may use a similarity measure to retrieve relevant cases.

For numerical attributes, Euclidean distance is one possible choice:

$$
d(x,y)=\sqrt{\sum_{i=1}^{n}(x_i-y_i)^2}
$$

Smaller distances indicate greater similarity when attributes are appropriately scaled.

For mixed attributes, a weighted similarity function can be used:

$$
\operatorname{Sim}(x,y)=
\frac{\sum_{i=1}^{n}w_i s_i(x,y)}
{\sum_{i=1}^{n}w_i}
$$

Where:

- $w_i$ is the importance of attribute $i$.
- $s_i(x,y)$ is the similarity between the two cases for that attribute.

For example, budget may receive a higher weight than color when recommending laptops for programming.

### Advantages

1. **Uses previous experience:** Past solutions help solve new recommendation problems.
2. **Supports explanations:** The system can explain recommendations by referring to similar previous cases.
3. **Adaptability:** Existing solutions can be modified for new requirements.
4. **Incremental learning:** New cases can be added without redesigning the entire system.
5. **Useful for complex problems:** Particularly effective when expert experience and successful past decisions are available.

### Limitations

1. **Dependence on past cases:** Recommendations may be poor when the case base contains few relevant examples.
2. **Case retrieval complexity:** Finding similar cases can become expensive as the case base grows.
3. **Adaptation difficulty:** A previous solution may not transfer directly to a new problem.
4. **Case maintenance:** Outdated, duplicate, or unsuccessful cases may reduce recommendation quality.
5. **Similarity design:** The choice of attributes, weights, and similarity measure significantly affects results.

### Applications

- Travel and holiday planning
- Product selection
- Medical decision support
- Troubleshooting and technical support
- Financial planning
- Personalized service recommendations

**Exam point:** Case-based recommendation relies on previously solved, similar problems and adapts their solutions. The 4R cycle is a key point to remember.

---

## 4. Difference between constraint-based and case-based recommenders

| Basis | Constraint-Based Recommender | Case-Based Recommender |
|---|---|---|
| Fundamental principle | Matches items against explicitly defined requirements and constraints. | Finds similar past cases and adapts their solutions. |
| Main knowledge source | Domain rules, item attributes, and user constraints. | A case base containing previous problems and their solutions. |
| Recommendation process | Evaluates whether items satisfy hard and soft constraints. | Retrieves, reuses, revises, and retains cases. |
| Role of history | Can work without historical user interactions. | Depends on the availability of relevant previous cases. |
| Adaptation | Relies on changing constraints or ranking preferences. | Adapts a previously successful solution to a new problem. |
| Explanation | Explains which constraints an item satisfies or violates. | Explains the recommendation using similar previous cases. |
| Main challenge | Defining and maintaining appropriate constraints. | Retrieving useful cases and adapting their solutions. |
| Example | Selecting a house within a budget and minimum area requirement. | Recommending a house based on similar buyers' previous cases. |

---

## Quick revision

**1. What is the difference between knowledge representation and reasoning?**

Knowledge representation stores domain knowledge in a structured form; reasoning applies that knowledge to draw conclusions.

**2. What are hard and soft constraints?**

Hard constraints are mandatory conditions; soft constraints are desirable preferences that can be used for ranking.

**3. What are the four R's of case-based reasoning?**

Retrieve, Reuse, Revise, Retain.

**4. Can a constraint-based recommender work without past ratings?**

Yes. It can use explicit requirements, domain knowledge, and item attributes.

**5. What happens during the revise step?**

The proposed solution is evaluated and modified if necessary.

**6. What happens during the retain step?**

The new case and its outcome may be stored for future recommendations.

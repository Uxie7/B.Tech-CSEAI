# UNIT I — Collaborative Filtering

---

## Sections

1. [Introduction to Collaborative Filtering](#1-introduction-to-collaborative-filtering)
2. [User-Based Nearest-Neighbour CF](#2-user-based-nearest-neighbour-cf)
3. [Item-Based Nearest-Neighbour CF](#3-item-based-nearest-neighbour-cf)
4. [Model-Based Collaborative Filtering](#4-model-based-collaborative-filtering)
5. [Preprocessing Approaches in CF](#5-preprocessing-approaches-in-cf)
6. [Attacks on Collaborative Filtering](#6-attacks-on-collaborative-filtering)
7. [General Issues in Collaborative Filtering](#7-general-issues-in-collaborative-filtering)
8. [Explicit and implicit feedback](#8-explicit-and-implicit-feedback)
9. [Additional numerical practice](#9-additional-numerical-practice)

---

## 1. Introduction to Collaborative Filtering

**Definition:** Collaborative Filtering (CF) is a recommendation technique that predicts a user's interests by analysing ratings, preferences, or interactions from multiple users.

**Basic assumption:** Users who have shown similar preferences in the past may have similar preferences in the future.

**Example:** If two users both enjoy several of the same films, a film liked by one user may be recommended to the other.

Unlike content-based filtering, CF primarily uses user–item interactions rather than item attributes such as genre, description, or keywords.

### Types of Collaborative Filtering

| Type | Principle | Example |
|---|---|---|
| User-based nearest-neighbour | Find users with similar preferences. | Recommend films liked by similar users. |
| Item-based nearest-neighbour | Find items with similar rating patterns. | Recommend films that receive ratings similar to films the user likes. |
| Model-based | Learn patterns from historical interactions. | Predict preferences using matrix factorisation. |
| Preprocessing-based | Prepare or transform interaction data before recommendation. | Normalise ratings before calculating similarity. |

---

## 2. User-Based Nearest-Neighbour CF

### 2.1 Principle and working

User-based CF finds users whose rating patterns resemble those of the target user. It uses their ratings to predict the target user's preferences for unseen items.

The steps are:

1. Construct the user–item rating matrix.
2. Select the target user.
3. Calculate similarity between the target user and other users.
4. Select the most relevant neighbours.
5. Predict ratings for unseen items.
6. Rank items and recommend the highest-scoring candidates.

### 2.2 Similarity measures

#### A. Cosine similarity

Measures the angle between two rating vectors.

$$
\operatorname{sim}(u,v)=
\frac{\mathbf r_u\cdot\mathbf r_v}
{\|\mathbf r_u\|\|\mathbf r_v\|}
$$

The dot product is divided by the product of the vectors' magnitudes. In a sparse rating matrix, similarity is usually computed using co-rated items or a suitable adjusted representation.

#### B. Pearson correlation

Measures whether two users' ratings vary together, accounting for differences in their rating levels.

$$
\operatorname{sim}(u,v)=
\frac{\sum_{i\in I_{uv}}(r_{ui}-\bar r_u)(r_{vi}-\bar r_v)}
{\sqrt{\sum_{i\in I_{uv}}(r_{ui}-\bar r_u)^2}
\sqrt{\sum_{i\in I_{uv}}(r_{vi}-\bar r_v)^2}}
$$

Here, $I_{uv}$ is the set of items rated by both users, and $\bar r_u,\bar r_v$ are their respective mean ratings. The exact mean convention should be applied consistently with the method being used.

**Interpretation:**

- $+1$: perfectly positively correlated rating patterns.
- $0$: no linear correlation.
- $-1$: perfectly negatively correlated rating patterns.

Pearson correlation can be more informative than raw cosine similarity when users have different rating habits.

### 2.3 Exam-style numerical 1 — Calculate cosine similarity

**Question:** Two users have rated three common movies as follows. Calculate their cosine similarity.

| Movie | User A | User B |
|---|---|---|
| M1 | 5 | 4 |
| M2 | 1 | 2 |
| M3 | 4 | 3 |

**Step 1: Write the vectors.**

$$
\mathbf r_A=[5,1,4],\qquad
\mathbf r_B=[4,2,3]
$$

**Step 2: Calculate the dot product.**

$$
\mathbf r_A\cdot\mathbf r_B
=5(4)+1(2)+4(3)=34
$$

**Step 3: Calculate the magnitudes.**

$$
\|\mathbf r_A\|=\sqrt{5^2+1^2+4^2}=\sqrt{42}
$$

$$
\|\mathbf r_B\|=\sqrt{4^2+2^2+3^2}=\sqrt{29}
$$

**Step 4: Substitute into the formula.**

$$
\operatorname{sim}(A,B)
=\frac{34}{\sqrt{42}\sqrt{29}}
$$

$$
\boxed{\operatorname{sim}(A,B)\approx0.974}
$$

**Conclusion:** The users have highly similar rating vectors under cosine similarity.

### 2.4 Exam-style numerical 2 — Calculate Pearson correlation

**Question:** Two users give the following ratings to two common movies. Calculate the Pearson correlation.

| Movie | User A | User B |
|---|---|---|
| M1 | 5 | 1 |
| M2 | 1 | 5 |

**Step 1: Calculate means over these common items.**

$$
\bar r_A=\frac{5+1}{2}=3,\qquad
\bar r_B=\frac{1+5}{2}=3
$$

**Step 2: Calculate deviations from the means.**

- User A: $5-3=2,\ 1-3=-2$
- User B: $1-3=-2,\ 5-3=2$

**Step 3: Calculate the numerator.**

$$
2(-2)+(-2)(2)=-8
$$

**Step 4: Calculate the denominator.**

$$
\sqrt{(2^2+(-2)^2)( (-2)^2+2^2)}
=\sqrt{8\times8}=8
$$

**Step 5: Calculate the correlation.**

$$
\boxed{\operatorname{sim}(A,B)=-8/8=-1}
$$

**Conclusion:** The users have perfectly opposite rating patterns on these two movies.

### 2.5 Rating prediction formula

After calculating similarity, the system predicts the rating of an unseen item using the neighbours' ratings.

A common mean-centred formula is:

$$
\hat r_{ui}=\bar r_u+
\frac{\sum_{v\in N(u)}\operatorname{sim}(u,v)(r_{vi}-\bar r_v)}
{\sum_{v\in N(u)}|\operatorname{sim}(u,v)|}
$$

Where:

- $\hat r_{ui}$: predicted rating of user $u$ for item $i$.
- $\bar r_u$: target user's mean rating.
- $N(u)$: selected neighbours who rated item $i$.
- $r_{vi}$: neighbour $v$'s rating for item $i$.
- $\bar r_v$: neighbour $v$'s mean rating.

The formula starts with the target user's average and adjusts it based on how far the neighbours' ratings differ from their own averages.

### 2.6 Exam-style numerical 3 — Predict a rating

**Question:** User U1 has an average rating of 3.5. Two neighbours rated Movie X as shown below. Using the mean-centred prediction formula, predict U1's rating.

| Neighbour | Similarity to U1 | Neighbour mean | Rating for X |
|---|---|---|---|
| U2 | 0.8 | 4 | 5 |
| U3 | 0.6 | 3 | 4 |

**Step 1: Substitute the known values.**

$$
\hat r_{U1,X}=3.5+
\frac{0.8(5-4)+0.6(4-3)}{|0.8|+|0.6|}
$$

**Step 2: Calculate the weighted deviations.**

$$
0.8(1)=0.8,\qquad 0.6(1)=0.6
$$

**Step 3: Add the numerator and denominator.**

$$
\text{Numerator}=0.8+0.6=1.4
$$

$$
\text{Denominator}=0.8+0.6=1.4
$$

**Step 4: Calculate the prediction.**

$$
\hat r_{U1,X}=3.5+\frac{1.4}{1.4}
$$

$$
\boxed{\hat r_{U1,X}=4.5}
$$

**Conclusion:** The predicted rating is 4.5 out of 5. If the computed prediction falls outside the allowed rating scale, a system may clip it to the permitted range.

### 2.7 Case study — Movie recommendation platform

**Possible exam question:** A movie platform wants to recommend films to a user based on the preferences of similar users. Explain how user-based Collaborative Filtering can be applied.

**Answer:**

1. The platform constructs a user–movie matrix from historical ratings.
2. It selects the target user and identifies movies rated by both that user and other users.
3. It calculates similarities using cosine similarity or Pearson correlation.
4. It selects the most relevant neighbours.
5. It uses the neighbours' ratings to predict the target user's ratings for unseen movies.
6. It ranks the movies by predicted rating and recommends the highest-ranked candidates.

**Advantages:** It can discover interests not explicitly represented by movie descriptions.

**Limitations:** It struggles with sparse ratings, new users, and changes in user preferences.

This is an illustrative case study, not a claim about a particular company's production implementation.

---

## 3. Item-Based Nearest-Neighbour CF

### 3.1 Principle

Item-based CF calculates similarity between items using the rating patterns they receive from users. It then recommends items that are similar to those the target user has already rated highly.

For example, if users who rate Movie A highly also tend to rate Movie B highly, Movie B may be recommended to someone who liked Movie A.

Unlike content-based filtering, the similarity is based primarily on interaction data, not necessarily on genre or descriptive features.

### 3.2 Working

1. Construct the user–item rating matrix.
2. Represent each item by its ratings from users.
3. Calculate item-to-item similarities.
4. Find similar items that the target user has already rated.
5. Estimate the rating of an unseen item.
6. Rank candidate items and generate recommendations.

### 3.3 Item similarity formula

For item vectors $i$ and $j$:

$$
\operatorname{sim}(i,j)=
\frac{\mathbf r_i\cdot\mathbf r_j}
{\|\mathbf r_i\|\|\mathbf r_j\|}
$$

The vectors contain ratings given by users to each item. Missing ratings must be handled appropriately; they should not automatically be treated as zero.

### 3.4 Exam-style numerical 4 — Calculate item similarity

**Question:** Three users rate two movies as follows. Calculate the cosine similarity between Movie A and Movie B.

| User | Movie A | Movie B |
|---|---|---|
| U1 | 5 | 4 |
| U2 | 4 | 5 |
| U3 | 1 | 2 |

**Step 1: Form the item vectors.**

$$
\mathbf r_A=[5,4,1],\qquad
\mathbf r_B=[4,5,2]
$$

**Step 2: Calculate the dot product.**

$$
\mathbf r_A\cdot\mathbf r_B=5(4)+4(5)+1(2)=42
$$

**Step 3: Calculate the magnitudes.**

$$
\|\mathbf r_A\|=\sqrt{25+16+1}=\sqrt{42}
$$

$$
\|\mathbf r_B\|=\sqrt{16+25+4}=\sqrt{45}
$$

**Step 4: Calculate cosine similarity.**

$$
\operatorname{sim}(A,B)=\frac{42}{\sqrt{42}\sqrt{45}}
$$

$$
\boxed{\operatorname{sim}(A,B)\approx0.966}
$$

**Conclusion:** The two movies have highly similar rating vectors according to cosine similarity.

### 3.5 Rating prediction formula

A common basic item-based prediction formula is:

$$
\hat r_{ui}=
\frac{\sum_{j\in N(i;u)}\operatorname{sim}(i,j)r_{uj}}
{\sum_{j\in N(i;u)}|\operatorname{sim}(i,j)|}
$$

Here, $N(i;u)$ denotes items similar to target item $i$ that user $u$ has already rated.

### 3.6 Exam-style numerical 5 — Predict a rating using item similarities

**Question:** A user rated Item A as 5 and Item B as 3. Their similarities to an unrated target Item X are 0.9 and 0.6, respectively. Predict the rating for X using the basic item-based formula.

| Previously rated item | User's rating | Similarity to X |
|---|---|---|
| A | 5 | 0.9 |
| B | 3 | 0.6 |

**Step 1: Substitute the values.**

$$
\hat r_{uX}=\frac{0.9(5)+0.6(3)}{0.9+0.6}
$$

**Step 2: Calculate the weighted ratings.**

$$
0.9(5)=4.5,\qquad 0.6(3)=1.8
$$

$$
\text{Numerator}=4.5+1.8=6.3
$$

**Step 3: Calculate the denominator.**

$$
0.9+0.6=1.5
$$

**Step 4: Calculate the prediction.**

$$
\boxed{\hat r_{uX}=\frac{6.3}{1.5}=4.2}
$$

**Conclusion:** The predicted rating is 4.2 out of 5.

### 3.7 User-based vs. item-based CF

| Basis | User-based CF | Item-based CF |
|---|---|---|
| Similarity | Calculated between users. | Calculated between items. |
| Recommendation | Items liked by similar users. | Items similar to those the user liked. |
| Prediction | Uses neighbours' ratings of the target item. | Uses the user's ratings of similar items. |
| Computation | Can be costly with a very large user population. | Can be efficient when item relationships remain relatively stable. |
| Main challenge | User preferences can change. | New items may lack sufficient ratings. |

Both methods are typically classified as memory-based or neighbourhood-based CF.

### 3.8 Case study — E-commerce recommendations

**Possible exam question:** An online shopping platform wants to recommend products similar in rating behaviour to products a customer has already purchased and rated. Explain the use of item-based CF.

**Answer:**

1. The platform collects users' product ratings or interactions.
2. It builds item vectors from the interaction matrix.
3. It calculates similarities between products.
4. It identifies products similar to those rated highly by the customer.
5. It predicts the customer's ratings for unseen products using weighted similarities.
6. It ranks and recommends the most promising products.

**Advantages:** Item relationships can be reused across many users, and recommendations can remain relatively stable.

**Limitations:** New products lack interaction histories, and popularity or sparse ratings can distort similarity estimates.

---

## 4. Model-Based Collaborative Filtering

### 4.1 Definition

Model-based CF learns patterns from historical user–item interactions and uses the trained model to predict preferences or generate recommendations.

Unlike neighbourhood methods, it does not need to calculate all relevant user or item similarities afresh for every prediction.

### 4.2 Working

1. Collect historical ratings or interactions.
2. Prepare the data.
3. Train a recommendation model.
4. Use the learned parameters to estimate missing preferences.
5. Rank items and produce recommendations.
6. Retrain or update the model as new data becomes available.

### 4.3 Matrix factorisation

Matrix factorisation approximates a large user–item rating matrix using two lower-dimensional matrices:

$$
R\approx PQ^T
$$

Where:

- $R$: user–item rating matrix.
- $P$: matrix of user latent factors.
- $Q$: matrix of item latent factors.
- $PQ^T$: approximate reconstruction of the ratings.

A latent factor is a learned, hidden dimension of preference. It may capture an underlying pattern in how users rate items, without being explicitly labelled beforehand.

The predicted rating is commonly written as:

$$
\hat r_{ui}=\mathbf p_u^T\mathbf q_i
$$

Some models additionally include user and item biases.

### 4.4 Exam-style numerical 6 — Latent-factor prediction

**Question:** A model represents a user and an item using the following latent-factor vectors. Calculate their predicted score.

$$
\mathbf p_u=[0.8,0.6],\qquad
\mathbf q_i=[0.5,0.9]
$$

**Step 1: Write the dot product.**

$$
\hat r_{ui}=\mathbf p_u^T\mathbf q_i
$$

**Step 2: Multiply corresponding components and add.**

$$
\hat r_{ui}=0.8(0.5)+0.6(0.9)
$$

$$
=0.4+0.54
$$

$$
\boxed{\hat r_{ui}=0.94}
$$

**Conclusion:** The raw predicted score is 0.94. It is not automatically a rating on a 1–5 scale; the interpretation depends on the model's training and output transformation.

### 4.5 Important model-based approaches

**A. Matrix factorisation:** Learns compact representations of users and items from interaction data.

**B. SVD-based approaches:** Singular Value Decomposition is a matrix decomposition technique. Recommender systems use SVD-inspired matrix-factorisation methods to learn lower-dimensional representations and estimate missing ratings. Practical recommender implementations may differ from a direct SVD of the original sparse matrix.

**C. Clustering-based methods:** Group users or items according to interaction patterns, then use information from the relevant cluster to generate recommendations.

**D. Classification and probabilistic methods:** Predict whether a user is likely to click, purchase, or otherwise interact with an item, or estimate the probability of a positive preference.

### 4.6 Memory-based vs. model-based CF

| Memory-based | Model-based |
|---|---|
| Uses stored interaction data and neighbourhood similarity directly. | Learns model parameters from historical interactions. |
| Examples: user-based and item-based nearest neighbours. | Examples: matrix factorisation and clustering-based models. |
| Predictions depend on relevant neighbours and their ratings. | Predictions depend on the trained model. |
| Can be easier to explain through specific neighbours. | May capture hidden patterns but can be less directly interpretable. |
| Can require substantial similarity computation. | Requires training, but prediction may be efficient afterwards. |

### 4.7 Case study — Music recommendation

**Possible exam question:** A music platform has millions of user–song interactions and wants to learn hidden preference patterns. Explain how matrix factorisation can help.

**Answer:**

1. The platform forms a sparse user–song interaction matrix.
2. It factorises the matrix into lower-dimensional user and song representations.
3. It learns the latent factors from observed interactions.
4. It estimates a user's preference for an unheard song using the corresponding latent vectors.
5. It ranks songs by predicted preference and recommends suitable candidates.
6. The model is updated as new interactions become available.

**Advantages:** Can capture latent preference patterns and work with large interaction datasets.

**Limitations:** Training requires data and computation; new users and new songs still pose cold-start challenges. Latent factors may also be difficult to interpret.

---

## 5. Preprocessing Approaches in CF

Preprocessing prepares interaction data before similarity calculations or model training. It can improve consistency, data quality, and computational efficiency.

### 5.1 Rating normalisation

Users may use rating scales differently. For example, one user gives most films ratings of 4–5, while another tends to give ratings of 2–3.

Mean-centering transforms a rating as follows:

$$
r'_{ui}=r_{ui}-\bar r_u
$$

**Possible exam question:** A user has an average rating of 4 and rates a film as 5. Calculate the mean-centred rating.

$$
r'_{ui}=5-4=\boxed{1}
$$

The rating is one point above that user's average.

### 5.2 Binarisation

Binarisation converts numerical ratings into binary preference indicators using a threshold.

For threshold 4:

$$
b_{ui}=
\begin{cases}
1,&r_{ui}\geq4\\
0,&r_{ui}<4
\end{cases}
$$

**Possible exam question:** Convert ratings 5, 4, 3, and 1 into binary preferences using a threshold of 4.

| Original rating | Binary value |
|---|---|
| 5 | 1 |
| 4 | 1 |
| 3 | 0 |
| 1 | 0 |

The threshold depends on the application. A zero here means the rating fell below the chosen threshold, not necessarily that the user explicitly disliked the item.

### 5.3 Handling missing ratings

An absent rating generally means the user has not rated the item. It does not automatically mean dislike.

Common approaches include:

- Use only co-rated items when computing similarity.
- Ignore missing entries in calculations designed for sparse data.
- Estimate missing preferences with an appropriate trained model.
- Use methods designed for implicit feedback, such as clicks, views, or purchases.

**Possible exam question:** Why should missing ratings not automatically be replaced by zero?

**Answer:** Zero may represent an artificial dislike that the user never expressed. Treating all missing entries as zero can distort user/item vectors, similarity scores, and predictions.

### 5.4 Dimensionality reduction

A user–item matrix can contain millions of entries, most of which are missing. Dimensionality reduction represents the interaction data using fewer dimensions.

Examples include matrix factorisation and suitable SVD-based methods.

**Benefits:** Reduced representation size, potential computational savings, and discovery of latent preference patterns.

### 5.5 Data cleaning and preparation

- Remove duplicate or invalid interaction records.
- Standardise inconsistent rating formats.
- Filter inactive users or extremely rare items where justified.
- Separate training and test data to avoid evaluation leakage.
- Select a suitable representation for explicit ratings or implicit feedback.

**Exam conclusion:** Preprocessing improves the usability of interaction data, but inappropriate transformations can remove useful information or introduce bias.

---

## 6. Attacks on Collaborative Filtering

### 6.1 Definition

A shilling attack, also called a profile-injection attack, is an attempt to manipulate recommendations by inserting fabricated user profiles or ratings into a system.

### 6.2 Push and nuke attacks

- **Push attack:** Attempts to artificially increase a target item's rating or ranking.
- **Nuke attack:** Attempts to artificially decrease a target item's rating or ranking.

### 6.3 How an attack works

1. An attacker creates fabricated user profiles.
2. The profiles rate selected filler items and a target item strategically.
3. The CF algorithm processes the injected interactions alongside genuine ratings.
4. The fabricated profiles may influence similarity calculations or model training.
5. The target item's predicted rating or ranking may be manipulated.

### 6.4 Types of attacks

| Attack | Explanation |
|---|---|
| Random attack | Filler-item ratings follow a random or broadly distributed pattern. |
| Average attack | Filler ratings are chosen to resemble the average ratings of the respective items. |
| Bandwagon attack | The fabricated profiles rate popular items to appear similar to many genuine users. |
| Push attack | Describes the goal of promoting the target item. |
| Nuke attack | Describes the goal of damaging the target item. |

**Important distinction:** Push and nuke describe the objective, whereas random, average, and bandwagon describe profile-construction strategies.

### 6.5 Exam-style case study — Manipulated product ratings

**Possible exam question:** A seller creates fake accounts that rate its own product highly while rating competing products poorly. Identify the attack, explain its impact, and suggest countermeasures.

**Answer:**

- **Attack:** Profile-injection or shilling attack.
- **Objective:** Push the seller's product and nuke competing products.
- **Working:** Fake profiles introduce strategically chosen ratings, potentially altering neighbourhood similarities or learned preference patterns.
- **Impact:** Distorted rankings, reduced recommendation accuracy, unfair product exposure, and lower user trust.
- **Countermeasures:** Detect coordinated or abnormal rating patterns, limit the influence of suspicious profiles, use robust similarity methods, monitor sudden ranking changes, and evaluate the system against simulated attacks.

No single defence eliminates every possible attack, so multiple safeguards are usually needed.

---

## 7. General Issues in Collaborative Filtering

| Issue | Explanation | Example |
|---|---|---|
| Data sparsity | Most users interact with only a small fraction of available items. | Two users have too few common ratings for reliable similarity. |
| Cold start | A new user or item lacks sufficient interaction history. | A new user has not rated any films. |
| Scalability | Large user and item populations increase computation and storage requirements. | Calculating similarities across millions of users. |
| Synonymy | Distinct item identities can obscure similarities in underlying characteristics or roles. | Two near-identical products are treated as unrelated items because their IDs differ. |
| Shilling attacks | Fabricated profiles manipulate ratings and recommendations. | Fake accounts inflate a product's ranking. |
| Privacy | Interaction histories can reveal personal interests and behaviour. | A rating history reveals sensitive viewing preferences. |
| Popularity bias | Popular items can receive disproportionate exposure. | Less popular but relevant items are rarely recommended. |

### Exam-style question — Discuss the limitations of CF

**Answer structure for a 5-mark question:**

Define Collaborative Filtering briefly, then explain at least four relevant limitations: sparsity, cold start, scalability, and shilling attacks. Add an example for each and conclude that performance depends on interaction-data quality, algorithm choice, and appropriate safeguards.

---

## 8. Explicit and implicit feedback

This distinction is useful for conceptual and comparison questions.

| Explicit feedback | Implicit feedback |
|---|---|
| The user directly expresses a preference. | The system infers a preference from behaviour. |
| Examples include star ratings and written reviews. | Examples include clicks, watch time, purchases, and listening history. |
| A rating directly indicates the user's stated evaluation. | An interaction may indicate interest but does not always indicate satisfaction. |
| Rating prediction is a common task. | Predicting future interactions or ranking items is common. |

**Possible exam question:** A streaming service records both star ratings and watch history. Distinguish these forms of feedback.

**Answer:** Star ratings are explicit feedback because users directly state their evaluations. Watch history is implicit feedback because the system infers possible interests from behaviour. Watching a film does not necessarily mean the user liked it, so implicit interactions must be interpreted carefully.

---

## 9. Additional numerical practice

The previous worked questions cover cosine similarity, Pearson correlation, user-based prediction, item-based prediction, and matrix-factorisation scores. Practise these two variations as well.

### Numerical 7 — Mean-centred ratings

**Question:** A user gives ratings $2,4,5,3$. Calculate the mean rating and the mean-centred value of the rating 5.

**Step 1: Calculate the mean.**

$$
\bar r=\frac{2+4+5+3}{4}=\frac{14}{4}=3.5
$$

**Step 2: Subtract the mean from the given rating.**

$$
r'=5-3.5
$$

$$
\boxed{r'=1.5}
$$

The rating of 5 is 1.5 points above the user's average.

### Numerical 8 — Binarisation

**Question:** A recommendation system classifies ratings of 3 or more as positive. Convert the ratings $5,3,2,1,4$ into binary values.

Using the threshold rule:

$$
b=
\begin{cases}
1,&r\geq3\\
0,&r<3
\end{cases}
$$

The result is:

$$
\boxed{[1,1,0,0,1]}
$$

---

## 10. How to answer case-study questions in the exam

For almost any scenario-based CF question, use this structure:

1. **Identify the method:** user-based, item-based, or model-based CF.
2. **Explain the input:** ratings, clicks, purchases, or other interactions.
3. **Describe the operation:** similarity calculation, neighbour selection, or model training.
4. **Explain the prediction:** how an unseen rating or preference is estimated.
5. **State the output:** ranked items or recommended products.
6. **Mention one advantage and one limitation.**

For an attack scenario, identify the attack type, state whether it is intended to push or nuke an item, explain its effect, and propose defences.

For a numerical, always write the formula first, substitute the values, show intermediate calculations, and state the answer with its interpretation.

---

## 11. Final revision checklist

- [ ] Define Collaborative Filtering and explain its assumption.
- [ ] Explain the working of user-based nearest-neighbour CF.
- [ ] Calculate cosine similarity from rating vectors.
- [ ] Calculate Pearson correlation from co-rated items.
- [ ] Solve a mean-centred user-based rating prediction.
- [ ] Explain item-based CF and calculate item similarity.
- [ ] Solve an item-based rating prediction.
- [ ] Compare user-based, item-based, memory-based, and model-based CF.
- [ ] Explain matrix factorisation and calculate a latent-factor score.
- [ ] Explain normalisation, binarisation, missing data, and dimensionality reduction.
- [ ] Distinguish explicit and implicit feedback.
- [ ] Explain shilling attacks, push vs. nuke, and random/average/bandwagon attacks.
- [ ] Discuss sparsity, cold start, scalability, privacy, and popularity bias.
- [ ] Practise one end-to-end case study for each major CF method.

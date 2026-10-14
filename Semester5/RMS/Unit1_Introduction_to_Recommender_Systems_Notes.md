# UNIT I — Introduction to Recommender Systems

---

## Sections

1. [Introduction to Recommender Systems](#1-introduction-to-recommender-systems)
2. [Functions of a Recommender System](#2-functions-of-a-recommender-system)
3. [Linear Algebra Notation](#3-linear-algebra-notation)
4. [Applications of Recommender Systems](#4-applications-of-recommender-systems)
5. [Issues with Recommender Systems](#5-issues-with-recommender-systems)

---

## 1. Introduction to Recommender Systems

### 1.1 Definition of a Recommender System

A recommender system is an information-filtering system that predicts the preferences, interests, or potential utility of items for a user and suggests the items that are most likely to be relevant to that user.

It uses information such as user preferences, past interactions, item characteristics, ratings, and the behaviour of similar users to generate personalized recommendations.

**Examples:** Netflix recommending movies, Amazon suggesting products, Spotify recommending songs, and YouTube suggesting videos.

### 1.2 Objectives of a Recommender System

The primary objectives are:

1. **Personalization:** Provide different recommendations to different users based on their preferences.
2. **Prediction:** Estimate how much a user may like an item or how likely they are to interact with it.
3. **Information filtering:** Reduce the number of irrelevant choices from a large collection of items.
4. **Discovery:** Help users discover relevant items that they might not find independently.
5. **Decision support:** Assist users in selecting products, movies, books, music, or other services.

### 1.3 Basic Working of a Recommender System

```text
Step 1: Data Collection
Ratings, clicks, purchases, user preferences, item attributes
                    ↓
Step 2: Data Processing
Clean, organize, and represent the collected information
                    ↓
Step 3: Preference Modelling
Identify user interests, item similarities, or learned patterns
                    ↓
Step 4: Recommendation Generation
Predict relevance or preference scores for candidate items
                    ↓
Step 5: Ranking and Presentation
Rank suitable items and present the top recommendations
```

The system may then collect feedback from the user and update future recommendations. This creates a feedback loop.

### 1.4 Types of Information Used

| Information | Meaning | Example |
|---|---|---|
| Explicit feedback | A preference directly provided by the user | Giving a movie 5 stars |
| Implicit feedback | Behaviour that indirectly indicates interest | Watching a video or purchasing a book |
| User information | Attributes or preferences associated with a user | Preferred genres |
| Item information | Characteristics of the items being recommended | Movie genre, director, language |
| Contextual information | Circumstances surrounding an interaction | Time, location, or device |

**Exam tip:** Explicit feedback directly communicates a preference; implicit feedback requires the system to infer it from behaviour.

---

## 2. Functions of a Recommender System

### 2.1 Formal Definition

A recommender system estimates the utility of an item for a particular user. Let:

- $U$ be the set of users.
- $I$ be the set of items.
- $R$ be the set of possible ratings or preference scores.

The system aims to learn a utility function:

$$
f: U\times I\rightarrow R
$$

where $f(u,i)$ represents the predicted preference or utility of item $i$ for user $u$.

The recommendation task can be expressed as:

$$
i^*=\arg\max_{i\in I_u} f(u,i)
$$

where $I_u$ is the set of candidate items for user $u$, and $i^*$ is the item with the highest predicted utility. In many systems, $I_u$ excludes items the user has already consumed.

### 2.2 Major Functions

**1. Rating prediction**

Estimates the rating a user would assign to an item.

*Example:* Predicting that a user would rate a movie 4.5 out of 5.

**2. Top-N recommendation**

Identifies the $N$ most relevant items for a user and presents them in ranked order.

*Example:* Recommending the top 10 songs on Spotify.

**3. Personalized ranking**

Orders items according to their estimated relevance to an individual user.

*Example:* Two users may see the same products in different orders.

**4. Similar-item recommendation**

Identifies items similar to a selected or previously consumed item.

*Example:* Recommending movies similar to a user's favourite science-fiction film.

**5. Preference learning**

Learns user interests from explicit ratings or implicit behavioural data and updates the user's preference profile.

**6. Novelty and discovery**

Introduces relevant items that are unfamiliar to the user rather than repeatedly recommending only familiar choices.

**7. Context-aware recommendation**

Uses contextual information, such as time, location, or current activity, to adapt recommendations when that information is available.

### 2.3 Rating Prediction vs Top-N Recommendation

| Rating Prediction | Top-N Recommendation |
|---|---|
| Predicts a numerical preference score for a user-item pair. | Selects and ranks the N most relevant candidate items. |
| Example: Predict a rating of 4.2/5 for a movie. | Example: Recommend the user's top 10 movies. |
| Often evaluated using MAE or RMSE when numerical ratings are available. | Often evaluated using Precision@N, Recall@N, or ranking metrics such as NDCG. |

These functions are related but not identical. A system may predict ratings and then use those predictions to generate a ranked list.

---

## 3. Linear Algebra Notation

### 3.1 Matrices and Their Dimensions

A matrix is a rectangular arrangement of numbers in rows and columns. It is commonly used in recommender systems to represent user ratings, item features, and other numerical information.

A matrix $A$ with $m$ rows and $n$ columns is denoted by:

$$
A=[a_{ij}]_{m\times n}
$$

where $a_{ij}$ is the element in the $i$-th row and $j$-th column.

Consider the following user-item rating matrix:

$$
R=
\begin{bmatrix}
5&3&0\\
4&0&2
\end{bmatrix}
$$

Here, rows represent two users and columns represent three items. For illustration, $0$ denotes an unrated item, not a genuine zero-star rating.

- $r_{11}=5$: User 1 rated Item 1 as 5.
- $r_{12}=3$: User 1 rated Item 2 as 3.
- $r_{23}=2$: User 2 rated Item 3 as 2.
- Dimensions of $R$: $2\times3$.

This representation is important because recommender algorithms operate on these structured data representations.

### 3.2 Matrix Addition

**Definition:** Matrix addition is the element-wise addition of two matrices having identical dimensions. The corresponding elements are added to obtain the resulting matrix.

If $A=[a_{ij}]$ and $B=[b_{ij}]$, then:

$$
C=A+B,\qquad c_{ij}=a_{ij}+b_{ij}
$$

The matrices must have the same number of rows and columns.

#### Solved Example 1 — Matrix Addition

Given:

$$
A=\begin{bmatrix}1&2\\3&4\end{bmatrix},
\quad
B=\begin{bmatrix}5&6\\7&8\end{bmatrix}
$$

Find $A+B$.

**Step 1: Verify dimensions**

Both matrices are $2\times2$, so addition is defined.

**Step 2: Add corresponding elements**

$$
A+B=
\begin{bmatrix}
1+5&2+6\\
3+7&4+8
\end{bmatrix}
$$

**Step 3: Simplify**

$$
\boxed{
A+B=\begin{bmatrix}6&8\\10&12\end{bmatrix}
}
$$

Properties worth remembering:

- Commutative: $A+B=B+A$.
- Associative: $(A+B)+C=A+(B+C)$.
- Additive identity: $A+0=A$, where $0$ is a zero matrix of the same dimensions.

### 3.3 Matrix Multiplication

**Definition:** Matrix multiplication produces a new matrix by taking the dot product of each row of the first matrix with each column of the second matrix.

If $A$ has dimensions $m\times n$ and $B$ has dimensions $n\times p$, then $AB$ is defined and has dimensions $m\times p$.

The number of columns of the first matrix must equal the number of rows of the second matrix.

The general formula is:

$$
(AB)_{ij}=\sum_{k=1}^{n}a_{ik}b_{kj}
$$

#### Solved Example 2 — Matrix Multiplication

Given:

$$
A=\begin{bmatrix}1&2\\3&4\end{bmatrix},
\quad
B=\begin{bmatrix}5&6\\7&8\end{bmatrix}
$$

Find $AB$.

**Step 1: Check dimensions**

$A$ is $2\times2$ and $B$ is $2\times2$. The inner dimensions match, so $AB$ exists and the result is $2\times2$.

**Step 2: Calculate each entry using row-by-column multiplication**

First row, first column:

$$
c_{11}=(1)(5)+(2)(7)=19
$$

First row, second column:

$$
c_{12}=(1)(6)+(2)(8)=22
$$

Second row, first column:

$$
c_{21}=(3)(5)+(4)(7)=43
$$

Second row, second column:

$$
c_{22}=(3)(6)+(4)(8)=50
$$

**Step 3: Form the resulting matrix**

$$
\boxed{
AB=\begin{bmatrix}19&22\\43&50\end{bmatrix}
}
$$

Important examination points:

- Matrix multiplication is generally not commutative: $AB\ne BA$.
- Matrix multiplication is associative: $(AB)C=A(BC)$.
- It is distributive over addition: $A(B+C)=AB+AC$, when dimensions permit.

#### Solved Example 3 — Rectangular Matrices

Let:

$$
A=\begin{bmatrix}1&2&3\\4&5&6\end{bmatrix},
\quad
B=\begin{bmatrix}1&2\\3&4\\5&6\end{bmatrix}
$$

Find $AB$.

**Step 1:** $A$ is $2\times3$, and $B$ is $3\times2$. Therefore, $AB$ is $2\times2$.

**Step 2:** Compute the four entries.

$$
\begin{aligned}
c_{11}&=1(1)+2(3)+3(5)=22\\
c_{12}&=1(2)+2(4)+3(6)=28\\
c_{21}&=4(1)+5(3)+6(5)=49\\
c_{22}&=4(2)+5(4)+6(6)=64
\end{aligned}
$$

**Step 3:** Write the final result.

$$
\boxed{AB=\begin{bmatrix}22&28\\49&64\end{bmatrix}}
$$

Notice that $BA$ would have dimensions $3\times3$, so it cannot equal $AB$, which has dimensions $2\times2$.

### 3.4 Matrix Transposition

**Definition:** The transpose of a matrix is obtained by interchanging its rows and columns. The element at position $(i,j)$ becomes the element at position $(j,i)$.

If $A=[a_{ij}]$, its transpose is denoted by $A^T$, where:

$$
(A^T)_{ij}=a_{ji}
$$

A matrix of dimensions $m\times n$ becomes an $n\times m$ matrix after transposition.

#### Solved Example 4 — Transpose

Given:

$$
A=\begin{bmatrix}
1&2&3\\
4&5&6
\end{bmatrix}
$$

Find $A^T$.

**Step 1: Identify the original dimensions.**

$A$ is $2\times3$.

**Step 2: Convert each row into a column.**

First row $[1,2,3]$ becomes the first column. Second row $[4,5,6]$ becomes the second column.

**Step 3: Write the transpose.**

$$
\boxed{
A^T=\begin{bmatrix}
1&4\\
2&5\\
3&6
\end{bmatrix}
}
$$

The resulting dimensions are $3\times2$.

Properties:

$$
(A^T)^T=A
$$

$$
(A+B)^T=A^T+B^T
$$

$$
(AB)^T=B^TA^T
$$

Remember the reversed order in the last formula.

### 3.5 Inverse of a Matrix

**Definition:** The inverse of a square matrix $A$ is a matrix $A^{-1}$ such that their product in either order equals the identity matrix $I$.

$$
AA^{-1}=A^{-1}A=I
$$

The identity matrix has 1s on the main diagonal and 0s elsewhere.

For a $2\times2$ matrix,

$$
A=\begin{bmatrix}a&b\\c&d\end{bmatrix}
$$

its determinant is:

$$
\det(A)=ad-bc
$$

If $\det(A)\ne0$, the inverse exists and is given by:

$$
\boxed{
A^{-1}=\frac{1}{ad-bc}
\begin{bmatrix}d&-b\\-c&a\end{bmatrix}
}
$$

If the determinant is zero, the matrix is singular and has no inverse.

#### Solved Example 5 — Finding a Matrix Inverse

Find the inverse of:

$$
A=\begin{bmatrix}2&1\\5&3\end{bmatrix}
$$

**Step 1: Calculate the determinant**

$$
\det(A)=(2)(3)-(1)(5)=6-5=1
$$

Since the determinant is nonzero, the inverse exists.

**Step 2: Apply the inverse formula**

For a $2\times2$ matrix, interchange the diagonal entries and change the signs of the off-diagonal entries.

$$
A^{-1}=\frac{1}{1}
\begin{bmatrix}3&-1\\-5&2\end{bmatrix}
$$

**Step 3: Write the final answer**

$$
\boxed{A^{-1}=\begin{bmatrix}3&-1\\-5&2\end{bmatrix}}
$$

**Step 4: Verify the result**

$$
AA^{-1}=
\begin{bmatrix}
2(3)-1(5)&2(-1)+1(2)\\
5(3)-3(5)&5(-1)+3(2)
\end{bmatrix}
$$

$$
=\begin{bmatrix}1&0\\0&1\end{bmatrix}=I
$$

Hence, the inverse is correct.

**Why does matrix inversion matter in ML and recommender systems?**

Matrix inversion appears in certain linear-algebraic solutions to optimization problems, including some regression formulations. It is not required by every recommender algorithm, and practical systems often use numerical methods rather than explicitly computing an inverse.

### 3.6 Covariance and Covariance Matrices

#### Definition of covariance

Covariance is a statistical measure that indicates how two variables vary together. It helps identify whether deviations from their respective means tend to occur in the same or opposite directions.

For two variables $X$ and $Y$, population covariance is:

$$
\mathrm{Cov}(X,Y)
=\frac{1}{n}\sum_{i=1}^{n}(x_i-\bar{x})(y_i-\bar{y})
$$

where:

- $n$ is the number of observations.
- $x_i,y_i$ are corresponding observations.
- $\bar{x},\bar{y}$ are their respective means.

For a sample covariance, the conventional denominator is $n-1$:

$$
s_{XY}=\frac{1}{n-1}\sum_{i=1}^{n}(x_i-\bar{x})(y_i-\bar{y})
$$

**Important:** Use the denominator specified in the question. If the question says sample covariance, use $n-1$; for population covariance, use $n$.

#### Interpretation of covariance

| Covariance | Interpretation |
|---|---|
| Positive | The variables tend to deviate from their means in the same direction. |
| Negative | The variables tend to deviate from their means in opposite directions. |
| Zero | There is no linear co-variation as measured by covariance; nonlinear relationships may still exist. |

Covariance magnitude depends on the scales of the variables, so it should not automatically be interpreted as a standardized strength of association.

#### Definition of a covariance matrix

A covariance matrix is a square matrix containing the variances of individual variables on its diagonal and the pairwise covariances between variables in its off-diagonal entries.

For two variables $X$ and $Y$:

$$
\Sigma=
\begin{bmatrix}
\mathrm{Var}(X)&\mathrm{Cov}(X,Y)\\
\mathrm{Cov}(Y,X)&\mathrm{Var}(Y)
\end{bmatrix}
$$

Since covariance is symmetric,

$$
\mathrm{Cov}(X,Y)=\mathrm{Cov}(Y,X)
$$

Therefore, the covariance matrix is symmetric.

#### Solved Example 6 — Calculating Covariance

Suppose two users' ratings of three items are:

| Item | User A ($X$) | User B ($Y$) |
|---|---|---|
| 1 | 1 | 2 |
| 2 | 2 | 4 |
| 3 | 3 | 6 |

Calculate the population covariance and the sample covariance.

**Step 1: Calculate the means**

$$
\bar{x}=\frac{1+2+3}{3}=2
$$

$$
\bar{y}=\frac{2+4+6}{3}=4
$$

**Step 2: Calculate deviations from the means**

| Item | $x_i-\bar{x}$ | $y_i-\bar{y}$ | Product |
|---|---|---|---|
| 1 | -1 | -2 | 2 |
| 2 | 0 | 0 | 0 |
| 3 | 1 | 2 | 2 |
| Sum | | | 4 |

**Step 3: Calculate population covariance**

$$
\mathrm{Cov}(X,Y)=\frac{4}{3}
$$

**Step 4: Calculate sample covariance**

$$
s_{XY}=\frac{4}{3-1}=2
$$

**Final answers:** Population covariance $=4/3$; sample covariance $=2$.

The positive covariance indicates that higher ratings from User A tend to correspond to higher ratings from User B in this example. It does not, by itself, prove that they have similar preferences across other items.

#### Constructing a covariance matrix

For the same data, the population variance of $X$ is:

$$
\mathrm{Var}(X)
=\frac{(-1)^2+0^2+1^2}{3}
=\frac{2}{3}
$$

For $Y$:

$$
\mathrm{Var}(Y)
=\frac{(-2)^2+0^2+2^2}{3}
=\frac{8}{3}
$$

Thus, the population covariance matrix is:

$$
\boxed{
\Sigma=
\begin{bmatrix}
2/3&4/3\\
4/3&8/3
\end{bmatrix}
}
$$

The diagonal contains variances, and the off-diagonal entries contain covariances.

**Recommender-system connection:** Covariance can help analyze relationships among user preferences or item attributes. However, covariance is not the same as a user-similarity measure; algorithms may instead use Pearson correlation, cosine similarity, or other measures.

### 3.7 Understanding Ratings

Ratings are representations of users' preferences or feedback about items. They form a central source of information for many collaborative filtering algorithms.

#### Types of ratings

1. **Explicit ratings:** Users directly express their opinions.

   *Examples:* a 1–5 star rating, a thumbs-up/thumbs-down response, or a written review.

2. **Implicit ratings or feedback:** The system infers interest from observed behaviour.

   *Examples:* clicks, viewing time, purchases, repeat listening, and browsing history.

Implicit feedback does not necessarily mean positive preference: a click may reflect curiosity, and a purchase may be influenced by factors other than liking.

#### User-item rating matrix

Let $R$ denote a user-item rating matrix with $m$ users and $n$ items.

$$
R\in\mathbb{R}^{m\times n}
$$

The entry $r_{ui}$ represents the observed rating given by user $u$ to item $i$.

For example:

$$
R=
\begin{matrix}
U_1\\
U_2\\
U_3
\end{matrix}
\begin{bmatrix}
5&3&?\\
4&?&2\\
?&5&4
\end{bmatrix}
$$

Here, ? denotes missing feedback. The system may try to estimate those missing preferences.

#### Important characteristics of ratings

- **Sparsity:** Most users rate only a small fraction of all available items.
- **Subjectivity:** Different users may assign different ratings to the same item.
- **Scale variation:** Some users tend to rate generously, while others rate strictly.
- **Temporal variation:** Preferences can change over time.
- **Implicitness:** Many systems observe behaviour rather than direct ratings.

#### Solved Example 7 — Rating Matrix and Sparsity

Suppose 4 users can rate 5 items, giving a total of $4\times5=20$ possible user-item entries. Only 6 entries contain ratings.

**Step 1: Calculate the number of missing entries.**

$$
20-6=14
$$

**Step 2: Calculate the sparsity percentage.**

$$
\text{Sparsity}=
\frac{\text{Missing entries}}{\text{Total entries}}\times100
$$

$$
=\frac{14}{20}\times100=\boxed{70\%}
$$

**Step 3: Interpret the result.**

The matrix is 70% sparse because 70% of the possible user-item ratings are missing.

Do not confuse sparsity with density:

$$
\text{Density}=\frac{6}{20}\times100=30\%
$$

Sparsity and density sum to 100% when every possible entry is classified as either observed or missing.

---

## 4. Applications of Recommender Systems

### Definition

Applications of recommender systems are domains in which personalized predictions and rankings are used to help users discover, evaluate, and select relevant items or services from large collections.

### Major applications

1. **Entertainment:** Platforms such as Netflix and Spotify recommend movies, shows, and music based on preferences, interactions, and item characteristics.
2. **E-commerce:** Platforms such as Amazon suggest products based on purchase history, browsing activity, product attributes, and similar users' behaviour.
3. **Online content and social platforms:** Systems recommend videos, articles, posts, and other content using viewing history, engagement, and content relevance.
4. **Travel and tourism:** Systems suggest hotels, destinations, and activities based on budget, previous trips, location, and travel preferences.
5. **Education:** Learning platforms recommend courses, exercises, and learning resources based on a student's interests, performance, and learning needs.

Other applications include news personalization, job recommendations, healthcare decision support, and financial product discovery.

### Advantages of using recommender systems

1. **Reduced information overload:** Filters large item collections into manageable choices.
2. **Personalized experience:** Adapts recommendations to individual preferences.
3. **Improved discoverability:** Helps users find relevant or less familiar items.
4. **User engagement:** Can increase interaction with a platform.
5. **Business benefits:** May improve conversion, retention, and customer satisfaction when recommendations are useful.

For an exam question asking for applications, write the domain, explain how recommendations are generated in that domain, and give one example.

---

## 5. Issues with Recommender Systems

### Definition

Issues with recommender systems are the technical, statistical, and ethical challenges that affect the accuracy, reliability, diversity, fairness, and usefulness of generated recommendations.

### Major issues

**1. Cold-start problem**

Occurs when the system lacks sufficient information about a new user or a new item.

- New users have little or no interaction history.
- New items have few or no ratings.
- Possible solutions include onboarding questionnaires, item metadata, popularity-based recommendations, and hybrid methods.

**2. Data sparsity**

Occurs when only a small fraction of possible user-item pairs have observed ratings.

- Similarities become harder to estimate reliably.
- Many users and items have limited interaction histories.
- Matrix factorization, data enrichment, and suitable hybrid approaches can help.

**3. Scalability**

A recommender must handle large numbers of users, items, and interactions efficiently.

- Computing all pairwise similarities can be expensive.
- Large datasets increase storage and computation requirements.
- Approximate nearest-neighbor search, indexing, and efficient candidate generation can reduce costs.

**4. Synonymy and semantic ambiguity**

Different terms may express similar meanings, while the same term may have different meanings in different contexts.

- Keyword-based matching may miss relevant items.
- Feature representations may fail to capture semantic relationships.
- Better feature extraction and semantic representations can improve matching.

**5. Overspecialization**

Occurs when a system repeatedly recommends items very similar to those the user already likes.

- Recommendations may lack diversity.
- Users may miss new interests or unfamiliar items.
- Diversity-aware ranking and controlled exploration can help.

**6. Shilling attacks and profile manipulation**

Malicious users may create fake profiles or submit artificial ratings to manipulate recommendations.

- **Push attack:** Attempts to promote a target item.
- **Nuke attack:** Attempts to reduce a target item's recommendation score or popularity.

Detection techniques may include identifying suspicious rating patterns, robust aggregation, and limiting the influence of untrustworthy profiles.

**7. Privacy concerns**

Recommendation algorithms may use sensitive or personal behavioural information.

- Excessive data collection can expose users to privacy risks.
- User histories may reveal personal interests or routines.
- Data minimization, access controls, and privacy-preserving techniques can reduce risk.

**8. Popularity bias**

Popular items may receive disproportionate exposure, even when less popular items are relevant to a user.

- Niche items may remain undiscovered.
- Existing popularity can reinforce further exposure.
- Re-ranking and exposure-aware recommendation can improve item visibility.

**9. Evaluation and feedback-loop problems**

Past recommendations influence the data the system subsequently observes.

- Users cannot interact with items they never see.
- Clicks and ratings may not fully reflect satisfaction.
- Offline metrics may not accurately predict real-world performance.

A combination of offline evaluation, user studies, and carefully designed online experiments may be necessary.

### Exam-ready conclusion

Recommender systems improve information discovery and personalization, but their effectiveness depends on the quality and availability of data, computational efficiency, resistance to manipulation, user privacy, and the ability to produce relevant and diverse recommendations. Appropriate algorithm design, evaluation, and data-management practices are therefore essential for building reliable recommendation systems.

---

## Quick self-test — Unit I Introduction

**1. Which function estimates a numerical rating for a particular user-item pair?**

- Top-N recommendation
- Rating prediction
- Novelty generation
- Context collection

**2. A 3 × 2 matrix is multiplied by a 2 × 4 matrix. What are the dimensions of the result?**

- 2 × 2
- 3 × 4
- 4 × 3
- 3 × 2

**3. What condition guarantees that a square matrix has an inverse?**

- Its determinant is zero
- Its rows are all identical
- Its determinant is nonzero
- It contains only positive entries

**4. What does a covariance matrix contain on its diagonal?**

- Pairwise correlations
- Variances of the individual variables
- Missing ratings
- Predicted recommendation scores

**5. A user has rated only 5 out of 100 available items. Which issue is most directly illustrated?**

- Scalability
- Data sparsity
- Overspecialization
- Shilling attack

**6. A malicious profile is created to artificially promote a product. What is this called?**

- Cold start
- Synonymy
- Push attack
- Overspecialization

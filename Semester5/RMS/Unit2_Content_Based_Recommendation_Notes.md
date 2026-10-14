# UNIT II — Content-Based Recommendation

---

## Sections

1. [Content-Based Recommendation](#1-content-based-recommendation)
2. [High-Level Architecture of Content-Based Systems](#2-high-level-architecture-of-content-based-systems)
3. [Advantages and Drawbacks of Content-Based Filtering](#3-advantages-and-drawbacks-of-content-based-filtering)
4. [Item Profiles](#4-item-profiles)
5. [Discovering Features of Documents](#5-discovering-features-of-documents)
6. [Obtaining Item Features from Tags](#6-obtaining-item-features-from-tags)
7. [Representing Item Profiles](#7-representing-item-profiles)
8. [Methods for Learning User Profiles](#8-methods-for-learning-user-profiles)
9. [Similarity-Based Retrieval](#9-similarity-based-retrieval)
10. [Classification Algorithms](#10-classification-algorithms)

---

## 1. Content-Based Recommendation

### Definition

A content-based recommender system is an information-filtering system that recommends items to a user by comparing the features of candidate items with the user's preference profile, which is learned from previously liked, selected, or interacted-with items.

The fundamental principle is that items with characteristics similar to those of items preferred by a user are more likely to interest that user.

**Example:** If a user frequently watches science-fiction movies, the system learns that preference and recommends other science-fiction movies with similar themes, actors, or descriptions.

### Working of content-based recommendation

1. Collect item information such as descriptions, genres, keywords, tags, and attributes.
2. Extract useful features from the collected information.
3. Represent each item as a feature vector.
4. Learn the user's preference profile from previous interactions.
5. Calculate the similarity or predicted relevance of candidate items to the user profile.
6. Rank the candidate items and recommend the most relevant ones.
7. Update the user profile as new feedback becomes available.

---

## 2. High-Level Architecture of Content-Based Systems

A content-based system can be understood through five major components.

```text
1. Item Information Source
Documents, genres, tags, product attributes, metadata
                    ↓
2. Content Analyzer
Feature extraction, keyword processing, text analysis
                    ↓
3. Item Profile Generator
Creates numerical or symbolic feature representations
                    ↓
User Profile Learner                      Matching Engine
Learns preferences from feedback          Compares user and item profiles
                    ↓
4. Recommendation Generator
Scores, filters, and ranks candidate items
                    ↓
5. Recommended Items and Feedback
Presents recommendations and uses new interactions to update preferences
```

### Explanation of components

1. **Item information source:** Stores descriptive information about the items available for recommendation.
2. **Content analyzer:** Extracts meaningful features from text, tags, metadata, or other item attributes.
3. **Item profile generator:** Converts the extracted features into structured representations such as binary vectors, TF-IDF vectors, or embeddings.
4. **User profile learner and matching engine:** Learns the user's preferences and compares the user profile with candidate item profiles using similarity measures or predictive models.
5. **Recommendation generator:** Selects and ranks suitable items, presents them to the user, and incorporates new feedback where appropriate.

**Exam conclusion:** The architecture enables personalized recommendations by transforming item content into feature representations, learning user preferences, and matching those preferences against candidate items.

---

## 3. Advantages and Drawbacks of Content-Based Filtering

### Advantages

1. **Personalization:** Recommendations are tailored to each user's interests rather than depending entirely on the behaviour of other users.
2. **Independence from other users:** The system can operate without requiring ratings from a large community.
3. **New-item recommendations:** An item with no ratings can still be recommended if its features are available and match the user's profile.
4. **Explainability:** Recommendations can often be explained using matching attributes, such as genre, keywords, or product specifications.
5. **Preference adaptation:** User profiles can be updated as new feedback is received.
6. **Privacy potential:** A system can use an individual's own history and item metadata without necessarily collecting other users' histories.

### Drawbacks

1. **Overspecialization:** The system may repeatedly recommend items similar to those the user already likes.
2. **Limited feature extraction:** Important characteristics may be difficult to extract from unstructured text, images, audio, or video.
3. **New-user cold start:** A new user with no history provides insufficient information to construct a reliable preference profile.
4. **Dependence on item features:** Inaccurate, incomplete, or poorly chosen features can reduce recommendation quality.
5. **Limited serendipity:** Unexpected but interesting items may not match the existing user profile closely enough to be recommended.
6. **Changing preferences:** A static profile may not reflect evolving interests or contextual needs.

### Comparison with collaborative filtering

| Content-Based Filtering | Collaborative Filtering |
|---|---|
| Uses item characteristics and an individual user's profile. | Uses patterns in user-item interactions and ratings. |
| Can recommend unrated items when descriptive features are available. | Pure interaction-based methods struggle with items that have no interaction history. |
| Often recommends items similar in content to previously liked items. | Can recommend items favoured by similar users, even when their content differs. |
| Relies on feature quality and user-profile representation. | Relies on interaction data and reliable user/item relationships. |

**Exam tip:** If asked for advantages and disadvantages, explain each point in one or two sentences rather than listing isolated keywords.

---

## 4. Item Profiles

### Definition

An item profile is a structured representation of an item's relevant characteristics, attributes, and features used by a recommender system to determine its suitability for a user.

### Components

- **Textual features:** Keywords, phrases, and terms from item descriptions.
- **Categorical features:** Genres, topics, product categories, or content types.
- **Numerical features:** Price, duration, size, or other measurable attributes.
- **Tags:** Descriptive labels assigned by users, editors, or a platform.
- **Feature weights:** Numerical values indicating the importance of different features.

### Mathematical representation

If an item has $k$ features, its profile can be represented as:

$$
\mathbf{x}_i=[x_{i1},x_{i2},\ldots,x_{ik}]
$$

where $x_{ij}$ denotes the value or weight of feature $j$ for item $i$.

For $n$ items, the item-profile matrix is:

$$
X=
\begin{bmatrix}
x_{11}&x_{12}&\cdots&x_{1k}\\
x_{21}&x_{22}&\cdots&x_{2k}\\
\vdots&\vdots&\ddots&\vdots\\
x_{n1}&x_{n2}&\cdots&x_{nk}
\end{bmatrix}
$$

Its dimensions are $n\times k$.

### Example

Suppose movies are represented using the features Science Fiction, Romance, and Comedy.

| Movie | Science Fiction | Romance | Comedy |
|---|---|---|---|
| A | 1 | 0 | 0 |
| B | 1 | 1 | 0 |
| C | 0 | 0 | 1 |

The profile of Movie B is:

$$
\mathbf{x}_B=[1,1,0]
$$

Here, 1 means that the feature is present and 0 means it is absent.

---

## 5. Discovering Features of Documents

### Definition

Feature discovery is the process of identifying and extracting informative characteristics from a document so that its content can be represented in a form suitable for recommendation.

For textual documents, features may include keywords, phrases, term frequencies, topics, or semantic representations.

### Major techniques

1. **Tokenization:** Divides text into individual words or tokens.
2. **Stop-word removal:** Removes common words that may contribute little to the task, such as “the” and “is.”
3. **Stemming:** Reduces words to approximate root forms.
4. **Lemmatization:** Converts words into linguistically appropriate base forms.
5. **Keyword extraction:** Identifies words or phrases that describe the document's main subject.
6. **Term-frequency representation:** Records how often terms occur in a document.
7. **TF-IDF weighting:** Assigns higher weights to terms that are important to a document relative to the entire collection.
8. **Semantic feature extraction:** Uses embeddings or language models to capture semantic relationships between terms and documents.

### TF-IDF formula

Term Frequency–Inverse Document Frequency (TF-IDF) measures the importance of a term within a document relative to a collection of documents.

A common formulation is:

$$
\mathrm{TF}(t,d)=f_{t,d}
$$

$$
\mathrm{IDF}(t)=\log\left(\frac{N}{df_t}\right)
$$

Therefore,

$$
\boxed{\mathrm{TFIDF}(t,d)=
\mathrm{TF}(t,d)\times\mathrm{IDF}(t)}
$$

where:

- $f_{t,d}$ is the frequency of term $t$ in document $d$.
- $N$ is the total number of documents.
- $df_t$ is the number of documents containing term $t$.

Different implementations may use normalized term frequencies or smoothed IDF values.

### Solved numerical — TF-IDF

A collection contains 10 documents. The term “space” occurs 4 times in Document A and appears in 2 documents overall. Calculate TF-IDF using raw term frequency and base-10 logarithms.

**Step 1: Identify the values.**

$$
f_{t,d}=4,\quad N=10,\quad df_t=2
$$

**Step 2: Calculate IDF.**

$$
\mathrm{IDF}(t)=\log_{10}\left(\frac{10}{2}\right)
$$

$$
=\log_{10}(5)\approx0.6990
$$

**Step 3: Calculate TF-IDF.**

$$
\mathrm{TFIDF}(t,d)=4(0.6990)
$$

$$
\boxed{\mathrm{TFIDF}(t,d)\approx2.796}
$$

**Interpretation:** The term has a positive weight because it appears in the document and is relatively uncommon across the collection. Its score depends on the TF-IDF convention used.

---

## 6. Obtaining Item Features from Tags

### Definition

Tag-based feature extraction is the process of using descriptive labels associated with an item as features in its item profile.

Tags may be assigned by users, content creators, editors, or the platform.

### Methods of representing tags

1. **Binary representation:** A feature is 1 when the tag is present and 0 otherwise.
2. **Frequency representation:** Records how frequently a tag occurs or is assigned.
3. **Weighted representation:** Assigns different importance to tags based on relevance or reliability.
4. **Normalized representation:** Scales the feature vector to make comparisons more suitable.

### Example

A book has the tags Fantasy, Adventure, and Magic.

Let the complete tag vocabulary be:

$$
T=[\text{Fantasy},\text{Romance},\text{Adventure},\text{Magic}]
$$

Its binary feature vector is:

$$
\boxed{\mathbf{x}=[1,0,1,1]}
$$

The Romance feature is zero because the book does not have that tag.

### Advantages and limitations

**Advantages**

- Simple to implement and interpret.
- Captures descriptive information directly.
- Useful when detailed text is unavailable but tags exist.

**Limitations**

- Tags may be missing, ambiguous, inconsistent, or subjective.
- Incorrect tags can reduce recommendation quality.
- Different users may use different labels for similar concepts.

**Key distinction:** Document feature discovery extracts features from the document's content; tag-based feature extraction uses descriptive labels associated with the item.

---

## 7. Representing Item Profiles

### Definition

Item profile representation is the process of converting extracted item characteristics into a structured numerical or symbolic form that can be processed by a recommendation algorithm.

### Common representations

| Representation | Description | Example |
|---|---|---|
| Binary vector | Indicates the presence or absence of features. | $[1,0,1]$ |
| Count vector | Records term occurrence counts. | $[3,0,2]$ |
| TF-IDF vector | Stores importance-weighted term values. | $[0.8,0,0.5]$ |
| Numerical feature vector | Stores measurable attributes. | $[250,4.5,120]$ |
| Embedding vector | Stores learned semantic features. | $[0.12,-0.37,0.81,\ldots]$ |

The values shown are illustrative.

### Mathematical representation

For $n$ items described by $k$ features:

$$
X\in\mathbb{R}^{n\times k}
$$

Each row represents one item, and each column represents one feature.

For example, if 100 movies are represented using 20 features, then:

$$
\mathrm{Dimensions}(X)=100\times20
$$

**Choosing a representation:** Binary vectors are useful for presence/absence features, TF-IDF for keyword-based text retrieval, numerical vectors for quantitative attributes, and embeddings for capturing learned semantic relationships.

---

## 8. Methods for Learning User Profiles

### Definition

A user profile is a structured representation of a user's interests and preferences that helps the system identify items likely to be relevant to that user.

### Methods

1. **Explicit feedback:** Users directly state preferences through ratings, likes, or selected categories.
2. **Implicit feedback:** Preferences are inferred from clicks, purchases, viewing history, or reading behaviour.
3. **Relevance feedback:** Users mark recommendations as relevant or irrelevant, allowing the system to update their profiles.
4. **Learning from rated items:** Feature vectors of positively and negatively rated items are combined to estimate user preferences.
5. **Machine-learning-based methods:** A classifier or ranking model learns patterns associated with a user's positive feedback.

### Weighted user-profile formula

A simple profile can be calculated as a weighted average of the feature vectors of items a user has rated:

$$
\boxed{
\mathbf{p}_u=
\frac{\sum_{i\in I_u}w_{ui}\mathbf{x}_i}
{\sum_{i\in I_u}w_{ui}}
}
$$

where:

- $\mathbf{p}_u$ is the user's preference vector.
- $\mathbf{x}_i$ is the feature vector of item $i$.
- $w_{ui}$ is the non-negative weight assigned to the user's feedback.
- $I_u$ is the set of items with observed feedback from user $u$.

This formulation requires a nonzero sum of weights.

### Solved numerical — Learning a user profile

Suppose the features are $[\text{Sci-Fi},\text{Romance},\text{Comedy}]$.

| Movie | Feature vector | User rating |
|---|---|---|
| A | $[1,0,0]$ | 5 |
| B | $[0,1,0]$ | 3 |

Use the raw ratings as weights.

**Step 1: Multiply each vector by its rating.**

$$
5[1,0,0]=[5,0,0]
$$

$$
3[0,1,0]=[0,3,0]
$$

**Step 2: Add the weighted vectors.**

$$
[5,0,0]+[0,3,0]=[5,3,0]
$$

**Step 3: Divide by the sum of ratings.**

$$
\mathbf{p}_u=\frac{[5,3,0]}{5+3}
$$

$$
\boxed{\mathbf{p}_u=[0.625,0.375,0]}
$$

**Interpretation:** Science Fiction has a higher weight than Romance in this simplified user profile.

This example uses raw ratings for simplicity. Actual systems may center ratings around a user's mean or separately account for positive and negative feedback.

---

## 9. Similarity-Based Retrieval

### Definition

Similarity-based retrieval is a technique that identifies and ranks candidate items according to how closely their feature representations match a user's preference profile or a query vector.

### A. Cosine similarity

Cosine similarity measures the cosine of the angle between two nonzero vectors.

$$
\boxed{
\mathrm{cosSim}(\mathbf{u},\mathbf{v})
=\frac{\mathbf{u}\cdot\mathbf{v}}
{\|\mathbf{u}\|\|\mathbf{v}\|}
}
$$

The dot product is:

$$
\mathbf{u}\cdot\mathbf{v}=\sum_{j=1}^{k}u_jv_j
$$

The vector magnitude is:

$$
\|\mathbf{u}\|=\sqrt{\sum_{j=1}^{k}u_j^2}
$$

For non-negative feature vectors, cosine similarity lies between 0 and 1.

#### Solved numerical — Cosine similarity

Given:

$$
\mathbf{u}=[1,1,0],\quad \mathbf{v}=[1,0,1]
$$

**Step 1: Calculate the dot product.**

$$
\mathbf{u}\cdot\mathbf{v}=1(1)+1(0)+0(1)=1
$$

**Step 2: Calculate magnitudes.**

$$
\|\mathbf{u}\|=\sqrt{1^2+1^2+0^2}=\sqrt2
$$

$$
\|\mathbf{v}\|=\sqrt{1^2+0^2+1^2}=\sqrt2
$$

**Step 3: Substitute.**

$$
\mathrm{cosSim}(\mathbf{u},\mathbf{v})
=\frac{1}{\sqrt2\sqrt2}
$$

$$
\boxed{\mathrm{cosSim}=0.5}
$$

### B. Jaccard similarity

Jaccard similarity measures the overlap between two sets.

$$
\boxed{J(A,B)=\frac{|A\cap B|}{|A\cup B|}}
$$

**Example:** Let $A=\{\text{Fantasy, Magic, Adventure}\}$ and $B=\{\text{Fantasy, Magic, Romance}\}$.

**Step 1:** Intersection size $=2$.

**Step 2:** Union size $=4$.

**Step 3:** Calculate:

$$
J(A,B)=\frac{2}{4}=\boxed{0.5}
$$

### C. Euclidean distance

Euclidean distance measures the straight-line distance between two feature vectors.

$$
\boxed{d(\mathbf{u},\mathbf{v})=\sqrt{\sum_{j=1}^{k}(u_j-v_j)^2}}
$$

**Example:** Let $\mathbf{u}=[1,2]$ and $\mathbf{v}=[4,6]$.

**Step 1: Subtract corresponding components.**

$$
[1-4,2-6]=[-3,-4]
$$

**Step 2: Square and sum the differences.**

$$
(-3)^2+(-4)^2=9+16=25
$$

**Step 3: Take the square root.**

$$
\boxed{d(\mathbf{u},\mathbf{v})=5}
$$

Unlike similarity scores, smaller Euclidean distances generally indicate greater closeness.

### Ranking candidate items

Suppose a user's profile is $[1,1,0]$ and the candidates are:

$$
A=[1,1,0],\quad B=[1,0,1],\quad C=[0,1,1]
$$

The cosine similarities are:

| Candidate | Similarity |
|---|---|
| A | 1.0 |
| B | 0.5 |
| C | 0.5 |

The ranking is:

$$
\boxed{A>B=C}
$$

Item A is the best match, while B and C tie. A recommendation system may use further ranking criteria to break ties.

---

## 10. Classification Algorithms

### Definition

A classification algorithm is a supervised machine-learning algorithm that learns from labelled examples and assigns new inputs to predefined classes.

In content-based recommendation, classification can predict whether a candidate item is relevant to a user, whether the user is likely to engage with it, or which preference category it belongs to.

### Common algorithms

| Algorithm | Working principle | Recommendation application |
|---|---|---|
| Naive Bayes | Estimates class probabilities using Bayes' theorem and a conditional-independence assumption. | Classifies articles as relevant or irrelevant. |
| Decision Tree | Learns feature-based decision rules arranged in a tree. | Classifies products or content by attributes. |
| K-Nearest Neighbors | Predicts a class based on nearby labelled examples. | Uses similar previously liked or disliked items. |
| Support Vector Machine | Learns a decision boundary that separates classes. | Classifies item feature vectors. |
| Logistic Regression | Estimates the probability of a class, commonly for binary classification. | Predicts the likelihood of positive feedback. |

### Naive Bayes formula

$$
\boxed{
P(C\mid X)=\frac{P(X\mid C)P(C)}{P(X)}
}
$$

where $P(C\mid X)$ is the posterior probability of class $C$ given the observed features $X$.

### Solved numerical — Naive Bayes

A news recommendation classifier distinguishes Relevant ($R$) from Not Relevant ($N$) articles.

Given:

$$
P(R)=0.6,\quad P(N)=0.4
$$

$$
P(\text{space}\mid R)=0.8
$$

$$
P(\text{space}\mid N)=0.2
$$

Classify an article containing the word “space.”

**Step 1: Calculate the unnormalized scores.**

$$
S_R=0.8(0.6)=0.48
$$

$$
S_N=0.2(0.4)=0.08
$$

**Step 2: Calculate the evidence.**

$$
P(\text{space})=0.48+0.08=0.56
$$

**Step 3: Calculate posterior probabilities.**

$$
P(R\mid\text{space})=\frac{0.48}{0.56}\approx0.8571
$$

$$
P(N\mid\text{space})=\frac{0.08}{0.56}\approx0.1429
$$

**Step 4: Choose the class with the highest probability.**

$$
\boxed{\text{Predicted class}=\text{Relevant}}
$$

The article is classified as relevant because its posterior probability is approximately 85.71%.

### Advantages of classification-based recommendation

- Learns decision rules from labelled examples.
- Can predict relevance for previously unseen items with available features.
- Supports different kinds of item features.
- Can be evaluated using accuracy, precision, recall, and F1-score.

### Limitations

- Requires labelled training data.
- Can inherit biases in historical feedback.
- Depends on suitable feature representations and model selection.
- Predicting relevance does not automatically produce an optimal ranking.

**Key distinction:** Similarity-based retrieval ranks items according to a similarity measure, while classification predicts a class or class probability. Both can be used in content-based recommendation.

---

## Final exam revision checklist

### Unit II checklist

- [ ] Definition and working of content-based recommendation
- [ ] Architecture diagram with component explanations
- [ ] Advantages, drawbacks, and comparison with collaborative filtering
- [ ] Item profiles and their mathematical representation
- [ ] Document feature discovery and TF-IDF numerical
- [ ] Tag-based feature extraction
- [ ] Binary, count, TF-IDF, numerical, and embedding representations
- [ ] Methods for learning user profiles and weighted-profile numerical
- [ ] Cosine similarity, Jaccard similarity, and Euclidean distance numericals
- [ ] Classification algorithms and Naive Bayes numerical

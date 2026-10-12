# UNIT II — Supervised Learning

## Index

- [2. Classification & Models — Part B](#2-classification--models--part-b)
  - [2.4 K-nearest-neighbor (KNN)](#24-k-nearest-neighbor-knn)
  - [2.5 Bayesian and Naïve Bayes Classifier](#25-bayesian-and-naïve-bayes-classifier)
  - [2.6 Naïve Bayes Classifier](#26-naïve-bayes-classifier)
- [3. Decision Tree Learning](#3-decision-tree-learning)
  - [3.1 Definition](#31-definition)
  - [3.2 Structure and working](#32-structure-and-working)
  - [3.3 Entropy](#33-entropy)
  - [3.4 Information Gain](#34-information-gain)
  - [3.5 Worked numerical — ID3, Play Tennis root node](#35-worked-numerical--id3-play-tennis-root-node)
  - [3.6 Worked numerical — ID3 next-level tree construction](#36-worked-numerical--id3-next-level-tree-construction)
  - [3.7 Gini Index](#37-gini-index)
  - [3.8 Decision Tree construction algorithms](#38-decision-tree-construction-algorithms)
  - [3.9 Overfitting and pruning](#39-overfitting-and-pruning)
  - [3.10 Decision Tree numerical revision](#310-decision-tree-numerical-revision)
  - [3.11 Final comparison: KNN, Naïve Bayes and Decision Trees](#311-final-comparison-knn-naïve-bayes-and-decision-trees)
  - [3.12 Final checklist for Classification & Models — Part B](#312-final-checklist-for-classification--models--part-b)

---

## 2. Classification & Models — Part B

We'll finish the remaining three syllabus topics in the same exam-ready format:

1. K-nearest-neighbor (KNN)
2. Bayesian and Naïve Bayes Classifier
3. Decision Tree Learning

We'll preserve your original numerical numbering: 10–17, including the Play Tennis decision-tree examples and the Gini Index question.

---

### 2.4 K-nearest-neighbor (KNN)

#### A. Definition

K-nearest-neighbor (KNN) is a supervised, instance-based learning algorithm that predicts the class or value of a new observation using the $K$ closest training observations.

It is called a **lazy learning** algorithm because it does not usually build an explicit model during training. Instead, it stores the training data and performs calculations when a new prediction is required.

KNN can be used for:

- **Classification:** Predicting a class, such as Pass or Fail.
- **Regression:** Predicting a numerical value, such as house price.

#### B. Working procedure

1. Choose the value of $K$.
2. Calculate the distance between the query observation and every training observation.
3. Sort the observations by increasing distance.
4. Select the $K$ nearest observations.
5. For classification, use majority voting; for regression, typically average their target values.
6. Return the predicted class or numerical value.

#### C. Distance measures

##### 1. Euclidean distance

The most common distance measure for numerical features is:

$$
\boxed{d(x,y)=\sqrt{\sum_{j=1}^{p}(x_j-y_j)^2}}
$$

Where:

- $x,y$ = two observations.
- $x_j,y_j$ = their values for feature $j$.
- $p$ = number of features.
- $d(x,y)$ = Euclidean distance between the observations.

For two-dimensional points:

$$
d(x,y)=\sqrt{(x_1-y_1)^2+(x_2-y_2)^2}
$$

##### 2. Manhattan distance

$$
\boxed{d(x,y)=\sum_{j=1}^{p}|x_j-y_j|}
$$

This adds the absolute differences across all features.

##### 3. Minkowski distance

$$
d(x,y)=\left(\sum_{j=1}^{p}|x_j-y_j|^q\right)^{1/q}
$$

Where $q$ is the distance parameter. $q=1$ gives Manhattan distance, and $q=2$ gives Euclidean distance.

#### D. Classification by majority voting

Suppose the three nearest neighbors have labels:

- Pass
- Pass
- Fail

The majority class is Pass, so the query observation is classified as Pass.

The basic prediction rule is:

$$
\boxed{\hat y=\operatorname{mode}(y_1,y_2,\ldots,y_K)}
$$

Here, $y_1,\ldots,y_K$ are the labels of the selected neighbors, and the mode is the most frequently occurring label.

If there is a tie, the result depends on the tie-breaking rule used by the implementation. Choosing an odd $K$ can reduce ties in binary classification, but does not eliminate every possible tie in multiclass problems.

#### E. Worked numerical — KNN classification

This is your original **Numerical 10**.

Suppose the training data is:

| Student | Study feature $x_1$ | Attendance feature $x_2$ | Class |
|---|---|---|---|
| A | 2 | 3 | Fail |
| B | 6 | 7 | Pass |
| C | 7 | 8 | Pass |
| D | 5 | 5 | Fail |
| E | 8 | 8 | Pass |

Classify the new observation $X=(6,8)$ using $K=3$.

**Step 1: Calculate distances**

Using Euclidean distance:

$$
d(X,A)=\sqrt{(6-2)^2+(8-3)^2}
=\sqrt{41}\approx6.40
$$

$$
d(X,B)=\sqrt{(6-6)^2+(8-7)^2}=1
$$

$$
d(X,C)=\sqrt{(6-7)^2+(8-8)^2}=1
$$

$$
d(X,D)=\sqrt{(6-5)^2+(8-5)^2}
=\sqrt{10}\approx3.16
$$

$$
d(X,E)=\sqrt{(6-8)^2+(8-8)^2}=2
$$

**Step 2: Sort by distance**

| Neighbor | Distance | Class |
|---|---|---|
| B | 1.00 | Pass |
| C | 1.00 | Pass |
| E | 2.00 | Pass |
| D | 3.16 | Fail |
| A | 6.40 | Fail |

**Step 3: Select the three nearest neighbors**

B, C, and E all belong to Pass.

**Step 4: Majority vote**

Pass = 3 votes; Fail = 0 votes.

$$
\boxed{\text{Predicted class = Pass}}
$$

This matches your original numerical's answer.

#### F. Choosing the value of $K$

- **Small $K$:** More sensitive to individual observations and noise; can produce a complex decision boundary.
- **Large $K$:** Produces smoother predictions but may overlook local patterns.
- $K=1$ assigns the label of the single nearest neighbor.
- The best $K$ is typically selected using validation data or cross-validation.

#### G. Feature scaling in KNN

KNN relies on distances. If one feature has a much larger numerical scale than another, it can dominate the distance calculation.

For example, a distance calculation using age (18–60) and annual income (10,000–1,000,000) may be dominated by income.

Normalization or standardization can help ensure features contribute on a more comparable scale.

#### H. Advantages and limitations

**Advantages**

- Simple to understand and implement.
- No strong assumption about the form of the decision boundary.
- Can handle multiclass classification.
- Training is inexpensive because it mainly stores the data.

**Limitations**

- Prediction can be slow for large training datasets.
- Requires memory to store the training observations.
- Sensitive to feature scaling, irrelevant features, and noise.
- Performance can deteriorate in high-dimensional spaces.
- Depends on the choice of $K$ and distance measure.

#### I. KNN classification versus KNN regression

| Basis | KNN classification | KNN regression |
|---|---|---|
| Output | Class label | Numerical value |
| Prediction | Majority class among neighbors | Usually mean of neighbors' target values |
| Example | Predict Pass/Fail | Predict examination marks |
| Evaluation | Accuracy, precision, recall, F1 | MAE, MSE, RMSE |

---

### 2.5 Bayesian and Naïve Bayes Classifier

#### A. Bayes' theorem

Bayes' theorem calculates the probability of a hypothesis or event after observing evidence.

$$
\boxed{P(A\mid B)=\frac{P(B\mid A)P(A)}{P(B)}}
$$

Where:

- $P(A\mid B)$ = posterior probability of event $A$ given evidence $B$.
- $P(B\mid A)$ = likelihood of evidence $B$ when $A$ is true.
- $P(A)$ = prior probability of $A$.
- $P(B)$ = probability of observing the evidence.

The main idea is that an existing belief (prior) is updated using the likelihood of the evidence to obtain a posterior probability.

**Illustrative example:** With $P(A)=0.20$, $P(B\mid A)=0.85$ and $P(B)=0.25$:

$$
P(A\mid B)=\frac{0.85(0.20)}{0.25}=0.68
$$

Here, $P(B\cap A)=0.17$, $P(B\cap \neg A)=0.08$, and therefore $P(B)=0.17+0.08=0.25$.

#### B. Bayesian classification

A Bayesian classifier predicts the class with the highest posterior probability.

Suppose an observation has features $X$ and possible classes $C_1,C_2,\ldots,C_k$.

$$
P(C_j\mid X)=\frac{P(X\mid C_j)P(C_j)}{P(X)}
$$

Where:

- $C_j$ = a possible class.
- $X$ = observed feature values.
- $P(C_j)$ = prior probability of class $C_j$.
- $P(X\mid C_j)$ = likelihood of the observed features given that class.
- $P(C_j\mid X)$ = posterior probability of the class given the features.

The prediction rule is:

$$
\boxed{\hat C=\arg\max_{C_j}P(C_j\mid X)}
$$

Since $P(X)$ is the same for all candidate classes for a fixed observation, classification can compare:

$$
P(X\mid C_j)P(C_j)
$$

without calculating the common denominator.

#### C. Worked numerical — Two-bag Bayes problem

This is your original **Numerical 15**.

A bag is selected randomly from two bags:

- Bag $B_1$: 2 red balls and 3 black balls.
- Bag $B_2$: 1 red ball and 3 black balls.

A ball drawn from the selected bag is red. Find the probability that the ball came from $B_1$.

**Step 1: Calculate the priors**

Both bags are equally likely to be selected:

$$
P(B_1)=P(B_2)=\frac12
$$

**Step 2: Calculate the likelihoods**

$$
P(R\mid B_1)=\frac25
$$

$$
P(R\mid B_2)=\frac14
$$

**Step 3: Apply Bayes' theorem**

$$
P(B_1\mid R)=
\frac{P(R\mid B_1)P(B_1)}
{P(R\mid B_1)P(B_1)+P(R\mid B_2)P(B_2)}
$$

Substitute:

$$
=\frac{\frac25\cdot\frac12}
{\frac25\cdot\frac12+\frac14\cdot\frac12}
$$

$$
=\frac{\frac15}{\frac15+\frac18}
=\frac{\frac15}{\frac{13}{40}}
$$

$$
\boxed{P(B_1\mid R)=\frac8{13}\approx0.6154}
$$

Therefore, the probability that the selected red ball came from Bag $B_1$ is approximately 61.54%.

---

### 2.6 Naïve Bayes Classifier

#### A. Definition

Naïve Bayes is a probabilistic supervised classification algorithm based on Bayes' theorem. It assumes that the input features are conditionally independent of one another given the class.

This assumption simplifies the calculation of the likelihood of multiple features.

#### B. Naïve Bayes formula

For features $X=(x_1,x_2,\ldots,x_p)$ and class $C$:

$$
P(C\mid X)=\frac{P(X\mid C)P(C)}{P(X)}
$$

Under the conditional-independence assumption:

$$
P(X\mid C)=\prod_{j=1}^{p}P(x_j\mid C)
$$

Therefore:

$$
\boxed{
P(C\mid X)\propto P(C)\prod_{j=1}^{p}P(x_j\mid C)
}
$$

Where:

- $P(C)$ = prior probability of the class.
- $P(x_j\mid C)$ = likelihood of feature value $x_j$ given class $C$.
- $p$ = number of features.
- $\prod$ = multiplication over all features.
- $\propto$ = proportional to; the common evidence denominator is omitted.

The predicted class is the one with the highest posterior score.

#### C. Conditional independence assumption

Suppose the task is to predict whether an email is spam using the features Free=Yes and Win=Yes.

Naïve Bayes assumes:

$$
P(\text{Free=Yes, Win=Yes}\mid C)
$$

$$
=P(\text{Free=Yes}\mid C)
\times P(\text{Win=Yes}\mid C)
$$

This does not mean the features are independent in every situation. It assumes independence **conditional on the class**.

The assumption may not be exactly true in real data, but the method can still work well for many classification tasks.

#### D. Step-by-step procedure

1. Calculate the prior probability of every class.
2. Calculate the conditional probability of each observed feature value within each class.
3. Multiply the prior by the relevant conditional probabilities.
4. Compare the resulting class scores.
5. Predict the class with the largest score.
6. Normalize the scores if actual posterior probabilities are required.

#### E. Laplace smoothing

A feature value that never appears in a particular class can make its unsmoothed likelihood zero. Since Naïve Bayes multiplies likelihoods, one zero factor can force the entire class score to zero.

Laplace smoothing adds a small count, usually 1, to avoid zero probabilities.

For a categorical feature:

$$
\boxed{P(x=v\mid C)=\frac{N_{v,C}+\alpha}{N_C+\alpha m}}
$$

Where:

- $N_{v,C}$ = number of observations in class $C$ with feature value $v$.
- $N_C$ = number of observations in class $C$.
- $m$ = number of possible values of the feature.
- $\alpha$ = smoothing parameter; $\alpha=1$ gives Laplace smoothing.

For example, if a class contains 4 emails and none contains the word Prize, with two possible feature states (present/absent), then:

$$
P(\text{Prize present}\mid C)
=\frac{0+1}{4+2}=\boxed{\frac16}
$$

Instead of zero, the smoothed likelihood is $1/6$.

#### F. Types of Naïve Bayes

| Type | Likelihood model | Typical use |
|---|---|---|
| Gaussian Naïve Bayes | Models numerical features using class-conditional Gaussian distributions | Measurements such as height or temperature |
| Multinomial Naïve Bayes | Uses feature counts or non-negative frequencies | Word-count-based text classification |
| Bernoulli Naïve Bayes | Uses binary feature indicators | Whether a word appears or does not appear in a document |
| Categorical Naïve Bayes | Uses categorical feature probabilities | Attributes such as weather or student category |

#### G. Worked numerical — Naïve Bayes Play prediction

This is your original **Numerical 11**.

Suppose a Play Tennis dataset has two classes: Play = Yes and Play = No. A new observation has:

- Outlook = Sunny
- Temperature = Cool
- Humidity = High
- Wind = Strong

For each class, calculate:

$$
Score(\text{Yes})=
P(\text{Yes})P(\text{Sunny}\mid\text{Yes})
P(\text{Cool}\mid\text{Yes})
P(\text{High}\mid\text{Yes})
P(\text{Strong}\mid\text{Yes})
$$

Similarly:

$$
Score(\text{No})=
P(\text{No})P(\text{Sunny}\mid\text{No})
P(\text{Cool}\mid\text{No})
P(\text{High}\mid\text{No})
P(\text{Strong}\mid\text{No})
$$

Compare the scores:

- If $Score(\text{Yes})>Score(\text{No})$, predict Play = Yes.
- Otherwise, predict Play = No.

**Important:** The exact numerical answer depends on the frequency table provided in the question. Use those counts to calculate the priors and likelihoods; do not assume the result from a different version of the Play Tennis dataset.

#### H. Worked numerical — Naïve Bayes student result

This is your original **Numerical 16**.

Suppose the features are:

- FY = Yes
- F = No
- S1 = Yes

The classes are Pass and Fail, with equal priors:

$$
P(\text{Pass})=P(\text{Fail})=0.5
$$

Using the conditional probabilities from the question, calculate:

$$
Score(\text{Pass})=
P(\text{Pass})P(FY=\text{Yes}\mid\text{Pass})
P(F=\text{No}\mid\text{Pass})
P(S1=\text{Yes}\mid\text{Pass})
$$

$$
Score(\text{Fail})=
P(\text{Fail})P(FY=\text{Yes}\mid\text{Fail})
P(F=\text{No}\mid\text{Fail})
P(S1=\text{Yes}\mid\text{Fail})
$$

The previously recorded scores for your example were:

$$
Score(\text{Pass})=0.024
$$

$$
Score(\text{Fail})=0.072
$$

Since $0.072>0.024$:

$$
\boxed{\text{Predicted result = Fail}}
$$

These scores should be checked against the original frequency table before using the answer in an exam.

#### I. Worked numerical — Naïve Bayes email spam

This is your original **Numerical 17**.

Suppose the observed features are:

- Free = Yes
- Win = Yes

The classes are Spam and Not Spam, with equal priors:

$$
P(\text{Spam})=P(\text{NotSpam})=0.5
$$

Calculate:

$$
Score(\text{Spam})=
P(\text{Spam})P(\text{Free=Yes}\mid\text{Spam})
P(\text{Win=Yes}\mid\text{Spam})
$$

$$
Score(\text{NotSpam})=
P(\text{NotSpam})P(\text{Free=Yes}\mid\text{NotSpam})
P(\text{Win=Yes}\mid\text{NotSpam})
$$

For your recorded six-row example, the unsmoothed scores were:

$$
Score(\text{Spam})=\frac29\approx0.2222
$$

$$
Score(\text{NotSpam})=0
$$

The zero occurs because one of the conditional likelihoods for Not Spam is zero.

Thus, the unsmoothed model predicts:

$$
\boxed{\text{Spam}}
$$

With Laplace smoothing, the recorded Not Spam score was $0.04$, while the Spam score must also be recalculated using the same smoothing rule for a fair comparison. In this example, the zero-likelihood problem is resolved by smoothing.

#### J. Naïve Bayes versus general Bayesian classification

| Basis | Bayesian classification | Naïve Bayes |
|---|---|---|
| Foundation | Uses Bayes' theorem to calculate posterior probabilities | Uses Bayes' theorem plus conditional independence |
| Feature relationships | Can model dependencies when the chosen probability model supports them | Assumes features are conditionally independent given the class |
| Probability calculations | May require a more complex joint likelihood | Factorizes likelihood into individual feature probabilities |
| Computational cost | Depends on the probability model; can be expensive | Usually computationally efficient |
| Data requirements | Depend on the complexity of the joint model | Often works well with relatively simple frequency estimates |
| Typical application | General probabilistic classification | Spam detection, text classification, categorical prediction |

#### K. Advantages and limitations of Naïve Bayes

**Advantages**

- Simple and fast to train.
- Works well for many text-classification tasks.
- Can handle multiple classes.
- Often performs reasonably well with high-dimensional sparse data.
- Requires relatively little training data for basic probability estimates.

**Limitations**

- The conditional independence assumption may be unrealistic.
- Zero-frequency values require smoothing.
- Probability estimates can be poorly calibrated.
- Correlated or dependent features may cause likelihoods to be counted in ways that reduce accuracy.

---

## 3. Decision Tree Learning

### 3.1 Definition

A Decision Tree is a supervised learning model that predicts an output by repeatedly splitting the data according to feature-based conditions.

It has a tree structure in which:

- **Root node:** The first decision or split.
- **Internal node:** A further test on a feature.
- **Branch:** An outcome of a test.
- **Leaf node:** The final prediction, such as a class label or numerical value.

Decision trees can perform both classification and regression. Your syllabus focuses on decision tree learning, including entropy, information gain, and the Gini Index.

### 3.2 Structure and working

Example of a simple student-result tree:

```text
Attendance ≥ 75%?
├── Yes → Study hours ≥ 3?
│          ├── Yes → Pass
│          └── No  → Fail
└── No  → Fail
```

To classify a new student, begin at the root, follow the branch matching the student's feature value, and continue until reaching a leaf.

### 3.3 Entropy

Entropy measures the impurity or uncertainty of a set of class labels.

A node containing observations from only one class has zero entropy. A node containing a more even mixture of classes has higher entropy.

$$
\boxed{H(S)=-\sum_{i=1}^{c}p_i\log_2 p_i}
$$

Where:

- $S$ = dataset or node being evaluated.
- $c$ = number of classes.
- $p_i$ = proportion of observations belonging to class $i$.
- $\log_2$ = logarithm to base 2.

For binary classification:

$$
H(S)=-p_+\log_2 p_+-p_-\log_2 p_-
$$

Where $p_+$ and $p_-$ are the proportions of positive and negative examples.

Special cases:

- If all examples belong to one class, entropy is $0$.
- If two classes are equally represented, entropy is $1$ bit.

For calculations, the convention $0\log_2 0=0$ is used.

### 3.4 Information Gain

Information Gain measures the reduction in entropy after splitting a dataset using an attribute.

$$
\boxed{IG(S,A)=H(S)-H(S\mid A)}
$$

Where:

- $IG(S,A)$ = information gain from splitting dataset $S$ on attribute $A$.
- $H(S)$ = entropy before splitting.
- $H(S\mid A)$ = weighted entropy after splitting on $A$.

The weighted conditional entropy is:

$$
\boxed{
H(S\mid A)=\sum_{v\in Values(A)}
\frac{|S_v|}{|S|}H(S_v)
}
$$

Where:

- $Values(A)$ = possible values of attribute $A$.
- $S_v$ = subset of records having value $v$.
- $|S_v|$ = number of records in that subset.
- $|S|$ = total number of records.

**ID3 algorithm:** It selects the attribute with the highest Information Gain at each step.

### 3.5 Worked numerical — ID3, Play Tennis root node

This is your original **Numerical 1**.

Suppose the dataset contains 14 days:

- Play = Yes: 9 records.
- Play = No: 5 records.

**Step 1: Calculate the total entropy**

$$
H(S)=-\frac9{14}\log_2\frac9{14}
-\frac5{14}\log_2\frac5{14}
$$

$$
\boxed{H(S)\approx0.9403}
$$

**Step 2: Calculate the conditional entropy for Outlook**

Suppose the Outlook subsets are:

| Outlook | Yes | No | Total |
|---|---|---|---|
| Sunny | 2 | 3 | 5 |
| Overcast | 4 | 0 | 4 |
| Rain | 3 | 2 | 5 |

Sunny entropy:

$$
H(\text{Sunny})=
-\frac25\log_2\frac25
-\frac35\log_2\frac35
\approx0.9710
$$

Overcast entropy:

$$
H(\text{Overcast})=0
$$

Rain entropy:

$$
H(\text{Rain})=
-\frac35\log_2\frac35
-\frac25\log_2\frac25
\approx0.9710
$$

**Step 3: Calculate weighted entropy**

$$
H(S\mid\text{Outlook})
=\frac5{14}(0.9710)+\frac4{14}(0)
+\frac5{14}(0.9710)
$$

$$
\boxed{H(S\mid\text{Outlook})\approx0.6935}
$$

**Step 4: Calculate Information Gain**

$$
IG(S,\text{Outlook})=0.9403-0.6935
$$

$$
\boxed{IG(S,\text{Outlook})\approx0.2468}
$$

The same procedure is used to calculate Information Gain for Temperature, Humidity, and Wind. For the standard 14-record Play Tennis dataset, Outlook has the highest Information Gain, so ID3 selects it as the root.

**Exam method:** Calculate parent entropy → each subset's entropy → weighted entropy → Information Gain → compare attributes → select the highest.

### 3.6 Worked numerical — ID3 next-level tree construction

This is your original **Numerical 2**.

Once the root is selected, ID3 repeats the same process on each branch's subset. The best attribute can differ from branch to branch.

For the standard Play Tennis dataset, the root is Outlook.

#### Example: Constructing the Sunny branch

The Sunny subset contains five records:

- Play = Yes: 2
- Play = No: 3

Its entropy is:

$$
H(\text{Sunny})\approx0.9710
$$

Suppose we split this subset on Humidity:

| Humidity | Yes | No | Total |
|---|---|---|---|
| High | 0 | 3 | 3 |
| Normal | 2 | 0 | 2 |

Both resulting subsets are pure, so:

$$
H(\text{High})=0,\qquad H(\text{Normal})=0
$$

Weighted conditional entropy:

$$
H(\text{Sunny}\mid\text{Humidity})
=\frac35(0)+\frac25(0)=0
$$

Information Gain:

$$
IG(\text{Sunny},\text{Humidity})
=0.9710-0=\boxed{0.9710}
$$

Humidity perfectly separates the classes in this branch.

Therefore:

- Sunny and High humidity → Play = No.
- Sunny and Normal humidity → Play = Yes.

#### Constructing the remaining branches

Apply the same procedure independently to Overcast and Rain:

- **Overcast:** All four records are Play = Yes, so the branch is already pure and becomes a leaf.
- **Rain:** Compare the Information Gain of the remaining attributes. In the standard dataset, Wind separates the records into pure groups.

The resulting tree is:

```text
Outlook
├── Sunny → Humidity
│            ├── High   → No
│            └── Normal → Yes
├── Overcast → Yes
└── Rain → Wind
             ├── Weak   → Yes
             └── Strong → No
```

**Key rule:** After every split, calculate entropy and Information Gain using only the records that reach that node—not the full original dataset.

### 3.7 Gini Index

The Gini Index is another measure of impurity used to select decision-tree splits. CART-style decision trees commonly use Gini impurity.

$$
\boxed{Gini(S)=1-\sum_{i=1}^{c}p_i^2}
$$

Where:

- $S$ = dataset or node.
- $c$ = number of classes.
- $p_i$ = proportion of observations belonging to class $i$.

For binary classification:

$$
Gini(S)=1-p_+^2-p_-^2
$$

Interpretation:

- $Gini=0$: Pure node; all observations belong to one class.
- For two equally represented classes, $Gini=0.5$.
- Lower Gini impurity indicates a purer node.

#### Weighted Gini after a split

For a candidate split that produces subsets $S_1,S_2,\ldots,S_k$:

$$
\boxed{
Gini_{\text{split}}=
\sum_{j=1}^{k}\frac{|S_j|}{|S|}Gini(S_j)
}
$$

Where:

- $S_j$ = subset $j$.
- $|S_j|$ = number of records in subset $j$.
- $|S|$ = number of records in the parent node.
- $k$ = number of resulting subsets.

The preferred split is the one with the lowest weighted Gini impurity, or equivalently the greatest reduction in Gini impurity relative to the parent.

#### Worked example — comparing two splits

Suppose a parent node contains 10 records: 5 Yes and 5 No.

Parent Gini:

$$
Gini(S)=1-\left(\frac5{10}\right)^2
-\left(\frac5{10}\right)^2
=\boxed{0.5}
$$

**Split A:** Two pure subsets, each containing five records.

$$
Gini_A=\frac5{10}(0)+\frac5{10}(0)=\boxed{0}
$$

**Split B:** Two subsets, each containing 5 records with 3 Yes and 2 No.

For each child:

$$
Gini=1-\left(\frac35\right)^2-\left(\frac25\right)^2
=1-0.36-0.16=0.48
$$

Therefore:

$$
Gini_B=\frac5{10}(0.48)+\frac5{10}(0.48)
=\boxed{0.48}
$$

Since $0<0.48$, Split A is better: it produces pure child nodes.

#### Gini Index versus Entropy

| Basis | Entropy | Gini Index |
|---|---|---|
| Formula | $-\sum p_i\log_2 p_i$ | $1-\sum p_i^2$ |
| Measures | Uncertainty or impurity | Impurity |
| Pure node | 0 | 0 |
| Binary balanced node | 1 bit | 0.5 |
| Split selection | Highest Information Gain | Lowest weighted Gini impurity |
| Common association | ID3 uses Information Gain | CART commonly uses Gini impurity |
| Calculation | Uses logarithms | Uses squared proportions |

Both are used to evaluate candidate splits, but they are not numerically interchangeable.

#### Original Numerical 3 — Gini Index for Loan Approval

For your loan-approval question, follow this procedure using the exact counts in the provided dataset:

1. Calculate the parent Gini from the total Approved and Rejected counts.
2. For each candidate attribute, divide the data into its subsets.
3. Calculate the Gini impurity of every subset.
4. Weight each subset's Gini by its proportion of the parent.
5. Add the weighted values.
6. Select the attribute with the lowest weighted Gini.

The exact winning attribute and numerical result depend on the loan-approval table's counts, so they should not be guessed without that table.

### 3.8 Decision Tree construction algorithms

| Algorithm | Split criterion / approach | Main characteristics |
|---|---|---|
| ID3 | Information Gain based on entropy | Builds a tree recursively; traditionally handles categorical attributes |
| C4.5 | Gain Ratio | Extends ID3 and supports continuous attributes and pruning |
| CART | Gini impurity for classification; squared-error criteria for regression | Produces binary splits and supports classification and regression |

Gain Ratio, used by C4.5, adjusts Information Gain for the number and distribution of outcomes of a split:

$$
GainRatio(A)=\frac{IG(S,A)}{SplitInfo(A)}
$$

Where $SplitInfo(A)$ measures how the data is distributed among the subsets produced by attribute $A$. If $SplitInfo(A)=0$, the ratio is undefined and the split is not useful in that form.

### 3.9 Overfitting and pruning

A decision tree can become too complex, memorizing patterns specific to its training data rather than generalizing well to new observations. This is called **overfitting**.

#### Pruning

Pruning removes branches that contribute little to generalization.

- **Pre-pruning:** Stops tree growth early using constraints such as maximum depth, minimum samples per split, or minimum impurity reduction.
- **Post-pruning:** First grows a larger tree and then removes branches that are not sufficiently useful.

| Pre-pruning | Post-pruning |
|---|---|
| Stops growth during construction | Simplifies a tree after it has been grown |
| Usually faster | May require more computation |
| Can stop too early and underfit | Can remove unnecessary branches after evaluating the larger tree |

**Advantages of decision trees**

- Easy to understand and visualize.
- Can model nonlinear relationships and feature interactions.
- Require relatively little feature scaling.
- Can handle both classification and regression.
- Provide interpretable decision rules.

**Limitations of decision trees**

- Deep trees can overfit.
- Small changes in training data can produce a different tree.
- Greedy split selection does not guarantee a globally optimal tree.
- Trees may favour attributes with many possible split points under certain criteria.
- A single tree may be less accurate than an appropriately tuned ensemble.

---

### 3.10 Decision Tree numerical revision

Your original index includes these relevant questions:

| No. | Topic | What to practise |
|---|---|---|
| 1 | ID3 — Play Tennis root node | Calculate parent entropy, subset entropies, Information Gain, and select the root. |
| 2 | ID3 — Next-level tree construction | Recalculate conditional entropy and Information Gain on each branch. |
| 3 | Gini Index — Loan approval | Calculate class impurity, weighted Gini for each split, and select the best split. |
| 11 | Naïve Bayes — Play prediction | Calculate class priors, conditional probabilities, and compare class scores. |
| 12 | Decision Tree — Information Gain | Apply entropy and Information Gain to select the splitting attribute. |
| 14 | Naïve Bayes — Fruit classification | Use the provided class priors and attribute likelihoods to compare fruit classes. |

The remaining Naïve Bayes numericals from this block are 15 (Two-Bag Bayes theorem), 16 (Student result), and 17 (Email spam), which we covered above.

### 3.11 Final comparison: KNN, Naïve Bayes and Decision Trees

| Basis | KNN | Naïve Bayes | Decision Tree |
|---|---|---|---|
| Learning approach | Instance-based, lazy learning | Probabilistic learning | Rule-based recursive splitting |
| Main principle | Nearest observations determine prediction | Highest posterior probability determines prediction | Best feature split separates the data |
| Main calculations | Distances and voting | Priors and conditional likelihoods | Entropy, Information Gain, or Gini |
| Feature scaling | Often important | Depends on the likelihood model | Usually not required |
| Interpretability | Explains predictions through neighbours | Explains predictions through class probabilities | Often highly interpretable as rules |
| Main limitation | Slow prediction on large datasets | Conditional independence assumption | Can overfit and be unstable |

### 3.12 Final checklist for Classification & Models — Part B

- [ ] Explain KNN and solve a distance-based classification numerical.
- [ ] Calculate Euclidean distance and apply majority voting.
- [ ] State how $K$, feature scaling, and dimensionality affect KNN.
- [ ] State Bayes' theorem and explain prior, likelihood, evidence, and posterior.
- [ ] Calculate a posterior probability using Bayes' theorem.
- [ ] Explain the conditional independence assumption in Naïve Bayes.
- [ ] Calculate class scores and select the highest-scoring class.
- [ ] Explain Laplace smoothing and why zero probabilities are a problem.
- [ ] Define a decision tree, root, internal node, branch, and leaf.
- [ ] Calculate entropy and Information Gain.
- [ ] Construct the next level of an ID3 tree.
- [ ] Calculate Gini impurity and weighted Gini.
- [ ] Compare ID3, C4.5, and CART.
- [ ] Explain overfitting and distinguish pre-pruning from post-pruning.

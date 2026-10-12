# Machine Learning Numericals

## Index

**1. Data preprocessing and evaluation**

1. [Min-max normalization [0,1]](#n1) *(Orig. 17)*
2. [Min-max normalization [-1,1]](#n2) *(Orig. 18)*
3. [Mean Squared Error (MSE)](#n3) *(Orig. 19)*
4. [Root Mean Squared Error (RMSE)](#n4) *(Orig. 19)*

**2. Regression**

5. [Least-squares linear regression](#n5) *(Orig. 3)*
6. [Ridge regression](#n6) *(Orig. 4)*
7. [LASSO regression](#n7) *(Orig. 5)*
8. [Logistic regression and log-loss](#n8) *(Orig. 6)*

**3. Distance-based and margin-based classification**

9. [KNN classification — general dataset](#n9) *(Orig. 9)*
10. [KNN classification — student pass/fail](#n10) *(Orig. 12)*
11. [SVM margin and classification](#n11) *(Orig. 7)*
12. [Polynomial kernel and feature mapping](#n12) *(Orig. 8)*

**4. Probability and Bayesian classification**

13. [Bayes' theorem — two bags](#n13) *(Orig. 14)*
14. [Naïve Bayes — Play prediction](#n14) *(Orig. 10)*
15. [Naïve Bayes — student result](#n15) *(Orig. 15)*
16. [Naïve Bayes — email spam](#n16) *(Orig. 16)*
17. [Naïve Bayes — fruit identification](#n17) *(Orig. 13)*

**5. Decision trees**

18. [ID3 — entropy and information gain](#n18) *(Orig. 1)*
19. [Decision tree — information gain calculation](#n19) *(Orig. 11)*
20. [ID3 — next-level tree construction](#n20) *(Orig. —)*
21. [Gini Index and weighted Gini](#n21) *(Orig. 2)*

---

## Part 1 — Data preprocessing and evaluation

<a id="n1"></a>
### 1. Min-max normalization [0,1]

**Original No.:** 17

#### Question

Given the dataset

$$X=\{10,20,30,40,50\}$$

normalize the value $X=30$ to the range $[0,1]$ using min-max normalization.

#### Step 1 — Write the formula

$$\boxed{X'=\frac{X-X_{\min}}{X_{\max}-X_{\min}}}$$

Where:
- $X$ = original value
- $X_{\min}$ = minimum value
- $X_{\max}$ = maximum value
- $X'$ = normalized value

#### Step 2 — Identify the values

From the dataset,

$$X=30,\qquad X_{\min}=10,\qquad X_{\max}=50$$

#### Step 3 — Substitute into the formula

$$X'=\frac{30-10}{50-10}=\frac{20}{40}$$

$$\boxed{X'=0.5}$$

**Final answer:** The normalized value of 30 in the range $[0,1]$ is **0.5**.

#### Exam tips
- The minimum value maps to 0.
- The maximum value maps to 1.
- Values between the minimum and maximum map proportionally between 0 and 1.
- Apply the formula to each value if the question asks you to normalize the entire dataset.

---

<a id="n2"></a>
### 2. Min-max normalization [-1,1]

**Original No.:** 18

#### Question

Given the dataset

$$X=\{10,20,30,40,50\}$$

normalize the value $X=30$ to the range $[-1,1]$.

#### Step 1 — Write the generalized min-max formula

To map a value from the original range $[X_{\min},X_{\max}]$ to a target range $[a,b]$,

$$\boxed{X'=a+\frac{X-X_{\min}}{X_{\max}-X_{\min}}(b-a)}$$

Here,

$$a=-1,\qquad b=1$$

#### Step 2 — Substitute the values

$$X'=-1+\frac{30-10}{50-10}\bigl(1-(-1)\bigr)$$

$$=-1+\frac{20}{40}(2)$$

$$=-1+\frac12(2)$$

$$=-1+1$$

$$\boxed{X'=0}$$

**Final answer:** The normalized value of 30 in the range $[-1,1]$ is **0**.

#### Quick comparison

| Original value | Normalized to $[0,1]$ | Normalized to $[-1,1]$ |
|:-:|:-:|:-:|
| 10 | 0 | −1 |
| 20 | 0.25 | −0.5 |
| 30 | 0.5 | 0 |
| 40 | 0.75 | 0.5 |
| 50 | 1 | 1 |

> **Exam tip:** Remember the difference between the formulas. For $[0,1]$, there is no extra offset. For $[-1,1]$, the generalized formula starts with $a=-1$.

---

<a id="n3"></a>
### 3. Mean Squared Error (MSE)

**Original No.:** 19

#### Question

Calculate the Mean Squared Error (MSE) and Root Mean Squared Error (RMSE) for the following actual and predicted values.

| Actual $Y$ | Predicted $\hat Y$ |
|:-:|:-:|
| 10 | 12 |
| 20 | 18 |
| 30 | 33 |
| 40 | 36 |

#### Step 1 — Write the formulas

Mean Squared Error:

$$\boxed{MSE=\frac1n\sum_{i=1}^{n}(Y_i-\hat Y_i)^2}$$

Root Mean Squared Error:

$$\boxed{RMSE=\sqrt{MSE}}$$

Where:
- $Y_i$ = actual value
- $\hat Y_i$ = predicted value
- $n$ = number of observations

#### Step 2 — Calculate errors and squared errors

Error is defined as

$$e_i=Y_i-\hat Y_i$$

| Actual $Y$ | Predicted $\hat Y$ | Error $Y-\hat Y$ | Squared error |
|:-:|:-:|:-:|:-:|
| 10 | 12 | −2 | 4 |
| 20 | 18 | 2 | 4 |
| 30 | 33 | −3 | 9 |
| 40 | 36 | 4 | 16 |
| **Total** | | | **33** |

#### Step 3 — Calculate MSE

The number of observations is $n=4$.

$$MSE=\frac{4+4+9+16}{4}=\frac{33}{4}$$

$$\boxed{MSE=8.25}$$

#### Step 4 — Calculate RMSE

$$RMSE=\sqrt{8.25}$$

$$\boxed{RMSE\approx2.87}$$

**Final answers:**
- Mean Squared Error: $\boxed{8.25}$
- Root Mean Squared Error: $\boxed{2.87}$

#### Interpretation
- MSE measures the average squared prediction error.
- RMSE is the square root of MSE and is expressed in the same units as the target variable.
- Lower values generally indicate better predictions when comparing models on the same dataset and scale.
- Squaring errors makes larger errors contribute disproportionately more to MSE.

---

<a id="n4"></a>
### 4. Root Mean Squared Error (RMSE)

**Original No.:** 19

*Solved together with [#3](#n3) (same question, same data).*

$$RMSE=\sqrt{MSE}=\sqrt{8.25}\approx\boxed{2.87}$$

---

## Part 2 — Regression

<a id="n5"></a>
### 5. Least-squares linear regression

**Original No.:** 3

#### Question

Fit a straight line $y=a+bx$ to the following data using the least-squares method.

| $x$ | $y$ |
|:-:|:-:|
| 1 | 2 |
| 2 | 4 |
| 3 | 5 |
| 4 | 4 |
| 5 | 5 |

Find the regression equation, predicted values, and residuals.

#### Step 1 — Prepare the calculation table

| $x$ | $y$ | $x^2$ | $xy$ |
|:-:|:-:|:-:|:-:|
| 1 | 2 | 1 | 2 |
| 2 | 4 | 4 | 8 |
| 3 | 5 | 9 | 15 |
| 4 | 4 | 16 | 16 |
| 5 | 5 | 25 | 25 |
| **Σ** | **20** | **55** | **66** |

Also, $n=5$ and $\sum x=15$.

#### Step 2 — Calculate the slope

The least-squares slope is

$$b=\frac{n\sum xy-(\sum x)(\sum y)}{n\sum x^2-(\sum x)^2}$$

Substitute:

$$b=\frac{5(66)-(15)(20)}{5(55)-15^2}=\frac{330-300}{275-225}=\frac{30}{50}$$

$$\boxed{b=0.6}$$

#### Step 3 — Calculate the intercept

$$a=\frac{\sum y-b\sum x}{n}$$

$$a=\frac{20-(0.6)(15)}5=\frac{11}{5}$$

$$\boxed{a=2.2}$$

#### Step 4 — Write the regression equation

$$\boxed{\hat y=2.2+0.6x}$$

#### Step 5 — Calculate predictions and residuals

Residual $=y-\hat y$.

| $x$ | Actual $y$ | Predicted $\hat y$ | Residual |
|:-:|:-:|:-:|:-:|
| 1 | 2 | 2.8 | −0.8 |
| 2 | 4 | 3.4 | 0.6 |
| 3 | 5 | 4.0 | 1.0 |
| 4 | 4 | 4.6 | −0.6 |
| 5 | 5 | 5.2 | −0.2 |

**Final answer:** $\boxed{\hat y=2.2+0.6x}$

#### Exam tips
- Do not confuse slope $b$ with intercept $a$.
- Residual is actual minus predicted; some questions may instead define error as predicted minus actual.
- The least-squares method minimizes the sum of squared residuals.

---

<a id="n6"></a>
### 6. Ridge regression

**Original No.:** 4

#### Question

Given the model $y=wx$, without an intercept, and data

$$x=[1,2,3],\qquad y=[2,2.5,3.6]$$

find the Ridge Regression coefficient for $\lambda=1$. Compare it with ordinary least squares (OLS).

#### Step 1 — Write the Ridge cost function

$$J(w)=\sum_{i=1}^{n}(y_i-wx_i)^2+\lambda w^2$$

For one feature and no intercept, the coefficient is

$$\boxed{w_{\text{ridge}}=\frac{\sum x_i y_i}{\sum x_i^2+\lambda}}$$

#### Step 2 — Calculate the required sums

$$\sum x_i y_i=(1)(2)+(2)(2.5)+(3)(3.6)=2+5+10.8=17.8$$

$$\sum x_i^2=1^2+2^2+3^2=14$$

#### Step 3 — Substitute

$$w_{\text{ridge}}=\frac{17.8}{14+1}$$

$$\boxed{w_{\text{ridge}}\approx1.1867}$$

#### Step 4 — Compare with OLS

When $\lambda=0$,

$$w_{\text{OLS}}=\frac{17.8}{14}$$

$$\boxed{w_{\text{OLS}}\approx1.2714}$$

| Method | Coefficient |
|:-:|:-:|
| OLS | 1.2714 |
| Ridge, $\lambda=1$ | 1.1867 |

**Conclusion:** Ridge regularization reduces the coefficient magnitude in this example. It trades some bias for potentially lower variance and better generalization.

#### Exam tips
- Larger $\lambda$ generally increases regularization.
- Ridge uses an L2 penalty: $\lambda\sum_j w_j^2$.
- Ridge generally shrinks coefficients toward zero but does not usually make them exactly zero.
- The formula above assumes no intercept and one feature. Intercepts are commonly left unpenalized.

---

<a id="n7"></a>
### 7. LASSO regression

**Original No.:** 5

#### Question

The OLS coefficient for a feature, using the normalization convention specified by the problem, is $w_{\text{OLS}}=0.9$. Apply LASSO soft-thresholding for:
1. $\lambda=0.3$
2. $\lambda=1.0$

#### Step 1 — Write the formula

$$\boxed{w_{\text{LASSO}}=\operatorname{sign}(w_{\text{OLS}})\max(|w_{\text{OLS}}|-\lambda,0)}$$

This formula applies to a suitably normalized, standardized one-feature problem under the stated coordinate-descent convention.

#### Case 1: $\lambda=0.3$

$$w_{\text{LASSO}}=\operatorname{sign}(0.9)\max(|0.9|-0.3,0)=1\times\max(0.6,0)$$

$$\boxed{w_{\text{LASSO}}=0.6}$$

#### Case 2: $\lambda=1.0$

$$w_{\text{LASSO}}=\operatorname{sign}(0.9)\max(0.9-1.0,0)=1\times\max(-0.1,0)$$

$$\boxed{w_{\text{LASSO}}=0}$$

#### Final comparison

| $\lambda$ | LASSO coefficient |
|:-:|:-:|
| 0.3 | 0.6 |
| 1.0 | 0 |

**Conclusion:** LASSO uses an L1 penalty and can set coefficients exactly to zero. This enables feature selection.

> **Exam tip:** Don't simply subtract $\lambda$ from every coefficient. Soft-thresholding also preserves the sign and sets the result to zero whenever the magnitude does not exceed the threshold.

---

<a id="n8"></a>
### 8. Logistic regression and log-loss

**Original No.:** 6

#### Question

A logistic regression model uses weights $w_0=-4$ and $w_1=0.6$. Predict the pass probability for a student who studied $x=8$ hours. Use a classification threshold of 0.5. If the actual label is Pass, calculate the log-loss.

#### Step 1 — Calculate the linear score

$$z=w_0+w_1x$$

$$z=-4+0.6(8)$$

$$\boxed{z=0.8}$$

#### Step 2 — Apply the sigmoid function

$$\sigma(z)=\frac1{1+e^{-z}}$$

$$\sigma(0.8)=\frac1{1+e^{-0.8}}$$

Using $e^{-0.8}\approx0.4493$,

$$\hat y=\frac1{1+0.4493}$$

$$\boxed{\hat y\approx0.6900}$$

Thus, the estimated probability of passing is approximately $69\%$.

#### Step 3 — Apply the classification threshold

Decision rule:

$$\hat y\geq0.5\Rightarrow\text{Pass}$$

Since $0.6900>0.5$,

$$\boxed{\text{Predicted class}=\text{Pass (1)}}$$

#### Step 4 — Calculate log-loss

For actual label $y=1$,

$$L=-[y\ln\hat y+(1-y)\ln(1-\hat y)]$$

Substituting:

$$L=-[1\ln(0.6900)+0\ln(1-0.6900)]=-\ln(0.6900)$$

$$\boxed{L\approx0.371}$$

**Final answers:** Probability $\approx0.69$; prediction = Pass; log-loss $\approx0.371$.

#### Exam tips
- Sigmoid output is a probability between 0 and 1.
- The threshold determines the predicted class, not the probability itself.
- Log-loss uses the natural logarithm in the conventional formulation.
- A confidently wrong prediction incurs a large loss.

---

## Part 3 — Distance-based and margin-based classification

<a id="n9"></a>
### 9. KNN classification — general dataset

**Original No.:** 9

#### Question

Classify the point $P=(3,7)$ using KNN with $K=3$ and Euclidean distance.

| Point | Coordinates | Class |
|:-:|:-:|:-:|
| A | (1, 2) | Red |
| B | (2, 4) | Red |
| C | (3, 6) | Blue |
| D | (6, 8) | Blue |
| E | (7, 1) | Red |

#### Step 1 — Write the Euclidean distance formula

For points $P=(x_1,y_1)$ and $Q=(x_2,y_2)$,

$$d(P,Q)=\sqrt{(x_1-x_2)^2+(y_1-y_2)^2}$$

#### Step 2 — Calculate distances

**Distance from A**

$$d(P,A)=\sqrt{(3-1)^2+(7-2)^2}=\sqrt{4+25}=\sqrt{29}\approx5.39$$

**Distance from B**

$$d(P,B)=\sqrt{(3-2)^2+(7-4)^2}=\sqrt{1+9}=\sqrt{10}\approx3.16$$

**Distance from C**

$$d(P,C)=\sqrt{(3-3)^2+(7-6)^2}=1$$

**Distance from D**

$$d(P,D)=\sqrt{(3-6)^2+(7-8)^2}=\sqrt{9+1}=\sqrt{10}\approx3.16$$

**Distance from E**

$$d(P,E)=\sqrt{(3-7)^2+(7-1)^2}=\sqrt{16+36}=\sqrt{52}\approx7.21$$

#### Step 3 — Arrange distances in ascending order

| Rank | Point | Distance | Class |
|:-:|:-:|:-:|:-:|
| 1 | C | 1.00 | Blue |
| 2 | B | 3.16 | Red |
| 3 | D | 3.16 | Blue |
| 4 | A | 5.39 | Red |
| 5 | E | 7.21 | Red |

#### Step 4 — Majority voting

For $K=3$, the nearest neighbors are C, B, and D.
- Blue: 2 votes
- Red: 1 vote

$$\boxed{\text{Predicted class}=\text{Blue}}$$

#### Exam tips
- Always sort the distances before voting.
- $K$ means the number of neighbors, not the number of classes.
- If there is a tie in distance or voting, follow the tie-breaking rule specified in the question.
- Standard KNN can be sensitive to feature scales; normalization is often important.

---

<a id="n10"></a>
### 10. KNN classification — student pass/fail

**Original No.:** 12

#### Question

A student has scored 6 in Mathematics and 8 in Computer Science. Predict whether the student will Pass or Fail using KNN with $K=3$, based on the following training data.

| Point | Mathematics | Computer Science | Result |
|:-:|:-:|:-:|:-:|
| A | 4 | 3 | Fail |
| B | 6 | 7 | Pass |
| C | 7 | 8 | Pass |
| D | 5 | 5 | Fail |
| E | 8 | 8 | Pass |

The query point is $X=(6,8)$.

#### Step 1 — Write the Euclidean distance formula

For a query point $X=(x_1,x_2)$ and training point $A=(a_1,a_2)$,

$$d(X,A)=\sqrt{(x_1-a_1)^2+(x_2-a_2)^2}$$

#### Step 2 — Calculate the distance from each point

**Distance from A:**

$$d(X,A)=\sqrt{(6-4)^2+(8-3)^2}=\sqrt{4+25}=\sqrt{29}$$

$$\boxed{d(X,A)\approx5.39}$$

**Distance from B:**

$$d(X,B)=\sqrt{(6-6)^2+(8-7)^2}=\sqrt{0+1}=\boxed{1}$$

**Distance from C:**

$$d(X,C)=\sqrt{(6-7)^2+(8-8)^2}=\sqrt{1+0}=\boxed{1}$$

**Distance from D:**

$$d(X,D)=\sqrt{(6-5)^2+(8-5)^2}=\sqrt{1+9}=\boxed{\sqrt{10}\approx3.16}$$

**Distance from E:**

$$d(X,E)=\sqrt{(6-8)^2+(8-8)^2}=\sqrt{4+0}=\boxed{2}$$

#### Step 3 — Arrange the distances in ascending order

| Rank | Point | Distance | Result |
|:-:|:-:|:-:|:-:|
| 1 | B | 1.00 | Pass |
| 2 | C | 1.00 | Pass |
| 3 | E | 2.00 | Pass |
| 4 | D | 3.16 | Fail |
| 5 | A | 5.39 | Fail |

#### Step 4 — Apply majority voting

Since $K=3$, select the three nearest neighbors: B, C and E.
- Pass votes = 3
- Fail votes = 0

$$\boxed{\text{Predicted result}=\text{Pass}}$$

#### Exam tips
- Calculate all distances before selecting neighbors.
- Choose the $K$ smallest distances.
- The class with the majority vote becomes the prediction.

---

<a id="n11"></a>
### 11. SVM margin and classification

**Original No.:** 7

#### Question

Consider the decision boundary

$$w^Tx+b=0$$

where $w=(1,1)$ and $b=-2$, giving the line

$$x_1+x_2-2=0$$

Find:
1. The margin width.
2. The predicted class of point $(3,0)$.

#### Step 1 — Calculate the norm of the weight vector

$$\|w\|=\sqrt{w_1^2+w_2^2}=\sqrt{1^2+1^2}$$

$$\boxed{\|w\|=\sqrt2}$$

#### Step 2 — Calculate the margin width

For a canonical SVM with support-vector functional margins equal to $+1$ and $-1$,

$$\text{Margin width}=\frac2{\|w\|}=\frac2{\sqrt2}$$

$$\boxed{\text{Margin width}=\sqrt2\approx1.414}$$

#### Step 3 — Classify $(3,0)$

The decision function is

$$f(x)=w^Tx+b$$

Substitute:

$$f(3,0)=1(3)+1(0)-2$$

$$\boxed{f(3,0)=1}$$

Since $f(x)>0$, the point belongs to the positive class.

$$\boxed{\hat y=+1}$$

> **Important qualification:** The margin formula $2/\|w\|$ assumes the canonical scaling of an SVM. The given line has that geometric normal vector, but the claimed points $(2,2)$ and $(0,0)$ are not both support vectors for this line: $(2,2)$ is not on the margin line $x_1+x_2=3$, and $(0,0)$ lies on the opposite side of the decision boundary. Use the supplied boundary for the requested calculation, but don't treat those points as a consistent support-vector pair.

---

<a id="n12"></a>
### 12. Polynomial kernel and feature mapping

**Original No.:** 8

#### Question

Given $x=(1,2)$, $z=(3,4)$, and the polynomial kernel

$$K(x,z)=(x^Tz+1)^2$$

calculate the kernel value. Verify it using the corresponding feature mapping.

#### Step 1 — Calculate the dot product

$$x^Tz=x_1z_1+x_2z_2=(1)(3)+(2)(4)=3+8$$

$$\boxed{x^Tz=11}$$

#### Step 2 — Calculate the kernel value

$$K(x,z)=(x^Tz+1)^2=(11+1)^2=12^2$$

$$\boxed{K(x,z)=144}$$

#### Step 3 — Verify using the feature mapping

For the degree-2 polynomial kernel $(x^Tz+1)^2$, one valid feature map is

$$\phi(a,b)=[a^2,\sqrt2ab,b^2,\sqrt2a,\sqrt2b,1]$$

Therefore,

$$\phi(x)=[1,2\sqrt2,4,\sqrt2,2\sqrt2,1]$$

$$\phi(z)=[9,12\sqrt2,16,3\sqrt2,4\sqrt2,1]$$

Calculate their dot product:

$$\begin{aligned}
\phi(x)^T\phi(z)
&=9+48+64+6+16+1\\
&=144
\end{aligned}$$

Hence,

$$\boxed{\phi(x)^T\phi(z)=K(x,z)=144}$$

**Conclusion:** The kernel trick calculates a dot product in an implicit feature space without requiring explicit feature transformation.

> **Exam tip:** Use the exact kernel specified in the question. A polynomial kernel can be written $(x^Tz+c)^d$; changing $c$ or $d$ changes the result.

---

## Part 4 — Probability and Bayesian classification

<a id="n13"></a>
### 13. Bayes' theorem — two bags

**Original No.:** 14

#### Question

Two bags are selected with equal probability. Bag 1 contains 2 red and 3 black balls, while Bag 2 contains 1 red and 3 black balls.

A ball is drawn and is found to be red. Find the probability that it was drawn from Bag 1.

#### Step 1 — Write the given probabilities

Let $B_1$ and $B_2$ represent selecting Bag 1 and Bag 2, respectively. Let $R$ represent drawing a red ball.

Since both bags are equally likely to be selected,

$$P(B_1)=P(B_2)=\frac12$$

For Bag 1:

$$P(R\mid B_1)=\frac25$$

For Bag 2:

$$P(R\mid B_2)=\frac14$$

#### Step 2 — Calculate the total probability of drawing red

Using the law of total probability,

$$P(R)=P(R\mid B_1)P(B_1)+P(R\mid B_2)P(B_2)$$

Substitute:

$$P(R)=\frac25\times\frac12+\frac14\times\frac12=\frac15+\frac18$$

Taking the LCM:

$$P(R)=\frac8{40}+\frac5{40}$$

$$\boxed{P(R)=\frac{13}{40}}$$

#### Step 3 — Apply Bayes' theorem

We need to find $P(B_1\mid R)$.

$$P(B_1\mid R)=\frac{P(R\mid B_1)P(B_1)}{P(R)}$$

Substitute:

$$P(B_1\mid R)=\frac{\frac25\times\frac12}{\frac{13}{40}}=\frac{\frac15}{\frac{13}{40}}$$

Dividing by a fraction means multiplying by its reciprocal:

$$=\frac15\times\frac{40}{13}$$

$$\boxed{P(B_1\mid R)=\frac8{13}\approx0.6154}$$

**Final answer:** The probability that the red ball came from Bag 1 is approximately **61.54%**.

#### Exam tips
- $P(B_1)$ is the prior probability of selecting Bag 1.
- $P(R\mid B_1)$ is the probability of drawing red given Bag 1.
- $P(B_1\mid R)$ is the posterior probability of Bag 1 given that red was drawn.
- Do not confuse $P(R\mid B_1)$ with $P(B_1\mid R)$.

---

<a id="n14"></a>
### 14. Naïve Bayes — Play prediction

**Original No.:** 10

#### Question

Given the following training data, predict whether Play = Yes or No when Outlook = Sunny.

| Outlook | Play |
|:-:|:-:|
| Sunny | No |
| Sunny | No |
| Overcast | Yes |
| Rain | Yes |
| Yes | Yes |
| Sunny | Yes |
| Overcast | Yes |
| Rain | No |
| Sunny | No |
| Sunny | Yes |

> **Note:** The fifth row in the supplied text appears to have a missing Outlook value. The calculation below uses the stated class totals and Sunny counts, assuming the intended dataset has 10 complete observations, 6 Yes, 4 No, 2 Sunny among Yes, and 3 Sunny among No. The incomplete row should be checked against your original PDF before using this as an exact dataset reconstruction.

#### Step 1 — Calculate prior probabilities

There are 10 observations.

$$P(\text{Yes})=\frac6{10}=0.6,\qquad P(\text{No})=\frac4{10}=0.4$$

#### Step 2 — Calculate likelihoods

From the supplied counts:

$$P(\text{Sunny}\mid\text{Yes})=\frac26=\frac13,\qquad P(\text{Sunny}\mid\text{No})=\frac34=0.75$$

#### Step 3 — Apply Bayes' theorem

$$P(C\mid X)=\frac{P(X\mid C)P(C)}{P(X)}$$

For classification, first calculate the unnormalized scores.

**For Yes:**

$$P(\text{Sunny}\mid\text{Yes})P(\text{Yes})=\frac26\times\frac6{10}=\boxed{0.200}$$

**For No:**

$$P(\text{Sunny}\mid\text{No})P(\text{No})=\frac34\times\frac4{10}=\boxed{0.300}$$

#### Step 4 — Normalize the scores

The sum of the scores is

$$P(\text{Sunny})=0.200+0.300=0.500$$

Therefore,

$$P(\text{Yes}\mid\text{Sunny})=\frac{0.200}{0.500}=\boxed{0.40}$$

$$P(\text{No}\mid\text{Sunny})=\frac{0.300}{0.500}=\boxed{0.60}$$

#### Final answer

Since $0.60>0.40$,

$$\boxed{\text{Predicted class}=\text{No}}$$

#### Exam tips
- Prior = probability of a class before observing the feature.
- Likelihood = probability of the observed feature given the class.
- Posterior = probability of the class given the observed feature.
- For multiple features, Naïve Bayes multiplies the conditional likelihoods under its conditional-independence assumption.
- If a feature value has zero frequency for a class, Laplace smoothing may be needed.

---

<a id="n15"></a>
### 15. Naïve Bayes — student result

**Original No.:** 15

#### Question

A dataset records students' Year, Gender, Subject and Result. Predict the Result for a student with:
- Year = FY
- Gender = F
- Subject = S1

The supplied dataset has 10 observations, with 5 Pass and 5 Fail results.

#### Step 1 — Calculate prior probabilities

$$P(\text{Pass})=\frac5{10}=0.5$$

$$P(\text{Fail})=\frac5{10}=0.5$$

#### Step 2 — Calculate the conditional probabilities

The counts in the supplied handwritten solution give the following probabilities.

| Feature | Conditional probability | Pass | Fail |
|:-:|:-:|:-:|:-:|
| Year | $P(FY\mid Result)$ | $3/5$ | $2/5$ |
| Year | $P(SY\mid Result)$ | $2/5$ | $3/5$ |
| Gender | $P(M\mid Result)$ | $4/5$ | $2/5$ |
| Gender | $P(F\mid Result)$ | $1/5$ | $3/5$ |
| Subject | $P(S1\mid Result)$ | $2/5$ | $3/5$ |
| Subject | $P(S2\mid Result)$ | $3/5$ | $2/5$ |

#### Step 3 — Calculate the score for Pass

For the query $X=(FY,F,S1)$,

$$\begin{aligned}
Score(\text{Pass})={}&P(\text{Pass})\\
&\times P(FY\mid\text{Pass})\\
&\times P(F\mid\text{Pass})\\
&\times P(S1\mid\text{Pass})
\end{aligned}$$

Substitute:

$$=\frac5{10}\times\frac35\times\frac15\times\frac25=\frac12\times\frac35\times\frac15\times\frac25$$

$$\boxed{Score(\text{Pass})=0.024}$$

#### Step 4 — Calculate the score for Fail

$$\begin{aligned}
Score(\text{Fail})={}&P(\text{Fail})\\
&\times P(FY\mid\text{Fail})\\
&\times P(F\mid\text{Fail})\\
&\times P(S1\mid\text{Fail})
\end{aligned}$$

Substitute:

$$=\frac5{10}\times\frac25\times\frac35\times\frac35=\frac12\times\frac25\times\frac35\times\frac35$$

$$\boxed{Score(\text{Fail})=0.072}$$

#### Step 5 — Compare the scores

$$Score(\text{Fail})>Score(\text{Pass})\quad\Rightarrow\quad 0.072>0.024$$

$$\boxed{\text{Predicted Result}=\text{Fail}}$$

#### Exam tips
- Multiply the prior by the likelihood of every given feature.
- Use the conditional probabilities corresponding to the same class throughout each calculation.
- Compare unnormalized scores to select the class.
- The table above follows the conditional counts written in your notes; check them against the original dataset if your teacher expects exact row-by-row calculations.

---

<a id="n16"></a>
### 16. Naïve Bayes — email spam

**Original No.:** 16

#### Question

Given the following training data, classify an email with Free = Yes and Win = Yes as Spam or Not Spam using Naïve Bayes.

| Email | Free | Win | Class |
|:-:|:-:|:-:|:-:|
| 1 | Yes | Yes | Spam |
| 2 | Yes | No | Spam |
| 3 | No | Yes | Spam |
| 4 | No | No | Not Spam |
| 5 | Yes | No | Not Spam |
| 6 | No | No | Not Spam |

#### Step 1 — Calculate prior probabilities

There are 6 emails: 3 Spam and 3 Not Spam.

$$P(\text{Spam})=\frac36=0.5$$

$$P(\text{Not Spam})=\frac36=0.5$$

#### Step 2 — Calculate conditional probabilities

For Spam emails:

$$P(Free=Yes\mid Spam)=\frac23,\qquad P(Win=Yes\mid Spam)=\frac23$$

For Not Spam emails:

$$P(Free=Yes\mid NotSpam)=\frac13,\qquad P(Win=Yes\mid NotSpam)=\frac03=0$$

#### Step 3 — Calculate the Spam score

$$\begin{aligned}
Score(Spam)={}&P(Spam)\\
&\times P(Free=Yes\mid Spam)\\
&\times P(Win=Yes\mid Spam)
\end{aligned}$$

$$=\frac12\times\frac23\times\frac23$$

$$\boxed{Score(Spam)=\frac29\approx0.2222}$$

#### Step 4 — Calculate the Not Spam score

$$\begin{aligned}
Score(NotSpam)={}&P(NotSpam)\\
&\times P(Free=Yes\mid NotSpam)\\
&\times P(Win=Yes\mid NotSpam)
\end{aligned}$$

$$=\frac12\times\frac13\times0$$

$$\boxed{Score(NotSpam)=0}$$

#### Step 5 — Predict the class

Since the Spam score is greater,

$$\boxed{\text{Predicted class}=\text{Spam}}$$

#### Optional extension — Laplace smoothing

The zero likelihood occurs because the training data contains no Not Spam emails with Win = Yes. Laplace smoothing avoids assigning a zero probability to an unseen feature value.

For a binary feature, with add-one smoothing, apply it to **both** classes:

$$P(Win=Yes\mid NotSpam)=\frac{0+1}{3+2}=\frac15,\qquad P(Free=Yes\mid NotSpam)=\frac{1+1}{3+2}=\frac25$$

$$P(Free=Yes\mid Spam)=\frac{2+1}{3+2}=\frac35,\qquad P(Win=Yes\mid Spam)=\frac{2+1}{3+2}=\frac35$$

The smoothed scores become

$$Score(NotSpam)=\frac12\times\frac25\times\frac15\quad\Rightarrow\quad\boxed{0.04}$$

$$Score(Spam)=\frac12\times\frac35\times\frac35\quad\Rightarrow\quad\boxed{0.18}$$

Since $0.18>0.04$, the prediction remains Spam.

#### Exam tips
- Calculate the prior and likelihoods separately for each class.
- Multiply them to obtain each class score.
- A zero likelihood makes the entire unsmoothed score zero.
- Apply Laplace smoothing only if the question asks for it or the model specifies it.
- When smoothing, smooth the likelihoods of every class, not just the one with the zero.

---

<a id="n17"></a>
### 17. Naïve Bayes — fruit identification

**Original No.:** 13

#### Question

A fruit dataset contains the following counts. Given that a fruit is Yellow, Sweet and Long, predict whether it is an Orange, Banana or another fruit using Naïve Bayes.

| Fruit | Yellow | Sweet | Long | Total |
|:-:|:-:|:-:|:-:|:-:|
| Orange | 350 | 450 | 0 | 650 |
| Banana | 400 | 300 | 350 | 400 |
| Other | 50 | 100 | 50 | 150 |
| **Total** | 800 | 850 | 400 | 1200 |

> **Important:** These handwritten counts are internally inconsistent. For example, Orange's attribute counts sum to 800, not 650; Banana's sum to 1,050, not 400. Therefore, the exact probabilities cannot all be valid for one dataset. The worked solution below follows the conditional probabilities used in the handwritten solution to illustrate the method, rather than claiming the table is a consistent frequency dataset.

#### Step 1 — Write Bayes' theorem

$$P(C\mid X)=\frac{P(X\mid C)P(C)}{P(X)}$$

For Naïve Bayes, the feature likelihoods are multiplied under the conditional-independence assumption:

$$P(C\mid X)\propto P(C)\prod_jP(x_j\mid C)$$

Here, $X=\{\text{Yellow, Sweet, Long}\}$.

#### Step 2 — Calculate the prior probabilities

Using the totals shown:

$$P(\text{Orange})=\frac{650}{1200},\qquad P(\text{Banana})=\frac{400}{1200},\qquad P(\text{Other})=\frac{150}{1200}$$

These priors sum to 1, based on the stated totals.

#### Step 3 — Calculate the class scores

The handwritten calculations use these approximate conditional probabilities:

| Feature likelihood | Orange | Banana | Other |
|:-:|:-:|:-:|:-:|
| $P(\text{Yellow}\mid C)$ | 0.50 | 1.00 | 0.33 |
| $P(\text{Sweet}\mid C)$ | 0.69 | 0.75 | 0.66 |
| $P(\text{Long}\mid C)$ | 0.00 | 0.87 | 0.33 |

Calculate the unnormalized scores:

**Orange:**

$$P(X\mid O)P(O)=0.50(0.69)(0)\,P(O)\quad\Rightarrow\quad\boxed{\text{Score}(O)=0}$$

**Banana:**

$$P(X\mid B)P(B)=1.00(0.75)(0.87)\,P(B)=0.6525\left(\frac{400}{1200}\right)$$

$$\boxed{\text{Score}(B)=0.2175}$$

**Other:**

$$P(X\mid T)P(T)=0.33(0.66)(0.33)\,P(T)=0.0719\left(\frac{150}{1200}\right)$$

$$\boxed{\text{Score}(T)\approx0.0090}$$

#### Step 4 — Select the class with the highest score

$$0.2175>0.0090>0$$

$$\boxed{\text{Predicted fruit}=\text{Banana}}$$

#### Exam tips
- In Naïve Bayes, calculate the prior and conditional likelihood for every class.
- Multiply them to obtain unnormalized scores.
- Compare the scores; normalization is unnecessary when only the winning class is required.
- If any feature has zero likelihood, the entire class score becomes zero. Laplace smoothing can avoid this problem.
- For an exam, use a corrected frequency table if the question supplies one. Do not mix inconsistent totals and conditional probabilities.

---

## Part 5 — Decision trees

<a id="n18"></a>
### 18. ID3 — entropy and information gain

**Original No.:** 1

#### Question

The following dataset contains 14 days of weather observations. Determine the root node of a decision tree using the ID3 algorithm, calculating the information gain for Weather, Temperature, Humidity, and Wind. Then continue splitting the dataset to construct the decision tree.

| Day | Weather | Temp. | Humidity | Wind | Play? |
|:-:|:-:|:-:|:-:|:-:|:-:|
| 1 | Sunny | Hot | High | Weak | No |
| 2 | Sunny | Hot | High | Strong | No |
| 3 | Cloudy | Hot | High | Weak | Yes |
| 4 | Rain | Mild | High | Weak | Yes |
| 5 | Rain | Cool | Normal | Weak | Yes |
| 6 | Rain | Cool | Normal | Strong | No |
| 7 | Cloudy | Cool | Normal | Strong | Yes |
| 8 | Sunny | Mild | High | Weak | No |
| 9 | Sunny | Cool | Normal | Weak | Yes |
| 10 | Rain | Mild | Normal | Weak | Yes |
| 11 | Sunny | Mild | Normal | Strong | Yes |
| 12 | Cloudy | Mild | High | Strong | Yes |
| 13 | Cloudy | Hot | Normal | Weak | Yes |
| 14 | Rain | Mild | High | Strong | No |

#### Step 1 — Calculate the entropy of the complete dataset

There are 14 instances:
- Play = Yes: 9
- Play = No: 5

The entropy formula is

$$H(S)=-\sum_{i=1}^{c}p_i\log_2p_i$$

For a binary classification problem:

$$H(S)=-p_{\text{Yes}}\log_2p_{\text{Yes}}-p_{\text{No}}\log_2p_{\text{No}}$$

Substituting the values:

$$H(S)=-\frac9{14}\log_2\frac9{14}-\frac5{14}\log_2\frac5{14}$$

$$H(S)=-(0.6429)(-0.6374)-(0.3571)(-1.4854)\approx 0.9403$$

**Answer:**

$$\boxed{H(S)\approx0.940\text{ bits}}$$

#### Step 2 — Calculate information gain for Weather

The information gain formula is

$$IG(S,A)=H(S)-\sum_{v\in Values(A)}\frac{|S_v|}{|S|}H(S_v)$$

Here, $S_v$ is the subset corresponding to a particular value of the attribute.

For Weather, the subsets are:

| Weather | Yes | No | Total |
|:-:|:-:|:-:|:-:|
| Sunny | 2 | 3 | 5 |
| Cloudy | 4 | 0 | 4 |
| Rain | 3 | 2 | 5 |
| **Total** | 9 | 5 | 14 |

**A. Entropy of Sunny**

$$H(\text{Sunny})=-\frac25\log_2\frac25-\frac35\log_2\frac35\approx0.971$$

**B. Entropy of Cloudy**

All four instances are Yes, so the subset is pure.

$$H(\text{Cloudy})=-1\log_2 1-0\log_2 0$$

Using the convention $0\log_2 0=0$:

$$\boxed{H(\text{Cloudy})=0}$$

**C. Entropy of Rain**

$$H(\text{Rain})=-\frac35\log_2\frac35-\frac25\log_2\frac25\approx0.971$$

**D. Weighted entropy after splitting on Weather**

$$H(S\mid\text{Weather})=\frac5{14}H(\text{Sunny})+\frac4{14}H(\text{Cloudy})+\frac5{14}H(\text{Rain})$$

$$=\frac5{14}(0.971)+\frac4{14}(0)+\frac5{14}(0.971)\approx0.6936$$

Therefore,

$$IG(S,\text{Weather})=0.9403-0.6936$$

$$\boxed{IG(S,\text{Weather})\approx0.247}$$

#### Step 3 — Calculate information gain for Temperature

The subsets are:

| Temperature | Yes | No | Total |
|:-:|:-:|:-:|:-:|
| Hot | 2 | 2 | 4 |
| Mild | 4 | 2 | 6 |
| Cool | 3 | 1 | 4 |

**A. Entropy of Hot**

$$H(\text{Hot})=-\frac24\log_2\frac24-\frac24\log_2\frac24=1$$

**B. Entropy of Mild**

$$H(\text{Mild})=-\frac46\log_2\frac46-\frac26\log_2\frac26\approx0.9183$$

**C. Entropy of Cool**

$$H(\text{Cool})=-\frac34\log_2\frac34-\frac14\log_2\frac14\approx0.8113$$

**Weighted entropy:**

$$H(S\mid T)=\frac4{14}(1)+\frac6{14}(0.9183)+\frac4{14}(0.8113)$$

$$H(S\mid T)\approx0.2857+0.3936+0.2318\approx0.9111$$

Therefore,

$$IG(S,T)=0.9403-0.9111$$

$$\boxed{IG(S,T)\approx0.0292}$$

#### Step 4 — Calculate information gain for Humidity

| Humidity | Yes | No | Total |
|:-:|:-:|:-:|:-:|
| High | 3 | 4 | 7 |
| Normal | 6 | 1 | 7 |

**A. Entropy of High**

$$H(\text{High})=-\frac37\log_2\frac37-\frac47\log_2\frac47\approx0.9852$$

**B. Entropy of Normal**

$$H(\text{Normal})=-\frac67\log_2\frac67-\frac17\log_2\frac17\approx0.5917$$

**Weighted entropy:**

$$H(S\mid H)=\frac7{14}(0.9852)+\frac7{14}(0.5917)\approx0.7885$$

Therefore,

$$\boxed{IG(S,H)\approx0.1518}$$

#### Step 5 — Calculate information gain for Wind

| Wind | Yes | No | Total |
|:-:|:-:|:-:|:-:|
| Weak | 6 | 2 | 8 |
| Strong | 3 | 3 | 6 |

**A. Entropy of Weak**

$$H(\text{Weak})=-\frac68\log_2\frac68-\frac28\log_2\frac28\approx0.8113$$

**B. Entropy of Strong**

$$H(\text{Strong})=-\frac36\log_2\frac36-\frac36\log_2\frac36=1$$

**Weighted entropy:**

$$H(S\mid W)=\frac8{14}(0.8113)+\frac6{14}(1)\approx0.8922$$

Therefore,

$$\boxed{IG(S,W)\approx0.0481}$$

#### Step 6 — Select the root node

| Attribute | Information Gain |
|:-:|:-:|
| Weather | 0.2467 |
| Temperature | 0.0292 |
| Humidity | 0.1518 |
| Wind | 0.0481 |

The attribute with the highest information gain becomes the root.

$$\boxed{\text{Root node}=\text{Weather}}$$

#### Step 7 — Construct the decision tree

For the Sunny subset, Humidity separates the outcomes perfectly. For Rain, Wind separates the outcomes perfectly. Cloudy already contains only Yes outcomes.

```
Weather
├── Sunny  → Humidity
│            ├── High   → No
│            └── Normal → Yes
├── Cloudy → Yes
└── Rain   → Wind
             ├── Weak   → Yes
             └── Strong → No
```

**Final result:** Weather is the root node; the tree classifies all 14 training examples correctly.

#### Exam tips
- Use base-2 logarithms for entropy.
- The entropy of a pure node is zero.
- Compare information gains only after calculating each attribute's weighted entropy.
- Recalculate the best attribute for each impure subset; don't automatically reuse the original root calculation.

---

<a id="n19"></a>
### 19. Decision tree — information gain calculation

**Original No.:** 11

#### Question

A dataset contains 10 observations: 6 Yes and 4 No. The dataset is split using the attribute Outlook.

| Outlook | Yes | No | Total |
|:-:|:-:|:-:|:-:|
| Sunny | 2 | 3 | 5 |
| Overcast | 2 | 0 | 2 |
| Rain | 2 | 1 | 3 |
| **Total** | 6 | 4 | 10 |

Calculate the information gain of Outlook.

#### Step 1 — Calculate the entropy of the parent dataset

$$H(S)=-\sum_i p_i\log_2p_i$$

$$H(S)=-\frac6{10}\log_2\frac6{10}-\frac4{10}\log_2\frac4{10}$$

$$=-0.6\log_2(0.6)-0.4\log_2(0.4)=0.4422+0.5288$$

$$\boxed{H(S)\approx0.9710}$$

#### Step 2 — Calculate the entropy of each subset

**A. Sunny: 2 Yes, 3 No**

$$H(\text{Sunny})=-\frac25\log_2\frac25-\frac35\log_2\frac35$$

$$\boxed{H(\text{Sunny})\approx0.9710}$$

**B. Overcast: 2 Yes, 0 No**

This is a pure subset.

$$\boxed{H(\text{Overcast})=0}$$

**C. Rain: 2 Yes, 1 No**

$$H(\text{Rain})=-\frac23\log_2\frac23-\frac13\log_2\frac13$$

$$\boxed{H(\text{Rain})\approx0.9183}$$

#### Step 3 — Calculate weighted entropy

$$\begin{aligned}
H(S\mid\text{Outlook})={}&
\frac5{10}H(\text{Sunny})\\
&+\frac2{10}H(\text{Overcast})\\
&+\frac3{10}H(\text{Rain})
\end{aligned}$$

Substitute:

$$=\frac5{10}(0.9710)+\frac2{10}(0)+\frac3{10}(0.9183)=0.4855+0+0.2755$$

$$\boxed{H(S\mid\text{Outlook})\approx0.7610}$$

#### Step 4 — Calculate information gain

$$IG(S,\text{Outlook})=H(S)-H(S\mid\text{Outlook})=0.9710-0.7610$$

$$\boxed{IG(S,\text{Outlook})\approx0.2100}$$

**Final answer:** The information gain of Outlook is approximately **0.21 bits**.

The attribute with the highest information gain among the candidate attributes is selected as the splitting node in ID3.

---

<a id="n20"></a>
### 20. ID3 — next-level tree construction

**Original No.:** —

*Covered in [#18](#n18): Step 7 continues the splits on the Sunny and Rain subsets and builds the complete tree.*

---

<a id="n21"></a>
### 21. Gini Index and weighted Gini

**Original No.:** 2

#### Question

Given the dataset below, use the Gini Index to evaluate the split at Loan Amount ≥ 200.

| ID | Loan Amount | Loan Status |
|:-:|:-:|:-:|
| 1 | 100 | Bad |
| 2 | 200 | Good |
| 3 | 250 | Bad |
| 4 | 150 | Good |
| 5 | 300 | Bad |

#### Step 1 — Write the Gini formula

$$Gini(S)=1-\sum_{i=1}^{c}p_i^2$$

For two classes:

$$Gini(S)=1-p_{\text{Good}}^2-p_{\text{Bad}}^2$$

A smaller Gini Index indicates a purer node.

#### Step 2 — Divide the dataset

For Loan Amount ≥ 200:
- True: IDs 2, 3, 5 → Good = 1, Bad = 2.
- False: IDs 1, 4 → Good = 1, Bad = 1.

#### Step 3 — Calculate the Gini Index of the True subset

$$Gini(T)=1-\left(\frac13\right)^2-\left(\frac23\right)^2=1-\frac19-\frac49$$

$$\boxed{Gini(T)=\frac49\approx0.4444}$$

#### Step 4 — Calculate the Gini Index of the False subset

$$Gini(F)=1-\left(\frac12\right)^2-\left(\frac12\right)^2=1-\frac14-\frac14$$

$$\boxed{Gini(F)=0.5}$$

#### Step 5 — Calculate the weighted Gini Index

The formula is

$$Gini_{\text{split}}=\frac{|T|}{|S|}Gini(T)+\frac{|F|}{|S|}Gini(F)$$

Substituting:

$$Gini_{\text{split}}=\frac35\left(\frac49\right)+\frac25\left(\frac12\right)=\frac4{15}+\frac15$$

$$\boxed{Gini_{\text{split}}=\frac7{15}\approx0.4667}$$

#### Final answer

$$\boxed{Gini_{\text{split}}\approx0.467}$$

The split produces a weighted Gini Index of approximately 0.467.

> **Important correction:** The handwritten solution's weighted result of $4/15$ assumes a pure two-instance branch and a three-instance branch with class proportions 2:1. That does not match the five records and threshold shown in the question. For the actual supplied data, the correct result is $7/15$.

> **Exam tip:** When asked to select the best split, calculate the weighted Gini Index for every candidate split and choose the one with the lowest value. A single split's score alone does not prove it is the best.

---

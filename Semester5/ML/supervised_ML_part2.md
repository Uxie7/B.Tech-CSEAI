# UNIT II — Supervised Learning

## Index

- [2. Classification & Models — Part A](#2-classification--models--part-a)
  - [2.1 Logistic Regression](#21-logistic-regression)
  - [2.2 Support Vector Machines (SVM)](#22-support-vector-machines-svm)
  - [2.3 Kernels for Learning Non-linear Functions](#23-kernels-for-learning-non-linear-functions)
  - [2.4 Logistic Regression versus SVM](#24-logistic-regression-versus-svm)
  - [2.5 Final numerical index for this block](#25-final-numerical-index-for-this-block)
  - [2.6 Exam revision checklist](#26-exam-revision-checklist)

---

## 2. Classification & Models — Part A

We'll cover these three topics end to end:

1. Logistic Regression
2. Support Vector Machines (SVM)
3. Kernels for learning non-linear functions

We'll preserve your original numerical numbering: 7, 8 and 9.

---

### 2.1 Logistic Regression

#### A. Definition

Logistic Regression is a supervised learning algorithm primarily used for classification. It estimates the probability that an observation belongs to a particular class and assigns a class label using a decision threshold.

Despite its name, Logistic Regression is generally used for classification rather than predicting an unrestricted continuous output.

**Example:** Predict whether an email is spam, whether a student passes, or whether a transaction is fraudulent.

#### B. Why not use ordinary linear regression for classification?

Suppose we encode the target as:

- Pass = 1
- Fail = 0

Ordinary linear regression can produce predictions below 0 or above 1, which are not valid probabilities. Logistic Regression applies the sigmoid function to map its output into the interval $(0,1)$.

#### C. Logistic Regression model

First, calculate a linear score:

$$
z=b_0+b_1x_1+b_2x_2+\cdots+b_px_p
$$

Then apply the sigmoid function:

$$
\boxed{\sigma(z)=\frac{1}{1+e^{-z}}}
$$

Therefore,

$$
\boxed{P(y=1\mid X)=\frac{1}{1+e^{-z}}}
$$

Where:

- $X$ = input feature vector.
- $x_j$ = value of feature $j$.
- $b_0$ = intercept.
- $b_j$ = coefficient of feature $j$.
- $z$ = linear score.
- $e$ = base of the natural logarithm.
- $\sigma(z)$ = sigmoid output.
- $P(y=1\mid X)$ = estimated probability of the positive class given the input.

The output is always strictly between 0 and 1.

#### D. Understanding the sigmoid function

##### Shape of the sigmoid curve

The sigmoid maps any real-valued score to a probability-like value between 0 and 1.

Important values:

| Linear score $z$ | Sigmoid $\sigma(z)$ | Interpretation |
|---|---|---|
| $-\infty$ | Approaches 0 | Very low positive-class probability |
| $-2$ | 0.1192 | About 11.92% |
| $0$ | 0.5 | 50% |
| $2$ | 0.8808 | About 88.08% |
| $+\infty$ | Approaches 1 | Very high positive-class probability |

When $z=0$, the sigmoid output is exactly 0.5.

#### E. Decision threshold

The probability is converted into a class label using a threshold.

For the common threshold of 0.5:

$$
\hat y=
\begin{cases}
1, & P(y=1\mid X)\geq 0.5\\
0, & P(y=1\mid X)<0.5
\end{cases}
$$

Where $\hat y$ is the predicted class.

For example, if the estimated probability of passing is 0.82, the model predicts Pass at a threshold of 0.5.

The threshold need not always be 0.5. A lower threshold can increase recall for the positive class but may also increase false positives.

#### F. Worked numerical — sigmoid and classification

Suppose the model is:

$$
z=-4+1.2x
$$

For an observation with $x=5$:

**Step 1: Calculate the linear score**

$$
z=-4+1.2(5)=2
$$

**Step 2: Apply the sigmoid**

$$
P(y=1\mid x)=\frac{1}{1+e^{-2}}
$$

Using $e^{-2}\approx0.1353$:

$$
P(y=1\mid x)=\frac{1}{1.1353}
\approx\boxed{0.8808}
$$

**Step 3: Apply the threshold**

Since $0.8808\geq0.5$, the predicted class is:

$$
\boxed{\hat y=1}
$$

If class 1 represents Pass, the model predicts Pass.

#### G. Log-odds and interpretation of coefficients

Logistic Regression models the logarithm of the odds as a linear function:

$$
\boxed{
\ln\left(\frac{p}{1-p}\right)
=b_0+b_1x_1+\cdots+b_px_p
}
$$

Where $p=P(y=1\mid X)$.

- **Odds:** $p/(1-p)$, the probability of the positive class divided by the probability of the negative class.
- **Log-odds:** Natural logarithm of the odds.
- A coefficient $b_j$ represents the change in log-odds for a one-unit increase in feature $x_j$, holding the other features constant.
- The odds are multiplied by $e^{b_j}$ for a one-unit increase in $x_j$, holding other features constant.

A positive coefficient increases the estimated positive-class probability as that feature increases; a negative coefficient decreases it, assuming other features remain fixed.

#### H. Log-loss (binary cross-entropy)

Logistic Regression commonly estimates its coefficients by minimizing log-loss.

$$
\boxed{
L=-\frac1n\sum_{i=1}^{n}
\left[y_i\ln(p_i)+(1-y_i)\ln(1-p_i)\right]
}
$$

Where:

- $L$ = average log-loss.
- $n$ = number of observations.
- $y_i\in\{0,1\}$ = actual class label.
- $p_i$ = predicted probability of class 1 for observation $i$.
- $\ln$ = natural logarithm.

Log-loss penalizes confident incorrect predictions heavily.

**Worked example:** Suppose the actual label is $y=1$ and the predicted probability is $p=0.8$.

$$
L=-[1\ln(0.8)+0\ln(0.2)]
$$

$$
L=-\ln(0.8)\approx\boxed{0.2231}
$$

If the model instead predicted $p=0.1$:

$$
L=-\ln(0.1)\approx\boxed{2.3026}
$$

The second prediction receives a much larger loss because the model assigned a low probability to the true class.

#### I. Types, advantages and limitations

**Types**

- **Binary Logistic Regression:** Two classes, such as Pass/Fail.
- **Multinomial Logistic Regression:** More than two unordered classes.
- **Ordinal Logistic Regression:** Ordered class categories.

**Advantages**

- Produces interpretable probability estimates.
- Efficient and relatively simple to train.
- Works well when class separation is reasonably represented by a linear boundary in the features.
- Provides coefficients that help explain the relationship between features and class probabilities.

**Limitations**

- A basic model has a linear decision boundary in the original feature space.
- Complex nonlinear relationships may require feature engineering or other models.
- Multicollinearity can affect coefficient stability.
- Performance can be affected by class imbalance and inappropriate thresholds.
- Estimated probabilities may require calibration if reliable probability estimates are important.

---

### 2.2 Support Vector Machines (SVM)

#### A. Definition

A Support Vector Machine (SVM) is a supervised learning algorithm that finds a decision boundary separating classes while maximizing the margin between the boundary and the nearest training observations.

SVM is commonly used for classification and can also be adapted for regression.

#### B. Hyperplane and decision boundary

For two input features, a linear decision boundary is:

$$
w_1x_1+w_2x_2+b=0
$$

For $p$ features:

$$
\boxed{w^Tx+b=0}
$$

Where:

- $x$ = input feature vector.
- $w$ = weight vector perpendicular to the boundary.
- $w^T$ = transpose of $w$.
- $b$ = bias or intercept.

The classifier predicts a class using the sign of the decision function:

$$
f(x)=w^Tx+b
$$

For labels encoded as $-1$ and $+1$, a standard prediction rule is:

$$
\hat y=\operatorname{sign}(w^Tx+b)
$$

#### C. Margin

The margin is the distance between the decision boundary and the nearest training points. A maximum-margin classifier seeks a boundary with the largest possible separation from those points.

For a canonical linear SVM, the support hyperplanes are:

$$
w^Tx+b=+1
$$

and

$$
w^Tx+b=-1
$$

The distance between these hyperplanes is:

$$
\boxed{\text{Margin width}=\frac{2}{\|w\|}}
$$

Where $\|w\|$ is the Euclidean norm of the weight vector.

Thus, maximizing the margin is equivalent to minimizing $\|w\|^2/2$, subject to the classification constraints.

#### D. Support vectors

Support vectors are the training observations that determine or strongly influence the position of the decision boundary.

They lie on the margin boundaries or within the margin in a soft-margin SVM. Observations farther away generally have no direct effect on the fitted boundary once the model is fixed.

#### E. Hard-margin SVM

Hard-margin SVM assumes that the training data can be separated perfectly by a linear hyperplane.

Its optimization problem is:

$$
\boxed{
\min_{w,b}\frac12\|w\|^2
}
$$

Subject to:

$$
\boxed{y_i(w^Tx_i+b)\geq1}
$$

Where:

- $x_i$ = feature vector for observation $i$.
- $y_i\in\{-1,+1\}$ = class label.
- $w,b$ = hyperplane parameters.

The constraints require every training observation to lie on the correct side of the margin.

**Limitation:** Hard-margin SVM is highly sensitive to noise and outliers and is unsuitable when the training classes cannot be perfectly separated.

#### F. Soft-margin SVM

Real-world data is often noisy or overlapping. Soft-margin SVM permits some observations to violate the margin constraints using slack variables.

Its objective is:

$$
\boxed{
\min_{w,b,\xi}\frac12\|w\|^2+C\sum_{i=1}^{n}\xi_i
}
$$

Subject to:

$$
y_i(w^Tx_i+b)\geq1-\xi_i
$$

$$
\xi_i\geq0
$$

Where:

- $\xi_i$ = slack variable for observation $i$.
- $C>0$ = parameter controlling the penalty for margin violations.
- $n$ = number of training observations.

**Effect of $C$:**

- **Larger $C$:** Penalizes violations more heavily and tends to fit training data more strictly.
- **Smaller $C$:** Allows more violations in exchange for a wider, more regularized margin.

The best value is generally selected using validation or cross-validation.

#### G. Worked numerical — SVM margin width and classification

Suppose the decision boundary is:

$$
2x_1+x_2-4=0
$$

Thus, $w=(2,1)$ and $b=-4$.

**Step 1: Calculate the norm of the weight vector**

$$
\|w\|=\sqrt{2^2+1^2}=\sqrt5
$$

**Step 2: Calculate the canonical margin width**

$$
\text{Margin width}=\frac{2}{\sqrt5}
$$

$$
\boxed{\text{Margin width}\approx0.8944}
$$

This assumes the equation is in canonical SVM form, with support hyperplanes at decision-function values $+1$ and $-1$.

**Step 3: Classify the point $(3,1)$**

Calculate:

$$
f(x)=2(3)+1-4=3
$$

Since $f(x)>0$, the point is assigned to the positive class.

$$
\boxed{\hat y=+1}
$$

**Step 4: Classify the point $(1,1)$**

$$
f(x)=2(1)+1-4=-1
$$

Since $f(x)<0$, the point is assigned to the negative class.

$$
\boxed{\hat y=-1}
$$

**Important:** A decision boundary alone determines class labels, but the margin width formula $2/\|w\|$ requires the canonical scaling of the SVM equation.

#### H. Advantages and limitations of SVM

**Advantages**

- Effective in high-dimensional feature spaces.
- Uses support vectors to define the decision boundary.
- Can handle nonlinear classification using kernels.
- Maximum-margin learning can generalize well when appropriately regularized.

**Limitations**

- Can be expensive to train on very large datasets, particularly with nonlinear kernels.
- Performance depends on parameters such as $C$, kernel choice, and kernel parameters.
- Feature scaling is often important.
- Basic SVM does not directly produce calibrated class probabilities.
- Less interpretable than a simple linear model in many settings.

---

### 2.3 Kernels for Learning Non-linear Functions

#### A. Why are kernels needed?

A linear classifier may fail when the classes cannot be separated by a straight line or hyperplane in the original feature space.

A kernel method enables algorithms such as SVM to learn nonlinear decision boundaries by calculating inner products corresponding to a transformed feature space, without necessarily constructing the transformed features explicitly.

This is known as the **kernel trick**.

#### B. Feature mapping

Let the original input be $x$. A feature mapping transforms it into a higher-dimensional representation:

$$
\phi(x)
$$

Where:

- $x$ = original input.
- $\phi(x)$ = transformed feature vector.

A linear decision boundary in the transformed space can correspond to a nonlinear boundary in the original space.

**Illustrative example:** Suppose the input contains two features $x_1,x_2$. A mapping might introduce additional terms:

$$
\phi(x)=(x_1^2,\sqrt2x_1x_2,x_2^2)
$$

The model can now represent relationships involving squared and interaction terms.

Instead of calculating the full mapping for every observation, a kernel calculates the inner product directly.

#### C. Kernel function

A kernel function is commonly defined as:

$$
\boxed{K(x,z)=\phi(x)^T\phi(z)}
$$

Where:

- $x,z$ = two input vectors.
- $\phi(x),\phi(z)$ = their transformed feature vectors.
- $K(x,z)$ = inner product in the transformed feature space.

The kernel gives the similarity needed by the algorithm without requiring explicit construction of the mapped vectors.

#### D. Common kernel functions

| Kernel | Formula | Main use |
|---|---|---|
| Linear | $K(x,z)=x^Tz$ | Linear relationships or already suitable feature spaces |
| Polynomial | $K(x,z)=(x^Tz+c)^d$ | Nonlinear relationships involving polynomial interactions |
| RBF (Gaussian) | $K(x,z)=\exp(-\gamma\lVert x-z\rVert^2)$ | Flexible nonlinear decision boundaries |
| Sigmoid | $K(x,z)=\tanh(\alpha x^Tz+c)$ | Certain neural-network-like similarity formulations; valid kernel conditions depend on parameters |

Where:

- $c$ = constant offset.
- $d$ = polynomial degree.
- $\gamma$ = RBF kernel parameter controlling how quickly similarity decreases with distance.
- $\alpha$ = scaling parameter in the sigmoid kernel.

**RBF interpretation:** Points close together tend to have kernel values near 1, while points far apart tend to have values closer to 0 for $\gamma>0$.

#### E. Polynomial kernel — worked numerical

This connects directly to your original Numerical 9.

Suppose:

$$
x=(1,2),\qquad z=(3,4)
$$

Use a polynomial kernel of degree $d=2$, with $c=1$:

$$
K(x,z)=(x^Tz+c)^d
$$

**Step 1: Calculate the dot product**

$$
x^Tz=(1)(3)+(2)(4)=3+8=11
$$

**Step 2: Add the constant**

$$
x^Tz+c=11+1=12
$$

**Step 3: Raise to the specified degree**

$$
K(x,z)=12^2
$$

$$
\boxed{K(x,z)=144}
$$

This is the kernel value. It equals the dot product between the two observations' mapped feature vectors for the corresponding valid polynomial feature mapping.

#### F. Explicit polynomial mapping example

For two-dimensional inputs, consider:

$$
\phi(x_1,x_2)=
(x_1^2,\sqrt2x_1x_2,x_2^2)
$$

This mapping corresponds to the homogeneous degree-2 polynomial kernel:

$$
K(x,z)=(x^Tz)^2
$$

For $x=(1,2)$ and $z=(3,4)$:

$$
x^Tz=11
$$

Therefore:

$$
K(x,z)=11^2=\boxed{121}
$$

The mapped vectors are:

$$
\phi(x)=(1,2\sqrt2,4)
$$

$$
\phi(z)=(9,12\sqrt2,16)
$$

Their dot product is:

$$
\phi(x)^T\phi(z)
=(1)(9)+(2\sqrt2)(12\sqrt2)+(4)(16)
$$

$$
=9+48+64=\boxed{121}
$$

This verifies that the transformed-space dot product matches the kernel calculation.

**Exam distinction:** The polynomial kernel $(x^Tz+c)^d$ includes an offset $c$. The explicit mapping above corresponds to the special case $c=0,d=2$, not the offset version used in the preceding numerical.

#### G. How kernel SVM works

1. Select a suitable kernel.
2. Calculate kernel values between training observations.
3. Fit the SVM using those values.
4. Identify the support vectors and learn the decision boundary in the implicit feature space.
5. Calculate kernel values between a new observation and the support vectors.
6. Predict its class using the resulting decision function.

#### H. Choosing a kernel

- **Linear kernel:** A good starting point for high-dimensional or approximately linearly separable data.
- **Polynomial kernel:** Useful when polynomial interactions are meaningful.
- **RBF kernel:** A common choice when nonlinear relationships are expected but their exact form is unknown.
- **Sigmoid kernel:** Less commonly used; suitability depends on parameter settings and whether the resulting function satisfies kernel validity requirements.

Kernel choice and parameters should generally be selected using validation or cross-validation rather than the final test set.

---

### 2.4 Logistic Regression versus SVM

| Basis | Logistic Regression | SVM |
|---|---|---|
| Main objective | Estimate class probabilities using a logistic model | Find a maximum-margin decision boundary |
| Output | Probability estimates, then class labels | Decision scores and class labels; probabilities require additional calibration |
| Decision boundary | Linear in the supplied features in its basic form | Linear by default, or nonlinear with a suitable kernel |
| Optimization | Commonly minimizes log-loss | Commonly minimizes a margin-based objective with regularization |
| Important parameters | Regularization strength, threshold | $C$, kernel choice and kernel parameters |
| Interpretability | Coefficients can be interpreted through log-odds | Linear SVM coefficients can be inspected; nonlinear kernels are harder to interpret |
| Best suited for | Probability estimation and relatively interpretable classification | Maximum-margin classification, including nonlinear boundaries with kernels |
| Limitation | Basic form may not capture complex nonlinear boundaries | Can require more tuning and may be computationally expensive |

---

### 2.5 Final numerical index for this block

| No. | Topic | What to practise |
|---|---|---|
| 7 | Logistic Regression | Calculate the sigmoid probability, apply a classification threshold, and calculate log-loss. |
| 8 | Support Vector Machine | Calculate the margin width and classify a point using the decision function. |
| 9 | Polynomial Kernel | Calculate the kernel value and understand its equivalence to a mapped feature-space dot product. |

---

### 2.6 Exam revision checklist

- [ ] Define Logistic Regression and explain why it is used for classification.
- [ ] Write the sigmoid formula and calculate a probability.
- [ ] Apply a classification threshold.
- [ ] Explain log-odds and interpret a coefficient.
- [ ] Calculate binary log-loss.
- [ ] Define SVM, hyperplane, margin, and support vectors.
- [ ] Distinguish hard-margin and soft-margin SVM.
- [ ] Calculate margin width and classify a point.
- [ ] Explain the kernel trick and feature mapping.
- [ ] Differentiate linear, polynomial, RBF, and sigmoid kernels.
- [ ] Solve Numerical 9 and distinguish the offset polynomial kernel from the homogeneous polynomial kernel.

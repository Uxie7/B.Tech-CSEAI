# UNIT II — Supervised Learning

## Index

- [1. Regression](#1-regression)
  - [1.1 Least Mean Square Regression](#11-least-mean-square-regression)
  - [1.2 Ridge Regression](#12-ridge-regression)
  - [1.3 LASSO Regression](#13-lasso-regression)
  - [1.4 Comparison of all three regression methods](#14-comparison-of-all-three-regression-methods)
  - [1.5 Numerical index for this block](#15-numerical-index-for-this-block)
  - [1.6 Final revision checklist](#16-final-revision-checklist)

---

## 1. Regression

We'll cover the three syllabus topics completely, in this order:

1. Least Mean Square Regression
2. Ridge Regression
3. LASSO Regression

The goal is to understand the concepts, learn the formulas, see how each numerical is solved, and be ready to write theory answers in the exam.

---

### 1.1 Least Mean Square Regression

#### A. Definition

Least Mean Square (LMS) Regression is a regression method that estimates the relationship between input variables and a continuous output by minimizing the sum of squared differences between actual and predicted values.

In the usual linear-regression formulation taught with least squares, the objective is to find the line that best fits the observed data by minimizing squared prediction errors.

**Example:** Predicting a student's marks based on study hours, estimating house prices from their features, or forecasting sales from advertising expenditure.

#### B. Basic regression equation

For simple linear regression, the model is:

$$
\hat y=b_0+b_1x
$$

Where:

- $x$ = input or independent variable.
- $\hat y$ = predicted output.
- $b_0$ = intercept; predicted output when $x=0$.
- $b_1$ = slope; expected change in predicted output for a one-unit increase in $x$.

For example:

$$
\hat y=20+5x
$$

If $x=4$, then:

$$
\hat y=20+5(4)=40
$$

The predicted value is 40.

For multiple linear regression, the model becomes:

$$
\hat y=b_0+b_1x_1+b_2x_2+\cdots+b_px_p
$$

Here, $p$ is the number of input features, and $b_j$ is the coefficient associated with feature $x_j$.

#### C. Actual values, predicted values, and residuals

A regression model produces predictions, which can differ from the observed values.

$$
e_i=y_i-\hat y_i
$$

Where:

- $y_i$ = actual output for observation $i$.
- $\hat y_i$ = predicted output for observation $i$.
- $e_i$ = residual or prediction error for observation $i$.

| Actual value $y_i$ | Predicted value $\hat y_i$ | Residual $e_i=y_i-\hat y_i$ |
|---|---|---|
| 10 | 12 | -2 |
| 20 | 18 | 2 |
| 30 | 33 | -3 |
| 40 | 36 | 4 |

A positive residual means the model predicted too low. A negative residual means the model predicted too high.

The objective of least-squares regression is to find coefficients that make the overall squared residuals as small as possible.

#### D. Least-squares objective function

$$
\boxed{SSE=\sum_{i=1}^{n}(y_i-\hat y_i)^2}
$$

Where:

- $SSE$ = sum of squared errors or residual sum of squares.
- $n$ = number of observations.
- $y_i$ = actual value.
- $\hat y_i$ = predicted value.

Substituting the regression equation:

$$
SSE=\sum_{i=1}^{n}(y_i-b_0-b_1x_i)^2
$$

The method chooses $b_0$ and $b_1$ to minimize this expression.

**Why square the errors?**

1. Positive and negative residuals do not cancel one another.
2. Larger errors receive greater penalties.
3. The resulting objective can be optimized mathematically.

The mean squared error (MSE) is:

$$
MSE=\frac{1}{n}\sum_{i=1}^{n}(y_i-\hat y_i)^2
$$

Since $n$ is fixed for a dataset, minimizing SSE and minimizing MSE give the same coefficients.

#### E. Finding the regression coefficients

For simple linear regression, the least-squares estimates are:

$$
\boxed{b_1=\frac{\sum_{i=1}^{n}(x_i-\bar x)(y_i-\bar y)}
{\sum_{i=1}^{n}(x_i-\bar x)^2}}
$$

$$
\boxed{b_0=\bar y-b_1\bar x}
$$

Where:

- $\bar x$ = mean of the input values.
- $\bar y$ = mean of the output values.
- $b_1$ = estimated slope.
- $b_0$ = estimated intercept.

The slope measures how the predicted output changes with the input. The intercept fixes the position of the fitted line.

For multiple features, the ordinary least-squares solution can be expressed as:

$$
\hat{\boldsymbol{\beta}}=(X^TX)^{-1}X^Ty
$$

Where:

- $X$ = design matrix containing the input features, typically with a column of ones for the intercept.
- $X^T$ = transpose of $X$.
- $y$ = vector of actual output values.
- $\hat{\boldsymbol{\beta}}$ = vector of estimated coefficients.

This inverse-based formula applies when $X^TX$ is invertible. If it is singular, a pseudoinverse or another suitable numerical method can be used.

#### F. Worked numerical — finding the regression line

Suppose the dataset gives study hours $x$ and marks $y$:

| Student | Study hours $x$ | Marks $y$ |
|---|---|---|
| A | 1 | 2 |
| B | 2 | 3 |
| C | 3 | 5 |
| D | 4 | 4 |

**Step 1: Calculate the means**

$$
\bar x=\frac{1+2+3+4}{4}=2.5
$$

$$
\bar y=\frac{2+3+5+4}{4}=3.5
$$

**Step 2: Prepare the calculation table**

| $x_i$ | $y_i$ | $x_i-\bar x$ | $y_i-\bar y$ | Product | $(x_i-\bar x)^2$ |
|---|---|---|---|---|---|
| 1 | 2 | -1.5 | -1.5 | 2.25 | 2.25 |
| 2 | 3 | -0.5 | -0.5 | 0.25 | 0.25 |
| 3 | 5 | 0.5 | 1.5 | 0.75 | 0.25 |
| 4 | 4 | 1.5 | 0.5 | 0.75 | 2.25 |
| **Total** | | | | **4** | **5** |

**Step 3: Calculate the slope**

$$
b_1=\frac{4}{5}=\boxed{0.8}
$$

**Step 4: Calculate the intercept**

$$
b_0=3.5-(0.8)(2.5)=\boxed{1.5}
$$

**Step 5: Write the fitted regression line**

$$
\boxed{\hat y=1.5+0.8x}
$$

**Step 6: Predict marks for 5 study hours**

$$
\hat y=1.5+0.8(5)=\boxed{5.5}
$$

The model predicts 5.5 marks in the numerical scale of this example.

##### Interactive understanding of the fitted line

Move the points and observe how the fitted line changes. The vertical gaps between observed and predicted values are the residuals that least-squares regression tries to minimize collectively.

#### G. Gradient descent and LMS terminology

Some courses use Least Mean Squares (LMS) to refer specifically to an iterative weight-update algorithm, rather than the closed-form ordinary least-squares solution. Check which meaning your lecturer uses.

In gradient-descent-style least-squares optimization, coefficients are updated repeatedly to reduce the loss.

For a single feature, using the half-MSE objective:

$$
J(b_0,b_1)=\frac{1}{2n}
\sum_{i=1}^{n}(\hat y_i-y_i)^2
$$

The updates are:

$$
b_0\leftarrow b_0-\eta
\frac{\partial J}{\partial b_0}
$$

$$
b_1\leftarrow b_1-\eta
\frac{\partial J}{\partial b_1}
$$

Where:

- $J$ = loss function.
- $\eta$ = learning rate, controlling the update size.
- $\partial J/\partial b_0$ and $\partial J/\partial b_1$ = gradients indicating how the loss changes with each coefficient.

For batch gradient descent:

$$
\frac{\partial J}{\partial b_0}
=\frac{1}{n}\sum_{i=1}^{n}(\hat y_i-y_i)
$$

$$
\frac{\partial J}{\partial b_1}
=\frac{1}{n}\sum_{i=1}^{n}(\hat y_i-y_i)x_i
$$

The process repeats until convergence or a stopping condition is reached.

**Distinction:** The closed-form least-squares solution calculates coefficients directly when the required conditions hold. Gradient descent or LMS-style updates iteratively approach a solution.

#### H. Assumptions and limitations

Common assumptions or considerations for ordinary linear regression include:

- **Linearity:** The expected response is linear in the model's coefficients.
- **Independence:** Observations or errors should satisfy the relevant independence assumptions.
- **Constant error variance:** Homoscedasticity is important for conventional inference.
- **Error distribution:** Normally distributed errors are commonly assumed for exact small-sample inference, though not strictly required to calculate least-squares coefficients.
- **Multicollinearity:** Strong correlations among predictors can make coefficient estimates unstable.
- **Outliers:** Squared errors give large residuals substantial influence.

**Advantages**

- Simple and interpretable.
- Efficient to fit for many datasets.
- Produces a clear mathematical relationship between inputs and output.
- Provides a baseline for more complex regression methods.

**Limitations**

- A linear model may underfit nonlinear relationships.
- Outliers can have a large influence.
- Highly correlated features can make coefficients unstable.
- Extrapolating beyond the observed data range can be unreliable.

---

### 1.2 Ridge Regression

#### A. Definition

Ridge Regression is a regularized form of linear regression that minimizes the squared prediction error while penalizing large coefficient values using an $L_2$ penalty.

It is particularly useful when a model has many correlated features or when ordinary least-squares coefficients are unstable.

#### B. Objective function

$$
\boxed{
J(\boldsymbol{\beta})
=\sum_{i=1}^{n}(y_i-\hat y_i)^2
+\lambda\sum_{j=1}^{p}\beta_j^2
}
$$

Where:

- $J(\boldsymbol{\beta})$ = penalized objective to minimize.
- $n$ = number of observations.
- $p$ = number of input features.
- $y_i$ = actual output for observation $i$.
- $\hat y_i$ = predicted output.
- $\beta_j$ = coefficient of feature $j$.
- $\lambda\geq0$ = regularization parameter controlling the penalty strength.

The intercept is typically not penalized.

The first term measures prediction error. The second term penalizes large coefficients.

#### C. How Ridge Regression works

1. Start with a linear regression model.
2. Calculate the squared prediction error.
3. Add a penalty proportional to the sum of squared coefficients.
4. Minimize the combined objective.
5. Obtain coefficients that balance fitting the data against limiting their magnitude.

When $\lambda=0$, Ridge Regression reduces to ordinary least squares.

As $\lambda$ increases, coefficients are generally shrunk more strongly toward zero. However, Ridge Regression generally does not set coefficients exactly to zero.

#### D. Ridge Regression formula

For the multiple-feature model, the Ridge solution can be written as:

$$
\boxed{
\hat{\boldsymbol{\beta}}_{\text{ridge}}
=(X^TX+\lambda I)^{-1}X^Ty
}
$$

This formula assumes the intercept has been handled separately or the features have been suitably centred, so the intercept is not penalized.

Where:

- $X$ = design matrix of features.
- $X^T$ = transpose of $X$.
- $I$ = identity matrix.
- $\lambda$ = regularization strength.
- $y$ = output vector.
- $\hat{\boldsymbol{\beta}}_{\text{ridge}}$ = estimated Ridge coefficients.

Adding $\lambda I$ helps make the matrix invertible for $\lambda>0$ under the usual setup, even when the original feature matrix has collinear columns.

#### E. Worked numerical — Ridge coefficient shrinkage

Consider a simplified one-coefficient example with a fixed intercept of zero:

$$
J(\beta)=(y-x\beta)^2+\lambda\beta^2
$$

Suppose $x=2,\ y=6,\ \lambda=2$.

Substitute:

$$
J(\beta)=(6-2\beta)^2+2\beta^2
$$

Differentiate and set the derivative to zero:

$$
\frac{dJ}{d\beta}=-4(6-2\beta)+4\beta=0
$$

$$
-24+8\beta+4\beta=0
$$

$$
12\beta=24
$$

$$
\boxed{\beta=2}
$$

Without the penalty, ordinary least squares gives:

$$
\beta_{\text{OLS}}=\frac{y}{x}=\frac{6}{2}=3
$$

With Ridge regularization, the coefficient falls from 3 to 2 in this example. The model accepts a different fit in exchange for a smaller coefficient.

**Note:** Some textbooks define the squared-error term with a factor such as $1/2$ or $1/n$. The numerical solution changes according to the exact scaling used for the penalty, so always use the objective stated in the question.

#### F. Choosing $\lambda$

- $\lambda=0$: no regularization; ordinary least squares.
- Small positive $\lambda$: mild shrinkage.
- Large $\lambda$: stronger shrinkage, potentially causing underfitting.

The parameter is typically selected using validation data or cross-validation.

#### G. Advantages and limitations

**Advantages**

- Reduces coefficient instability caused by multicollinearity.
- Can reduce overfitting.
- Retains all features while shrinking their coefficients.
- Often improves prediction on unseen data when ordinary least squares is too variable.

**Limitations**

- Coefficients are biased toward zero.
- Does not usually perform exact feature selection.
- Requires selection of $\lambda$.
- Feature scaling is important because the penalty acts on coefficient magnitudes.

---

### 1.3 LASSO Regression

#### A. Definition

LASSO (Least Absolute Shrinkage and Selection Operator) Regression is a regularized regression technique that minimizes squared prediction error while penalizing the absolute values of the coefficients using an $L_1$ penalty.

LASSO can shrink some coefficients exactly to zero, making it useful for feature selection.

#### B. Objective function

$$
\boxed{
J(\boldsymbol{\beta})
=\sum_{i=1}^{n}(y_i-\hat y_i)^2
+\lambda\sum_{j=1}^{p}|\beta_j|
}
$$

Where:

- $J(\boldsymbol{\beta})$ = objective to minimize.
- $y_i$ = actual output.
- $\hat y_i$ = predicted output.
- $n$ = number of observations.
- $p$ = number of input features.
- $\beta_j$ = coefficient of feature $j$.
- $|\beta_j|$ = absolute value of that coefficient.
- $\lambda\geq0$ = regularization strength.

As with Ridge Regression, the intercept is usually excluded from the penalty.

#### C. How LASSO works

1. Fit a regression model to the training data.
2. Calculate squared prediction error.
3. Add a penalty based on the absolute values of the coefficients.
4. Minimize the combined objective.
5. Some coefficients may become exactly zero, effectively removing those features from the fitted model.

When $\lambda=0$, LASSO reduces to ordinary least squares. Increasing $\lambda$ generally increases shrinkage and can remove more features.

#### D. Ridge versus LASSO: the penalty

**Ridge Regression — $L_2$ penalty**

$$
\lambda\sum_{j=1}^{p}\beta_j^2
$$

Penalizes the squared magnitudes of coefficients.

**LASSO Regression — $L_1$ penalty**

$$
\lambda\sum_{j=1}^{p}|\beta_j|
$$

Penalizes the absolute magnitudes of coefficients.

The different penalty shapes explain their different behaviours: Ridge tends to distribute shrinkage across coefficients, whereas LASSO can produce sparse solutions containing exact zeros.

#### E. Worked numerical — LASSO soft-thresholding

For a simplified one-coefficient problem with a fixed intercept of zero, consider:

$$
J(\beta)=\frac12(z-\beta)^2+\lambda|\beta|
$$

Here, $z$ is the unregularized coefficient in this simplified formulation, and $\lambda$ controls the penalty.

The solution is given by the soft-thresholding rule:

$$
\boxed{
\hat\beta=
\begin{cases}
z-\lambda, & z>\lambda\\
0, & -\lambda\leq z\leq\lambda\\
z+\lambda, & z<-\lambda
\end{cases}
}
$$

Equivalently,

$$
\hat\beta=\operatorname{sign}(z)\max(|z|-\lambda,0)
$$

Where:

- $z$ = unregularized coefficient in the simplified problem.
- $\lambda$ = regularization parameter.
- $\operatorname{sign}(z)$ = sign of $z$.

**Case 1: Coefficient remains nonzero**

Suppose $z=5$ and $\lambda=2$.

Since $5>2$,

$$
\hat\beta=5-2=\boxed{3}
$$

The coefficient shrinks from 5 to 3.

**Case 2: Coefficient becomes zero**

Suppose $z=1.5$ and $\lambda=2$.

Since $-2\leq1.5\leq2$,

$$
\boxed{\hat\beta=0}
$$

The feature's coefficient becomes zero.

**Case 3: Negative coefficient**

Suppose $z=-5$ and $\lambda=2$.

Since $-5<-2$,

$$
\hat\beta=-5+2=\boxed{-3}
$$

The coefficient moves toward zero while retaining its negative sign.

**Important:** This soft-thresholding formula is exact for the stated simplified, separable problem. In a general multivariable LASSO problem with correlated features, coefficients are typically found using iterative optimization rather than independently applying this formula to every ordinary least-squares coefficient.

#### F. Advantages and limitations

**Advantages**

- Performs feature selection by setting some coefficients to zero.
- Can reduce overfitting.
- Produces sparse and potentially easier-to-interpret models.
- Useful when many features may be irrelevant.

**Limitations**

- May select one feature from a group of highly correlated features somewhat arbitrarily.
- Coefficients are biased toward zero.
- Performance depends on selecting $\lambda$.
- Feature scaling is important.
- The solution can be unstable when predictors are highly correlated.

---

### 1.4 Comparison of all three regression methods

This is the main comparison table to learn for theory questions.

| Basis | Least Mean Square / Ordinary Least Squares | Ridge Regression | LASSO Regression |
|---|---|---|---|
| Main objective | Minimize squared prediction errors | Minimize squared errors plus an $L_2$ penalty | Minimize squared errors plus an $L_1$ penalty |
| Regularization | None in ordinary least squares | Yes | Yes |
| Penalty term | None | $\lambda\sum \beta_j^2$ | $\lambda\sum\lvert\beta_j\rvert$ |
| Coefficient behaviour | Estimates coefficients to minimize squared errors | Shrinks coefficients toward zero | Shrinks coefficients and can set some exactly to zero |
| Feature selection | No built-in sparsity mechanism | Generally retains all features | Performs embedded feature selection |
| Multicollinearity | Can produce unstable coefficients | Often improves coefficient stability | May select among correlated features; selection can be unstable |
| Bias and variance | Can have low bias but high variance | Introduces shrinkage bias, often reducing variance | Introduces shrinkage bias and may reduce variance |
| Hyperparameter | No regularization parameter | $\lambda$ | $\lambda$ |
| Best suited for | A suitable linear relationship without a need for coefficient regularization | Prediction with many correlated features | Sparse models when some features may be unnecessary |
| Main limitation | Sensitive to outliers and potentially unstable with correlated predictors | Does not usually eliminate features | Feature selection may be unstable with correlated predictors |

#### Choosing between them

- Use ordinary least squares when a linear model is appropriate and coefficient regularization is not required.
- Use Ridge when many features contribute information but coefficient estimates are unstable.
- Use LASSO when you want a model that may discard unnecessary features by setting coefficients to zero.

#### Why feature scaling matters

Suppose a model uses age measured in years and income measured in rupees. Their numerical scales can differ substantially.

Because Ridge and LASSO penalize coefficient magnitudes, the relative scales of input features affect how the penalty influences their coefficients. Standardizing numerical features is therefore often appropriate before applying these methods.

A common standardization formula is:

$$
z=\frac{x-\mu}{\sigma}
$$

Where:

- $x$ = original feature value.
- $\mu$ = training-set mean of that feature.
- $\sigma$ = training-set standard deviation.
- $z$ = standardized value.

The mean and standard deviation must be estimated from the training data and then reused for validation and test data.

---

### 1.5 Numerical index for this block

We'll preserve your original numbering.

| No. | Topic | What to practise |
|---|---|---|
| 4 | Least Mean Square (Linear) Regression | Calculate slope, intercept, fitted line, predictions, and residuals. |
| 5 | Ridge Regression | Understand the penalty, coefficient shrinkage, and regularized solution. |
| 6 | LASSO Regression | Apply the $L_1$ penalty and soft-thresholding formula. |

---

### 1.6 Final revision checklist

- [ ] Define regression and explain the regression equation.
- [ ] Distinguish actual values, predictions, residuals, SSE, and MSE.
- [ ] Calculate slope and intercept from a dataset.
- [ ] Fit a regression line and make a prediction.
- [ ] Explain the difference between the closed-form least-squares solution and iterative LMS-style updates.
- [ ] Write and explain the Ridge objective function.
- [ ] Explain how $\lambda$ affects Ridge coefficients.
- [ ] Write and explain the LASSO objective function.
- [ ] Solve a soft-thresholding example.
- [ ] Compare ordinary least squares, Ridge, and LASSO.

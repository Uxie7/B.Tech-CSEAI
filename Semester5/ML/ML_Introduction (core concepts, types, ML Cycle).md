# UNIT I — INTRODUCTION

## Index

- [1. Core Concepts: Goals and Applications of Machine Learning](#1-core-concepts-goals-and-applications-of-machine-learning)
  - [1.1 Definition of Machine Learning](#11-definition-of-machine-learning)
  - [1.2 Goals of Machine Learning](#12-goals-of-machine-learning)
  - [1.3 Applications of Machine Learning](#13-applications-of-machine-learning)
- [2. Types of Machine Learning: Supervised Learning, Unsupervised Learning](#2-types-of-machine-learning-supervised-learning-unsupervised-learning)
  - [2.1 Supervised Learning](#21-supervised-learning)
  - [2.2 Unsupervised Learning](#22-unsupervised-learning)
  - [2.3 Comprehensive Comparison: Supervised Learning vs Unsupervised Learning](#23-comprehensive-comparison-supervised-learning-vs-unsupervised-learning)
  - [2.4 Other Learning Settings — Supplementary](#24-other-learning-settings--supplementary)
- [3. Machine Learning Cycle](#3-machine-learning-cycle)
  - [3.1 Train-Test Split](#31-train-test-split)
  - [3.2 Validation Data](#32-validation-data)
  - [3.3 K-Fold Cross-Validation](#33-k-fold-cross-validation)
  - [3.4 Evaluation Metrics](#34-evaluation-metrics)
  - [Quick revision sheet](#quick-revision-sheet)

---

## 1. Core Concepts: Goals and Applications of Machine Learning

### 1.1 Definition of Machine Learning

Machine Learning (ML) is a branch of Artificial Intelligence that enables computer systems to learn patterns and relationships from data and use them to make predictions or decisions without being explicitly programmed with rules for every possible situation.

A machine learning algorithm learns from training data and produces a model that can be applied to new, unseen data.

$$
\text{Training Data}+\text{Learning Algorithm}
\rightarrow \text{Trained Model}
$$

$$
\text{New Input}+\text{Trained Model}
\rightarrow \text{Prediction}
$$

**Example:** A spam detection system learns patterns from emails labelled as spam or legitimate and applies those patterns to classify new emails.

### 1.2 Goals of Machine Learning

1. **Prediction:** Estimate unknown or future outcomes from existing data, such as predicting sales or house prices.
2. **Classification:** Assign observations to predefined categories, such as spam/not spam or fraudulent/legitimate.
3. **Pattern discovery:** Discover hidden structures, relationships, trends and similarities in large datasets.
4. **Automation:** Automate complex tasks that would otherwise require extensive manually written rules.
5. **Decision support:** Assist decision-making by estimating likely outcomes and risks.
6. **Adaptability:** Enable systems to be retrained as new data becomes available or patterns change.
7. **Generalization:** Learn patterns that remain useful for previously unseen examples instead of merely memorizing the training data.
8. **Efficiency:** Process large amounts of data and identify relationships that may be difficult to detect manually.

### 1.3 Applications of Machine Learning

| Application area | Purpose | Example |
|---|---|---|
| Healthcare | Predict diseases and support diagnosis | Estimating disease risk from medical records |
| Finance | Detect fraud and assess financial risk | Flagging suspicious bank transactions |
| Education | Analyse performance and support learning | Predicting students who may need academic assistance |
| E-commerce | Personalize user experiences | Recommending products based on purchase history |
| Natural Language Processing | Process human language | Spam detection, translation and chatbots |
| Computer Vision | Interpret images and videos | Object recognition in photographs |
| Cybersecurity | Identify abnormal or malicious activity | Detecting unusual network traffic |
| Transportation | Forecast conditions and support automation | Traffic prediction and driver-assistance systems |
| Agriculture | Monitor crops and improve productivity | Detecting plant diseases from leaf images |
| Manufacturing | Predict equipment failures | Predictive maintenance using sensor readings |
| Entertainment | Personalize content | Recommending movies, music and shows |
| Weather and Environment | Analyse environmental data | Forecasting air pollution levels |

---

## 2. Types of Machine Learning: Supervised Learning, Unsupervised Learning

Machine learning approaches can be distinguished by the kind of data available during learning and the objective of the task.

The two types explicitly included in your syllabus are Supervised Learning and Unsupervised Learning.

### 2.1 Supervised Learning

**Definition:** Supervised learning is a machine learning approach in which a model learns the relationship between input features and known target outputs from labelled training data.

A labelled dataset can be represented as:

$$
D=\{(x_i,y_i)\}_{i=1}^{n}
$$

Where:

- $D$ = training dataset.
- $n$ = number of training examples.
- $x_i$ = input features of the $i$-th example.
- $y_i$ = actual target value or class label.
- $i$ = index of a training example.

The model learns a function $f$ that approximates the relationship between the input and the target:

$$
\hat{y}=f(x)
$$

Here, $\hat{y}$ represents the predicted output.

**Working procedure:**

1. Collect labelled training data.
2. Identify input features and the target variable.
3. Select a suitable learning algorithm.
4. Train the algorithm to learn patterns between the features and target.
5. Evaluate the trained model on data not used for training.
6. Use the model to predict outputs for new observations.

#### Main tasks of supervised learning

##### A. Classification

Classification predicts a discrete class or category.

Examples:

- Email classification: spam or legitimate.
- Student classification: pass or fail.
- Transaction classification: fraudulent or legitimate.

Common classification settings:

- **Binary classification:** Two classes, such as pass/fail.
- **Multiclass classification:** One of more than two mutually exclusive classes, such as cat/dog/bird.
- **Multilabel classification:** An observation may receive multiple labels, such as a news article tagged both politics and economics.

##### B. Regression

Regression predicts a continuous numerical value.

Examples:

- Predicting house prices.
- Estimating temperature.
- Forecasting sales revenue.
- Predicting numerical examination scores.

Algorithms covered later in your Unit II: Logistic Regression, SVM, KNN, Bayesian and Naïve Bayes Classifier, Decision Tree Learning, Least Mean Square Regression, Ridge Regression and LASSO Regression.

### 2.2 Unsupervised Learning

**Definition:** Unsupervised learning is a machine learning approach in which an algorithm analyses unlabelled data to identify hidden patterns, similarities, relationships or underlying structures without being provided with target outputs.

An unlabelled dataset can be represented as:

$$
D=\{x_i\}_{i=1}^{n}
$$

Unlike supervised learning, the training data does not provide a corresponding target $y_i$ for every observation.

**Working procedure:**

1. Collect unlabelled data.
2. Select and represent the relevant features.
3. Apply an unsupervised learning algorithm.
4. Identify patterns, groups or lower-dimensional representations.
5. Interpret and evaluate the discovered structure.

#### Main tasks of unsupervised learning

##### A. Clustering

Clustering groups observations according to their similarity.

**Example:** Grouping customers into segments based on purchasing behaviour.

Your Unit III clustering techniques are:

- Hierarchical Agglomerative Clustering
- K-means Partitional Clustering
- Density-based Clustering
- Expectation Maximization (EM) for soft clustering

##### B. Dimensionality Reduction

Dimensionality reduction decreases the number of features while retaining as much relevant information as possible.

It can simplify datasets, reduce computational costs and help visualize high-dimensional data.

Your Unit III includes PCA and LDA. Note that PCA is generally unsupervised, whereas LDA for dimensionality reduction uses class labels and is supervised.

##### C. Association Rule Learning — Additional Concept

Association rule learning discovers relationships between items that frequently occur together.

**Example:** Identifying that customers who purchase bread often purchase butter as well.

A rule can be represented as:

$$
X\rightarrow Y
$$

Here, $X$ is the antecedent and $Y$ is the consequent. Association rule learning is useful background, although it is not explicitly listed in your syllabus.

### 2.3 Comprehensive Comparison: Supervised Learning vs Unsupervised Learning

This is the main comparison table to prepare. Each row gives you a separate point you can expand in a long-answer question.

| Basis | Supervised Learning | Unsupervised Learning |
|---|---|---|
| Definition | Learns a mapping between inputs and known target outputs using labelled examples. | Discovers patterns or structure in data without supplied target labels. |
| Nature of data | Uses labelled training data containing inputs and their corresponding outputs. | Uses unlabelled data containing observations and their features. |
| Learning objective | Learn to predict the correct target for a given input. | Identify natural groupings, relationships or underlying structures in data. |
| Input representation | Features $X$ together with target labels $Y$. | Features $X$, without target labels $Y$ during training. |
| Role of the algorithm | Minimize prediction errors or optimize another objective based on known targets. | Optimize an objective that reveals meaningful structure, similarity or representation. |
| Working procedure | Train on labelled examples, validate model choices, evaluate predictions and apply the model to new inputs. | Analyse unlabelled examples, discover patterns, examine the resulting structure and interpret it. |
| Main learning tasks | Classification and regression. | Clustering and unsupervised representation or structure discovery. |
| Typical output | Predicted class labels, class probabilities or numerical values. | Cluster assignments, similarity structures, associations or reduced-dimensional representations. |
| Classification | A major supervised task; predicts discrete classes using known labels during training. | Does not ordinarily learn a classifier from supplied target labels; may discover groups without predefined classes. |
| Regression | A major supervised task; predicts continuous numerical targets. | Standard unsupervised learning does not use known continuous target values to train a regression model. |
| Algorithms | Linear Regression, Logistic Regression, SVM, KNN, Naïve Bayes and Decision Trees. | K-means, Hierarchical Clustering, DBSCAN, PCA and EM-based clustering. |
| Example: education | Predict whether a student will pass using previous labelled student records. | Group students according to similarities in attendance, study hours and scores. |
| Example: healthcare | Predict disease status from patient records with known outcomes. | Discover groups of patients with similar clinical characteristics. |
| Example: e-commerce | Predict whether a customer will purchase a particular product. | Segment customers according to browsing and purchasing behaviour. |
| Evaluation | Predictions can be compared against known targets using metrics such as accuracy, precision, recall, MAE or MSE, depending on the task. | Evaluation may use cluster-quality measures, structural consistency, domain usefulness or downstream performance. |
| Interpretation of results | Predictions are interpreted relative to the known target or outcome. | Discovered patterns require interpretation to determine whether they are meaningful. |
| Advantages | Directly optimizes prediction against known outcomes; performance can be evaluated using labelled test data. | Can reveal previously unknown structure and use datasets for which target labels are unavailable. |
| Limitations | Requires labelled examples, which may be expensive or time-consuming to obtain; can overfit or generalize poorly. | Results can be harder to evaluate and interpret; discovered groups may not correspond to meaningful real-world categories. |
| Common challenge | Avoiding overfitting and ensuring accurate predictions on unseen data. | Choosing useful representations and determining whether the discovered structure is meaningful. |
| Best suited for | Tasks where the desired output is known for training examples and the goal is to predict that output for new observations. | Tasks where labels are unavailable and the goal is to explore or understand the data's structure. |

**Important distinctions for the exam:**

- Classification and regression are the two principal supervised-learning tasks.
- Clustering is a major unsupervised-learning task.
- Not every machine learning algorithm belongs exclusively to one category in every possible use; the learning setup and objective matter.
- Unsupervised learning does not mean that the algorithm performs no learning. It learns structure from the features even when target labels are absent.

### 2.4 Other Learning Settings — Supplementary

Your syllabus explicitly specifies supervised and unsupervised learning, so prioritize those. For conceptual completeness:

- **Semi-supervised learning:** Uses a small labelled dataset together with a larger unlabelled dataset.
- **Reinforcement learning:** An agent learns actions by interacting with an environment and receiving rewards or penalties.

---

## 3. Machine Learning Cycle

The Machine Learning Cycle is the sequence of steps followed to develop, evaluate, and use a machine learning model. It involves preparing data, training a model, evaluating its performance, and improving it when necessary.

The main stages are:

1. Data collection
2. Data exploration and preprocessing
3. Train-test split
4. Model training using training data
5. Model selection using validation data or cross-validation
6. Final evaluation on test data
7. Deployment and monitoring

The model may be improved by revisiting preprocessing, features, algorithms, or hyperparameters. Once selected, its final performance is measured on test data that was not used to train or select the model.

The three concepts that must not be confused are:

- **Training data:** Used to learn model parameters.
- **Validation data:** Used to select models and tune hyperparameters.
- **Test data:** Used for the final, unbiased-as-possible assessment of the selected model.

### 3.1 Train-Test Split

#### Definition

The train-test split is a method of dividing a dataset into separate subsets: one used to train a machine learning model and another used to evaluate how well it performs on unseen data.

#### Training set

The training set is used by the learning algorithm to learn the model's parameters and patterns.

For example, in linear regression, the model learns the slope and intercept from the training observations.

#### Test set

The test set contains observations excluded from model training. It is used to estimate how well the trained model generalizes to new data.

**Important:** The test set should not be repeatedly used to choose algorithms or tune hyperparameters. Doing so leaks information from the test set into model development and makes the final evaluation overly optimistic.

#### Common train-test ratios

| Split | Training data | Test data | Typical use |
|---|---|---|---|
| 80:20 | 80% | 20% | Common general-purpose split |
| 70:30 | 70% | 30% | When a larger test set is desired |
| 90:10 | 90% | 10% | When sufficient data is available for training |

These are common choices, not fixed rules. The appropriate ratio depends on dataset size, class balance, and the task.

#### Procedure

1. Collect and prepare the dataset.
2. Decide the training and test proportions.
3. Split the observations into the two subsets.
4. Train the model using only the training subset.
5. Apply the trained model to the test subset.
6. Compare predictions against the actual targets using appropriate evaluation metrics.

#### Formula for the split

Let:

- $N$ = total number of observations.
- $r$ = fraction assigned to training.
- $N_{\text{train}}$ = number of training observations.
- $N_{\text{test}}$ = number of test observations.

Then:

$$
N_{\text{train}}=rN
$$

$$
N_{\text{test}}=N-N_{\text{train}}
$$

For an 80:20 split, $r=0.8$.

**Example:** A dataset contains 1,000 observations.

$$
N_{\text{train}}=0.8(1000)=800
$$

$$
N_{\text{test}}=1000-800=200
$$

Therefore, 800 observations are used for training and 200 for testing.

For datasets where the result is not a whole number, the split implementation rounds the subset sizes appropriately.

#### Types of splitting

##### A. Random split

Observations are randomly assigned to training and test subsets. This is common for independent, identically distributed data.

##### B. Stratified split

The split preserves approximately the same class proportions in both subsets. It is particularly useful for classification with imbalanced classes.

**Example:** If 10% of the full dataset represents fraudulent transactions, stratification aims to preserve approximately that proportion in both subsets.

##### C. Time-based split

Earlier observations are used for training and later observations for testing. This is appropriate for time-series or forecasting problems because random splitting may allow future information to leak into training.

#### Advantages

- Simple and easy to implement.
- Requires relatively little computation.
- Provides a separate dataset for evaluating generalization.
- Useful for establishing a baseline model.

#### Limitations

- Performance can depend on the particular split.
- A small dataset may not provide enough training or test observations.
- A random split may produce unrepresentative class distributions.
- It can be inappropriate for time-dependent data if chronology is ignored.

---

### 3.2 Validation Data

#### Definition

Validation data is a separate subset of data used during model development to compare candidate models, tune hyperparameters, and make design decisions without using the test set.

#### Purpose of validation data

Validation data helps with:

1. **Hyperparameter tuning:** Selecting values such as the number of neighbours $K$ in KNN or the regularization strength in Ridge Regression.
2. **Model selection:** Comparing different algorithms or model configurations.
3. **Overfitting detection:** Identifying when training performance improves but validation performance deteriorates.
4. **Early stopping:** Deciding when to stop training iterative models if validation performance stops improving.
5. **Feature and configuration selection:** Comparing alternative feature sets or preprocessing choices.

#### Training, validation and test sets

| Aspect | Training set | Validation set | Test set |
|---|---|---|---|
| Main purpose | Learn model parameters | Select the model and tune settings | Assess the final selected model |
| Used to update model parameters? | Yes | Usually not directly | No |
| Used for hyperparameter selection? | Not usually on its own | Yes | No |
| Used repeatedly during development? | Yes | Yes | Ideally no |
| Example | Learn regression coefficients | Select regularization strength | Report final predictive error |

#### Three-way split

A dataset can be divided into training, validation, and test subsets.

A common illustrative split is:

- 70% training
- 15% validation
- 15% testing

For 2,000 observations:

$$
N_{\text{train}}=0.70(2000)=1400
$$

$$
N_{\text{validation}}=0.15(2000)=300
$$

$$
N_{\text{test}}=0.15(2000)=300
$$

These proportions are examples rather than mandatory standards.

#### Why not use the test set for tuning?

Suppose two models are evaluated on the test set. You select whichever performs better, adjust its hyperparameters, and evaluate again. Repeating this process gradually makes decisions based on the test results, so the test set is no longer an independent final assessment.

**Correct approach:** Use validation data or cross-validation to choose the model, then evaluate the selected model on the test set at the end.

---

### 3.3 K-Fold Cross-Validation

#### Definition

K-fold cross-validation is a model evaluation technique in which a dataset is divided into $K$ approximately equal folds. The model is trained and evaluated $K$ times, with a different fold used for validation in each iteration.

Unlike a single train-test split, this method allows each observation to be used for validation once and for training in the other iterations, assuming ordinary non-overlapping folds.

#### Procedure

1. Divide the dataset into $K$ approximately equal folds.
2. Select the first fold as the validation fold and use the remaining $K-1$ folds for training.
3. Train the model and record its validation score.
4. Repeat the process, choosing a different fold for validation each time.
5. Continue until every fold has been used for validation once.
6. Calculate the average of the $K$ validation scores.

#### Example: 5-fold cross-validation

Each row represents one training-and-validation run. The highlighted fold (**Val**) is held out for validation.

| Run | Fold 1 | Fold 2 | Fold 3 | Fold 4 | Fold 5 |
|---|---|---|---|---|---|
| Run 1 | **Val** | Train | Train | Train | Train |
| Run 2 | Train | **Val** | Train | Train | Train |
| Run 3 | Train | Train | **Val** | Train | Train |
| Run 4 | Train | Train | Train | **Val** | Train |
| Run 5 | Train | Train | Train | Train | **Val** |

Each fold serves as the validation set exactly once. The other four folds are used for training in that run.

#### Formula for average validation performance

Let $S_i$ be the evaluation score obtained in fold $i$, and let $K$ be the number of folds.

$$
\bar{S}=\frac{1}{K}\sum_{i=1}^{K}S_i
$$

Where:

- $\bar{S}$ = average cross-validation score.
- $S_i$ = score from the $i$-th fold.
- $K$ = total number of folds.
- $\sum$ = sum of the scores across all folds.

**Example:** Suppose the accuracy scores from five folds are 80%, 84%, 82%, 86%, and 83%.

$$
\bar{S}=\frac{80+84+82+86+83}{5}
=\frac{415}{5}=83\%
$$

The mean cross-validation accuracy is 83%.

#### Common values of K

- **5-fold cross-validation:** Common balance between computational cost and evaluation reliability.
- **10-fold cross-validation:** Provides more validation runs, but requires more computation.
- **Leave-One-Out Cross-Validation (LOOCV):** A special case where $K=N$, so each observation is held out individually.

#### Advantages

1. Makes efficient use of limited data.
2. Every observation is used for validation once.
3. Reduces dependence on one particular train-validation split.
4. Supports comparison and hyperparameter selection.
5. Provides information about variation in performance across folds.

#### Limitations

1. Requires training the model $K$ times, increasing computational cost.
2. Results can still vary with the partitioning of data.
3. Standard random folds are unsuitable for many time-series problems because they may violate chronological order.
4. Preprocessing performed before the folds are created can cause data leakage.

#### Important precautions

- Fit preprocessing steps, such as scaling and imputation, using only the training portion of each fold; apply the learned transformation to its validation portion.
- Use stratified folds for many classification tasks, especially when classes are imbalanced.
- Use time-aware cross-validation for time-dependent data.
- Keep the final test set separate if one is available.

#### Train-test split vs K-fold cross-validation

| Basis | Train-test split | K-fold cross-validation |
|---|---|---|
| Data division | One training subset and one test subset | $K$ folds used in $K$ different runs |
| Number of model runs | Usually one | $K$ |
| Data usage | Test observations are held out from training | Each fold is used for validation once |
| Computational cost | Lower | Higher |
| Dependence on one split | Can be substantial | Reduced by averaging across folds |
| Main use | Simple evaluation or final testing | Model selection, hyperparameter tuning and more robust performance estimation |

**Remember:** Cross-validation is commonly used for model selection and performance estimation. A separate final test set is still useful for an independent final assessment.

---

### 3.4 Evaluation Metrics

#### Definition

Evaluation metrics are quantitative measures used to assess the performance of a machine learning model by comparing its predictions with the actual target values.

The appropriate metric depends on the learning task. Classification and regression generally use different measures.

- **Classification metrics:** Accuracy, precision, recall, F1-score and specificity.
- **Regression metrics:** Mean Absolute Error (MAE), Mean Squared Error (MSE), Root Mean Squared Error (RMSE) and coefficient of determination $R^2$.

#### A. Classification Metrics

##### Confusion matrix

A confusion matrix summarizes the predictions of a classification model by comparing predicted classes with actual classes.

For binary classification:

| | Predicted Positive | Predicted Negative |
|---|---|---|
| **Actual Positive** | True Positive (TP) | False Negative (FN) |
| **Actual Negative** | False Positive (FP) | True Negative (TN) |

- **TP:** Positive cases correctly predicted as positive.
- **TN:** Negative cases correctly predicted as negative.
- **FP:** Negative cases incorrectly predicted as positive.
- **FN:** Positive cases incorrectly predicted as negative.

**Example:** For disease detection, a false negative means the model predicts that a person does not have the disease when they actually do.

##### 1. Accuracy

Accuracy measures the proportion of all predictions that are correct.

$$
\text{Accuracy}=\frac{TP+TN}{TP+TN+FP+FN}
$$

**Use:** When overall correctness matters and the class distribution does not make accuracy misleading.

##### 2. Precision

Precision measures the proportion of predicted positive cases that are actually positive.

$$
\text{Precision}=\frac{TP}{TP+FP}
$$

**Use:** When false positive predictions are costly, such as incorrectly flagging legitimate transactions as fraudulent.

##### 3. Recall (Sensitivity)

Recall measures the proportion of actual positive cases correctly identified by the model.

$$
\text{Recall}=\frac{TP}{TP+FN}
$$

**Use:** When missing a positive case is costly, such as failing to identify a disease.

##### 4. Specificity

Specificity measures the proportion of actual negative cases correctly identified.

$$
\text{Specificity}=\frac{TN}{TN+FP}
$$

**Use:** When correctly identifying negative cases is important.

##### 5. F1-score

The F1-score is the harmonic mean of precision and recall.

$$
F_1=2\cdot\frac{PR}{P+R}
$$

Where:

- $P$ = precision.
- $R$ = recall.
- $F_1$ = F1-score.

It is useful when both precision and recall matter, particularly when class distributions are imbalanced.

##### Worked classification example

Suppose a model produces the following results:

- $TP=40$
- $TN=50$
- $FP=10$
- $FN=20$

Total observations:

$$
40+50+10+20=120
$$

Accuracy:

$$
\frac{40+50}{120}=0.75=75\%
$$

Precision:

$$
\frac{40}{40+10}=0.80=80\%
$$

Recall:

$$
\frac{40}{40+20}=0.667\approx66.7\%
$$

Specificity:

$$
\frac{50}{50+10}=0.833\approx83.3\%
$$

F1-score:

$$
F_1=2\cdot\frac{0.80(0.667)}{0.80+0.667}
\approx0.727=72.7\%
$$

**Interpretation:** The model correctly classifies 75% of all observations, but identifies only about 66.7% of actual positive cases. Accuracy alone would not reveal this limitation.

#### B. Regression Metrics

Regression metrics compare predicted numerical values $\hat y_i$ with actual values $y_i$.

Let:

- $y_i$ = actual value of observation $i$.
- $\hat y_i$ = predicted value.
- $n$ = number of observations.
- $e_i=y_i-\hat y_i$ = prediction error or residual under this sign convention.

##### 1. Mean Absolute Error (MAE)

MAE is the average of the absolute differences between actual and predicted values.

$$
\operatorname{MAE}=\frac{1}{n}\sum_{i=1}^{n}|y_i-\hat y_i|
$$

The absolute value prevents positive and negative errors from cancelling one another.

**Interpretation:** If MAE is 4, the average absolute prediction error is 4 units.

##### 2. Mean Squared Error (MSE)

MSE is the average of the squared prediction errors.

$$
\operatorname{MSE}=\frac{1}{n}\sum_{i=1}^{n}(y_i-\hat y_i)^2
$$

Squaring makes all contributions non-negative and penalizes larger errors more heavily.

**Interpretation:** MSE is expressed in squared units of the target variable.

##### 3. Root Mean Squared Error (RMSE)

RMSE is the square root of MSE.

$$
\operatorname{RMSE}=\sqrt{\operatorname{MSE}}
$$

It is expressed in the same units as the target variable, making it easier to interpret than MSE.

##### 4. Coefficient of Determination ($R^2$)

The coefficient of determination measures how well the model explains variation in the target relative to a baseline that predicts the mean.

$$
R^2=1-\frac{\sum_{i=1}^{n}(y_i-\hat y_i)^2}
{\sum_{i=1}^{n}(y_i-\bar y)^2}
$$

Where:

- $\bar y$ = mean of the actual target values.
- The numerator is the residual sum of squares.
- The denominator is the total sum of squares around the mean.

An $R^2$ value of 1 indicates perfect predictions. A value of 0 means the model performs like the mean-prediction baseline on this measure. On test data, $R^2$ can be negative if the model performs worse than that baseline.

##### Comparison of regression metrics

| Metric | What it measures | Effect of large errors | Units |
|---|---|---|---|
| MAE | Average absolute error | Less sensitive than squared-error measures | Same as target |
| MSE | Average squared error | Penalizes large errors strongly | Squared target units |
| RMSE | Square root of average squared error | Penalizes large errors strongly | Same as target |
| $R^2$ | Improvement relative to mean-prediction baseline | Depends on squared errors | Unitless |

##### Worked regression example

Suppose the actual and predicted values are:

| Observation | Actual $y_i$ | Predicted $\hat y_i$ | Error $y_i-\hat y_i$ | Squared error |
|---|---|---|---|---|
| 1 | 10 | 12 | −2 | 4 |
| 2 | 20 | 18 | 2 | 4 |
| 3 | 30 | 33 | −3 | 9 |
| 4 | 40 | 36 | 4 | 16 |
| **Total** | | | | **33** |

Here, $n=4$.

$$
\operatorname{MSE}=\frac{33}{4}=8.25
$$

$$
\operatorname{RMSE}=\sqrt{8.25}\approx2.87
$$

Therefore:

- MSE = 8.25
- RMSE ≈ 2.87

Notice that MSE is in squared units, whereas RMSE is in the original target units.

This is the same type of calculation covered by Numericals 20 and 21 in your original index.

#### Important points about evaluation metrics

1. No single metric is best for every task. Select the metric based on the problem and the cost of different errors.
2. High accuracy can be misleading on imbalanced datasets. For example, a model predicting every transaction as legitimate could achieve high accuracy if fraudulent transactions are rare.
3. Precision and recall involve a trade-off: changing the classification threshold may increase one while decreasing the other.
4. MAE is less sensitive to large errors than MSE and RMSE.
5. RMSE is easier to interpret in the target's original units than MSE.
6. Evaluation on the training data alone does not establish that the model generalizes to unseen observations.

---

## Quick revision sheet

### Machine Learning Cycle

**Train-test split**

Training data learns model parameters; test data evaluates the final selected model.

**Validation data**

Used for model selection, hyperparameter tuning and early stopping.

**K-fold cross-validation**

Train and validate K times, changing the held-out fold; average the scores.

$$
\bar S=\frac{1}{K}\sum_{i=1}^{K}S_i
$$

**Classification metrics**

Accuracy, precision, recall, specificity and F1-score.

**Regression metrics**

MAE, MSE, RMSE and $R^2$.

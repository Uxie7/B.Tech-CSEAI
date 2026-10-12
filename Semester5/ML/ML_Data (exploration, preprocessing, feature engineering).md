# UNIT I — Data Exploration, Pre-processing and Feature Engineering

We'll cover all three blocks end to end, keeping the exact syllabus topics and the same exam-ready style as the earlier notes: proper definitions, formulas with symbols explained, meaningful comparison tables, worked examples, and links to relevant numericals from your original index.

## Index

- [1. Data Exploration](#1-data-exploration)
  - [1.1 Data Objects and Attributes](#11-data-objects-and-attributes)
  - [1.2 Statistical Measures](#12-statistical-measures)
  - [1.3 Data Visualization](#13-data-visualization)
- [2. Data Pre-processing](#2-data-pre-processing)
  - [2.1 Data Cleaning](#21-data-cleaning)
  - [2.2 Data Integration](#22-data-integration)
  - [Numerical connection: Min-max normalization](#numerical-connection-min-max-normalization)
- [3. Feature Engineering](#3-feature-engineering)
  - [3.1 Feature Extraction](#31-feature-extraction)
  - [3.2 Feature Reduction](#32-feature-reduction)
- [Quick revision: all three blocks](#quick-revision-all-three-blocks)

---

## 1. Data Exploration

### 1.1 Data Objects and Attributes

#### Data

Data is a collection of facts, observations, measurements, or records used for analysis and machine learning.

**Example:** A student dataset may contain marks, attendance, study hours, and pass/fail status.

#### Data object

A data object is an individual entity or observation represented in a dataset. It is also called a record, instance, sample, or data point.

**Example:** One student's complete record is one data object.

#### Attribute

An attribute is a property or characteristic describing a data object. It is also called a feature, variable, or field.

**Example:** Marks, attendance, and study hours are attributes of a student.

Consider the following dataset:

| Student | Study hours | Attendance (%) | Marks | Result |
|---|---|---|---|---|
| A | 2 | 65 | 42 | Fail |
| B | 4 | 80 | 68 | Pass |
| C | 6 | 90 | 85 | Pass |
| D | 3 | 70 | 55 | Fail |

- **Data objects:** 4 students (A, B, C, D).
- **Attributes:** Study hours, attendance, marks, and result.
- **Feature attributes:** Study hours, attendance, and marks.
- **Target attribute:** Result, if the objective is to predict whether a student passes.
- **Dataset size:** 4 rows and 5 columns, including the student identifier.

#### Types of attributes

This classification is important for both theory questions and choosing suitable statistical methods.

| Attribute type | Meaning | Example | Suitable operations |
|---|---|---|---|
| Nominal | Categories with no inherent order | Colour, city, blood group | Frequency, mode |
| Binary | Attribute with two possible states | Yes/No, Pass/Fail | Frequency, proportions |
| Ordinal | Categories with a meaningful order, but unequal or unknown gaps | Low, Medium, High | Ordering, median, rank-based comparisons |
| Interval | Numeric values with meaningful differences but no true zero | Temperature in °C | Addition/subtraction, mean, standard deviation |
| Ratio | Numeric values with meaningful differences and a true zero | Height, weight, age, income | All ordinary arithmetic operations, including ratios |

**Key distinction:**

- For nominal data, the order of categories has no meaning.
- For ordinal data, the order matters, but the difference between consecutive categories cannot automatically be treated as equal.
- For interval data, differences are meaningful, but ratios are not. For example, $20^\circ C$ is not twice as hot as $10^\circ C$.
- For ratio data, both differences and ratios are meaningful.

#### Discrete and continuous attributes

| Discrete attributes | Continuous attributes |
|---|---|
| Take distinct, countable values. | Can take any value within a range, subject to measurement precision. |
| Usually obtained by counting. | Usually obtained by measuring. |
| Examples: number of students, number of purchases. | Examples: height, temperature, time. |

A numeric attribute can be either discrete or continuous; these categories describe the nature of its values, whereas nominal, ordinal, interval, and ratio describe measurement scales.

#### Feature and target attributes

- **Feature (input variable):** Information supplied to a model to make a prediction.
- **Target (output variable):** The value the model is expected to predict in supervised learning.

For example, to predict student marks from attendance and study hours:

$$
X=(\text{attendance},\text{study hours})
$$

$$
y=\text{marks}
$$

Here, $X$ represents the input features and $y$ represents the target.

**Exam point:** The target is not always a feature. In supervised learning, the target is the known output used during training, while features are the inputs used to predict it.

---

### 1.2 Statistical Measures

Statistical measures summarise the important properties of data, helping us understand its central tendency, variability, distribution, and relationships between attributes.

Consider the dataset:

$$
X=\{2,4,4,6,9\}
$$

The number of observations is $n=5$.

#### A. Measures of central tendency

These describe the central or typical value of a dataset.

##### 1. Mean (arithmetic average)

$$
\bar{x}=\frac{\sum_{i=1}^{n}x_i}{n}
$$

Where:

- $\bar{x}$ = sample mean.
- $x_i$ = the $i$-th observation.
- $n$ = total number of observations.
- $\sum$ = sum of all observations.

For $X=\{2,4,4,6,9\}$:

$$
\bar{x}=\frac{2+4+4+6+9}{5}
=\frac{25}{5}=\boxed{5}
$$

##### 2. Median

The median is the middle value after sorting the observations.

- For an odd number of observations, it is the middle value.
- For an even number, it is the average of the two middle values.

For $X=\{2,4,4,6,9\}$, the median is $\boxed{4}$.

##### 3. Mode

The mode is the most frequently occurring value.

For $X=\{2,4,4,6,9\}$, the mode is $\boxed{4}$.

| Measure | Main characteristic | Best suited for |
|---|---|---|
| Mean | Uses every observation; sensitive to extreme values | Approximately symmetric numerical data |
| Median | Resistant to extreme values | Skewed data or data containing outliers |
| Mode | Identifies the most frequent value | Categorical data or repeated values |

**Example:** For salaries $\{20,22,24,25,109\}$, the mean is 40, whereas the median is 24. The unusually high value raises the mean, making the median more representative of a typical observation.

#### B. Measures of dispersion

Dispersion describes how spread out the data values are.

##### 1. Range

$$
\text{Range}=x_{\max}-x_{\min}
$$

For $X=\{2,4,4,6,9\}$:

$$
\text{Range}=9-2=\boxed{7}
$$

The range is easy to calculate but depends only on the minimum and maximum values.

##### 2. Variance

Variance measures the average squared deviation from the mean.

Population variance:

$$
\sigma^2=\frac{\sum_{i=1}^{N}(x_i-\mu)^2}{N}
$$

Sample variance:

$$
s^2=\frac{\sum_{i=1}^{n}(x_i-\bar{x})^2}{n-1}
$$

Where:

- $\sigma^2$ = population variance.
- $s^2$ = sample variance.
- $N$ = population size.
- $n$ = sample size.
- $\mu$ = population mean.
- $\bar{x}$ = sample mean.

The sample formula uses $n-1$ because it estimates population variance from a sample.

For $X=\{2,4,4,6,9\}$, the mean is 5.

| $x_i$ | $x_i-\bar{x}$ | $(x_i-\bar{x})^2$ |
|---|---|---|
| 2 | -3 | 9 |
| 4 | -1 | 1 |
| 4 | -1 | 1 |
| 6 | 1 | 1 |
| 9 | 4 | 16 |
| **Total** | **0** | **28** |

Population variance:

$$
\sigma^2=\frac{28}{5}=\boxed{5.6}
$$

Sample variance:

$$
s^2=\frac{28}{4}=\boxed{7}
$$

##### 3. Standard deviation

Standard deviation is the square root of variance and is expressed in the same units as the original data.

$$
\sigma=\sqrt{\sigma^2}
$$

For the population above:

$$
\sigma=\sqrt{5.6}\approx\boxed{2.37}
$$

A small standard deviation indicates that values tend to lie close to the mean; a large one indicates greater spread.

##### 4. Interquartile range (IQR)

$$
IQR=Q_3-Q_1
$$

Where $Q_1$ is the first quartile and $Q_3$ is the third quartile.

The IQR measures the spread of the middle 50% of observations and is relatively resistant to outliers.

**Outlier rule:** A common rule flags observations below $Q_1-1.5(IQR)$ or above $Q_3+1.5(IQR)$ as potential outliers. These are not automatically errors; they require investigation.

#### C. Measures of position and distribution

**Percentile:** The $p$-th percentile is a value at or below which approximately $p\%$ of observations fall, subject to the percentile convention used.

**Skewness:** Describes asymmetry in a distribution.

- **Approximately symmetric:** Both sides have a similar shape.
- **Positively skewed:** A longer tail extends toward larger values.
- **Negatively skewed:** A longer tail extends toward smaller values.

**Kurtosis:** Describes aspects of the distribution's tail heaviness and concentration relative to a reference distribution. It can help identify distributions prone to extreme values.

#### D. Covariance and correlation

These measures describe relationships between two numerical attributes.

##### 1. Covariance

Sample covariance:

$$
s_{xy}=\frac{\sum_{i=1}^{n}(x_i-\bar{x})(y_i-\bar{y})}{n-1}
$$

Where:

- $x_i,y_i$ = paired observations.
- $\bar{x},\bar{y}$ = their respective means.
- $n$ = number of pairs.

Interpretation:

- **Positive covariance:** the variables tend to increase together.
- **Negative covariance:** one tends to increase as the other decreases.
- **Covariance near zero:** little linear co-variation, though a nonlinear relationship may still exist.

Its magnitude depends on the measurement scales, so it is difficult to compare across different pairs of variables.

##### 2. Pearson correlation coefficient

$$
r=\frac{s_{xy}}{s_xs_y}
$$

Where $s_x$ and $s_y$ are the sample standard deviations of $X$ and $Y$.

$$
-1\leq r\leq 1
$$

| Correlation | Interpretation |
|---|---|
| $r=+1$ | Perfect positive linear relationship |
| $0<r<1$ | Positive linear relationship |
| $r=0$ | No linear correlation |
| $-1<r<0$ | Negative linear relationship |
| $r=-1$ | Perfect negative linear relationship |

Correlation does not establish causation, and a correlation of zero does not rule out a nonlinear relationship.

#### E. Frequency distribution

A frequency distribution records how often each value or category occurs.

**Example:**

| Result | Frequency | Relative frequency |
|---|---|---|
| Pass | 30 | $30/50=0.60$ |
| Fail | 20 | $20/50=0.40$ |
| **Total** | **50** | **1.00** |

Relative frequency is calculated as:

$$
\text{Relative frequency}
=\frac{\text{Frequency of category}}{\text{Total observations}}
$$

It is useful for understanding class proportions, identifying imbalanced datasets, and summarising categorical attributes.

---

### 1.3 Data Visualization

Data visualization is the graphical representation of data to identify patterns, trends, distributions, relationships, and unusual observations.

It helps us understand the dataset before selecting or training a machine learning model.

#### Types of data visualization

##### 1. Histogram

Displays the frequency distribution of a numerical attribute using adjacent intervals called bins.

**Used for:** Understanding distribution, spread, skewness, and possible multiple peaks.

**Example:** Distribution of student marks.

##### 2. Box plot

Summarises numerical data using the median, quartiles, interquartile range, and whiskers. Potential outliers may be plotted separately.

**Used for:** Detecting outliers and comparing distributions across groups.

**Example:** Comparing marks across different sections.

##### 3. Scatter plot

Displays paired numerical observations as points on two axes.

**Used for:** Studying relationships, correlation, clusters, and outliers.

**Example:** Study hours against examination marks.

##### 4. Bar chart

Compares the frequencies or values of discrete categories using separated bars.

**Used for:** Comparing categories.

**Example:** Number of students who passed and failed.

##### 5. Line graph

Connects values in an ordered sequence, often time.

**Used for:** Understanding trends and changes over time.

**Example:** Monthly sales or daily temperature.

##### 6. Heatmap

Uses colours to represent values in a matrix.

**Used for:** Exploring correlation matrices, missing-value patterns, and other structured data.

**Example:** A correlation matrix of numerical features.

#### Choosing an appropriate visualization

| Objective | Suitable visualization | Reason |
|---|---|---|
| Study numerical distribution | Histogram | Shows frequency across intervals |
| Identify potential outliers | Box plot | Highlights quartiles and extreme observations |
| Examine a relationship between two numerical features | Scatter plot | Shows the pattern between paired values |
| Compare categories | Bar chart | Makes category-wise differences clear |
| Analyse change over time | Line graph | Shows trends in an ordered sequence |
| Inspect relationships among many numerical features | Correlation heatmap | Summarises pairwise correlations |

**Important distinctions:**

- A histogram is generally used for numerical distributions; a bar chart is generally used for categories.
- A scatter plot can reveal nonlinear patterns that a correlation coefficient alone may miss.
- Visualizations support exploration but do not prove causation or guarantee that a suspected outlier is erroneous.

---

## 2. Data Pre-processing

Data pre-processing transforms raw data into a suitable format for analysis and machine learning. It addresses problems such as missing values, noise, inconsistent records, duplicate observations, incompatible formats, and differing numerical scales.

### 2.1 Data Cleaning

Data cleaning identifies and handles inaccurate, incomplete, inconsistent, duplicated, or otherwise problematic data.

#### A. Missing-value handling

Missing values occur when a feature's value is unavailable for some observations.

**Example:**

| Student | Attendance (%) | Marks |
|---|---|---|
| A | 80 | 70 |
| B | Missing | 65 |
| C | 90 | Missing |
| D | 70 | 75 |

Common approaches:

| Method | Procedure | Suitable situation | Limitation |
|---|---|---|---|
| Delete rows | Remove observations containing missing values | Few rows are affected and deletion is justified | Can lose useful data or introduce bias |
| Delete columns | Remove a feature with excessive missingness and little usefulness | Feature is not important enough to retain | May discard predictive information |
| Mean imputation | Replace missing numerical values with the mean | Rough baseline for numerical data | Sensitive to outliers; reduces observed variability |
| Median imputation | Replace missing numerical values with the median | Skewed numerical data or outliers | Does not capture the true value's uncertainty |
| Mode imputation | Replace with the most frequent category or value | Categorical features | Can overrepresent the dominant category |
| Forward/backward fill | Use the previous/next observed value | Some ordered or time-series data | Can distort trends if used inappropriately |
| Model-based imputation | Estimate missing values using other attributes | More complex missingness patterns | More computationally demanding and can introduce modelling bias |

##### Mean imputation example

Suppose attendance values are $70,80,\text{Missing},90$.

$$
\text{Mean}=\frac{70+80+90}{3}=80
$$

The missing value is replaced with 80, producing $70,80,80,90$.

**Important:** Compute imputation values using the training data only, then apply the learned values to validation and test data. Otherwise, information from the evaluation data can leak into training.

#### B. Noise and outlier handling

**Noise** refers to random errors, disturbances, or irrelevant variation in the data.

**Outliers** are observations that differ substantially from the rest of the dataset.

**Example:** In the marks dataset $\{65,70,72,75,98\}$, 98 is not automatically an error. It may be a genuine high score.

Common approaches:

- **Verification:** Check the source for measurement or entry errors.
- **Smoothing:** Reduce random variation, for example using binning or suitable filtering.
- **Capping or winsorization:** Replace extreme values beyond chosen limits with boundary values.
- **Transformation:** Apply a transformation such as a logarithm to reduce right skew when appropriate.
- **Removal:** Remove an observation only when there is a defensible reason.

A common IQR-based rule flags a value as a potential outlier when:

$$
x<Q_1-1.5(IQR)
$$

or

$$
x>Q_3+1.5(IQR)
$$

where $Q_1$ is the first quartile, $Q_3$ is the third quartile, and $IQR=Q_3-Q_1$.

#### C. Handling inconsistent data

Inconsistent data contains values that disagree in format, representation, units, or meaning.

Examples:

- Gender represented as M, Male, and male.
- Dates represented as 12/10/2026 and 2026-10-12.
- Height stored in both centimetres and metres.
- Categories with spelling variations, such as Delhi and delhi.

Handling procedure:

1. Identify inconsistent values.
2. Establish a standard representation or unit.
3. Convert values into that standard.
4. Validate the transformed records.

For example, $1.7$ metres can be converted to $170$ centimetres before combining measurements.

#### D. Duplicate data

Duplicate records represent the same observation more than once.

**Example:**

| Student ID | Marks |
|---|---|
| S101 | 80 |
| S102 | 65 |
| S101 | 80 |

The repeated record for S101 may need to be removed if it is a true duplicate.

However, repeated values are not necessarily duplicate records. Two different students can legitimately score 80 marks.

**Procedure:** Identify duplicates using appropriate identifiers and attributes, verify whether they are genuine duplicates, and remove or consolidate them where justified.

#### E. Data-type and format errors

Data may contain values stored in inappropriate types.

Examples:

- Age stored as text instead of a number.
- A date stored as an ordinary string.
- A numerical feature containing symbols such as "₹1,000".
- Categories represented using inconsistent codes.

These errors should be corrected before statistical calculations or model training.

#### Summary of data-cleaning techniques

| Data problem | Common solution |
|---|---|
| Missing numerical values | Mean, median, or model-based imputation |
| Missing categorical values | Mode, explicit missing category, or suitable imputation |
| Noisy observations | Verification, smoothing, or suitable filtering |
| Potential outliers | Investigate, correct, transform, cap, or remove when justified |
| Inconsistent representations | Standardize formats and units |
| Duplicate records | Detect and remove or consolidate true duplicates |
| Incorrect data types | Convert to appropriate types and validate |

---

### 2.2 Data Integration

Data integration is the process of combining data from multiple sources into a unified dataset while resolving structural and semantic inconsistencies.

**Example:** A college may maintain separate student, attendance, and examination databases. Integrating them can produce one dataset for predicting academic performance.

#### Data integration process

1. **Identify sources:** Determine which files, tables, databases, or systems contain relevant data.
2. **Schema integration:** Align column names, data types, structures, and meanings.
3. **Entity identification:** Determine whether records in different sources refer to the same real-world entity.
4. **Record matching:** Match corresponding records using identifiers or other reliable attributes.
5. **Resolve conflicts:** Reconcile differences in units, formats, values, and naming conventions.
6. **Remove redundancy:** Identify duplicated records and overlapping attributes.
7. **Validate:** Check consistency, completeness, and correctness after merging.

#### Common issues in data integration

| Issue | Meaning | Example | Solution |
|---|---|---|---|
| Schema mismatch | Sources use different structures or names | Student_ID versus Roll_No | Map equivalent fields |
| Naming conflict | Same attribute has different names | DOB versus Date_of_Birth | Standardize names |
| Value conflict | Same attribute has different values | Different addresses in two sources | Verify source reliability and update rules |
| Unit conflict | Values use different units | Weight in kg versus pounds | Convert to a common unit |
| Entity identification | Same entity appears under different identifiers | Student listed as S101 in one table and 101 in another | Use a reliable key or record-matching process |
| Redundancy | Same information is stored multiple times | Two sources contain the same attendance field | Identify overlap and consolidate carefully |

#### Data integration example

Suppose the sources are:

**Student table**

| Student ID | Name |
|---|---|
| 101 | Asha |
| 102 | Riya |

**Marks table**

| Student ID | Marks |
|---|---|
| 101 | 85 |
| 102 | 72 |

After integration using Student ID as the common key:

| Student ID | Name | Marks |
|---|---|---|
| 101 | Asha | 85 |
| 102 | Riya | 72 |

The common key enables the matching records to be combined.

#### Data cleaning versus data integration

| Basis | Data cleaning | Data integration |
|---|---|---|
| Main objective | Improve the quality of data | Combine data from multiple sources |
| Primary focus | Missing, noisy, incorrect, inconsistent, or duplicate values | Schema matching, record matching, source conflicts, and redundancy |
| Input | One dataset or multiple datasets | Two or more sources |
| Typical operations | Imputation, correction, deduplication, type conversion | Joining tables, mapping fields, matching entities, resolving conflicts |
| Output | Cleaner, more reliable data | A unified dataset, ideally with consistent and reliable data |
| Relationship | May be required before or after integration | Often reveals additional cleaning requirements |

**Exam point:** Data integration and data cleaning are distinct but complementary. Integrated data may still require cleaning, and cleaning can be performed before or after integration depending on the situation.

---

### Numerical connection: Min-max normalization

Normalization is a common pre-processing operation that rescales numerical values to a specified range. It is especially useful when attributes have different units or magnitudes.

For example, a model using both age (roughly 18–60) and annual income (potentially in lakhs) may be disproportionately influenced by the larger-scale feature in some distance-based methods.

#### Min-max normalization to $[0,1]$

$$
x'=\frac{x-x_{\min}}{x_{\max}-x_{\min}}
$$

Where:

- $x$ = original value.
- $x'$ = normalized value.
- $x_{\min}$ = minimum value of the feature.
- $x_{\max}$ = maximum value of the feature.

**Worked example:** Normalize $x=30$ from the dataset $\{10,20,30,40,50\}$.

$$
x'=\frac{30-10}{50-10}
=\frac{20}{40}=\boxed{0.5}
$$

#### Min-max normalization to $[-1,1]$

$$
x'=2\left(\frac{x-x_{\min}}{x_{\max}-x_{\min}}\right)-1
$$

Using the same data:

$$
x'=2(0.5)-1=\boxed{0}
$$

| Property | Normalization to $[0,1]$ | Normalization to $[-1,1]$ |
|---|---|---|
| Minimum maps to | 0 | -1 |
| Maximum maps to | 1 | 1 |
| Midpoint maps to | 0.5 | 0 |
| Original numerical questions | 18 | 19 |

**Important:** Min-max normalization is sensitive to extreme values because the minimum and maximum determine the scale. Fit the scaling parameters on training data only, then apply the same parameters to validation and test data.

---

## 3. Feature Engineering

Feature engineering is the process of creating, transforming, selecting, or representing input variables so that machine learning algorithms can learn useful patterns more effectively.

A model's performance depends not only on the algorithm but also on the quality and representation of its input features.

**Example:** A dataset contains a student's date of birth. Instead of using the raw date, we may derive the student's age, which is more directly relevant to predicting academic performance.

### 3.1 Feature Extraction

Feature extraction transforms raw data into a new set of meaningful features that represent useful information from the original data.

It is especially useful when the raw data is complex, high-dimensional, or unsuitable for direct use by a learning algorithm.

#### Common approaches to feature extraction

| Approach | How it works | Example |
|---|---|---|
| Mathematical transformation | Applies a mathematical function to existing attributes | Log-transforming income |
| Domain-based extraction | Derives a feature using subject knowledge | Age from date of birth |
| Text feature extraction | Converts text into numerical representations | Bag of Words, TF-IDF |
| Image feature extraction | Represents images using measurable characteristics | Edges, texture, colour descriptors |
| Signal feature extraction | Derives characteristics from a signal | Mean, variance, frequency components |
| Projection-based extraction | Projects original features into a smaller set of new features | Principal Component Analysis (PCA) |

#### Example: Deriving features from existing data

Suppose a dataset contains:

| Student | Study hours | Attendance (%) | Marks |
|---|---|---|---|
| A | 20 | 80 | 75 |
| B | 30 | 90 | 85 |

We can derive a new feature called average study hours per day if study hours represent a weekly total:

$$
\text{Daily study hours}=
\frac{\text{Weekly study hours}}{7}
$$

For Student A:

$$
\frac{20}{7}\approx 2.86
$$

The new feature provides a different, potentially useful representation of the same underlying information.

#### Text feature extraction

Machine learning algorithms generally require numerical inputs. Text therefore needs to be represented numerically.

##### 1. Bag of Words (BoW)

Represents a document using the counts of words from a vocabulary, usually ignoring word order.

Consider two sentences:

- Document 1: ML is useful
- Document 2: ML is powerful

Vocabulary: ML, is, useful, powerful

| Document | ML | is | useful | powerful |
|---|---|---|---|---|
| Document 1 | 1 | 1 | 1 | 0 |
| Document 2 | 1 | 1 | 0 | 1 |

Each document becomes a numerical vector.

**Limitation:** Basic Bag of Words does not preserve word order or fully capture meaning.

##### 2. TF-IDF (Term Frequency–Inverse Document Frequency)

TF-IDF gives greater weight to words that are frequent in a document but relatively uncommon across the document collection.

A common form is:

$$
TFIDF(t,d)=TF(t,d)\times IDF(t)
$$

Where:

- $t$ = term or word.
- $d$ = document.
- $TF(t,d)$ = frequency or normalized frequency of term $t$ in document $d$.
- $IDF(t)$ = inverse document frequency, measuring how uncommon the term is across documents.

One common IDF definition is:

$$
IDF(t)=\log\left(\frac{N}{df(t)}\right)
$$

Where:

- $N$ = total number of documents.
- $df(t)$ = number of documents containing term $t$.

A word appearing in almost every document has a lower IDF than a word appearing in only a few documents.

#### Feature extraction versus feature transformation

Feature extraction is the broader process of deriving useful representations from raw data. Feature transformation changes the representation of existing attributes, for example by scaling values or applying logarithms.

These operations overlap in practice; their exact naming can depend on the context.

---

### 3.2 Feature Reduction

Feature reduction decreases the number of input dimensions used by a machine learning model while attempting to preserve useful information.

It is important when datasets contain many features, redundant attributes, irrelevant variables, or high-dimensional representations.

#### Why feature reduction is needed

- Reduces computational cost and memory requirements.
- Can reduce overfitting by removing irrelevant or redundant information.
- May improve model generalization.
- Can make models easier to interpret.
- Can help visualize high-dimensional data in two or three dimensions.
- May reduce noise and multicollinearity.

There are two major approaches.

#### A. Feature selection

Feature selection chooses a subset of the original features and discards the rest.

**Example:** From 20 student attributes, retain attendance, study hours, and previous marks because they are most useful for predicting final marks.

The selected features keep their original meanings.

##### Methods of feature selection

| Method | Procedure | Example |
|---|---|---|
| Filter method | Ranks or screens features using statistical criteria before model training | Correlation, chi-square test, mutual information |
| Wrapper method | Evaluates subsets by repeatedly training and assessing a model | Forward selection, backward elimination |
| Embedded method | Performs feature selection as part of model training | LASSO, decision-tree feature selection |

**Filter method:** Usually computationally efficient, but may not account fully for a particular model's behaviour.

**Wrapper method:** Can identify useful combinations of features, but may be computationally expensive.

**Embedded method:** Combines selection with model fitting, but the selected features can depend on the algorithm and its settings.

#### B. Dimensionality reduction

Dimensionality reduction transforms the original high-dimensional feature space into a lower-dimensional representation.

Unlike feature selection, it often creates new features that are combinations or projections of the original ones.

**Example:** A dataset has 50 numerical features. A dimensionality-reduction method may represent the data using 5 new components, retaining as much relevant structure as possible.

Two important techniques in your syllabus are PCA and LDA.

##### 1. Principal Component Analysis (PCA)

PCA is an unsupervised dimensionality-reduction technique that projects numerical data onto orthogonal directions called principal components, ordered by the variance they explain.

**Main steps:**

1. Standardize features when their scales differ substantially and standardization is appropriate.
2. Calculate the covariance matrix of the data.
3. Find its eigenvalues and eigenvectors.
4. Rank components by their eigenvalues.
5. Select the leading components.
6. Project the original data onto the selected components.

For a centred data matrix $X$, PCA finds directions that capture the greatest variance.

If $v$ is a unit direction vector, the variance of the data projected onto that direction is:

$$
\operatorname{Var}(Xv)=v^T S v
$$

Where:

- $X$ = centred data matrix.
- $v$ = unit direction vector.
- $S$ = covariance matrix of the features.
- $v^T$ = transpose of $v$.

The first principal component maximizes this projected variance. Subsequent components capture the greatest remaining variance subject to being orthogonal to earlier components.

**Explained variance ratio**

$$
EVR_i=\frac{\lambda_i}{\sum_{j=1}^{p}\lambda_j}
$$

Where:

- $\lambda_i$ = eigenvalue associated with principal component $i$.
- $p$ = total number of original features.
- $EVR_i$ = proportion of total variance explained by component $i$.

For example, if the first two components explain 60% and 25% of total variance, together they explain:

$$
60\%+25\%=\boxed{85\%}
$$

Retaining two components would preserve 85% of the variance in this example.

**Advantages of PCA**

- Reduces the number of dimensions.
- Can remove redundancy associated with correlated features.
- Can improve computational efficiency.
- Helps visualize complex data.

**Limitations of PCA**

- New components may be difficult to interpret.
- High variance does not necessarily mean high predictive importance.
- Some information is lost when components are discarded.
- It is sensitive to scaling, so preprocessing decisions matter.

##### 2. Linear Discriminant Analysis (LDA)

LDA is a supervised technique that finds projections that separate known classes as effectively as possible.

Unlike PCA, LDA uses class labels.

Its objective is to maximize separation between class means while limiting the spread of observations within each class.

A common objective is:

$$
J(w)=\frac{w^T S_B w}{w^T S_W w}
$$

Where:

- $w$ = projection direction.
- $S_B$ = between-class scatter matrix.
- $S_W$ = within-class scatter matrix.
- $J(w)$ = ratio measuring class separation after projection.

A larger value indicates a direction with greater between-class separation relative to within-class variation.

For $C$ classes, standard LDA can produce at most $C-1$ discriminant directions.

**Example:** If a dataset contains Pass and Fail labels, LDA can find a projection that separates the two groups based on their feature values.

**Advantages of LDA**

- Uses class information to seek discriminative directions.
- Can reduce dimensions while retaining information relevant to class separation.
- Useful in classification pipelines.

**Limitations of LDA**

- Requires labelled data.
- The standard method is based on assumptions that may not hold for every dataset.
- Its number of discriminant directions is limited by the number of classes.

#### Feature selection versus dimensionality reduction

| Basis | Feature selection | Dimensionality reduction |
|---|---|---|
| Main operation | Selects a subset of existing features | Transforms features into a lower-dimensional representation |
| Resulting features | Original features | Often new derived features |
| Interpretability | Usually easier to interpret | Can be more difficult to interpret |
| Example | Retain age, attendance, and marks | Replace 20 features with 3 principal components |
| Methods | Filter, wrapper, embedded | PCA, LDA |
| Main benefit | Removes irrelevant or redundant inputs | Compresses the representation of data |
| Potential drawback | Useful information may be discarded | New dimensions may be difficult to interpret |

#### Feature extraction versus feature reduction

| Basis | Feature extraction | Feature reduction |
|---|---|---|
| Main purpose | Create a useful representation from raw or existing data | Decrease the number of features or dimensions |
| Typical operation | Derive, transform, or encode information | Select fewer features or project into fewer dimensions |
| Example | Convert text into TF-IDF vectors | Reduce thousands of text-vector dimensions to a smaller set |
| Relationship | May create many features, even when starting with raw data | May use extraction or selection to obtain fewer dimensions |

**Important relationship:** Feature extraction and feature reduction are not mutually exclusive. PCA is both a feature-extraction technique and a dimensionality-reduction technique because it creates new features and retains only selected components.

---

## Quick revision: all three blocks

| Block | What to remember |
|---|---|
| 1. Data Exploration | Data objects and attributes; nominal, ordinal, interval, ratio; mean, median, mode, variance, standard deviation, IQR, covariance, correlation; histogram, box plot, scatter plot, bar chart, line graph, heatmap |
| 2. Data Pre-processing | Missing values, noise, outliers, inconsistent data, duplicates, data types; integrating schemas and records; min-max normalization |
| 3. Feature Engineering | Feature extraction, BoW, TF-IDF, feature selection, dimensionality reduction, PCA, LDA |

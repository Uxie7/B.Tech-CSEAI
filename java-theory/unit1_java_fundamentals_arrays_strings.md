# UNIT I: Java Fundamentals

We'll follow the official syllabus headings, focusing on definitions, syntax, output-based questions, and Java-specific differences from C++. Since you already know C++ fundamentals, prioritize what Java does differently.

---

## 1. Introduction to Java

### 1.1 History of Java

Java was developed by James Gosling and his team at Sun Microsystems. It was initially called Oak and was later renamed Java. It was officially released in 1995.

Important milestones to remember:

- 1991: Green Project began.
- 1995: Java was officially introduced.
- 2010: Oracle acquired Sun Microsystems.

For an exam answer, mention that Java was designed to be portable, secure, robust and suitable for networked applications.

### 1.2 Java Buzzwords

Java's major features, often called buzzwords, describe its design goals.

| Feature | Meaning |
|---|---|
| Simple | Avoids several complex C++ features, such as explicit pointer arithmetic |
| Object-oriented | Supports classes, objects, inheritance, polymorphism and encapsulation |
| Platform-independent | Bytecode can run on compatible JVM implementations |
| Portable | Consistent language behaviour across supported platforms |
| Robust | Strong type checking, exception handling and automatic memory management |
| Secure | Provides bytecode verification, access controls and runtime security mechanisms |
| Multithreaded | Supports concurrent execution using threads |
| Architecture-neutral | Bytecode is not tied to a specific processor architecture |
| High-performance | JIT compilation can optimize frequently executed code |
| Distributed | Provides networking APIs for distributed applications |
| Dynamic | Supports runtime class loading and related dynamic mechanisms |

#### Most important concept: platform independence

Java source code is compiled into bytecode, which is executed by a Java Virtual Machine (JVM).

```
Java source code
Program.java
      ↓
Java compiler (javac)
Compiles source code
      ↓
Bytecode
Program.class
      ↓
JVM
Executes bytecode on the host platform
```

This is the basis of Java's slogan: **Write Once, Run Anywhere**, provided a compatible JVM is available.

### 1.3 JVM, JRE and JDK

| Term | Full form | Purpose |
|---|---|---|
| JVM | Java Virtual Machine | Executes Java bytecode |
| JRE | Java Runtime Environment | Conceptual runtime package containing the JVM and supporting libraries |
| JDK | Java Development Kit | Development tools, including the compiler and runtime components |

Remember the relationship:

- **JVM:** Executes bytecode.
- **JRE:** Provides the runtime environment.
- **JDK:** Provides tools for developing Java programs.

Modern Java distributions do not necessarily provide a separately packaged JRE, but this conceptual distinction remains useful for exams.

### 1.4 Java versus C++

| Concept | Java | C++ |
|---|---|---|
| Compilation | Source → bytecode → JVM execution/JIT | Usually source → native executable |
| Portability | Bytecode runs on compatible JVMs | Native binaries depend on target platforms |
| Multiple class inheritance | Not supported | Supported |
| Memory management | Automatic garbage collection | Manual management and RAII are available |
| Pointers | References; no general pointer arithmetic | Supports pointers and pointer arithmetic |
| Operator overloading | Generally not supported for user-defined classes | Supported |
| Source extension | .java | .cpp |
| Header files | No traditional header files required | Commonly uses headers |
| Root class | Classes implicitly extend Object unless another superclass is specified | No universal root superclass |
| Generics | Type erasure for ordinary Java generics | Templates are a different mechanism |

---

## 2. Data Types, Variables and Type Conversion

### 2.1 Primitive data types

Java has eight primitive types.

| Type | Typical size | Example |
|---|---|---|
| byte | 8 bits | `byte x = 10;` |
| short | 16 bits | `short x = 100;` |
| int | 32 bits | `int x = 500;` |
| long | 64 bits | `long x = 100000L;` |
| float | 32 bits | `float x = 3.5f;` |
| double | 64 bits | `double x = 3.5;` |
| char | 16 bits | `char c = 'A';` |
| boolean | JVM-dependent representation | `boolean flag = true;` |

Java `char` represents a UTF-16 code unit, and `boolean` has the values `true` and `false`.

Reference types include classes, arrays, interfaces and enums. A reference variable can refer to an object or be `null`.

### 2.2 Variables

- **Local variable:** Declared inside a method, constructor or block. It must be initialized before being read.
- **Instance variable:** Belongs to an object; receives a default value if not explicitly initialized.
- **Static variable:** Belongs to the class; shared among instances.

Example:

```java
class Demo {
    int x;            // Instance variable
    static int count; // Static variable

    void show() {
        int y = 10;   // Local variable
        System.out.println(x + " " + count + " " + y);
    }
}
```

For fields, default values include `0` for integer types, `false` for boolean, `'\u0000'` for char, and `null` for reference types.

### 2.3 Type conversion and casting

**Widening conversion:** Converts a value to a type that can represent a wider range of values, generally without an explicit cast.

```java
int x = 10;
double y = x;
System.out.println(y);
```

Output: 10.0

**Narrowing conversion:** Converts to a type with a narrower range or precision and generally requires an explicit cast.

```java
double x = 9.8;
int y = (int) x;
System.out.println(y);
```

Output: 9

The fractional part is discarded; this is not rounding.

Other important points:

- Assigning an `int` literal to a `byte` variable generally requires a cast, except where a compile-time constant fits the target type.
- `float` literals normally require the `f` suffix.
- `long` literals may use the `L` suffix.
- Boolean values cannot be converted to numeric types.

### 2.4 Operators and expressions

Java supports arithmetic, relational, logical, assignment, unary, bitwise, shift and conditional operators.

| Category | Operators |
|---|---|
| Arithmetic | `+`, `-`, `*`, `/`, `%` |
| Relational | `==`, `!=`, `<`, `>`, `<=`, `>=` |
| Logical | `&&`, `\|\|`, `!` |
| Assignment | `=`, `+=`, `-=`, `*=`, `/=` |
| Increment/decrement | `++`, `--` |
| Conditional | `condition ? value1 : value2` |
| Bitwise | `&`, `\|`, `^`, `~` |
| Shift | `<<`, `>>`, `>>>` |

Java integer division truncates toward zero:

```java
System.out.println(7 / 2);
System.out.println(7.0 / 2);
```

Output:

```
3
3.5
```

The `&&` and `||` operators use short-circuit evaluation. The second operand is evaluated only when necessary.

### 2.5 Control statements and decision-making

Java supports:

- `if`, `if-else`, nested `if`
- `switch`
- `for`, enhanced `for`
- `while`, `do-while`
- `break`, `continue`, `return`

Example:

```java
int n = 7;

if (n % 2 == 0) {
    System.out.println("Even");
} else {
    System.out.println("Odd");
}
```

Output: Odd

Remember that `do-while` executes its body at least once, while `while` may execute zero times.

### 2.6 Standard input-output

Java commonly uses `Scanner` for console input.

```java
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int age = sc.nextInt();
        String name = sc.next();

        System.out.println(name + " " + age);
        System.out.printf("Age: %d%n", age);

        sc.close();
    }
}
```

Important methods:

- `nextInt()` — reads an integer.
- `nextDouble()` — reads a double.
- `next()` — reads one token.
- `nextLine()` — reads the remaining line.
- `print()` — prints without automatically adding a newline.
- `println()` — prints and adds a newline.
- `printf()` — formats output.

**Common trap:** `nextInt()` followed by `nextLine()` may cause `nextLine()` to consume the leftover newline. Consume that newline first if you need to read a subsequent full line.

---

# UNIT I: Arrays and String

## 3. Arrays

### 3.1 Definition

An array is an object that stores a fixed number of elements of the same type. Array indexing starts at 0.

#### Declaration, creation and initialization

```java
int[] a;              // Declaration
a = new int[5];       // Creation
int[] b = {10, 20, 30}; // Declaration + initialization
```

You can also write `int a[]`, but `int[] a` is the conventional Java style.

When an array is created, its elements receive default values. For example, an `int` array contains zeros initially.

### 3.2 One-dimensional arrays

```java
int[] a = {10, 20, 30, 40};

for (int i = 0; i < a.length; i++) {
    System.out.println(a[i]);
}
```

Output:

```
10
20
30
40
```

Important properties:

- `a.length` gives the array size.
- Valid indices range from `0` to `a.length - 1`.
- Accessing an invalid index throws `ArrayIndexOutOfBoundsException`.
- Array size is fixed after creation.

### 3.3 Enhanced for loop

Used to iterate through array elements without explicitly managing indices.

```java
int[] a = {10, 20, 30};

for (int x : a) {
    System.out.println(x);
}
```

This is convenient when you need each element but do not need its index.

### 3.4 Two-dimensional arrays

Java represents a two-dimensional array as an array of arrays. Rows can therefore have different lengths.

```java
int[][] a = {
    {1, 2, 3},
    {4, 5, 6}
};

for (int i = 0; i < a.length; i++) {
    for (int j = 0; j < a[i].length; j++) {
        System.out.print(a[i][j] + " ");
    }
    System.out.println();
}
```

Output:

```
1 2 3
4 5 6
```

Remember:

- `a.length` gives the number of rows.
- `a[i].length` gives the number of elements in row `i`.
- `new int[3][4]` creates three rows, each with four integer elements.
- Java also supports jagged arrays, such as `new int[3][]`, whose rows can be initialized to different lengths.

### 3.5 Arrays versus individual variables

Arrays are useful when multiple values of the same type must be stored and processed using loops. They simplify operations such as searching, sorting, summing and traversing matrices.

---

## 4. String Class

### 4.1 Definition

A String is an object representing a sequence of characters. Java's `String` class belongs to the `java.lang` package, which is imported automatically.

```java
String s = "Java";
```

Strings are immutable: once a String object is created, its contents cannot be changed. Operations that appear to modify a String produce a new String instead.

```java
String s = "Java";
s.concat(" Programming");

System.out.println(s);
```

Output:

```
Java
```

The result of `concat()` was not assigned back to `s`.

Correct version:

```java
s = s.concat(" Programming");
System.out.println(s);
```

Output: Java Programming

### 4.2 Important String methods

| Method | Purpose | Example result |
|---|---|---|
| length() | Returns the number of UTF-16 code units | `"Java".length()` → 4 |
| charAt(i) | Returns the character at index i | `"Java".charAt(1)` → 'a' |
| substring(a, b) | Extracts indices a through b-1 | `"Java".substring(1,3)` → "av" |
| equals(s) | Compares String contents | `"Java".equals("Java")` → true |
| equalsIgnoreCase(s) | Compares contents ignoring case | `"Java".equalsIgnoreCase("JAVA")` → true |
| compareTo(s) | Lexicographically compares Strings | `"abc".compareTo("abd")` → negative value |
| indexOf(s) | Finds the first occurrence | `"banana".indexOf("na")` → 2 |
| toUpperCase() | Converts letters to uppercase | "java" → "JAVA" |
| toLowerCase() | Converts letters to lowercase | "JAVA" → "java" |
| trim() | Removes leading/trailing characters up to U+0020 | `" hi ".trim()` → "hi" |
| split(regex) | Splits using a regular expression | `"a,b".split(",")` → ["a","b"] |
| contains(s) | Checks whether a sequence occurs | `"Java".contains("av")` → true |

**Important:** `substring(begin, end)` excludes the ending index. Also, `split()` accepts a regular expression, so some special characters need escaping.

### 4.3 length versus length()

This is a common exam question.

```java
int[] a = {1, 2, 3};
String s = "Java";

System.out.println(a.length);
System.out.println(s.length());
```

Output:

```
3
4
```

- Arrays use the `length` property.
- Strings use the `length()` method.

### 4.4 == versus equals()

This distinction is particularly important for Java Strings.

```java
String s1 = new String("Java");
String s2 = new String("Java");

System.out.println(s1 == s2);
System.out.println(s1.equals(s2));
```

Output:

```
false
true
```

`==` compares object references. `equals()` compares String contents.

String literals can be stored in the String pool, so two identical literals may refer to the same object:

```java
String a = "Java";
String b = "Java";

System.out.println(a == b);
```

Output: true in this case.

Do not rely on `==` for comparing String contents.

---

## Mind map: quick revision

```
JAVA FUNDAMENTALS, ARRAYS AND STRINGS
├── Introduction to Java
│   ├── History
│   │   ├── James Gosling at Sun Microsystems
│   │   ├── Originally called Oak
│   │   ├── Green Project 1991
│   │   ├── Released 1995
│   │   └── Oracle acquired Sun 2010
│   ├── Buzzwords
│   │   ├── Simple
│   │   ├── Object oriented
│   │   ├── Platform independent
│   │   ├── Portable
│   │   ├── Robust
│   │   ├── Secure
│   │   ├── Multithreaded
│   │   ├── Architecture neutral
│   │   ├── High performance via JIT
│   │   ├── Distributed
│   │   └── Dynamic
│   ├── Platform independence
│   │   ├── Source file .java
│   │   ├── javac compiles
│   │   ├── Bytecode .class
│   │   ├── JVM executes
│   │   └── Write Once Run Anywhere
│   ├── JVM JRE JDK
│   │   ├── JVM runs bytecode
│   │   ├── JRE runtime environment
│   │   └── JDK development tools
│   └── Java vs C++
│       ├── Bytecode vs native executable
│       ├── No multiple class inheritance
│       ├── Garbage collection
│       ├── No pointer arithmetic
│       ├── No operator overloading
│       ├── No header files
│       └── Object is root class
├── Data types and variables
│   ├── 8 primitives
│   │   ├── byte 8 bits
│   │   ├── short 16 bits
│   │   ├── int 32 bits
│   │   ├── long 64 bits needs L
│   │   ├── float 32 bits needs f
│   │   ├── double 64 bits
│   │   ├── char 16 bits UTF-16
│   │   └── boolean true or false
│   ├── Reference types
│   │   ├── Classes
│   │   ├── Arrays
│   │   ├── Interfaces
│   │   ├── Enums
│   │   └── Can be null
│   ├── Variable kinds
│   │   ├── Local must be initialized
│   │   ├── Instance gets default value
│   │   └── Static shared by class
│   └── Field defaults
│       ├── 0 for integers
│       ├── false for boolean
│       ├── null char for char
│       └── null for references
├── Type conversion
│   ├── Widening
│   │   ├── int to double
│   │   └── Implicit
│   ├── Narrowing
│   │   ├── double to int
│   │   ├── Explicit cast
│   │   └── Fraction truncated not rounded
│   └── Rules
│       ├── boolean never converts
│       ├── float literal needs f
│       └── long literal uses L
├── Operators and control
│   ├── Operators
│   │   ├── Arithmetic
│   │   ├── Relational
│   │   ├── Logical short circuit
│   │   ├── Assignment
│   │   ├── Increment decrement
│   │   ├── Ternary conditional
│   │   ├── Bitwise
│   │   ├── Shift
│   │   └── Integer division truncates so 7 / 2 is 3
│   └── Control statements
│       ├── if, if-else, nested if
│       ├── switch
│       ├── for and enhanced for
│       ├── while runs zero or more times
│       ├── do while runs at least once
│       └── break continue return
├── Standard input output
│   ├── Scanner
│   │   ├── nextInt
│   │   ├── nextDouble
│   │   ├── next reads one token
│   │   └── nextLine reads rest of line
│   ├── Output
│   │   ├── print no newline
│   │   ├── println adds newline
│   │   └── printf formatted
│   └── Trap
│       └── nextInt then nextLine eats leftover newline
├── Arrays
│   ├── Basics
│   │   ├── Fixed size object
│   │   ├── Index starts at 0
│   │   ├── Default values on creation
│   │   └── Declare then create then initialize
│   ├── One dimensional
│   │   ├── length is a property
│   │   ├── Valid index 0 to length minus 1
│   │   ├── ArrayIndexOutOfBoundsException
│   │   └── Enhanced for loop
│   └── Two dimensional
│       ├── Array of arrays
│       ├── a.length gives rows
│       ├── Row length gives columns
│       └── Jagged arrays allowed
└── String class
    ├── Core facts
    │   ├── In java.lang
    │   ├── Immutable
    │   └── concat result must be assigned back
    ├── Methods
    │   ├── length
    │   ├── charAt
    │   ├── substring end index excluded
    │   ├── equals
    │   ├── equalsIgnoreCase
    │   ├── compareTo
    │   ├── indexOf
    │   ├── toUpperCase toLowerCase
    │   ├── trim
    │   ├── split takes regex
    │   └── contains
    └── Common exam traps
        ├── Array length property vs String length method
        ├── == compares references
        ├── equals compares contents
        └── String pool makes identical literals share object
```

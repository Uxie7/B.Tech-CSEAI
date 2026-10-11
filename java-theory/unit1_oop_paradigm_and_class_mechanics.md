# UNIT I: Object Oriented Paradigm and Class Mechanics

We'll use your official syllabus headings and cover the listed topics as exam-ready study material, with definitions, Java syntax, examples, output, and important comparisons. Since you already know OOP in C++, the focus is on Java-specific rules and differences.

---

## 1. Object Oriented Paradigm

### 1.1 Class, Object, Reference and Object Lifetime

#### Class

A class is a blueprint or template that defines the data members (fields) and behaviour (methods) of objects.

```java
class Student {
    int rollNo;
    String name;

    void display() {
        System.out.println(rollNo + " " + name);
    }
}
```

Here, `Student` defines two fields and one method.

#### Object

An object is an instance of a class. It has state (field values) and behaviour (methods).

```java
Student s = new Student();
s.rollNo = 101;
s.name = "Alice";
s.display();
```

Output:

```
101 Alice
```

`new Student()` creates an object and invokes its constructor.

#### Reference

A reference variable holds a reference to an object or `null`. It is used to access the object's accessible members.

```java
Student s1 = new Student();
Student s2 = s1;
```

Both `s1` and `s2` refer to the same object. Changing a field through either reference affects that same object.

```java
s2.rollNo = 20;
System.out.println(s1.rollNo);
```

Output: 20

**Important:** Java references are not C++ pointers. Java does not expose general pointer arithmetic or direct memory-address manipulation.

#### Object lifetime

An object created using `new` remains available while it is reachable through the relevant reference relationships, subject to Java's garbage-collection rules.

```java
Student s = new Student();
s = null;
```

Setting `s` to `null` removes that reference to the object. It does not guarantee that the object is immediately destroyed, especially if another reference still points to it.

#### Garbage collection

Garbage collection (GC) is Java's automatic memory-management mechanism for reclaiming memory occupied by objects that are no longer reachable.

Key points:

- The programmer generally does not explicitly free objects as in C++ with `delete`.
- An object may become eligible for garbage collection when it is no longer reachable.
- Eligibility does not mean immediate collection.
- The exact time of collection is not guaranteed.
- `System.gc()` is only a request or suggestion to the JVM, not a guarantee that collection will occur.

---

## 2. Constructors and Constructor Overloading

### 2.1 Constructor

A constructor is a special class member used to initialize a newly created object.

#### Characteristics

- Its name is the same as the class name.
- It has no return type, not even `void`.
- It is invoked during object creation.
- Constructors can be overloaded.
- Constructors are not inherited and cannot be overridden.

#### A. Default constructor

If a class declares no constructors, the compiler supplies a default no-argument constructor.

```java
class Student {
    int rollNo;
}
```

Java supplies an implicit no-argument constructor here.

**Important distinction:** If you declare any constructor yourself, the compiler does not automatically supply the default constructor.

#### B. No-argument constructor written by the programmer

```java
class Student {
    Student() {
        System.out.println("Object created");
    }
}
```

This is a no-argument constructor, but it is explicitly defined by the programmer, not the compiler-generated default constructor.

#### C. Parameterized constructor

A constructor that accepts parameters to initialize an object.

```java
class Student {
    int rollNo;
    String name;

    Student(int r, String n) {
        rollNo = r;
        name = n;
    }
}
```

Usage:

```java
Student s = new Student(101, "Alice");
```

#### Constructor overloading

Constructor overloading means defining multiple constructors in the same class with different parameter lists.

```java
class Student {
    int rollNo;
    String name;

    Student() {
        rollNo = 0;
        name = "Unknown";
    }

    Student(int r) {
        rollNo = r;
        name = "Unknown";
    }

    Student(int r, String n) {
        rollNo = r;
        name = n;
    }
}
```

Each constructor provides a different way to initialize a `Student`.

| Default constructor | Parameterized constructor |
|---|---|
| Compiler-generated only if no constructor is declared | Declared by the programmer with parameters |
| Takes no arguments | Takes one or more arguments |
| Provides default initialization behaviour | Initializes using supplied values |

---

## 3. this Keyword

The `this` keyword refers to the current object whose instance method or constructor is executing.

### 3.1 Distinguishing instance variables from parameters

```java
class Student {
    int rollNo;

    Student(int rollNo) {
        this.rollNo = rollNo;
    }
}
```

Here:

- `this.rollNo` refers to the instance field.
- `rollNo` refers to the constructor parameter.

Without `this`, `rollNo = rollNo;` would assign the parameter to itself and leave the instance field unchanged.

### 3.2 Calling another constructor using this()

A constructor can invoke another constructor in the same class using `this(...)`.

```java
class Student {
    int rollNo;
    String name;

    Student() {
        this(0, "Unknown");
    }

    Student(int r, String n) {
        rollNo = r;
        name = n;
    }
}
```

Calling `new Student()` invokes the second constructor through `this(0, "Unknown")`.

Rules:

- `this(...)` must be the first statement in a constructor under traditional Java syntax.
- It is used for constructor chaining.
- A constructor cannot directly or indirectly invoke itself in a cycle.
- `this` cannot be used in a static method because a static method has no current instance.

---

## 4. Access Modifiers

Access modifiers control the visibility of classes and class members.

| Modifier | Same class | Same package | Subclass in another package | Unrelated class in another package |
|---|---|---|---|---|
| private | Yes | No | No | No |
| Default (no modifier) | Yes | Yes | No | No |
| protected | Yes | Yes | Yes, with restrictions | No |
| public | Yes | Yes | Yes | Yes, if the declaring type is accessible |

### Example

```java
class Account {
    private double balance = 5000;

    public double getBalance() {
        return balance;
    }
}
```

The field `balance` cannot be accessed directly by unrelated classes, but the public method provides controlled access to its value.

### Key points

- `private`: accessible within the declaring class and permitted nestmates.
- Default/package-private: accessible within the same package.
- `protected`: accessible within the same package and through the applicable subclass access rules.
- `public`: accessible wherever the declaring type is accessible.
- Top-level classes can be `public` or package-private, but not `private` or `protected`.

---

## 5. Class Mechanics

### 5.1 Static Variables and Methods in a Class

#### Static variable

A static variable belongs to the class rather than to each individual object. Only one class-level variable exists for that class's loaded definition, rather than a separate instance field per object.

```java
class Student {
    int rollNo;
    static String college = "IGDTUW";
}
```

All `Student` objects share the same `college` variable.

#### Static method

A static method belongs to the class and can be called without creating an instance.

```java
class MathUtil {
    static int square(int n) {
        return n * n;
    }
}
```

Usage:

```java
System.out.println(MathUtil.square(5));
```

Output:

```
25
```

#### Static versus instance members

| Static member | Instance member |
|---|---|
| Belongs to the class | Belongs to an object |
| One class-level variable shared by instances | Each object has its own instance field |
| Can be accessed using the class name | Usually accessed through an object |
| Cannot directly access instance members without an object reference | Can access both instance and static members |
| Cannot use `this` | Instance methods can use `this` |

#### Example

```java
class Counter {
    static int count = 0;
    int id;

    Counter(int id) {
        this.id = id;
        count++;
    }
}
```

```java
Counter c1 = new Counter(1);
Counter c2 = new Counter(2);

System.out.println(Counter.count);
```

Output: 2

Both constructors increment the same static variable.

**Exam point:** A static method cannot directly access a non-static field because no particular object is implied.

---

### 5.2 Overloading Methods and Constructors

#### Method overloading

Method overloading means having multiple methods with the same name but different parameter lists.

```java
class Calculator {
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
}
```

These methods are overloaded because their parameter lists differ.

#### Rules

- The method name is the same.
- The parameter lists must differ in number, types or order.
- Return type alone cannot distinguish overloaded methods.
- Overloading is resolved at compile time.
- Constructors can also be overloaded.

This is invalid:

```java
int show() { return 1; }
double show() { return 1.0; } // Compilation error
```

The parameter lists are identical; only the return types differ.

#### Overloading versus overriding

| Overloading | Overriding |
|---|---|
| Same name, different parameter lists | Redefines an inherited instance method |
| Can occur within one class | Requires an inheritance relationship |
| Compile-time method selection | Runtime dispatch for overridden instance methods |
| Return type alone cannot distinguish methods | Return type must be compatible |
| Example: `add(int,int)` and `add(double,double)` | `Dog.sound()` replacing `Animal.sound()` |

---

### 5.3 Nested and Inner Class

#### Nested class

A nested class is a class declared inside another class.

Java distinguishes between:

1. **Static nested class:** Declared with `static`.
2. **Inner class:** A non-static nested class associated with an enclosing instance.

#### A. Static nested class

```java
class Outer {
    static class Nested {
        void display() {
            System.out.println("Static nested class");
        }
    }
}
```

Usage:

```java
Outer.Nested obj = new Outer.Nested();
obj.display();
```

A static nested class does not require an instance of `Outer` to be created.

#### B. Inner class

```java
class Outer {
    int x = 10;

    class Inner {
        void display() {
            System.out.println(x);
        }
    }
}
```

Usage:

```java
Outer outer = new Outer();
Outer.Inner inner = outer.new Inner();
inner.display();
```

Output:

```
10
```

An inner class can access instance members of its enclosing object.

#### Nested class versus inner class

| Static nested class | Inner class |
|---|---|
| Declared using `static` | Non-static nested class |
| No enclosing instance is required | Associated with an enclosing instance |
| Cannot directly access enclosing instance members | Can access enclosing instance members |
| Created using `new Outer.Nested()` | Created using `outer.new Inner()` |

**Remember:** Every inner class is a nested class, but not every nested class is an inner class.

---

### 5.4 Object Class

The `Object` class is the root superclass of Java's class hierarchy. A class that does not explicitly extend another class implicitly extends `Object`, except for the special case of `Object` itself.

It provides methods available to ordinary objects, including `toString()`, `equals()`, `hashCode()` and `getClass()`.

#### Important methods

| Method | Purpose |
|---|---|
| toString() | Returns a String representation of an object |
| equals(Object obj) | Tests equality according to the method's implementation |
| hashCode() | Returns an integer hash code |
| getClass() | Returns the object's runtime class |
| clone() | Creates a field-by-field copy when the relevant cloning requirements are met |
| wait() | Causes a thread to wait on an object's monitor |
| notify() | Wakes one thread waiting on that object's monitor |
| notifyAll() | Wakes all threads waiting on that object's monitor |

For this syllabus, prioritize the first four methods.

#### A. toString()

Returns a String representation of an object. The default implementation typically includes the class name and a hash-code-related hexadecimal representation.

It can be overridden for meaningful output.

```java
class Student {
    String name = "Alice";

    public String toString() {
        return name;
    }
}
```

```java
Student s = new Student();
System.out.println(s);
```

Output:

```
Alice
```

Passing an object to `println()` normally results in its String representation being printed.

#### B. equals()

The default implementation in `Object` tests whether two references identify the same object. A class can override `equals()` to define logical equality.

For example, two `Student` objects might be considered equal if their roll numbers match.

#### C. hashCode()

Returns an integer hash code used by hash-based collections such as `HashMap` and `HashSet`.

**Important contract:** If two objects are equal according to `equals()`, they must have the same hash code. Unequal objects may still have the same hash code.

If you override `equals()`, you should generally override `hashCode()` consistently.

#### D. getClass()

Returns the runtime class of the object.

```java
Student s = new Student();
System.out.println(s.getClass().getName());
```

For a class named `Student` in the unnamed package, this prints:

```
Student
```

#### == versus equals()

| == | equals() |
|---|---|
| Compares primitive values when used with primitives | Method for object equality |
| For references, checks reference identity | Checks whatever equality the method implements |
| Cannot be customized as an operator | Can be overridden |
| Two separate objects may compare unequal | Two separate objects may compare equal |

Example:

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

The two `String` objects are distinct, but their contents are equal.

---

## Final revision: key distinctions

| Topic | Must remember |
|---|---|
| Class vs object | Blueprint vs instance |
| Reference | Refers to an object or null |
| Constructor | Same name as class, no return type |
| Default constructor | Compiler supplies it only if no constructor is declared |
| this | Current object; can chain constructors using `this(...)` |
| Static | Class-level member |
| Overloading | Same name, different parameter lists |
| Overriding | Subclass implementation of inherited instance method |
| Nested class | Any class declared inside another class |
| Inner class | Non-static nested class |
| toString() | String representation |
| equals() | Logical equality if overridden |
| hashCode() | Hash-based collection support |
| getClass() | Runtime class information |
| Garbage collection | Automatic reclamation of eligible objects; timing is not guaranteed |

---

## Quick self-test

### 7-question quiz

0/7 answered

**1. When does Java provide a default constructor?**

- [ ] For every class
- [ ] Only when no constructor is declared ✓
- [ ] Only when a static method exists
- [ ] Only for abstract classes

**2. What does `this` refer to in an instance method?**

- [ ] The superclass
- [ ] The current object ✓
- [ ] The class itself
- [ ] The next object created

**3. Which is true of a static method?**

- [ ] It can directly use this
- [ ] It belongs to each object separately
- [ ] It can be called using the class name ✓
- [ ] It must be overridden

**4. Can methods be overloaded using only different return types?**

- [ ] Yes
- [ ] No ✓
- [ ] Only if static
- [ ] Only in subclasses

**5. Which statement about nested classes is correct?**

- [ ] All nested classes are inner classes
- [ ] A static nested class requires an outer object
- [ ] An inner class is non-static ✓
- [ ] Nested classes cannot access outer members

**6. If equals() considers two objects equal, what must be true?**

- [ ] Their references must be identical
- [ ] Their hash codes must be equal ✓
- [ ] Their class names must differ
- [ ] Their fields must all be static

**7. Does setting a reference to null guarantee immediate garbage collection?**

- [ ] Yes
- [ ] No ✓
- [ ] Only for Strings
- [ ] Only for static variables

---

## Mind map: quick revision

```
OOP PARADIGM AND CLASS MECHANICS
├── Class and object
│   ├── Class
│   │   ├── Blueprint or template
│   │   └── Fields and methods
│   ├── Object
│   │   ├── Instance of a class
│   │   ├── State and behaviour
│   │   └── Created using new
│   └── Reference
│       ├── Refers to object or null
│       ├── Not a C++ pointer
│       └── Two references can share one object
├── Object lifetime
│   ├── Reachable object stays alive
│   ├── Setting null removes only one reference
│   └── Garbage collection
│       ├── Automatic
│       ├── Eligible does not mean collected now
│       ├── Timing not guaranteed
│       └── System.gc is only a request
├── Constructors
│   ├── Rules
│   │   ├── Same name as class
│   │   ├── No return type
│   │   ├── Not inherited
│   │   └── Cannot be overridden
│   ├── Kinds
│   │   ├── Default only if none declared
│   │   ├── No argument written by programmer
│   │   └── Parameterized
│   └── Overloading
│       ├── Different parameter lists
│       └── Same class
├── this keyword
│   ├── Refers to current object
│   ├── this.field separates field from parameter
│   ├── this call chains constructors
│   ├── Must be first statement
│   └── Not allowed in static method
├── Access modifiers
│   ├── private same class only
│   ├── Default same package
│   ├── protected package plus subclasses
│   ├── public everywhere accessible
│   └── Top level class only public or default
├── Static members
│   ├── Belong to class
│   ├── One shared copy
│   ├── Called using class name
│   ├── Cannot use this
│   └── Cannot touch instance members directly
├── Method overloading
│   ├── Same name
│   ├── Different number, type or order of parameters
│   ├── Return type alone not enough
│   ├── Resolved at compile time
│   └── Overriding differs
│       ├── Needs inheritance
│       └── Runtime dispatch
├── Nested and inner classes
│   ├── Static nested
│   │   ├── Declared static
│   │   ├── No outer object needed
│   │   └── new Outer.Nested
│   ├── Inner class
│   │   ├── Non static
│   │   ├── Needs outer object
│   │   ├── outer.new Inner
│   │   └── Can use outer instance members
│   └── Every inner class is nested
└── Object class
    ├── Root superclass
    ├── toString
    │   ├── String form of object
    │   └── Override for meaningful output
    ├── equals
    │   ├── Default compares references
    │   └── Override for logical equality
    ├── hashCode
    │   ├── Used by HashMap and HashSet
    │   └── Equal objects need equal hash codes
    ├── getClass
    │   └── Runtime class
    ├── Others
    │   ├── clone
    │   └── wait notify notifyAll
    └── == vs equals
        ├── == identity
        └── equals content when overridden
```

# UNIT II: Inheritance and Polymorphism

We'll follow the official syllabus headings in order and build proper exam-ready notes under each topic. Since you have studied OOP in C++, I'll explain the core concepts through familiar OOP principles and emphasize Java-specific rules, syntax, and output-based questions.

---

## 1. Class Inheritance

### 1.1 Definition

Inheritance is an OOP mechanism in which a class acquires accessible properties and behaviours of another class, allowing code reuse and the creation of hierarchical relationships between classes.

- **Superclass / Parent class:** The class whose members are inherited.
- **Subclass / Child class:** The class that inherits from another class.
- **extends:** Keyword used for class inheritance in Java.

#### Syntax

```java
class Parent {
    void display() {
        System.out.println("Parent class");
    }
}

class Child extends Parent {
    void show() {
        System.out.println("Child class");
    }
}
```

Usage:

```java
Child c = new Child();
c.display();
c.show();
```

Output:

```
Parent class
Child class
```

The `Child` class can use the inherited accessible `display()` method without redefining it.

#### Advantages of inheritance

1. **Code reusability:** Avoids rewriting common functionality.
2. **Extensibility:** Subclasses can add new features.
3. **Method overriding:** Subclasses can provide specialized implementations.
4. **Polymorphism:** A superclass reference can refer to subclass objects.
5. **Maintainability:** Shared functionality can be maintained in a common superclass.

**Java vs C++:** Java uses `extends` for class inheritance, whereas C++ uses `:`. Java classes do not support multiple inheritance of classes.

---

## 2. Member Access

Member access determines which inherited fields, methods and constructors can be accessed by a subclass.

### 2.1 Access modifiers

| Modifier | Same class | Same package | Subclass in another package | Unrelated class in another package |
|---|---|---|---|---|
| private | Yes | No | No | No |
| Default (no modifier) | Yes | Yes | No | No |
| protected | Yes | Yes | Yes, with restrictions | No |
| public | Yes | Yes | Yes | Yes, if the type is accessible |

#### Example

```java
class Parent {
    private int a = 10;
    protected int b = 20;
    public int c = 30;
}

class Child extends Parent {
    void display() {
        // System.out.println(a); // Error
        System.out.println(b);    // Allowed
        System.out.println(c);    // Allowed
    }
}
```

Output:

```
20
30
```

#### Important points

- A subclass does not directly access `private` superclass members.
- Private members still exist as part of the superclass state, but they are not directly accessible in subclass code.
- `protected` members are accessible within the same package and in subclasses across packages, subject to Java's protected-access rules.
- Constructors are not inherited, although a subclass constructor can invoke a superclass constructor.

#### Member access and inheritance

A subclass can inherit accessible members but can also declare its own members.

If a subclass declares a field with the same name as a superclass field, it hides that field. Fields are not overridden like instance methods.

---

## 3. Forms of Inheritance

Your syllabus specifically names four forms: specialization, specification, construction and extension. These describe inheritance in terms of design purpose, so learn them separately from the structural forms such as single and multilevel inheritance.

### 3.1 Specialization

Specialization means creating a more specific class from a general class.

Example: Vehicle → Car

```java
class Vehicle {
    void move() {
        System.out.println("Vehicle moves");
    }
}

class Car extends Vehicle {
    void drive() {
        System.out.println("Car drives");
    }
}
```

Here, `Car` is a specialized form of `Vehicle`.

### 3.2 Specification

Specification refers to defining a general contract or expected behaviour that a class must fulfil. In Java, interfaces and abstract classes are commonly used for this purpose.

```java
interface Shape {
    double area();
}

class Circle implements Shape {
    double radius = 2;

    public double area() {
        return Math.PI * radius * radius;
    }
}
```

The interface specifies what `area()` must do, while `Circle` provides the implementation.

### 3.3 Construction

Construction refers to creating a new class by combining or reusing existing class functionality as building blocks.

For example, a `Car` class may reuse common vehicle behaviour while adding car-specific features.

```java
class Vehicle {
    void start() {
        System.out.println("Vehicle started");
    }
}

class Car extends Vehicle {
    void openBoot() {
        System.out.println("Boot opened");
    }
}
```

Here, the subclass is constructed by extending the existing class.

### 3.4 Extension

Extension means extending an existing class with additional properties or behaviours without changing the original class.

```java
class Employee {
    void work() {
        System.out.println("Employee working");
    }
}

class Manager extends Employee {
    void manageTeam() {
        System.out.println("Managing team");
    }
}
```

`Manager` retains the accessible functionality of `Employee` and adds a new capability.

**Exam caution:** These four labels are textbook-dependent and are not the standard Java structural inheritance categories. Use the precise definitions and examples given in your lecturer's notes if they differ. The code examples above illustrate the general ideas rather than a universal formal classification.

---

## 4. Multilevel Inheritance

### Definition

Multilevel inheritance occurs when a class inherits from a class that itself inherits from another class, forming a chain.

Example:

```
Animal
  ↓
Mammal extends Animal
  ↓
Dog extends Mammal
```

```java
class Animal {
    void eat() {
        System.out.println("Eating");
    }
}

class Mammal extends Animal {
    void walk() {
        System.out.println("Walking");
    }
}

class Dog extends Mammal {
    void bark() {
        System.out.println("Barking");
    }
}
```

A `Dog` object can call `eat()`, `walk()` and `bark()`.

```java
Dog d = new Dog();
d.eat();
d.walk();
d.bark();
```

Output:

```
Eating
Walking
Barking
```

### Structural forms you should recognize

| Form | Meaning |
|---|---|
| Single | One subclass extends one superclass |
| Multilevel | Inheritance occurs through a chain of classes |
| Hierarchical | Multiple subclasses extend the same superclass |
| Multiple | One class inherits from multiple classes; not supported for Java classes |
| Hybrid | Combination of structural inheritance forms; Java can combine class inheritance and interface implementation |

Java supports multiple inheritance of type through interfaces, even though it prohibits extending multiple classes.

---

## 5. Overriding Methods

### Definition

Method overriding occurs when a subclass provides a new implementation of an inherited instance method with a compatible signature and return type.

It enables runtime polymorphism.

### Example

```java
class Animal {
    void sound() {
        System.out.println("Animal sound");
    }
}

class Dog extends Animal {
    @Override
    void sound() {
        System.out.println("Dog barks");
    }
}
```

Usage:

```java
Animal a = new Dog();
a.sound();
```

Output:

```
Dog barks
```

Although `a` is declared as type `Animal`, the actual object is a `Dog`. Therefore, Java executes the overridden `Dog.sound()` method.

### Rules of method overriding

1. The subclass method must have a compatible signature.
2. The return type must be the same or covariant for reference types.
3. The overriding method cannot reduce access visibility.
4. A `final` method cannot be overridden.
5. A `private` superclass method is not overridden because it is not inherited as an accessible method.
6. Static methods are hidden rather than overridden.
7. Constructors cannot be overridden.
8. The `@Override` annotation helps the compiler verify that a method really overrides an inherited method.

### Overloading vs overriding

| Overloading | Overriding |
|---|---|
| Same method name with different parameter lists | Same inherited instance-method signature |
| Usually occurs within the same class, though it can span inherited methods | Requires inheritance |
| Resolved at compile time | Runtime dispatch applies to overridden instance methods |
| Return type alone cannot distinguish overloads | Return type must be compatible |
| Example: `add(int, int)` and `add(double, double)` | `Dog.sound()` replacing inherited `Animal.sound()` |

---

## 6. Use of super and final Keywords

### 6.1 super keyword

The `super` keyword refers to the immediate superclass context. It is used to access superclass members or invoke a superclass constructor.

#### A. Accessing a superclass method

```java
class Parent {
    void display() {
        System.out.println("Parent");
    }
}

class Child extends Parent {
    void display() {
        super.display();
        System.out.println("Child");
    }
}
```

Output:

```
Parent
Child
```

#### B. Accessing a hidden superclass field

```java
class Parent {
    int x = 10;
}

class Child extends Parent {
    int x = 20;

    void show() {
        System.out.println(x);
        System.out.println(super.x);
    }
}
```

Output:

```
20
10
```

#### C. Calling a superclass constructor

```java
class Parent {
    Parent(int x) {
        System.out.println("Parent: " + x);
    }
}

class Child extends Parent {
    Child() {
        super(10);
        System.out.println("Child constructor");
    }
}
```

Output:

```
Parent: 10
Child constructor
```

**Important:** A `super(...)` constructor invocation must occur first in the constructor body under traditional Java syntax. Java 25 introduced flexible constructor bodies with restricted statements permitted before the explicit constructor invocation; for a standard exam answer, use the traditional rule unless your syllabus covers the newer feature.

### 6.2 final keyword

The `final` keyword restricts modification or extension, depending on where it is applied.

#### A. Final variable

A final variable can be assigned only once.

```java
final int MAX = 100;
// MAX = 200; // Compilation error
```

For a reference variable, `final` prevents reassignment of the reference, but it does not automatically make the referenced object immutable.

#### B. Final method

A final method cannot be overridden in a subclass.

```java
class Parent {
    final void display() {
        System.out.println("Fixed method");
    }
}
```

A subclass cannot override `display()`.

#### C. Final class

A final class cannot be extended.

```java
final class Security {
}

// class AdvancedSecurity extends Security {} // Error
```

Example of a final class in Java: `String`.

| Usage | Meaning |
|---|---|
| final variable | Cannot be reassigned after assignment |
| final method | Cannot be overridden |
| final class | Cannot be subclassed |

---

## 7. Abstract Methods

### Definition

An abstract method is a method declared without a method body, leaving its implementation to a concrete subclass.

### Syntax

```java
abstract void calculate();
```

Example:

```java
abstract class Shape {
    abstract double area();
}
```

The method `area()` specifies behaviour but does not define how that behaviour is implemented.

### Rules

- An abstract method has no method body in its ordinary declaration.
- A class containing an abstract method must be declared abstract.
- A concrete subclass must implement all inherited abstract methods unless it is also abstract.
- Abstract methods cannot be `private`, `static` or `final`, because they must be eligible for implementation by subclasses.
- An abstract method cannot be declared in a non-abstract class.

---

## 8. Abstract Class

### Definition

An abstract class is a class declared with the `abstract` keyword that cannot be instantiated directly. It may contain abstract methods, concrete methods, fields and constructors.

### Example

```java
abstract class Shape {
    abstract double area();

    void display() {
        System.out.println("Calculating area");
    }
}

class Circle extends Shape {
    double radius = 5;

    @Override
    double area() {
        return Math.PI * radius * radius;
    }
}

class Main {
    public static void main(String[] args) {
        Shape s = new Circle();
        s.display();
        System.out.println(s.area());
    }
}
```

Output:

```
Calculating area
78.53981633974483
```

### Why use abstract classes?

- To define a common base for related classes.
- To share common fields and implemented methods.
- To require subclasses to implement particular methods.
- To support abstraction and runtime polymorphism.

### Important points

- An abstract class cannot be instantiated directly.
- It can have constructors, which run during subclass object creation.
- It can have both abstract and concrete methods.
- It can be extended by another abstract or concrete class.
- A concrete subclass must implement all inherited abstract methods.

---

## 9. Polymorphism and Runtime Method Dispatch

Although the syllabus heading combines inheritance and polymorphism, make sure you understand how overriding enables runtime polymorphism.

Polymorphism means that the same interface or superclass reference can represent objects with different implementations of the same operation.

Example:

```java
class Animal {
    void sound() {
        System.out.println("Animal sound");
    }
}

class Dog extends Animal {
    @Override
    void sound() {
        System.out.println("Bark");
    }
}

class Cat extends Animal {
    @Override
    void sound() {
        System.out.println("Meow");
    }
}
```

```java
Animal a;

a = new Dog();
a.sound();

a = new Cat();
a.sound();
```

Output:

```
Bark
Meow
```

The method executed depends on the actual object's class, not merely the reference variable's declared type.

### Upcasting

Upcasting is assigning a subclass object to a superclass reference.

```java
Animal a = new Dog();
```

This is valid without an explicit cast.

However, the reference can directly access only members available through its declared type. Overridden instance methods still use runtime dispatch.

### Constructor execution order

When creating a subclass object, Java first performs superclass construction and then completes subclass construction.

```java
class Parent {
    Parent() {
        System.out.println("Parent constructor");
    }
}

class Child extends Parent {
    Child() {
        System.out.println("Child constructor");
    }
}
```

Output:

```
Parent constructor
Child constructor
```

This order ensures that superclass initialization takes place before the subclass constructor completes.

---

## 10. High-priority comparison table

| Concept | Key exam point |
|---|---|
| Inheritance | Reuses and extends accessible superclass functionality |
| Method overriding | Replaces an inherited instance-method implementation |
| Runtime polymorphism | Executes the overridden method based on the actual object |
| super | Accesses superclass members or invokes its constructor |
| final method | Cannot be overridden |
| final class | Cannot be extended |
| Abstract method | Declared without a body |
| Abstract class | Cannot be instantiated directly |
| Upcasting | Subclass object referenced using a superclass type |
| Constructor order | Superclass construction precedes completion of subclass construction |

---

## Quick exam test

### 7 MCQs

0/7 answered

**1. Which keyword is used for class inheritance in Java?**

- [ ] implements
- [ ] extends ✓
- [ ] inherits
- [ ] super

**2. Which method is executed for `Animal a = new Dog(); a.sound();` if Dog overrides sound()?**

- [ ] Animal.sound()
- [ ] Dog.sound() ✓
- [ ] Both methods
- [ ] Compilation error

**3. Which statement about a final class is correct?**

- [ ] It cannot have methods
- [ ] It cannot be instantiated
- [ ] It cannot be extended ✓
- [ ] It cannot have constructors

**4. Can an abstract class have a constructor?**

- [ ] Yes ✓
- [ ] No
- [ ] Only if it has no abstract methods
- [ ] Only if it is final

**5. Which statement about `super` is correct?**

- [ ] It creates a new superclass object
- [ ] It invokes or accesses superclass functionality ✓
- [ ] It overrides a method
- [ ] It makes a method final

**6. What happens if a concrete subclass does not implement an inherited abstract method?**

- [ ] It compiles normally
- [ ] It must become abstract or compilation fails ✓
- [ ] The method becomes private
- [ ] The superclass method runs automatically

**7. Which form creates a chain of inheritance?**

- [ ] Single
- [ ] Multilevel ✓
- [ ] Multiple class inheritance
- [ ] Only interface implementation

---

## Mind map: quick revision

```
INHERITANCE AND POLYMORPHISM
├── Class inheritance
│   ├── extends keyword
│   ├── Superclass and subclass
│   ├── Advantages
│   │   ├── Reusability
│   │   ├── Extensibility
│   │   ├── Overriding
│   │   ├── Polymorphism
│   │   └── Maintainability
│   └── No multiple class inheritance
├── Member access
│   ├── private not directly accessible
│   ├── protected package plus subclasses
│   ├── public accessible everywhere
│   ├── Constructors not inherited
│   └── Same field name hides superclass field
├── Forms of inheritance
│   ├── By design purpose
│   │   ├── Specialization more specific class
│   │   ├── Specification contract via interface or abstract class
│   │   ├── Construction reuse as building block
│   │   └── Extension adds new behaviour
│   └── By structure
│       ├── Single
│       ├── Multilevel
│       ├── Hierarchical
│       ├── Multiple not for classes
│       └── Hybrid
├── Multilevel inheritance
│   ├── Chain Animal to Mammal to Dog
│   └── Bottom class gets all accessible members
├── Method overriding
│   ├── Same signature in subclass
│   ├── Return type same or covariant
│   ├── Cannot reduce access
│   ├── final method not overridden
│   ├── private method not overridden
│   ├── static method hidden not overridden
│   ├── Constructors not overridden
│   ├── @Override checks at compile time
│   └── Enables runtime polymorphism
├── super keyword
│   ├── super.method calls parent version
│   ├── super.field reaches hidden field
│   ├── super call invokes parent constructor
│   └── Must be first statement
├── final keyword
│   ├── Variable assigned once
│   ├── Method cannot be overridden
│   ├── Class cannot be extended
│   ├── Example String
│   └── Reference final does not make object immutable
├── Abstract method
│   ├── No body
│   ├── Class must be abstract
│   ├── Cannot be private static or final
│   └── Concrete subclass must implement
├── Abstract class
│   ├── Cannot be instantiated
│   ├── Can have constructors
│   ├── Abstract and concrete methods
│   └── Can have fields
└── Polymorphism
    ├── Superclass reference to subclass object
    ├── Upcasting needs no cast
    ├── Method chosen by actual object
    └── Constructor order parent first then child
```

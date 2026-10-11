# UNIT II — Packages and Interfaces

## 1. Packages and Interfaces

### 1.1 Overview of Packages in Java

#### Definition

A package in Java is a collection of related classes, interfaces, enums and subpackages used to organize code, avoid naming conflicts, and control access to classes and members.

Packages provide:

- **Organization:** Group related classes and interfaces together.
- **Namespace management:** Prevent naming conflicts between classes with the same name.
- **Access control:** Package membership affects access to classes and members.
- **Reusability and maintenance:** Makes large applications easier to manage.

For example, two packages can contain classes named Student:

```
college.Student
school.Student
```

Their fully qualified names distinguish them.

#### Types of packages

1. **Predefined packages:** Supplied by the Java API, such as `java.lang`, `java.util` and `java.io`.
2. **User-defined packages:** Created by programmers to organize application code.

A package may also contain subpackages. For example, `java.util.concurrent` is a separate package from `java.util`; importing one does not automatically import the other.

---

### 1.2 Predefined and User-Defined Packages

#### A. Predefined packages

These packages come with the Java platform and provide commonly used functionality.

| Package | Purpose | Examples |
|---|---|---|
| java.lang | Fundamental language classes | String, Math, System, Object |
| java.util | Utilities and collections | Scanner, ArrayList, HashMap |
| java.io | Input/output operations | File, FileReader, BufferedReader |
| java.net | Networking | URL, Socket |
| java.sql | Database access | Connection, ResultSet |
| java.time | Date and time API | LocalDate, LocalTime |

**Important:** `java.lang` is automatically available to Java source code. Other packages generally need to be imported or referenced using fully qualified names.

Example:

```java
import java.util.Scanner;

class Demo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(n);
        sc.close();
    }
}
```

#### B. User-defined packages

Programmers create these packages using the `package` declaration.

Example:

```java
package college;

public class Student {
    public void display() {
        System.out.println("Student details");
    }
}
```

The class belongs to the `college` package.

To use it from another package:

```java
import college.Student;

class Test {
    public static void main(String[] args) {
        Student s = new Student();
        s.display();
    }
}
```

For this example, the compiled `Student.class` must be available on the classpath in the appropriate package directory.

---

### 1.3 Importing Packages

The `import` statement allows a class or interface to be referred to by its simple name instead of its fully qualified name.

#### Types of imports

**1. Single-type import**

Imports one class or interface.

```java
import java.util.Scanner;
```

**2. On-demand type import**

Makes accessible types in a package available by simple name.

```java
import java.util.*;
```

This does not recursively import subpackages and does not import nested types from every class.

**3. Static import**

Allows static members to be used without qualifying them with their declaring class.

```java
import static java.lang.Math.PI;
import static java.lang.Math.sqrt;

class Demo {
    public static void main(String[] args) {
        System.out.println(PI);
        System.out.println(sqrt(25));
    }
}
```

#### Important rules

- The package declaration, if present, must be the first non-comment declaration in a compilation unit.
- Imports follow the package declaration and precede top-level type declarations.
- `java.lang` does not need to be imported explicitly.
- `import java.util.*;` does not import `java.util.concurrent` or resolve every naming conflict automatically.
- Importing a package does not copy its classes into your project or install them.

---

### 1.4 Organizing Classes and Interfaces in Packages

Java conventionally organizes packages using directories that correspond to package names.

Example project structure:

```
Project/
├── college/
│   ├── Student.java
│   └── Teacher.java
└── app/
    └── Main.java
```

`Student.java`:

```java
package college;

public class Student {
    public void show() {
        System.out.println("College student");
    }
}
```

`Main.java`:

```java
package app;

import college.Student;

public class Main {
    public static void main(String[] args) {
        Student s = new Student();
        s.show();
    }
}
```

#### Compilation and execution

From the project directory, a typical command sequence is:

```
javac -d . college/Student.java app/Main.java
java app.Main
```

The `-d .` option tells the compiler to place generated class files under the specified output directory, following package structure. The `java` command uses the fully qualified class name, without `.class`.

**Exam point:** Package names and directory structures conventionally correspond, and the compiler/runtime must be able to locate the required classes.

---

### 1.5 Packages and Member Access

Access modifiers determine where classes, methods, variables and constructors can be accessed.

#### Access modifier table

| Modifier | Same class | Same package | Subclass in another package | Unrelated class in another package |
|---|---|---|---|---|
| private | Yes | No | No | No |
| Default (package-private) | Yes | Yes | No | No |
| protected | Yes | Yes | Yes, subject to subclass access rules | No |
| public | Yes | Yes | Yes | Yes, if the declaring type is accessible |

#### Explanation

**private**

Accessible only within the declaring top-level class and its permitted nestmates. It is not directly accessible to unrelated classes or subclasses.

**Default / package-private**

When no access modifier is specified, the member is accessible within the same package, but not from unrelated code in other packages.

```java
class Student {
    int marks = 90; // package-private
}
```

**protected**

Accessible within the same package and, with additional restrictions, from subclasses in other packages.

For example, a subclass in another package can access an inherited protected instance member through itself or an appropriate subclass-type reference, but cannot freely access that member through an arbitrary superclass object.

**public**

Accessible from other packages when the declaring class or interface is itself accessible.

#### Important distinction

A top-level class can generally be either `public` or package-private. It cannot be declared `private` or `protected`.

---

### 1.6 Defining Package in Java

A package is defined using the `package` keyword.

#### Syntax

```java
package packageName;
```

Example:

```java
package university.department;

public class Faculty {
    public void display() {
        System.out.println("Faculty details");
    }
}
```

The fully qualified class name is:

```
university.department.Faculty
```

#### Rules for defining packages

1. The package declaration appears before imports and type declarations.
2. A source file can have at most one package declaration.
3. If no package is declared, the class belongs to the unnamed package.
4. Package names are conventionally written in lowercase.
5. Directory organization should correspond to the package hierarchy.
6. A public top-level class normally has the same name as its source file.

**Possible exam question:** Explain how to create a user-defined package and access its classes from another package.

For this answer, write the definition, package syntax, a class in the package, an import statement, and the steps needed to compile and run it.

---

### 1.7 Finding Packages and CLASSPATH

#### What is CLASSPATH?

CLASSPATH specifies locations where Java tools can search for user classes and other class files required by a program. Depending on the setup, these locations can include directories and JAR files.

It can be supplied through the `-cp` or `-classpath` command-line option or through the `CLASSPATH` environment variable.

Example:

```
javac -cp . Main.java
java -cp . Main
```

Here, `.` means the current directory.

If compiled classes are in a directory named `out`:

```
java -cp out app.Main
```

#### How does Java find a class?

When a class is referenced, the compiler or runtime must be able to locate its definition using the relevant source path, classpath, module path or class-loading configuration.

For a conventional package structure:

```
out/
  college/
    Student.class
  app/
    Main.class
```

The classpath entry is `out`, not `out/college`. The runtime locates `college.Student` relative to the classpath root.

#### CLASSPATH versus import

| import | CLASSPATH |
|---|---|
| A source-code declaration | A compiler/runtime search-path configuration |
| Lets code use a type's simple name | Identifies locations where classes may be found |
| Does not locate or install missing libraries by itself | Helps locate compiled classes and libraries |
| Example: `import java.util.Scanner;` | Example: `java -cp out app.Main` |

**Remember:** `import` affects how names are resolved in source code; CLASSPATH affects where tools can look for classes.

---

## 2. Interface Mechanics

### 2.1 Defining and Implementing Interfaces

#### Definition

An interface in Java is a reference type that specifies a contract which implementing classes agree to fulfil. It can declare abstract methods and can also contain permitted default, static and private methods.

Interfaces support abstraction and multiple inheritance of type.

#### Defining an interface

```java
interface Printable {
    void print();
}
```

A class implements an interface using the `implements` keyword:

```java
class Report implements Printable {
    public void print() {
        System.out.println("Printing report");
    }
}
```

Using the interface:

```java
class Main {
    public static void main(String[] args) {
        Printable p = new Report();
        p.print();
    }
}
```

Output:

```
Printing report
```

#### Important rules

- A class uses `implements` to implement an interface.
- An implementing class must provide implementations for inherited abstract methods, unless the class itself is abstract.
- Implemented interface methods must be declared `public`, because interface abstract methods are public.
- An interface cannot be instantiated directly.
- A class can implement more than one interface.
- A class can extend only one direct superclass, but can implement multiple interfaces.

#### Interface versus abstract class

| Interface | Abstract class |
|---|---|
| Declared using `interface` | Declared using `abstract class` |
| Implemented using `implements` | Inherited using `extends` |
| A class can implement multiple interfaces | A class can extend only one class |
| Fields are implicitly `public static final` | Can have instance and static fields |
| No constructors | Can have constructors |
| Can have abstract, default, static and private methods | Can have abstract and concrete methods |

Modern Java interfaces can also declare private methods, but these are implementation helpers, not methods that implementing classes inherit as public interface operations.

---

### 2.2 Nested Interfaces

A nested interface is an interface declared inside another class or interface.

It helps group a related contract with the type to which it belongs.

Example:

```java
class University {
    interface Exam {
        void conduct();
    }
}

class Department implements University.Exam {
    public void conduct() {
        System.out.println("Exam conducted");
    }
}
```

Usage:

```java
class Main {
    public static void main(String[] args) {
        University.Exam e = new Department();
        e.conduct();
    }
}
```

Output:

```
Exam conducted
```

#### Key points

- A nested interface is referred to using its enclosing type, such as `University.Exam`.
- An interface declared inside another interface is implicitly `public static`.
- A member interface inside a class can have access modifiers, subject to the rules for member types.
- A nested interface defines a separate type; it does not automatically create an object of the enclosing class.

---

### 2.3 Variables and Methods in Interface

This is an important theory and syntax topic.

#### A. Variables in an interface

Every field declared in an interface is implicitly:

```
public static final
```

Example:

```java
interface Constants {
    int MAX = 100;
}
```

This is equivalent to:

```java
interface Constants {
    public static final int MAX = 100;
}
```

Consequences:

- The field belongs to the interface, not to individual implementing objects.
- It must be initialized.
- Its value cannot be reassigned after initialization.

#### B. Methods in an interface

Java interfaces can contain several method forms.

| Method type | Purpose |
|---|---|
| Abstract method | Specifies a method an implementing class must implement, unless the class is abstract |
| Default method | Provides an inherited instance-method implementation |
| Static method | Belongs to the interface itself |
| Private method | Supports code reuse inside the interface |

Example:

```java
interface Vehicle {
    void start();

    default void stop() {
        System.out.println("Vehicle stopped");
    }

    static void info() {
        System.out.println("Vehicle interface");
    }

    private void helper() {
        System.out.println("Internal helper");
    }
}
```

In this example:

- `start()` is implicitly `public abstract`.
- `stop()` is a public default method.
- `info()` is a public static method.
- `helper()` is private and can be called only from permitted code within the interface, such as its own default or static methods.

A class implementing `Vehicle` must implement `start()` or remain abstract. It can use the inherited `stop()` implementation.

**Exam note:** Fields are implicitly `public static final`; ordinary abstract interface methods are implicitly `public abstract`. Do not apply the abstract-method rule to default, static or private methods.

---

### 2.4 Multiple Inheritance Using Interface

#### Concept

Java does not permit a class to extend multiple classes directly. However, it permits a class to implement multiple interfaces, allowing it to satisfy several contracts.

Example:

```java
interface Camera {
    void click();
}

interface MusicPlayer {
    void play();
}

class Phone implements Camera, MusicPlayer {
    public void click() {
        System.out.println("Photo clicked");
    }

    public void play() {
        System.out.println("Music playing");
    }
}
```

Here, `Phone` implements both `Camera` and `MusicPlayer`.

#### Why is this useful?

- Allows a class to provide multiple capabilities.
- Encourages loose coupling and abstraction.
- Avoids the restriction of inheriting implementation from multiple classes.
- Allows code to interact with objects through interface references.

#### What if interfaces have the same default method?

If two unrelated interfaces provide conflicting default implementations of the same method, the implementing class generally must resolve the conflict by overriding the method.

```java
interface A {
    default void show() {
        System.out.println("A");
    }
}

interface B {
    default void show() {
        System.out.println("B");
    }
}

class C implements A, B {
    public void show() {
        System.out.println("C");
    }
}
```

Output from `new C().show()`:

```
C
```

This conflict-resolution rule is worth remembering for conceptual questions.

---

### 2.5 Private Interface Methods

Private interface methods were introduced in Java 9.

They allow common code to be shared by default and static methods inside the same interface, avoiding duplication.

Example:

```java
interface Greeting {
    default void sayHello() {
        message();
    }

    default void sayWelcome() {
        message();
    }

    private void message() {
        System.out.println("Welcome!");
    }
}
```

Both `sayHello()` and `sayWelcome()` can use `message()` internally.

#### Key points

- Declared using the `private` keyword.
- Can have a method body.
- Cannot be accessed directly by implementing classes.
- Cannot be overridden as an inherited interface method.
- May be instance methods or static methods, depending on their declaration.
- Must be used within the interface under the applicable access rules.

**Why were they introduced?** To avoid duplicating implementation code shared by multiple default or static methods.

---

## Exam revision: what to learn first

Given your four-hour preparation window, prioritize the following:

1. Access modifiers and CLASSPATH vs import: frequently tested distinctions.
2. Interface declaration and implementation: write a complete example.
3. Interface fields and method types: memorize their implicit modifiers.
4. Multiple inheritance through interfaces: explain with a two-interface example.
5. Interface vs abstract class: prepare a comparison table.
6. Packages: define, create, import, compile and use a user-defined package.
7. Nested interfaces and private interface methods: understand the syntax and purpose.

---

## Quick self-test

**1. Which modifier combination is implicit for an interface field?**

- [ ] private static final
- [ ] public static final ✓
- [ ] public final
- [ ] protected static

**2. Which statement about importing packages is correct?**

- [ ] It downloads the package
- [ ] It imports all subpackages recursively
- [ ] It lets source code refer to accessible types by simple name ✓
- [ ] It changes the classpath

**3. How can a Java class support multiple interface contracts?**

- [ ] Using multiple extends clauses for classes
- [ ] Using multiple implements interfaces ✓
- [ ] Using multiple constructors
- [ ] Using multiple package declarations

**4. Which is true of a private interface method?**

- [ ] Implementing classes must override it
- [ ] It is accessible from any implementing object
- [ ] It can support code reuse within the interface ✓
- [ ] It must be abstract

**5. What does `java -cp out app.Main` specify?**

- [ ] The package declaration
- [ ] The classpath root and fully qualified main class ✓
- [ ] A source file to compile
- [ ] An import statement

**6. Which top-level class declaration is permitted?**

- [ ] private class A {}
- [ ] protected class A {}
- [ ] public class A {} ✓
- [ ] Both private and protected

---

## Mind map: quick revision

```
PACKAGES AND INTERFACES
├── Packages
│   ├── Purpose
│   │   ├── Organization
│   │   ├── Namespace management
│   │   ├── Access control
│   │   └── Reusability
│   ├── Types
│   │   ├── Predefined
│   │   │   ├── java.lang auto available
│   │   │   ├── java.util
│   │   │   ├── java.io
│   │   │   ├── java.net
│   │   │   ├── java.sql
│   │   │   └── java.time
│   │   └── User defined
│   │       └── package keyword
│   └── Subpackages are separate
│       └── java.util.concurrent not imported by java.util star
├── Importing
│   ├── Single type import
│   ├── On demand star import
│   ├── Static import
│   └── Rules
│       ├── package first then imports then types
│       ├── java.lang needs no import
│       └── Import does not install anything
├── Organizing and defining
│   ├── Directories match package names
│   ├── javac -d dot compiles into structure
│   ├── java app.Main uses full name
│   ├── One package statement per file
│   ├── No package means unnamed package
│   ├── Lowercase names by convention
│   └── Public class matches file name
├── Member access
│   ├── private same class
│   ├── Default same package
│   ├── protected package plus subclasses
│   ├── public everywhere accessible
│   └── Top level only public or default
├── CLASSPATH
│   ├── Where tools search for classes
│   ├── -cp option or CLASSPATH variable
│   ├── Entry is root folder not package folder
│   └── Import vs CLASSPATH
│       ├── Import is source code names
│       └── CLASSPATH is search location
└── Interfaces
    ├── Defining and implementing
    │   ├── Contract
    │   ├── implements keyword
    │   ├── Methods must be public
    │   ├── Cannot instantiate
    │   └── Class implements many interfaces
    ├── Interface vs abstract class
    │   ├── implements vs extends
    │   ├── Many vs one
    │   ├── Fields public static final
    │   └── No constructors
    ├── Nested interfaces
    │   ├── Declared inside class or interface
    │   ├── Referred as Outer.Inner
    │   └── Inside interface is public static
    ├── Variables
    │   ├── public static final implicitly
    │   └── Must be initialized
    ├── Methods
    │   ├── Abstract
    │   ├── Default
    │   ├── Static
    │   └── Private
    ├── Multiple inheritance
    │   ├── Implement several interfaces
    │   ├── Same default method conflict
    │   └── Class must override to resolve
    └── Private interface methods
        ├── Java 9
        ├── Share code between default and static methods
        └── Not visible to implementing classes
```

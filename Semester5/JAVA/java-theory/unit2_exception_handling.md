# UNIT II — Exception Handling

## 1. Fundamentals of Exception Handling

### What is an exception?

An exception is an abnormal event that occurs during program execution and disrupts the normal flow of instructions.

Examples:

- Dividing an integer by zero.
- Accessing an array index that does not exist.
- Trying to use a method on a null reference.
- Opening a file that does not exist.

Exception handling is the mechanism used to detect and handle such events so that the program can respond appropriately instead of terminating unexpectedly.

### Why do we need it?

Suppose a program divides two numbers:

```java
int a = 10, b = 0;
System.out.println(a / b);
System.out.println("Program continues");
```

This throws an `ArithmeticException`. The second statement is not executed because the exception is unhandled.

With exception handling:

```java
int a = 10, b = 0;

try {
    System.out.println(a / b);
} catch (ArithmeticException e) {
    System.out.println("Cannot divide by zero");
}

System.out.println("Program continues");
```

Output:

```
Cannot divide by zero
Program continues
```

The exception is caught, handled, and normal execution continues after the catch block.

**Exam definition:** Exception handling is a mechanism for detecting and handling runtime abnormalities using constructs such as `try`, `catch`, `throw`, `throws`, and `finally`.

---

## 2. Exception hierarchy and types

Java represents exceptions and errors using classes. The root of this hierarchy is `Throwable`.

```
Object
└── Throwable
    ├── Error
    │   ├── Serious JVM/system problems
    │   └── OutOfMemoryError
    └── Exception
        ├── Conditions applications may handle
        └── RuntimeException
            └── Unchecked exceptions
```

More precisely, `RuntimeException` is a subclass of `Exception`. Other subclasses of `Exception`, such as `IOException`, are generally checked exceptions.

### A. Checked exceptions

These are checked by the compiler. A method must generally handle them using try-catch or declare them using `throws`.

Examples:

- IOException
- FileNotFoundException
- SQLException
- ClassNotFoundException

### B. Unchecked exceptions

These are not subject to the compiler's catch-or-declare requirement. They include `RuntimeException` and its subclasses.

Examples:

- ArithmeticException
- NullPointerException
- ArrayIndexOutOfBoundsException
- NumberFormatException

### C. Errors

These generally represent serious problems that applications are not expected to handle routinely.

Examples:

- OutOfMemoryError
- StackOverflowError

**Important distinction:** Errors and unchecked exceptions are different categories, even though neither is subject to the checked-exception requirement.

| Checked exception | Unchecked exception |
|---|---|
| Checked at compile time | Not required to be caught or declared |
| Must generally be caught or declared | Catching or declaring is optional |
| Example: IOException | Example: NullPointerException |

---

## 3. try, catch and finally

### try block

Contains code that may throw an exception.

### catch block

Handles a matching exception thrown from the associated `try` block.

### finally block

Contains cleanup code that normally executes whether an exception occurs or not, provided control leaves the try/catch structure normally. It is not guaranteed to run if the JVM terminates abruptly.

General syntax:

```java
try {
    // Code that may throw an exception
} catch (ExceptionType e) {
    // Exception-handling code
} finally {
    // Cleanup code
}
```

Example:

```java
try {
    int x = 10 / 0;
} catch (ArithmeticException e) {
    System.out.println("Exception caught");
} finally {
    System.out.println("Finally executed");
}
```

Output:

```
Exception caught
Finally executed
```

### Multiple catch clauses

A single `try` block can have multiple `catch` blocks to handle different exception types.

```java
try {
    int[] a = {10, 20};
    System.out.println(a[5]);
} catch (ArithmeticException e) {
    System.out.println("Arithmetic error");
} catch (ArrayIndexOutOfBoundsException e) {
    System.out.println("Invalid index");
} catch (Exception e) {
    System.out.println("Other exception");
}
```

Output:

```
Invalid index
```

**Rule:** Place more specific exception types before more general types. If `catch (Exception e)` came before `catch (ArrayIndexOutOfBoundsException e)`, the latter would be unreachable and the code would fail to compile.

### Nested try statements

A `try` block inside another `try` block is called a nested try.

```java
try {
    try {
        int x = 10 / 0;
    } catch (ArithmeticException e) {
        System.out.println("Inner catch");
    }

    System.out.println("Outer try continues");
} catch (Exception e) {
    System.out.println("Outer catch");
}
```

Output:

```
Inner catch
Outer try continues
```

The inner catch handles the exception, so it does not propagate to the outer catch.

If the inner block did not handle the exception, the exception could propagate outward to a suitable enclosing handler.

---

## 4. throw versus throws

This is a common exam question.

| throw | throws |
|---|---|
| Used to explicitly throw an exception object | Used to declare exceptions a method may propagate |
| Appears in the method body | Appears in the method declaration |
| Followed by an exception object | Followed by exception class names |
| Throws one exception object per statement | Can declare multiple exception types |

Example of `throw`:

```java
int age = 15;

if (age < 18) {
    throw new IllegalArgumentException("Underage");
}
```

Example of `throws`:

```java
import java.io.*;

static void readFile() throws IOException {
    FileReader f = new FileReader("data.txt");
}
```

Here, `readFile()` declares that an `IOException` may propagate to its caller.

**C++ connection:** Both languages support throwing exceptions and handling them. Java additionally uses `throws` in method declarations to document and enforce checked-exception handling.

---

## 5. Built-in exceptions

Learn these examples and their causes:

| Exception | Cause |
|---|---|
| ArithmeticException | Integer division by zero |
| NullPointerException | Calling a method or accessing a member through null |
| ArrayIndexOutOfBoundsException | Invalid array index |
| NumberFormatException | Invalid String-to-number conversion |
| ClassCastException | Invalid runtime reference cast |
| IllegalArgumentException | Method receives an illegal argument |
| IOException | Input/output operation failure |
| FileNotFoundException | Requested file cannot be opened |
| ClassNotFoundException | Required class cannot be found during certain class-loading operations |

Remember that integer division by zero throws `ArithmeticException`; floating-point division by zero behaves differently and may produce infinity or NaN.

---

## 6. Creating your own exception class

A user-defined exception allows you to represent application-specific errors.

For a checked exception, extend `Exception`:

```java
class InvalidAgeException extends Exception {
    InvalidAgeException(String message) {
        super(message);
    }
}
```

Use it as follows:

```java
class Test {
    static void checkAge(int age) throws InvalidAgeException {
        if (age < 18) {
            throw new InvalidAgeException("Age must be 18 or above");
        }
    }

    public static void main(String[] args) {
        try {
            checkAge(16);
        } catch (InvalidAgeException e) {
            System.out.println(e.getMessage());
        }
    }
}
```

Output:

```
Age must be 18 or above
```

Know the three parts:

1. Extend `Exception` to create a checked exception.
2. Use `throw` to create and throw an instance.
3. Use `throws` or a suitable try-catch to satisfy checked-exception handling requirements.

If you extend `RuntimeException` instead, the custom exception is unchecked.

---

## 7. Chained exceptions

A chained exception is an exception associated with another exception, preserving the original cause of a failure.

For example, a low-level database exception may be wrapped in a higher-level application exception.

```java
try {
    throw new ArithmeticException("Original cause");
} catch (ArithmeticException e) {
    throw new RuntimeException("Operation failed", e);
}
```

Here:

- The original exception is the cause.
- The new `RuntimeException` provides a higher-level description.
- `e` is passed to the constructor to preserve the original cause.

Useful methods include `getCause()` and `initCause()`.

---

## 8. Uncaught exceptions

An uncaught exception is an exception for which no matching handler is found as it propagates through the call stack.

Java's default exception handler typically prints the exception type, message and stack trace, then terminates the affected thread. If this is the main thread and no other non-daemon threads keep the application running, the program will terminate.

Example:

```java
public static void main(String[] args) {
    int x = 10 / 0;
    System.out.println("Hello");
}
```

The `ArithmeticException` is uncaught, so "Hello" is never printed.

---

## Test yourself

Answer these without looking back. These are the kinds of distinctions and output-tracing questions worth practising before the exam.

### 8-question quiz

0/8 answered

**1. Which is the root class of Java's exception hierarchy?**

- [ ] Exception
- [ ] Throwable ✓
- [ ] RuntimeException
- [ ] Error

**2. Which is a checked exception?**

- [ ] NullPointerException
- [ ] ArithmeticException
- [ ] IOException ✓
- [ ] ArrayIndexOutOfBoundsException

**3. What is the purpose of `throw`?**

- [ ] Declare possible exceptions
- [ ] Handle exceptions
- [ ] Explicitly throw an exception object ✓
- [ ] Always execute cleanup code

**4. What happens if a superclass catch appears before its subclass catch?**

- [ ] Both execute
- [ ] Subclass catch is unreachable; compilation fails ✓
- [ ] Superclass catch is skipped
- [ ] It becomes a nested try

**5. When does `finally` normally execute?**

- [ ] Only if an exception occurs
- [ ] Only if no exception occurs
- [ ] During normal or exceptional exit from try/catch ✓
- [ ] Only when catch handles an exception

**6. Which declaration creates a checked custom exception?**

- [ ] class MyEx extends Error
- [ ] class MyEx extends Exception ✓
- [ ] class MyEx extends Object
- [ ] class MyEx extends String

**7. What does `throws IOException` do?**

- [ ] Immediately throws an IOException
- [ ] Declares that the method may propagate IOException ✓
- [ ] Catches IOException
- [ ] Creates a new IOException

**8. What is exception chaining?**

- [ ] Catching every exception in one block
- [ ] Calling multiple catch blocks in sequence
- [ ] Preserving one exception as the cause of another ✓
- [ ] Throwing the same exception repeatedly

---

## Mind map: quick revision

```
EXCEPTION HANDLING
├── Fundamentals
│   ├── Exception is abnormal runtime event
│   ├── Handling avoids sudden termination
│   └── Keywords try catch throw throws finally
├── Hierarchy
│   ├── Throwable is root
│   ├── Error
│   │   ├── OutOfMemoryError
│   │   ├── StackOverflowError
│   │   └── Not handled routinely
│   └── Exception
│       ├── Checked
│       │   ├── IOException
│       │   ├── FileNotFoundException
│       │   ├── SQLException
│       │   ├── ClassNotFoundException
│       │   └── Catch or declare
│       └── RuntimeException unchecked
│           ├── ArithmeticException
│           ├── NullPointerException
│           ├── ArrayIndexOutOfBoundsException
│           └── NumberFormatException
├── try catch finally
│   ├── try holds risky code
│   ├── catch handles matching exception
│   ├── finally cleanup
│   │   ├── Runs on normal or exceptional exit
│   │   └── Not guaranteed if JVM terminates
│   ├── Multiple catch
│   │   ├── Specific before general
│   │   └── General first gives compile error
│   └── Nested try
│       ├── Inner handles first
│       └── Unhandled propagates outward
├── throw vs throws
│   ├── throw
│   │   ├── In method body
│   │   └── Throws one exception object
│   └── throws
│       ├── In method declaration
│       └── Lists exception classes
├── Built-in exceptions
│   ├── ArithmeticException integer divide by zero
│   ├── NullPointerException member access via null
│   ├── ArrayIndexOutOfBoundsException bad index
│   ├── NumberFormatException bad string to number
│   ├── ClassCastException bad cast
│   ├── IllegalArgumentException illegal argument
│   ├── IOException I O failure
│   ├── FileNotFoundException file cannot be opened
│   └── ClassNotFoundException class not found
├── User defined exceptions
│   ├── extends Exception for checked
│   ├── extends RuntimeException for unchecked
│   ├── Constructor calls super with message
│   └── Use throw plus throws or try catch
├── Chained exceptions
│   ├── Wrap original as cause
│   ├── Pass cause to constructor
│   ├── getCause
│   └── initCause
└── Uncaught exceptions
    ├── No handler found
    ├── Default handler prints stack trace
    ├── Thread terminates
    └── Rest of code never runs
```

# 23 Design Patterns (Gang of Four - GoF) in C++

## Creational Patterns (Object Creation Mechanisms)

### 1- Singleton
- Ensures that a class has only one instance and provides a global access point to it.
- Use Case: Used for database connection pools, logging mechanisms, or thread pools 
  to ensure controlled access to a single resource.

### 2 - Factory Method.
- Provides an interface for creating objects but lets subclasses alter the type of objects that will be created.
- Use Case: Used in logging frameworks to create different types of loggers
 (file, console, database) without modifying the core logic.

3 - Abstract Factory.

4- Builder

5- Prototype



## Structural Patterns (Class & Object Composition)

1- Adapter

2- Bridge

3- Composite

### 4- Decorator
- Dynamically adds responsibilities to an object without modifying its structure.
- Use Case: Used in GUI frameworks to add scrolling, borders, etc., to a window dynamically.

5- Facade

6- Flyweight

7- Proxy

## Behavioral Patterns (Object Communication & Responsibilities)

1- Chain of Responsibility

2- Command

3- Interpreter

4- Iterator

5- Mediator

6- Memento

### 7- Observer
- Defines a dependency between objects so that when one object changes state, all its dependents are notified.
- Use Case: Used in event-driven systems like GUI components where a button click notifies multiple listeners.

8- State

9- Strategy

10- Template Method

11- Visitor

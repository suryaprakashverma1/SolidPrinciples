# SolidPrinciples




🚀 Concept: Open-Closed Principle (OCP)
Definition:

Software entities (classes, modules, functions, etc.) should be open for extension, but closed for modification.

In simpler terms:

You should be able to add new behavior without changing existing code.

Achieve this by using abstraction + polymorphism.

🧠 What is Liskov Substitution Principle (LSP)?
Definition:

If class B is a subclass of class A, then A’s objects should be replaceable with B’s objects without altering the correctness of the program.

In short:

A derived class must be usable wherever its base class is expected — without breaking the system’s behavior.

🎯 What is ISP?
Clients should not be forced to depend on interfaces they do not use.
Don't impliment fatty interfaces to force every one to impliment all even if they don't need, other wise it will also break Liskov substitution as well if unnecessary functions are implimented to throw errors.

In C++ terms:
Avoid designing fat interfaces — break them into smaller, more specific ones so that classes only implement what they need.

# Interface Inheritance

## Goals:
- Use copilot to assist you in writing an interface and coding classes that implement an interface.

---

# Inheritance

## Steps:
1. Code a class to represent an `Employee`. Make the employee class abstract since it models an abstract concept that should never be instantiated. Add two public fields: a `string` for the name and a `double` for the salary. Add a protected constructor that sets the name and salary. Making the constructor protected does not really change the behavior of the class since it is already abstract (and thus cannot be instantiated). However, an abstract class with a public constructor seems odd - external clients can never use the constructor since the class is abstract. Making the constructor protected emphasizes the fact that clients cannot instantiate the class. Add a public virtual `Print` method that prints the name and salary of the employee to the console.
2. Derive a `Programmer` class from `Employee`. Add a private `double` field to store the average overtime worked by the programmer. Provide a public constructor that sets the name, salary, and overtime of the programmer. Call the `Employee` constructor to set the name and salary rather than assigning to the protected fields directly. Override the virtual print method to chain to the base class version first and then print out the derived class fields.
3. Derive a `Manager` class from `Employee`. Add a private `string` field to store the name of the manager's assistant. Provide a public constructor that sets the name, salary, and assistant of the manager. Call the `Employee` constructor to set the name and salary rather than assigning to the protected fields directly. Override the virtual print method to chain to the base class version first and then print out the derived class fields.
4. Derive an `Intern` class from `Employee`. Add a private `int` field to store the number of months of the internship. Provide a public constructor that sets the name, salary, and internship length. Call the `Employee` constructor to set the name and salary rather than assigning to the protected fields directly. Override the virtual print method to chain to the base class version first and then print out the derived class fields.
5. Instantiate a `Programmer` object and a `Manager` object. Call the `Print` method on each object to verify that the correct version of the method is called.

---

# Interface

We would like to promote our employees by coding a `Promote` method. However, not all employees are eligible for promotion: programmers and managers get promoted, but interns are temporary employees and are not eligible. Because not all our classes should support the promote operation, it would be incorrect to add the method to the employee class. Instead, we define a separate interface `IPromotable` for the method. Programmer and manager implement the interface while intern does not. Once we have the interface implemented, we then write some generic code to work with a group of employees and promote only those that are eligible.

## Steps:
1. Code an interface named `IPromotable` containing a `Promote` method. `Promote` should take no arguments and return `void`.
2. Implement the `IPromotable` interface in both the programmer and manager classes. Programmers get a 10% raise when promoted and Managers a 50% raise.
3. Create a driver class `Program` containing a `Main` method. Make an array of `Employee` references and fill the array with a mix of programmers, managers, and interns. Loop through the array and call `Promote` on those objects that implement the `IPromotable` interface. Recall that you can use the `is` operator to test if an object implements a particular interface. Note that you will not be able to call `Promote` through an `Employee` reference so casting will be required. You may want to use the print method to display the contents of the array before and after the promotions.

## Solution:
[Interfaces.cs](../../../../work/InterfaceInheritance/After/Interfaces.cs)
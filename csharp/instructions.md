# Interface Inheritance

## Goals:
- Use copilot to assist you in writing an interface and coding classes that implement an interface.
- Explore the use of Copilot to write unit tests for your code.
- Use XML documentation comments to document your code.

## Part 1: Modeling Employees

### Step 1:
1. Code a class to represent an `Employee`. 
1a. Make the employee class abstract since it models an abstract concept that should never be instantiated. 
1b. Add two public fields: a `string` for the name and a `double` for the salary.
1c. Add a protected constructor that sets the name and salary. 
1d. Add a public virtual `Print` method that prints the name and salary of the employee to the console.
### Step 2:
2. Derive a `Programmer` class from `Employee`.
2a. Add a private `double` field to store the average overtime worked by the programmer.
2b. Provide a public constructor that sets the name, salary, and overtime of the programmer.
2c. Call the `Employee` constructor to set the name and salary rather than assigning to the protected fields directly. 
2d. Override the virtual print method to chain to the base class version first and then print out the derived class fields.
### Step 3:
3. Derive a `Manager` class from `Employee`. 
3a. Add a private `string` field to store the name of the manager's assistant.
3b. Provide a public constructor that sets the name, salary, and assistant of the manager. Call the `Employee` constructor to set the name and salary rather than assigning to the protected fields directly. 
3c. Override the virtual print method to chain to the base class version first and then print out the derived class fields.
### Step 4:
4. Derive an `Intern` class from `Employee`.
4a. Add a private `int` field to store the number of months of the internship.
4b. Provide a public constructor that sets the name, salary, and internship length.
4c. Call the `Employee` constructor to set the name and salary rather than assigning to the protected fields directly. 
4d. Override the virtual print method to chain to the base class version first and then print out the derived class fields.
### Step 5:
5	Create a driver class `Program` containing a `Main` method.
5a. Instantiate a `Programmer` object and a `Manager` object. 
5b. Call the `Print` method on each object to verify that the correct version of the method is called.

## Part 2: Modeling Type Specific Behavior

We would like to promote our employees by coding a `Promote` method. However, not all employees are eligible for promotion: programmers and managers get promoted, but interns are temporary employees and are not eligible. Because not all our classes should support the promote operation, it would be incorrect to add the method to the employee class. 

Define a separate interface `IPromotable` for the method. Programmer and Manager implement the interface while Intern does not. Once you have the interface implemented, write some generic code to work with a group of employees and promote only those that are eligible.

## Part 3: Unit Testing the Model

Create a unit test project and write tests to verify that the `Print` and `Promote` methods work as expected. 

## Part 4: Documentation

Add XML documentation comments to the classes and methods in the model. Use the `cref` attribute to link to other classes and methods in the documentation. 





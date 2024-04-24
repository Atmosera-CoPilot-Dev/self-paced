# C# exercise

## Goals:
- Use copilot and copilot chat to assist you in writing an interface and classes that implement an interface.
- Explore the use of Copilot to write unit tests for your code.
- Use docstring comments to document your code.

## Part 1: Modeling Employees

### Step 1:
- Code a class to represent an `Employee`. 
- Make the employee class abstract since it models an abstract concept that should never be instantiated. 
- Add two public fields: a `string` for the name and a `double` for the salary.
- Add a protected constructor that sets the name and salary. 
- Add a public virtual `Print` method that prints the name and salary of the employee to the console.
### Step 2:
- Derive a `Programmer` class from `Employee`.
- Add a private `double` field to store the average overtime worked by the programmer.
- Provide a public constructor that sets the name, salary, and overtime of the programmer.
- Call the `Employee` constructor to set the name and salary rather than assigning to the protected fields directly. 
- Override the virtual print method to chain to the base class version first and then print out the derived class fields.
### Step 3:
- Derive a `Manager` class from `Employee`. 
- Add a private `string` field to store the name of the manager's assistant.
- Provide a public constructor that sets the name, salary, and assistant of the manager. Call the `Employee` constructor to set the name and salary rather than assigning to the protected fields directly. 
- Override the virtual print method to chain to the base class version first and then print out the derived class fields.
### Step 4:
- Derive an `Intern` class from `Employee`.
- Add a private `int` field to store the number of months of the internship.
- Provide a public constructor that sets the name, salary, and internship length.
- Call the `Employee` constructor to set the name and salary rather than assigning to the protected fields directly. 
- Override the virtual print method to chain to the base class version first and then print out the derived class fields.
### Step 5:
- Create a driver class `Program` containing a `Main` method.
- Instantiate a `Programmer` object and a `Manager` object. 
- Call the `Print` method on each object to verify that the correct version of the method is called.

## Part 2: Modeling Type Specific Behavior

We would like to promote our employees by coding a `Promote` method. However, not all employees are eligible for promotion: programmers and managers get promoted, but interns are temporary employees and are not eligible. Because not all our classes should support the promote operation, it would be incorrect to add the method to the employee class. 

Define a separate interface `IPromotable` for the method. Programmer and Manager implement the interface while Intern does not. Once you have the interface implemented, write some generic code to work with a group of employees and promote only those that are eligible.

## Part 3: Unit Testing the Model

Create a unit test project and write tests to verify that the `Print` and `Promote` methods work as expected. 

## Part 4: Documentation

Add XML documentation comments to the classes and methods in the model. Use the `cref` attribute to link to other classes and methods in the documentation. 





# Functional JavaScript

This workshop consists of 2 parts. Each exercise will reinforce your
ability to use copilot to assist in solving problems.

## Part 1

Open the starter.html file in an editor. In the scripts section are two
methods that require attention:

        var mappedNames = names.map(function (){
            //   return a string in the form 'last, first'
        });
        
        mappedNames.forEach(function (){
            // use console.log to print each name in its new form
        });

It is your assignment to implement the correct solution.

The output should look like ths: \[\'Jones, Jim\', \'Fen, Li\', \'Ti,
May\', \'Thomas, J.T\'\]

Tip: Using your favorite search engine, search \"mdn Array\". This will
help you quickly find the Array object documentation on the Mozilla
website. Look for Array.prototype.map() and Array.prototype.forEach(),
be sure to check for the structure of the callback function.

## Part 2

In this part you will be using functional style iteration with reduce, map, and filter:

1) calculate the total salary using the reduce method of Array. Save the result in a variable totalSalary
    
2) Next calculate the average salary. Save the result in a variable averageSalary.
        
3) Use the Array filter function to return an array of all employees whose salary is greater than the calculated average stored in the variable averageSalary.

4) Find the employee whose id is 1.

5) Use map and JSON.stringify() to return an array of objects ready for
    output.

6) Use a forEach iteration to display the results of #2 to the console.

7) Implement a solution to display to the console the name and salary
    of each employee whose salary is greater than 70000, sorted in
    descending order of salary.

8) Here\'s a tricky one: implement a way to answer the question \'Are
    there any employees whose salary is greater than 70000?\'.

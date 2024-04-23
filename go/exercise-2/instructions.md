# Refactoring

You are given a MySQL script 'recordings.sql' and an application 'main.go' that uses the database defined in the script.

Rewrite the application to use a database abstraction layer so that it can be easily modified to use a different database in the future.

## Steps:

1) Modify go.mod if necessary, then run tidy.

2) Refactor the code in main.go by creating a new package, for example 'dblayer', and move the database-specific code into it. You will also need to modify 'main.go' to use the package.

3) Add unit testing with a mocking library of your choice.

4) Add a README.md file with instructions on how to run the application and the tests.

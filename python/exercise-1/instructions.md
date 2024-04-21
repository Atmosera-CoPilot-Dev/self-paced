# Python exercise 1

- This exercise will let you practice using Copilot with Python. 
- You will work with JSON, text, and CSV files to answer basic questions about the data contained within. 
- While doing this, you will be logging the results to a text file.
- These instructions assume you have Python 3 installed. You can use any OS you choose (OS X, Windows,or Linux).

## Part 1 Add file logging

1) Open the program.py and logger.py files (or project if you are using PyCharm) Before/file_io_before. Notice that the program.py file depends upon the logger.py file. 

2) Run program.py and observe that it outputs a message warning that logging must be implemented.

3) Open the logger.py file and check out the TODOs. Add code to implement each of these and remove the warning(s). Note each message should add to the log file, not overwrite it.


## Part 2 Working with JSON

Turn your attention to the load_json method of the Program.py file. Follow the detailed TODOs in the code. You will be loading a file named python‐course.json. 

Use the fact that a dictionary is returned from the json module to answer the questions:

- What is the Name of the course?
- How many Engagements (session of the course) exist in the datastore?
- What is the City and StartDate of each?


## Part 3 Working with CSV

Finally, turn your attention to the load_csv method of the Program.py file.  You will be loading a file named fx‐seven‐day.csv. This is the currency exchange rates for a 7 day period. Note that these values are relative to Canadian dollars. Your job will be to answer the question:

- What is the 7 day average for RUPEEs to USD?

Here is rough sketch of the steps needed to answer this:

1. Parse the CSV into a data structure you can leverage. A dictionary of `key = three‐letter‐code`, `value = dictionary of row values` is a good choice.

2. Find the average of the 7‐day rate for Rupees to Canadian dollars.

3. Find the average of the 7‐day rate for USD to Canadian dollars.

4. Compute Rupees / USD by dividing the two values above.

## Part 4 Unit Testing

Use Copilot to assist you in creating a unit test. 

## Part 5 Documentation

Use Copilot to assist you in documenting the code.

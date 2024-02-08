#!/usr/local/bin/python3
import os

from logger import Logger


class Program:
    def __init__(self):
        this_folder = os.path.dirname(__file__)
        data_folder = os.path.join(this_folder, os.pardir, os.pardir, "data")
        self.data_folder = os.path.abspath(data_folder)
        self.logger = Logger(os.path.join(self.data_folder, "log.txt"))

    def run(self):
        try:
            self.log_startup()
            self.load_json()
            self.load_csv()
        except Exception as e:
            print(e.__repr__())

    def log_startup(self):
        self.logger.log("Application starting up...")
        self.logger.log("Data folder: {0}".format(self.data_folder))


    def load_json(self):
        self.logger.log("******* LOAD_JSON NOT FINISHED ******* ")
        filename = os.path.join(self.data_folder, "python-course.json")
        # TODO: log which json file is being opened

        # TODO: open a file as a standard text file
        # TODO: read the contents into a string
        # TODO: load the string with json module
        # TODO: locate the course Name property, show and log it.
        # TODO: find the course engagements via the Engagements property, print the City of each


    def load_csv(self):
        filename = os.path.join(self.data_folder, "fx-seven-day.csv")
        self.logger.log("******* LOAD_CSV NOT FINISHED ******* ")
        # TODO: log which csv file is being opened

        # TODO: Answer what is the 7 day average for RUPEEs to USD?
        # (need to go from rupees -> canadian dollars -> usd)
        # hint: build a lookup of each row by ID (e.g. CZK),
        #       store the seven day values as a list of floats.

        rupee_per_usd = 0.0

        # TODO: show and log the answer 1 USD is worth X Rupees
        # note: this value should be around 60.
        # we have provided an average method below for you to use
        

    @staticmethod
    def average(numbers):
        if len(numbers) <= 0:
            return float('nan')

        return sum(numbers) / float(len(numbers))


if __name__ == "__main__":
    p = Program()
    p.run()


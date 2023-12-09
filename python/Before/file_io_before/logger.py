import platform
import datetime


class Logger:
    def __init__(self, logfile):
        self.logfile = logfile

        # TODO: Verify directory exists (note file not needed)
        # TODO: Verify logfile is not itself a directory

    def log(self, msg):
        machine = platform.node()
        now = datetime.datetime.now()
        date = "{0}_{1}_{2} {3}:{4}:{5}".format(
            now.year, now.month, now.day,
            now.hour, now.minute, now.second)

        text = "{0}/{1}: {2}".format(machine, date, msg)
        # TODO: Print to console
        # TODO: Append line to log file
        print("******* LOG METHOD SHOULD BE IMPLEMENTED FIRST ******* ")

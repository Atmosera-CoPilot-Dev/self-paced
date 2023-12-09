import os
import platform
import datetime


class Logger:

    def __init__(self, logfile):
        self.logfile = logfile

        if os.path.isdir(logfile):
            raise Exception("The path for the log file must be a file, not a directory.")

        folder = os.path.dirname(logfile)
        if not os.path.exists(folder):
            raise Exception("The folder for the log file does not exist.")

        # Verify directory exists (note file not needed)
        # Verify logfile is not itself a directory

    def log(self, msg):
        machine = platform.node()
        now = datetime.datetime.now()
        date = "{0}_{1}_{2} {3}:{4}:{5}".format(
            now.year, now.month, now.day,
            now.hour, now.minute, now.second)

        text = "{0}/{1}: {2}".format(machine, date, msg)
        # Print to console
        print("    log=" + text)

        # Add to log file
        with open(self.logfile, 'a+') as fout:
            fout.write("{0}\n".format(text))

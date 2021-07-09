#! /usr/bin/python3
"""
Run the all the test cases for lab3.
"""
import os
import re
import sys
import subprocess

PATH = os.getcwd()
PATTERN = re.compile(r'^\d\.\d{2}')
LINE = '=================================\n'

def main():
    """
    Run all the tests
    """
    files = get_files()

    with open('results.txt', 'w') as f:
        
        f.write(f'{sys.version}\n')
        f.write(LINE) 

        for exe in ['./sort1', './sort2', './sort3']:
            for file in files:

                cmd = subprocess.run(['time', exe, file], capture_output=True, text=True)

                if cmd.returncode != 0:
                    print("Error")
                    sys.exit(cmd.returncode)

                time = PATTERN.findall(cmd.stderr)[0]
                f.write(f'time {exe} {file} : {time}\n')

            f.write(LINE)
            
def get_files():
    """
    return: a list of files used for testing
    """
    files = os.listdir(PATH)

    text_files = [
        file
        for file in files
        if file.find('txt') != -1 and file not in  {'answers.txt', 'results.txt'}
    ]

    return text_files

if __name__ == "__main__":
    print('Running tests...')
    main()
    print('Tests completed...')
    sys.exit(0)
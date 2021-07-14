import os

def get_files(path):
    """
    return: a list of files used for testing
    """
    files = os.listdir(path)

    text_files = [
        file
        for file in files
        if file.find('txt') != -1 and file not in  {'answers.txt', 'results.txt'}
    ]

    return text_files
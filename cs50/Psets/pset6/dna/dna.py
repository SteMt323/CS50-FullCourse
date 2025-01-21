import csv
import sys


def main():

    # TODO: Check for command-line usage
    if(len(sys.argv) < 3):
        print("Error: Ingrese los argumentos necesarios")
        return

    # TODO: Read database file into a variable
    dat = []
    with open(sys.argv[1], newline='') as csvfile:
        csvreader = csv.DictReader(csvfile) #utiliza para convertir un archivo CSV en un diccionario Python
        for i in csvreader:
            dat.append(i)
    subsequences = list(dat[0].keys())[1:]

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], newline='') as csvfile:
        sequence = csvfile.read()

    # TODO: Find longest match of each STR in DNA sequence
    matches = {}
    for i in subsequences:
        matches[i] = str(longest_match(sequence, i))

    # TODO: Check database for matching profiles
    for subject in dat:
        match = 0
        for i in subsequences:
            if subject[i] == (matches[i]):
                match += 1
        if match == len(subsequences):
            print(subject["name"])
            return
    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()

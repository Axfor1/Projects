from sys import argv, exit
import csv


def main():
    if len(argv) != 3:
        print("Usage: python dna.py data.csv txt")
        exit(1)

    STRs = []
    profile = []

    # Read in database file
    with open(argv[1], mode="r") as database:
        reader = csv.DictReader(database)
        # Populate Short Tandem Repeats
        STRs = reader.fieldnames[1:]
        for row in reader:
            # Add persoN
            profile.append(row)

    # Initialise dictionary for sequence file
    seq_str_count = dict.fromkeys(STRs, 0)

    # Read in sequence file
    with open(argv[2], mode="r") as sequence_file:
        # Grab first line of txt file
        sequence = sequence_file.readline()
        # Loop over every STR from the database
        for STR in STRs:
            # Update the Sequence STR dictionary with max amount of repeats
            seq_str_count[STR] = find_repeats(sequence, STR)

    # Check if any person has same amount of STR repeats
    for profile in profile:
        match_count = 0

        for STR in STRs:
            if int(profile[STR]) != seq_str_count[STR]:
                continue
            match_count += 1

        if match_count == len(STRs):
            print(profile['name'])
            exit(0)

    print("No match")
    exit(1)


def find_repeats(sequence, STR):
    # Number of bases in Short Tandem Repeat
    K = len(STR)

    max_repeats = 0
    for i in range(len(sequence)):
        # Initialise and reset repeat counter
        repeats = 0

        if sequence[i: i + K] == STR:
            # Account for first match
            repeats += 1
            # Keep adding to count for consecutive repeats
            while sequence[i: i + K] == sequence[i + K: i + (2 * K)]:
                repeats += 1
                # Shift reading frame
                i += K

        # Update max count if current repeat steak is greater than max
        if repeats > max_repeats:
            max_repeats = repeats

    return max_repeats


if __name__ == "__main__":
    main()
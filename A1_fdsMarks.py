# Write a Python program to store marks scored in subject “Fundamental of Data Structure” by N students in the class. 
# Write functions to compute following: 
# a) The average score of class 
# b) Highest score and lowest score of class 
# c) Count of students who were absent for the test 
# d) Display mark with highest frequency.

def get_average(marks):
    # Computes the average score of the class. 
    total = 0
    count = 0
    for mark in marks:
        if mark != -1:  # Exclude absent students
            total += mark
            count += 1
    if count > 0:
        return total / count
    else:
        return 0

def get_highest_lowest(marks):
    # Finds the highest and lowest score in the class.
    valid_marks = [mark for mark in marks if mark != -1]
    if valid_marks:
        highest = max(valid_marks)
        lowest = min(valid_marks)
    else:
        highest = None
        lowest = None
    return highest, lowest

def count_absent(marks):
    # Counts the number of students who were absent
    absent_count = 0
    for mark in marks:
        if mark == -1:
            absent_count += 1
    return absent_count

def mark_with_highest_frequency(marks):
    # Finds the mark with the highest frequency.
    frequency = {}
    for mark in marks:
        if mark != -1:  # Exclude absent students
            if mark in frequency:
                frequency[mark] += 1
            else:
                frequency[mark] = 1
    if frequency:
        max_frequency = 0
        most_frequent_marks = []
        for mark, freq in frequency.items():
            if freq > max_frequency:
                max_frequency = freq
                most_frequent_marks = [mark]
            elif freq == max_frequency:
                most_frequent_marks.append(mark)
        return most_frequent_marks
    else:
        return None

def main():
    # Input the marks
    marks = list(map(int, input("Enter the marks of students (-1 for absent, space-separated): ").split()))

    # a) Average score of the class
    average_score = get_average(marks)
    print("a) The average score of the class is:", average_score)

    # b) Highest and lowest score of the class
    highest, lowest = get_highest_lowest(marks)
    print("b) The highest score is:", highest)
    print("   The lowest score is:", lowest)

    # c) Count of students who were absent for the test
    absent_count = count_absent(marks)
    print("c) The number of students absent for the test is:", absent_count)

    # d) Mark with the highest frequency
    most_frequent_marks = mark_with_highest_frequency(marks)
    if most_frequent_marks:
        print("d) The mark(s) with the highest frequency:", ", ".join(str(mark) for mark in most_frequent_marks))
    else:
        print("d) No marks available to determine frequency.")

main()

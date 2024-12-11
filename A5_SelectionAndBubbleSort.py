#  Write a Python program to store first year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using
# a) Selection Sort 
# b) Bubble sort 
# c) display top five scores. 

def selection_sort(array):
    #Sorts the array in ascending order using selection sort.
    n = len(array)
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if array[j] < array[min_index]:
                min_index = j
        array[i], array[min_index] = array[min_index], array[i]

def bubble_sort(array):
    #Sorts the array in ascending order using bubble sort.
    n = len(array)
    for i in range(n):
        for j in range(0, n - i - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]

def display_top_five(array):
    #Displays the top five scores from the sorted array.
    print("Top five scores are:")
    for i in range(min(5, len(array))):
        print(array[-(i + 1)])

def main():
  while True:
    # Input array of percentages
    n = int(input("Enter the number of students: "))
    percentages = []
    for i in range(n):
        print("Enter percentage of student", i + 1, ":", end=" ")
        percentage = float(input())
        percentages.append(percentage)

    print("Choose sorting method:")
    print("1. Selection Sort")
    print("2. Bubble Sort")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        selection_sort(percentages)
        print("Array sorted using Selection Sort:", percentages)
    elif choice == 2:
        bubble_sort(percentages)
        print("Array sorted using Bubble Sort:", percentages)
    else:
        print("Invalid choice.")
        return

    display_top_five(percentages)
    
	 # Check if the user wants to continue
    print("Do you want to continue? (yes/no):")
    continue_choice = input()
    if continue_choice != "yes" or 'YES' or 'y' or 'Y':
        break

main()

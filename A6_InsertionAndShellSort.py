#  Write a python program to store second year percentage of student in array. Write function for sorting array of floating point numbers in ascending order using 
# a) Insertion sort
# b) Shell sort display top five scores.

def insertion_sort(array):
    # Sorts the array in ascending order using insertion sort.
    for i in range(1, len(array)):
        key = array[i]
        j = i - 1
        while j >= 0 and key < array[j]:
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = key

def shell_sort(array):
    # Sorts the array in ascending order using shell sort.
    n = len(array)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = array[i]
            j = i
            while j >= gap and array[j - gap] > temp:
                array[j] = array[j - gap]
                j -= gap
            array[j] = temp
        gap //= 2

def display_top_five(array):
    # Displays the top five scores from the sorted array.
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
        print("1. Insertion Sort")
        print("2. Shell Sort")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            insertion_sort(percentages)
            print("Array sorted using Insertion Sort:", percentages)
        elif choice == 2:
            shell_sort(percentages)
            print("Array sorted using Shell Sort:", percentages)
        else:
            print("Invalid choice.")
            return

        display_top_five(percentages)

        # Check if the user wants to continue
        print("Do you want to continue? (yes/no):")
        continue_choice = input().strip().lower()
        if continue_choice != "yes" or 'YES' or 'y' or 'Y':
            break
        
main()

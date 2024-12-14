# Function to delete duplicate books
def delete_duplicates(books):
    unique_books = []
    for book in books:
        if book not in unique_books:
            unique_books.append(book)
    return unique_books

# Function to display books in ascending order based on cost
def display_sorted_books(books):
    for i in range(len(books)):
        for j in range(i + 1, len(books)):
            if books[i][1] > books[j][1]:
                books[i], books[j] = books[j], books[i]
    print("Books in ascending order based on cost:")
    for book in books:
        print("Title:", book[0], "Cost:", book[1])

# Function to count books with cost more than 500
def count_expensive_books(books):
    count = 0
    for book in books:
        if book[1] > 500:
            count += 1
    print("Number of books with cost more than 500:", count)

# Function to create a new list with books having cost less than 500
def copy_cheap_books(books):
    cheap_books = []
    for book in books:
        if book[1] < 500:
            cheap_books.append(book)
    print("Books with cost less than 500:")
    for book in cheap_books:
        print("Title:", book[0], "Cost:", book[1])
    return cheap_books

# Main program
n = int(input("Enter the number of books: "))
books = []

# Input book details
for i in range(n):
    print("Enter details of book", i + 1)
    title = input("Enter the title of the book: ")
    cost = int(input("Enter the cost of the book: "))
    books.append([title, cost])

# Menu-driven program
while True:
    print("\nLibrary Management System")
    print("1. Delete duplicate entries")
    print("2. Display books in ascending order based on cost")
    print("3. Count books with cost more than 500")
    print("4. Copy books with cost less than 500")
    print("5. Exit")

    choice = input("Enter your choice: ")
    
    if choice == "1":
        books = delete_duplicates(books)
        print("Duplicate entries have been removed.")

    elif choice == "2":
        display_sorted_books(books)

    elif choice == "3":
        count_expensive_books(books)

    elif choice == "4":
        copy_cheap_books(books)

    elif choice == "5":
        print("Exiting the program. Thank you!")
        break

    else:
        print("Invalid choice. Please try again.")

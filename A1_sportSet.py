def unique_list(lst):
    #Removes duplicate entries from the list.
    result = []
    for item in lst:
        if item not in result:
            result.append(item)
    return result

def intersection(lst1, lst2):
    #Returns the intersection of two lists.
    result = []
    for item in lst1:
        if item in lst2 and item not in result:
            result.append(item)
    return result

def union(lst1, lst2):
    #Returns the union of two lists.
    result = lst1[:]
    for item in lst2:
        if item not in result:
            result.append(item)
    return result

def difference(lst1, lst2):
    #Returns the difference of two lists (lst1 - lst2).
    result = []
    for item in lst1:
        if item not in lst2:
            result.append(item)
    return result

def symmetric_difference(lst1, lst2):
    #Returns the symmetric difference of two lists.
    result = []
    for item in lst1:
        if item not in lst2:
            result.append(item)
    for item in lst2:
        if item not in lst1:
            result.append(item)
    return result

def main():
    # User input for players
    cricket = unique_list(input("Enter names of students who play cricket (comma-separated): ").split(","))
    badminton = unique_list(input("Enter names of students who play badminton (comma-separated): ").split(","))
    football = unique_list(input("Enter names of students who play football (comma-separated): ").split(","))
    all_students = unique_list(input("Enter names of all students (comma-separated): ").split(","))

    # a) List of students who play both cricket and badminton
    both_cricket_badminton = intersection(cricket, badminton)
    print("a) Students who play both cricket and badminton:", both_cricket_badminton)

    # b) List of students who play either cricket or badminton but not both
    either_cricket_badminton = symmetric_difference(cricket, badminton)
    print("b) Students who play either cricket or badminton but not both:", either_cricket_badminton)

    # c) Number of students who play neither cricket nor badminton
    cricket_badminton_union = union(cricket, badminton)
    neither_cricket_badminton = difference(all_students, cricket_badminton_union)
    print("c) Number of students who play neither cricket nor badminton:", len(neither_cricket_badminton))

    # d) Number of students who play cricket and football but not badminton
    cricket_football = intersection(cricket, football)
    cricket_football_not_badminton = difference(cricket_football, badminton)
    print("d) Number of students who play cricket and football but not badminton:", len(cricket_football_not_badminton))

    # Call all functions
    print("\nCalling functions directly to display results:")
    print("Unique cricket list:", unique_list(cricket))
    print("Unique badminton list:", unique_list(badminton))
    print("Unique football list:", unique_list(football))
    print("Intersection of cricket and badminton:", intersection(cricket, badminton))
    print("Union of cricket and badminton:", union(cricket, badminton))
    print("Difference of cricket and badminton:", difference(cricket, badminton))
    print("Symmetric difference of cricket and badminton:", symmetric_difference(cricket, badminton))

main()

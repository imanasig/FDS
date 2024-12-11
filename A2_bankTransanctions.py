# Write a Python program that computes the net amount of a bank account based a transaction log from console input. The transaction log format is shown as following: 
# D 100 W 200 (Withdrawal is not allowed if balance is going negative. 
# Write functions for withdraw and deposit, D means deposit while W means withdrawal. 
# Suppose the following input is supplied to the program: D 300, D 300 , W 200, D 100 Then, the output should be: 500 

def deposit(balance, amount):
    #Handles deposit transactions
    balance += amount
    return balance

def withdraw(balance, amount):
    #Handles withdrawal transactions. Ensures no negative balance.
    if balance >= amount:
        balance -= amount
    else:
        print("Withdrawal denied: Insufficient balance.")
    return balance

def main():
    balance = 0
    print("Enter transactions (D <amount> for deposit, W <amount> for withdrawal):")
    while True:
        transaction = input("Transaction: ")
        if not transaction:
            break

        parts = transaction.split()
        if len(parts) != 2:
            print("Invalid transaction format. Please use 'D <amount>' or 'W <amount>'.")
            continue

        action, amount_str = parts
        try:
            amount = int(amount_str)
        except ValueError:
            print("Invalid amount. Please enter a numeric value.")
            continue

        if action == 'D':
            balance = deposit(balance, amount)
        elif action == 'W':
            balance = withdraw(balance, amount)
        else:
            print("Invalid action. Use 'D' for deposit and 'W' for withdrawal.")

    print("Final balance:", balance)

    main()

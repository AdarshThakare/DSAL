#2 ------------ Set ADT Operations ------------

def accept_set(A):
    n = int(input("Enter no. of elements in set : "))
    for i in range(n):
        x = input("Add element to the set : ")
        A.append(x)
    print("Set accepted successfully")
    
def display_set(A):
    n = len(A)
    if(n==0):
        print("Set is empty")
    else:
        print("Elements of set are : ")
        for i in range(n):
            print(A[i], end=' ')

def delete_element(A,X):
    A.remove(X)
    print("Deleted element : ",X)
                
def set_contain(A,X):
    n=len(A)
    
    for i in range(n): 
        
        if (X==A[i]):
            return True
    return False
    
def size_of_set(A):
    n = len(A)
    print("Size  : ",n)
            
                
def search_set(A,X):
    for i in range(len(A)):
        if (A[i] == X):
            return 1
    return 0

def intersection(A,B,C):
    for i in range(len(A)):
        flag = search_set(B,A[i])
        if(flag==1):
            C.append(A[i])    

def union(A,B,C):
    for i in range(len(A)):
        C.append(A[i])
    for i in range(len(B)):
        flag = search_set(A,B[i])
        if(flag==0):
            C.append(B[i])

def difference(A,B,C):
    for i in range(len(A)):
        flag = search_set(B,A[i])
        if(flag==0):
            C.append(A[i])

def subset(A, B):
    for i in range(len(A)):
        if  set_contain(B,A[i]):
            return True
    return False

def main():
    set_A = []
    set_B = []
    while True:
        print("\n1. Accept Set")
        print("2. Display Set")
        print("3. Delete Element")
        print("4. Size of set")
        print("5. Set contains")
        print("6. Intersection of two sets")
        print("7. Union of two sets")
        print("8. Difference of two sets")
        print("9. Subset")
        print("10. Exit")
        
        ch = int(input("Enter your choice : "))
        set_R = []
        
        if(ch == 10):
            print("End of the program!")
            break
        elif(ch == 1 ):
            print("\nEnter first Set :")
            accept_set(set_A)
            print("\nEnter second Set :")
            accept_set(set_B)
        elif(ch == 2):
            print("\nFirst set :")
            display_set(set_A)
            print("\nSecond set : ")
            display_set(set_B)
        elif(ch == 3):
            R=input ("enter the set from which u want to delete  1 OR 2 ")
            if R=='1':
                X = input("Enter the element you want to delete : ")
                delete_element(set_A,X)
            elif R=='2':
                 X = input("Enter the element you want to delete ")
                 delete_element(set_B,X)
            else :
                print("wrong choice of set choose from 1 and 2 ")
                
        elif(ch == 4):
            print("size of first set is :")
            size_of_set(set_A)
            
            print("size of second set is :")
            size_of_set(set_B)
            
        elif(ch == 5):
            X = input("Enter element you want to check: ")
            R = input("Enter set to check in (A/B): ").upper()
            if R == 'A':
                result = set_contain(set_A, X)
            elif R == 'B':
                result = set_contain(set_B, X)
            else:
                print("Invalid set choice")
                continue
            print(f"Element {X} is {'present' if result else 'not present'} in set {R}")
        elif(ch == 6):
            print("\nIntersection set : ")
            intersection(set_A,set_B,set_R)
            display_set(set_R)
        elif(ch == 7):
            print("\nUnion set : ")
            union(set_A,set_B,set_R)
            display_set(set_R)
        elif(ch == 8):
        
            print("\nDifference set : ")
            difference(set_A,set_B,set_R)
            display_set(set_R)
        elif(ch == 9):
            result = subset(set_A, set_B)
            if result:
                print("Set A is a subset of Set B")
            else:
                print("Set A is not a subset of Set B")
        else:
            print("Enter valid choice!")

main()
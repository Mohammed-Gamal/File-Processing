# write students function
def writeStudent():
    c = 'y'

    # open the file in 'append' mode
    with open("student.txt", "a") as file:
        while c == 'y':

            # get data from user
            id = input("\nEnter id: ")
            name = input("Enter name: ")
            age = input("Enter age: ")

            # variable with the user's inputs
            line = id + "\t" + name + "\t" + age + "\n"

            # write the line in the file
            file.write(line)

            # ask user whether to proceed or not
            c = input("Do you want to add more students (y/n)? ")

# function call, to run
#writeStudent()

#--------------------------------------------
# read student function

def readStudent():
    try:
        with open("student.txt", "r") as file:
            print("\nID\tName\tAge")

            for line in file:
                print(line, end='')
    except:
        print("\nfile is not found or empty!")
    finally:
        print("\nDone!\n")
	
# function call
#readStudent()

#-----------------------------------------------
# search student function

def searchStudent():
    
    try:
        # get id from user
        id = input("\nEnter id of the student: ")

        flag = False

        # open the file in 'read' mode
        with open("student.txt", "r") as file:
            for line in file:
                fields = line.split() # fields = ['1', 'Ahmed', '15'] ... etc

                if id == fields[0]: # fields[0] = '1' ...
                    flag = True
                    print("\nID:", fields[0])
                    print("Name:", fields[1])
                    print("Age:", fields[2])
                    break
                
            if not flag:
                print("No match!")
    except:
        print("file is not found!")
    finally:
        print("\nDone!\n")

# function call            
#searchStudent()

#------------------------------------------------
# update student function

def updateStudent():

    try:
        # import the 'rename' & 'remove' functions
        from os import remove, rename

        # get student id from the user
        id = input("\nEnter studnet id: ")

        # open the required files
        file = open("student.txt", "r")
        tempFile = open("temp.txt", "w")
        
        flag = False

        for line in file:
            fields = line.split()   # fields = ['1', 'Ahmed', '15'] ... etc

            if id == fields[0]: # fileds[0] = '1' ...
                flag = True

                # get new data from the user
                name = input("Enter new name: ")
                age = input("Enter new age: ")

                # format the line with the new data
                line = id + "\t" + name + "\t" + age + "\n"

            # write the new data in the new file
            tempFile.write(line)

        # close the files
        file.close()
        tempFile.close()

        # remove the old file
        remove("student.txt")

        # rename the new 'temp.txt' file
        rename("temp.txt", "student.txt")

        if flag:
            print("\nStudent successfully updated.")
        else:
            print("No match!")
    except:
        print("file is not found!")
    finally:
        print("Done!\n")

# function call
#updateStudent()

#------------------------------------------------
# delete student function

def deleteStudent():
    try:
        # import the 'remove' & 'rename' functions
        from os import remove, rename

        # get student id from the user
        id = input("\nEnter id of the student: ")

        # open the required files
        file = open("student.txt", "r")
        tempFile = open("temp.txt", "w")
        
        flag = False

        for line in file:
            fields = line.split() # fields = ['1', 'Ahmed', '15'] ... etc

            if id == fields[0]: # fields[0] = '1' ...
                flag = True
            else:
                tempFile.write(line)

        # close the files
        file.close()
        tempFile.close()

        # remove the old file
        remove("student.txt")

        # rename the new file
        rename("temp.txt", "student.txt")

        if flag:
            print("\nStudent successfully deleted.")
        else:
            print("\nNo match!")
    except:
        print("file is not found!\n")
    finally:
        print("\nDone!\n")
        
# function call
#deleteStudent()

#------------------------------------------------
# menu function

def menu():
    c = 'y'
    
    while c == 'y':
        print("\n- Choose to perform an operation from the following:\n")
        print("1. Add new students")
        print("2. View all students")
        print("3. Search students")
        print("4. Update students")
        print("5. Delete students")

        # get input from user
        #NOTE: input() function returns a string
        c = input("\nEnter your choice: ")

        if c == '1':
            writeStudent()
        elif c == '2':
            readStudent()
        elif c == '3':
            searchStudent()
        elif c == '4':
            updateStudent()
        elif c == '5':
            deleteStudent()
        else:
            print("Invalid option/input!")
            menu()

        # ask user for another operation
        while True:
            c = input("Perform another operation (y/n)? ")

            if c == 'y' or c =='n':
                break

# function call
menu()
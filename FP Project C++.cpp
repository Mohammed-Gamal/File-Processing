/*
	- Basic file operations made by "Mohamed Gamal" at "06/05/2021" "10:05 PM".
	
	- This program includes:
		 [reading, insertion at both the beginning and end, update, searching, deletion]
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <cctype>
#include <unistd.h>   // for sleep() function
using namespace std;

// Main Student class
class Student
{
	public:
		int id;
		char name[20];
};

// Student's general info class
class StudentInfo : public Student
{
	public:
		int grade, department, subjects;
};

// Student's personal info class
class PersInfo : public Student
{
	public:
		char Email[25], date_of_birth[15];
		int graduation_year;
};

// Student's marks class
class Marks : public Student
{
	public:
		int marks;
};

// Student's fee class
class Fee : public Student
{
	public:
		int fee;
};

void writeStudentsBeg()
{	
	system("CLS");
	
	int nof;
	
	cout << "Writing at the beginning of the file...\n" << endl;
	cout << "Which file would you like to use?\n";
	cout << "\n1- 'Information about student' file" << endl;
	cout << "2- 'Personal information' file" << endl;
	cout << "3- 'Marks' file" << endl;
	cout << "4- 'Fee' file" << endl;
	cout << "0- Go back\n" << endl;
	
	cout << "Option: ";
	cin >> nof;
	
	switch(nof)
	{
		case 1:
		{
			system("CLS");
			cout << "Writing at the beginning of \"Information about student\" file...\n" << endl;
			fstream main("student_info.txt", ios::in | ios::out);
			ofstream newf("old.txt", ios::out | ios::app);
			
			StudentInfo s1;
			
			// get data from user
			cout << "Enter ID: ";
			cin >> s1.id;
			
			cout << "Enter name: ";
			cin >> s1.name;
			
			cout << "Enter grade: ";
			cin >> s1.grade;
			
			cout << "Enter department ID: ";
			cin >> s1.department;
			
			cout << "Enter number of subjects: ";
			cin >> s1.subjects;
			
			newf.write((char*)&s1, sizeof(s1));
			
			while(main.read((char*)&s1, sizeof(s1)))
			{
				newf.write((char*)&s1, sizeof(s1));
			}
			
			// close the files
			main.close();
			newf.close();
		
			// remove the old file
			remove("student_info.txt");
			
			// rename the new file to 'Student'
			rename("old.txt", "student_info.txt");
			
			system("CLS");
			cout << "Successful Operation!\n" << endl;
			
			cout << "\nLoading."; sleep(.5); cout << "."; sleep(.5); cout << ".";
			sleep(.5); cout << "." < endl; sleep(.7);
			
			break;
		}
		case 2:
		{
			system("CLS");
			cout << "Writing at the beginning of \"Information about student\" file...\n" << endl;
			fstream main("personal_info.txt", ios::in | ios::out);
			ofstream newf("old.txt", ios::out | ios::app);
			
			PersInfo s1;
			
			// get data from user
			cout << "Enter ID: ";
			cin >> s1.id;
			
			cout << "Enter name: ";
			cin >> s1.name;
			
			cout << "Enter E-Mail: ";
			cin >> s1.Email;
			
			cout << "Enter date of birth (DD:MM:YYYY): ";
			cin >> s1.date_of_birth;
			
			cout << "Enter graduation year (YYYY): ";
			cin >> s1.graduation_year;
	
			// write the data to the file
			newf.write((char*)&s1, sizeof(s1));
			
			while(main.read((char*)&s1, sizeof(s1)))
			{
				newf.write((char*)&s1, sizeof(s1));
			}
			
			// close the files
			main.close();
			newf.close();
		
			// remove the old file
			remove("personal_info.txt");
			
			// rename the new file to 'Student'
			rename("old.txt", "personal_info.txt");
			
			system("CLS");
			cout << "\nSuccessful Operation!" << endl;
			
			cout << "\nLoading."; sleep(.5); cout << "."; sleep(.5); cout << ".";
			sleep(.5); cout << "." < endl; sleep(.7);
			
			break;
		}
		case 3:
		{
			system("CLS");
			cout << "Writing at the beginning of 'Marks' file...\n" << endl;
			fstream main("marks.txt", ios::in | ios::out);
			ofstream newf("old.txt", ios::out | ios::app);
			
			Marks s1;
			
			// get data from user
			cout << "Enter ID: ";
			cin >> s1.id;
			
			cout << "Enter name: ";
			cin >> s1.name;
			
			cout << "Enter marks: ";
			cin >> s1.marks;
			 
			// write the data to the file
			newf.write((char*)&s1, sizeof(s1));
			
			while(main.read((char*)&s1, sizeof(s1)))
			{
				newf.write((char*)&s1, sizeof(s1));
			}
			
			// close the files
			main.close();
			newf.close();
		
			// remove the old file
			remove("marks.txt");
			
			// rename the new file to 'Student'
			rename("old.txt", "marks.txt");
			
			system("CLS");
			cout << "\nSuccessful Operation!" << endl;
			 
			cout << "\nLoading."; sleep(.5); cout << "."; sleep(.5); cout << ".";
			sleep(.5); cout << "." < endl; sleep(.7);
			 
			break;
		}
		case 4:
		{
			system("CLS");
			cout << "Writing at the beginning of 'Fee' file...\n" << endl;
			fstream main("fee.txt", ios::in | ios::out);
			ofstream newf("old.txt", ios::out | ios::app);
			
			Fee s1;
			
			// get data from user
			cout << "Enter ID: ";
			cin >> s1.id;
			
			cout << "Enter name: ";
			cin >> s1.name;
			
			cout << "Enter the student's fees: ";
			cin >> s1.fee;
			 
			// write the data to the file
			newf.write((char*)&s1, sizeof(s1));
			
			while(main.read((char*)&s1, sizeof(s1)))
			{
				newf.write((char*)&s1, sizeof(s1));
			}
			
			// close the files
			main.close();
			newf.close();
		
			// remove the old file
			remove("fee.txt");
			
			// rename the new file to 'Student'
			rename("old.txt", "fee.txt");
			
			system("CLS");
			cout << "\nSuccessful Operation!" << endl;
			
			cout << "\nLoading."; sleep(.5); cout << "."; sleep(.5); cout << ".";
			sleep(.5); cout << "." < endl; sleep(.7);
			
			break;
		}
		case 0:
		{
			break;
		}
		default:
			cout << "\nInvalid input or option!" << endl;
	}
}

void writeStudentsEnd()
{
	system("CLS");
	
	int nof;
	
	cout << "Writing to the end of the file...\n" << endl;
	cout << "Which file would you like to use?\n";
	cout << "\n1- 'Information about student' file" << endl;
	cout << "2- 'Personal information' file" << endl;
	cout << "3- 'Marks' file" << endl;
	cout << "4- 'Fee' file" << endl;
	cout << "0- Go back\n" << endl;
	
	cout << "Option: ";
	cin >> nof;
	
	switch(nof)
	{
		case 1:
		{
			system("CLS");
			cout << "Writing to the end of \"Information about student\" file...\n" << endl;
			ofstream input("student_info.txt", ios::out | ios::app);
			
			StudentInfo s1;
			
			// get data from user
			cout << "Enter ID: ";
			cin >> s1.id;
			
			cout << "Enter name: ";
			cin >> s1.name;
			
			cout << "Enter the grade: ";
			cin >> s1.grade;
			
			cout << "Enter the department ID: ";
			cin >> s1.department;
			
			cout << "Enter the number of subjects: ";
			cin >> s1.subjects;
	
			// write the data to the file
			input.write((char*)&s1, sizeof(s1));
			
			// close the file
			input.close();
			
			system("CLS");
			cout << "\nSuccessful Operation!" << endl;
			
			cout << "\nLoading..";
			sleep(.5);
			cout << "..." << endl;
			sleep(.7);
			
			break;
		}
		case 2:
		{
			system("CLS");
			cout << "Writing to the end of \"Personal Information\" file...\n" << endl;
			ofstream input("personal_info.txt", ios::out | ios::app);
			
			PersInfo s1;
			
			// get data from user
			cout << "Enter ID: ";
			cin >> s1.id;
			
			cout << "Enter name: ";
			cin >> s1.name;
			
			cout << "Enter E-Mail (i.e example@info.com): ";
			cin >> s1.Email;
			
			cout << "Enter date of birth (i.e 15:11:2021): ";
			cin >> s1.date_of_birth;
			
			cout << "Enter graduation year (i.e 2021): ";
			cin >> s1.graduation_year;
	
			// write the data to the file
			input.write((char*)&s1, sizeof(s1));
			
			// close the file
			input.close();
			
			system("CLS");
			cout << "\nSuccessful Operation!" << endl;
			
			cout << "\nLoading."; sleep(.5); cout << "."; sleep(.5); cout << ".";
			sleep(.5); cout << "." < endl; sleep(.7);
			
			break;
		}
		case 3:
		{
			system("CLS");
			cout << "Writing to the end of \"Marks\" file...\n" << endl;
			ofstream input("marks.txt", ios::out | ios::app);
			
			Marks s1;
			
			// get data from user
			cout << "Enter ID: ";
			cin >> s1.id;
			
			cout << "Enter name: ";
			cin >> s1.name;
			
			cout << "Enter marks: ";
			cin >> s1.marks;
			 
			// write the data to the file
			input.write((char*)&s1, sizeof(s1));
			
			// close the file
			input.close(); 
			
			system("CLS");
			cout << "\nSuccessful Operation!" << endl;
			
			cout << "\nLoading."; sleep(.5); cout << "."; sleep(.5); cout << ".";
			sleep(.5); cout << "." < endl; sleep(.7);
			 
			break;
		}
		case 4:
		{
			system("CLS");
			cout << "Writing to the end of \"Fee\" file...\n" << endl;
			ofstream input("fee.txt", ios::out | ios::app);
			
			Fee s1;
			
			// get data from user
			cout << "Enter ID: ";
			cin >> s1.id;
			
			cout << "Enter name: ";
			cin >> s1.name;
			
			cout << "Enter the student's fees: ";
			cin >> s1.fee;
			 
			// write the data to the file
			input.write((char*)&s1, sizeof(s1));
			
			// close the file
			input.close(); 
			
			system("CLS");
			cout << "\nSuccessful Operation!" << endl;
			
			cout << "\nLoading."; sleep(.5); cout << "."; sleep(.5); cout << ".";
			sleep(.5); cout << "." < endl; sleep(.7);
			
			break;
		}
		case 0:
		{
			break;
		}
		default:
			cout << "\nInvalid input or option!" << endl;
	}
}

// Read students' records function
void readStudents()
{
	system("CLS");
	
	int nof;
	
	cout << "Reading from the file...\n" << endl;
	cout << "Which file would you like to use?\n";
	cout << "\n1- 'Information about student' file" << endl;
	cout << "2- 'Personal information' file" << endl;
	cout << "3- 'Marks' file" << endl;
	cout << "4- 'Fee' file" << endl;
	cout << "0- Go back\n" << endl;
	cout << "Option: ";
	cin >> nof;
	
	switch(nof)
	{
		case 1:
		{
			// clear the screen for the user
			system("CLS");
			
			StudentInfo s1;
			ifstream output("student_info.txt");
			
			cout << "Reading from the file..." << endl;
			
			if(output)
			{
				// read the data from the file
				cout << "\nID\tName\tGrade\tDepartment ID\tSubjects" << endl;
				while(output.read((char*)&s1, sizeof(s1)))
				{
					cout << s1.id << "\t" << s1.name << "\t  " << s1.grade << "\t   " << s1.department << "\t\t  " << s1.subjects << endl;
				}
				
				// close the file
				output.close();	
				
				cout << "\nSuccessful Operation!\n" << endl;
			}
			else
				cout << "Error: couldn't open the file!" << endl;
			
			break;
		}
		case 2:
		{
			// clear the screen for the user
			system("CLS");
			
			PersInfo s1;
			ifstream output("personal_info.txt");
			
			cout << "Reading from the file..." << endl;
			
			if(output)
			{
				// read the data from the file
				cout << "\nID\tName\tE-Mail\tDate Of Birth\tGraduation Year" << endl;
				while(output.read((char*)&s1, sizeof(s1)))
				{
					cout << s1.id << "\t" << s1.name << "\t" << s1.Email << "\t" << s1.date_of_birth << "\t" << s1.graduation_year << endl;
				}
				
				// close the file
				output.close();	
				
				cout << "\nSuccessful Operation!\n" << endl;
			}
			else
				cout << "Error: couldn't open the file!" << endl;
				
			break;
		}
		case 3:
		{
			// clear the screen for the user
			system("CLS");
			
			Marks s1;
			ifstream output("marks.txt");
			
			cout << "Reading from the file..." << endl;
			
			if(output)
			{
				// read the data from the file
				cout << "\nID\tName\tMarks" << endl;
				while(output.read((char*)&s1, sizeof(s1)))
				{
					cout << s1.id << "\t" << s1.name << "\t" << s1.marks << endl;
				}
				
				// close the file
				output.close();	
				
				cout << "Successful Operation!\n" << endl;
			}
			else
				cout << "Error: couldn't open the file!" << endl;
			
			break;
		}
		case 4:
		{
			// clear the screen for the user
			system("CLS");
			
			Fee s1;
			ifstream output("fee.txt");
			
			cout << "Reading from the file..." << endl;
			
			if(output)
			{
				// read the data from the file
				cout << "\nID\tName\tFees" << endl;
				while(output.read((char*)&s1, sizeof(s1)))
				{
					cout << s1.id << "\t" << s1.name << "\t" << s1.fee << endl;
				}
				
				// close the file
				output.close();	
				
				cout << "\nSuccessful Operation!\n" << endl;
			}
			else
				cout << "Error: couldn't open the file!" << endl;
				
			break;
		}
		case 0:
		{
			break;
		}
		default:
			cout << "Invalid input or option!" << endl;
	}
}

// Search students' records function
void searchStudents()
{
	system("CLS");
	
	int nof;
	
	cout << "Searching a file...\n" << endl;
	cout << "Which file would you like to use?\n";
	cout << "\n1- 'Information about student' file" << endl;
	cout << "2- 'Personal information' file" << endl;
	cout << "3- 'Marks' file" << endl;
	cout << "4- 'Fee' file" << endl;
	cout << "0- Go back\n" << endl;
	cout << "Option: ";
	cin >> nof;
	
	switch(nof)
	{
		case 1:
		{
			// clear the screen for the user
			system("CLS");
			
			StudentInfo s1;
			ifstream pointer("student_info.txt");
			
			cout << "Searching the file...\n" << endl;
			
			if(pointer)
			{
				int found;
				char sname[20];
			
				// get the name from the user
				cout << "Enter a name to search for: ";
				cin >> sname;
			
				while(pointer.read((char*)&s1, sizeof(s1)))
				{
					if(strcmp(sname, s1.name) == 0)
					{
						found = true;
						break;
					}
					else
						found = false;
				}
				
				if(found)
				{
					// read the data from the file
					cout << "\nID\tName\tGrade\tDepartment ID\tSubjects" << endl;
					cout << s1.id << "\t" << s1.name << "\t  " << s1.grade << "\t   " << s1.department << "\t\t  " << s1.subjects << endl;
				
					cout << "\nSuccessful Operation!\n" << endl;
				}
				else
				{
					cout << "\nInsufficient input, please enter a valid name!" << endl;
					cout<< "\nUnsuccessful Operation!\n" << endl;
				}
				
				// close the file	
				pointer.close();
			}
			else
				cout << "\nCouldn't open the file!" << endl;
			
			break;
		}
		case 2:
		{
			// clear the screen for the user
			system("CLS");
			
			PersInfo s1;
			ifstream pointer("personal_info.txt");
			
			cout << "Searching the file...\n" << endl;
			
			if(pointer)
			{
				int found;
				char sname[20];
			
				// get the name from the user
				cout << "Enter a name to search for: ";
				cin >> sname;
			
				while(pointer.read((char*)&s1, sizeof(s1)))
				{
					if(strcmp(sname, s1.name) == 0)
					{
						found = true;
						break;
					}
					else
						found = false;
				}
				
				if(found)
				{
					// read the data from the file
					cout << "\nID\tName\tE-Mail\tDate Of Birth\tGraduation Year" << endl;
					cout << s1.id << "\t" << s1.name << "\t" << s1.Email << "\t" << s1.date_of_birth << "\t" << s1.graduation_year << endl;				
				
					cout << "\nSuccessful Operation!\n" << endl;
				}
				else
				{
					cout << "\nInsufficient input, please enter a valid name!" << endl;
					cout<< "\nUnsuccessful Operation!\n" << endl;
				}
				
				// close the file	
				pointer.close();
			}
			else
				cout << "\nCouldn't open the file!" << endl;

			break;
		}
		case 3:
		{
			// clear the screen for the user
			system("CLS");
			
			Marks s1;
			ifstream pointer("marks.txt");
			
			cout << "Searching the file...\n" << endl;
			
			if(pointer)
			{
				int found;
				char sname[20];
			
				// get the name from the user
				cout << "Enter a name to search for: ";
				cin >> sname;
			
				while(pointer.read((char*)&s1, sizeof(s1)))
				{
					if(strcmp(sname, s1.name) == 0)
					{
						found = true;
						break;
					}
					else
						found = false;
				}
				
				if(found)
				{
					// read the data from the file
					cout << "\nID\tName\tMarks" << endl;
					cout << s1.id << "\t" << s1.name << "\t" << s1.marks << endl;
					
					cout << "\nSuccessful Operation!\n" << endl;
				}
				else
				{
					cout << "\nInsufficient input, please enter a valid name!" << endl;
					cout<< "\nUnsuccessful Operation!\n" << endl;
				}
				
				// close the file	
				pointer.close();
			}
			else
				cout << "\nCouldn't open the file!" << endl;

			break;
		}
		case 4:
		{
			// clear the screen for the user
			system("CLS");
			
			Fee s1;
			ifstream pointer("fee.txt");
			
			cout << "Searching the file...\n" << endl;
			
			if(pointer)
			{
				int found;
				char sname[20];
			
				// get the name from the user
				cout << "Enter a name to search for: ";
				cin >> sname;
			
				while(pointer.read((char*)&s1, sizeof(s1)))
				{
					if(strcmp(sname, s1.name) == 0)
					{
						found = true;
						break;
					}
					else
						found = false;
				}
				
				if(found)
				{
					// read the data from the file
					cout << "\nID\tName\tFees" << endl;
					cout << s1.id << "\t" << s1.name << "\t" << s1.fee << endl;
					
					cout << "\nSuccessful Operation!\n" << endl;
				}
				else
				{
					cout << "\nInsufficient input, please enter a valid name!" << endl;
					cout<< "\nUnsuccessful Operation!\n" << endl;
				}
				
				// close the file	
				pointer.close();
			}
			else
				cout << "Error: Couldn't open the file!" << endl;

			break;
		}
		case 0:
		{
			break;
		}
		default:
			cout << "Invalid input or option!" << endl;
	}
}

// Update students' records function
void updateStudents()
{
	system("CLS");

	int nof;
	
	cout << "Updating a file...\n" << endl;
	cout << "Which file would you like to use?\n";
	cout << "\n1- 'Information about student' file" << endl;
	cout << "2- 'Personal information' file" << endl;
	cout << "3- 'Marks' file" << endl;
	cout << "4- 'Fee' file" << endl;
	cout << "0- Go back\n" << endl;
	cout << "Option: ";
	cin >> nof;
	
	switch(nof)
	{
		case 1:
		{
			// clear the screen for the user
			system("CLS");
			
			StudentInfo s1;
			fstream edit("student_info.txt", ios::out | ios::in);
			
			int found, curPos;
			char sname[20];
			
			cout << "Updating the file...\n" << endl;
			
			// Get the new data from the user
			cout << "\nEnter the name you wish to update its id: ";
			cin >> sname;
			
			if(edit)
			{
				// reading the file data to search it
				while(edit.read((char*)&s1, sizeof(s1)))
				{
					if(strcmp(sname, s1.name) == 0)
					{
						// Get the user position using the reading pointer
						curPos = edit.tellg();
						
						found = true;
						break;
					}
					else
						found = false;
				}
				
				// if the data is found
				if(found)
				{
					// Get the new data from the user
					cout << "\nEnter the new ID for \"" << s1.name << "\": ";
					cin >> s1.id;
					
					// Update the data
					edit.seekp(curPos - sizeof(s1), ios::beg);
		            edit.write((char*) &s1, sizeof(s1));
		
					// Initialize the reading pointer of the new data
		            edit.seekg(curPos - sizeof(s1), ios::beg);
		            edit.read((char*) &s1, sizeof(s1));
					
					// Print out the new updated record
					cout << "\nID\tName\tGrade\tDepartment ID\tSubjects" << endl;
					cout << s1.id << "\t" << s1.name << "\t  " << s1.grade << "\t   " << s1.department << "\t\t  " << s1.subjects << endl;

				}
				else
					cout << "\nInsufficient input, please enter a valid name!" << endl;
				
				// Close the file
				edit.close();
				
				cout << "\nSuccessful Operation!\n" << endl;
			}
			else
			{
				cout << "Error: Couldn't open the file!" << endl;
				cout << "\nUnsuccessful Operation!\n" << endl;
			}
			
			break;
		}
		case 2:
		{
			// clear the screen for the user
			system("CLS");
			
			PersInfo s1;
			fstream edit("personal_info.txt", ios::out | ios::in);
			
			int found, curPos;
			char sname[20];
			
			cout << "Updating the file...\n" << endl;
			
			// Get the new data from the user
			cout << "\nEnter the name you wish to update its id: ";
			cin >> sname;
			
			if(edit)
			{
				// reading the file data to search it
				while(edit.read((char*)&s1, sizeof(s1)))
				{
					if(strcmp(sname, s1.name) == 0)
					{
						// Get the user position using the reading pointer
						curPos = edit.tellg();
						
						found = true;
						break;
					}
					else
						found = false;
				}
				
				// if the data is found
				if(found)
				{
					// Get the new data from the user
					cout << "\nEnter the new ID for \"" << s1.name << "\": ";
					cin >> s1.id;
					
					// Update the data
					edit.seekp(curPos - sizeof(s1), ios::beg);
		            edit.write((char*) &s1, sizeof(s1));
		
					// Initialize the reading pointer of the new data
		            edit.seekg(curPos - sizeof(s1), ios::beg);
		            edit.read((char*) &s1, sizeof(s1));
					
					// Print out the new updated record
					cout << "\nID\tName\tE-Mail\tDate Of Birth\tGraduation Year" << endl;
					cout << s1.id << "\t" << s1.name << "\t" << s1.Email << "\t" << s1.date_of_birth << "\t" << s1.graduation_year << endl;
				}
				else
					cout << "\nInsufficient input, please enter a valid name!" << endl;
				
				// Close the file
				edit.close();
				
				cout << "\nSuccessful Operation!\n" << endl;
			}
			else
			{
				cout << "Error: Couldn't open the file!" << endl;
				cout << "\nUnsuccessful Operation!\n" << endl;
			}
			
			break;
		}
		case 3:
		{
			// clear the screen for the user
			system("CLS");
			
			Marks s1;
			fstream edit("marks.txt", ios::out | ios::in);
			
			int found, curPos;
			char sname[20];
			
			cout << "Updating the file...\n" << endl;
			
			// Get the new data from the user
			cout << "\nEnter the name you wish to update its id: ";
			cin >> sname;
			
			if(edit)
			{
				// reading the file data to search it
				while(edit.read((char*)&s1, sizeof(s1)))
				{
					if(strcmp(sname, s1.name) == 0)
					{
						// Get the user position using the reading pointer
						curPos = edit.tellg();
						
						found = true;
						break;
					}
					else
						found = false;
				}
				
				// if the data is found
				if(found)
				{
					// Get the new data from the user
					cout << "\nEnter the new ID for \"" << s1.name << "\": ";
					cin >> s1.id;
					
					// Update the data
					edit.seekp(curPos - sizeof(s1), ios::beg);
		            edit.write((char*) &s1, sizeof(s1));
		
					// Initialize the reading pointer of the new data
		            edit.seekg(curPos - sizeof(s1), ios::beg);
		            edit.read((char*) &s1, sizeof(s1));
					
					// Print out the new updated record
					cout << "\nID\tName\tMarks" << endl;
					cout << s1.id << "\t" << s1.name << "\t" << s1.marks << endl;
				}
				else
					cout << "\nInsufficient input, please enter a valid name!" << endl;
				
				// Close the file
				edit.close();
				
				cout << "\nSuccessful Operation!\n" << endl;
			}
			else
			{
				cout << "Error: Couldn't open the file!" << endl;
				cout << "\nUnsuccessful Operation!\n" << endl;
			}
			
			break;
		}
		case 4:
		{
			// clear the screen for the user
			system("CLS");
			
			Fee s1;
			fstream edit("fee.txt", ios::out | ios::in);
			
			int found, curPos;
			char sname[20];
			
			cout << "Updating the file...\n" << endl;
			
			// Get the new data from the user
			cout << "\nEnter the name you wish to update its id: ";
			cin >> sname;
			
			if(edit)
			{
				// reading the file data to search it
				while(edit.read((char*)&s1, sizeof(s1)))
				{
					if(strcmp(sname, s1.name) == 0)
					{
						// Get the user position using the reading pointer
						curPos = edit.tellg();
						
						found = true;
						break;
					}
					else
						found = false;
				}
				
				// if the data is found
				if(found)
				{
					// Get the new data from the user
					cout << "\nEnter the new ID for \"" << s1.name << "\": ";
					cin >> s1.id;
					
					// Update the data
					edit.seekp(curPos - sizeof(s1), ios::beg);
		            edit.write((char*) &s1, sizeof(s1));
		
					// Initialize the reading pointer of the new data
		            edit.seekg(curPos - sizeof(s1), ios::beg);
		            edit.read((char*) &s1, sizeof(s1));
					
					// Print out the new updated record
					cout << "\nID\tName\tFees" << endl;
					cout << s1.id << "\t" << s1.name << "\t" << s1.fee << endl;
				}
				else
					cout << "\nInsufficient input, please enter a valid name!" << endl;
				
				// Close the file
				edit.close();
				
				cout << "\nSuccessful Operation!\n" << endl;
			}
			else
			{
				cout << "Error: Couldn't open the file!" << endl;
				cout << "\nUnsuccessful Operation!\n" << endl;
			}
			
			break;
		}
		case 0:
		{
			break;
		}
		default:
			cout << "Invalid input or option!" << endl;
	}
}

// delete students' records function
void deleteStudents()
{
	system("CLS");
	
	int nof;
	
	cout << "Deletion from a file...\n" << endl;
	cout << "Which file would you like to use?\n";
	cout << "\n1- 'Information about student' file" << endl;
	cout << "2- 'Personal information' file" << endl;
	cout << "3- 'Marks' file" << endl;
	cout << "4- 'Fee' file" << endl;
	cout << "0- Go back\n" << endl;
	cout << "Option: ";
	cin >> nof;
	
	
	switch(nof)
	{
		case 1:
		{
			// clear the screen for the user
			system("CLS");
			
			StudentInfo s1;
			char sname[20];
			int found = false;
			ifstream main("student_info.txt"); // read
			ofstream temp("temp.txt");  // write
			
			cout << "Deleting from the file...\n" << endl;
			
			if(main)
			{
				cout << "\nEnter a name to delete its record: ";
				cin >> sname;
			
				while(main.read((char*)&s1, sizeof(s1)))
				{
					if(strcmp(sname, s1.name) != 0)
					{
						temp.write((char*)&s1, sizeof(s1));
					}
					else
					{
						found = true;
						continue;
					}
				}
				
				if(!found)
				{
					cout << "\nInsufficient input, please enter a valid name!" << endl;
					cout << "No records were deleted!" << endl;
					
					return;
				}
				
				// close the files
				main.close();
				temp.close();
				
				// delete the 'main' file
				remove("student_info.txt");
				
				// rename the 'temp' file
				rename("temp.txt", "student_info.txt");
				
				cout << "\nSuccessful Operation!\n" << endl;
			}
			else
				cout << "Error: Couldn't open the file!" << endl;
		}
		case 2:
		{
			// clear the screen for the user
			system("CLS");
			
			PersInfo s1;
			char sname[20];
			int found = false;
			ifstream main("personal_info.txt"); // read
			ofstream temp("temp.txt");  // write
			
			cout << "Deleting from the file...\n" << endl;
			
			if(main)
			{
				cout << "\nEnter a name to delete its record: ";
				cin >> sname;
			
				while(main.read((char*)&s1, sizeof(s1)))
				{
					if(strcmp(sname, s1.name) != 0)
					{
						temp.write((char*)&s1, sizeof(s1));
					}
					else
					{
						found = true;
						continue;
					}
				}
				
				if(!found)
				{
					cout << "\nInsufficient input, please enter a valid name!" << endl;
					cout << "No records were deleted!" << endl;
					
					return;
				}
				
				// close the files
				main.close();
				temp.close();
				
				// delete the 'main' file
				remove("personal_info.txt");
				
				// rename the 'temp' file
				rename("temp.txt", "personal_info.txt");
				
				cout << "\nSuccessful Operation!\n" << endl;
			}
			else
				cout << "Error: Couldn't open the file!" << endl;
		}
		case 3:
		{
			// clear the screen for the user
			system("CLS");
			
			Marks s1;
			char sname[20];
			int found = false;
			ifstream main("marks.txt"); // read
			ofstream temp("temp.txt");  // write
			
			cout << "Deleting from the file...\n" << endl;
			
			if(main)
			{
				cout << "\nEnter a name to delete its record: ";
				cin >> sname;
			
				while(main.read((char*)&s1, sizeof(s1)))
				{
					if(strcmp(sname, s1.name) != 0)
					{
						temp.write((char*)&s1, sizeof(s1));
					}
					else
					{
						found = true;
						continue;
					}
				}
				
				if(!found)
				{
					cout << "\nInsufficient input, please enter a valid name!" << endl;
					cout << "No records were deleted!" << endl;
					
					return;
				}
				
				// close the files
				main.close();
				temp.close();
				
				// delete the 'main' file
				remove("marks.txt");
				
				// rename the 'temp' file
				rename("temp.txt", "marks.txt");
				
				cout << "\nSuccessful Operation!\n" << endl;
			}
			else
				cout << "Error: Couldn't open the file!" << endl;
		}
		case 4:
		{
			// clear the screen for the user
			system("CLS");
			
			Fee s1;
			char sname[20];
			int found = false;
			ifstream main("fee.txt"); // read
			ofstream temp("temp.txt");  // write
			
			cout << "Deleting from the file...\n" << endl;
			
			if(main)
			{
				cout << "\nEnter a name to delete its record: ";
				cin >> sname;
			
				while(main.read((char*)&s1, sizeof(s1)))
				{
					if(strcmp(sname, s1.name) != 0)
					{
						temp.write((char*)&s1, sizeof(s1));
					}
					else
					{
						found = true;
						continue;
					}
				}
				
				if(!found)
				{
					cout << "\nInsufficient input, please enter a valid name!" << endl;
					cout << "No records were deleted!" << endl;
					
					return;
				}
				
				// close the files
				main.close();
				temp.close();
				
				// delete the 'main' file
				remove("fee.txt");
				
				// rename the 'temp' file
				rename("temp.txt", "fee.txt");
				
				cout << "\nSuccessful Operation!\n" << endl;
			}
			else
				cout << "Error: Couldn't open the file!" << endl;
		}
		case 0:
		{
			break;
		}
		default:
			cout << "Invalid input or option!" << endl;
	}
}

// menu for the user
void menu()
{
	int c = 0;
	char k;
	
	system("CLS");
	cout << "\t\t\t\tSimple file operations!\n" << endl;
	
	cout << "Choose to perfrom an operation from the following: \n" << endl;
	cout << "1- Reading from a file" << endl;
	cout << "2- Writing at the beginning of a file" << endl;
	cout << "3- Writing at the end of a file" << endl;
	cout << "4- Searching by name" << endl;
	cout << "5- Deletion by name" << endl;
	cout << "6- Update by name" << endl;
	cout << "0- Exit\n" << endl;;
	
	cout << "Option: ";
	cin >> c;
	
	switch(c)
	{
		case 1:
		{
			readStudents();
			break;
		}
		case 2:
		{
			writeStudentsBeg();
			break;
		}
		case 3:
		{
			writeStudentsEnd();
			break;
		}
		case 4:
		{
			searchStudents();
			break;
		}
		case 5:
		{
			deleteStudents();
			break;
		}
		case 6:
		{
			updateStudents();
			break;
		}
		case 0:
		{
			system("CLS");
			cout << "\nThanks for using the system!" << endl;
			
			break;
		}
		default:
			cout << "\nYou have entered an invalid input!" << endl;
	}
	
	if(c != 0)
	{
		sleep(1);
		system("CLS");
		
		cout << "\nEnter (y/n) to perform another operation or exit: ";
		cin >> k;
		
		k = (char) tolower(k);
		
		if(k == 'y')
		{
			system("CLS");
			menu();
		}
		else if(k == 'n')
			return;
		else
		{
			system("CLS");
			
			while(1)
			{
				cout << "\nEnter either (y/n) to perform another operation or exit: ";
				cin >> k;
				
				k = (char) tolower(k);
				
				if(k == 'y')
				{
					system("CLS");
					menu();
					
					break;
				}
				
				if(k == 'n')
					break;
			}
		}	
	}
}

int main()
{
	menu();
	
	return 0;
}

#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
using namespace std;
class Node
{
public:
	Node()
	{
		next = nullptr;
	}
	string BookTitle;
	string studentOneName, studentTwoName, studentThreeName;
	int BookID;
	Node* next;
};

class LinkedList
{
	Node* head;
	//creates a new node and returns its address
	Node* createNode(int bkID, string bkTitle, string studOne, string studTwo, string studThree)
	{
		Node* newNode = new Node;
		newNode->BookTitle = bkTitle;
		newNode->studentOneName = studOne;
		newNode->studentTwoName = studTwo;
		newNode->studentThreeName = studThree;
		newNode->BookID = bkID;

		return newNode;
	}
public:
	LinkedList()
	{
		head = nullptr;
	}

	//Checks if list is empty or not
	bool isEmpty()
	{
		if (head == nullptr)
			return true;
		else
			return false;
	}

	//Add a new node at beginning
	void prependNode(int bkID, string bkTitle, string studOne, string studTwo, string studThree)
	{
		if (isEmpty())
		{
			head = createNode(bkID, bkTitle, studOne, studTwo, studThree);
		}
		else
		{
			//creates a new node and add it to the beginning
			Node* newNode = createNode(bkID, bkTitle, studOne, studTwo, studThree);

			newNode->next = head;
			head = newNode;
		}
	}
	//Add a new node at end of the list
	void appendNode(int bkID, string bkTitle, string studOne, string studTwo, string studThree)
	{
		if (isEmpty())
		{
			head = createNode(bkID, bkTitle, studOne, studTwo, studThree);
		}
		else
		{
			//creates a new node and add it to the end
			Node* newNode = createNode(bkID, bkTitle, studOne, studTwo, studThree);
			Node* temp = head;

			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
	//Add a new node at after a given node
	void addNodeAfter(int findID, int bkID, string bkTitle, string studOne, string studTwo, string studThree)
	{
		if (isEmpty())
		{
			head = createNode(bkID, bkTitle, studOne, studTwo, studThree);
		}
		else
		{
			//creates a new node and add it after a given node
			Node* newNode = createNode(bkID, bkTitle, studOne, studTwo, studThree);
			Node* temp = head;

			while (temp->BookID != findID)
			{
				temp = temp->next;
			}

			newNode->next = temp->next;
			temp->next = newNode;
		}
	}
	//Takes Project Title as parameter and returns true if present
	Node* searchNode(int bkID)
	{
		//bool flag = false;

		if (isEmpty())
			return nullptr;
		else
		{
			Node* temp = head;

			while (temp != nullptr)
			{
				if (temp->BookID == bkID)
				{
					break;
				}
				temp = temp->next;
			}
			return temp;
		}
	}
	//updates existing node
	void updateExistingNode(int bkID)
	{
		if (isEmpty())
			cout << "List is Empty!" << endl;
		else if (searchNode(bkID) == nullptr)
			cout << "Project with this ID, does not exist!" << endl;
		else
		{
			int userInput = 0;
			string update = "";
			Node* tempNode = head;
			while (tempNode->next != nullptr)
			{
				if (tempNode->BookID == bkID)
					break;
				tempNode = tempNode->next;
			}

			do
			{
				cout << "1- Update Book Title \n2- Update Name of Member 1 \n3- Update Name of Member 2 \n4- Update Name of Member 3 \n5- Exit\nPlease make a choice: "; cin >> userInput;
				if (userInput == 1)
				{
					cout << "Please enter Book Title: "; cin.ignore(); getline(cin, update);
					tempNode->BookTitle = update;
				}
				else if (userInput == 2)
				{
					cout << "Please enter New Name: "; cin.ignore(); getline(cin, update);
					tempNode->studentOneName = update;
				}
				else if (userInput == 3)
				{
					cout << "Please enter New Name: "; cin.ignore(); getline(cin, update);
					tempNode->studentTwoName = update;
				}
				else if (userInput == 4)
				{
					cout << "Please enter New Name: "; cin.ignore(); getline(cin, update);
					tempNode->studentThreeName = update;
				}
				else if (userInput == 5)
				{
					break;
				}
				else
				{
					cout << "Invalid Choice!" << endl;
				}
			} while ((userInput > 0 && userInput <= 4) || userInput != 5);
		}
	}
	//Finds a node and deletes
	void deleteNode(int bkID)
	{
		if (isEmpty())
			cout << "List is Empty!" << endl;
		else if (searchNode(bkID) == nullptr)
			cout << "Book with this ID, does not exist!" << endl;
		else
		{
			Node* tempNode = head;

			while (tempNode->next != nullptr)
			{
				if (tempNode->BookID == bkID)
					break;
				tempNode = tempNode->next;
			}

			if (tempNode == head)
			{
				Node* delNode = head;
				head = head->next;

				delete delNode;
			}
			else if (tempNode->next == nullptr)
			{
				Node* delNode = tempNode->next;

				Node* tempForSearch = head;
				while (tempForSearch->next->next != nullptr)
				{
					tempForSearch = tempForSearch->next;
				}
				tempForSearch->next = nullptr;

				delete delNode;
			}
			else
			{
				Node* delNode = nullptr;
				Node* tempNode = head;
				Node* previousNode = nullptr;
				Node* nextNode = nullptr;

				while (tempNode->next != nullptr)
				{
					if (tempNode->next->BookID == bkID)
						break;
					tempNode = tempNode->next;
				}

				previousNode = tempNode;
				nextNode = tempNode->next->next;
				delNode = tempNode->next;

				previousNode->next = nextNode;

				delete delNode;
			}
		}
	}
	bool duplicateBookID(unsigned int tempID)
	{
		bool flag = false;

		if (isEmpty())
			return flag;
		else
		{
			Node* tempNode = head;

			while (tempNode != nullptr)
			{
				if (tempNode->BookID == tempID)
				{
					flag = true;
					break;
				}
				tempNode = tempNode->next;
			}
			return flag;
		}
	}

	//Displays linked list
	void traverse()
	{
		for (Node* temp = head; temp != nullptr; temp = temp->next)
		{
			cout << "Book ID: " << temp->BookID << endl;
			cout << "Book Title: " << temp->BookTitle << endl;
			cout << "Group Member 1: " << temp->studentOneName << endl;
			cout << "Group Member 2: " << temp->studentTwoName << endl;
			cout << "Group Member 3: " << temp->studentThreeName << endl;
		}
		cout << endl << endl;
	}
};
int main()
{
	LinkedList BooksList;
	char userInput = '\0';
	string username, password;

	cout << "1- Enter Login \n2- Signup \n3- Reset Password \nPlease make a choice: "; cin >> userInput;

	do
	{
		if (userInput == '1')
		{
			cout << "Please enter username: "; cin >> username;
			cout << "Please enter password: "; cin >> password;
		}
		else if (userInput == '2')
		{
			char choice = '\0';
			cout << "Only 1 username and password left: user \nPress 1 to assign: "; cin >> choice;

			if (choice == '1')
			{
				username = "user";
				password = "user";
				cout << "Successfully assigned!" << endl;
			}
		}
		else
		{
		again:
			cout << "Please enter your phone number +92***-*****67: "; cin >> password;

			if (password == "+92300-1234567")
			{
				cout << "Your username and password is: admin\nPlease try logging again!" << endl;
			}
			else
			{
				cout << "Incorrect!" << endl;
				goto again;
			}
		}
		if ((username == "admin" && password == "admin"))
		{
			do
			{
				cout << "--------------------------------------------------------------------------------------------" << endl;
				cout << "\t\t\t\t\tWelcome to Library Managment System" << endl;
				cout << "--------------------------------------------------------------------------------------------" << endl;
				cout << "1- Add a Book \n2- Delete a Book \n3- Search a Book \n4- Update  Book Details \n5- Display All Library Records \n6- Exit \nPlease make a choice: "; cin >> userInput;
				cout << "--------------------------------------------------------------------------------------------" << endl;

				switch (userInput)
				{
				case'1':
				{
						   unsigned int bkID = 0, find = 0;
						   string BookTitle = "", name_1 = "", name_2 = "", name_3 = "";
						   do
						   {
							   cout << "--------------------------------------------------------------------------------------------" << endl;
							   cout << "1- Prepend a Book \n2- Append a Book  at End \n3- Add a Book After completing one book \n4- Exit \nPlease make a choice: "; cin >> userInput;
							   cout << "--------------------------------------------------------------------------------------------" << endl;
							   if (userInput == '1')
							   {
								   cout << "--------------------------------------------------------------------------------------------" << endl;
								   cout << "\t\t\t\t\t\t\tAllocating New Library Books" << endl;
								   cout << "--------------------------------------------------------------------------------------------" << endl;
								   cout << "Please enter Book ID: "; cin >> bkID;

								   if (!BooksList.isEmpty())
								   {
									   if (BooksList.duplicateBookID(bkID))
									   {
										   cout << "Sorry this ID is already assigned!" << endl;
									   }
									   else
									   {
										   cout << "Please enter book Title: "; cin.ignore(); getline(cin, BookTitle);
										   cout << "Please enter Name of Member 1: "; cin.ignore(); getline(cin, name_1);
										   cout << "Please enter Name of Member 2: "; cin.ignore(); getline(cin, name_2);
										   cout << "Please enter Name of Member 3: "; cin.ignore(); getline(cin, name_3);

										   BooksList.prependNode(bkID, BookTitle, name_1, name_2, name_3);
									   }
								   }
								   else
								   {
									   cout << "Please enter book Title: "; cin.ignore(); getline(cin, BookTitle);
									   cout << "Please enter Name of Member 1: "; cin.ignore(); getline(cin, name_1);
									   cout << "Please enter Name of Member 2: "; cin.ignore(); getline(cin, name_2);
									   cout << "Please enter Name of Member 3: "; cin.ignore(); getline(cin, name_3);

									   BooksList.prependNode(bkID, BookTitle, name_1, name_2, name_3);
								   }
							   }
							   else if (userInput == '2')
							   {
								   cout << "--------------------------------------------------------------------------------------------" << endl;
								   cout << "\t\t\t\t\t\t\t\t\tAllocating New Library Books" << endl;
								   cout << "--------------------------------------------------------------------------------------------" << endl;
								   cout << "Please enter Book ID: "; cin >> bkID;

								   if (!BooksList.isEmpty())
								   {
									   if (BooksList.duplicateBookID(bkID))
									   {
										   cout << "Sorry this ID is already assigned!" << endl;
									   }
									   else
									   {
										   cout << "Please enter book Title: "; cin.ignore(); getline(cin, BookTitle);
										   cout << "Please enter Name of Member 1: "; cin.ignore(); getline(cin, name_1);
										   cout << "Please enter Name of Member 2: "; cin.ignore(); getline(cin, name_2);
										   cout << "Please enter Name of Member 3: "; cin.ignore(); getline(cin, name_3);

										   BooksList.appendNode(bkID, BookTitle, name_1, name_2, name_3);
									   }
								   }
								   else
								   {
									   cout << "Please enter book Title: "; cin.ignore(); getline(cin, BookTitle);
									   cout << "Please enter Name of Member 1: "; cin.ignore(); getline(cin, name_1);
									   cout << "Please enter Name of Member 2: "; cin.ignore(); getline(cin, name_2);
									   cout << "Please enter Name of Member 3: "; cin.ignore(); getline(cin, name_3);

									   BooksList.appendNode(bkID, BookTitle, name_1, name_2, name_3);
								   }
							   }
							   else if (userInput == '3')
							   {
								   cout << "--------------------------------------------------------------------------------------------" << endl;
								   cout << "\t\t\t\t\t\t\t\t\tAllocating New Library Books" << endl;
								   cout << "--------------------------------------------------------------------------------------------" << endl;
								   cout << "Please enter Book ID to be found: "; cin >> find;

								   if (!BooksList.isEmpty())
								   {
									   if (BooksList.searchNode(find))
									   {
										   cout << "Please enter Book ID for New Books: "; cin >> bkID;

										   if (BooksList.duplicateBookID(bkID))
										   {
											   cout << "Sorry this ID is already assigned!" << endl;
										   }
										   else
										   {
											   cout << "Please enter Book Title for New Book: "; cin.ignore(); getline(cin, BookTitle);
											   cout << "Please enter Name of Member 1 for New Book: "; cin.ignore(); getline(cin, name_1);
											   cout << "Please enter Name of Member 2 for New Book: "; cin.ignore(); getline(cin, name_2);
											   cout << "Please enter Name of Member 3 for New Book: "; cin.ignore(); getline(cin, name_3);

											   BooksList.addNodeAfter(find, bkID, BookTitle, name_1, name_2, name_3);
										   }
									   }
									   else
									   {
										   cout << "Sorry node not found!" << endl;
									   }
								   }
								   else
								   {
									   cout << "Please enter Book Title for New Books: "; cin.ignore(); getline(cin, BookTitle);
									   cout << "Please enter Name of Member 1 for New Book: "; cin.ignore(); getline(cin, name_1);
									   cout << "Please enter Name of Member 2 for New Book: "; cin.ignore(); getline(cin, name_2);
									   cout << "Please enter Name of Member 3 for New Book: "; cin.ignore(); getline(cin, name_3);

									   BooksList.addNodeAfter(find, bkID, BookTitle, name_1, name_2, name_3);
								   }
							   }
							   else if (userInput > '4')
							   {
								   cout << "Invalid Choice!" << endl;
							   }
						   } while (userInput != '4');
				}
					break;
				case'2':
				{
						   cout << "--------------------------------------------------------------------------------------------" << endl;
						   cout << "\t\t\t\t\t\t\tLibrary Records Deletion" << endl;
						   cout << "--------------------------------------------------------------------------------------------" << endl;
						   unsigned int find = 0;
						   cout << "Please enter Book ID to be deleted: "; cin >> find;
						   BooksList.deleteNode(find);
				}
					break;
					/*case'3':
					{
					cout << "--------------------------------------------------------------------------------------------" << endl;
					cout << "\t\t\t\t\t\t\t\t\tSearching a Book ID and Name" << endl;
					cout << "--------------------------------------------------------------------------------------------" << endl;
					unsigned int find = 0;
					cout << "Please enter Book ID to be searched: "; cin >> find;

					Node* tempNode = BooksList.searchNode(find);

					if (tempNode == nullptr)
					cout << "NO Book records Found!" << endl;
					else
					{
					cout << "-------------------------------" << endl;
					cout << "\t\tProject Found!" << endl;
					cout << "-------------------------------" << endl;
					cout << "Project ID: " << tempNode->BookID << endl;
					cout << "Project Title: " << tempNode->BookTitle << endl;
					cout << "Group Member 1: " << tempNode->studentOneName << endl;
					cout << "Group Member 2: " << tempNode->studentTwoName << endl;
					cout << "Group Member 3: " << tempNode->studentThreeName << endl;
					}
					}
					break;*/
				case'4':
				{
						   cout << "--------------------------------------------------------------------------------------------" << endl;
						   cout << "\t\t\t\t\t\t\tLibrary Record Updation" << endl;
						   cout << "--------------------------------------------------------------------------------------------" << endl;
						   unsigned int find = 0;
						   cout << "Please enter Book ID to update: "; cin >> find;
						   BooksList.updateExistingNode(find);
				}
					break;
				case'5':
				{
						   cout << "--------------------------------------------------------------------------------------------" << endl;
						   cout << "\t\t\t\t\t\t\tAllocated Records" << endl;
						   cout << "--------------------------------------------------------------------------------------------" << endl;
						   if (BooksList.isEmpty())
							   cout << "List is empty, consider adding Library Records first!" << endl;
						   else
							   BooksList.traverse();
				}
					break;

				case'6':
					if (userInput > '6');
					{
						//cout << "Invalid Choice!" << endl;
						break;
					}
				}
			} while (userInput != '6');
		}
		break;
	    if (username == "user" && password == "user")
		{
			cout << "--------------------------------------------------------------------------------------------" << endl;
			cout << "\t\t\t\tSearching a Book ID and Name" << endl;
			cout << "--------------------------------------------------------------------------------------------" << endl;
			unsigned int find = 0;
			cout << "Please enter Book ID to be searched: "; cin >> find;

			Node* tempNode = BooksList.searchNode(find);

			if (tempNode == nullptr)
				cout << "NO Book records Found!" << endl;
			else
			{
				cout << "-------------------------------" << endl;
				cout << "\t\tProject Found!" << endl;
				cout << "-------------------------------" << endl;
				cout << "Project ID: " << tempNode->BookID << endl;
				cout << "Project Title: " << tempNode->BookTitle << endl;
				cout << "Group Member 1: " << tempNode->studentOneName << endl;
				cout << "Group Member 2: " << tempNode->studentTwoName << endl;
				cout << "Group Member 3: " << tempNode->studentThreeName << endl;
			}
		}
		else
		{
			cout << "Invalid username or password" << endl;
		}
		}
	while (userInput != '6');
	system("pause");
	return 0;
}		
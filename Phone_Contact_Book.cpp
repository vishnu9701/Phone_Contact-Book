#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Node
{
    string name;
    long long int phone_number;
    Node *next;
    Node *prev;
};

class ContactBook
{
    Node *head;
    string x;
    long long int y;

public:
    ContactBook()
    {
        head = NULL;
        x = "";
        y = 0;
    }
    void CreateNode()
    {
        Node *newer = new Node;
        cout << "  Name of Contact: ";
        cin >> x;
        newer->name = x;
        cout << "  Phone Number: ";
        cin >> y;
        newer->phone_number = y;

        newer->next = NULL;

        if (head == NULL)
        {
            newer->prev == NULL;
            head = newer;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newer;
            newer->prev = temp;
        }
         cout << "  Contact Added" << endl;
    }

    void Display()
    {
        Node *temp = head;
        int count = 0;

        if (temp == NULL)
        {
            cout << "  No Contacts... Please Add Some Contacts" << endl;
            cout << "  Thanks" << endl;
        }
        else
        {
            BubbleSort(); // For Sorting The Name in A-Z .
            cout << "  Name: "
                 << "      Number: \n"
                 << endl;
            while (temp != NULL)
            {
                count++;
                cout << "  " << temp->name;
                cout << "          " << temp->phone_number << endl;
                temp = temp->next;
            }
            cout << "  Total contacts: " << count << endl;
        }
    }

    int Search()
    {
        bool found = false;
        Node *temp = head;
        cout << "************************" << endl;
        cout << "  Press 1 if you want to Search By Name." << endl;
        cout << "  Press 2 if you want to Search By Number." << endl;
        int option;
        cout << "  Enter the choice: ";
        cin >> option;

        if (option == 1 && temp != NULL)
        {
            cout << "  Enter the Name to Search: ";
            cin >> x;

            for (temp = head; temp != NULL && temp->name == x; temp = temp->next)
            {
                cout << "*******************" << endl;
                cout << "  Name: " << temp->name << endl;
                cout << "  Phone Number:" << temp->phone_number << endl;
                cout << "*******************" << endl;
                found = true;
                break;
            }
            if (found == false)
            {
                cout << "  Name Not Found" << endl;
            }
        }
        else if (option == 2)
        {
            cout << "  Enter the Number to Search: ";
            cin >> y;

            for (temp = head; temp != NULL && temp->phone_number == y; temp = temp->next)
            {
                cout << "*******************" << endl;
                cout << "  Name: " << temp->name << endl;
                cout << "  Phone Number: " << temp->phone_number << endl;
                cout << "*******************" << endl;
                found = true;
                break;
            }
            if (found == false)
            {
                cout << "  Number Not Found" << endl;
            }
        }
    }

    void DeleteAllContacts()
    {
        Node *temp = head;
        Node *del;
        if (head == NULL)
        {
            cout << "  Already Contact Book is Empty" << endl;
            cout << "*******************" << endl;
        }
        else
        {
            for (temp = head; temp != NULL; temp = temp->next)
            {
                del = temp;
                delete del;
            }
            head = NULL;
            cout << "  Successfully Deleted All Contacts" << endl;
            cout << "*******************" << endl;
        }
    }

    int DeleteContactBySearch()
    {
        Node *temp = head;
        cout << "*******************" << endl;
        cout << "  Press 1 if you want to Search By name" << endl;
        cout << "  Press 2 if you want to Search By Number" << endl;
        int option;
        cout << "  Enter the Option: ";
        cin >> option;

        if (option == 1)
        {
            bool found = false;
            cout << "  Enter the Name to Delete: ";
            cin >> x;

            for (temp = head; temp != NULL && temp->name == x; temp = temp->next)
            {
                cout << "*******************" << endl;
                cout << "  Name: " << temp->name << endl;
                cout << "  Phone Number: " << temp->phone_number << endl;
                cout << "*******************" << endl;
                found = true;
                break;
            }
            if (found == true)
            {
                int ready;
                cout << "  Press 1 to Delete the Contact: ";
                cin >> ready;

                if (ready == 1 & temp == head)
                {
                    Node *del;
                    del = temp;
                    temp = temp->next;
                    delete del;

                    temp->prev = NULL;
                    head = temp;
                    cout << "  Contact Deleted Success Fully" << endl;
                }
                else if (ready == 1 & temp->next == NULL)
                {
                    temp->prev->next = NULL;
                    delete temp;
                    cout << "  Contact Deleted Success Fully" << endl;
                }
                else if (ready == 1)
                {
                    Node *del;
                    del = temp;
                    temp->prev->next = del->next;
                    temp->next->prev = del->prev;
                    delete del;
                    cout << "  Contact Deleted Success Fully" << endl;
                }
                else
                {
                    cout << "  You Enter Wrong Option ... Try Again" << endl;
                }
            }
            else if (found == false)
            {
                cout << "  Contact of This Name Not Found." << endl;
            }
        }
        else if (option == 2)
        {
            bool found = false;
            cout << "  Enter the Number to Delete: ";
            cin >> y;

            for (temp = head; temp != NULL && temp->phone_number == y; temp = temp->next)
            {
                cout << "*******************" << endl;
                cout << "name: " << temp->name << endl;
                cout << "Phone Number: " << temp->phone_number << endl;
                cout << "*******************" << endl;
                found = true;
                break;
            }
            if (found == true)
            {
                int ready;
                cout << "  Press 1 to Delete the Contact: ";
                cin >> ready;
                if (ready == 1 & temp == head)
                {
                    Node *del;
                    del = temp;
                    temp = temp->next;
                    delete del;

                    temp->prev = NULL;
                    head = temp;
                    cout << "  Contact Deleted Success Fully" << endl;
                }
                else if (ready == 1 & temp->next == NULL)
                {
                    temp->prev->next = NULL;
                    delete temp;
                    cout << "  Contact Deleted Success Fully" << endl;
                }
                else if (ready == 1)
                {
                    Node *del;
                    del = temp;
                    temp->prev->next = del->next;
                    temp->next->prev = del->prev;
                    delete del;
                    cout << "  Contact Deleted Success Fully" << endl;
                }
                else
                {
                    cout << "  You Enter Wrong Option ... Try Again" << endl;
                }
            }
            else if (found == false)
            {
                cout << "  Contact of This Name Not Found." << endl;
            }
        }
        else
        {
            cout << "  You Enter Option" << endl;
        }
    }

    void BubbleSort()
    {
        Node *temp = head;
        Node *i, *j;
        string n;
        long long int n2;
        if (temp = NULL)
        {
            cout << "  Empty contact Book" << endl;
        }
        else
        {
            for (i = head; i->next != NULL; i = i->next)
            {
                for (j = i->next; j != NULL; j = j->next)
                {
                    if (i->name > j->name)
                    {
                        n = i->name;
                        i->name = j->name;
                        j->name = n;

                        n2 = i->phone_number;
                        i->phone_number = j->phone_number;
                        j->phone_number = n2;
                    }
                }
            }
        }
    }

    int EditContacts()
    {
        Node *temp = head;
        cout << "*******************" << endl;
        cout << "  Press 1 if you want to Search By Name" << endl;
        cout << "  Press 2 if you want to Search By Number" << endl;
        int option;
        cout << "  Enter the Option: ";
        cin >> option;

        if (option == 1)
        {
            bool found = false;
            cout << "  Enter the Name to Edit: ";
            cin >> x;

            for (temp = head; temp != NULL && temp->name == x; temp = temp->next)
            {
                cout << "*******************" << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Phone Number: " << temp->phone_number << endl;
                cout << "*******************" << endl;
                found = true;
                break;
            }

            if (found == true)
            {
                int ready;
                cout << "  Press 1 to Edit the Contact: ";
                cin >> ready;
                if (ready == 1)
                {
                    cout << "  Enter New Name: ";
                    cin >> x;
                    cout << "  Enter New Number: ";
                    cin >> y;

                    temp->name = x;
                    temp->phone_number = y;

                    cout << "  Contact Edited Success Fully" << endl;
                }
                else
                {
                    cout << "  You Enter Wrong Option ... Try Again" << endl;
                }
            }
            else if (found == false)
            {
                cout << "  Contact Not Found" << endl;
            }
        }
        else if (option == 2)
        {
            bool found = false;
            cout << "  Enter the Number to Edit: ";
            cin >> y;

            for (temp = head; temp != NULL && temp->phone_number == y; temp = temp->next)
            {
                cout << "*******************" << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Phone Number: " << temp->phone_number << endl;
                cout << "*******************" << endl;
                found = true;
            }
            if (found == true)
            {
                int ready;
                cout << "  Press 1 to Edit the Contact: ";
                cin >> ready;
                if (ready == 1)
                {
                    cout << "  Enter New Name: ";
                    cin >> x;
                    cout << "  Enter New Number: ";
                    cin >> y;

                    temp->name = x;
                    temp->phone_number = y;

                    cout << "  Contact Edited Success Fully" << endl;
                }
                else
                {
                    cout << "  You Enter Wrong Option" << endl;
                }
            }
            else if (found == false)
            {
                cout << "  There is No Contact of this Number." << endl;
            }
        }
        else
        {
            cout << "  You Enter Wrong Option ... Try Again" << endl;
        }
    }

    void OflineSave()
    {
        Node *temp = head;
        ofstream myfile("Contact_Book.txt");
        if (myfile.is_open())
        {
            for (temp = head; temp != NULL; temp = temp->next)
            {
                myfile << temp->name << endl;
                myfile << temp->phone_number << endl;
            }
            myfile.close();
            Structure();
        }
        else
        {
            cout << "  Thanks file is empty." << endl;
        }
    }

    void reopenCB()
    {
        bool isEmpty;
        ifstream myfile("Contact_Book.txt");
        if (myfile.is_open() & myfile.peek() != EOF)
        {
            int i = 0;
            while (getline(myfile, x))
            {
                if (i % 2 == 0)
                {
                    if (head == NULL)
                    {
                        Node *newer = new Node;
                        newer->name = x;

                        newer->next = NULL;
                        newer->prev == NULL;
                        head = newer;
                    }
                    else
                    {
                        Node *newer = new Node;

                        newer->name = x;
                        newer->next = NULL;

                        Node *temp = head;
                        while (temp->next != NULL)
                        {
                            temp = temp->next;
                        }
                        temp->next = newer;
                        newer->prev = temp;
                    }
                }
                else
                {
                    Node *temp = head;
                    if (temp->phone_number == 0)
                    {

                        stringstream convert(x);
                        convert >> y;
                        temp->phone_number = y;
                    }
                    else
                    {
                        Node *temp = head;
                        while (temp->next != NULL)
                        {
                            temp = temp->next;
                        }

                        stringstream convert(x);
                        convert >> y;
                        temp->phone_number = y;
                    }
                }
                i++;
            }
            myfile.close();
        }
        else
        {
            cout << "  File is Empty so Cannot open...Sorry" << endl;
        }
    }
    void Structure()
    {
        cout << "*******************" << endl;
        cout << "  1. Add Contact" << endl;
        cout << "  2. Edit the Contact" << endl;
        cout << "  3. Delete Contact" << endl;
        cout << "  4. Search Contact" << endl;
        cout << "  5. Display All Contacts" << endl;
        cout << "  6. Delete All Contacts" << endl;
        cout << "*******************" << endl;

        int action;
        cout << "  Choose an Option: ";
        cin >> action;
        try
        {
            switch (action)
            {
            case 1:
            {
                CreateNode();
                OflineSave();
                Structure();
                break;
            }
            case 2:
            {
                EditContacts();
                OflineSave();
                Structure();
                break;
            }
            case 3:
            {
                DeleteContactBySearch();
                Structure();
                break;
            }
            case 4:
            {
                Search();
                Structure();
                break;
            }
            case 5:
            {
                Display();
                OflineSave();
                Structure();
                break;
            }
            case 6:
            {
                DeleteAllContacts();
                OflineSave();
                Structure();
                break;
            }
            default:
            {
                throw(action);
            }
            }
        }

        catch (int action)
        {
            cout << "  You have Choosed Wrong Option... Run the Code Again" << endl;
            Structure();
        }
    }
};

int main()
{
    ContactBook MyContacts;
    MyContacts.reopenCB();
    string name;
    cout << "  What is Your Name: ";
    cin >> name;

    cout << "*******************" << endl;
    cout << "  " << name << "  WELCOME TO CONTACT-BOOK     " << endl;
    cout << "*******************" << endl;
    MyContacts.Structure();
    return 0;
}

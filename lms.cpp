#include <iostream>
#include <conio.h>
using namespace std;

void bookaddition2(string book);
void welcomeScreen();
void header2();
void person(); // Giving prototypes for the functions.
void startUpAdmin();
void startUpUser();
void loginAdmin();
void loginUser();
void signUpAdmin();
void signUpUser();
void homepage();
void mainMenuAdmin();
void mainMenuUser();
void bookList(int number);
void bookAddition(string book);
void bookUpdate();
void bookDelete();
void purchase();
void reserve();

const int size = 100;
int passWord[size]; // We declare the arrays globally
string username[size];
int choice;
const int SIZE = 10;
string books[SIZE] = {"The_Alchemist", "The_Red_Pot", "Peer_e_Kaamil", "Jannat_k_pattay", "Harry_Potter_The_Series", "Forty_Rules_of_love", "", "", "", ""};

main()
{
    welcomeScreen(); // calling the welcome screen function to start the application.
    header2();
    person();
}

void person()
{

    cout << "Press (1) for admin: " << endl; // if 1 is entered as the choice, the admin will use the application.
    cout << "Press (2) for user: " << endl;  // if 2 is entered as the choice, the user will use the application.

    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 1)
    {
        system("cls");
        header2();
        startUpAdmin();
    }
    if (choice == 2)
    {
        system("cls");
        header2();
        startUpUser();
    }

    else if (choice != 1 || choice != 2) // if invalid input, i.e other than 1 or 2, is put ,please re-enter the choice.
    {
        cout << "WRONG CHOICE ENTERED. Try Again!" << endl;
        person();
    }
}

void startUpAdmin()
{

    cout << "Press (1) to login: " << endl;   // When 1 is entered, it shows the menu for login.
    cout << "Press (2) to Sign Up: " << endl; // When 2 is entered, it shows the menu for signup.
    cout << "Press (3) to go back" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        system("cls");
        header2();
        loginAdmin();
    }
    else if (choice == 2)
    {
        system("cls");
        header2();
        signUpAdmin();
    }

    else if (choice == 3)
    {
        system("cls");
        header2();
        person();
    }
    else
    {
        cout << "you have entered invalid choice please enter again" << endl;
        system("cls");
        header2();
        startUpAdmin();
    }
}
void loginAdmin()
{
    string user;
    int password;
    cout << "Enter your username: " << endl; // to login admin has to enter the username
    cin >> user;

    cout << "Enter your password: " << endl; // to login admin has to enter the password
    cin >> password;

    for (int i = 0; i < 100; i++)
    {
        if (user == username[i] && password == passWord[i])
        {
            cout << "log in";
            homepage();
            mainMenuAdmin();
            break;
        }
        else
        {
            cout << "User already exists!" << endl;
            getch();
            system("cls");
            header2();
            startUpAdmin();
        }
    }
}
void signUpAdmin()
{
    string user;
    int password, confirmPassword;
    cout << "Enter your username: " << endl; // user
    cin >> user;

    for (int x = 0; x < 100; x++)
    {
        if (user != username[x])
        {
            cout << "enter password:" << endl;
            cin >> password;
            cout << "confirm password:" << endl;
            cin >> confirmPassword;

            if (confirmPassword == password)
            {
                username[x] = user;
                passWord[x] = password;
                cout << "User registered" << endl;

                break;
            }
            else
            {
                cout << "password didnt match" << endl; // if the admin entered different passwords while confirming passwords they will have to put it again
                signUpAdmin();
            }
        }
        else
        {
            cout << "username already exist";
            break;
        }
    }
    system("cls");
    header2();
    startUpAdmin();
}

void mainMenuAdmin()
{
    int number;
    string book;
    welcomeScreen();
    header2();

    cout << "Press (1) to View list of books" << endl;
    cout << "Press (2) to Add a book" << endl;
    cout << "Press (3) to Update a book" << endl;
    cout << "Press (4) to Delete a book" << endl;
    cout << "Press (5) to Reserve a book" << endl;
    cout << "Press (6) to Purchase a book" << endl;
    cout << "Press (7) to Logout" << endl;

    cout << "Enter your choice: " << endl;
    cin >> choice;

    if (choice == 1)
    {
        system("cls");
        welcomeScreen();
        header2();
        bookList(number);
    }
    else if (choice == 2)
    {
        system("cls");
        welcomeScreen();
        header2();
        bookaddition2(book);
    }
    else if (choice == 3)
    {
        system("cls");
        welcomeScreen();
        header2();
        bookUpdate();
    }
    else if (choice == 4)
    {
        system("cls");
        welcomeScreen();
        header2();
        bookDelete();
    }
}

void bookList(int number)
{
    int count = 6; // there are already 6 books present in the library

    cout << "                       WELCOME TO THE LIBRARY!                                   " << endl;
    cout << "The following is the list of the books present in our library: " << endl;

    for (int x = 0; x < count; x++)
    {
        cout << x << ": " << books[x] << endl;
    }
    cout << "Press any number to go back to the main menu....... " << endl;
    cin >> number;
    mainMenuAdmin();
}
void bookaddition2(string book)
{
    int NumOfBookAdd;
    int count = 6;
    cout << " Enter the nummber of books you want to add";
    cin >> NumOfBookAdd;
    if (count > NumOfBookAdd && (count + NumOfBookAdd) < 10)
    {
        for (int x = count; x < (count + NumOfBookAdd); x++)
        {
            cout << "ADD a book" << endl;
            cin >> book; // book added without spaces
            books[x] = book;
            cout << "A new book " << book << "  has been add to the library!!!!" << endl;
        }
    }
    else if ((count + NumOfBookAdd) > 10)
    {
        cout << "  only 10 books can be added to the library" << endl;
    }
    for (int x = 0; x < SIZE; x++)
    {
        cout << x + 1 << ":" << books[x] << endl;
    }
}

void bookAdditon(string book)
{
    int NumOfBookAdd;
    int count = 6;

    cout << "Enter the number of books you want to add: ";
    cin >> NumOfBookAdd;

    if (count > NumOfBookAdd && NumOfBookAdd <= 10) // only 10 books can be added to the library
    {
        for (int x = count; x < NumOfBookAdd; x++)
        {
            cout << "Add a Book: " << endl;
            cin >> book;
            books[x] = book;
            cout << "A new book " << book << "has been added to the library!" << endl;
        }
    }
    else if (NumOfBookAdd > 10)
    {
        cout << "ONLY 10 BOOKS CAN BE ADDED TO THE LIBRARY!" << endl;
    }
    for (int x = 0; x < count; x++)
    {
        cout << x << ": " << books[x] << endl;
    }
}

void bookUpdate()
{
    string book, newbook;
    int count = 6;
    cout << "the lists of books is " << endl;
    for (int x = 0; x < count; x++)
    {

        cout << x << ": " << books[x] << endl;
    }
    cout << "Enter the book you want to update: " << endl;
    cin >> book;

    for (int x = 0; x < SIZE; x++)
    {
        if (books[x] == book)
        {
            cout << "enter the updated name of the book" << endl;
            cin >> newbook;
            books[x] = newbook;
            cout << "the name has been updated" << endl;
            break;
        }
        else
        {
            if (x == SIZE)
            {
                cout << "The book doesn't exist in the library!";
                bookUpdate();
            }
            else
            {
                continue;
            }
        }
    }
    for (int x = 0; x < count; x++)
    {
        cout << "the list of books after update is" << endl;
        cout << x << ": " << books[x] << endl;
    }
}

void bookDelete()
{
    string book, deletebook;
    int count = 6;
    cout << "the lists of books is " << endl;
    for (int x = 0; x < count; x++)
    {

        cout << x << ": " << books[x] << endl;
    }

    cout << "enter the name of the book you want to delete: " << endl;
    cin >> deletebook;
    for (int x = 0; x < SIZE; x++)
    {
        if (books[x] == deletebook)
        {
            books[x] = "";
            cout << "the name has been deleted" << endl;
            break;
        }
        else
        {
            if (x == SIZE)
            {
                cout << "The book doesn't exist in the library!";
                bookUpdate();
            }
            else
            {
                continue;
            }
        }
    }
    cout << "the list of books after deleting the book is" << endl;
    for (int x = 0; x < count; x++)
    {
        if (books[x] != "")
        {
            cout << x << ": " << books[x] << endl;
        }
    }
}

void startUpUser()
{
    cout << "Press (1) to login: " << endl;   // When 1 is entered, it shows the menu for login.
    cout << "Press (2) to Sign Up: " << endl; // When 2 is entered, it shows the menu for signup.
    cout << "Press (3) to go back" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        system("cls");
        header2();
        loginUser();
    }
    else if (choice == 2)
    {
        system("cls");
        header2();
        signUpUser();
    }

    else if (choice == 3)
    {
        system("cls");
        header2();
        person();
    }
    else
    {
        cout << "you have entered invalid choice please enter again" << endl;
        system("cls");
        header2();
        startUpUser();
    }
}

void loginUser()
{
    string user;
    int password;
    cout << "Enter your username: " << endl; // to login user has to enter the username
    cin >> user;

    cout << "Enter your password: " << endl; // to login user has to enter the password
    cin >> password;

    for (int i = 0; i < 100; i++)
    {
        if (user == username[i] && password == passWord[i])
        {
            cout << "log in";
            homepage();
            mainMenuUser();
            break;
        }
        else
        {
            cout << "User already exists!" << endl;
            getch();
            system("cls");
            header2();
            startUpUser();
        }
    }
}

void signUpUser()
{
    string user;
    int password, confirmPassword;
    cout << "Enter your username: " << endl; // user
    cin >> user;

    for (int x = 0; x < 100; x++)
    {
        if (user != username[x])
        {
            cout << "enter password:" << endl;
            cin >> password;
            cout << "confirm password:" << endl;
            cin >> confirmPassword;

            if (confirmPassword == password)
            {
                username[x] = user;
                passWord[x] = password;
                cout << "User registered" << endl;

                break;
            }
            else
            {
                cout << "password didnt match" << endl; // if the user entered different passwords while confirming passwords they will have to put it again
                signUpUser();
            }
        }
        else
        {
            cout << "username already exist";
            break;
        }
    }
    system("cls");
    header2();
    startUpUser();
}

void mainMenuUser()
{
    int number;
    cout << "Press (1) if you want to see the books list" << endl;
    cout << "Press (2) if you want to Purchase a book from the library" << endl;
    cout << "Press (3) if you want to Reserve a book from the library" << endl;

    cout << "Enter your choice: " << endl;
    cin >> choice;

    if (choice == 1)
    {
        system("cls");
        welcomeScreen();
        header2();
        bookList(number);
    }
    if (choice == 2)
    {
        system("cls");
        header2();
        purchase();
    }
    if (choice == 3)
    {
        system("cls");
        header2();
        reserve();
    }
}

void purchase()
{
    string book, purchaseBook;
    int count = 6;
    float price, number;
    cout << "the lists of books is " << endl; // this will show the list of the books present in the library
    for (int x = 0; x < count; x++)
    {

        cout << x << ": " << books[x] << endl;
    }

    cout << "PRICE FOR EACH BOOK IS 120$." << endl;

    cout << "Enter the number of books you want to purchase: " << endl;
    cin >> number;

    for(int x = 0; x < number ; x++)
    {
    cout << "enter the name of the book you want to Purchase: " << endl;
    cin >> purchaseBook;
    }

    price = number * 120;

    cout << "YOUR BOOK HAS BEEN PURCHASED FOR: " << price << "$" << endl;

    cout << "Press 1 to go back to the main menu: ";
    cin >> number;
    if (number == 1)
    {
        mainMenuUser();
    }
    else
    {
         cout << "WRONG NUMBER ENTERED, PLEASE TRY AGAIN: " << endl;
         cout << "Press 1 to go back to the main menu: " << endl;
         cin >> number;
    }

}

void reserve()
{
    string book;
    int number;

    cout << "Enter the number of books you want to reserve: " << endl;
    cin >> number;
    for (int x = 0; x < number; x++)
    {
        cout << "Enter the name of the book you want to reserve: " << endl;
        cin >> book;
    }

    cout << "Your book has been reserved!" << endl;

}

void welcomeScreen()
{

    cout << " __| |__________________________________________________________________________________| |__     " << endl;
    cout << "(__   __________________________________________________________________________________   __)    " << endl;
    cout << "   | |                                                                                  | |       " << endl;
    cout << "           __...--~~~~~-._  _.-~~~~~--...__                                                       " << endl;
    cout << "         //               `V'              \\            LIBRARY                                  " << endl;
    cout << "        //                 |                \\          MANAGEMENT                                " << endl;
    cout << "       //__...--~~~~~~-._  | _.-~~~~~~--...__\\           SYSTEM                                  " << endl;
    cout << "      //__.....----~~~~._  |  _.~~~~----....._\\                                                  " << endl;
    cout << "     ====================\\|//====================                                                " << endl;
    cout << "                         `---`                                                                    " << endl;
    cout << " __| |__________________________________________________________________________________| |__     " << endl;
    cout << "(__   __________________________________________________________________________________   __)    " << endl;
    cout << "   | |                                                                                  | |       " << endl;
}

void header2()
{

    cout << " ***************************************************************************************************  " << endl;
    cout << " ***************************************************************************************************  " << endl;
    cout << " *                                                                                                 *  " << endl;
    cout << " *                                 Library Management System                                       *  " << endl;
    cout << " *                                                                                                 *  " << endl;
    cout << " ***************************************************************************************************  " << endl;
    cout << " ***************************************************************************************************  " << endl;
}

void homepage()
{

    cout << " ***************************************************************************************************  " << endl;
    cout << " ***************************************************************************************************  " << endl;
    cout << " *    *     *                                                                          *     *     *  " << endl;
    cout << " *       *    *   *                                                              *   *    *        *  " << endl;
    cout << " *          *   *   *                      LIBRARY                             *   *   *           *  " << endl;
    cout << " *             *  *  *                    MANAGEMENT                          *  *  *              *  " << endl;
    cout << " *                 *  *                     SYSTEM                           *  *                  *  " << endl;
    cout << " *                   **                                                      **                    *  " << endl;
    cout << " *                    *                                                      *                     *  " << endl;
    cout << " *                                                                                                 *  " << endl;
    cout << " ***************************************************************************************************  " << endl;
    cout << " ***************************************************************************************************  " << endl;
}

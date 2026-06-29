//1. Declare a structure named Person with the following details. First Name, Last Name, Age, Salary and a function named show to print the information of a person.
#include <iostream>
using namespace std;

struct Person {
    string firstName;
    string lastName;
    int age;
    double salary;

    // Function to display details
    void show() {
        cout << "First Name: " << firstName << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Person p;

    // Input
    cout << "Enter First Name: ";
    cin >> p.firstName;
    cout << "Enter Last Name: ";
    cin >> p.lastName;
    cout << "Enter Age: ";
    cin >> p.age;
    cout << "Enter Salary: ";
    cin >> p.salary;

    // Output
    cout << "\nPerson Details:\n";
    p.show();

    return 0;
}


// 2. Declare a class named Person with the previous information.
#include <iostream>
using namespace std;

class Person {
private:
    string firstName;
    string lastName;
    int age;
    double salary;

public:
    // Function to take input
    void input() {
        cout << "Enter First Name: ";
        cin >> firstName;
        cout << "Enter Last Name: ";
        cin >> lastName;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    // Function to display details
    void show() {
        cout << "First Name: " << firstName << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Person p;

    p.input();

    cout << "\nPerson Details:\n";
    p.show();

    return 0;
}

// 3. Find the Euclidean distancc between two coordinates P1(5,6) and P2(10, 12).
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int x1=3, x2=4, y1=5, y2=7;
    double euc = sqrt(pow((x2-x1),2) + pow((y2-y1),2));
    cout<<"The Eucledian distabce is: "<< euc;
    return 0;
}


//-----------------------------Assignment-3(classes and object)---------------------------------------

//1. Create a class Vector to represent vector (a series of float values). Define member functions outside the class definition to perform the following tasks: (a) to create the vector (b) to modify the value of a given element (c) to display the vector in the form (10.5, 20.4, 30.7, ...) (d) to add two vectors and display the resultant vector.
#include <iostream>
using namespace std;

class Vector {
private:
    float arr[100];
    int size;

public:
    // Function to create vector
    void createVector();

    // Function to modify an element
    void modifyElement(int index, float value);

    // Function to display vector
    void displayVector();

    // Function to add two vectors
    Vector addVector(Vector v);
};

// ================= Function Definitions Outside Class =================

// Create Vector
void Vector::createVector() {
    cout << "Enter number of elements: ";
    cin >> size;

    cout << "Enter vector elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

// Modify element
void Vector::modifyElement(int index, float value) {
    if (index >= 0 && index < size) {
        arr[index] = value;
    } else {
        cout << "Invalid index!\n";
    }
}

// Display vector
void Vector::displayVector() {
    cout << "(";
    for (int i = 0; i < size; i++) {
        cout << arr[i];

        if (i != size - 1)
            cout << ", ";
    }
    cout << ")";
}

// Add two vectors
Vector Vector::addVector(Vector v) {
    Vector temp;

    if (size != v.size) {
        cout << "\nVector sizes must be equal!\n";
        temp.size = 0;
        return temp;
    }

    temp.size = size;

    for (int i = 0; i < size; i++) {
        temp.arr[i] = arr[i] + v.arr[i];
    }

    return temp;
}

// ================= Main Function =================

int main() {
    Vector v1, v2, result;

    cout << "Create First Vector\n";
    v1.createVector();

    cout << "\nCreate Second Vector\n";
    v2.createVector();

    cout << "\nFirst Vector = ";
    v1.displayVector();

    cout << "\nSecond Vector = ";
    v2.displayVector();

    // Modify an element
    cout << "\n\nModifying first element of First Vector to 100.5\n";
    v1.modifyElement(0, 100.5);

    cout << "Modified First Vector = ";
    v1.displayVector();

    // Add vectors
    result = v1.addVector(v2);

    cout << "\n\nResultant Vector after Addition = ";
    result.displayVector();

    cout << endl;

    return 0;
}

//2. Create a class called Time that has separate data member for hours, minutes and seconds. Write a member function to display the time in the format hh: mm: ss. Write another member function to add two objects of type Time passed as arguments. Write a program to test the class and its functions.
#include <iostream>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;

public:
    // Function to input time
    void setTime(int h, int m, int s);

    // Function to display time
    void displayTime();

    // Function to add two Time objects
    Time addTime(Time t);
};

// ============ Function Definitions Outside Class ============

// Set Time
void Time::setTime(int h, int m, int s) {
    hours = h;
    minutes = m;
    seconds = s;
}

// Display Time
void Time::displayTime() {
    cout << hours << " : " << minutes << " : " << seconds;
}

// Add Two Time Objects
Time Time::addTime(Time t) {
    Time temp;

    temp.seconds = seconds + t.seconds;
    temp.minutes = minutes + t.minutes;
    temp.hours = hours + t.hours;

    // Convert extra seconds into minutes
    if (temp.seconds >= 60) {
        temp.minutes += temp.seconds / 60;
        temp.seconds = temp.seconds % 60;
    }

    // Convert extra minutes into hours
    if (temp.minutes >= 60) {
        temp.hours += temp.minutes / 60;
        temp.minutes = temp.minutes % 60;
    }

    return temp;
}

// ================= Main Function =================

int main() {
    Time t1, t2, result;

    // Set first time
    t1.setTime(2, 45, 50);

    // Set second time
    t2.setTime(3, 20, 30);

    cout << "First Time  = ";
    t1.displayTime();

    cout << "\nSecond Time = ";
    t2.displayTime();

    // Add two times
    result = t1.addTime(t2);

    cout << "\n\nSum of Time = ";
    result.displayTime();

    cout << endl;

    return 0;
}

//3. Define a class Account to represent a bank account. Include the following members. Data members: Name of the depositor, Account number, Account type, Balance amount in the account. Member functions: To assign initial values, To deposit an amount, To withdraw an amount after checking the balance, To display name and balance, To display customer details. Write a program to test the program for a given number of customers. The program should be able to search any customer if the account number is provided.
#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string depositorName;
    int accountNumber;
    string accountType;
    float balance;

public:
    // Function to assign initial values
    void assignValues();

    // Function to deposit amount
    void depositAmount(float amount);

    // Function to withdraw amount
    void withdrawAmount(float amount);

    // Function to display name and balance
    void displayNameBalance();

    // Function to display all customer details
    void displayCustomerDetails();

    // Function to return account number
    int getAccountNumber();
};

// ============== Function Definitions Outside Class ==============

// Assign Initial Values
void Account::assignValues() {
    cout << "Enter Depositor Name: ";
    cin.ignore();
    getline(cin, depositorName);

    cout << "Enter Account Number: ";
    cin >> accountNumber;

    cout << "Enter Account Type: ";
    cin >> accountType;

    cout << "Enter Initial Balance: ";
    cin >> balance;
}

// Deposit Amount
void Account::depositAmount(float amount) {
    balance += amount;
    cout << "Amount Deposited Successfully.\n";
}

// Withdraw Amount
void Account::withdrawAmount(float amount) {
    if (amount <= balance) {
        balance -= amount;
        cout << "Withdrawal Successful.\n";
    } else {
        cout << "Insufficient Balance!\n";
    }
}

// Display Name and Balance
void Account::displayNameBalance() {
    cout << "\nDepositor Name : " << depositorName;
    cout << "\nBalance Amount : " << balance << endl;
}

// Display Customer Details
void Account::displayCustomerDetails() {
    cout << "\n----- Customer Details -----\n";
    cout << "Depositor Name : " << depositorName << endl;
    cout << "Account Number : " << accountNumber << endl;
    cout << "Account Type   : " << accountType << endl;
    cout << "Balance Amount : " << balance << endl;
}

// Return Account Number
int Account::getAccountNumber() {
    return accountNumber;
}

// ====================== Main Function ======================

int main() {
    int n;

    cout << "Enter Number of Customers: ";
    cin >> n;

    Account customers[100];

    // Input customer details
    for (int i = 0; i < n; i++) {
        cout << "\nEnter Details for Customer " << i + 1 << endl;
        customers[i].assignValues();
    }

    // Deposit and Withdraw Example
    customers[0].depositAmount(5000);
    customers[0].withdrawAmount(2000);

    // Display Name and Balance
    customers[0].displayNameBalance();

    // Search Customer by Account Number
    int searchAccNo;
    bool found = false;

    cout << "\n\nEnter Account Number to Search: ";
    cin >> searchAccNo;

    for (int i = 0; i < n; i++) {
        if (customers[i].getAccountNumber() == searchAccNo) {
            customers[i].displayCustomerDetails();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Customer Not Found!" << endl;
    }

    return 0;
}

// 4. Create two classes DM and DB which store the value of distances. DM stores distances in metres and centimeters and DB in feet and inches. Write a program that can read values for the class objects and add one object of DM with another object of DB. Use a friend function to carry out the addition operation. The object that stores the result may be a DM object or a DB object, depending on the units in which the results are required. The display should be done in the format of feet and inches or meters and centimeters depending on the object on display.
#include <iostream>
using namespace std;

class DB; // Forward declaration

// ================= Class DM =================
class DM {
private:
    int meter, centimeter;

public:
    void getDM();
    void displayDM();

    // Friend function
    friend void addDistance(DM, DB);
};

// ================= Class DB =================
class DB {
private:
    int feet, inches;

public:
    void getDB();
    void displayDB();

    // Friend function
    friend void addDistance(DM, DB);
};

// ================= Function Definitions =================

// Input distance in meters and centimeters
void DM::getDM() {
    cout << "Enter distance in meters and centimeters:\n";
    cin >> meter >> centimeter;
}

// Display DM object
void DM::displayDM() {
    cout << meter << " meters " << centimeter << " centimeters\n";
}

// Input distance in feet and inches
void DB::getDB() {
    cout << "Enter distance in feet and inches:\n";
    cin >> feet >> inches;
}

// Display DB object
void DB::displayDB() {
    cout << feet << " feet " << inches << " inches\n";
}

// Friend function to add distances
void addDistance(DM d1, DB d2) {

    // Convert DM into centimeters
    float totalCM1 = (d1.meter * 100) + d1.centimeter;

    // Convert DB into centimeters
    // 1 inch = 2.54 cm
    float totalCM2 = ((d2.feet * 12) + d2.inches) * 2.54;

    // Total distance in centimeters
    float totalCM = totalCM1 + totalCM2;

    int choice;

    cout << "\nDisplay Result In:\n";
    cout << "1. Meters and Centimeters\n";
    cout << "2. Feet and Inches\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {

        // Convert to meters and centimeters
        int meter = totalCM / 100;
        float centimeter = totalCM - (meter * 100);

        cout << "\nResult = ";
        cout << meter << " meters "
             << centimeter << " centimeters\n";
    }

    else if (choice == 2) {

        // Convert centimeters to inches
        float totalInches = totalCM / 2.54;

        int feet = totalInches / 12;
        float inches = totalInches - (feet * 12);

        cout << "\nResult = ";
        cout << feet << " feet "
             << inches << " inches\n";
    }

    else {
        cout << "Invalid Choice!\n";
    }
}

// ================= Main Function =================

int main() {

    DM d1;
    DB d2;

    d1.getDM();
    d2.getDB();

    cout << "\nDistance in DM format: ";
    d1.displayDM();

    cout << "Distance in DB format: ";
    d2.displayDB();

    // Add distances using friend function
    addDistance(d1, d2);

    return 0;
}

//-------------------------------Assignment-4(Constructors & Destructors)----------------------------------------

//1. Create a class Queue to implement queue data structure with constructors & destructors. Define suitable member functions for insertion & deletion of elements to & from the queue. Write a program clearly specifying the overflow & underflow conditions.
#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int front, rear, size;

public:
    // Constructor
    Queue(int s);

    // Destructor
    ~Queue();

    // Insert element
    void enqueue(int value);

    // Delete element
    void dequeue();

    // Display queue
    void display();
};

// ================= Constructor =================
Queue::Queue(int s) {
    size = s;
    arr = new int[size];

    front = -1;
    rear = -1;

    cout << "Queue Created Successfully.\n";
}

// ================= Destructor =================
Queue::~Queue() {
    delete[] arr;
    cout << "Queue Destroyed Successfully.\n";
}

// ================= Insert Element =================
void Queue::enqueue(int value) {

    // Overflow Condition
    if (rear == size - 1) {
        cout << "Queue Overflow! Cannot insert more elements.\n";
        return;
    }

    // First insertion
    if (front == -1)
        front = 0;

    rear++;
    arr[rear] = value;

    cout << value << " inserted into queue.\n";
}

// ================= Delete Element =================
void Queue::dequeue() {

    // Underflow Condition
    if (front == -1 || front > rear) {
        cout << "Queue Underflow! Queue is empty.\n";
        return;
    }

    cout << arr[front] << " deleted from queue.\n";
    front++;

    // Reset queue when empty
    if (front > rear) {
        front = rear = -1;
    }
}

// ================= Display Queue =================
void Queue::display() {

    if (front == -1) {
        cout << "Queue is Empty.\n";
        return;
    }

    cout << "Queue Elements: ";

    for (int i = front; i <= rear; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// ================= Main Function =================
int main() {

    int size, choice, value;

    cout << "Enter Queue Size: ";
    cin >> size;

    Queue q(size);

    do {
        cout << "\n===== QUEUE MENU =====\n";
        cout << "1. Insert Element\n";
        cout << "2. Delete Element\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter Value to Insert: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}

// 2. Create a class DATE such that- a. It can output the date in multiple formats such as – i. DD-MM-YYYY ii. MM/DD/YY iii. MON, DD, YYYY b. Use overloaded constructors with the following format – i. DD-MM-YYYY ii. Default constructor with predefined date.
#include <iostream>
#include <iomanip>
using namespace std;

class DATE {
private:
    int day, month, year;

public:
    // Default Constructor
    DATE();

    // Parameterized Constructor
    DATE(int d, int m, int y);

    // Display in DD-MM-YYYY format
    void displayFormat1();

    // Display in MM/DD/YY format
    void displayFormat2();

    // Display in MON, DD, YYYY format
    void displayFormat3();
};

// ================= Constructor Definitions =================

// Default Constructor
DATE::DATE() {
    day = 1;
    month = 1;
    year = 2025;
}

// Parameterized Constructor
DATE::DATE(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

// ================= Display Functions =================

// DD-MM-YYYY
void DATE::displayFormat1() {
    cout << setw(2) << setfill('0') << day << "-"
         << setw(2) << setfill('0') << month << "-"
         << year;
}

// MM/DD/YY
void DATE::displayFormat2() {
    cout << setw(2) << setfill('0') << month << "/"
         << setw(2) << setfill('0') << day << "/"
         << year % 100;
}

// MON, DD, YYYY
void DATE::displayFormat3() {

    string months[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN",
                       "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

    cout << months[month - 1] << ", "
         << setw(2) << setfill('0') << day
         << ", " << year;
}

// ================= Main Function =================

int main() {

    int d, m, y;

    // Using Default Constructor
    DATE d1;

    // Taking User Input
    cout << "Enter Day Month Year: ";
    cin >> d >> m >> y;

    // Using Parameterized Constructor
    DATE d2(d, m, y);

    cout << "\nDefault Date Formats:\n";

    cout << "\n1. DD-MM-YYYY : ";
    d1.displayFormat1();

    cout << "\n2. MM/DD/YY   : ";
    d1.displayFormat2();

    cout << "\n3. MON, DD, YYYY : ";
    d1.displayFormat3();

    cout << "\n\nUser Entered Date Formats:\n";

    cout << "\n1. DD-MM-YYYY : ";
    d2.displayFormat1();

    cout << "\n2. MM/DD/YY   : ";
    d2.displayFormat2();

    cout << "\n3. MON, DD, YYYY : ";
    d2.displayFormat3();

    cout << endl;

    return 0;
}

// 3. Define a class UserString that could work as a user-defined string type. Include constructors that will enable us to create an uninitialized string String s1; // string with length 0 and also to initialize an object with a string constant at the time of creation like String s2 (“Well Done”); Include a function that adds two strings to make a third string. Note that the statement s2 = s1; will be perfectly reasonable expression to copy one string to another. Write a complete program to test your class to see that it does the following tasks: (a) Creates uninitialized string objects (b) Creates objects with string constants (c) Concatenates two strings properly (d) Displays a desired string object.
#include <iostream>
#include <cstring>
using namespace std;

class UserString {
private:
    char str[100];

public:
    // Default Constructor
    UserString();

    // Parameterized Constructor
    UserString(char s[]);

    // Function to concatenate strings
    UserString addString(UserString s);

    // Function to display string
    void display();
};

// ================= Constructor Definitions =================

// Default Constructor
UserString::UserString() {
    strcpy(str, "");
}

// Parameterized Constructor
UserString::UserString(char s[]) {
    strcpy(str, s);
}

// ================= Member Functions =================

// Concatenate two strings
UserString UserString::addString(UserString s) {

    UserString temp;

    strcpy(temp.str, str);
    strcat(temp.str, s.str);

    return temp;
}

// Display String
void UserString::display() {
    cout << str;
}

// ================= Main Function =================

int main() {

    char s1[100], s2[100];

    // Uninitialized String Object
    UserString obj1;

    cout << "Enter First String: ";
    cin.getline(s1, 100);

    cout << "Enter Second String: ";
    cin.getline(s2, 100);

    // Objects with string constants
    UserString obj2(s1);
    UserString obj3(s2);

    // Concatenation
    UserString obj4 = obj2.addString(obj3);

    // Copy one string to another
    obj1 = obj2;

    cout << "\nFirst String Object : ";
    obj2.display();

    cout << "\nSecond String Object : ";
    obj3.display();

    cout << "\nCopied String Object : ";
    obj1.display();

    cout << "\nConcatenated String : ";
    obj4.display();

    cout << endl;

    return 0;
}


//--------------------------------Assignment-5(Operator and Overloading)-----------------------------------

// 1. Create a class Matrix to implement a matrix of size m x n. Write a program to overload * operator for multiplying two matrix objects. Do this with friend function & without friend function.

//without friend function
#include <iostream>
using namespace std;

class Matrix {
private:
    int a[10][10];
    int row, col;

public:
    void getMatrix();
    void display();

    Matrix operator*(Matrix m);
};

// Input Matrix
void Matrix::getMatrix() {
    cout << "Enter number of rows and columns: ";
    cin >> row >> col;

    cout << "Enter Matrix Elements:\n";
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> a[i][j];
}

// Display Matrix
void Matrix::display() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
}

// Operator Overloading
Matrix Matrix::operator*(Matrix m) {

    Matrix result;

    if (col != m.row) {
        cout << "Matrix multiplication not possible.\n";
        result.row = result.col = 0;
        return result;
    }

    result.row = row;
    result.col = m.col;

    for (int i = 0; i < result.row; i++) {
        for (int j = 0; j < result.col; j++) {

            result.a[i][j] = 0;

            for (int k = 0; k < col; k++)
                result.a[i][j] += a[i][k] * m.a[k][j];
        }
    }

    return result;
}

int main() {

    Matrix A, B, C;

    cout << "Enter First Matrix\n";
    A.getMatrix();

    cout << "\nEnter Second Matrix\n";
    B.getMatrix();

    C = A * B;

    cout << "\nResultant Matrix:\n";
    C.display();

    return 0;
}
//with friend function
#include <iostream>
using namespace std;

class Matrix {
private:
    int a[10][10];
    int row, col;

public:
    void getMatrix();
    void display();

    friend Matrix operator*(Matrix, Matrix);
};

// Input Matrix
void Matrix::getMatrix() {

    cout << "Enter number of rows and columns: ";
    cin >> row >> col;

    cout << "Enter Matrix Elements:\n";

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> a[i][j];
}

// Display Matrix
void Matrix::display() {

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
}

// Friend Function
Matrix operator*(Matrix m1, Matrix m2) {

    Matrix result;

    if (m1.col != m2.row) {
        cout << "Matrix multiplication not possible.\n";
        result.row = result.col = 0;
        return result;
    }

    result.row = m1.row;
    result.col = m2.col;

    for (int i = 0; i < result.row; i++) {
        for (int j = 0; j < result.col; j++) {

            result.a[i][j] = 0;

            for (int k = 0; k < m1.col; k++)
                result.a[i][j] += m1.a[i][k] * m2.a[k][j];
        }
    }

    return result;
}

int main() {

    Matrix A, B, C;

    cout << "Enter First Matrix\n";
    A.getMatrix();

    cout << "\nEnter Second Matrix\n";
    B.getMatrix();

    C = A * B;

    cout << "\nResultant Matrix:\n";
    C.display();

    return 0;
}

// 2. Repeat exercise 11 for String class and overload the = = operator to compare two strings and display which string’s length is more and by how much(<=).
#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char str[100];

public:
    // Default Constructor
    String();

    // Parameterized Constructor
    String(char s[]);

    // Display String
    void display();

    // Concatenate Strings
    String operator+(String s);

    // Overload == operator
    void operator==(String s);
};

// ================= Constructor Definitions =================

// Default Constructor
String::String() {
    strcpy(str, "");
}

// Parameterized Constructor
String::String(char s[]) {
    strcpy(str, s);
}

// ================= Display Function =================

void String::display() {
    cout << str;
}

// ================= Concatenation Operator =================

String String::operator+(String s) {

    String temp;

    strcpy(temp.str, str);
    strcat(temp.str, s.str);

    return temp;
}

// ================= == Operator Overloading =================

void String::operator==(String s) {

    int len1 = strlen(str);
    int len2 = strlen(s.str);

    if (len1 == len2) {
        cout << "Both strings have equal length (" << len1 << ")." << endl;
    }
    else if (len1 > len2) {
        cout << "First string is longer by "
             << (len1 - len2) << " characters." << endl;
    }
    else {
        cout << "Second string is longer by "
             << (len2 - len1) << " characters." << endl;
    }
}

// ================= Main Function =================

int main() {

    char s1[100], s2[100];

    cout << "Enter First String: ";
    cin.getline(s1, 100);

    cout << "Enter Second String: ";
    cin.getline(s2, 100);

    String str1(s1);
    String str2(s2);

    cout << "\nFirst String : ";
    str1.display();

    cout << "\nSecond String: ";
    str2.display();

    // Concatenation
    String str3 = str1 + str2;

    cout << "\nConcatenated String: ";
    str3.display();

    cout << "\n\nComparing String Lengths...\n";
    str1 == str2;

    return 0;
}

// 3. Write a program in C++ to overload +=, -=, *= and /= operators for a COMPLEX class.
#include <iostream>
using namespace std;

class Complex {
private:
    float real, imag;

public:
    // Constructor
    Complex(float r = 0, float i = 0);

    // Input Function
    void getData();

    // Display Function
    void display();

    // Operator Overloading
    void operator += (Complex c);
    void operator -= (Complex c);
    void operator *= (Complex c);
    void operator /= (Complex c);
};

// ================= Constructor =================

Complex::Complex(float r, float i) {
    real = r;
    imag = i;
}

// ================= Input Function =================

void Complex::getData() {
    cout << "Enter Real Part: ";
    cin >> real;

    cout << "Enter Imaginary Part: ";
    cin >> imag;
}

// ================= Display Function =================

void Complex::display() {
    if (imag >= 0)
        cout << real << " + " << imag << "i";
    else
        cout << real << " - " << -imag << "i";
}

// ================= += Operator =================

void Complex::operator += (Complex c) {
    real += c.real;
    imag += c.imag;
}

// ================= -= Operator =================

void Complex::operator -= (Complex c) {
    real -= c.real;
    imag -= c.imag;
}

// ================= *= Operator =================

void Complex::operator *= (Complex c) {

    float r = (real * c.real) - (imag * c.imag);
    float i = (real * c.imag) + (imag * c.real);

    real = r;
    imag = i;
}

// ================= /= Operator =================

void Complex::operator /= (Complex c) {

    float denominator = (c.real * c.real) + (c.imag * c.imag);

    float r = ((real * c.real) + (imag * c.imag)) / denominator;
    float i = ((imag * c.real) - (real * c.imag)) / denominator;

    real = r;
    imag = i;
}

// ================= Main Function =================

int main() {

    Complex c1, c2;

    cout << "Enter First Complex Number\n";
    c1.getData();

    cout << "\nEnter Second Complex Number\n";
    c2.getData();

    // +=
    Complex temp1 = c1;
    temp1 += c2;
    cout << "\nAfter += : ";
    temp1.display();

    // -=
    Complex temp2 = c1;
    temp2 -= c2;
    cout << "\nAfter -= : ";
    temp2.display();

    // *=
    Complex temp3 = c1;
    temp3 *= c2;
    cout << "\nAfter *= : ";
    temp3.display();

    // /=
    Complex temp4 = c1;
    temp4 /= c2;
    cout << "\nAfter /= : ";
    temp4.display();

    cout << endl;

    return 0;
}



//-----------------------------Assignment-6(Inheritance)-------------------------------------

//1. Assume that a bank maintains two kinds of accounts for customers, one called as savings account and the other is current account. The savings account provides simple interest and withdrawal facilities. The current account provides no interest. Current account holders should also maintain a minimum balance and if the balance falls below this level, a service charge is imposed. Create a class Account that stores customer name, account number and type of account. From this derive the classes CurAcc and SavAcc to make them more specific to their requirements. Include necessary member functions in order to achieve the following tasks: (a) Accept deposit from a customer and update the balance (b) Display the balance (c) Compute and deposit interest. (d) Permit withdrawal and update balance (e) Check for minimum balance, impose penalty, if necessary and update the balance.
#include <iostream>
#include <string>
using namespace std;

// Base Class
class Account
{
protected:
    string customerName;
    int accountNumber;
    string accountType;
    double balance;

public:
    void createAccount(string name, int accNo, string type, double bal)
    {
        customerName = name;
        accountNumber = accNo;
        accountType = type;
        balance = bal;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited Amount = " << amount << endl;
    }

    void displayBalance()
    {
        cout << "Current Balance = Rs. " << balance << endl;
    }
};

// Derived Class for Savings Account
class SavAcc : public Account
{
private:
    double interestRate;

public:
    void setInterestRate(double rate)
    {
        interestRate = rate;
    }

    void computeInterest()
    {
        double interest = (balance * interestRate) / 100;
        balance += interest;

        cout << "Interest Added = Rs. " << interest << endl;
        cout << "Balance after Interest = Rs. " << balance << endl;
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal Successful." << endl;
        }
        else
        {
            cout << "Insufficient Balance!" << endl;
        }
    }
};

// Derived Class for Current Account
class CurAcc : public Account
{
private:
    const double minBalance = 1000;
    const double penalty = 100;

public:
    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal Successful." << endl;
            checkMinimumBalance();
        }
        else
        {
            cout << "Insufficient Balance!" << endl;
        }
    }

    void checkMinimumBalance()
    {
        if (balance < minBalance)
        {
            cout << "Balance below minimum balance!" << endl;
            cout << "Penalty of Rs. " << penalty << " imposed." << endl;
            balance -= penalty;
        }
    }
};

int main()
{
    cout << "===== Savings Account =====" << endl;

    SavAcc s;
    s.createAccount("Rahul", 101, "Savings", 5000);
    s.displayBalance();

    s.deposit(2000);
    s.displayBalance();

    s.setInterestRate(5);
    s.computeInterest();

    s.withdraw(1000);
    s.displayBalance();

    cout << "\n===== Current Account =====" << endl;

    CurAcc c;
    c.createAccount("Amit", 201, "Current", 3000);
    c.displayBalance();

    c.deposit(1000);
    c.displayBalance();

    c.withdraw(3500);
    c.displayBalance();

    return 0;
}

// 2. Consider a class network in which the class Master derives pay information from Accountclass and experience information from Admin class which in turn derive the employee name and empid information from the class Person. Define all the four classes and write a program to create, update and display the information stored in Master object.
#include <iostream>
#include <string>
using namespace std;

// Base Class
class Person
{
protected:
    string empName;
    int empId;

public:
    void setPerson(string name, int id)
    {
        empName = name;
        empId = id;
    }
};

// Derived Class 1
class Account : virtual public Person
{
protected:
    float pay;

public:
    void setPay(float p)
    {
        pay = p;
    }
};

// Derived Class 2
class Admin : virtual public Person
{
protected:
    int experience;

public:
    void setExperience(int exp)
    {
        experience = exp;
    }
};

// Derived Class 3
class Master : public Account, public Admin
{
public:
    void createRecord(string name, int id, float salary, int exp)
    {
        setPerson(name, id);
        setPay(salary);
        setExperience(exp);
    }

    void updateSalary(float salary)
    {
        pay = salary;
    }

    void updateExperience(int exp)
    {
        experience = exp;
    }

    void display()
    {
        cout << "\nEmployee Details" << endl;
        cout << "-----------------" << endl;
        cout << "Employee Name : " << empName << endl;
        cout << "Employee ID   : " << empId << endl;
        cout << "Salary        : Rs. " << pay << endl;
        cout << "Experience    : " << experience << " Years" << endl;
    }
};

int main()
{
    Master m;

    // Create Record
    m.createRecord("Rahul Sharma", 101, 50000, 5);

    cout << "Initial Information:";
    m.display();

    // Update Information
    m.updateSalary(60000);
    m.updateExperience(6);

    cout << "\nAfter Updating Information:";
    m.display();

    return 0;
}

// 3. Design and implement the following classes Politician, Senator, Congress and Person. Senator and Congress are subclasses of Person (with data member name and phone number). A politician in addition to having a name and phone number has a party and a state. A senator has a rank (Junior / Senior). A Congress person has a unique id. Design the class hierarchy and they should include methods to initialize access and modify the data members of the object.
#include <iostream>
#include <string>
using namespace std;

// Base Class
class Person
{
protected:
    string name;
    string phone;

public:
    void setPerson(string n, string p)
    {
        name = n;
        phone = p;
    }

    void displayPerson()
    {
        cout << "Name         : " << name << endl;
        cout << "Phone Number : " << phone << endl;
    }
};

// Derived Class
class Politician : public Person
{
protected:
    string party;
    string state;

public:
    void setPolitician(string n, string p, string par, string st)
    {
        setPerson(n, p);
        party = par;
        state = st;
    }

    void displayPolitician()
    {
        displayPerson();
        cout << "Party        : " << party << endl;
        cout << "State        : " << state << endl;
    }
};

// Senator Class
class Senator : public Politician
{
private:
    string rank;

public:
    void setSenator(string n, string p, string par,
                    string st, string r)
    {
        setPolitician(n, p, par, st);
        rank = r;
    }

    void modifyRank(string r)
    {
        rank = r;
    }

    void display()
    {
        cout << "\n----- Senator Information -----" << endl;
        displayPolitician();
        cout << "Rank         : " << rank << endl;
    }
};

// Congress Class
class Congress : public Politician
{
private:
    int uniqueID;

public:
    void setCongress(string n, string p, string par,
                     string st, int id)
    {
        setPolitician(n, p, par, st);
        uniqueID = id;
    }

    void modifyID(int id)
    {
        uniqueID = id;
    }

    void display()
    {
        cout << "\n----- Congress Information -----" << endl;
        displayPolitician();
        cout << "Unique ID    : " << uniqueID << endl;
    }
};

int main()
{
    Senator s;
    Congress c;

    // Initialize objects
    s.setSenator("Rahul Sharma", "9876543210",
                 "Democratic", "California", "Junior");

    c.setCongress("Amit Roy", "9123456780",
                  "Republican", "Texas", 101);

    // Display initial details
    s.display();
    c.display();

    // Modify data
    s.modifyRank("Senior");
    c.modifyID(202);

    cout << "\nAfter Modification:" << endl;

    s.display();
    c.display();

    return 0;
}

// 4. Create a base class Shape. Use this class to store two double type values that could be used to store the dimensions to compute the area of the figures. Derive two classes named Triangle and Rectangle from the base class Shape. Design the class hierarchy and they should include methods to initialize, access and modify the data members of the object. Write a program that will accept dimensions of a triangle and rectangle object interactively and display the area. Remember the two values (dimensions) given as input will be treated as lengths of two sides in case of rectangle and as base and height in case of triangle.
#include <iostream>
using namespace std;

// Base Class
class Shape
{
protected:
    double dim1, dim2;

public:
    // Initialize dimensions
    void setDimensions(double d1, double d2)
    {
        dim1 = d1;
        dim2 = d2;
    }

    // Access dimensions
    double getDim1()
    {
        return dim1;
    }

    double getDim2()
    {
        return dim2;
    }

    // Modify dimensions
    void modifyDimensions(double d1, double d2)
    {
        dim1 = d1;
        dim2 = d2;
    }
};

// Derived Class: Triangle
class Triangle : public Shape
{
public:
    double area()
    {
        return 0.5 * dim1 * dim2;
    }
};

// Derived Class: Rectangle
class Rectangle : public Shape
{
public:
    double area()
    {
        return dim1 * dim2;
    }
};

int main()
{
    Triangle t;
    Rectangle r;

    double base, height;
    double length, breadth;

    // Input Triangle dimensions
    cout << "Enter base and height of Triangle: ";
    cin >> base >> height;

    t.setDimensions(base, height);

    // Input Rectangle dimensions
    cout << "Enter length and breadth of Rectangle: ";
    cin >> length >> breadth;

    r.setDimensions(length, breadth);

    // Display Areas
    cout << "\nArea of Triangle = "
         << t.area() << endl;

    cout << "Area of Rectangle = "
         << r.area() << endl;

    return 0;
}


//-----------------------------------Assignment-7(Templates)---------------------------------------

// 1. Write a function template for finding the minimum value contained in an array.
#include <iostream>
using namespace std;

// Function Template
template <class T>
T findMin(T arr[], int size)
{
    T min = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }

    return min;
}

int main()
{
    int intArr[] = {25, 10, 35, 5, 40};
    float floatArr[] = {4.5, 2.3, 8.1, 1.7, 6.2};

    cout << "Minimum element in Integer Array = "
         << findMin(intArr, 5) << endl;

    cout << "Minimum element in Float Array = "
         << findMin(floatArr, 5) << endl;

    return 0;
}

// 2. Write a class template to represent a generic vector. Include member functions to perform the following tasks: (a) To create the vector (b) To modify the value of a given element (c) To multiply by a scalar value (d) To display the vector in the form (10, 20, 30, ........).
#include <iostream>
using namespace std;

template <class T>
class Vector
{
    T v[100];
    int size;

public:
    // Create Vector
    void create()
    {
        cout << "Enter size of vector: ";
        cin >> size;

        cout << "Enter vector elements:\n";
        for(int i = 0; i < size; i++)
        {
            cin >> v[i];
        }
    }

    // Modify an element
    void modify(int pos, T value)
    {
        if(pos >= 0 && pos < size)
        {
            v[pos] = value;
        }
        else
        {
            cout << "Invalid Position!" << endl;
        }
    }

    // Multiply by scalar
    void scalarMultiply(T scalar)
    {
        for(int i = 0; i < size; i++)
        {
            v[i] = v[i] * scalar;
        }
    }

    // Display Vector
    void display()
    {
        cout << "(";
        for(int i = 0; i < size; i++)
        {
            cout << v[i];

            if(i != size - 1)
                cout << ", ";
        }
        cout << ")" << endl;
    }
};

int main()
{
    Vector<int> v;

    v.create();

    cout << "\nOriginal Vector: ";
    v.display();

    // Modify element
    v.modify(2, 50);

    cout << "After Modification: ";
    v.display();

    // Scalar Multiplication
    v.scalarMultiply(2);

    cout << "After Scalar Multiplication: ";
    v.display();

    return 0;
}

// 3. Create a generic Stack class and write push ( ), pop ( ), overflow ( ) and underflow ( ) functions. Test the class in a program.
#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
    T stack[10];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool overflow()
    {
        return (top == 9);
    }

    bool underflow()
    {
        return (top == -1);
    }

    void push(T item)
    {
        if (overflow())
        {
            cout << "Stack Overflow!" << endl;
            return;
        }

        stack[++top] = item;
        cout << item << " pushed into stack." << endl;
    }

    void pop()
    {
        if (underflow())
        {
            cout << "Stack Underflow!" << endl;
            return;
        }

        cout << stack[top] << " popped from stack." << endl;
        top--;
    }

    void display()
    {
        if (underflow())
        {
            cout << "Stack is Empty." << endl;
            return;
        }

        cout << "Stack Elements: ";
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.pop();
    s.display();

    s.pop();
    s.pop();
    s.pop(); // Underflow condition

    return 0;
}

// 4. Write a program in C++ using class template to read two matrices of different data types such as integers & floating point values and finds the sum of the matrices of integers and floating point number separately and displays the total sums of these arrays individually.
#include <iostream>
using namespace std;

template <class T>
class Matrix
{
private:
    T A[10][10], B[10][10], C[10][10];
    int rows, cols;

public:
    void readMatrix()
    {
        cout << "Enter number of rows and columns: ";
        cin >> rows >> cols;

        cout << "Enter elements of First Matrix:\n";
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> A[i][j];

        cout << "Enter elements of Second Matrix:\n";
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> B[i][j];
    }

    void addMatrix()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                C[i][j] = A[i][j] + B[i][j];
            }
        }
    }

    void displayResult()
    {
        T totalSum = 0;

        cout << "\nResultant Matrix:\n";

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << C[i][j] << "\t";
                totalSum += C[i][j];
            }
            cout << endl;
        }

        cout << "Total Sum of Matrix Elements = "
             << totalSum << endl;
    }
};

int main()
{
    cout << "===== INTEGER MATRICES =====\n";

    Matrix<int> intMat;
    intMat.readMatrix();
    intMat.addMatrix();
    intMat.displayResult();

    cout << "\n===== FLOAT MATRICES =====\n";

    Matrix<float> floatMat;
    floatMat.readMatrix();
    floatMat.addMatrix();
    floatMat.displayResult();

    return 0;
}

// 5. Write a program in C++ to read a set of numbers up to n, where n is defined by the user & print the contents of the array in the reverse order using a class template.
#include <iostream>
using namespace std;

template <class T>
class ReverseArray
{
private:
    T arr[100];
    int n;

public:
    void readArray()
    {
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }

    void displayReverse()
    {
        cout << "\nElements in Reverse Order:\n";

        for (int i = n - 1; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    ReverseArray<int> obj;

    obj.readArray();
    obj.displayReverse();

    return 0;
}

// 6. Write a program in C++ to implement Insertion sort using function template.
#include <iostream>
using namespace std;

// Function Template for Insertion Sort
template <class T>
void insertionSort(T arr[], int n)
{
    T key;
    int j;

    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Function Template to Display Array
template <class T>
void display(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\nOriginal Array: ";
    display(arr, n);

    insertionSort(arr, n);

    cout << "Sorted Array: ";
    display(arr, n);

    return 0;
}
/**
 * birthdays.cpp
 * Project UID: 59fc568b7f83f8c109ae360f448f7f821ba0a71
 * 
 * Khanh Gia Nguyen
 * kgnguyen
 *
 * EECS 183: Project 2
 *
 * Returns the user's day of birth given their birthday as the input,
 * or returns the next 10 leap years from the year inputed.
 */

#include <cmath>
#include <iostream>
#include <string>

using namespace std;


/**
 * REQUIRES: nothing
 * MODIFIES: cout
 * EFFECTS:  Prints out the initial heading for the program
 */
void printHeading();


/**
 * REQUIRES: nothing
 * MODIFIES: cout
 * EFFECTS:  Prints out the final greeting for the program
 */
void printCloser();


/**
 * REQUIRES: nothing
 * MODIFIES: cout 
 * EFFECTS:  Prints the menu text. Does not read from cin.
 */
void printMenu();

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: nothing
 * MODIFIES: cout, cin
 * EFFECTS:     1. Prints the menu
 *           2. Reads the input from the user
 *           3. Checks to make sure the input is within range for the menu
 *              If not prints "Invalid menu choice"
 *           4. Continues to print the menu and read an input until 
 *              a valid one is entered
 *           5. Returns the user's choice of menu options
 * 
 *           This function must call printMenu().
 */
int getMenuChoice();

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: month, day, year represent a valid date
 * MODIFIES: nothing
 * EFFECTS:  Returns true if the date is in the limits
 *           of the Gregorian calendar otherwise returns false
 *           See the spec for definition of "limits of the Gregorian calendar"
 */
bool isGregorianDate(int month, int day, int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: year is a Gregorian year
 * MODIFIES: nothing
 * EFFECTS:  returns true if the year is a leap year
 *           otherwise returns false.
 *           See the spec for definition of a leap year.
 */
bool isLeapYear(int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: month, day, year may represent a date
 * MODIFIES: nothing
 * EFFECTS:  returns true if the date is valid
 *           otherwise returns false
 *           See the spec for definition of "valid"
 */
bool isValidDate(int month, int day, int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: month, day, year is a valid date
 *           i.e., the date passed to this function has already passed
 *               isValidDate()
 * MODIFIES: nothing
 * EFFECTS:  returns the value f that Zeller's formula calculates
 */
int determineDay(int month, int day, int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: day is a value of f output by Zeller's formula
*            (0 represents Saturday, 1 Sunday, 2 Monday, 3 Tuesday, etc)
 * MODIFIES: cout
 * EFFECTS:  prints the day of the week corresponding to day, suchas
 *           "Sunday", "Monday", ..., "Saturday"
 */
void printDayOfBirth(int day);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: nothing
 * MODIFIES: cout, cin
 * EFFECTS:  Asks for the month / day / year of the user's birthday.
 *           If the date is valid, it will print the day
 *           of the week you were born on
 *           Otherwise, it will print "Invalid date" prompt.
 */
void determineDayOfBirth();

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: nothing
 * MODIFIES: cin, cout
 * EFFECTS:  Asks for a Gregorian year and prints the
 *           10 leap years after (not including) the year entered.
 *           If the year is invalid, it prints nothing.
 *
 *           This function must call isLeapYear().
 */
void print10LeapYears();

/* 
 * EFFECTS: Main driver for the Birthdays program. See the
 *          "Putting it Together" section of the spec for what
 *          this function needs to accomplish.
 */
void birthdays() {
    
    // Print the heading and get user choice from the menu
    printHeading();
    int choice = getMenuChoice();
    
    // Determine which function based on input choice
    while (choice != 3) {
        if (choice == 1) {
            determineDayOfBirth();
        } else if (choice == 2) {
            print10LeapYears();
        }
        choice = getMenuChoice();
    }
    printCloser();
}


void printHeading() {
    cout << "*******************************" << endl
         << "      Birthday Calculator      " << endl
         << "*******************************" << endl << endl;
    return;
}


void printCloser() {
    cout << endl;
    cout << "****************************************************" << endl
         << "      Thanks for using the Birthday Calculator      " << endl
         << "****************************************************" << endl
         << endl;
    return;
}


void printMenu() {
    cout << endl;
    cout << "Menu Options" << endl
         << "------------" << endl;
    cout << "1) Determine day of birth" << endl;
    cout << "2) Print the next 10 leap years" << endl;
    cout << "3) Finished" << endl << endl;
    
    cout << "Choice --> ";
}

int getMenuChoice() {
    printMenu();
    int choice;
   
    // Check if the input is within 1-3. Otherwise, print the menu
    // and get the user input again
    while (cin >> choice && (choice < 1 || choice > 3)) {
        cout << "Invalid menu choice" << endl;
        printMenu();
    }
   
    return choice;
}

bool isGregorianDate(int month, int day, int year) {
    if (year < 1752) {
        return false;
    }
    
    if (year == 1752) {
        if ((month < 9) || (month == 9 && day < 14)) {
            return false;
        }
    }
    
    return true;
}

bool isLeapYear(int year) {
    
    // Check if the year is divisible by 4. If it is also divisible by 100
    // check if it's divisible by 400
    if ((year % 4 != 0) || (year % 100 == 0 && year % 400 != 0)) {
        return false;
    }
    
    return true;
}

bool isValidDate(int month, int day, int year) {
    if (!isGregorianDate(month, day, year)) {
        return false;
    }
    
    if ((month < 1) || (month > 12)) {
        return false;
    }
    
    // Check the input date for months with 31 days
    if ((month == 1) || (month == 3) || (month == 5) || (month == 7) ||
        (month == 8) || (month == 10) || (month == 12)) {
        if ((day < 1) || (day > 31)) {
            return false;
        }
    }
    
    // Check the input date for months with 30 days
    if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
        if ((day < 1) || (day > 30)) {
            return false;
        }
    }
    
    // Check for leap year
    if (month == 2) {
        if (isLeapYear(year)) {
            if ((day < 0) || (day > 29)) {
                return false;
            }
        } else {
            if ((day < 0) || (day > 28)) {
                return false;
            }
        }
    }
    
    return true;
}


int determineDay(int month, int day, int year) {
    int f;
    int century;
    int yearAdjusted;
    
    // Convert January and February to Zeller's calendar
    if ((month == 1) || (month == 2)) {
        month += 12;
        year -= 1;
    }
    
    // Get the first two digits of the year
    century = year / 100;
    
    // Get the last two digits of the year
    yearAdjusted = year - century * 100;
    
    // Apply Zeller's formula
    f = (day + (13 * (month + 1) / 5) + yearAdjusted +
        (yearAdjusted / 4) + (century / 4) + 5 * century) % 7;
    
    return f;
}

void printDayOfBirth(int day) {
    if (day == 0) {
        cout << "Saturday";
    } else if (day == 1) {
        cout << "Sunday";
    } else if (day == 2) {
        cout << "Monday";
    } else if (day == 3) {
        cout << "Tuesday";
    } else if (day == 4) {
        cout << "Wednesday";
    } else if (day == 5) {
        cout << "Thursday";
    } else if (day == 6) {
        cout << "Friday";
    }
}


void determineDayOfBirth() {
    int month;
    int day;
    int year;
    
    // Define a placeholder char for storing the '/' character
    char slashHolder;
    
    cout << "Enter your date of birth" << endl;
    cout << "format: month / day / year  -->  ";
    cin >> month >> slashHolder >> day >> slashHolder >> year;
    
    if (!isValidDate(month, day, year)) {
        cout << "Invalid date" << endl;
    } else {
        cout << "You were born on a: ";
        printDayOfBirth(determineDay(month, day, year));
        cout << endl;
        cout << "Have a great birthday!!!" << endl;
    }
}

void print10LeapYears() {
    int year;
    int count = 0;
    
    cout << "Enter year --> ";
    cin >> year;
    
    // Add 1 to start with the following year
    year++;
    
    if (year >= 1752) {
        while (count < 10) {
            if (isLeapYear(year)) {
                cout << "Leap year is " << year << endl;
                count++;
            }
            year++;
        }
    }
}

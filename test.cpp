/**
 * test.cpp
 * Project UID: d27ac2f9d9ef51141f8207ca61bd9b22d96076f1
 * 
 * Khanh Gia Nguyen
 * kgnguyen
 *
 * EECS 183: Project 2
 *
 * Testing functions for your birthdays.cpp implementation.
 * Holds the definitions of required testing functions.
 * We have stubbed all required functions for you.
 */

#include <cassert>
#include <cctype>
#include <iostream>
#include <limits>
#include <string>

using namespace std;


//************************************************************************
// You should have implemented the following functions in birthdays.cpp
//************************************************************************
int getMenuChoice();
bool isLeapYear (int year);
bool isGregorianDate(int m, int d, int y);
bool isValidDate(int month, int day, int year);
int determineDay (int month, int day, int year);
void printDayOfBirth(int day);
void determineDayOfBirth();
void print10LeapYears();

//************************************************************************
// Testing function declarations. Function definition is below main.
// Tests not run by these functions will not be run by the autograder.
//************************************************************************
void test_getMenuChoice();
void test_isGregorianDate();
void test_isLeapYear();
void test_isValidDate();
void test_determineDay();
void test_printDayOfBirth();
void test_determineDayOfBirth();
void test_print10LeapYears();

void startTests()
{
    test_getMenuChoice();
    test_isGregorianDate();
    test_isLeapYear();
    test_isValidDate();
    test_determineDay();
    test_printDayOfBirth();
    test_determineDayOfBirth();
    test_print10LeapYears();
}

void test_getMenuChoice()
{
    cout << "Now testing funtion getMenuChoice()\n";
    cout << "Please enter 1:" << endl;
    int choice1 = getMenuChoice();
    cout << "Test result: expected: 1, actual: " << choice1 << endl << endl;
    
    cout << "Please enter 2:" << endl;
    int choice2 = getMenuChoice();
    cout << "Test result: expected: 2, actual: " << choice2 << endl << endl;
    
    cout << "Please enter 3:" << endl;
    int choice3 = getMenuChoice();
    cout << "Test result: expected: 3, actual: " << choice3 << endl << endl;

    cout << "Please enter 5 then 1:";
    int choice4 = getMenuChoice();
    cout << "Test result: " << endl;
    cout << "Expected: \"Invalid menu choice\", then 1." << endl;
    cout << "Actual: " << choice4 << endl << endl;
    
    cout << "Please enter 0 then 2:";
    int choice5 = getMenuChoice();
    cout << "Test result: " << endl;
    cout << "Expected: \"Invalid menu choice\", then 2." << endl;
    cout << "Actual: " << choice5 << endl << endl;
    
    cout << "Please enter -1 then 3:";
    int choice6 = getMenuChoice();
    cout << "Test result: " << endl;
    cout << "Expected: \"Invalid menu choice\", then 3." << endl;
    cout << "Actual: " << choice6 << endl << endl;
    
    cout << "Please enter 0, 10 then 1:";
    int choice7 = getMenuChoice();
    cout << "Test result: " << endl;
    cout << "Expected: \"Invalid menu choice\", \"Invalid menu choice\""
         << "and then 3." << endl;
    cout << "Actual: " << choice7 << endl << endl;

}

void test_isGregorianDate()
{
    // isGregorianDate does not read from cin, so
    // all its tests can be run automatically
    cout << "Now testing function isGregorianDate()\n";
    cout << "9/2/2019:  Expected: 1, Actual: " 
         << isGregorianDate(9, 2, 2019) << endl;
    cout << "1/31/1001: Expected: 0, Actual: "
         << isGregorianDate(1, 31, 1001) << endl;
    cout << "9/12/1752:  Expected: 0, Actual: "
         << isGregorianDate(9, 12, 1752) << endl;
    cout << "9/13/1752:  Expected: 0, Actual: "
         << isGregorianDate(9, 13, 1752) << endl;
    cout << "9/14/1752: Expected: 1, Actual: "
         << isGregorianDate(9, 14, 1752) << endl;
    cout << "9/15/1752:  Expected: 1, Actual: "
         << isGregorianDate(9, 15, 1752) << endl;
    cout << "12/31/2050: Expected: 1, Actual: "
         << isGregorianDate(12, 31, 2050) << endl;
    cout << "5/20/780:  Expected: 0, Actual: "
         << isGregorianDate(5, 20, 780) << endl;
}

void test_isLeapYear()
{
    cout << "Now testing function isLeapYear()\n";
    cout << "1768: Expected: 1, Actual: "
         << isLeapYear(1768) << endl;
    cout << "1994: Expected: 0, Actual: "
         << isLeapYear(1994) << endl;
    cout << "1800: Expected: 0, Actual: "
         << isLeapYear(1800) << endl;
    cout << "2000: Expected: 1, Actual: "
         << isLeapYear(2000) << endl;
    cout << "2001: Expected: 0, Actual: "
         << isLeapYear(2001) << endl;
    cout << "1899: Expected: 0, Actual: "
         << isLeapYear(1899) << endl;
    cout << "1796: Expected: 1, Actual: "
         << isLeapYear(1796) << endl;
    cout << "1900: Expected: 0, Actual: "
         << isLeapYear(1900) << endl;
    cout << "2012: Expected: 1, Actual: "
         << isLeapYear(2012) << endl;
    cout << "2040: Expected: 1, Actual: "
         << isLeapYear(2040) << endl;
    cout << "2400: Expected: 1, Actual: "
         << isLeapYear(2400) << endl;
}

void test_isValidDate()
{
    cout << "Now testing function isValidDate()\n";
    cout << "9/23/2022: Expected: 1, Actual: "
         << isValidDate(9, 23, 2022) << endl;
    cout << "1/1/2040: Expected: 1, Actual: "
         << isValidDate(1, 1, 2040) << endl;
    cout << "19/4/1993: Expected: 0, Actual: "
         << isValidDate(19, 4, 1993) << endl;
    cout << "10/35/1899: Expected: 0, Actual: "
         << isValidDate(10, 35, 1899) << endl;
    cout << "8/7/1752: Expected: 0, Actual: "
         << isValidDate(8, 7, 1752) << endl;
    cout << "9/31/1995: Expected: 0, Actual: "
         << isValidDate(9, 31, 1995) << endl;
    cout << "2/29/2015: Expected: 0, Actual: "
         << isValidDate(2, 29, 2015) << endl;
    cout << "2/29/2016: Expected: 1, Actual: "
         << isValidDate(2, 29, 2016) << endl;
    cout << "1/32/2035: Expected: 0, Actual: "
         << isValidDate(1, 32, 2035) << endl;
}

void test_determineDay()
{
    cout << "Now testing function determineDay()\n";
    cout << "9/22/2022: Expected: 5, Actual: "
         << determineDay(9, 22, 2022) << endl;
    cout << "2/21/2024: Expected: 4, Actual: "
         << determineDay(2, 21, 2024) << endl;
    cout << "5/18/2015: Expected: 2, Actual: "
         << determineDay(5, 18, 2015) << endl;
    cout << "7/11/2004: Expected: 1, Actual: "
         << determineDay(7, 11, 2004) << endl;
    cout << "10/10/1987: Expected: 0, Actual: "
         << determineDay(10, 10, 1987) << endl;
    cout << "12/18/1953: Expected: 6, Actual: "
         << determineDay(12, 18, 1953) << endl;
    cout << "6/17/2042: Expected: 3, Actual: "
         << determineDay(6, 17, 2042) << endl;
}

void test_printDayOfBirth()
{
    cout << "Now testing function printDayOfBirth()\n";
    cout << "0: Expected: Saturday, Actual: ";
    printDayOfBirth(0);
    cout << endl;
    cout << "1: Expected: Sunday, Actual: ";
    printDayOfBirth(1);
    cout << endl;
    cout << "2: Expected: Monday, Actual: ";
    printDayOfBirth(2);
    cout << endl;
    cout << "3: Expected: Tuesday, Actual: ";
    printDayOfBirth(3);
    cout << endl;
    cout << "4: Expected: Wednesday, Actual: ";
    printDayOfBirth(4);
    cout << endl;
    cout << "5: Expected: Thursday, Actual: ";
    printDayOfBirth(5);
    cout << endl;
    cout << "6: Expected: Friday, Actual: ";
    printDayOfBirth(6);
    cout << endl;
}

void test_determineDayOfBirth()
{
    cout << "Now testing function determineDayOfBirth()\n";
    cout << "19 / 12 / 2021 Test result:" << endl;
    cout << "Expected: " << endl
         << "Enter your date of birth" << endl
         << "format: month / day / year  -->  12 / 19 / 2021" << endl
         << "You were born on a: Sunday" << endl
         << "Have a great birthday!!!" << endl;
    cout << "Acutal: " << endl;
    cout << "Please enter 12 / 19 / 2021" << endl;
    determineDayOfBirth();
    cout << endl;
    
    cout << "8 / 14 / 2023 Test result:" << endl;
    cout << "Expected: " << endl
         << "Enter your date of birth" << endl
         << "format: month / day / year  -->  8 / 14 / 2023" << endl
         << "You were born on a: Monday" << endl
         << "Have a great birthday!!!" << endl;
    cout << "Acutal: " << endl;
    cout << "Please enter 8 / 14 / 2023" << endl;
    determineDayOfBirth();
    cout << endl;
    
    cout << "13 / 2 / 2002 Test result:" << endl;
    cout << "Expected: " << endl
         << "Enter your date of birth" << endl
         << "format: month / day / year  -->  13 / 2 / 2002" << endl
         << "Invalid date" << endl;
    cout << "Acutal: " << endl;
    cout << "Please enter 13 / 2 / 2002" << endl;
    determineDayOfBirth();
    cout << endl;
    
    cout << "9 / 14 / 1752 Test result:" << endl;
    cout << "Expected: " << endl
         << "Enter your date of birth" << endl
         << "format: month / day / year  -->  9 / 14 / 1752" << endl
         << "You were born on a: Thursday" << endl
         << "Have a great birthday!!!" << endl;
    cout << "Acutal: " << endl;
    cout << "Please enter 9 / 14 / 1752" << endl;
    determineDayOfBirth();
    cout << endl;
    
    cout << "9 / 13 / 1752 Test result:" << endl;
    cout << "Expected: " << endl
         << "Enter your date of birth" << endl
         << "format: month / day / year  -->  9 / 13 / 1752" << endl
         << "Invalid date" << endl;
    cout << "Acutal: " << endl;
    cout << "Please enter 9 / 13 / 1752" << endl;
    determineDayOfBirth();
    cout << endl;
    
    cout << "2 / 29 / 2012 Test result:" << endl;
    cout << "Expected: " << endl
         << "Enter your date of birth" << endl
         << "format: month / day / year  -->  2 / 29 / 2012" << endl
         << "You were born on a: Wednesday" << endl
         << "Have a great birthday!!!" << endl;
    cout << "Acutal: " << endl;
    cout << "Please enter 2 / 29 / 2012" << endl;
    determineDayOfBirth();
    cout << endl;
    
    cout << "2 / 29 / 2015 Test result:" << endl;
    cout << "Expected: " << endl
         << "Enter your date of birth" << endl
         << "format: month / day / year  -->  2 / 29 / 2015" << endl
         << "Invalid date" << endl;
    cout << "Acutal: " << endl;
    cout << "Please enter 2 / 29 / 2015" << endl;
    determineDayOfBirth();
    cout << endl;
}

void test_print10LeapYears()
{
    cout << "Now testing function print10LeapYears()\n";
    cout << "1752" << endl
         << "Expected:" << endl
         << "Leap year is 1756" << endl
         << "Leap year is 1760" << endl
         << "Leap year is 1764" << endl
         << "Leap year is 1768" << endl
         << "Leap year is 1772" << endl
         << "Leap year is 1776" << endl
         << "Leap year is 1780" << endl
         << "Leap year is 1784" << endl
         << "Leap year is 1788" << endl
         << "Leap year is 1792" << endl;
    cout << "Actual: " << endl << "Enter 1752" << endl;
    print10LeapYears();
    cout << endl;
    
    cout << "1876" << endl
         << "Expected:" << endl
         << "Leap year is 1880" << endl
         << "Leap year is 1884" << endl
         << "Leap year is 1888" << endl
         << "Leap year is 1892" << endl
         << "Leap year is 1896" << endl
         << "Leap year is 1904" << endl
         << "Leap year is 1908" << endl
         << "Leap year is 1912" << endl
         << "Leap year is 1916" << endl
         << "Leap year is 1920" << endl;
    cout << "Actual: " << endl << "Enter 1876" << endl;
    print10LeapYears();
    cout << endl;
    
    cout << "1750" << endl
         << "Expected:" << endl;
    cout << "Actual: " << endl << "Enter 1750" << endl;
    print10LeapYears();
    cout << endl;
    
    cout << "2035" << endl
         << "Expected:" << endl
         << "Leap year is 2036" << endl
         << "Leap year is 2040" << endl
         << "Leap year is 2044" << endl
         << "Leap year is 2048" << endl
         << "Leap year is 2052" << endl
         << "Leap year is 2056" << endl
         << "Leap year is 2060" << endl
         << "Leap year is 2064" << endl
         << "Leap year is 2068" << endl
         << "Leap year is 2072" << endl;
    cout << "Actual: " << endl << "Enter 2035" << endl;
    print10LeapYears();
    cout << endl;
    
    cout << "1999" << endl
         << "Expected:" << endl
         << "Leap year is 2000" << endl
         << "Leap year is 2004" << endl
         << "Leap year is 2008" << endl
         << "Leap year is 2012" << endl
         << "Leap year is 2016" << endl
         << "Leap year is 2020" << endl
         << "Leap year is 2024" << endl
         << "Leap year is 2028" << endl
         << "Leap year is 2032" << endl
         << "Leap year is 2036" << endl;
    cout << "Actual: " << endl << "Enter 1999" << endl;
    print10LeapYears();
    cout << endl;
}

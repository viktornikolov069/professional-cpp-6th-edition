#include "Database.h"
#include "Employee.h"
#include <iostream>
#include <print>
#include <string>

using namespace std;

int displayMenu();
void doHire(Records::Database &db);
void doFire(Records::Database &db);
void doPromote(Records::Database &db);

int main() {
    Records::Database employeeDB;

    bool done {false};
    while (!done) {
        int selection {displayMenu()};
        switch (selection) {
        case 0:
            done = true;
            break;
        case 1:
            doHire(employeeDB);
            break;
        case 2:
            doFire(employeeDB);
            break;
        case 3:
            doPromote(employeeDB);
            break;
        case 4:
            employeeDB.displayAll();
            break;
        case 5:
            employeeDB.displayCurrent();
            break;
        case 6:
            employeeDB.displayFormer();
            break;
        default:
            std::println(std::cerr, "Unknown command.");
            break;
        }
    }
}

int displayMenu() {
    // Note:
    //		One important note is that this code assumes that the user will
    //		"play nice" and type a number when a number is requested.
    //		When you read about I/O in Chapter 13, you will learn how to
    //		protect against bad input.

    int selection;

    std::println("");
    std::println("Employee Database");
    std::println("-----------------");
    std::println("1) Hire a new employee");
    std::println("2) Fire an employee");
    std::println("3) Promote an employee");
    std::println("4) List all employees");
    std::println("5) List all current employees");
    std::println("6) List all former employees");
    std::println("0) Quit");
    std::println("");
    print("---> ");

    cin >> selection;

    return selection;
}

void doHire(Records::Database &db) {
    string firstName;
    string lastName;

    print("First name? ");
    cin >> firstName;

    print("Last name? ");
    cin >> lastName;

    auto &employee {db.addEmployee(firstName, lastName)};
    std::println("Hired employee {} {} with employee number {}.", firstName, lastName,
                 employee.getEmployeeNumber());
    employee.setFirstName("Kevin");
}

void doFire(Records::Database &db) {
    int employeeNumber;
    print("Employee number? ");
    cin >> employeeNumber;

    try {
        auto &emp {db.getEmployee(employeeNumber)};
        emp.fire();
        std::println("Employee {} terminated.", employeeNumber);
    } catch (const std::logic_error &exception) {
        std::println(cerr, "Unable to terminate employee: {}", exception.what());
    }
}

void doPromote(Records::Database &db) {
    int employeeNumber;
    print("Employee number? ");
    cin >> employeeNumber;

    int raiseAmount;
    print("How much of a raise? ");
    cin >> raiseAmount;

    try {
        auto &emp {db.getEmployee(employeeNumber)};
        emp.promote(raiseAmount);
    } catch (const std::logic_error &exception) {
        std::println(cerr, "Unable to promote employee: {}", exception.what());
    }
}
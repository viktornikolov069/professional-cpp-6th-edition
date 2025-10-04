#pragma once

#include "Employee.h"
#include <vector>

/**
 * @brief The Records namespace contains the Database class
 */
namespace Records {

    /**
     * Employee numbering starts from 1000
     */
    const int FirstEmployeeNumber {1000};

    /**
     * The Database stores a collection of employees. It supports
     * adding and retrieving employees, and displaying employees
     * satisfying certain constraints.
     */
    class Database {
      public:
        /**
         * @brief Adds employee and their names to database
         * @param firstName First name
         * @param lastName Second name
         * @return A reference to an HR::Employee object
         */
        HR::Employee &addEmployee(const std::string &firstName, const std::string &lastName);

        /**
         * Finds an employee based on an employee number.
         *
         * @param employeeNumber The employee number to find.
         * @return The employee with given number.
         * @throws logic_error When the requested employee cannot be found.
         */
        HR::Employee &getEmployee(int employeeNumber);

        /**
         * Finds an employee based on a name.
         *
         * @param firstName The first name of the employee to find.
         * @param lastName The last name of the employee to find.
         * @return The employee with given name.
         * @throws logic_error When the requested employee cannot be found.
         */
        HR::Employee &getEmployee(const std::string &firstName, const std::string &lastName);

        void displayAll() const;
        void displayCurrent() const;
        void displayFormer() const;

      private:
        std::vector<HR::Employee> m_employees;
        int m_nextEmployeeNumber {FirstEmployeeNumber};
    };

} // namespace Records
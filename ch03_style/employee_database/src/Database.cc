#include "Database.h"
#include <stdexcept>

namespace Records {

    HR::Employee &Database::addEmployee(const std::string &firstName, const std::string &lastName) {
        HR::Employee emp {firstName, lastName};
        emp.setEmployeeNumber(m_nextEmployeeNumber++);
        emp.hire();
        m_employees.push_back(emp);
        return m_employees.back();
    }

    HR::Employee &Database::getEmployee(int employeeNumber) {
        for (auto &employee : m_employees) {
            if (employee.getEmployeeNumber() == employeeNumber) {
                return employee;
            }
        }
        throw std::logic_error {"No employee found."};
    }

    HR::Employee &Database::getEmployee(const std::string &firstName, const std::string &lastName) {
        for (auto &employee : m_employees) {
            if (employee.getFirstName() == firstName && employee.getLastName() == lastName) {
                return employee;
            }
        }
        throw std::logic_error {"No employee found."};
    }

    void Database::displayAll() const {
        for (const auto &employee : m_employees) {
            employee.display();
        }
    }
    void Database::displayCurrent() const {
        for (const auto &employee : m_employees) {
            if (employee.isHired()) {
                employee.display();
            }
        }
    }
    void Database::displayFormer() const {
        for (const auto &employee : m_employees) {
            if (!employee.isHired()) {
                employee.display();
            }
        }
    }
} // namespace Records
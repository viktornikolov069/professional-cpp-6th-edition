#include <print>

#include "Employee.h"

int main() {

    Records::Employee demo {"Viktor", "Nikolov"};
    std::println("Name is {}", demo.getFirstName());
    return 0;
}
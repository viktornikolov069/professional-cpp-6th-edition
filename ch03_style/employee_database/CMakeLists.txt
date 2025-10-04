cmake_minimum_required(VERSION 3.24)
project(employee_database LANGUAGES CXX)

# ——————————————————————————————
# C++ standard
# ——————————————————————————————
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Doxygen REQUIRED)

doxygen_add_docs(
    employee_database_docs
    ${PROJECT_SOURCE_DIR}/include 
    ${PROJECT_SOURCE_DIR}/src
    COMMENT "Generate API documentation with Doxygen"
)

# ——————————————————————————————
# Source files (use GLOB only for quick prototypes)
# ——————————————————————————————
set (SOURCE_FILES 
    test/UserInterface.cc
    src/Employee.cc
    src/Database.cc
)

# ——————————————————————————————
# Executable target
# ——————————————————————————————
add_executable(${PROJECT_NAME}
    ${SOURCE_FILES}
)

# ——————————————————————————————
# Target-local include paths
# ——————————————————————————————
target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

# # Student Record Management System

This is a simple command-line program in C for managing student records. It allows you to perform the following tasks:

1. **Add Record:** Add information about a new student, including name, mobile number, roll number, course, and branch.

2. **View Record:** View a list of all student records with details such as name, mobile number, roll number, course, and branch.

3. **Search Record:** Search for a student record by entering their roll number.

4. **Modify Record:** Modify the details of a student record by entering their roll number.

5. **Delete Record:** Delete a student record by entering their roll number.

## How to Use

1. Clone or download the repository.

2. Compile the C program using a C compiler. For example, on Windows, you can use a tool like Code::Blocks or Dev-C++, while on Linux, you can use GCC.

3. Run the compiled executable to start the program.

4. Follow the on-screen menu to perform various tasks, such as adding, viewing, searching, modifying, or deleting student records.

## Features

- The program uses file handling to store student records in a file named "record.txt."

- It provides a simple and intuitive menu-driven interface for managing records.

- Records can be added, viewed, searched, modified, and deleted interactively.

- The program performs error handling to handle cases such as file opening failures and invalid user inputs.

## Dependencies

- The program depends on the standard C libraries (`stdio.h`, `stdlib.h`, `string.h`, etc.).

- It also uses Windows-specific libraries (`conio.h` and `windows.h`) for console manipulation, so it may be more suitable for Windows environments.

- Note that the use of Windows-specific libraries may limit portability to other platforms.




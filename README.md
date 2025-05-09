# Bank Management System (C++)

This is a console-based Bank Management System written in C++. It is part of my problem-solving projects and demonstrates file handling, user authentication, and basic client management functionality.

## Features

- User login system
- View client list
- Add, delete, update, and search clients
- Manage users with permissions
- Console-based interface using standard C++ libraries
- Data persistence via text files

## Getting Started

### 1. Clone the Repository
bash
git clone https://github.com/bilmoh287/Alg-and-problem-solving-level-4.git

2. Open the Project
Open the solution in Visual Studio (or any C++ IDE).

Build the project and run Project_1_Bank_Extension.cpp.

3. Required File: Users2.txt
Before running the project, create a file named Users2.txt in the same directory as your executable (or adjust the path in code).

Example contents of Users2.txt:
Admin#//#1234#//#-1

Make sure there are no extra spaces or blank lines in the file.

The program reads this file to authenticate users before granting access.

File Structure
Project_1_Bank_Extension.cpp: Main logic of the project.

Users2.txt: User login information.

Clients2.txt: (Optional) Data file for client records (if implemented in your version).

## Notes

- Ensure the text files are properly formatted.
- Login credentials are case-sensitive.
- If login fails, the system will continue to prompt until correct credentials are entered.


Made with 💻 by [Bilal Mohammedhasen](https://github.com/bilmoh287)


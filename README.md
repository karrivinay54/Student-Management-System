# 🎓 Student Management System

A console-based **Student Management System** developed in **C++** that allows users to efficiently manage student records using **file handling** and a **menu-driven interface**.

The application performs complete CRUD (Create, Read, Update, Delete) operations while storing data persistently in a text file, ensuring that records remain available even after the program is closed.

---

## ✨ Features

- ➕ Add new student records
- 📋 Display all student records
- 🔍 Search students using Student ID
- ✏️ Update existing student details
- 🗑️ Delete student records
- 💾 Persistent storage using file handling
- ✅ Duplicate Student ID detection
- 📱 Phone number validation
- 🎯 CGPA validation (0–10)
- 🎂 Age validation
- 🏫 Branch validation
- 🖥️ Simple menu-driven console interface

---

## 🛠️ Technologies Used

- **Language:** C++
- **Concepts:** Structures, File Handling, Conditional Statements, Loops
- **IDE:** Dev-C++
- **Storage:** Text File (`students.txt`)

---

## 📂 Project Structure

```
Student-Management-System/
│
├── main.cpp          # Source code
├── students.txt      # Student records
├── .gitignore
└── README.md
```

---

## ⚙️ How It Works

The system stores each student record in a comma-separated format inside `students.txt`.

Example:

```
N210614,Vinay,20,ECE,8.8,1234567890
```

Each line represents one complete student record.

---

## 🚀 Functionalities

### Add Student

- Accepts student details
- Checks for duplicate Student ID
- Validates age, CGPA, phone number, and branch
- Saves the record to the file

---

### Display Students

Displays all stored student records in a formatted table.

---

### Search Student

Searches for a student using their Student ID and displays complete details if found.

---

### Update Student

Updates an existing student's information while preserving all other records.

---

### Delete Student

Deletes a student record permanently using the Student ID.

---

## 📸 Sample Output

### Main Menu

```
=====================================
     Student Management System
=====================================

1. Add Student
2. Display Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit
```

---

### Display Students

```
ID             Name           Age     Branch      CGPA    Phone
------------------------------------------------------------------
N210614        Vinay          20      ECE         8.8     1234567890
N210225        Lokesh         21      CSE         8.4     9876543210
```

---

## 📖 Concepts Demonstrated

- Structures (`struct`)
- File Handling (`ifstream`, `ofstream`)
- CRUD Operations
- Data Validation
- Menu-Driven Programming
- Searching Algorithms
- Updating Records using Temporary Files
- Deleting Records using Temporary Files

---

## 🔮 Future Improvements

Potential enhancements include:

- Password-protected login
- Multiple search options
- Sorting student records
- Attendance management
- GPA statistics
- Graphical User Interface (GUI)
- Database integration using MySQL or SQLite

---

## 👨‍💻 Author

**Vinay Karri**

Electronics & Communication Engineering (ECE)

RGUKT IIIT Nuzvid

GitHub: https://github.com/karrivinay54

---

## ⭐ If you found this project useful, consider giving it a star!

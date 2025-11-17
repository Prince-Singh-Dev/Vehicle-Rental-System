# 🚗 Vehicle Rental System – C++ (OOP Project)

A console-based Vehicle Rental System developed using C++ and Object-Oriented Programming (OOP) concepts.
The project allows users to view available vehicles, rent vehicles using a unique token, return them, and track the total profit earned.
It demonstrates real-world application of key OOP principles like inheritance, abstraction, polymorphism, and encapsulation.

# 📌 Features

✔ Vehicle Management

Three categories: Cars, Bikes, Trucks
5 vehicles in each category
Separate classes for each using inheritance
Display vehicle details in a clean tabular format

✔ Rental System

User can rent a vehicle by selecting category and model
System generates a unique rental token
Auto-calculates rent based on days
Generates a detailed rental receipt

✔ Return System

User enters the rental token to return vehicle
Verifies rental record from stored data
Updates return status
Prints final receipt

✔ Profit Tracking

Automatically adds every rental amount to profit
Displays total accumulated profit
Profit stored using file handling (profit.txt)

✔ Data Persistence

All rental records are saved in rentals.txt
Records are loaded automatically when program starts
Maintains both active and returned rentals

✔ Error Handling

Validates all user inputs
Prevents crashes due to invalid integers or characters
Ensures rental selections are within valid range

# 🧠 Concepts Used (OOP)

| Concept           | Description                                         |
| ----------------- | --------------------------------------------------- |
| **Abstraction**   | Achieved through abstract class `Rentable`          |
| **Inheritance**   | Car, Bike, Truck ← Vehicle ← Rentable               |
| **Encapsulation** | Vehicle details stored in private/protected members |
| **Polymorphism**  | Overridden `calculateRent()` and `displayInfo()`    |
| **File Handling** | Used to store rentals and profit records            |

# 📂 Project Structure

📁 Vehicle-Rental-System

├── main.cpp

├── rentals.txt        # stores all rental records

├── profit.txt         # stores total profit

└── README.md          # project documentation

# 🖥 How It Works

1️⃣ Show Available Vehicles

Displays all cars, bikes, and trucks with brand, price per day, and features.

2️⃣ Rent a Vehicle

Select category
Select specific vehicle
Enter number of days
System generates token & receipt
Saves record to file

3️⃣ Return a Vehicle

Enter rental token
System verifies record
Marks as returned
Shows updated receipt

4️⃣ View Active Rentals

Displays all ongoing, non-returned rentals.

5️⃣ View Total Profit

Shows accumulated profit from all completed rentals.

# 📸 Sample Output (Console)

=========================================
        VEHICLE RENTAL SYSTEM
=========================================
1. Show Available Vehicles
2. Rent a Vehicle
3. Return a Vehicle
4. Show Active Rentals
5. View Total Profit
6. Exit
-----------------------------------------
Enter choice:

# 🛠 Requirements

C++ Compiler (g++ recommended).
CodeBlocks / VS Code / Dev-C++ (any IDE).
Basic understanding of OOP concepts.

# 🚀 How to Run

Using G++ (Terminal)
g++ main.cpp -o rental
./rental

Using CodeBlocks

Create a new console project
Replace main.cpp with this file
Build & run

# 📈 Future Enhancements (Optional)

Add customer login system
Add admin panel for adding/removing vehicles
Store data using SQLite/MySQL instead of text files
Generate printable PDF receipts
Add GUI using Qt or Python

# 🧑‍💻 Author

Prince
3rd Semester – Computer Science & Engineering

# 📝 License

This project is created for academic and learning purposes.
Feel free to modify, enhance, and use it in your college submissions.
Prevents crashes due to invalid integers or characters

Ensures rental selections are within valid range

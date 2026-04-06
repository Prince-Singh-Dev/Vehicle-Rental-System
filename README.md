<!-- ======================= HEADER ======================= -->

<p align="center">
  <img src="https://readme-typing-svg.herokuapp.com?font=Orbitron&size=30&duration=2500&pause=800&color=00F7FF&center=true&vCenter=true&width=900&lines=Vehicle+Rental+Management+System;C%2B%2B+Object-Oriented+Architecture;File+Handling+%7C+Polymorphism+%7C+Inheritance;Academic+Project+with+Real-World+Simulation" />
</p>

<p align="center">
  <img src="https://img.shields.io/github/stars/Prince-Singh-Dev/Vehicle-Rental-System?style=for-the-badge&color=yellow"/>
  <img src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B"/>
  <img src="https://img.shields.io/badge/Architecture-OOP-orange?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Storage-File%20Handling-purple?style=for-the-badge"/>
</p>

---

# 🚗 Vehicle Rental Management System

## 📌 Overview

The **Vehicle Rental Management System** is a console-based application developed in **C++**, designed to simulate a real-world vehicle rental business environment...

The system enables users to:
- View available vehicles
- Rent vehicles using a secure token system
- Return rented vehicles
- Track cumulative business profit
- Persist rental data using file handling

This project demonstrates practical implementation of **core Object-Oriented Programming (OOP) principles** and structured software design.

---

# 🎯 Project Objectives

- Apply OOP concepts in a real-world simulation
- Design modular and scalable system architecture
- Implement persistent data storage
- Build a reliable input validation mechanism
- Follow structured software engineering practices

---

# 🏗 System Architecture

```
                Rentable (Abstract Class)
                         ▲
                         │
                     Vehicle (Base Class)
            ┌────────────┼────────────┐
            │            │            │
           Car          Bike         Truck
```

### Architectural Principles Used:
- Abstraction through abstract base class
- Inheritance hierarchy for vehicle categories
- Encapsulation of vehicle properties
- Polymorphism via overridden rent calculation methods

---

# 🔥 Core Functional Modules

## 1️⃣ Vehicle Management Module
- Three vehicle categories (Cars, Bikes, Trucks)
- Five vehicles per category
- Availability tracking
- Structured tabular display

---

## 2️⃣ Rental Processing Module
- Category & vehicle selection
- Rental duration input
- Unique rental token generation
- Automated rent calculation
- Receipt generation
- Data persistence to `rentals.txt`

---

## 3️⃣ Return Management Module
- Token-based rental verification
- Rental status update
- Final receipt display
- Record maintenance

---

## 4️⃣ Profit Management Module
- Automatic profit accumulation
- Persistent storage in `profit.txt`
- Displays cumulative revenue

---

## 5️⃣ Input Validation System
- Validates numeric input
- Prevents invalid menu selections
- Protects against runtime crashes
- Ensures secure rental flow

---

# 🧠 OOP Concepts Implemented

| Concept        | Implementation |
|---------------|----------------|
| Abstraction    | `Rentable` abstract class |
| Inheritance    | Car, Bike, Truck derived from Vehicle |
| Encapsulation  | Private data members with controlled access |
| Polymorphism   | Overridden `calculateRent()` methods |
| File Handling  | rentals.txt & profit.txt for persistence |

---

# 📂 Project Structure

```
Vehicle-Rental-System/
│
├── main.cpp
├── rentals.txt
├── profit.txt
└── README.md
```

---

# 🖥 Console Interface Preview

```
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
```

---

# ⚙ Technical Specifications

- Language: C++
- Paradigm: Object-Oriented Programming
- Data Storage: File Handling (Text-Based)
- Execution Environment: Console Application
- Compiler: g++ recommended

---

# 🚀 Installation & Execution

## 🔹 Using Terminal (Linux / macOS / Windows with MinGW)

```bash
g++ main.cpp -o rental
./rental
```

## 🔹 Using IDE (CodeBlocks / VS Code)

1. Create new C++ Console Project
2. Replace `main.cpp` with project source
3. Build and Run

---

# 📈 Future Enhancements

- Database Integration (MySQL / SQLite)
- Admin Dashboard
- Customer Authentication System
- GUI Version using Qt Framework
- REST API Backend Version
- Payment Gateway Simulation
- PDF Invoice Generation

---

# 📊 Engineering Improvement Roadmap

- Layered Architecture Implementation
- MVC Pattern Adaptation
- Modular Service Separation
- Unit Testing Integration
- Logging System Implementation

---

# 🤝 Contribution Guidelines

1. Fork the repository
2. Create feature branch
3. Commit changes
4. Open pull request

---

# 📜 License

This project is developed for academic and learning purposes.  
Open for modification and educational use.

---

# 👨‍💻 Author

**Prince Singh**  
3rd Semester – Computer Science & Engineering  
Focused on Backend Systems & OOP Design  

---

<p align="center">
  ⭐ If you found this project helpful, consider starring the repository.
</p>

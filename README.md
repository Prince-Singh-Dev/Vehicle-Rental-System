<!-- ======================= HEADER ======================= -->

<p align="center">
  <img src="https://readme-typing-svg.herokuapp.com?font=Orbitron&size=32&duration=2500&pause=1000&color=00F7FF&center=true&vCenter=true&width=900&lines=🚗+Vehicle+Rental+Management+System;Built+With+C%2B%2B+%7C+OOP+Architecture;File+Handling+%7C+Polymorphism+%7C+Inheritance;Console-Based+Real+World+Simulation" />
</p>

<p align="center">
  <img src="https://media.giphy.com/media/l0HlQ7LRalQqdWfao/giphy.gif" width="750"/>
</p>

<p align="center">
  <img src="https://img.shields.io/github/stars/https://github.com/Prince-Singh-Dev/Vehicle-Rental-System?style=for-the-badge&color=yellow"/>
  <img src="https://img.shields.io/github/forks/https://github.com/Prince-Singh-Dev/Vehicle-Rental-System?style=for-the-badge&color=blue"/>
  <img src="https://img.shields.io/github/license/https://github.com/Prince-Singh-Dev/Vehicle-Rental-System?style=for-the-badge&color=green"/>
  <img src="https://img.shields.io/badge/Made%20With-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B"/>
  <img src="https://img.shields.io/badge/OOP-Concepts-orange?style=for-the-badge"/>
</p>

---

# 🚗 Vehicle Rental System  
### 🧠 Object-Oriented Programming Based Console Application

> A real-world inspired rental management system built using modern C++ principles and structured OOP architecture.

This project simulates a professional rental business environment where vehicles can be rented, returned, and profit is automatically tracked using persistent file storage.

---

# ✨ Why This Project Is Different?

✔ Structured OOP Hierarchy  
✔ Real-world business logic simulation  
✔ Persistent file-based storage  
✔ Token-based rental tracking  
✔ Clean modular architecture  
✔ Robust input validation system  
✔ Expandable & scalable design  

---

# 🏗 System Architecture

```
                Rentable (Abstract Class)
                         ▲
                         │
                     Vehicle
            ┌────────────┼────────────┐
            │            │            │
           Car          Bike         Truck
```

- Abstract behavior defined in `Rentable`
- Shared attributes managed by `Vehicle`
- Specialized rental calculation via polymorphism

---

# 🔥 Core Functional Modules

## 🚘 Vehicle Management Engine
- 3 Categories (Cars, Bikes, Trucks)
- 5 Vehicles per category
- Tabular display formatting
- Availability tracking

---

## 🧾 Smart Rental Processor
- Category selection
- Vehicle selection
- Rental duration input
- Unique token generation
- Automated rent calculation
- Receipt generation
- Auto-save to `rentals.txt`

---

## 🔁 Intelligent Return Handler
- Token-based verification
- Rental status update
- Final bill display
- Record persistence

---

## 💰 Automated Profit Tracker
- Adds completed rental amounts
- Stored in `profit.txt`
- Displays cumulative earnings
- Maintains data across sessions

---

## 🛡 Input Validation System
- Prevents invalid integers
- Handles wrong menu choices
- Prevents invalid vehicle selection
- Avoids runtime crashes

---

# 📂 Project Structure

```
📁 Vehicle-Rental-System
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

# 🧠 OOP Concepts Implemented

| Concept | Real Implementation |
|----------|--------------------|
| Abstraction | `Rentable` Abstract Class |
| Inheritance | Car, Bike, Truck → Vehicle |
| Encapsulation | Private Data Members |
| Polymorphism | Overridden `calculateRent()` |
| File Handling | Persistent Rental & Profit Records |

---

# ⚙ Technology Stack

- Language: C++
- Paradigm: Object-Oriented Programming
- Storage: File Handling (Text Files)
- Environment: Console Application

---

# 🚀 How To Run

## 🔹 Terminal (G++)

```bash
g++ main.cpp -o rental
./rental
```

## 🔹 Using IDE
1. Create new C++ console project  
2. Replace `main.cpp`  
3. Build & Run  

---

# 📈 Scalability Possibilities

🔹 Add Admin Panel  
🔹 Database Integration (MySQL / SQLite)  
🔹 User Authentication System  
🔹 GUI Version (Qt Framework)  
🔹 REST API Backend Version  
🔹 Cloud Data Storage  
🔹 Printable PDF Invoice Generation  

---

# 📊 Future Production-Level Upgrade Vision

- Modular service layers  
- MVC architecture  
- Microservice separation  
- Real-time vehicle availability sync  
- Payment gateway simulation  

---

# 👨‍💻 Author

**Prince**  
🎓 3rd Semester – Computer Science & Engineering  
🚀 Passionate about OOP, Systems & Backend Development  

---

<p align="center">
  <img src="https://github-profile-trophy.vercel.app/?username=yourusername&theme=matrix&margin-w=15"/>
</p>

---

<p align="center">
  🚀 If you found this project useful, consider giving it a ⭐
</p>

---
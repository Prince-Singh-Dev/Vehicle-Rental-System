#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <iomanip>
using namespace std;

// ---------- Utility: Safe Input Function ----------
int getValidatedInput(int minVal, int maxVal) {
    int input;
    while (true) {
        cin >> input;
        if (cin.fail() || input < minVal || input > maxVal) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number between "
                 << minVal << " and " << maxVal << ": ";
        } else {
            cin.ignore(1000, '\n');
            return input;
        }
    }
}

// ------------------- Abstract Class -------------------
class Rentable {
public:
    virtual double calculateRent(int days) = 0;
    virtual void displayInfo(int index = 0) = 0;
    virtual ~Rentable() {}
};

// ------------------- Base Class -------------------
class Vehicle : public Rentable {
protected:
    string vehicleID;
    string brand;
    double pricePerDay;

public:
    Vehicle(string id, string b, double price)
        : vehicleID(id), brand(b), pricePerDay(price) {}

    string getVehicleID() const { return vehicleID; }
    string getBrand() const { return brand; }
    double getPricePerDay() const { return pricePerDay; }

    virtual void displayInfo(int index = 0) {
        cout << left << setw(5) << index
             << setw(10) << vehicleID
             << setw(20) << brand
             << "Rs. " << fixed << setprecision(2) << setw(8) << pricePerDay;
    }

    virtual double calculateRent(int days) = 0;
};

// ------------------- Derived Classes -------------------
class Car : public Vehicle {
    int seats;
public:
    Car(string id, string b, double price, int s)
        : Vehicle(id, b, price), seats(s) {}

    double calculateRent(int days) {
        double rent = pricePerDay * days;
        if (days > 5) rent *= 0.9;
        return rent;
    }

    void displayInfo(int index = 0) {
        cout << "[Car] ";
        Vehicle::displayInfo(index);
        cout << " | Seats: " << seats << endl;
    }
};

class Bike : public Vehicle {
    bool hasGear;
public:
    Bike(string id, string b, double price, bool gear)
        : Vehicle(id, b, price), hasGear(gear) {}

    double calculateRent(int days) {
        double rent = pricePerDay * days;
        if (!hasGear) rent *= 0.95;
        return rent;
    }

    void displayInfo(int index = 0) {
        cout << "[Bike]";
        Vehicle::displayInfo(index);
        cout << " | Gear: " << (hasGear ? "Yes" : "No") << endl;
    }
};

class Truck : public Vehicle {
    double loadCapacity;
public:
    Truck(string id, string b, double price, double capacity)
        : Vehicle(id, b, price), loadCapacity(capacity) {}

    double calculateRent(int days) {
        double rent = pricePerDay * days;
        if (loadCapacity > 10) rent *= 1.05;
        return rent;
    }

    void displayInfo(int index = 0) {
        cout << "[Truck]";
        Vehicle::displayInfo(index);
        cout << " | Load: " << loadCapacity << " tons" << endl;
    }
};

// ------------------- Rental Record -------------------
struct RentalRecord {
    string token;
    string vehicleType;
    string brand;
    int days;
    double totalRent;
    bool returned;

    void displayReceipt() const {
        cout << "\n-----------------------------------------\n";
        cout << "             RENTAL RECEIPT              \n";
        cout << "-----------------------------------------\n";
        cout << left;
        cout << setw(18) << "Token ID:"      << token << endl;
        cout << setw(18) << "Vehicle Type:"  << vehicleType << endl;
        cout << setw(18) << "Brand:"         << brand << endl;
        cout << setw(18) << "Days Rented:"   << days << endl;
        cout << setw(18) << "Total Rent:"    << "Rs. " << fixed << setprecision(2) << totalRent << endl;
        cout << setw(18) << "Status:"        << (returned ? "Returned" : "Not Returned") << endl;
        cout << "-----------------------------------------\n";
    }
};

// ------------------- Rental System -------------------
class RentalSystem {
private:
    map<string, RentalRecord> activeRentals;
    const string fileName = "rentals.txt";
    const string profitFile = "profit.txt";

    string generateToken() {
        string token = "TKN";
        for (int i = 0; i < 4; ++i)
            token += to_string(rand() % 10);
        return token;
    }

    void saveToFile() {
        ofstream file(fileName);
        if (!file) return;

        for (auto &p : activeRentals) {
            RentalRecord r = p.second;
            file << r.token << "," << r.vehicleType << "," << r.brand << ","
                 << r.days << "," << r.totalRent << "," << r.returned << "\n";
        }
        file.close();
    }

    void loadFromFile() {
        ifstream file(fileName);
        if (!file) return;

        RentalRecord r;
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            string temp;

            getline(ss, r.token, ',');
            getline(ss, r.vehicleType, ',');
            getline(ss, r.brand, ',');
            getline(ss, temp, ','); r.days = stoi(temp);
            getline(ss, temp, ','); r.totalRent = stod(temp);
            getline(ss, temp, ','); r.returned = stoi(temp);

            activeRentals[r.token] = r;
        }
        file.close();
    }

    void addProfit(double amount) {
        double currentProfit = getTotalProfit();
        currentProfit += amount;

        ofstream file(profitFile);
        if (file)
            file << currentProfit;
        file.close();
    }

public:
    RentalSystem() {
        loadFromFile();
    }

    ~RentalSystem() {
        saveToFile();
    }

    double getTotalProfit() {
        ifstream file(profitFile);
        double profit = 0;
        if (file) file >> profit;
        file.close();
        return profit;
    }

    void rentVehicle(Vehicle* v, string type) {
        cout << "Enter number of days to rent: ";
        int days = getValidatedInput(1, 365);

        string token = generateToken();
        double rent = v->calculateRent(days);

        RentalRecord rec = {token, type, v->getBrand(), days, rent, false};
        activeRentals[token] = rec;
        saveToFile();
        addProfit(rent);

        cout << "\nVehicle rented successfully. Keep your token safe.\n";
        rec.displayReceipt();
    }

    void returnVehicle() {
        string token;
        cout << "Enter your rental token: ";
        cin >> token;

        if (activeRentals.find(token) != activeRentals.end()) {
            if (activeRentals[token].returned) {
                cout << "Vehicle already returned.\n";
            } else {
                activeRentals[token].returned = true;
                cout << "\nVehicle returned successfully.\n";
                activeRentals[token].displayReceipt();
                saveToFile();
            }
        } else {
            cout << "Invalid token. No record found.\n";
        }
    }

    void showActiveRentals() {
        bool found = false;
        for (auto &pair : activeRentals) {
            if (!pair.second.returned) {
                pair.second.displayReceipt();
                found = true;
            }
        }
        if (!found)
            cout << "No active rentals found.\n";
    }

    void showTotalProfit() {
        cout << "\n---------------------------------------------------\n";
        cout << "   Total Profit Earned So Far: Rs. " << fixed << setprecision(2)
             << getTotalProfit() << endl;
        cout << "-----------------------------------------------------\n";
    }
};

// ------------------- Main Function -------------------
int main() {
    srand(time(0));
    RentalSystem system;

    // Cars
    Car car1("C101", "Hyundai", 2500, 5);
    Car car2("C102", "Maruti", 2000, 4);
    Car car3("C103", "Honda", 2800, 5);
    Car car4("C104", "Tata", 2200, 5);
    Car car5("C105", "Mahindra", 3000, 7);

    // Bikes
    Bike bike1("B201", "Yamaha", 800, true);
    Bike bike2("B202", "Hero", 600, false);
    Bike bike3("B203", "Honda", 700, true);
    Bike bike4("B204", "Suzuki", 850, true);
    Bike bike5("B205", "Royal Enfield", 1200, true);

    // Trucks
    Truck truck1("T301", "Tata", 5000, 12);
    Truck truck2("T302", "Ashok Leyland", 4800, 10);
    Truck truck3("T303", "Eicher", 5200, 15);
    Truck truck4("T304", "Mahindra", 4500, 8);
    Truck truck5("T305", "Volvo", 7000, 20);

    int choice;
    do {
        cout << "\n=========================================\n";
        cout << "         VEHICLE RENTAL SYSTEM           \n";
        cout << "=========================================\n";
        cout << "1. Show Available Vehicles\n";
        cout << "2. Rent a Vehicle\n";
        cout << "3. Return a Vehicle\n";
        cout << "4. Show Active Rentals\n";
        cout << "5. View Total Profit\n";
        cout << "6. Exit\n";
        cout << "-----------------------------------------\n";
        cout << "Enter choice: ";

        choice = getValidatedInput(1, 6);

        switch (choice) {
        case 1:
            cout << "\n========== AVAILABLE VEHICLES ==========\n";
            cout << "\n---- CARS ----\n";
            car1.displayInfo(1); car2.displayInfo(2); car3.displayInfo(3);
            car4.displayInfo(4); car5.displayInfo(5);

            cout << "\n---- BIKES ----\n";
            bike1.displayInfo(1); bike2.displayInfo(2); bike3.displayInfo(3);
            bike4.displayInfo(4); bike5.displayInfo(5);

            cout << "\n---- TRUCKS ----\n";
            truck1.displayInfo(1); truck2.displayInfo(2); truck3.displayInfo(3);
            truck4.displayInfo(4); truck5.displayInfo(5);
            cout << "-----------------------------------------\n";
            break;

        case 2: {
            cout << "\nSelect vehicle type:\n";
            cout << "1. Car\n2. Bike\n3. Truck\nEnter choice: ";
            int opt = getValidatedInput(1, 3);

            int subOpt;
            if (opt == 1) {
                cout << "\n---- AVAILABLE CARS ----\n";
                car1.displayInfo(1); car2.displayInfo(2); car3.displayInfo(3);
                car4.displayInfo(4); car5.displayInfo(5);
                cout << "-------------------------\nSelect Car (1-5): ";
                subOpt = getValidatedInput(1, 5);
                Car* cars[] = {&car1, &car2, &car3, &car4, &car5};
                system.rentVehicle(cars[subOpt - 1], "Car");
            } else if (opt == 2) {
                cout << "\n---- AVAILABLE BIKES ----\n";
                bike1.displayInfo(1); bike2.displayInfo(2); bike3.displayInfo(3);
                bike4.displayInfo(4); bike5.displayInfo(5);
                cout << "-------------------------\nSelect Bike (1-5): ";
                subOpt = getValidatedInput(1, 5);
                Bike* bikes[] = {&bike1, &bike2, &bike3, &bike4, &bike5};
                system.rentVehicle(bikes[subOpt - 1], "Bike");
            } else {
                cout << "\n---- AVAILABLE TRUCKS ----\n";
                truck1.displayInfo(1); truck2.displayInfo(2); truck3.displayInfo(3);
                truck4.displayInfo(4); truck5.displayInfo(5);
                cout << "-------------------------\nSelect Truck (1-5): ";
                subOpt = getValidatedInput(1, 5);
                Truck* trucks[] = {&truck1, &truck2, &truck3, &truck4, &truck5};
                system.rentVehicle(trucks[subOpt - 1], "Truck");
            }
            break;
        }

        case 3:
            system.returnVehicle();
            break;

        case 4:
            system.showActiveRentals();
            break;

        case 5:
            system.showTotalProfit();
            break;

        case 6:
            cout << "Exiting Vehicle Rental System... Goodbye!\n";
            break;
        }

    } while (choice != 6);

    return 0;
}

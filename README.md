# EVChargeHub CLI – EV Charging Station Management System

EVChargeHub CLI is a console-based Electric Vehicle (EV) Charging Station Management System developed using **C++17**. It provides a modular platform to manage users, vehicles, charging stations, bookings, charging sessions, payments, and system reports.

The project uses Object-Oriented Programming (OOP), STL containers, and in-memory data management. It is designed with clean, modular code and does not require any external libraries or database systems.

## Features

### 1. User Management
- Register new users.
- View all registered users.
- Search users by ID.
- Update user information.
- Delete users.

### 2. Vehicle Management
- Register EV vehicles.
- View all registered vehicles.
- Search vehicles by registration number.
- Delete vehicles.
- View vehicles belonging to a particular user.

### 3. Charging Station Management
- Add charging stations.
- View all charging stations.
- Search stations by ID.
- Update station availability.
- Delete charging stations.
- Configure charging points and electricity prices.

### 4. Booking Management
- Create charging bookings.
- View all bookings.
- Search bookings by ID.
- Cancel bookings.
- View bookings by user ID.
- Validate user, vehicle ownership, and station availability.

### 5. Charging Management
- Start charging sessions.
- Stop charging sessions.
- Calculate energy consumption.
- Calculate charging costs.
- View charging session history.

### 6. Payment Management
- Process payments for completed charging sessions.
- View payment history.
- Search payments by ID.
- Prevent duplicate payments.

### 7. Reports and Dashboard
- Total registered users.
- Total registered vehicles.
- Total charging stations.
- Available charging stations.
- Booking statistics.
- Charging session statistics.
- Total energy consumed.
- Total payments and revenue.

## Technology Stack

| Component | Technology |
|---|---|
| Programming Language | C++17 |
| Compiler | GCC / MinGW |
| Interface | Command Line Interface |
| Programming Paradigm | Object-Oriented Programming |
| Data Structures | STL Vector |
| Storage | In-memory storage |
| IDE | Dev-C++ / VS Code / Any C++ IDE |
| Build System | Direct G++ compilation |

## Project Structure

```text
EVChargeHub/
│
├── main.cpp
│
├── include/
│   ├── Menu.h
│   ├── User.h
│   ├── Vehicle.h
│   ├── Station.h
│   ├── Booking.h
│   ├── ChargingSession.h
│   └── Payment.h
│
├── src/
│   ├── Menu.cpp
│   ├── User.cpp
│   ├── Vehicle.cpp
│   ├── Station.cpp
│   ├── Booking.cpp
│   ├── ChargingSession.cpp
│   └── Payment.cpp
│
├── build.bat
│
└── README.md
```

## Requirements for Windows

Before building the project, ensure your Windows system has:

1. Windows 10 or Windows 11.
2. A C++17-compatible GCC compiler.
3. MinGW-w64 or Dev-C++ with GCC configured.
4. Command Prompt or PowerShell.

### Option 1: Using Dev-C++

If Dev-C++ is already installed:

1. Open Dev-C++.
2. Create a Console Application project.
3. Select C++.
4. Add `main.cpp` and all `.cpp` files inside the `src` directory.
5. Configure the compiler to use C++17.
6. Add the `include` directory to the compiler's header search paths.
7. Compile and run the application.

### Option 2: Using MinGW GCC from Terminal

If GCC is not installed, install MinGW-w64 through MSYS2.

Official website:

https://www.msys2.org/

After installation, verify GCC:

```cmd
g++ --version
```

If GCC is not recognized, add its `bin` directory to the Windows PATH environment variable.

For example:

```text
C:\msys64\ucrt64\bin
```

## Building the Project on Windows

### Step 1: Clone the repository

```cmd
git clone https://github.com/jagan11421/EVCharge-CLI.git
```

Alternatively, download and extract the project ZIP.

### Step 2: Open the project directory

```cmd
cd EVChargeHub
```

### Step 3: Compile the project

Run:

```cmd
g++ -std=c++17 -Wall -Wextra -Iinclude main.cpp src/*.cpp -o EVChargeHub.exe
```

This command:
- Enables C++17.
- Enables compiler warnings.
- Includes header files from the `include` directory.
- Compiles the main application and all source files.
- Generates `EVChargeHub.exe`.

### Step 4: Run the application

In Command Prompt:

```cmd
EVChargeHub.exe
```

In PowerShell:

```powershell
.\EVChargeHub.exe
```

## Build Using build.bat

A Windows build script is included to simplify compilation and execution.

Create or use the `build.bat` file in the project root:

```bat
@echo off

echo ====================================
echo       Building EVChargeHub
echo ====================================

g++ -std=c++17 -Wall -Wextra -Iinclude main.cpp src/*.cpp -o EVChargeHub.exe

if %errorlevel% neq 0 (
    echo.
    echo Build failed!
    pause
    exit /b 1
)

echo.
echo Build successful!
echo Starting EVChargeHub...
echo.

EVChargeHub.exe

pause
```

Double-click `build.bat` to compile and launch the application.

**Note:** G++ must be installed and available in PATH for this script to work.

## How to Use the Application

After launching EVChargeHub, the main menu displays:

```text
====================================
          EV CHARGE HUB
====================================
1. User Management
2. Vehicle Management
3. Station Management
4. Booking Management
5. Charging Management
6. Payment Management
7. Generate Reports
0. Exit
====================================
Enter your choice:
```

Select the required option and follow the instructions displayed in the terminal.

### Recommended Workflow

For testing the complete application:

1. Register a user.
2. Register a vehicle for that user.
3. Add a charging station.
4. Create a booking.
5. Start a charging session.
6. Stop the charging session.
7. Process the payment.
8. Generate system reports.

## Charging Cost Calculation

The application calculates energy consumption and charging costs using:

**Energy Consumption:**

```text
Energy (kWh) = Charging Power (kW) × Duration (Hours)
```

**Charging Cost:**

```text
Total Cost = Energy Consumed × Price per kWh
```

Example:

```text
Charging Power: 7 kW
Duration: 2 hours
Price per kWh: Rs. 12.50

Energy Consumed: 14 kWh
Total Cost: Rs. 175.00
```

## Object-Oriented Programming Concepts

The project demonstrates the following C++ concepts:

- Classes and Objects
- Encapsulation
- Constructors
- Access Specifiers
- Member Functions
- References
- Constructor Initialization Lists
- STL Vectors
- Iterators
- Modular Programming
- Header and Source File Separation
- Exception-free input validation and conditional checks

## Data Storage

EVChargeHub CLI currently uses **memory-only storage**.

- Application data is maintained using STL vectors.
- No database is required.
- No external storage files are generated.
- All registered users, vehicles, bookings, sessions, and payments exist only during the current execution.
- All application data is lost when the program terminates.

## Limitations

- No permanent database storage.
- No graphical user interface.
- Charging duration is manually entered.
- No real-time charging hardware integration.
- Payment processing is simulated.
- No network or online payment gateway integration.

## Future Enhancements

- Database integration using SQLite or PostgreSQL.
- Graphical interface.
- Real-time charging session monitoring.
- Online payment gateway integration.
- User authentication.
- Charging station reservation scheduling.
- Exportable CSV reports.
- Admin dashboard.

## License

This project is developed for educational and academic purposes.

---

**EVChargeHub CLI**  
A modular C++17-based EV Charging Station Management System.

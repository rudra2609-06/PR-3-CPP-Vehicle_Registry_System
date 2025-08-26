# PR-3-CPP-Vehicle_Registry_System
-----

# Vehicle Registry System

This is a console-based C++ application designed to manage a registry of various vehicles. The system uses object-oriented programming (OOP) principles, including inheritance and polymorphism, to create a flexible and extensible structure for handling different vehicle types.

## Features

The application provides a user-friendly menu to perform the following operations:

  * **Add Vehicle**: Add new vehicles to the registry. The program supports adding different types of vehicles, including:
      * Electric Cars
      * Flying Cars
      * Sedans
      * SUVs
  * **View All Vehicles**: Display a list of all vehicles currently stored in the registry, showing their details.
  * **Search by ID**: Find and display the details of a specific vehicle by its unique ID.
  * **Exit**: Terminate the application.

## How It Works

The system is built on a class hierarchy that demonstrates the power of C++ OOP.

  * `Vehicle` is the base class, containing common attributes like `vehicleID`, `model`, `manufacturer`, and `year`.
  * `Car` inherits from `Vehicle`, adding a `fuelType` attribute.
  * More specific vehicle types like `ElectricCar`, `Sedan`, and `SUV` inherit from `Car`, adding their own unique attributes (e.g., `batteryCapacity` for `ElectricCar`).
  * `FlyingCar` uses **multiple inheritance**, inheriting from both `Aircraft` and `Car`, as it has attributes of both a car and a flying machine (`flightRange`).
  * The `VehicleRegistry` class manages the collection of vehicles using an array of `Vehicle` pointers, showcasing polymorphism by treating all derived vehicle objects as their base `Vehicle` type.

## Getting Started

### Prerequisites

You will need a C++ compiler (e.g., g++) and a code editor like VS Code installed on your system.

### Compiling and Running

1.  Save the provided C++ code as `vehicle_registry_system.cpp`.
2.  Open your terminal or command prompt.
3.  Navigate to the directory where you saved the file.
4.  Compile the code using a C++ compiler:
    ```bash
    g++ vehicle_registry_system.cpp -o vehicle_registry_system
    ```
5.  Run the executable:
    ```bash
    ./vehicle_registry_system
    ```

## Screenshots

The following screenshots illustrate the application's functionality.

### 1\. Adding an Electric Car

This screenshot shows the process of adding a new Electric Car, where the user enters details like Vehicle ID, Model, Manufacturer, Year, Fuel Type, and Battery Capacity.

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/085dd73b-1f36-464c-b88f-ccef38f0a10e" />


\<br\>

### 2\. Viewing All Vehicles and Searching

This screenshot demonstrates two key features: first, displaying all vehicles in the registry (after adding the Electric Car), and second, successfully searching for a specific vehicle using its ID.

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/b271447b-57e2-465b-b869-cef7e3706b54" />


-----

### About the Developer

  * **Rudra Thakkar**
  * BCA (Data Science) Student
  * Practicing **Full Stack Development & C++**

#include <iostream>
using namespace std;

class Vehicle
{
protected:
    int vehicleID, year;
    string manufacturer, model;
    static int totalVehicles;

public:
    Vehicle(int vehicleID, string model, string manufacturer, int year)
    {
        this->vehicleID = vehicleID;
        this->model = model;
        this->manufacturer = manufacturer;
        this->year = year;
        totalVehicles++;
    }

    void setVehicle(int vehicleID, string model, string manufacturer, int year)
    {
        this->vehicleID = vehicleID;
        this->model = model;
        this->manufacturer = manufacturer;
        this->year = year;
    }

    void getVehicle()
    {
        cout << "Vehicle Id is: " << this->vehicleID << endl
             << "Vehicle Model is: " << this->model << endl
             << "Vehicle Manufacturer is: " << this->manufacturer << endl
             << "Vehicle Manufacturing year is: " << this->year << endl;
    }

    int getVehicleID()
    {
        return vehicleID;
    }

    ~Vehicle()
    {
        totalVehicles--;
    }
};

int Vehicle::totalVehicles = 0;

class Car : public Vehicle
{
protected:
    string fuelType;

public:
    Car(int vehicleID, string model, string manufacturer, int year, string fuelType)
        : Vehicle(vehicleID, model, manufacturer, year)
    {
        this->fuelType = fuelType;
    }

    void setCar(int fuelType)
    {
        this->fuelType = fuelType;
    }

    void getCar()
    {
        Vehicle::getVehicle();
        cout << "Vehicle fuel type is: " << this->fuelType << endl;
    }
};

class ElectricCar : public Car
{
protected:
    float batteryCapacity;

public:
    ElectricCar(int vehicleID, string model, string manufacturer, int year, string fuelType, float batteryCapacity)
        : Car(vehicleID, model, manufacturer, year, fuelType)
    {
        this->batteryCapacity = batteryCapacity;
    }

    void setElectricCar(float batteryCapacity)
    {
        this->batteryCapacity = batteryCapacity;
    }

    void getElectricCar()
    {
        Car::getCar();
        cout << "Vehicle Battery Capacity is: " << this->batteryCapacity << " KW" << endl;
    }
};

class Aircraft
{
protected:
    float flightRange;

public:
    Aircraft(float flightRange)
    {
        this->flightRange = flightRange;
    }

    void setAircraft(float flightRange)
    {
        this->flightRange = flightRange;
    }

    void getAircraft()
    {
        cout << "Aircraft Range is: " << this->flightRange << endl;
    }
};

class FlyingCar : public Aircraft, public Car
{
public:
    FlyingCar(int vehicleID, string model, string manufacturer, int year, string fuelType, float flightRange)
        : Car(vehicleID, model, manufacturer, year, fuelType), Aircraft(flightRange)
    {
    }

    void getFlyingCar()
    {
        Car::getCar();
        Aircraft::getAircraft();
    }
};

class SportsCar : public ElectricCar
{
protected:
    float topSpeed;

public:
    SportsCar(int vehicleID, string model, string manufacturer, int year, string fuelType, float batteryCapacity, float topSpeed)
        : ElectricCar(vehicleID, model, manufacturer, year, fuelType, batteryCapacity)
    {
        this->topSpeed = topSpeed;
    }

    void setSportsCar(float topSpeed)
    {
        this->topSpeed = topSpeed;
    }

    void getSportsCar()
    {
        ElectricCar::getElectricCar();
        cout << "Vehicle Top Speed is: " << this->topSpeed << endl;
    }
};

class Sedan : public Car
{
public:
    Sedan(int vehicleID, string model, string manufacturer, int year, string fuelType)
        : Car(vehicleID, model, manufacturer, year, fuelType) {}

    void getSedan()
    {
        Car::getCar();
    }
};

class SUV : public Car
{
public:
    SUV(int vehicleID, string model, string manufacturer, int year, string fuelType)
        : Car(vehicleID, model, manufacturer, year, fuelType) {}

    void getSUV()
    {
        Car::getCar();
    }
};

class VehicleRegistry
{
private:
    Vehicle *vech[100];
    int VehicleCount = 0;

public:
    void addVehicle(Vehicle *v)
    {
        vech[VehicleCount++] = v;
    }

    void displayVehicle()
    {
        cout << endl
             << "-----------Vehicle Registry-----------" << endl;
        for (int i = 0; i < VehicleCount; i++)
        {
            cout << "Vehicle #" << (i + 1) << endl;
            vech[i]->getVehicle();
        }
    }

    void searchVehicleByID(int vehicleID)
    {
        bool found = false;
        for (int j = 0; j < VehicleCount; j++)
        {
            if (vech[j]->getVehicleID() == vehicleID)
            {
                cout << endl
                     << "----------Vehicle Found----------" << endl;
                vech[j]->getVehicle();
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "No vehicle found corresponding to entered input" << endl;
        }
    }
};

void inputCommonDetails(int &id, string &model, string &manufacturer, int &year)
{
    cout << "Enter Vehicle ID: ";
    cin >> id;
    cout << "Enter Vehicle Model: ";
    cin.ignore();
    getline(cin, model);
    cout << "Enter Manufacturer: ";
    getline(cin, manufacturer);
    cout << "Enter Year: ";
    cin >> year;
}

int main()
{
    VehicleRegistry registry;
    int vehicleID, year, choice_int, size, i;
    string fueltype, model, manufacturer;
    char choice_char;
    float batteryCapacity, flightRange, topSpeed;

    do
    {
        cout << endl
             << "--------------Vehicle Registry System--------------" << endl;
        cout << "1.Add Vehicle" << endl;
        cout << "2.View All Vehicle" << endl;
        cout << "3.Search by ID" << endl;
        cout << "0.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice_int;

        switch (choice_int)
        {
        case 1:
            do
            {
                cout << endl
                     << "Which kind of vehicle you want to add ?" << endl;
                cout << "A.To Add Car" << endl;
                cout << "B.To Exit back to registry menu" << endl;
                cout << "C.To Exit the program" << endl;
                cout << "Enter your choice: ";
                cin >> choice_char;

                switch (choice_char)
                {
                case 'A':
                    do
                    {
                        cout << endl
                             << "Which Car do you want to add ?" << endl;
                        cout << "4.To add Electric Car" << endl;
                        cout << "5.To add Flying Car" << endl;
                        cout << "6.To add Sedan" << endl;
                        cout << "7.To add SUV" << endl;
                        cout << "8.To Exit back to registry menu" << endl;
                        cout << "0.To Exit Program" << endl;
                        cout << "Enter your choice:";
                        cin >> choice_int;

                        switch (choice_int)
                        {
                        case 4:
                            cout << "Enter Size (max = 100) : ";
                            cin >> size;
                            for (i = 0; i < size; i++)
                            {
                                inputCommonDetails(vehicleID, model, manufacturer, year);
                                cout << "Enter fuel Type: ";
                                cin.ignore();
                                getline(cin, fueltype);
                                cout << "Enter Battery Capacity (in KW): ";
                                cin >> batteryCapacity;

                                registry.addVehicle(new ElectricCar(vehicleID, model, manufacturer, year, fueltype, batteryCapacity));
                            }
                            break;

                        case 5:
                            cout << "Enter Size (max = 100) : ";
                            cin >> size;
                            for (i = 0; i < size; i++)
                            {
                                inputCommonDetails(vehicleID, model, manufacturer, year);
                                cout << "Enter fuel type: ";
                                cin.ignore();
                                getline(cin, fueltype);
                                cout << "Enter Flight Range: ";
                                cin >> flightRange;

                                registry.addVehicle(new FlyingCar(vehicleID, model, manufacturer, year, fueltype, flightRange));
                            }
                            break;

                        case 6:
                            cout << "Enter Size (max = 100) : ";
                            cin >> size;
                            for (i = 0; i < size; i++)
                            {
                                inputCommonDetails(vehicleID, model, manufacturer, year);
                                cout << "Enter fuel type: ";
                                cin.ignore();
                                getline(cin, fueltype);
                                registry.addVehicle(new Sedan(vehicleID, model, manufacturer, year, fueltype));
                            }
                            break;

                        case 7:
                            cout << "Enter Size (max = 100) : ";
                            cin >> size;
                            if (size <= 100)
                            {
                                for (i = 0; i < size; i++)
                                {
                                    inputCommonDetails(vehicleID, model, manufacturer, year);
                                    cout << "Enter fuel type: ";
                                    cin.ignore();
                                    getline(cin, fueltype);
                                    registry.addVehicle(new Sedan(vehicleID, model, manufacturer, year, fueltype));
                                }
                            }
                            else
                            {
                                cout << "Maximum Size is 100!" << endl;
                            }
                            break;

                        case 8:
                            cout << endl
                                 << "Returning to vehicle menu..." << endl;
                            break;

                        case 0:
                            cout << "Exiting..." << endl;
                            return 0;

                        default:
                            cout << "Enter valid input" << endl;
                        }
                        break;

                    } while (choice_int != 8);
                    break;

                case 'C':
                    cout << "Exiting Program..." << endl;
                    return 0;

                case 'B':
                    cout << "Exiting" << endl;
                    break;

                default:
                    cout << "Enter valid input" << endl;
                    break;
                }

            } while (choice_char != 'B');
            break;

        case 2:
            registry.displayVehicle();
            break;

        case 3:
            cout << "Enter vehicle id: ";
            cin >> vehicleID;
            registry.searchVehicleByID(vehicleID);
            break;

        case 0:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << endl
                 << "Enter valid input" << endl;
        }

    } while (choice_int != 0 && choice_char != 'C');

    return 0;
}

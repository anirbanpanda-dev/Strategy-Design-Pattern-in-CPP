#include <iostream> 
using namespace std;

class DriveStrategy{
    public:
    virtual void drive(int speed) = 0;
};

class NormalDriveStrategy: public DriveStrategy{
    int speed;
    bool fuelburning;
    public:
    virtual void drive(int speed) override;
};

class ProDriveStrategy: public DriveStrategy{
    int speed;
    bool fuelburning;
    public:
    virtual void drive(int speed) override;
};

class Vehicle{
    DriveStrategy* drivestrategy;
    public: 
    Vehicle(DriveStrategy *driveobj );
    void drive(int speed);
};

class SportVehicle: public Vehicle{
    public: 
    SportVehicle();
};

class OffRoadVehicle: public Vehicle{
    public: 
    OffRoadVehicle();
};

class PassangerVehicle: public Vehicle{
    public: 
    PassangerVehicle();
};
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
    virtual void drive(int speed) override{
        cout << " NormalDriveStrategy drive \n";
        this->speed = speed;
        if(speed>60){
            fuelburning = true;
        }
    }
};

class ProDriveStrategy: public DriveStrategy{
    int speed;
    bool fuelburning;
    public:
    virtual void drive(int speed) override{
        cout << " ProDriveStrategy drive \n";
        this->speed = speed;
        if(speed >100){
            fuelburning = true;
        }
    }
};

class Vehicle{
    DriveStrategy* drivestrategy;
    public: 
    Vehicle(DriveStrategy *driveobj ){
        this->drivestrategy = driveobj;
    }
    void drive(int speed){
        drivestrategy->drive(speed);
    }
};

class SportVehicle: public Vehicle{
    public: 
    SportVehicle(): Vehicle(new ProDriveStrategy()){
        std::cout << " sports vehicle \n";
    }

};

class OffRoadVehicle: public Vehicle{
    public: 
    OffRoadVehicle(): Vehicle(new ProDriveStrategy()){
        std::cout << " offroad vehicle \n";
    }
};

class PassangerVehicle: public Vehicle{
    public: 
    PassangerVehicle(): Vehicle(new NormalDriveStrategy()){
        std::cout << " psngr vehicle \n";
    }
};


int main(){
    unique_ptr<PassangerVehicle> p_vehicle = make_unique<PassangerVehicle>();
    p_vehicle->drive(10);
}
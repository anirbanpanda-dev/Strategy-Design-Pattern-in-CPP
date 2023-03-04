#include "Strategy.h"
using namespace std;


void NormalDriveStrategy::drive(int speed) {
    cout << " NormalDriveStrategy drive \n";
        this->speed = speed;
        if(speed>60){
            fuelburning = true;
        }
}

void ProDriveStrategy::drive(int speed) {
    cout << " ProDriveStrategy drive \n";
        this->speed = speed;
        if(speed >100){
            fuelburning = true;
        }
}

Vehicle::Vehicle(DriveStrategy *driveobj ){
    this->drivestrategy = driveobj;
}

void Vehicle::drive(int speed){
    drivestrategy->drive(speed);
}

SportVehicle::SportVehicle(): Vehicle(new ProDriveStrategy()){
    std::cout << " sports vehicle \n";
}

OffRoadVehicle::OffRoadVehicle(): Vehicle(new ProDriveStrategy()){
    std::cout << " offroad vehicle \n";
}

PassangerVehicle::PassangerVehicle(): Vehicle(new NormalDriveStrategy()){
    std::cout << " psngr vehicle \n";
}


int main(){
    unique_ptr<PassangerVehicle> p_vehicle = make_unique<PassangerVehicle>();
    p_vehicle->drive(10);
}
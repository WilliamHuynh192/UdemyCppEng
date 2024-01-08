#include <cmath>
#include <cstdint>
#include <iostream>

#include "AdConstants.h"
#include "AdFunctions.h"

float Ad::Utils::kph_to_mps(const float kph) {
    return kph / 3.6F;
}

Ad::Types::VehicleType Ad::Data::init_ego_vehicle() {
    auto vehicleType = Ad::Types::VehicleType{-1, Ad::Types::LaneAssociationType::Center, 135};
    return vehicleType;
}

void Ad::Visualize::print_vehicle(const Ad::Types::VehicleType vehicle) {
    std::printf("Id: %d, Speed: %d, Lane: %d\n", vehicle.id, vehicle.speed, vehicle.lane);
}

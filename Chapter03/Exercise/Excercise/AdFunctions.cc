#include <cmath>
#include <cstdint>
#include <iostream>

#include "AdConstants.h"
#include "AdFunctions.h"

namespace Ad
{
namespace Utils
{

float kph_to_mps(const float kph)
{
    return kph / 3.6F;
}

} // namespace Utils

namespace Data
{

Ad::Types::VehicleType init_ego_vehicle()
{
    return Ad::Types::VehicleType{
        .id = Ad::Constants::EGO_VEHICLE_ID,
        .lane = Ad::Types::LaneAssociationType::CENTER,
        .speed_mps = Ad::Utils::kph_to_mps(135.0F),
        .distance_m = 0.0F,
    };
}

Ad::Types::NeighborVehiclesType init_vehicles()
{
    Ad::Types::NeighborVehiclesType neighborVehicles{};

    // Left lane
    Ad::Types::VehicleType vehicle1
    {
        .id = 0,
        .lane = Ad::Types::LaneAssociationType::LEFT,
        .speed_mps = 40,
        .distance_m = 69
    };

    Ad::Types::VehicleType vehicle2
    {
        .id = 1,
        .lane = Ad::Types::LaneAssociationType::LEFT,
        .speed_mps = 30,
        .distance_m = 50
    };

    neighborVehicles.leftLaneVehicle[0] = vehicle1;
    neighborVehicles.leftLaneVehicle[1] = vehicle2;

    // Center lane
    Ad::Types::VehicleType vehicle3
    {
        .id = 2,
        .lane = Ad::Types::LaneAssociationType::CENTER,
        .speed_mps = 10,
        .distance_m = 40
    };

    Ad::Types::VehicleType vehicle4
    {
        .id = 3,
        .lane = Ad::Types::LaneAssociationType::CENTER,
        .speed_mps = 70,
        .distance_m = 35
    };

    neighborVehicles.centerLaneVehicle[0] = vehicle3;
    neighborVehicles.centerLaneVehicle[1] = vehicle4;

    // Right lane
    Ad::Types::VehicleType vehicle5
    {
        .id = 4,
        .lane = Ad::Types::LaneAssociationType::RIGHT,
        .speed_mps = 85,
        .distance_m = 23
    };

    Ad::Types::VehicleType vehicle6
    {
        .id = 5,
        .lane = Ad::Types::LaneAssociationType::RIGHT,
        .speed_mps = 100,
        .distance_m = 17
    };

    neighborVehicles.rightLaneVehicle[0] = vehicle5;
    neighborVehicles.rightLaneVehicle[1] = vehicle6;
}

} // namespace Data
} // namespace Ad

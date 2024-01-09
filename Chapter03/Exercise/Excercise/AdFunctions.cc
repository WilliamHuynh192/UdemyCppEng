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

void init_lanes_vehicle(
    std::array<Ad::Types::VehicleType, Ad::Constants::NUM_VEHICLES_ON_LANE>& vehicleLane,
    int index,
    std::int32_t id,
    Ad::Types::LaneAssociationType lane,
    float speed_mps,
    float distance_m
)
{
    Ad::Types::VehicleType vehicle
    {
        .id = id,
        .lane = lane,
        .speed_mps = speed_mps,
        .distance_m = distance_m
    };

    vehicleLane[index] = vehicle;
}

Ad::Types::NeighborVehiclesType init_vehicles()
{
    Ad::Types::NeighborVehiclesType neighborVehicles{};

    // Left lane
    init_lanes_vehicle(
        neighborVehicles.leftLaneVehicle,
        0,
        0,
        Ad::Types::LaneAssociationType::LEFT,
        Ad::Utils::kph_to_mps(40),
        69
    );

    init_lanes_vehicle(
        neighborVehicles.leftLaneVehicle,
        1,
        1,
        Ad::Types::LaneAssociationType::LEFT,
        Ad::Utils::kph_to_mps(30),
        50
    );

    // Center lane
    init_lanes_vehicle(
        neighborVehicles.centerLaneVehicle,
        0,
        2,
        Ad::Types::LaneAssociationType::CENTER,
        Ad::Utils::kph_to_mps(24),
        40
    );

    init_lanes_vehicle(
        neighborVehicles.leftLaneVehicle,
        1,
        3,
        Ad::Types::LaneAssociationType::CENTER,
        Ad::Utils::kph_to_mps(70),
        35
    );

    // Right lane
    init_lanes_vehicle(
        neighborVehicles.rightLaneVehicle,
        0,
        4,
        Ad::Types::LaneAssociationType::RIGHT,
        Ad::Utils::kph_to_mps(85),
        23
    );

    init_lanes_vehicle(
        neighborVehicles.rightLaneVehicle,
        1,
        5,
        Ad::Types::LaneAssociationType::RIGHT,
        Ad::Utils::kph_to_mps(100),
        17
    );
}

} // namespace Data
} // namespace Ad

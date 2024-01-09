#pragma once

#include <cstdint>
#include <array>

#include "AdConstants.h"

namespace Ad
{
namespace Types
{

enum class LaneAssociationType
{
    LEFT,
    CENTER,
    RIGHT,
    NONE,
};

struct VehicleType
{
    std::int32_t id;
    LaneAssociationType lane;
    float speed_mps;
    float distance_m;
};

struct NeighborVehiclesType
{
    std::array<VehicleType, Ad::Constants::NUM_VEHICLES_ON_LANE> leftLaneVehicle;
    std::array<VehicleType, Ad::Constants::NUM_VEHICLES_ON_LANE> centerLaneVehicle;
    std::array<VehicleType, Ad::Constants::NUM_VEHICLES_ON_LANE> rightLaneVehicle;
};

} // namespace Types
} // namespace Ad

#pragma once

#include <cstdint>

#include "AdConstants.h"

namespace Ad
{
namespace Types
{
enum class LaneAssociationType {
    Unknown,
    Left,
    Center,
    Right,
};

struct VehicleType
{
    int id;
    LaneAssociationType lane;
    int speed;
    int relativeDistance;
};
}
}

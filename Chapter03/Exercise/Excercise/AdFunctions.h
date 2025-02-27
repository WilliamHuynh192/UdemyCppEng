#pragma once

#include "AdTypes.h"

namespace Ad
{
namespace Utils
{

float kph_to_mps(const float kph);

} // namespace Utils

namespace Data
{

Ad::Types::VehicleType init_ego_vehicle();

void init_lanes_vehicle(
    std::array<Ad::Types::VehicleType, Ad::Constants::NUM_VEHICLES_ON_LANE>& vehicleLane,
    int index,
    std::int32_t id,
    Ad::Types::LaneAssociationType lane,
    float speed_mps,
    float distance_m
);

Ad::Types::NeighborVehiclesType init_vehicles();

} // namespace Data

namespace Visualize
{

void print_vehicle(const Ad::Types::VehicleType &vehicle);

void print_neighbor_vehicles(const Ad::Types::NeighborVehiclesType &vehicles);

void print_scene(const Ad::Types::VehicleType &ego_vehicle,
                 const Ad::Types::NeighborVehiclesType &vehicles);

} // namespace Visualize

} // namespace Ad

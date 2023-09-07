#pragma once

#include "nigiri/types.h"

namespace nigiri::routing {

struct update_costs {

  update_costs() : travel_time_(duration_t::max()) {}
  update_costs(duration_t travel_time) : travel_time_(travel_time) {}

  duration_t travel_time_;
};

}  // namespace nigiri::routing

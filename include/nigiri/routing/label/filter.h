#pragma once

#include "nigiri/types.h"

namespace nigiri::routing {

template <typename... Filters>
struct filter {
  template <typename Label>
  static bool is_filtered(Label const& l,
                          duration_t const smallest_known_travel_time) {
    return (Filters::is_filtered(l, smallest_known_travel_time) || ...);
  }
};

}  // namespace nigiri::routing

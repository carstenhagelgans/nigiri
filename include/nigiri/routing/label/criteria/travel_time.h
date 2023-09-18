#pragma once

#include "nigiri/routing/limits.h"
#include "nigiri/routing/mcraptor/update_costs.h"

namespace nigiri::routing {

struct travel_time_data {
  duration_t travel_time_;
};

struct travel_time_initializer {
  template <typename Label>
  static void initialize(Label& l) {
    l.travel_time_ = std::abs(l.now_ - l.start_);
  }
};

struct travel_time_updater {
  template <typename Label>
  static void update(Label& l, update_costs const& costs) {
    l.travel_time_ += costs.travel_time_;
  }
};

struct travel_time_dominator {
  template <typename Label>
  struct dominator_info {
    dominator_info(Label const& a, Label const& b)
        : greater_(a.travel_time_ > b.travel_time_),
          smaller_(a.travel_time_ < b.travel_time_) {}

    inline bool greater() const { return greater_; }
    inline bool smaller() const { return smaller_; }

    bool greater_, smaller_;
  };

  template <typename Label>
  static dominator_info<Label> get_dominator_info(Label const& a,
                                                  Label const& b) {
    return dominator_info<Label>(a, b);
  }
};

struct travel_time_filter {
  template <typename Label>
  static bool is_filtered(Label const& l,
                          duration_t const smallest_known_travel_time) {
    return l.travel_time_ >= smallest_known_travel_time;
  }
};

}  // namespace nigiri::routing

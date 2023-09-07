#pragma once

#include "nigiri/routing/mcraptor/update_costs.h"

namespace nigiri::routing {

template <typename... Updaters>
struct updater;

template <typename FirstUpdater, typename... RestUpdaters>
struct updater<FirstUpdater, RestUpdaters...> {
  template <typename Label>
  static void update(Label& l, update_costs const& costs) {
    FirstUpdater::update(l, costs);
    updater<RestUpdaters...>::update(l, costs);
  }
};

template <>
struct updater<> {
  template <typename Label>
  static void update(Label&, update_costs const&){};
};

}  // namespace nigiri::routing
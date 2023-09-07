#pragma once

#include "nigiri/routing/label/label.h"

#include "nigiri/routing/label/dominator.h"
#include "nigiri/routing/label/initializer.h"
#include "nigiri/routing/label/updater.h"

#include "nigiri/routing/label/criteria/travel_time.h"
#include "nigiri/routing/label/tie_breakers.h"

namespace nigiri::routing {

using raptor_label = label<label_data<travel_time_data>,
                           initializer<travel_time_initializer>,
                           updater<travel_time_updater>,
                           dominator<default_tb, travel_time_dominator>>;

}  // namespace nigiri::routing

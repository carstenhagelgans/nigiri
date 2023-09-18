#pragma once

#include "nigiri/types.h"

namespace nigiri::routing {

template <typename... CriteriaData>
struct label_data : public CriteriaData... {};

template <typename Data,
          typename Initializer,
          typename Updater,
          typename Dominator,
          typename Filter>
struct label : public Data {
  label() = default;
  label(time_t now) : now_(now) { Initializer::initialize(*this); };

  time_t start_, now_;
};

}  // namespace nigiri::routing

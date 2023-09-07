#pragma once

namespace nigiri::routing {

struct default_tb {
  template <typename Label>
  static bool dominates(bool, Label const&, Label const&) {
    return true;
  }
};

}  // namespace nigiri::routing

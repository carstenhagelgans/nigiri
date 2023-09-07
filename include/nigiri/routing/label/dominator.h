#pragma once

namespace nigiri::routing {
template <typename TieBreaker, typename... Dominators>
struct dominator;

template <typename TieBreaker,
          typename FirstDominator,
          typename... RestDominators>
struct dominator<TieBreaker, FirstDominator, RestDominators...> {
  template <typename Label>
  static bool dominates(bool could_dominate, Label const& a, Label const& b) {
    auto const dominator_info = FirstDominator::get_dominator_info(a, b);
    return !dominator_info.greater &&
           dominator<TieBreaker, RestDominators...>::dominates(
               could_dominate || dominator_info.smaller(), a, b);
  }
};

template <typename TieBreaker>
struct dominator<TieBreaker> {
  template <typename Label>
  static bool dominates(bool could_dominate, Label const& a, Label const& b) {
    return TieBreaker::dominates(could_dominate, a, b);
  }
};

}  // namespace nigiri::routing

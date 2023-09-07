#pragma once

namespace nigiri::routing {

template <typename... Initializers>
struct initializer;

template <typename FirstInitializer, typename... RestInitializer>
struct initializer<FirstInitializer, RestInitializer...> {
  template <typename Label>
  static void initialize(Label& l) {
    FirstInitializer::initialize(l);
    initializer<RestInitializer...>::initialize(l);
  }
};

template <>
struct initializer<> {
  template <typename Label>
  static void initialize(Label&) {}
};

}  // namespace nigiri::routing

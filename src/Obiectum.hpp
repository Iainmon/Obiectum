#pragma once

typedef unsigned long long uint64_t;
uint64_t micros(void);

namespace obiectum {}

#include "Component.hpp"
#include "GameObject.hpp"
#include "Hierarchy.hpp"
#include "physics/Vector.hpp"
#include "components/Components.hpp"

template<class ... Types> struct Tuple {};


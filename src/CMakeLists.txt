rock_library(numeric
    HEADERS
        Combinatorics.hpp
        FitPolynom.hpp
        Histogram.hpp
        IntegerPartitioning.hpp
        LimitedCombination.hpp
        MatchTemplate.hpp
        PlaneFitting.hpp
        Stats.hpp
    SOURCES
        Combinatorics.cpp
        IntegerPartitioning.cpp
    DEPS_PKGCONFIG base-types base-lib
)

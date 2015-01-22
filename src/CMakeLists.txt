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
        Twiddle.hpp
    SOURCES
        Combinatorics.cpp
        IntegerPartitioning.cpp
        Twiddle.cpp
    DEPS_PKGCONFIG base-types base-lib
)

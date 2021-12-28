add_library(day24 STATIC
    src/Day24.cpp
)
target_include_directories(day24 BEFORE
    PUBLIC include
)
target_link_libraries(
  day24
  day
)

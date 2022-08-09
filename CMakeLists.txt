cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(libredwg-playground C CXX)

add_library(libredwg STATIC IMPORTED)

set_property(
  TARGET libredwg APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG
)

set_target_properties(libredwg PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${LIBREDWG_ROOT}/lib/libredwg.a"
)

set_property(
  TARGET libredwg APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE
)

set_target_properties(libredwg PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${LIBREDWG_ROOT}/lib/libredwg.a"
)
  
set_target_properties(libredwg PROPERTIES
  MAP_IMPORTED_CONFIG_MINSIZEREL Release
  MAP_IMPORTED_CONFIG_RELWITHDEBINFO Release
)

target_include_directories(libredwg INTERFACE "${LIBREDWG_ROOT}/include")

SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

add_executable(${PROJECT_NAME}
    "src/main.cpp"
)

target_link_libraries(${PROJECT_NAME} libredwg)

cmake_minimum_required(VERSION 3.14.0)
project(playground VERSION 0.1.0 LANGUAGES C CXX)

### Env Setup ###
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
##################

### Dependency Fetching ###
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
###########################

# Build library from `lib/` sources and link into targets
file(GLOB_RECURSE LIB_SOURCES CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.c"
)
aux_source_directory(lib ALL_LIB_SOURCES)
add_library(src_lib STATIC ${LIB_SOURCES})
target_include_directories(src_lib PUBLIC
  ${ALL_LIB_SOURCES}  
  "${CMAKE_CURRENT_SOURCE_DIR}/lib"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/board"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/player"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/interface"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/strategy"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/game"
)
target_compile_features(src_lib PUBLIC cxx_std_23)
add_executable(app lib/main.cpp)
target_link_libraries(app PRIVATE src_lib)


### TESTING SETUP ###

include(CTest)
enable_testing()
aux_source_directory(tests ALL_TESTS)
add_executable(
  tests
  ${ALL_TESTS}
)
target_link_libraries(
  tests
  GTest::gtest_main
  src_lib
)

include(GoogleTest)
gtest_discover_tests(tests)

########################
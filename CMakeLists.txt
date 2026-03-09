cmake_minimum_required(VERSION 3.14)
project(cputils VERSION 1.0.0 LANGUAGES CXX)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# Header-only interface library
add_library(cputils INTERFACE)

target_include_directories(cputils INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_compile_features(cputils INTERFACE cxx_std_17)

# Install headers
install(
    DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Install target export
install(
    TARGETS cputils
    EXPORT cputilsTargets
)

install(
    EXPORT cputilsTargets
    FILE cputilsTargets.cmake
    NAMESPACE cputils::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/cputils
)

# Generate package config files
configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cputilsConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cputilsConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/cputils
)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/cputilsConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/cputilsConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/cputilsConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/cputils
)

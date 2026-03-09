cmake_minimum_required(VERSION 3.14)
project(cputils VERSION 1.0.0 LANGUAGES CXX)

# Header-only interface library
add_library(cputils INTERFACE)
target_include_directories(cputils INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
target_compile_features(cputils INTERFACE cxx_std_17)

# Install rules
include(GNUInstallDirs)
install(TARGETS cputils EXPORT cputilsTargets)
install(FILES include/cputils.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT cputilsTargets
    FILE cputilsTargets.cmake
    NAMESPACE cputils::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/cputils
)

# Package config
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/cputilsConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/cputilsConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/cputils
)

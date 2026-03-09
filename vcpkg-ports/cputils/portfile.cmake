vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO himaenshuu/cputils
    REF "v${VERSION}"
    SHA512 0  # Replace with: vcpkg hash <downloaded-tarball> after first release tag
    HEAD_REF main
)

set(VCPKG_BUILD_TYPE release)
vcpkg_cmake_configure(SOURCE_PATH "${SOURCE_PATH}")
vcpkg_cmake_install()
vcpkg_fixup_cmake_targets(CONFIG_PATH lib/cmake/cputils)

file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug")
vcpkg_install_copyright(FILE_LIST "${SOURCE_PATH}/LICENSE")

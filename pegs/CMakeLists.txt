find_package(PkgConfig)

pkg_check_modules(SFML REQUIRED sfml-all)

add_executable(
    pegs
    main.cpp
    peg.cpp
)

target_link_libraries(pegs ${SFML_LIBRARIES})

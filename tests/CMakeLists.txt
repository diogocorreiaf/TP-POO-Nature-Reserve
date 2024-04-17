# tests/CMakeLists.txt

# Include Google Test framework
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Add your test files
add_executable(tests test_main.cpp)

# Link your test executable with the Google Test libraries
target_link_libraries(tests gtest gtest_main)

# Add all the source files from your main project
target_sources(tests PRIVATE
        ${CMAKE_SOURCE_DIR}/main.cpp
        ${CMAKE_SOURCE_DIR}/Animal.cpp
        ${CMAKE_SOURCE_DIR}/Food.cpp
        ${CMAKE_SOURCE_DIR}/Interface.cpp
        ${CMAKE_SOURCE_DIR}/Reserva.cpp
        ${CMAKE_SOURCE_DIR}/Coelho.cpp
        ${CMAKE_SOURCE_DIR}/Ovelha.cpp
        ${CMAKE_SOURCE_DIR}/Lobo.cpp
        ${CMAKE_SOURCE_DIR}/Canguru.cpp
        ${CMAKE_SOURCE_DIR}/Relva.cpp
        ${CMAKE_SOURCE_DIR}/Bife.cpp
        ${CMAKE_SOURCE_DIR}/Cenoura.cpp
        ${CMAKE_SOURCE_DIR}/Corpo.cpp
        ${CMAKE_SOURCE_DIR}/Utils.cpp
        ${CMAKE_SOURCE_DIR}/Storage.cpp
)

# Link your test executable with your main project
target_link_libraries(tests TP2223)

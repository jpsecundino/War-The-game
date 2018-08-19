project(war)

add_executable(war-server war-server.cpp)
add_executable(war-client war-client.cpp)

add_library(rules rules.cpp)
add_library(map_data map_data.cpp)

target_link_libraries(war-server map_data rules)
target_link_libraries(war-client sfml-graphics sfml-window sfml-system)

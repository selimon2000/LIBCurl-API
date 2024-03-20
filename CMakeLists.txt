cmake_minimum_required(VERSION 3.0)
project(LibCurl)

# Add your executable
add_executable(string_output get_request_string.cpp)
add_executable(parsed_output get_request_parsed.cpp)

# Find and link with libcurl
find_package(CURL REQUIRED)
# Link with libcurl
target_link_libraries(string_output CURL::libcurl)
target_link_libraries(parsed_output CURL::libcurl)

# Find and link with JSON library
find_package(jsoncpp REQUIRED)
target_link_libraries(parsed_output jsoncpp)
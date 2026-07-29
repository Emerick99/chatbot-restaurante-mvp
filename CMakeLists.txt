cmake_minimum_required(VERSION 3.20)

project(
    chatbot_restaurante_mvp
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Drogon CONFIG REQUIRED)
find_package(TgBot CONFIG REQUIRED)

add_library(chatbot_project_options INTERFACE)

if(MSVC)
    target_compile_options(
        chatbot_project_options
        INTERFACE
            /W4
            /permissive-
    )
else()
    target_compile_options(
        chatbot_project_options
        INTERFACE
            -Wall
            -Wextra
            -Wpedantic
    )
endif()

add_library(chatbot_dependencies INTERFACE)
target_link_libraries(
    chatbot_dependencies
    INTERFACE
        Drogon::Drogon
        TgBot::TgBot
)

include(CTest)

if(BUILD_TESTING)
    add_executable(
        app_config_tests
        tests/AppConfigTests.cpp
        src/config/AppConfig.cpp
    )
    target_include_directories(
        app_config_tests
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src
    )
    target_link_libraries(
        app_config_tests
        PRIVATE
            chatbot_project_options
    )
    add_test(
        NAME app_config_tests
        COMMAND app_config_tests
    )
endif()

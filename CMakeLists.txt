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

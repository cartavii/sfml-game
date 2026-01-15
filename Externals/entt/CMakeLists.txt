cmake_minimum_required(VERSION 3.31)

include(FetchContent)
FetchContent_Declare(
        entt
        GIT_REPOSITORY https://github.com/skypjack/entt.git
        GIT_TAG        v3.16.0
)
FetchContent_MakeAvailable(entt)

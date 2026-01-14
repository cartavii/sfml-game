cmake_minimum_required(VERSION 3.31)
project(RxCpp)

include(FetchContent)
FetchContent_Declare(
        rxcpp
        GIT_REPOSITORY https://github.com/ReactiveX/RxCpp.git
        GIT_TAG        v4.1.1  # или main, если нужна последняя версия
)

FetchContent_MakeAvailable(rxcpp)

include_directories(.)

add_executable(emu
    main.cpp
    emulator.h
    emulator.cpp
    platform.h
)

target_link_libraries(emu PRIVATE SDL2::SDL2 SDL2::SDL2main)
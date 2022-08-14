add_executable(example example.cpp)

target_link_libraries(example PRIVATE ${LIBRARY_NAME}) 
target_compile_features(example PRIVATE cxx_std_17)

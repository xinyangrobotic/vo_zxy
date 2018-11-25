#vo_zxy
add_executable(vo_zxy main.cpp)
target_link_libraries(vo_zxy myslam)

#pangolintest
add_executable(test_pan test_pangolin.cpp)
target_link_libraries(test_pan myslam)
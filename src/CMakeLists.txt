#cmake_minimum_required(VERSION 3.1)
#project(vo_zxy)
#
#set(CMAKE_CXX_STANDARD 11)

#
#set(SOURCE_FILE ${CMAKE_SOURCE_DIR}/include/myslam)

add_library(myslam SHARED
        camera.cpp
        frame.cpp
        map.cpp ../include/myslam/map.h config.cpp ../include/myslam/config.h visual_odometry.cpp ../include/myslam/visual_odometry.h view.cpp g2o_types.cpp ../include/myslam/g2o_types.h mappoint.cpp ../include/myslam/mappoint.h ../include/myslam/view.h)

target_link_libraries(myslam
        ${THIRD_PARTY_LIBS}
        )

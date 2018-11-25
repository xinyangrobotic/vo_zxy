//
// Created by zxy on 18-11-25.
//

#ifndef VO_ZXY_VIEW_H
#define VO_ZXY_VIEW_H

#include "myslam/visual_odometry.h"
#include "myslam/map.h"
#include "myslam/mappoint.h"
#include "myslam/frame.h"
#include "myslam/common_include.h"
namespace myslam{

    class VisualOdometry;

    class Viewer{
    public:
        Viewer(VisualOdometry::Ptr pVO);

        void run();

    private:

        Frame::Ptr pFrame_;
    };

}
#endif //VO_ZXY_VIEW_H

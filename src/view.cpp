//
// Created by zxy on 18-11-22.
//
#include "myslam/view.h"
namespace myslam {

    void Viewer::run() {

                    float fx = 517.3, fy = 516.5, cx = 325.1, cy = 249.7;
                    // create pangolin window and plot the trajectory
                    pangolin::CreateWindowAndBind("Trajectory Viewer", 1024, 768);
                    // 3D Mouse handler requires depth testing to be enabled
                    glEnable(GL_DEPTH_TEST);
                    // Issue specific OpenGl we might need
                    glEnable(GL_BLEND);
                    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

// Define Camera Render Object (for view / scene browsing)
                    pangolin::OpenGlRenderState s_cam(
                            pangolin::ProjectionMatrix(1024, 768, 500, 500, 512, 389, 0.1, 1000),
                            pangolin::ModelViewLookAt(0, -0.7, -1.8, 0, 0, 0, 0.0, -1.0, 0.0)
                    );
// Add named OpenGL viewport to window and provide 3D Handler
                    pangolin::View &d_cam = pangolin::CreateDisplay()
                            .SetBounds(0.0, 1.0, pangolin::Attach::Pix(175), 1.0, -1024.0f / 768.0f)
                            .SetHandler(new pangolin::Handler3D(s_cam));

                    pangolin::OpenGlMatrix Twc;
                    Twc.SetIdentity();

                    while (1){
//    while (pangolin::ShouldQuit() == false) {
                    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//                    Twc = pFrame_->getCamCenter();
                    d_cam.Activate(s_cam);
                    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

                    // draw poses
                    float sz = 0.1;
                    int width = 640, height = 480;
//        for (auto &Tcw: poses) {
                    glPushMatrix();
                    Sophus::Matrix4f m = poses.inverse().matrix().cast<float>();
                    glMultMatrixf((GLfloat *) m.data());
                    glColor3f(1, 0, 0);
                    glLineWidth(2);
                    glBegin(GL_LINES);
                    glVertex3f(0, 0, 0);
                    glVertex3f(sz * (0 - cx) / fx, sz * (0 - cy) / fy, sz);
                    glVertex3f(0, 0, 0);
                    glVertex3f(sz * (0 - cx) / fx, sz * (height - 1 - cy) / fy, sz);
                    glVertex3f(0, 0, 0);
                    glVertex3f(sz * (width - 1 - cx) / fx, sz * (height - 1 - cy) / fy, sz);
                    glVertex3f(0, 0, 0);
                    glVertex3f(sz * (width - 1 - cx) / fx, sz * (0 - cy) / fy, sz);
                    glVertex3f(sz * (width - 1 - cx) / fx, sz * (0 - cy) / fy, sz);
                    glVertex3f(sz * (width - 1 - cx) / fx, sz * (height - 1 - cy) / fy, sz);
                    glVertex3f(sz * (width - 1 - cx) / fx, sz * (height - 1 - cy) / fy, sz);
                    glVertex3f(sz * (0 - cx) / fx, sz * (height - 1 - cy) / fy, sz);
                    glVertex3f(sz * (0 - cx) / fx, sz * (height - 1 - cy) / fy, sz);
                    glVertex3f(sz * (0 - cx) / fx, sz * (0 - cy) / fy, sz);
                    glVertex3f(sz * (0 - cx) / fx, sz * (0 - cy) / fy, sz);
                    glVertex3f(sz * (width - 1 - cx) / fx, sz * (0 - cy) / fy, sz);
                    glEnd();
                    glPopMatrix();
//        }
/*
        // points
        glPointSize(2);
        glBegin(GL_POINTS);
        for (size_t i = 0; i < points.size(); i++) {
            glColor3f(0.0, points[i][2]/4, 1.0-points[i][2]/4);
            glVertex3d(points[i][0], points[i][1], points[i][2]);
        }
        glEnd();
*/
                    pangolin::FinishFrame();
                    usleep(5000);   // sleep 5 ms
            }
    }

//}
}
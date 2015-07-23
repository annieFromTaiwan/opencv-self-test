// g++ video.cpp `pkg-config opencv --cflags` `pkg-config opencv --libs` -o video.out

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char *video_path;

    if(argc==2)
    {
        video_path = argv[1];
    }
    else
    {
        video_path = (char*)"/nas/android_movies/wanfi_2015Feb/shot_from_wanfi/B_WeiLun_D024/DMOV_0006.mp4";
    }

    cv::VideoCapture capture;
    if(capture.open(video_path) == false){
        fprintf(stderr, "can't open video: %s\n", video_path);
        return 0;
    }

    double fps = capture.get(CV_CAP_PROP_FPS);
    capture.release();
    fprintf(stderr, "fps: %.2f\n", fps);

    return 0;
}


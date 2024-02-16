#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat image = cv::imread("assert/cat.jpg");
    typedef cv::Point3_<uint8_t> Pixel;
    // std::cout << image.size << std::endl;

    // forEach 遍历图片像素
#if 1
    double start1 = static_cast<double>(cv::getTickCount());
    image.forEach<Pixel>([](Pixel &p, const int * position) -> void {
        p.x = 255 - p.x;
        p.y = 255 - p.y;
        p.z = 255 - p.z;
    });
    double end1 = static_cast<double>(cv::getTickCount());
    double time1 = static_cast<double> ((end1 - start1) / cv::getTickFrequency());

    printf(" forEach time : %.4f seconds\n", time1);
#endif

# if 1
    // 指针方式遍历像素
    double start2 = static_cast<double> (cv::getTickCount());
    for (size_t r = 0; r < image.rows; r++)
    {
        Pixel* ptr = image.ptr<Pixel>(r, 0);
        const Pixel* ptr_end = ptr + image.cols;
        for (; ptr != ptr_end; ++ptr)
        {
            ptr->x = 255 - ptr->x;
            ptr->y = 255 - ptr->y;
            ptr->z = 255 - ptr->z;
        }
    }
    double end2 = static_cast<double>(cv::getTickCount());
    double time2 = static_cast<double> ((end2 - start2) / cv::getTickFrequency());

    printf(" raw pointer time : %.4f seconds\n", time2);
#endif
    return 0;
}
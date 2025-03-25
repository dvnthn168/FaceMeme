#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Hàm chèn meme vào gương mặt
void overlayImage(Mat &background, Mat &meme, Rect face)
{
    // Thay đổi kích thước meme để khớp với kích thước gương mặt
    resize(meme, meme, Size(face.width, face.height));

    for (int y = 0; y < meme.rows; ++y)
    {
        for (int x = 0; x < meme.cols; ++x)
        {
            Vec4b pixel = meme.at<Vec4b>(y, x);
            if (pixel[3] > 0)
            { // Kiểm tra kênh alpha
                background.at<Vec3b>(face.y + y, face.x + x) = Vec3b(pixel[0], pixel[1], pixel[2]);
            }
        }
    }
}

int main()
{
    // Đường dẫn cố định cho ảnh và meme
    string imagePath = "input_image/input.jpg";
    string memePath = "input_image/icon.png";

    // Đọc ảnh đầu vào và meme
    Mat img = imread(imagePath);
    Mat meme = imread(memePath, IMREAD_UNCHANGED);

    if (img.empty() || meme.empty())
    {
        cerr << "Error loading images." << endl;
        return -1;
    }

    // Nạp bộ phát hiện gương mặt
    CascadeClassifier face_cascade;
    if (!face_cascade.load("input_image/haarcascade_frontalface_default.xml"))
    {
        cerr << "Error loading face cascade." << endl;
        return -1;
    }

    // Phát hiện gương mặt
    vector<Rect> faces;
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    face_cascade.detectMultiScale(gray, faces, 1.1, 5, 0, Size(100, 100));

    cout << "So luong guong mat phat hien: " << faces.size() << endl;
    for (const auto &face : faces)
    {
        overlayImage(img, meme, face);
    }

    // Hiển thị kết quả
    imshow("Meme Overlay", img);
    waitKey(0);

    // Lưu kết quả
    imwrite("output_image/output.png", img);

    return 0;
}
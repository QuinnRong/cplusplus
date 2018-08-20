#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;

void displayImage(const string& imgName)
{   /*
    * input: an image
    * output: a window displaying the image
    */
    cv::Mat image;
    string path = "data";
    image = cv::imread(path + "/" + imgName);
    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        return;
    }
    namedWindow("Display window", cv::WINDOW_AUTOSIZE);
    cv::imshow("Display window", image);
    cv::waitKey(0);
}

void convertColor(const string& imgName, const int& mode)
{   /*
    * input: an image, convert mode
    * output: two window displaying the original image and converted image
    */
    cv::Mat image;
    string path = "data";
    image = cv::imread(path + "/" + imgName);

    cv::Mat cvt_image;
    cv::cvtColor(image, cvt_image, mode);

    namedWindow("src", cv::WINDOW_AUTOSIZE);
    namedWindow("dst", cv::WINDOW_AUTOSIZE);
    cv::imshow("src", image);
    cv::imshow("dst", cvt_image);
    cv::waitKey(0);
}

void resizeImage(const string& imgName, const int& width, const int& height)
{   /*
    * input: an image, new size
    * output: two window displaying the original image and resized image
    */
    cv::Mat image;
    string path = "data";
    image = cv::imread(path + "/" + imgName);
    printf("Original width: %d, height:%d\n", image.size().width, image.size().height);

    cv::Mat rsz_image;
    cv::resize(image, rsz_image, cv::Size(width, height));  
    printf("Resized width: %d, height:%d\n", rsz_image.cols, rsz_image.rows);

    namedWindow("src", cv::WINDOW_AUTOSIZE);
    namedWindow("dst", cv::WINDOW_AUTOSIZE);
    cv::imshow("src", image);
    cv::imshow("dst", rsz_image);
    cv::waitKey(0);
}

template<typename Dtype>
void save_txt_nchw(Dtype* input, const string& output_file, int N, int C, int H, int W)
{   /*
    * input: data buffer
    * output: txt file
    * n c h w
    * val val...
    */
    ofstream ofs;
    ofs.open(output_file, ofstream::out);
    
    ofs << N << " " << C << " " << H << " " << W << "\n";
    for (int c = 0; c < C; ++c) 
    {
        for (int h = 0; h < H; ++h) 
        {
            for (int w = 0; w < W; ++w) 
            {
                int addr = c * W * H + h * W + w;
                ofs << input[addr] << " ";
            }
        }
    }

    ofs.close();
    cout << "Dump to " << output_file << " successfully!" << endl;
}

void load_txt_nchw(const string& input_file, cv::Mat& image)
{   /*
    * input: txt file
    * n c h w
    * val val...
    * output: mat
    */
    ifstream ifs;
    ifs.open(input_file, ifstream::in);

    int N, C, H, W;
    ifs >> N >> C >> H >> W;
    printf("input size: n=%d, c=%d, h=%d, w=%d\n", N, C, H, W);

    image.create(H, W, CV_8UC3);
    int val;
    for (int c = 0; c < C; ++c) 
    {
        for (int h = 0; h < H; ++h) 
        {
            for (int w = 0; w < W; ++w) 
            {
                ifs >> val;
                image.at<cv::Vec3b>(h, w)[c] = val;
            }
        }
    }
}

void img2txt(const string& imgName, const string& txtName,
    const int& width=-1, const int& height=-1, const int& mode=-1)
{   /*
    * input: an image
    * output: txt file (resize or convert channel)
    * n c h w
    * val val...
    */
    cv::Mat image, cvt_image, rsz_image;
    string path = "data";
    image = cv::imread(path + "/" + imgName);
    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        return;
    }

    if (mode >= 0)
        cv::cvtColor(image, cvt_image, mode);
    else
        cvt_image = image;

    if (width >= 0 && height >= 0)
        cv::resize(cvt_image, rsz_image, cv::Size(width, height));
    else
        rsz_image = cvt_image;

    int new_h = rsz_image.rows;
    int new_w = rsz_image.cols;
    float* data = new float[3 * new_h * new_w];
    for (int c = 0; c < 3; ++c)
    {
        for (int h = 0; h < new_h; ++h)
        {
            for (int w = 0; w < new_w; ++w)
            {
                data[c * new_h * new_w + h * new_w + w] = rsz_image.at<cv::Vec3b>(h, w)[c];
            }
        }
    }
    save_txt_nchw(data, path + "/" + txtName, 1, 3, new_h, new_w);

    delete[] data;
}

void txt2img(const string& txtName, const string& imgName,
    const int& width=-1, const int& height=-1, const int& mode=-1)
{   /*
    * input: txt file (resize or convert channel)
    * n c h w
    * val val...
    * output: an image
    */
    cv::Mat image, cvt_image, rsz_image;
    string path = "data";
    load_txt_nchw(path + "/" + txtName, image);

    if (mode >= 0)
        cv::cvtColor(image, cvt_image, mode);
    else
        cvt_image = image;

    if (width >= 0 && height >= 0)
        cv::resize(cvt_image, rsz_image, cv::Size(width, height));
    else
        rsz_image = cvt_image;

    cv::imwrite(path + "/" + imgName, rsz_image);
}

int main()
{
    displayImage("Lenna.jpg");
    convertColor("Lenna.jpg", cv::COLOR_BGR2GRAY);
    convertColor("Lenna.jpg", cv::COLOR_BGR2RGB);
    resizeImage("Lenna.jpg", 1280, 720);
    img2txt("Lenna.jpg", "Lenna.txt", 480, 320, cv::COLOR_BGR2RGB);
    txt2img("Lenna.txt", "Lenna1.jpg", 480, 320, cv::COLOR_BGR2RGB);
}
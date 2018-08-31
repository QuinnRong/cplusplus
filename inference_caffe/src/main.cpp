#include <string>
#include <fstream>

#include <caffe/net.hpp>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;

#define LOG_I_(format, args...) \
{ \
    printf("%s %s(%d): " format, "INFO", __FILE__, __LINE__, ##args); \
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
    LOG_I_("Dump to %s successfully!\n", output_file.c_str());
}

template<typename Dtype>
void load_txt_nchw(const string& input_file, Dtype* output, int N, int C, int H, int W)
{   /*
    * input: txt file
    * n c h w
    * val val...
    * output: data buffer
    */
    ifstream ifs;
    ifs.open(input_file, ifstream::in);

    int n0, c0, h0, w0;
    ifs >> n0 >> c0 >> h0 >> w0;
    if (n0 != N || c0 != C || h0 != H || w0 != W)
    {
        LOG_I_("Dimension not match! N=%d, C=%d, H=%d, W=%d\n", N, C, H, W);
        return;
    }
    for (int c = 0; c < C; ++c)
    {
        for (int h = 0; h < H; ++h)
        {
            for (int w = 0; w < W; ++w)
            {
                int addr = c * W * H + h * W + w;
                ifs >> output[addr];
            }
        }
    }

    ifs.close();
    LOG_I_("Read from %s successfully!\n", input_file.c_str());
}

template<typename Dtype>
void dumpData(Dtype* input, const string& output_file, int C, int H, int W)
{   /*
    * input: data buffer
    * output: txt file
    * [c,h,w] val
    * [c,h,w] val
    * ...
    */
    ofstream ofs;
    ofs.open(output_file, ofstream::out);

    for (int c = 0; c < C; ++c) 
    {
        for (int h = 0; h < H; ++h) 
        {
            for (int w = 0; w < W; ++w) 
            {
                int addr = c * W * H + h * W + w;
                ofs << "[" << c << "," << h << "," << w  << "] " << input[addr] << "\n";
            }
        }
    }

    ofs.close();
    LOG_I_("Dump to %s successfully!\n", output_file.c_str());
}

void img2txt(const string& imgName, const int& width, const int& height, float* data, const string& txtName="")
{   /*
    * input: an image
    * output: txt file (resized)
    * n c h w
    * val val...
    */
    cv::Mat image, rsz_image;
    image = cv::imread(imgName);
    if (image.empty())
    {
        LOG_I_("Could not open or find the image\n")
        return;
    }

    if (width >= 0 && height >= 0)
        cv::resize(image, rsz_image, cv::Size(width, height));
    else
        rsz_image = image;

    int new_h = rsz_image.rows;
    int new_w = rsz_image.cols;
    for (int c = 0; c < 3; ++c)
    {
        for (int h = 0; h < new_h; ++h)
        {
            for (int w = 0; w < new_w; ++w)
            {
                data[c * new_h * new_w + h * new_w + w] = rsz_image.at<cv::Vec3b>(h, w)[c] / 255.0;
            }
        }
    }

    if (txtName != "")
    {
        save_txt_nchw(data, txtName, 1, 3, new_h, new_w);
    }
}

void wrapInputLayer(caffe::Net<float>* net, float* input_data)
{
    caffe::Blob<float>* inputBlob = net->input_blobs()[0];
    int input_channels = inputBlob->channels();
    int input_w = inputBlob->width();
    int input_h = inputBlob->height();

    float* input_data_net = inputBlob->mutable_cpu_data();

    for (int c = 0; c < input_channels; ++c)
    {
        for (int h = 0; h < input_h; ++h)
        {
            for (int w = 0; w < input_w; ++w)
            {
                int index = c * input_h * input_w + h * input_w + w; 
                input_data_net[c * input_h * input_w + h * input_w + w] = input_data[index];
            }
        }
    }
}

int main(int argc,char **argv)
{
    string prototxt = "data/model.prototxt";
    string caffemodel = "data/model.caffemodel";
    string image = "data/image.jpg";
    string txt = "data/image.txt";

    bool isImage = false;

    LOG_I_("Run caffe test\n");
    caffe::Caffe::set_mode(caffe::Caffe::CPU);
    caffe::Net<float>* net;
    net = new caffe::Net<float>(prototxt, caffe::TEST);
    net->CopyTrainedLayersFrom(caffemodel);

    LOG_I_("width=%d, height=%d\n", net->input_blobs()[0]->width(), net->input_blobs()[0]->height());
    float* input_data = new float[net->input_blobs()[0]->width() * net->input_blobs()[0]->height() * 3];
    if (isImage)
    {
        img2txt(image, net->input_blobs()[0]->width(), net->input_blobs()[0]->height(), input_data, txt);
    }
    else
    {
        load_txt_nchw(txt, input_data, 1, 3, net->input_blobs()[0]->height(), net->input_blobs()[0]->width());
    }
    wrapInputLayer(net, input_data);

    LOG_I_("forward...\n");
    net->Forward();

    int output_count = net->output_blobs().size();
    LOG_I_("save %d outputs\n", output_count);
    for (int i = 0; i < output_count; ++i)
    {
        caffe::Blob<float>*  outputBlob = net->output_blobs()[i];
        int output_c = outputBlob->channels();
        int output_w = outputBlob->width();
        int output_h = outputBlob->height();
        const float* blobData = outputBlob->cpu_data();
        char output_name[100];
        sprintf(output_name, "output/output_%d.txt", i);
        dumpData(blobData, output_name, output_c, output_h, output_w);
    }

    delete[] input_data;
    delete net;
    return 0; 
}
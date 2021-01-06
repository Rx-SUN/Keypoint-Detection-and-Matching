#include <iostream>



#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>

#include <opencv2/highgui/highgui.hpp>

using namespace std;


cv::Mat add_image(string);
cv::Mat add_image(int img_index){
    
    return cv::imread("../images/image"+to_string(img_index)+".png");
}

class Keypoints_and_Descriptor{
    
public:
    int index;
    vector<cv::KeyPoint> keypoints;
    cv::Mat descriptors;
    void detect_keypoint();
    void compute_descriptor();
};

void Keypoints_and_Descriptor::detect_keypoint(){
    
    
} 

void Keypoints_and_Descriptor::compute_descriptor(){
    
    
} 


int main ( int argc, char** argv )
{
    
    int img_index=0;
    cv::Mat image_former = add_image(img_index); //read in the image
    cv::Mat image_latter = add_image(img_index+1); //read in the image
    
    // if the image loading failed
    if ( image_former.data == nullptr ) 
    {
        cerr<<"Image "+to_string(img_index)+" failed loading!"<<endl;
        return 0;
    }
    if ( image_latter.data == nullptr ) 
    {
        cerr<<"Image "+to_string(img_index+1)+" failed loading!"<<endl;
        return 0;
    }
    
    Keypoints_and_Descriptor i_former;
    Keypoints_and_Descriptor i_latter;
    
    
    cv::Ptr<cv::FeatureDetector> detector = cv::ORB::create();
    cv::Ptr<cv::DescriptorExtractor> descriptor = cv::ORB::create();
    
    //detect keypoints
    detector->detect ( image_former,i_former.keypoints );
    detector->detect ( image_latter,i_latter.keypoints );

    //conpute descriptors
    descriptor->compute ( image_former,i_former.keypoints, i_former.descriptors );
    descriptor->compute ( image_latter,i_latter.keypoints, i_latter.descriptors );
    
    //show the keypoints
    /*
    cv::Mat img_keypoints_f;
    drawKeypoints( image_former, i_former.keypoints, img_keypoints_f, cv::Scalar::all(-1), cv::DrawMatchesFlags::DEFAULT );
    cv::Mat img_keypoints_l;
    drawKeypoints( image_latter, i_latter.keypoints, img_keypoints_l, cv::Scalar::all(-1), cv::DrawMatchesFlags::DEFAULT );
    cv::imshow("ORB Former",img_keypoints_f);
    cv::imshow("ORB Latter",img_keypoints_l);
    cv::waitKey(0);
    */
    
    //match
    vector<cv::DMatch> matches;
    cv::BFMatcher BF(cv::NORM_HAMMING);
    BF.match ( i_former.descriptors, i_latter.descriptors, matches );
    
    /*show the matches
    cv::Mat image_matches;
	drawMatches(image_former,i_former.keypoints, image_latter,i_latter.keypoints, matches,image_matches);
	imshow("Matches", image_matches);
    cv::waitKey(0);
    */
    
    return 0;
 
}

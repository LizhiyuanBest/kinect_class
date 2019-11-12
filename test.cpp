
#include "kinect.h"

int main(int argc, char * argv[]){
  //create and initiate kinect
  Kinect kinect(OPENGL);
  
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>(512, 424));
  pcl::visualization::CloudViewer viewer ("Viewer");  //创建一个显示点云的窗口    
  cv::Mat color(1080, 1920, CV_8UC4);
  cv::Mat depth(424, 512, CV_32FC1);

  while(!stop){

    kinect.get(color, depth);
    kinect.getCloud(cloud);

    cv::imshow("color", color);
    cv::imshow("depth", depth / 4500.0f);
    //cv::imwrite("color.bmp", color);
    //cv::imwrite("depth.bmp", color);
    //显示点云
    viewer.showCloud(cloud);
    int key = cv::waitKey(1);
    stop = stop || (key > 0 && ((key & 0xFF) == 27)); 
    //pcl::io::savePLYFileASCII("pointcloud.ply", *cloud);
  }


  kinect.shutDown();
	
  return 0;
}


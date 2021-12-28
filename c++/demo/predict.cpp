
#include "core/detection.hpp"
#include "util/json.hpp"
#include <iostream>

std::string rgb_window_name = "RGB";
std::string gray_window_name = "Gray";
int display_window_init() {
  cv::namedWindow(rgb_window_name, WINDOW_NORMAL);
  cv::resizeWindow(rgb_window_name, 640, 480);
  cv::moveWindow(rgb_window_name, 0, 0);

  cv::namedWindow(gray_window_name, WINDOW_NORMAL);
  cv::moveWindow(gray_window_name, 800, 0);
  cv::resizeWindow(gray_window_name, 640, 480);
}

int main(int argc, char const *argv[]) {

  std::string model_path;
  if (argc < 2) {
    std::cout << "Please Input ./palator_car  model_path. " << std::endl;
    return -1;
  } else {
    model_path = argv[1];   
    std::cout << "Model Path :" << model_path << std::endl;
  }
  std::shared_ptr<Detection> detection = std::make_shared<Detection>(true);
  if (detection == nullptr) {
    std::cout << "Error : create detection failed." << std::endl;
    return -1;
  }
  int ret = detection->init(0, model_path);
  if (ret != 0) {
    std::cout << "Detection init failed. " << std::endl;
    return -1;
  }
  detection->start();
	
	display_window_init();

  while (1) {
    std::shared_ptr<DetectionResult> result = detection->getLastFrame();

    cv::imshow(rgb_window_name, result->rgb_frame);
    cv::imshow(gray_window_name, result->det_render_frame);
    cv::waitKeyEx(1);
  }

  return 0;
}

#pragma once
#include <ros/ros.h>
#include <sampling_core/voronoi.h>
#include <visualization_msgs/Marker.h>
#include <Eigen/Dense>
#include <vector>

namespace sampling {
namespace visualization {

const double KRGBRed[3] = {255, 0, 0};
const double KRGBGreen[3] = {0, 255, 0};
const double KRGBBlue[3] = {0, 0, 255};
const double KRGBYellow[3] = {255, 255, 0};
const double KRGBGray[3] = {128, 128, 128};
const double KRGBPink[3] = {255, 102, 255};

class VoronoiVisualization {
 public:
  VoronoiVisualization();

  VoronoiVisualization(const Eigen::MatrixXd &map);

  void UpdateMap(const std::vector<int> &cell_labels);

  visualization_msgs::Marker GetVoronoiMap();

  // robot_locations N x 2
  visualization_msgs::Marker GetRobotMarker(
      const Eigen::MatrixXd &robot_locations);

 private:
  visualization_msgs::Marker marker_array_;

  double map_x_origin_, map_y_origin_, map_x_scale_, map_y_scale_;

  Eigen::MatrixXd map_;
};
}  // namespace visualization
}  // namespace sampling
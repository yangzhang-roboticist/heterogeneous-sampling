#pragma once

#include <hector_navigation/hector_navigation.h>
#include <nav_msgs/Odometry.h>

#include "sampling_agent/hector_agent_params.h"
#include "sampling_agent/sampling_agent.h"
#include "sampling_agent/sampling_agent_params.h"

namespace sampling {
namespace agent {

using Hector = hector::navigation::HectorQuadrotor;

class HectorAgent : public SamplingAgent {
 public:
  HectorAgent() = delete;

  static std::unique_ptr<HectorAgent> MakeUniqueFromROSParam(
      ros::NodeHandle &nh, ros::NodeHandle &ph);

 private:
  HectorAgent(ros::NodeHandle &nh, const SamplingAgentParams &agent_params,
              const HectorAgentParams &params);

  HectorAgentParams hector_params_;

  bool Navigate() override;

  ros::Subscriber odom_subscriber_;

  ros::ServiceClient hector_takeoff_client_;

  ros::ServiceClient hector_navigate_client_;

  void UpdatePositionFromOdom(const nav_msgs::Odometry &msg);

  bool taken_off_;
};
}  // namespace agent
}  // namespace sampling

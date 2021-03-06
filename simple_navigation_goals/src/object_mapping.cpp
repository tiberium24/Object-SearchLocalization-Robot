#include <ros/ros.h>
//#include <move_base_msgs/MoveBaseAction.h>
//#include <actionlib/client/simple_action_client.h>
#include "visualization_msgs/Marker.h"
#include "visualization_msgs/MarkerArray.h"
#include <string>


int main(int argc, char** argv){
  ros::init(argc, argv, "object_mapping");
  ros::NodeHandle n;

  std::string plane = "package://labrob_gazebo/models/airplane_blue/meshes/plane_fixed.dae";
  std::string bike = "package://labrob_gazebo/models/bike_blue/meshes/bike.dae";
  std::string boat = "package://labrob_gazebo/models/boat_blue/meshes/boat_fixed.dae";
  std::string bottle = "package://labrob_gazebo/models/bottle_blue/meshes/bottle.dae";

  ros::Publisher object_pub = n.advertise<visualization_msgs::MarkerArray>("object_mapping/pos",100);

  ros::Rate loop_rate(10);
  
  while (ros::ok())
  {  
  
  visualization_msgs::Marker marker;
  marker.header.frame_id = "base_footprint"; 
  marker.header.stamp = ros::Time();
  //marker.ns = "my_namespace";
  marker.id = 1;
  marker.type = visualization_msgs::Marker::MESH_RESOURCE;
  visualization_msgs::Marker::MESH_RESOURCE;
  marker.action = visualization_msgs::Marker::ADD; 
  marker.pose.position.x = 1; 
  marker.pose.position.y = 1;
  marker.pose.position.z = 0.5;
  marker.pose.orientation.x = -0.707;
  marker.pose.orientation.y = 0.0;
  marker.pose.orientation.z = 0.0;
  marker.pose.orientation.w = 0.707;
  marker.scale.x = 1;
  marker.scale.y = 1;
  marker.scale.z = 1;
  marker.color.a = 1.0; // Don't forget to set the alpha!
  marker.color.r = 0.0;
  marker.color.g = 1.0;
  marker.color.b = 0.0;
  //only if using a MESH_RESOURCE marker type:
  //marker.mesh_resource = "package://pr2_description/meshes/base_v0/base.dae";
  marker.mesh_resource = plane;
  //marker.mesh_use_embedded_materials = "True";
  
  object_pub.publish(marker);

  ROS_INFO("Marker published!");  

  ros::spinOnce();
  
  loop_rate.sleep();  

  }
//return 0;
}

//
// Created by pierre on 18-5-11.
//

#include "main.hpp"
bool motor_ctrl_cb(rosservice_send::motor::Request &req, rosservice_send::motor::Response &res){
	if(req.isOpen){
		res.isSuccess = true;
		res.reply = "it has received the signal";
		ROS_INFO("open motor succeed");
		return true;
	}
	return false;
}
int main(int argc, char* argv[]){
	ros::init(argc, argv, "rosservice_received");
	ros::NodeHandle	nh_;
	ros::ServiceServer motor_service= nh_.advertiseService("motor_ctrl", motor_ctrl_cb);
	ros::spin();
	return 0;
}


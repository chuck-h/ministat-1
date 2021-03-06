#ifndef _ROS_move_base_msgs_MoveBaseActionGoal_h
#define _ROS_move_base_msgs_MoveBaseActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "move_base_msgs/MoveBaseGoal.h"

namespace move_base_msgs
{

  class MoveBaseActionGoal : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalID goal_id;
      move_base_msgs::MoveBaseGoal goal;

    MoveBaseActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
#ifndef ROS_MSG_DONT_SERIALIZE
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
#endif
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
#ifndef ROS_MSG_DONT_DESERIALIZE
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
#endif
     return offset;
    }

    const char * getType(){ return "move_base_msgs/MoveBaseActionGoal"; };
    const char * getMD5(){ return "660d6895a1b9a16dce51fbdd9a64a56b"; };

  };

}
#endif
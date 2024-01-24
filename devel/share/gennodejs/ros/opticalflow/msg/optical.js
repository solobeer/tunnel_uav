// Auto-generated. Do not edit!

// (in-package opticalflow.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class optical {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.frameClass = null;
      this.mode = null;
      this.vel_rate = null;
      this.vel_rate_fix = null;
      this.vel_rate_integ = null;
      this.quality = null;
      this.dir = null;
      this.angle = null;
      this.dis = null;
      this.acc_rate = null;
      this.gry_rate = null;
      this.quat = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('frameClass')) {
        this.frameClass = initObj.frameClass
      }
      else {
        this.frameClass = 0;
      }
      if (initObj.hasOwnProperty('mode')) {
        this.mode = initObj.mode
      }
      else {
        this.mode = 0;
      }
      if (initObj.hasOwnProperty('vel_rate')) {
        this.vel_rate = initObj.vel_rate
      }
      else {
        this.vel_rate = new geometry_msgs.msg.Vector3();
      }
      if (initObj.hasOwnProperty('vel_rate_fix')) {
        this.vel_rate_fix = initObj.vel_rate_fix
      }
      else {
        this.vel_rate_fix = new geometry_msgs.msg.Vector3();
      }
      if (initObj.hasOwnProperty('vel_rate_integ')) {
        this.vel_rate_integ = initObj.vel_rate_integ
      }
      else {
        this.vel_rate_integ = new geometry_msgs.msg.Vector3();
      }
      if (initObj.hasOwnProperty('quality')) {
        this.quality = initObj.quality
      }
      else {
        this.quality = 0.0;
      }
      if (initObj.hasOwnProperty('dir')) {
        this.dir = initObj.dir
      }
      else {
        this.dir = 0;
      }
      if (initObj.hasOwnProperty('angle')) {
        this.angle = initObj.angle
      }
      else {
        this.angle = 0;
      }
      if (initObj.hasOwnProperty('dis')) {
        this.dis = initObj.dis
      }
      else {
        this.dis = 0.0;
      }
      if (initObj.hasOwnProperty('acc_rate')) {
        this.acc_rate = initObj.acc_rate
      }
      else {
        this.acc_rate = new geometry_msgs.msg.Vector3();
      }
      if (initObj.hasOwnProperty('gry_rate')) {
        this.gry_rate = initObj.gry_rate
      }
      else {
        this.gry_rate = new geometry_msgs.msg.Vector3();
      }
      if (initObj.hasOwnProperty('quat')) {
        this.quat = initObj.quat
      }
      else {
        this.quat = new geometry_msgs.msg.Quaternion();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type optical
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [frameClass]
    bufferOffset = _serializer.int16(obj.frameClass, buffer, bufferOffset);
    // Serialize message field [mode]
    bufferOffset = _serializer.int16(obj.mode, buffer, bufferOffset);
    // Serialize message field [vel_rate]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.vel_rate, buffer, bufferOffset);
    // Serialize message field [vel_rate_fix]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.vel_rate_fix, buffer, bufferOffset);
    // Serialize message field [vel_rate_integ]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.vel_rate_integ, buffer, bufferOffset);
    // Serialize message field [quality]
    bufferOffset = _serializer.float32(obj.quality, buffer, bufferOffset);
    // Serialize message field [dir]
    bufferOffset = _serializer.uint8(obj.dir, buffer, bufferOffset);
    // Serialize message field [angle]
    bufferOffset = _serializer.uint16(obj.angle, buffer, bufferOffset);
    // Serialize message field [dis]
    bufferOffset = _serializer.float32(obj.dis, buffer, bufferOffset);
    // Serialize message field [acc_rate]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.acc_rate, buffer, bufferOffset);
    // Serialize message field [gry_rate]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.gry_rate, buffer, bufferOffset);
    // Serialize message field [quat]
    bufferOffset = geometry_msgs.msg.Quaternion.serialize(obj.quat, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type optical
    let len;
    let data = new optical(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [frameClass]
    data.frameClass = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [mode]
    data.mode = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [vel_rate]
    data.vel_rate = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    // Deserialize message field [vel_rate_fix]
    data.vel_rate_fix = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    // Deserialize message field [vel_rate_integ]
    data.vel_rate_integ = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    // Deserialize message field [quality]
    data.quality = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [dir]
    data.dir = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [angle]
    data.angle = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [dis]
    data.dis = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [acc_rate]
    data.acc_rate = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    // Deserialize message field [gry_rate]
    data.gry_rate = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    // Deserialize message field [quat]
    data.quat = geometry_msgs.msg.Quaternion.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 167;
  }

  static datatype() {
    // Returns string type for a message object
    return 'opticalflow/optical';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '8d8fc678561657c551426004e594a041';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    std_msgs/Header header
    int16 frameClass
    
    int16 mode
    geometry_msgs/Vector3 vel_rate
    geometry_msgs/Vector3 vel_rate_fix
    geometry_msgs/Vector3 vel_rate_integ
    float32 quality
    
    uint8 dir
    uint16 angle
    float32 dis
    
    geometry_msgs/Vector3 acc_rate
    geometry_msgs/Vector3 gry_rate
    
    geometry_msgs/Quaternion quat
    
    
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    string frame_id
    
    ================================================================================
    MSG: geometry_msgs/Vector3
    # This represents a vector in free space. 
    # It is only meant to represent a direction. Therefore, it does not
    # make sense to apply a translation to it (e.g., when applying a 
    # generic rigid transformation to a Vector3, tf2 will only apply the
    # rotation). If you want your data to be translatable too, use the
    # geometry_msgs/Point message instead.
    
    float64 x
    float64 y
    float64 z
    ================================================================================
    MSG: geometry_msgs/Quaternion
    # This represents an orientation in free space in quaternion form.
    
    float64 x
    float64 y
    float64 z
    float64 w
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new optical(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.frameClass !== undefined) {
      resolved.frameClass = msg.frameClass;
    }
    else {
      resolved.frameClass = 0
    }

    if (msg.mode !== undefined) {
      resolved.mode = msg.mode;
    }
    else {
      resolved.mode = 0
    }

    if (msg.vel_rate !== undefined) {
      resolved.vel_rate = geometry_msgs.msg.Vector3.Resolve(msg.vel_rate)
    }
    else {
      resolved.vel_rate = new geometry_msgs.msg.Vector3()
    }

    if (msg.vel_rate_fix !== undefined) {
      resolved.vel_rate_fix = geometry_msgs.msg.Vector3.Resolve(msg.vel_rate_fix)
    }
    else {
      resolved.vel_rate_fix = new geometry_msgs.msg.Vector3()
    }

    if (msg.vel_rate_integ !== undefined) {
      resolved.vel_rate_integ = geometry_msgs.msg.Vector3.Resolve(msg.vel_rate_integ)
    }
    else {
      resolved.vel_rate_integ = new geometry_msgs.msg.Vector3()
    }

    if (msg.quality !== undefined) {
      resolved.quality = msg.quality;
    }
    else {
      resolved.quality = 0.0
    }

    if (msg.dir !== undefined) {
      resolved.dir = msg.dir;
    }
    else {
      resolved.dir = 0
    }

    if (msg.angle !== undefined) {
      resolved.angle = msg.angle;
    }
    else {
      resolved.angle = 0
    }

    if (msg.dis !== undefined) {
      resolved.dis = msg.dis;
    }
    else {
      resolved.dis = 0.0
    }

    if (msg.acc_rate !== undefined) {
      resolved.acc_rate = geometry_msgs.msg.Vector3.Resolve(msg.acc_rate)
    }
    else {
      resolved.acc_rate = new geometry_msgs.msg.Vector3()
    }

    if (msg.gry_rate !== undefined) {
      resolved.gry_rate = geometry_msgs.msg.Vector3.Resolve(msg.gry_rate)
    }
    else {
      resolved.gry_rate = new geometry_msgs.msg.Vector3()
    }

    if (msg.quat !== undefined) {
      resolved.quat = geometry_msgs.msg.Quaternion.Resolve(msg.quat)
    }
    else {
      resolved.quat = new geometry_msgs.msg.Quaternion()
    }

    return resolved;
    }
};

module.exports = optical;

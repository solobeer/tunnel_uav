# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from nlink_parser/IotFrame0.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import nlink_parser.msg

class IotFrame0(genpy.Message):
  _md5sum = "8854697b4ab999e932111a65ada95ab0"
  _type = "nlink_parser/IotFrame0"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """uint32 uid
uint32 system_time
uint8 io_status
IotFrame0Node[] nodes

================================================================================
MSG: nlink_parser/IotFrame0Node
uint32 uid
float32 dis
float32 aoa_angle_horizontal
float32 aoa_angle_vertical
float32 fp_rssi
float32 rx_rssi
string user_data
"""
  __slots__ = ['uid','system_time','io_status','nodes']
  _slot_types = ['uint32','uint32','uint8','nlink_parser/IotFrame0Node[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       uid,system_time,io_status,nodes

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(IotFrame0, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.uid is None:
        self.uid = 0
      if self.system_time is None:
        self.system_time = 0
      if self.io_status is None:
        self.io_status = 0
      if self.nodes is None:
        self.nodes = []
    else:
      self.uid = 0
      self.system_time = 0
      self.io_status = 0
      self.nodes = []

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_2IB().pack(_x.uid, _x.system_time, _x.io_status))
      length = len(self.nodes)
      buff.write(_struct_I.pack(length))
      for val1 in self.nodes:
        _x = val1
        buff.write(_get_struct_I5f().pack(_x.uid, _x.dis, _x.aoa_angle_horizontal, _x.aoa_angle_vertical, _x.fp_rssi, _x.rx_rssi))
        _x = val1.user_data
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.nodes is None:
        self.nodes = None
      end = 0
      _x = self
      start = end
      end += 9
      (_x.uid, _x.system_time, _x.io_status,) = _get_struct_2IB().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.nodes = []
      for i in range(0, length):
        val1 = nlink_parser.msg.IotFrame0Node()
        _x = val1
        start = end
        end += 24
        (_x.uid, _x.dis, _x.aoa_angle_horizontal, _x.aoa_angle_vertical, _x.fp_rssi, _x.rx_rssi,) = _get_struct_I5f().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.user_data = str[start:end].decode('utf-8', 'rosmsg')
        else:
          val1.user_data = str[start:end]
        self.nodes.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_2IB().pack(_x.uid, _x.system_time, _x.io_status))
      length = len(self.nodes)
      buff.write(_struct_I.pack(length))
      for val1 in self.nodes:
        _x = val1
        buff.write(_get_struct_I5f().pack(_x.uid, _x.dis, _x.aoa_angle_horizontal, _x.aoa_angle_vertical, _x.fp_rssi, _x.rx_rssi))
        _x = val1.user_data
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.nodes is None:
        self.nodes = None
      end = 0
      _x = self
      start = end
      end += 9
      (_x.uid, _x.system_time, _x.io_status,) = _get_struct_2IB().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.nodes = []
      for i in range(0, length):
        val1 = nlink_parser.msg.IotFrame0Node()
        _x = val1
        start = end
        end += 24
        (_x.uid, _x.dis, _x.aoa_angle_horizontal, _x.aoa_angle_vertical, _x.fp_rssi, _x.rx_rssi,) = _get_struct_I5f().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.user_data = str[start:end].decode('utf-8', 'rosmsg')
        else:
          val1.user_data = str[start:end]
        self.nodes.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_2IB = None
def _get_struct_2IB():
    global _struct_2IB
    if _struct_2IB is None:
        _struct_2IB = struct.Struct("<2IB")
    return _struct_2IB
_struct_I5f = None
def _get_struct_I5f():
    global _struct_I5f
    if _struct_I5f is None:
        _struct_I5f = struct.Struct("<I5f")
    return _struct_I5f

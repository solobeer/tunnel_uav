# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from nlink_parser/TofsenseFrame0.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class TofsenseFrame0(genpy.Message):
  _md5sum = "5579723ab4876e453dd6025247ac5ffb"
  _type = "nlink_parser/TofsenseFrame0"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """uint8 id
uint32 system_time
float32 dis
uint8 dis_status
uint16 signal_strength
uint8 range_precision
"""
  __slots__ = ['id','system_time','dis','dis_status','signal_strength','range_precision']
  _slot_types = ['uint8','uint32','float32','uint8','uint16','uint8']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       id,system_time,dis,dis_status,signal_strength,range_precision

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(TofsenseFrame0, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.id is None:
        self.id = 0
      if self.system_time is None:
        self.system_time = 0
      if self.dis is None:
        self.dis = 0.
      if self.dis_status is None:
        self.dis_status = 0
      if self.signal_strength is None:
        self.signal_strength = 0
      if self.range_precision is None:
        self.range_precision = 0
    else:
      self.id = 0
      self.system_time = 0
      self.dis = 0.
      self.dis_status = 0
      self.signal_strength = 0
      self.range_precision = 0

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
      buff.write(_get_struct_BIfBHB().pack(_x.id, _x.system_time, _x.dis, _x.dis_status, _x.signal_strength, _x.range_precision))
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
      end = 0
      _x = self
      start = end
      end += 13
      (_x.id, _x.system_time, _x.dis, _x.dis_status, _x.signal_strength, _x.range_precision,) = _get_struct_BIfBHB().unpack(str[start:end])
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
      buff.write(_get_struct_BIfBHB().pack(_x.id, _x.system_time, _x.dis, _x.dis_status, _x.signal_strength, _x.range_precision))
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
      end = 0
      _x = self
      start = end
      end += 13
      (_x.id, _x.system_time, _x.dis, _x.dis_status, _x.signal_strength, _x.range_precision,) = _get_struct_BIfBHB().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_BIfBHB = None
def _get_struct_BIfBHB():
    global _struct_BIfBHB
    if _struct_BIfBHB is None:
        _struct_BIfBHB = struct.Struct("<BIfBHB")
    return _struct_BIfBHB
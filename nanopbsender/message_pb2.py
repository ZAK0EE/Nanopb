# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: message.proto
# Protobuf Python Version: 5.26.1
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import descriptor_pool as _descriptor_pool
from google.protobuf import symbol_database as _symbol_database
from google.protobuf.internal import builder as _builder
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n\rmessage.proto\"1\n\x0cMsg_ResetPin\x12\x10\n\x08Pin_Port\x18\x01 \x02(\r\x12\x0f\n\x07Pin_Num\x18\x02 \x02(\r\"0\n\x0bMsg_ReadPin\x12\x10\n\x08Pin_Port\x18\x01 \x02(\r\x12\x0f\n\x07Pin_Num\x18\x02 \x02(\r\"C\n\x0cMsg_PinValue\x12\x10\n\x08Pin_Port\x18\x01 \x02(\r\x12\x0f\n\x07Pin_Num\x18\x02 \x02(\r\x12\x10\n\x08Pin_Read\x18\x03 \x02(\r\"/\n\nMsg_SetPin\x12\x10\n\x08Pin_Port\x18\x01 \x02(\r\x12\x0f\n\x07Pin_Num\x18\x02 \x02(\r\"2\n\rMsg_TogglePin\x12\x10\n\x08Pin_Port\x18\x01 \x02(\r\x12\x0f\n\x07Pin_Num\x18\x02 \x02(\r\"-\n\nMsg_Header\x12\x0e\n\x06msg_ID\x18\x01 \x02(\x07\x12\x0f\n\x07msg_len\x18\x02 \x02(\x07')

_globals = globals()
_builder.BuildMessageAndEnumDescriptors(DESCRIPTOR, _globals)
_builder.BuildTopDescriptorsAndMessages(DESCRIPTOR, 'message_pb2', _globals)
if not _descriptor._USE_C_DESCRIPTORS:
  DESCRIPTOR._loaded_options = None
  _globals['_MSG_RESETPIN']._serialized_start=17
  _globals['_MSG_RESETPIN']._serialized_end=66
  _globals['_MSG_READPIN']._serialized_start=68
  _globals['_MSG_READPIN']._serialized_end=116
  _globals['_MSG_PINVALUE']._serialized_start=118
  _globals['_MSG_PINVALUE']._serialized_end=185
  _globals['_MSG_SETPIN']._serialized_start=187
  _globals['_MSG_SETPIN']._serialized_end=234
  _globals['_MSG_TOGGLEPIN']._serialized_start=236
  _globals['_MSG_TOGGLEPIN']._serialized_end=286
  _globals['_MSG_HEADER']._serialized_start=288
  _globals['_MSG_HEADER']._serialized_end=333
# @@protoc_insertion_point(module_scope)

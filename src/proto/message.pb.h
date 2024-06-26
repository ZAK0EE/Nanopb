/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.9-dev */

#ifndef PB_MESSAGE_PB_H_INCLUDED
#define PB_MESSAGE_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
typedef struct _Msg_ResetPin {
    uint32_t Pin_Port;
    uint32_t Pin_Num;
} Msg_ResetPin;

typedef struct _Msg_ReadPin {
    uint32_t Pin_Port;
    uint32_t Pin_Num;
} Msg_ReadPin;

typedef struct _Msg_PinValue {
    uint32_t Pin_Port;
    uint32_t Pin_Num;
    uint32_t Pin_Read;
} Msg_PinValue;

typedef struct _Msg_SetPin {
    uint32_t Pin_Port;
    uint32_t Pin_Num;
} Msg_SetPin;

typedef struct _Msg_TogglePin {
    uint32_t Pin_Port;
    uint32_t Pin_Num;
} Msg_TogglePin;

typedef struct _Msg_Header {
    uint32_t msg_ID;
    uint32_t msg_len;
} Msg_Header;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define Msg_ResetPin_init_default                {0, 0}
#define Msg_ReadPin_init_default                 {0, 0}
#define Msg_PinValue_init_default                {0, 0, 0}
#define Msg_SetPin_init_default                  {0, 0}
#define Msg_TogglePin_init_default               {0, 0}
#define Msg_Header_init_default                  {0, 0}
#define Msg_ResetPin_init_zero                   {0, 0}
#define Msg_ReadPin_init_zero                    {0, 0}
#define Msg_PinValue_init_zero                   {0, 0, 0}
#define Msg_SetPin_init_zero                     {0, 0}
#define Msg_TogglePin_init_zero                  {0, 0}
#define Msg_Header_init_zero                     {0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define Msg_ResetPin_Pin_Port_tag                1
#define Msg_ResetPin_Pin_Num_tag                 2
#define Msg_ReadPin_Pin_Port_tag                 1
#define Msg_ReadPin_Pin_Num_tag                  2
#define Msg_PinValue_Pin_Port_tag                1
#define Msg_PinValue_Pin_Num_tag                 2
#define Msg_PinValue_Pin_Read_tag                3
#define Msg_SetPin_Pin_Port_tag                  1
#define Msg_SetPin_Pin_Num_tag                   2
#define Msg_TogglePin_Pin_Port_tag               1
#define Msg_TogglePin_Pin_Num_tag                2
#define Msg_Header_msg_ID_tag                    1
#define Msg_Header_msg_len_tag                   2

/* Struct field encoding specification for nanopb */
#define Msg_ResetPin_FIELDLIST(X, a) \
X(a, STATIC,   REQUIRED, UINT32,   Pin_Port,          1) \
X(a, STATIC,   REQUIRED, UINT32,   Pin_Num,           2)
#define Msg_ResetPin_CALLBACK NULL
#define Msg_ResetPin_DEFAULT NULL

#define Msg_ReadPin_FIELDLIST(X, a) \
X(a, STATIC,   REQUIRED, UINT32,   Pin_Port,          1) \
X(a, STATIC,   REQUIRED, UINT32,   Pin_Num,           2)
#define Msg_ReadPin_CALLBACK NULL
#define Msg_ReadPin_DEFAULT NULL

#define Msg_PinValue_FIELDLIST(X, a) \
X(a, STATIC,   REQUIRED, UINT32,   Pin_Port,          1) \
X(a, STATIC,   REQUIRED, UINT32,   Pin_Num,           2) \
X(a, STATIC,   REQUIRED, UINT32,   Pin_Read,          3)
#define Msg_PinValue_CALLBACK NULL
#define Msg_PinValue_DEFAULT NULL

#define Msg_SetPin_FIELDLIST(X, a) \
X(a, STATIC,   REQUIRED, UINT32,   Pin_Port,          1) \
X(a, STATIC,   REQUIRED, UINT32,   Pin_Num,           2)
#define Msg_SetPin_CALLBACK NULL
#define Msg_SetPin_DEFAULT NULL

#define Msg_TogglePin_FIELDLIST(X, a) \
X(a, STATIC,   REQUIRED, UINT32,   Pin_Port,          1) \
X(a, STATIC,   REQUIRED, UINT32,   Pin_Num,           2)
#define Msg_TogglePin_CALLBACK NULL
#define Msg_TogglePin_DEFAULT NULL

#define Msg_Header_FIELDLIST(X, a) \
X(a, STATIC,   REQUIRED, FIXED32,  msg_ID,            1) \
X(a, STATIC,   REQUIRED, FIXED32,  msg_len,           2)
#define Msg_Header_CALLBACK NULL
#define Msg_Header_DEFAULT NULL

extern const pb_msgdesc_t Msg_ResetPin_msg;
extern const pb_msgdesc_t Msg_ReadPin_msg;
extern const pb_msgdesc_t Msg_PinValue_msg;
extern const pb_msgdesc_t Msg_SetPin_msg;
extern const pb_msgdesc_t Msg_TogglePin_msg;
extern const pb_msgdesc_t Msg_Header_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define Msg_ResetPin_fields &Msg_ResetPin_msg
#define Msg_ReadPin_fields &Msg_ReadPin_msg
#define Msg_PinValue_fields &Msg_PinValue_msg
#define Msg_SetPin_fields &Msg_SetPin_msg
#define Msg_TogglePin_fields &Msg_TogglePin_msg
#define Msg_Header_fields &Msg_Header_msg

/* Maximum encoded size of messages (where known) */
#define MESSAGE_PB_H_MAX_SIZE                    Msg_PinValue_size
#define Msg_Header_size                          10
#define Msg_PinValue_size                        18
#define Msg_ReadPin_size                         12
#define Msg_ResetPin_size                        12
#define Msg_SetPin_size                          12
#define Msg_TogglePin_size                       12

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif

/* 
 * File:   frame.h
 * Author: D8bauxit8
 *
 * Created on April 6, 2020, 8:06 PM
 */

#ifndef LRP_FRAME_H
#define    LRP_FRAME_H

#ifdef    __cplusplus
extern "C" {
#endif

#define FRAME_NUMBER_OF_MAX_DATA_BYTES 7u
#define FRAME_NUMBER_OF_HEADER_BYTES 2u
#define FRAME_NUMBER_OF_FRAME_BYTES (FRAME_NUMBER_OF_HEADER_BYTES + FRAME_NUMBER_OF_MAX_DATA_BYTES)

typedef struct _FrameData {
    unsigned char sourceDeviceId;
    unsigned char targetDeviceId;
    unsigned char command;
    unsigned char length;
    unsigned char *data[FRAME_NUMBER_OF_MAX_DATA_BYTES];
} _FrameData;

typedef struct _LRPFrame {
    unsigned char sourceDeviceId;
    unsigned char targetDeviceId;
    unsigned char command;
    unsigned char length;
    unsigned char *data[FRAME_NUMBER_OF_MAX_DATA_BYTES];
    unsigned char status;
    unsigned char buffer[FRAME_NUMBER_OF_FRAME_BYTES];
    struct _LRPFrame *next;
} _LRPFrame;

// Statuses
#define FRAME_READY_TO_REDEFINE 0u

#define FRAME_BROADCAST_ID 0b00011111u

void LRP_Frame_initBuffer(_LRPFrame *frameBuffer, const unsigned char *frameBufferLength);

void LRP_Frame_setStatus(_LRPFrame *frame, unsigned char status);

void LRP_Frame_resetStatus(_LRPFrame *frame);

unsigned char LRP_Frame_getTargetDeviceIdFromReceivedByte(const unsigned char *data);

void LRP_Frame_addHeaderDataToFrameDataFromFrameBuffer(_LRPFrame *frame);

void LRP_Frame_addDataToFrameDataFromFrameBuffer(_LRPFrame *frame);

void LRP_Frame_addHeaderDataToFrameBufferFromFrameData(_LRPFrame *frame);

void LRP_Frame_addDataToFrameBufferFromFrameData(_LRPFrame *frame);

#ifdef    __cplusplus
}
#endif

#endif    /* LRP_FRAME_H */


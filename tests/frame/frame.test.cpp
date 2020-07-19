#include <gtest/gtest.h>
#include "frame.test.h"

class FrameTest : public ::testing::Test {
protected:
    _LRPFrame frame{};
    const unsigned char const targetDeviceId = 0b00001;
    const unsigned char const command = 0b001;
    const unsigned char const sourceDeviceId = 0b00010;
    const unsigned char const length = 0b001;
};

TEST_F(FrameTest, Should_Be_Set_Status) {
    LRP_Frame_setStatus(&frame, FRAME_READY_TO_REDEFINE);

    ASSERT_EQ(frame.status, FRAME_READY_TO_REDEFINE);
}

TEST_F(FrameTest, Should_Be_Reset_Status) {
    LRP_Frame_resetStatus(&frame);

    ASSERT_EQ(frame.status, FRAME_READY_TO_REDEFINE);
}

TEST_F(FrameTest, Should_Be_Got_Target_Device_Id) {
    const unsigned char const data = (targetDeviceId << 3) | command;
    const unsigned char const targetDeviceIdToBeRead = LRP_Frame_getTargetDeviceIdFromReceivedByte(&data);
    ASSERT_EQ(targetDeviceIdToBeRead, targetDeviceId);
}

TEST_F(FrameTest, Should_Be_Added_Header_Data_To_Frame_Data_From_Frame_Buffer) {
    _LRPFrame *framePtr = TEST_createLRPFrameInWhichTheBufferIsFilled(targetDeviceId, command, sourceDeviceId, length);

    LRP_Frame_addHeaderDataToFrameDataFromFrameBuffer(framePtr);

    _FrameData *frameData = ((_FrameData *) framePtr);

    ASSERT_EQ(frameData->targetDeviceId, targetDeviceId);
    ASSERT_EQ(frameData->command, command);
    ASSERT_EQ(frameData->sourceDeviceId, sourceDeviceId);
    ASSERT_EQ(frameData->length, length);
}
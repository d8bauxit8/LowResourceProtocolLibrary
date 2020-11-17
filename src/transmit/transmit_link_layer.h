/* 
 * File:   transmit_link_layer.h
 * Author: D8bauxit8
 *
 * Created on April 6, 2020, 8:06 PM
 */

#ifndef LRP_TRANSMIT_LINK_LAYER_H
#define    LRP_TRANSMIT_LINK_LAYER_H

#ifdef    __cplusplus
extern "C" {
#endif

#include "transmit_structures.h"
#include "../link_layer.h"

unsigned char
LRP_TransmitLinkLayer_handler(_LRPTransmitSessionProvider *sessionProvider);

unsigned char LRP_TransmitLinkLayer_isEndOfBufferLength(_LRPTransmitSessionProvider *sessionProvider);

unsigned char LRP_TransmitLinkLayer_isReadyToTransmit(_LRPTransmitSessionProvider *sessionProvider);

void LRP_TransmitLinkLayer_startTransmitting(_LRPTransmitSessionProvider *sessionProvider);

void LRP_TransmitLinkLayer_endTransmitting(_LRPSessionProvider *sessionProvider);

void LRP_TransmitLinkLayer_errorStatusHandler(_LRPSessionProvider *sessionProvider);

#ifdef    __cplusplus
}
#endif

#endif    /* LRP_TRANSMIT_LINK_LAYER_H */


#include "link_layer.h"

void LRP_LinkLayer_setSkip(LRPSessionProvider *const sessionProvider) {
    sessionProvider->linkLayerStatus = LINK_LAYER_STATUS_SKIP;
    sessionProvider->linkLayerErrorCode = LINK_LAYER_NO_ERROR;
}

void LRP_LinkLayer_setError(LRPSessionProvider *const sessionProvider, const unsigned char errorCode) {
    sessionProvider->linkLayerStatus = LINK_LAYER_STATUS_ERROR;
    sessionProvider->linkLayerErrorCode = errorCode;
}

void LRP_LinkLayer_setOk(LRPSessionProvider *const sessionProvider) {
    sessionProvider->linkLayerStatus = LINK_LAYER_STATUS_OK;
    sessionProvider->linkLayerErrorCode = LINK_LAYER_NO_ERROR;
}

unsigned char LRP_LinkLayer_isStatusOK(LRPSessionProvider *const sessionProvider) {
    return sessionProvider->linkLayerStatus == LINK_LAYER_STATUS_OK;
}

unsigned char LRP_LinkLayer_isStatusError(LRPSessionProvider *const sessionProvider) {
    return sessionProvider->linkLayerStatus == LINK_LAYER_STATUS_ERROR;
}

unsigned char LRP_LinkLayer_isError(LRPSessionProvider *const sessionProvider, const unsigned char errorCode) {
    return sessionProvider->linkLayerErrorCode == errorCode;
}

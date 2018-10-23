//
// AUTO-GENERATED: DO NOT EDIT. 
//
 

// _________________________________________________________________________________________________
 
#ifndef __APPLE__ 
# define RPC_WEAK_DEFAULT_HANDLER
#endif 
 
#include <stdint.h>
#include <string.h>
#include "phRpc_HostDeSerialiser.h"
#include "phRpc_Cmd.h"
#define LEN_INFO_SIZE      2 //
#define SQNR_INFO_SIZE     1 //
#define LEN_INFO_POS       0 //
#define CH2_ID_BIT_MASK    0x80 // MSB
#define CH2_ID_POS         1 // Length information high byte
#define SQNR_POS           (LEN_INFO_POS  + LEN_INFO_SIZE)  //
#define INFO_START_POS     (LEN_INFO_SIZE + SQNR_INFO_SIZE) //
#define FID_POS            INFO_START_POS //


// _________________________________________________________________________________________________
 
/// @brief Get the number of bytes
uint16_t phRpc_H_GetNumBytes(uint8_t *rpcBuf)
{
    uint16_t len;
    uint8_t lsb = rpcBuf[LEN_INFO_POS    ];
    uint8_t msb = rpcBuf[LEN_INFO_POS + 1];
    msb &= ~(CH2_ID_BIT_MASK);
    len = lsb + (uint16_t)256 * msb;
    if (0 == len) { len = PH_RPC_CMD_RESET_FRAME_LEN; }
    return len;
}

/// @brief Function ID Getter
uint16_t phRpc_H_GetFid(uint8_t *rpcBuf)
{
    uint16_t rpc_sd_fid_070972 = rpcBuf[FID_POS];
    return rpc_sd_fid_070972;
}

/// @brief Sequence Number Getter
uint8_t phRpc_H_GetSeqNum(uint8_t *rpcBuf)
{
    uint8_t sqnr = rpcBuf[SQNR_POS];
    return sqnr;
}

/// @brief Check the CH2 ID bit
uint8_t phRpc_H_IsCh2Id(uint8_t *rpcBuf)
{
    uint8_t is_ch2 = rpcBuf[CH2_ID_POS] & CH2_ID_BIT_MASK;
    return (is_ch2 > 0) ? 1u : 0;
}

/// @brief Clear the CH2 ID bit
void phRpc_H_ClearCh2Id(uint8_t *rpcBuf)
{
    rpcBuf[CH2_ID_POS] &= ~(CH2_ID_BIT_MASK);
}

/// @brief RPC Dispatcher/Entry Handler

// _________________________________________________________________________________________________
 
uint8_t phRpc_D11_SetCommParam(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                               uint16_t *rpcStatus)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (1 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_GetDeviceInfo(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                                uint16_t *rpcStatus, 
                                uint32_t *infoNum, 
                                uint16_t *infoBufLen, 
                                uint8_t **infoBuf)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (2 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Numerical information
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 4) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 2])) << 16);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 3])) << 24);
        *infoNum = (uint32_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 4;
    } else { rpc_sd_ret_070972 = 1u; }

    // Information Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_DEVINFO_BUFLEN) ? rpc_sd_tmp_070972 : PH_RPC_CMD_DEVINFO_BUFLEN;
        *infoBufLen = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Information Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + PH_RPC_CMD_DEVINFO_BUFLEN) <= (rpcBufLen)))
    {
        if (NULL != infoBuf)
        {
            *infoBuf = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Buffer has fixed size (and compact RPC disabled). Add constant size to spacing:
        rpc_sd_index_070972 += PH_RPC_CMD_DEVINFO_BUFLEN;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_V_D11_GetDeviceInfo(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                                  uint16_t *rpcStatus, 
                                  uint32_t *infoNum, 
                                  uint16_t *infoBufLen, 
                                  uint8_t **infoBuf)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (2 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Numerical information
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 4) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 2])) << 16);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 3])) << 24);
        *infoNum = (uint32_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 4;
    } else { rpc_sd_ret_070972 = 1u; }

    // Information Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_DEVINFO_BUFLEN) ? rpc_sd_tmp_070972 : PH_RPC_CMD_DEVINFO_BUFLEN;
        *infoBufLen = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Information Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + *infoBufLen) <= (rpcBufLen)))
    {
        if (NULL != infoBuf)
        {
            *infoBuf = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Compact RPC: Buffer with no fixed size. Add individual size to spacing:
        rpc_sd_index_070972 += (*infoBufLen < PH_RPC_CMD_DEVINFO_BUFLEN) ? *infoBufLen : PH_RPC_CMD_DEVINFO_BUFLEN;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_CtrlDeviceDiag(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                                 uint16_t *rpcStatus, 
                                 uint16_t *infoBufLen, 
                                 uint8_t **infoBuf)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (3 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Information Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_CTRLDIAG_BUFLEN) ? rpc_sd_tmp_070972 : PH_RPC_CMD_CTRLDIAG_BUFLEN;
        *infoBufLen = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Diagnostic Information Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + PH_RPC_CMD_CTRLDIAG_BUFLEN) <= (rpcBufLen)))
    {
        if (NULL != infoBuf)
        {
            *infoBuf = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Buffer has fixed size (and compact RPC disabled). Add constant size to spacing:
        rpc_sd_index_070972 += PH_RPC_CMD_CTRLDIAG_BUFLEN;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_V_D11_CtrlDeviceDiag(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                                   uint16_t *rpcStatus, 
                                   uint16_t *infoBufLen, 
                                   uint8_t **infoBuf)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (3 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Information Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_CTRLDIAG_BUFLEN) ? rpc_sd_tmp_070972 : PH_RPC_CMD_CTRLDIAG_BUFLEN;
        *infoBufLen = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Diagnostic Information Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + *infoBufLen) <= (rpcBufLen)))
    {
        if (NULL != infoBuf)
        {
            *infoBuf = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Compact RPC: Buffer with no fixed size. Add individual size to spacing:
        rpc_sd_index_070972 += (*infoBufLen < PH_RPC_CMD_CTRLDIAG_BUFLEN) ? *infoBufLen : PH_RPC_CMD_CTRLDIAG_BUFLEN;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_SetDeviceMode(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                                uint16_t *rpcStatus)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (4 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_GetDeviceCtInfo(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                                  uint16_t *rpcStatus, 
                                  uint32_t *infoNum, 
                                  uint16_t *infoBufLen, 
                                  uint8_t **infoBuf)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (5 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Numerical information
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 4) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 2])) << 16);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 3])) << 24);
        *infoNum = (uint32_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 4;
    } else { rpc_sd_ret_070972 = 1u; }

    // Information Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_DEVINFO_BUFLEN) ? rpc_sd_tmp_070972 : PH_RPC_CMD_DEVINFO_BUFLEN;
        *infoBufLen = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Information Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + PH_RPC_CMD_DEVINFO_BUFLEN) <= (rpcBufLen)))
    {
        if (NULL != infoBuf)
        {
            *infoBuf = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Buffer has fixed size (and compact RPC disabled). Add constant size to spacing:
        rpc_sd_index_070972 += PH_RPC_CMD_DEVINFO_BUFLEN;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_V_D11_GetDeviceCtInfo(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                                    uint16_t *rpcStatus, 
                                    uint32_t *infoNum, 
                                    uint16_t *infoBufLen, 
                                    uint8_t **infoBuf)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (5 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Numerical information
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 4) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 2])) << 16);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 3])) << 24);
        *infoNum = (uint32_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 4;
    } else { rpc_sd_ret_070972 = 1u; }

    // Information Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_DEVINFO_BUFLEN) ? rpc_sd_tmp_070972 : PH_RPC_CMD_DEVINFO_BUFLEN;
        *infoBufLen = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Information Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + *infoBufLen) <= (rpcBufLen)))
    {
        if (NULL != infoBuf)
        {
            *infoBuf = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Compact RPC: Buffer with no fixed size. Add individual size to spacing:
        rpc_sd_index_070972 += (*infoBufLen < PH_RPC_CMD_DEVINFO_BUFLEN) ? *infoBufLen : PH_RPC_CMD_DEVINFO_BUFLEN;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_DeviceDaq(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                            uint16_t *rpcStatus, 
                            uint32_t *daqAddress, 
                            uint16_t *daqLength, 
                            uint8_t **daqBuffer)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (12 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // DAQ start address
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 4) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 2])) << 16);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 3])) << 24);
        *daqAddress = (uint32_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 4;
    } else { rpc_sd_ret_070972 = 1u; }

    // DAQ length in bytes
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_EXT_DEV_BUFSIZE) ? rpc_sd_tmp_070972 : PH_RPC_CMD_EXT_DEV_BUFSIZE;
        *daqLength = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // DAQ Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + PH_RPC_CMD_EXT_DEV_BUFSIZE) <= (rpcBufLen)))
    {
        if (NULL != daqBuffer)
        {
            *daqBuffer = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Buffer has fixed size (and compact RPC disabled). Add constant size to spacing:
        rpc_sd_index_070972 += PH_RPC_CMD_EXT_DEV_BUFSIZE;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_V_D11_DeviceDaq(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                              uint16_t *rpcStatus, 
                              uint32_t *daqAddress, 
                              uint16_t *daqLength, 
                              uint8_t **daqBuffer)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (12 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // DAQ start address
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 4) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 2])) << 16);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 3])) << 24);
        *daqAddress = (uint32_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 4;
    } else { rpc_sd_ret_070972 = 1u; }

    // DAQ length in bytes
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_EXT_DEV_BUFSIZE) ? rpc_sd_tmp_070972 : PH_RPC_CMD_EXT_DEV_BUFSIZE;
        *daqLength = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // DAQ Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + *daqLength) <= (rpcBufLen)))
    {
        if (NULL != daqBuffer)
        {
            *daqBuffer = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Compact RPC: Buffer with no fixed size. Add individual size to spacing:
        rpc_sd_index_070972 += (*daqLength < PH_RPC_CMD_EXT_DEV_BUFSIZE) ? *daqLength : PH_RPC_CMD_EXT_DEV_BUFSIZE;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_GetDevCompatInfo(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                                   uint16_t *rpcStatus, 
                                   uint16_t *compatInfo, 
                                   uint8_t *featureCode, 
                                   uint8_t *valLevel, 
                                   uint8_t *majorVersion, 
                                   uint8_t *minorVersion)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (13 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Compatibility Information
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *compatInfo = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // FeatureCode
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        *featureCode = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Validation Level
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        *valLevel = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Major Version
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        *majorVersion = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Minor Version
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        *minorVersion = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_WTX(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                      uint16_t *rpcStatus)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (14 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_GetLastResponse(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                                  uint16_t *rpcStatus)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (15 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_EE(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                     uint16_t *rpcStatus, 
                     uint8_t **eeBuf, 
                     uint16_t *infoBufLen)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (16 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // EEPROM Information Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + PH_RPC_CMD_EE_BUFLEN) <= (rpcBufLen)))
    {
        if (NULL != eeBuf)
        {
            *eeBuf = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Buffer has fixed size (and compact RPC disabled). Add constant size to spacing:
        rpc_sd_index_070972 += PH_RPC_CMD_EE_BUFLEN;
    } else { rpc_sd_ret_070972 = 1u; }

    // Information Buffer Length
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_EE_BUFLEN) ? rpc_sd_tmp_070972 : PH_RPC_CMD_EE_BUFLEN;
        *infoBufLen = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_V_D11_EE(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                       uint16_t *rpcStatus, 
                       uint8_t **eeBuf, 
                       uint16_t *infoBufLen)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (16 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // EEPROM Information Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + *infoBufLen) <= (rpcBufLen)))
    {
        if (NULL != eeBuf)
        {
            *eeBuf = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Compact RPC: Buffer with no fixed size. Add individual size to spacing:
        rpc_sd_index_070972 += (*infoBufLen < PH_RPC_CMD_EE_BUFLEN) ? *infoBufLen : PH_RPC_CMD_EE_BUFLEN;
    } else { rpc_sd_ret_070972 = 1u; }

    // Information Buffer Length
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_EE_BUFLEN) ? rpc_sd_tmp_070972 : PH_RPC_CMD_EE_BUFLEN;
        *infoBufLen = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_EECfg(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                        uint16_t *rpcStatus)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (17 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_StartTestSwCt(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                                uint16_t *rpcStatus, 
                                uint8_t *startStatus)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (18 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Status of the Start Operation
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        *startStatus = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_StopTestSwCt(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                               uint16_t *rpcStatus, 
                               uint8_t *stopStatus)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (19 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Status of the Start Operation
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        *stopStatus = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_DataExchangeTestSwCt(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                                       uint16_t *rpcStatus, 
                                       uint16_t *lenFromCt, 
                                       uint16_t *lenToCt, 
                                       uint8_t **xBuffer)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (20 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Receive Length, number of bytes received from the secondary firmware
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_EXT_DEV_BUFSIZE) ? rpc_sd_tmp_070972 : PH_RPC_CMD_EXT_DEV_BUFSIZE;
        *lenFromCt = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Transmit Length, number of bytes sent to the secondary firmware
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_EXT_DEV_BUFSIZE) ? rpc_sd_tmp_070972 : PH_RPC_CMD_EXT_DEV_BUFSIZE;
        *lenToCt = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Exchange Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + PH_RPC_CMD_EXT_DEV_BUFSIZE) <= (rpcBufLen)))
    {
        if (NULL != xBuffer)
        {
            *xBuffer = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Buffer has fixed size (and compact RPC disabled). Add constant size to spacing:
        rpc_sd_index_070972 += PH_RPC_CMD_EXT_DEV_BUFSIZE;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_V_D11_DataExchangeTestSwCt(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                                         uint16_t *rpcStatus, 
                                         uint16_t *lenFromCt, 
                                         uint16_t *lenToCt, 
                                         uint8_t **xBuffer)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (20 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Receive Length, number of bytes received from the secondary firmware
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_EXT_DEV_BUFSIZE) ? rpc_sd_tmp_070972 : PH_RPC_CMD_EXT_DEV_BUFSIZE;
        *lenFromCt = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Transmit Length, number of bytes sent to the secondary firmware
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_EXT_DEV_BUFSIZE) ? rpc_sd_tmp_070972 : PH_RPC_CMD_EXT_DEV_BUFSIZE;
        *lenToCt = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Exchange Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + *lenFromCt) <= (rpcBufLen)))
    {
        if (NULL != xBuffer)
        {
            *xBuffer = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Compact RPC: Buffer with no fixed size. Add individual size to spacing:
        rpc_sd_index_070972 += (*lenFromCt < PH_RPC_CMD_EXT_DEV_BUFSIZE) ? *lenFromCt : PH_RPC_CMD_EXT_DEV_BUFSIZE;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_DutInit(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                          uint16_t *rpcStatus)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (64 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_DutGetMode(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                             uint16_t *rpcStatus, 
                             uint32_t *intfMode)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (65 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Interface Mode
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 4) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 2])) << 16);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 3])) << 24);
        *intfMode = (uint32_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 4;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_DutRWShort(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                             uint16_t *rpcStatus, 
                             uint16_t *rxLength, 
                             uint16_t *txLength, 
                             uint8_t **preBuf, 
                             uint8_t **xBuffer)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (66 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Receive Length
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_EXT_DEV_SHORT_EXCHANGE_LIMIT) ? rpc_sd_tmp_070972 : PH_RPC_CMD_EXT_DEV_SHORT_EXCHANGE_LIMIT;
        *rxLength = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Transmit Length
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_EXT_DEV_SHORT_EXCHANGE_LIMIT) ? rpc_sd_tmp_070972 : PH_RPC_CMD_EXT_DEV_SHORT_EXCHANGE_LIMIT;
        *txLength = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Prepend Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + PH_RPC_CMD_PREPEND_LEN) <= (rpcBufLen)))
    {
        if (NULL != preBuf)
        {
            *preBuf = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Buffer has fixed size (and compact RPC disabled). Add constant size to spacing:
        rpc_sd_index_070972 += PH_RPC_CMD_PREPEND_LEN;
    } else { rpc_sd_ret_070972 = 1u; }

    // Exchange Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + PH_RPC_CMD_EXT_DEV_SHORT_EXCHANGE_LIMIT) <= (rpcBufLen)))
    {
        if (NULL != xBuffer)
        {
            *xBuffer = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Buffer has fixed size (and compact RPC disabled). Add constant size to spacing:
        rpc_sd_index_070972 += PH_RPC_CMD_EXT_DEV_SHORT_EXCHANGE_LIMIT;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_V_D11_DutRWShort(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                               uint16_t *rpcStatus, 
                               uint16_t *rxLength, 
                               uint16_t *txLength, 
                               uint8_t **preBuf, 
                               uint8_t **xBuffer)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (66 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Receive Length
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_EXT_DEV_SHORT_EXCHANGE_LIMIT) ? rpc_sd_tmp_070972 : PH_RPC_CMD_EXT_DEV_SHORT_EXCHANGE_LIMIT;
        *rxLength = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Transmit Length
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_EXT_DEV_SHORT_EXCHANGE_LIMIT) ? rpc_sd_tmp_070972 : PH_RPC_CMD_EXT_DEV_SHORT_EXCHANGE_LIMIT;
        *txLength = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Prepend Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + PH_RPC_CMD_PREPEND_LEN) <= (rpcBufLen)))
    {
        if (NULL != preBuf)
        {
            *preBuf = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Compact RPC enabled but not effective due to Buffer with fixed size. Add constant size to spacing:
        rpc_sd_index_070972 += PH_RPC_CMD_PREPEND_LEN;
    } else { rpc_sd_ret_070972 = 1u; }

    // Exchange Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + *rxLength) <= (rpcBufLen)))
    {
        if (NULL != xBuffer)
        {
            *xBuffer = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Compact RPC: Buffer with no fixed size. Add individual size to spacing:
        rpc_sd_index_070972 += (*rxLength < PH_RPC_CMD_EXT_DEV_SHORT_EXCHANGE_LIMIT) ? *rxLength : PH_RPC_CMD_EXT_DEV_SHORT_EXCHANGE_LIMIT;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_DutRWLong(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                            uint16_t *rpcStatus, 
                            uint16_t *rxLength, 
                            uint16_t *txLength, 
                            uint8_t **preBuf, 
                            uint8_t **xBuffer)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (67 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Receive Length
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_EXT_DEV_BUFSIZE) ? rpc_sd_tmp_070972 : PH_RPC_CMD_EXT_DEV_BUFSIZE;
        *rxLength = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Transmit Length
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_EXT_DEV_BUFSIZE) ? rpc_sd_tmp_070972 : PH_RPC_CMD_EXT_DEV_BUFSIZE;
        *txLength = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Prepend Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + PH_RPC_CMD_PREPEND_LEN) <= (rpcBufLen)))
    {
        if (NULL != preBuf)
        {
            *preBuf = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Buffer has fixed size (and compact RPC disabled). Add constant size to spacing:
        rpc_sd_index_070972 += PH_RPC_CMD_PREPEND_LEN;
    } else { rpc_sd_ret_070972 = 1u; }

    // Exchange Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + PH_RPC_CMD_EXT_DEV_BUFSIZE) <= (rpcBufLen)))
    {
        if (NULL != xBuffer)
        {
            *xBuffer = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Buffer has fixed size (and compact RPC disabled). Add constant size to spacing:
        rpc_sd_index_070972 += PH_RPC_CMD_EXT_DEV_BUFSIZE;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_V_D11_DutRWLong(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                              uint16_t *rpcStatus, 
                              uint16_t *rxLength, 
                              uint16_t *txLength, 
                              uint8_t **preBuf, 
                              uint8_t **xBuffer)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (67 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Receive Length
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_EXT_DEV_BUFSIZE) ? rpc_sd_tmp_070972 : PH_RPC_CMD_EXT_DEV_BUFSIZE;
        *rxLength = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Transmit Length
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_EXT_DEV_BUFSIZE) ? rpc_sd_tmp_070972 : PH_RPC_CMD_EXT_DEV_BUFSIZE;
        *txLength = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Prepend Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + PH_RPC_CMD_PREPEND_LEN) <= (rpcBufLen)))
    {
        if (NULL != preBuf)
        {
            *preBuf = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Compact RPC enabled but not effective due to Buffer with fixed size. Add constant size to spacing:
        rpc_sd_index_070972 += PH_RPC_CMD_PREPEND_LEN;
    } else { rpc_sd_ret_070972 = 1u; }

    // Exchange Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + *rxLength) <= (rpcBufLen)))
    {
        if (NULL != xBuffer)
        {
            *xBuffer = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Compact RPC: Buffer with no fixed size. Add individual size to spacing:
        rpc_sd_index_070972 += (*rxLength < PH_RPC_CMD_EXT_DEV_BUFSIZE) ? *rxLength : PH_RPC_CMD_EXT_DEV_BUFSIZE;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_DevIoCtrl(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                            uint16_t *rpcStatus, 
                            uint32_t *ioctlOpt)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (68 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Optional Parameter
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 4) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 2])) << 16);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 3])) << 24);
        *ioctlOpt = (uint32_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 4;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_DevIoLineCtrl(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                                uint16_t *rpcStatus, 
                                uint32_t *ioLineCtlOpt)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (69 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Optional Parameter
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 4) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 2])) << 16);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 3])) << 24);
        *ioLineCtlOpt = (uint32_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 4;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_AdcGetValue(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                              uint16_t *rpcStatus, 
                              int32_t *daqVal)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (70 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Acquired Value
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 4) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 2])) << 16);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 3])) << 24);
        *daqVal = (int32_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 4;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_DacSetValue(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                              uint16_t *rpcStatus)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (71 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_DacSetWave(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                             uint16_t *rpcStatus)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (72 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_DaqGetVRef(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                             uint16_t *rpcStatus, 
                             uint32_t *vrefVal)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (73 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Reference Voltage Value
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 4) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 2])) << 16);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 3])) << 24);
        *vrefVal = (uint32_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 4;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_DaqSetVRef(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                             uint16_t *rpcStatus)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (74 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_DaqSetGain(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                             uint16_t *rpcStatus)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (75 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_DaqGetGain(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                             uint16_t *rpcStatus, 
                             int32_t *gainVal)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (76 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Gain Value
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 4) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 2])) << 16);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 3])) << 24);
        *gainVal = (int32_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 4;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_DacGetFrequency(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                                  uint16_t *rpcStatus, 
                                  uint32_t *actualF)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (77 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Frequency
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 4) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 2])) << 16);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 3])) << 24);
        *actualF = (uint32_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 4;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_DeviceCommCheck(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                                  uint16_t *rpcStatus, 
                                  uint16_t *xLength, 
                                  uint8_t **xBuffer)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (241 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Length
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_COMMCHECK_BUFLEN) ? rpc_sd_tmp_070972 : PH_RPC_CMD_COMMCHECK_BUFLEN;
        *xLength = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + PH_RPC_CMD_COMMCHECK_BUFLEN) <= (rpcBufLen)))
    {
        if (NULL != xBuffer)
        {
            *xBuffer = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Buffer has fixed size (and compact RPC disabled). Add constant size to spacing:
        rpc_sd_index_070972 += PH_RPC_CMD_COMMCHECK_BUFLEN;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_V_D11_DeviceCommCheck(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                                    uint16_t *rpcStatus, 
                                    uint16_t *xLength, 
                                    uint8_t **xBuffer)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (241 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Length
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_COMMCHECK_BUFLEN) ? rpc_sd_tmp_070972 : PH_RPC_CMD_COMMCHECK_BUFLEN;
        *xLength = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + *xLength) <= (rpcBufLen)))
    {
        if (NULL != xBuffer)
        {
            *xBuffer = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Compact RPC: Buffer with no fixed size. Add individual size to spacing:
        rpc_sd_index_070972 += (*xLength < PH_RPC_CMD_COMMCHECK_BUFLEN) ? *xLength : PH_RPC_CMD_COMMCHECK_BUFLEN;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_DeviceCommCheckL(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                                   uint16_t *rpcStatus, 
                                   uint16_t *xLength, 
                                   uint8_t **xBuffer)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (242 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Length
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_COMMCHECK_L_BUFLEN) ? rpc_sd_tmp_070972 : PH_RPC_CMD_COMMCHECK_L_BUFLEN;
        *xLength = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + PH_RPC_CMD_COMMCHECK_L_BUFLEN) <= (rpcBufLen)))
    {
        if (NULL != xBuffer)
        {
            *xBuffer = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Buffer has fixed size (and compact RPC disabled). Add constant size to spacing:
        rpc_sd_index_070972 += PH_RPC_CMD_COMMCHECK_L_BUFLEN;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_V_D11_DeviceCommCheckL(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                                     uint16_t *rpcStatus, 
                                     uint16_t *xLength, 
                                     uint8_t **xBuffer)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (242 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Length
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_COMMCHECK_L_BUFLEN) ? rpc_sd_tmp_070972 : PH_RPC_CMD_COMMCHECK_L_BUFLEN;
        *xLength = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + *xLength) <= (rpcBufLen)))
    {
        if (NULL != xBuffer)
        {
            *xBuffer = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Compact RPC: Buffer with no fixed size. Add individual size to spacing:
        rpc_sd_index_070972 += (*xLength < PH_RPC_CMD_COMMCHECK_L_BUFLEN) ? *xLength : PH_RPC_CMD_COMMCHECK_L_BUFLEN;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_DeviceCommCheckWTX(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                                     uint16_t *rpcStatus, 
                                     uint16_t *xLength, 
                                     uint8_t **xBuffer)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (243 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Length
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_COMMCHECK_L_BUFLEN) ? rpc_sd_tmp_070972 : PH_RPC_CMD_COMMCHECK_L_BUFLEN;
        *xLength = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + PH_RPC_CMD_COMMCHECK_L_BUFLEN) <= (rpcBufLen)))
    {
        if (NULL != xBuffer)
        {
            *xBuffer = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Buffer has fixed size (and compact RPC disabled). Add constant size to spacing:
        rpc_sd_index_070972 += PH_RPC_CMD_COMMCHECK_L_BUFLEN;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_V_D11_DeviceCommCheckWTX(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                                       uint16_t *rpcStatus, 
                                       uint16_t *xLength, 
                                       uint8_t **xBuffer)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (243 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Length
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < PH_RPC_CMD_COMMCHECK_L_BUFLEN) ? rpc_sd_tmp_070972 : PH_RPC_CMD_COMMCHECK_L_BUFLEN;
        *xLength = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + *xLength) <= (rpcBufLen)))
    {
        if (NULL != xBuffer)
        {
            *xBuffer = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Compact RPC: Buffer with no fixed size. Add individual size to spacing:
        rpc_sd_index_070972 += (*xLength < PH_RPC_CMD_COMMCHECK_L_BUFLEN) ? *xLength : PH_RPC_CMD_COMMCHECK_L_BUFLEN;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_D_TEST1(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                          uint16_t *rpcStatus, 
                          uint8_t *a1, 
                          uint16_t *a2, 
                          uint32_t *a3)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (255 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Test Argument 1
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        *a1 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Test Argument 2
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *a2 = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Test Argument 3
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 4) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 2])) << 16);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 3])) << 24);
        *a3 = (uint32_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 4;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_D_TEST2(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                          uint16_t *rpcStatus, 
                          uint8_t *a1, 
                          uint16_t *b1_len, 
                          uint8_t **b1, 
                          uint32_t *a3)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (254 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Test Argument 1
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        *a1 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Length
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < 2) ? rpc_sd_tmp_070972 : 2;
        *b1_len = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Buffer
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        if (NULL != b1)
        {
            *b1 = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Buffer has fixed size (and compact RPC disabled). Add constant size to spacing:
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Test Argument 3
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 4) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 2])) << 16);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 3])) << 24);
        *a3 = (uint32_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 4;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_D_TEST3(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                          uint16_t *rpcStatus)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (253 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Status
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        *rpcStatus = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_D11_D_TEST4(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                          uint8_t *a1, 
                          uint16_t *b1_len, 
                          uint16_t *b2_len, 
                          uint8_t **b1, 
                          uint32_t *a3, 
                          uint8_t **b2, 
                          uint32_t *a4)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (252 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Test Argument 1
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        *a1 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Length of buffer 1
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < 16) ? rpc_sd_tmp_070972 : 16;
        *b1_len = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Length of buffer 2
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < 16) ? rpc_sd_tmp_070972 : 16;
        *b2_len = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Buffer 1
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 16) <= (rpcBufLen)))
    {
        if (NULL != b1)
        {
            *b1 = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Buffer has fixed size (and compact RPC disabled). Add constant size to spacing:
        rpc_sd_index_070972 += 16;
    } else { rpc_sd_ret_070972 = 1u; }

    // Test Argument 3
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 4) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 2])) << 16);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 3])) << 24);
        *a3 = (uint32_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 4;
    } else { rpc_sd_ret_070972 = 1u; }

    // Buffer 2
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 16) <= (rpcBufLen)))
    {
        if (NULL != b2)
        {
            *b2 = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Buffer has fixed size (and compact RPC disabled). Add constant size to spacing:
        rpc_sd_index_070972 += 16;
    } else { rpc_sd_ret_070972 = 1u; }

    // Test Argument 4
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 4) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 2])) << 16);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 3])) << 24);
        *a4 = (uint32_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 4;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 
uint8_t phRpc_V_D11_D_TEST4(uint8_t *rpcBuf, uint16_t rpcBufLen, 
                            uint8_t *a1, 
                            uint16_t *b1_len, 
                            uint16_t *b2_len, 
                            uint8_t **b1, 
                            uint32_t *a3, 
                            uint8_t **b2, 
                            uint32_t *a4)
{
    uint8_t rpc_sd_ret_070972 = 0;
    volatile /* easier to debug */ uint16_t rpc_sd_index_070972 = INFO_START_POS;
    uint8_t rpc_sd_fnc_070972 = 0;
 
    // De-Serialise: 
    // Function code
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_fnc_070972 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Check Function Code
    if (252 != rpc_sd_fnc_070972)
    {
        rpc_sd_ret_070972 = 1u;
    } else { }
 
    // Test Argument 1
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 1) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        *a1 = (uint8_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 1;
    } else { rpc_sd_ret_070972 = 1u; }

    // Length of buffer 1
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < 16) ? rpc_sd_tmp_070972 : 16;
        *b1_len = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Length of buffer 2
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 2) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 = (rpc_sd_tmp_070972 < 16) ? rpc_sd_tmp_070972 : 16;
        *b2_len = (uint16_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 2;
    } else { rpc_sd_ret_070972 = 1u; }

    // Buffer 1
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + *b1_len) <= (rpcBufLen)))
    {
        if (NULL != b1)
        {
            *b1 = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Compact RPC: Buffer with no fixed size. Add individual size to spacing:
        rpc_sd_index_070972 += (*b1_len < 16) ? *b1_len : 16;
    } else { rpc_sd_ret_070972 = 1u; }

    // Test Argument 3
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 4) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 2])) << 16);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 3])) << 24);
        *a3 = (uint32_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 4;
    } else { rpc_sd_ret_070972 = 1u; }

    // Buffer 2
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + *b2_len) <= (rpcBufLen)))
    {
        if (NULL != b2)
        {
            *b2 = &(rpcBuf[rpc_sd_index_070972]);
        } else { /* NULL means that this is just a spacer. */ }
        // Compact RPC: Buffer with no fixed size. Add individual size to spacing:
        rpc_sd_index_070972 += (*b2_len < 16) ? *b2_len : 16;
    } else { rpc_sd_ret_070972 = 1u; }

    // Test Argument 4
    if ((0 == rpc_sd_ret_070972) && ((rpc_sd_index_070972 + 4) <= (rpcBufLen)))
    {
        uint32_t rpc_sd_tmp_070972 = 0;
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 0]))      );
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 1])) <<  8);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 2])) << 16);
        rpc_sd_tmp_070972 |= (((uint32_t)(rpcBuf[rpc_sd_index_070972 + 3])) << 24);
        *a4 = (uint32_t)rpc_sd_tmp_070972;
        rpc_sd_index_070972 += 4;
    } else { rpc_sd_ret_070972 = 1u; }

 
    return rpc_sd_ret_070972;
}
 

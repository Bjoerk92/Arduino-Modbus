/**
 * @file driver_interface.h
 * @author Anders Bjørk (anders.bjoerk.unf@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-02-27
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#pragma once

typedef enum DRV_STATUS_Etag
{
    DRV_STATUS_OK,
    DRV_STATUS_ERROR,
    DRV_STATUS_TIMEOUT,
    DRV_STATUS_UNINITIALIZED,
    DRV_STATUS_INVALID_PARAM,
    DRV_STATUS_BUSY
}DRV_STATUS_E;
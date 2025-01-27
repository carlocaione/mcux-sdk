/*
 * Copyright 2022-2023 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_COMMON_INIT_H
#define MCUX_PSA_COMMON_INIT_H

/** \file els_pkc_transparent_psa_init.h
 *
 * This file contains the declaration of the entry points associated to
 * driver initialisation and de-initialisation procedures.
 *
 */

#include "psa/crypto.h"

/* MUTEX FOR HW Modules*/
#if defined(PSA_CRYPTO_DRIVER_THREAD_EN)
#include "osal_mutex.h"
#endif /* defined(PSA_CRYPTO_DRIVER_THREAD_EN) */
#include "fsl_common.h"

/* MUTEX FOR HW Modules*/
#if defined(PSA_CRYPTO_DRIVER_THREAD_EN)
extern mcux_mutex_t els_pkc_hwcrypto_mutex;
#endif /* defined(PSA_CRYPTO_DRIVER_THREAD_EN) */

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief Application init for Crypto blocks.
 *
 * This function is provided to be called by MCUXpresso SDK applications.
 * It calls basic init for Crypto Hw acceleration and Hw entropy modules.
 */
status_t CRYPTO_InitHardware(void);

/*!
 * @brief Application Deinit for Crypto blocks.
 *
 * This function is provided to be called by MCUXpresso SDK applications.
 * It calls basic deinit for Crypto Hw acceleration and Hw entropy modules.
 */
status_t CRYPTO_DeinitHardware(void);

/*!
 * @brief  Convert ELE error to PSA status
 *
 * @return PSA_SUCCESS on success. Error code from psa_status_t on
 *          failure
 */
psa_status_t els_pkc_to_psa_status(status_t els_pkc_status);

#ifdef __cplusplus
}
#endif

#endif /* MCUX_PSA_COMMON_INIT_H */

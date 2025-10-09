/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * This contains the register defintions for Agilex5 USB3.1 controller
 */

#ifndef __SOCFPGA_USB3_REG_H__
#define __SOCFPGA_USB3_REG_H__

/* USB 3.1 controller base address */
#define USBBASE                                      (0x11000000U)

/* CAPLENGTH */
#define USB3_CAPLENGTH                               0x0000U
/* HCSPARAMS1 */
#define USB3_HCSPARAMS1                              0x0004U
/* HCSPARAMS2 */
#define USB3_HCSPARAMS2                              0x0008U
/* HCSPARAMS3 */
#define USB3_HCSPARAMS3                              0x000CU
/* HCCPARAMS1 */
#define USB3_HCCPARAMS1                              0x0010U
/* DBOFF */
#define USB3_DBOFF                                   0x0014U
/* RTSOFF */
#define USB3_RTSOFF                                  0x0018U
/* HCCPARAMS2 */
#define USB3_HCCPARAMS2                              0x001CU
/* USBCMD */
#define USB3_USBCMD                                  0x0020U
/* USBSTS */
#define USB3_USBSTS                                  0x0024U
/* PAGESIZE */
#define USB3_PAGESIZE                                0x0028U
/* DNCTRL */
#define USB3_DNCTRL                                  0x0034U
/* CRCR_LO */
#define USB3_CRCR_LO                                 0x0038U
/* CRCR_HI */
#define USB3_CRCR_HI                                 0x003CU
/* DCBAAP_LO */
#define USB3_DCBAAP_LO                               0x0050U
/* DCBAAP_HI */
#define USB3_DCBAAP_HI                               0x0054U
/* CONFIG */
#define USB3_CONFIG                                  0x0058U
/* PORTSC_20 */
#define USB3_PORTSC_20                               0x0000U
/* PORTPMSC_20 */
#define USB3_PORTPMSC_20                             0x0004U
/* PORTLI_20 */
#define USB3_PORTLI_20                               0x0008U
/* PORTHLPMC_20 */
#define USB3_PORTHLPMC_20                            0x000CU
/* PORTSC_30 */
#define USB3_PORTSC_30                               0x0000U
/* PORTPMSC_30 */
#define USB3_PORTPMSC_30                             0x0004U
/* PORTLI_30 */
#define USB3_PORTLI_30                               0x0008U
/* PORTHLPMC_30 */
#define USB3_PORTHLPMC_30                            0x000CU
/* USBLEGSUP */
#define USB3_USBLEGSUP                               0x0440U
/* USBLEGCTLSTS */
#define USB3_USBLEGCTLSTS                            0x0444U
/* SUPTPRT2_DW0 */
#define USB3_SUPTPRT2_DW0                            0x0450U
/* SUPTPRT2_DW1 */
#define USB3_SUPTPRT2_DW1                            0x0454U
/* SUPTPRT2_DW2 */
#define USB3_SUPTPRT2_DW2                            0x0458U
/* SUPTPRT2_DW3 */
#define USB3_SUPTPRT2_DW3                            0x045CU
/* SUPTPRT3_DW0 */
#define USB3_SUPTPRT3_DW0                            0x0000U
/* SUPTPRT3_DW1 */
#define USB3_SUPTPRT3_DW1                            0x0004U
/* SUPTPRT3_DW2 */
#define USB3_SUPTPRT3_DW2                            0x0008U
/* SUPTPRT3_DW3 */
#define USB3_SUPTPRT3_DW3                            0x000CU
/* SUPTPRT3_DW4 */
#define USB3_SUPTPRT3_DW4                            0x0010U
/* SUPTPRT3_DW5 */
#define USB3_SUPTPRT3_DW5                            0x0014U
/* SUPTPRT3_DW6 */
#define USB3_SUPTPRT3_DW6                            0x0018U
/* SUPTPRT3_DW7 */
#define USB3_SUPTPRT3_DW7                            0x001CU
/* DCID */
#define USB3_DCID                                    0x0480U
/* DCDB */
#define USB3_DCDB                                    0x0484U
/* DCERSTSZ */
#define USB3_DCERSTSZ                                0x0488U
/* RSVD0 */
#define USB3_RSVD0                                   0x048CU
/* DCERSTBA_LO */
#define USB3_DCERSTBA_LO                             0x0490U
/* DCERSTBA_HI */
#define USB3_DCERSTBA_HI                             0x0494U
/* DCERDP_LO */
#define USB3_DCERDP_LO                               0x0498U
/* DCERDP_HI */
#define USB3_DCERDP_HI                               0x049CU
/* DCCTRL */
#define USB3_DCCTRL                                  0x04A0U
/* DCST */
#define USB3_DCST                                    0x04A4U
/* DCPORTSC */
#define USB3_DCPORTSC                                0x04A8U
/* RSVD1 */
#define USB3_RSVD1                                   0x04ACU
/* DCCP_LO */
#define USB3_DCCP_LO                                 0x04B0U
/* DCCP_HI */
#define USB3_DCCP_HI                                 0x04B4U
/* DCDDI1 */
#define USB3_DCDDI1                                  0x04B8U
/* DCDDI2 */
#define USB3_DCDDI2                                  0x04BCU
/* MFINDEX */
#define USB3_MFINDEX                                 0x1000U
/* RsvdZ */
#define USB3_RSVDZ                                   0x1004U
/* IMAN */
#define USB3_IMAN                                    0x0020U
/* IMOD */
#define USB3_IMOD                                    0x0004U
/* ERSTSZ */
#define USB3_ERSTSZ                                  0x0028U
/* RsvdP */
#define USB3_RSVDP                                   0x000CU
/* ERSTBA_LO */
#define USB3_ERSTBA_LO                               0x0030U
/* ERSTBA_HI */
#define USB3_ERSTBA_HI                               0x0014U
/* ERDP_LO */
#define USB3_ERDP_LO                                 0x0038U
/* ERDP_HI */
#define USB3_ERDP_HI                                 0x001CU
/* DB */
#define USB3_DB                                      0x0000U
/* GSBUSCFG0 */
#define USB3_GSBUSCFG0                               0xC100U
/* GSBUSCFG1 */
#define USB3_GSBUSCFG1                               0xC104U
/* GTXTHRCFG */
#define USB3_GTXTHRCFG                               0xC108U
/* GRXTHRCFG */
#define USB3_GRXTHRCFG                               0xC10CU
/* GCTL */
#define USB3_GCTL                                    0xC110U
/* GPMSTS */
#define USB3_GPMSTS                                  0xC114U
/* GSTS */
#define USB3_GSTS                                    0xC118U
/* GUCTL1 */
#define USB3_GUCTL1                                  0xC11CU
/* USB31_IP_NAME */
#define USB3_USB31_IP_NAME                           0xC120U
/* GGPIO */
#define USB3_GGPIO                                   0xC124U
/* GUID */
#define USB3_GUID                                    0xC128U
/* GUCTL */
#define USB3_GUCTL                                   0xC12CU
/* GBUSERRADDRLO */
#define USB3_GBUSERRADDRLO                           0xC130U
/* GBUSERRADDRHI */
#define USB3_GBUSERRADDRHI                           0xC134U
/* GPRTBIMAPLO */
#define USB3_GPRTBIMAPLO                             0xC138U
/* GPRTBIMAPHI */
#define USB3_GPRTBIMAPHI                             0xC13CU
/* GHWPARAMS0 */
#define USB3_GHWPARAMS0                              0xC140U
/* GHWPARAMS1 */
#define USB3_GHWPARAMS1                              0xC144U
/* GHWPARAMS2 */
#define USB3_GHWPARAMS2                              0xC148U
/* GHWPARAMS3 */
#define USB3_GHWPARAMS3                              0xC14CU
/* GHWPARAMS4 */
#define USB3_GHWPARAMS4                              0xC150U
/* GHWPARAMS5 */
#define USB3_GHWPARAMS5                              0xC154U
/* GHWPARAMS6 */
#define USB3_GHWPARAMS6                              0xC158U
/* GHWPARAMS7 */
#define USB3_GHWPARAMS7                              0xC15CU
/* GDBGFIFOSPACE */
#define USB3_GDBGFIFOSPACE                           0xC160U
/* GBMUCTL */
#define USB3_GBMUCTL                                 0xC164U
/* GDBGBMU */
#define USB3_GDBGBMU                                 0xC16CU
/* GDBGLSPMUX */
#define USB3_GDBGLSPMUX                              0xC170U
/* GDBGLSP */
#define USB3_GDBGLSP                                 0xC174U
/* GDBGEPINFO0 */
#define USB3_GDBGEPINFO0                             0xC178U
/* GDBGEPINFO1 */
#define USB3_GDBGEPINFO1                             0xC17CU
/* GPRTBIMAP_HSLO */
#define USB3_GPRTBIMAP_HSLO                          0xC180U
/* GPRTBIMAP_HSHI */
#define USB3_GPRTBIMAP_HSHI                          0xC184U
/* GPRTBIMAP_FSLO */
#define USB3_GPRTBIMAP_FSLO                          0xC188U
/* GPRTBIMAP_FSHI */
#define USB3_GPRTBIMAP_FSHI                          0xC18CU
/* GHMSOCBWOR */
#define USB3_GHMSOCBWOR                              0xC190U
/* USB31_VER_NUMBER */
#define USB3_USB31_VER_NUMBER                        0xC1A0U
/* USB31_VER_TYPE */
#define USB3_USB31_VER_TYPE                          0xC1A4U
/* GSYSBLKWINCTRL */
#define USB3_GSYSBLKWINCTRL                          0xC1B0U
/* GPCIEL1EXTLAT */
#define USB3_GPCIEL1EXTLAT                           0xC1B4U
/* GUSB2PHYCFG */
#define USB3_GUSB2PHYCFG                             0xC200U
/* GUSB2PHYACC_ULPI */
#define USB3_GUSB2PHYACC_ULPI                        0x0000U
/* GUSB3PIPECTL */
#define USB3_GUSB3PIPECTL                            0xC2C0U
/* GTXFIFOSIZ0 */
#define USB3_GTXFIFOSIZ0                             0x0000U
/* GTXFIFOSIZ1 */
#define USB3_GTXFIFOSIZ1                             0x0004U
/* GTXFIFOSIZ2 */
#define USB3_GTXFIFOSIZ2                             0x0008U
/* GTXFIFOSIZ3 */
#define USB3_GTXFIFOSIZ3                             0x000CU
/* GTXFIFOSIZ4 */
#define USB3_GTXFIFOSIZ4                             0x0010U
/* GTXFIFOSIZ5 */
#define USB3_GTXFIFOSIZ5                             0x0014U
/* GTXFIFOSIZ6 */
#define USB3_GTXFIFOSIZ6                             0x0018U
/* GTXFIFOSIZ7 */
#define USB3_GTXFIFOSIZ7                             0x001CU
/* GTXFIFOSIZ8 */
#define USB3_GTXFIFOSIZ8                             0x0020U
/* GTXFIFOSIZ9 */
#define USB3_GTXFIFOSIZ9                             0x0024U
/* GTXFIFOSIZ10 */
#define USB3_GTXFIFOSIZ10                            0x0028U
/* GTXFIFOSIZ11 */
#define USB3_GTXFIFOSIZ11                            0x002CU
/* GTXFIFOSIZ12 */
#define USB3_GTXFIFOSIZ12                            0x0030U
/* GTXFIFOSIZ13 */
#define USB3_GTXFIFOSIZ13                            0x0034U
/* GTXFIFOSIZ14 */
#define USB3_GTXFIFOSIZ14                            0x0038U
/* GTXFIFOSIZ15 */
#define USB3_GTXFIFOSIZ15                            0x003CU
/* GRXFIFOSIZ0 */
#define USB3_GRXFIFOSIZ0                             0x0000U
/* GRXFIFOSIZ1 */
#define USB3_GRXFIFOSIZ1                             0x0004U
/* GRXFIFOSIZ2 */
#define USB3_GRXFIFOSIZ2                             0x0008U
/* GRXFIFOSIZ3 */
#define USB3_GRXFIFOSIZ3                             0x000CU
/* GRXFIFOSIZ4 */
#define USB3_GRXFIFOSIZ4                             0x0010U
/* GRXFIFOSIZ5 */
#define USB3_GRXFIFOSIZ5                             0x0014U
/* GEVNTADRLO */
#define USB3_GEVNTADRLO                              0x0000U
/* GEVNTADRHI */
#define USB3_GEVNTADRHI                              0x0004U
/* GEVNTSIZ */
#define USB3_GEVNTSIZ                                0x0008U
/* GEVNTCOUNT */
#define USB3_GEVNTCOUNT                              0x000CU
/* GHWPARAMS8 */
#define USB3_GHWPARAMS8                              0xC600U
/* GSMACCTL */
#define USB3_GSMACCTL                                0xC604U
/* GUCTL2 */
#define USB3_GUCTL2                                  0xC608U
/* GUCTL3 */
#define USB3_GUCTL3                                  0xC60CU
/* GTXFIFOPRIDEV */
#define USB3_GTXFIFOPRIDEV                           0xC610U
/* GTXFIFOPRIHST */
#define USB3_GTXFIFOPRIHST                           0xC618U
/* GRXFIFOPRIHST */
#define USB3_GRXFIFOPRIHST                           0xC61CU
/* GFIFOPRIDBC */
#define USB3_GFIFOPRIDBC                             0xC620U
/* GDMAHLRATIO */
#define USB3_GDMAHLRATIO                             0xC624U
/* GOSTDDMA_ASYNC */
#define USB3_GOSTDDMA_ASYNC                          0xC628U
/* GOSTDDMA_PRD */
#define USB3_GOSTDDMA_PRD                            0xC62CU
/* GFLADJ */
#define USB3_GFLADJ                                  0xC630U
/* GUCTL4 */
#define USB3_GUCTL4                                  0xC634U
/* GUCTL5 */
#define USB3_GUCTL5                                  0xC638U
/* GUSB2RHBCTL */
#define USB3_GUSB2RHBCTL                             0x0000U
/* DCFG */
#define USB3_DCFG                                    0xC700U
/* DCTL */
#define USB3_DCTL                                    0xC704U
/* DEVTEN */
#define USB3_DEVTEN                                  0xC708U
/* DSTS */
#define USB3_DSTS                                    0xC70CU
/* DGCMDPAR */
#define USB3_DGCMDPAR                                0xC710U
/* DGCMD */
#define USB3_DGCMD                                   0xC714U
/* DCTL1 */
#define USB3_DCTL1                                   0xC718U
/* DALEPENA */
#define USB3_DALEPENA                                0xC720U
/* DLDMENA */
#define USB3_DLDMENA                                 0xC724U
/* Rsvd */
#define USB3_RSVD                                    0x0000U
/* DEPCMDPAR2 */
#define USB3_DEPCMDPAR2                              0x0000U
/* DEPCMDPAR1 */
#define USB3_DEPCMDPAR1                              0x0004U
/* DEPCMDPAR0 */
#define USB3_DEPCMDPAR0                              0x0008U
/* DEPCMD */
#define USB3_DEPCMD                                  0x000CU
/* DEV_IMOD */
#define USB3_DEV_IMOD                                0x0000U
/* rsvd0_reg */
#define USB3_RSVD0_REG                               0xCC00U
/* LU1LFPSRXTIM */
#define USB3_LU1LFPSRXTIM                            0x0000U
/* LU1LFPSTXTIM */
#define USB3_LU1LFPSTXTIM                            0x0004U
/* LU2LFPSRXTIM */
#define USB3_LU2LFPSRXTIM                            0x0008U
/* LU2LFPSTXTIM */
#define USB3_LU2LFPSTXTIM                            0x000CU
/* LU3LFPSRXTIM */
#define USB3_LU3LFPSRXTIM                            0x0010U
/* LU3LFPSTXTIM */
#define USB3_LU3LFPSTXTIM                            0x0014U
/* LPINGLFPSTIM */
#define USB3_LPINGLFPSTIM                            0x0018U
/* LPOLLLFPSTXTIM */
#define USB3_LPOLLLFPSTXTIM                          0x001CU
/* LSKIPFREQ */
#define USB3_LSKIPFREQ                               0x0020U
/* LLUCTL */
#define USB3_LLUCTL                                  0x0024U
/* LPTMDPDELAY */
#define USB3_LPTMDPDELAY                             0x0028U
/* LSCDTIM1 */
#define USB3_LSCDTIM1                                0x002CU
/* LSCDTIM2 */
#define USB3_LSCDTIM2                                0x0030U
/* LSCDTIM3 */
#define USB3_LSCDTIM3                                0x0034U
/* LSCDTIM4 */
#define USB3_LSCDTIM4                                0x0038U
/* LLPBMTIM1 */
#define USB3_LLPBMTIM1                               0x003CU
/* LLPBMTIM2 */
#define USB3_LLPBMTIM2                               0x0040U
/* LLPBMTXTIM */
#define USB3_LLPBMTXTIM                              0x0044U
/* LLINKERRINJ */
#define USB3_LLINKERRINJ                             0x0048U
/* LLINKERRINJEN */
#define USB3_LLINKERRINJEN                           0x004CU
/* GDBGLTSSM */
#define USB3_GDBGLTSSM                               0x0050U
/* GDBGLNMCC */
#define USB3_GDBGLNMCC                               0x0054U
/* LLINKDBGCTRL */
#define USB3_LLINKDBGCTRL                            0x0058U
/* LLINKDBGCNTTRIG */
#define USB3_LLINKDBGCNTTRIG                         0x005CU
/* LCSR_TX_DEEMPH */
#define USB3_LCSR_TX_DEEMPH                          0x0060U
/* LCSR_TX_DEEMPH_1 */
#define USB3_LCSR_TX_DEEMPH_1                        0x0064U
/* LCSR_TX_DEEMPH_2 */
#define USB3_LCSR_TX_DEEMPH_2                        0x0068U
/* LCSR_TX_DEEMPH_3 */
#define USB3_LCSR_TX_DEEMPH_3                        0x006CU
/* LCSRPTMDEBUG1 */
#define USB3_LCSRPTMDEBUG1                           0x0070U
/* LCSRPTMDEBUG2 */
#define USB3_LCSRPTMDEBUG2                           0x0074U
/* LPTMDPDELAY2 */
#define USB3_LPTMDPDELAY2                            0x0078U
/* BU31RHBDBG */
#define USB3_BU31RHBDBG                              0x0000U
/* BRAMHIADDR */
#define USB3_BRAMHIADDR                              0xD84CU
/* BRSERRCNT */
#define USB3_BRSERRCNT                               0xD850U
/* BRMERRCNT */
#define USB3_BRMERRCNT                               0xD854U
/* BRAMECCERR */
#define USB3_BRAMECCERR                              0xD858U
/* BRERRCTL */
#define USB3_BRERRCTL                                0xD85CU
/* BRAM0ADDRERR */
#define USB3_BRAM0ADDRERR                            0xD860U
/* BRAM1ADDRERR */
#define USB3_BRAM1ADDRERR                            0xD864U
/* BRAM2ADDRERR */
#define USB3_BRAM2ADDRERR                            0xD868U
/* BRAM3ADDRERR */
#define USB3_BRAM3ADDRERR                            0xD86CU
/* BRAM4ADDRERR */
#define USB3_BRAM4ADDRERR                            0xD870U
/* BLOOPBCKCTRL */
#define USB3_BLOOPBCKCTRL                            0xD900U
/* BLOOPBCKTFERSZ */
#define USB3_BLOOPBCKTFERSZ                          0xD904U
/* BBISTDATAPATSEED */
#define USB3_BBISTDATAPATSEED                        0xD908U
/* BBISTCTRL */
#define USB3_BBISTCTRL                               0xD90CU
/* BBISTXFERSTS0 */
#define USB3_BBISTXFERSTS0                           0xD910U
/* BBISTXFERSTS1 */
#define USB3_BBISTXFERSTS1                           0xD914U
/* BBISTXFERSTS2 */
#define USB3_BBISTXFERSTS2                           0xD918U
/* BBISTXFERSTS3 */
#define USB3_BBISTXFERSTS3                           0xD91CU
/* BBISTEXPDATASTS0 */
#define USB3_BBISTEXPDATASTS0                        0xD920U
/* BBISTEXPDATASTS1 */
#define USB3_BBISTEXPDATASTS1                        0xD924U
/* BBISTEXPDATASTS2 */
#define USB3_BBISTEXPDATASTS2                        0xD928U
/* BBISTEXPDATASTS3 */
#define USB3_BBISTEXPDATASTS3                        0xD92CU
/* BBISTRCVDDATASTS0 */
#define USB3_BBISTRCVDDATASTS0                       0xD930U
/* BBISTRCVDDATASTS1 */
#define USB3_BBISTRCVDDATASTS1                       0xD934U
/* BBISTRCVDDATASTS2 */
#define USB3_BBISTRCVDDATASTS2                       0xD938U
/* BBISTRCVDDATASTS3 */
#define USB3_BBISTRCVDDATASTS3                       0xD93CU
/* rsvd_reg */
#define USB3_RSVD_REG                                0xDA00U

/* Bit fields of CAPLENGTH register */
#define USB3_CAPLENGTH_HCIVERSION_MASK               0xFFFF0000U
#define USB3_CAPLENGTH_HCIVERSION_POS                16U
#define USB3_CAPLENGTH_CAPLENGTH_MASK                0x000000FFU
#define USB3_CAPLENGTH_CAPLENGTH_POS                 0U

/* Bit fields of HCSPARAMS1 register */
#define USB3_HCSPARAMS1_MAXPORTS_MASK                0xFF000000U
#define USB3_HCSPARAMS1_MAXPORTS_POS                 24U
#define USB3_HCSPARAMS1_MAXINTRS_MASK                0x0007FF00U
#define USB3_HCSPARAMS1_MAXINTRS_POS                 8U
#define USB3_HCSPARAMS1_MAXSLOTS_MASK                0x000000FFU
#define USB3_HCSPARAMS1_MAXSLOTS_POS                 0U

/* Bit fields of HCSPARAMS2 register */
#define USB3_HCSPARAMS2_MAXSCRATCHPADBUFS_MASK       0xF8000000U
#define USB3_HCSPARAMS2_MAXSCRATCHPADBUFS_POS        27U
#define USB3_HCSPARAMS2_SPR_MASK                     0x04000000U
#define USB3_HCSPARAMS2_SPR_POS                      26U
#define USB3_HCSPARAMS2_MAXSCRATCHPADBUFS_HI_MASK    0x03E00000U
#define USB3_HCSPARAMS2_MAXSCRATCHPADBUFS_HI_POS     21U
#define USB3_HCSPARAMS2_ERSTMAX_MASK                 0x000000F0U
#define USB3_HCSPARAMS2_ERSTMAX_POS                  4U
#define USB3_HCSPARAMS2_IST_MASK                     0x0000000FU
#define USB3_HCSPARAMS2_IST_POS                      0U

/* Bit fields of HCSPARAMS3 register */
#define USB3_HCSPARAMS3_U2_DEVICE_EXIT_LAT_MASK      0xFFFF0000U
#define USB3_HCSPARAMS3_U2_DEVICE_EXIT_LAT_POS       16U
#define USB3_HCSPARAMS3_U1_DEVICE_EXIT_LAT_MASK      0x000000FFU
#define USB3_HCSPARAMS3_U1_DEVICE_EXIT_LAT_POS       0U

/* Bit fields of HCCPARAMS1 register */
#define USB3_HCCPARAMS1_XECP_MASK                    0xFFFF0000U
#define USB3_HCCPARAMS1_XECP_POS                     16U
#define USB3_HCCPARAMS1_MAXPSASIZE_MASK              0x0000F000U
#define USB3_HCCPARAMS1_MAXPSASIZE_POS               12U
#define USB3_HCCPARAMS1_CFC_MASK                     0x00000800U
#define USB3_HCCPARAMS1_CFC_POS                      11U
#define USB3_HCCPARAMS1_SEC_MASK                     0x00000400U
#define USB3_HCCPARAMS1_SEC_POS                      10U
#define USB3_HCCPARAMS1_SPC_MASK                     0x00000200U
#define USB3_HCCPARAMS1_SPC_POS                      9U
#define USB3_HCCPARAMS1_PAE_MASK                     0x00000100U
#define USB3_HCCPARAMS1_PAE_POS                      8U
#define USB3_HCCPARAMS1_NSS_MASK                     0x00000080U
#define USB3_HCCPARAMS1_NSS_POS                      7U
#define USB3_HCCPARAMS1_LTC_MASK                     0x00000040U
#define USB3_HCCPARAMS1_LTC_POS                      6U
#define USB3_HCCPARAMS1_LHRC_MASK                    0x00000020U
#define USB3_HCCPARAMS1_LHRC_POS                     5U
#define USB3_HCCPARAMS1_PIND_MASK                    0x00000010U
#define USB3_HCCPARAMS1_PIND_POS                     4U
#define USB3_HCCPARAMS1_PPC_MASK                     0x00000008U
#define USB3_HCCPARAMS1_PPC_POS                      3U
#define USB3_HCCPARAMS1_CSZ_MASK                     0x00000004U
#define USB3_HCCPARAMS1_CSZ_POS                      2U
#define USB3_HCCPARAMS1_BNC_MASK                     0x00000002U
#define USB3_HCCPARAMS1_BNC_POS                      1U
#define USB3_HCCPARAMS1_AC64_MASK                    0x00000001U
#define USB3_HCCPARAMS1_AC64_POS                     0U

/* Bit fields of DBOFF register */
#define USB3_DBOFF_DOORBELL_ARRAY_OFFSET_MASK        0xFFFFFFFCU
#define USB3_DBOFF_DOORBELL_ARRAY_OFFSET_POS         2U

/* Bit fields of RTSOFF register */
#define USB3_RTSOFF_RUNTIME_REG_SPACE_OFFSET_MASK    0xFFFFFFE0U
#define USB3_RTSOFF_RUNTIME_REG_SPACE_OFFSET_POS     5U

/* Bit fields of HCCPARAMS2 register */
#define USB3_HCCPARAMS2_ETC_TSC_MASK                 0x00000080U
#define USB3_HCCPARAMS2_ETC_TSC_POS                  7U
#define USB3_HCCPARAMS2_ETC_MASK                     0x00000040U
#define USB3_HCCPARAMS2_ETC_POS                      6U
#define USB3_HCCPARAMS2_CIC_MASK                     0x00000020U
#define USB3_HCCPARAMS2_CIC_POS                      5U
#define USB3_HCCPARAMS2_LEC_MASK                     0x00000010U
#define USB3_HCCPARAMS2_LEC_POS                      4U
#define USB3_HCCPARAMS2_CTC_MASK                     0x00000008U
#define USB3_HCCPARAMS2_CTC_POS                      3U
#define USB3_HCCPARAMS2_FSC_MASK                     0x00000004U
#define USB3_HCCPARAMS2_FSC_POS                      2U
#define USB3_HCCPARAMS2_CMC_MASK                     0x00000002U
#define USB3_HCCPARAMS2_CMC_POS                      1U
#define USB3_HCCPARAMS2_U3C_MASK                     0x00000001U
#define USB3_HCCPARAMS2_U3C_POS                      0U

/* Bit fields of USBCMD register */
#define USB3_USBCMD_ETE_MASK                         0x00004000U
#define USB3_USBCMD_ETE_POS                          14U
#define USB3_USBCMD_CME_MASK                         0x00002000U
#define USB3_USBCMD_CME_POS                          13U
#define USB3_USBCMD_EU3S_MASK                        0x00000800U
#define USB3_USBCMD_EU3S_POS                         11U
#define USB3_USBCMD_EWE_MASK                         0x00000400U
#define USB3_USBCMD_EWE_POS                          10U
#define USB3_USBCMD_CRS_MASK                         0x00000200U
#define USB3_USBCMD_CRS_POS                          9U
#define USB3_USBCMD_CSS_MASK                         0x00000100U
#define USB3_USBCMD_CSS_POS                          8U
#define USB3_USBCMD_LHCRST_MASK                      0x00000080U
#define USB3_USBCMD_LHCRST_POS                       7U
#define USB3_USBCMD_HSEE_MASK                        0x00000008U
#define USB3_USBCMD_HSEE_POS                         3U
#define USB3_USBCMD_INTE_MASK                        0x00000004U
#define USB3_USBCMD_INTE_POS                         2U
#define USB3_USBCMD_HCRST_MASK                       0x00000002U
#define USB3_USBCMD_HCRST_POS                        1U
#define USB3_USBCMD_R_S_MASK                         0x00000001U
#define USB3_USBCMD_R_S_POS                          0U

/* Bit fields of USBSTS register */
#define USB3_USBSTS_HCE_MASK                         0x00001000U
#define USB3_USBSTS_HCE_POS                          12U
#define USB3_USBSTS_CNR_MASK                         0x00000800U
#define USB3_USBSTS_CNR_POS                          11U
#define USB3_USBSTS_SRE_MASK                         0x00000400U
#define USB3_USBSTS_SRE_POS                          10U
#define USB3_USBSTS_RSS_MASK                         0x00000200U
#define USB3_USBSTS_RSS_POS                          9U
#define USB3_USBSTS_SSS_MASK                         0x00000100U
#define USB3_USBSTS_SSS_POS                          8U
#define USB3_USBSTS_PCD_MASK                         0x00000010U
#define USB3_USBSTS_PCD_POS                          4U
#define USB3_USBSTS_EINT_MASK                        0x00000008U
#define USB3_USBSTS_EINT_POS                         3U
#define USB3_USBSTS_HSE_MASK                         0x00000004U
#define USB3_USBSTS_HSE_POS                          2U
#define USB3_USBSTS_HCH_MASK                         0x00000001U
#define USB3_USBSTS_HCH_POS                          0U

/* Bit fields of PAGESIZE register */
#define USB3_PAGESIZE_PAGE_SIZE_MASK                 0x0000FFFFU
#define USB3_PAGESIZE_PAGE_SIZE_POS                  0U

/* Bit fields of DNCTRL register */
#define USB3_DNCTRL_N0_N15_MASK                      0x0000FFFFU
#define USB3_DNCTRL_N0_N15_POS                       0U

/* Bit fields of CRCR_LO register */
#define USB3_CRCR_LO_CMD_RING_PNTR_MASK              0xFFFFFFC0U
#define USB3_CRCR_LO_CMD_RING_PNTR_POS               6U
#define USB3_CRCR_LO_CRR_MASK                        0x00000008U
#define USB3_CRCR_LO_CRR_POS                         3U
#define USB3_CRCR_LO_CA_MASK                         0x00000004U
#define USB3_CRCR_LO_CA_POS                          2U
#define USB3_CRCR_LO_CS_MASK                         0x00000002U
#define USB3_CRCR_LO_CS_POS                          1U
#define USB3_CRCR_LO_RCS_MASK                        0x00000001U
#define USB3_CRCR_LO_RCS_POS                         0U

/* Bit fields of CRCR_HI register */
#define USB3_CRCR_HI_CMD_RING_PNTR_MASK              0xFFFFFFFFU
#define USB3_CRCR_HI_CMD_RING_PNTR_POS               0U

/* Bit fields of DCBAAP_LO register */
#define USB3_DCBAAP_LO_DEVICE_CONTEXT_BAAP_MASK      0xFFFFFFC0U
#define USB3_DCBAAP_LO_DEVICE_CONTEXT_BAAP_POS       6U

/* Bit fields of DCBAAP_HI register */
#define USB3_DCBAAP_HI_DEVICE_CONTEXT_BAAP_MASK      0xFFFFFFFFU
#define USB3_DCBAAP_HI_DEVICE_CONTEXT_BAAP_POS       0U

/* Bit fields of CONFIG register */
#define USB3_CONFIG_CIE_MASK                         0x00000200U
#define USB3_CONFIG_CIE_POS                          9U
#define USB3_CONFIG_U3E_MASK                         0x00000100U
#define USB3_CONFIG_U3E_POS                          8U
#define USB3_CONFIG_MAXSLOTSEN_MASK                  0x000000FFU
#define USB3_CONFIG_MAXSLOTSEN_POS                   0U

/* Bit fields of PORTSC_20 register */
#define USB3_PORTSC_20_DR_MASK                       0x40000000U
#define USB3_PORTSC_20_DR_POS                        30U
#define USB3_PORTSC_20_WOE_MASK                      0x08000000U
#define USB3_PORTSC_20_WOE_POS                       27U
#define USB3_PORTSC_20_WDE_MASK                      0x04000000U
#define USB3_PORTSC_20_WDE_POS                       26U
#define USB3_PORTSC_20_WCE_MASK                      0x02000000U
#define USB3_PORTSC_20_WCE_POS                       25U
#define USB3_PORTSC_20_CAS_MASK                      0x01000000U
#define USB3_PORTSC_20_CAS_POS                       24U
#define USB3_PORTSC_20_PLC_MASK                      0x00400000U
#define USB3_PORTSC_20_PLC_POS                       22U
#define USB3_PORTSC_20_PRC_MASK                      0x00200000U
#define USB3_PORTSC_20_PRC_POS                       21U
#define USB3_PORTSC_20_OCC_MASK                      0x00100000U
#define USB3_PORTSC_20_OCC_POS                       20U
#define USB3_PORTSC_20_PEC_MASK                      0x00040000U
#define USB3_PORTSC_20_PEC_POS                       18U
#define USB3_PORTSC_20_CSC_MASK                      0x00020000U
#define USB3_PORTSC_20_CSC_POS                       17U
#define USB3_PORTSC_20_LWS_MASK                      0x00010000U
#define USB3_PORTSC_20_LWS_POS                       16U
#define USB3_PORTSC_20_PIC_MASK                      0x0000C000U
#define USB3_PORTSC_20_PIC_POS                       14U
#define USB3_PORTSC_20_PORTSPEED_MASK                0x00003C00U
#define USB3_PORTSC_20_PORTSPEED_POS                 10U
#define USB3_PORTSC_20_PP_MASK                       0x00000200U
#define USB3_PORTSC_20_PP_POS                        9U
#define USB3_PORTSC_20_PLS_MASK                      0x000001E0U
#define USB3_PORTSC_20_PLS_POS                       5U
#define USB3_PORTSC_20_PR_MASK                       0x00000010U
#define USB3_PORTSC_20_PR_POS                        4U
#define USB3_PORTSC_20_OCA_MASK                      0x00000008U
#define USB3_PORTSC_20_OCA_POS                       3U
#define USB3_PORTSC_20_PED_MASK                      0x00000002U
#define USB3_PORTSC_20_PED_POS                       1U
#define USB3_PORTSC_20_CCS_MASK                      0x00000001U
#define USB3_PORTSC_20_CCS_POS                       0U

/* Bit fields of PORTPMSC_20 register */
#define USB3_PORTPMSC_20_PRTTSTCTRL_MASK             0xF0000000U
#define USB3_PORTPMSC_20_PRTTSTCTRL_POS              28U
#define USB3_PORTPMSC_20_HLE_MASK                    0x00010000U
#define USB3_PORTPMSC_20_HLE_POS                     16U
#define USB3_PORTPMSC_20_L1DSLOT_MASK                0x0000FF00U
#define USB3_PORTPMSC_20_L1DSLOT_POS                 8U
#define USB3_PORTPMSC_20_BESL_MASK                   0x000000F0U
#define USB3_PORTPMSC_20_BESL_POS                    4U
#define USB3_PORTPMSC_20_RWE_MASK                    0x00000008U
#define USB3_PORTPMSC_20_RWE_POS                     3U
#define USB3_PORTPMSC_20_L1S_MASK                    0x00000007U
#define USB3_PORTPMSC_20_L1S_POS                     0U

/* Bit fields of PORTLI_20 register */

/* Bit fields of PORTHLPMC_20 register */
#define USB3_PORTHLPMC_20_BESLD_MASK            0x00003C00U
#define USB3_PORTHLPMC_20_BESLD_POS             10U
#define USB3_PORTHLPMC_20_L1_TIMEOUT_MASK       0x000003FCU
#define USB3_PORTHLPMC_20_L1_TIMEOUT_POS        2U
#define USB3_PORTHLPMC_20_HIRDM_MASK            0x00000003U
#define USB3_PORTHLPMC_20_HIRDM_POS             0U

/* Bit fields of PORTSC_30 register */
#define USB3_PORTSC_30_WPR_MASK                 0x80000000U
#define USB3_PORTSC_30_WPR_POS                  31U
#define USB3_PORTSC_30_DR_MASK                  0x40000000U
#define USB3_PORTSC_30_DR_POS                   30U
#define USB3_PORTSC_30_WOE_MASK                 0x08000000U
#define USB3_PORTSC_30_WOE_POS                  27U
#define USB3_PORTSC_30_WDE_MASK                 0x04000000U
#define USB3_PORTSC_30_WDE_POS                  26U
#define USB3_PORTSC_30_WCE_MASK                 0x02000000U
#define USB3_PORTSC_30_WCE_POS                  25U
#define USB3_PORTSC_30_CAS_MASK                 0x01000000U
#define USB3_PORTSC_30_CAS_POS                  24U
#define USB3_PORTSC_30_CEC_MASK                 0x00800000U
#define USB3_PORTSC_30_CEC_POS                  23U
#define USB3_PORTSC_30_PLC_MASK                 0x00400000U
#define USB3_PORTSC_30_PLC_POS                  22U
#define USB3_PORTSC_30_PRC_MASK                 0x00200000U
#define USB3_PORTSC_30_PRC_POS                  21U
#define USB3_PORTSC_30_OCC_MASK                 0x00100000U
#define USB3_PORTSC_30_OCC_POS                  20U
#define USB3_PORTSC_30_WRC_MASK                 0x00080000U
#define USB3_PORTSC_30_WRC_POS                  19U
#define USB3_PORTSC_30_PEC_MASK                 0x00040000U
#define USB3_PORTSC_30_PEC_POS                  18U
#define USB3_PORTSC_30_CSC_MASK                 0x00020000U
#define USB3_PORTSC_30_CSC_POS                  17U
#define USB3_PORTSC_30_LWS_MASK                 0x00010000U
#define USB3_PORTSC_30_LWS_POS                  16U
#define USB3_PORTSC_30_PIC_MASK                 0x0000C000U
#define USB3_PORTSC_30_PIC_POS                  14U
#define USB3_PORTSC_30_PORTSPEED_MASK           0x00003C00U
#define USB3_PORTSC_30_PORTSPEED_POS            10U
#define USB3_PORTSC_30_PP_MASK                  0x00000200U
#define USB3_PORTSC_30_PP_POS                   9U
#define USB3_PORTSC_30_PLS_MASK                 0x000001E0U
#define USB3_PORTSC_30_PLS_POS                  5U
#define USB3_PORTSC_30_PR_MASK                  0x00000010U
#define USB3_PORTSC_30_PR_POS                   4U
#define USB3_PORTSC_30_OCA_MASK                 0x00000008U
#define USB3_PORTSC_30_OCA_POS                  3U
#define USB3_PORTSC_30_PED_MASK                 0x00000002U
#define USB3_PORTSC_30_PED_POS                  1U
#define USB3_PORTSC_30_CCS_MASK                 0x00000001U
#define USB3_PORTSC_30_CCS_POS                  0U

/* Bit fields of PORTPMSC_30 register */
#define USB3_PORTPMSC_30_FLA_MASK               0x00010000U
#define USB3_PORTPMSC_30_FLA_POS                16U
#define USB3_PORTPMSC_30_U2_TIMEOUT_MASK        0x0000FF00U
#define USB3_PORTPMSC_30_U2_TIMEOUT_POS         8U
#define USB3_PORTPMSC_30_U1_TIMEOUT_MASK        0x000000FFU
#define USB3_PORTPMSC_30_U1_TIMEOUT_POS         0U

/* Bit fields of PORTLI_30 register */
#define USB3_PORTLI_30_TLC_MASK                 0x00F00000U
#define USB3_PORTLI_30_TLC_POS                  20U
#define USB3_PORTLI_30_RLC_MASK                 0x000F0000U
#define USB3_PORTLI_30_RLC_POS                  16U
#define USB3_PORTLI_30_LINK_ERROR_COUNT_MASK    0x0000FFFFU
#define USB3_PORTLI_30_LINK_ERROR_COUNT_POS     0U

/* Bit fields of PORTHLPMC_30 register */

/* Bit fields of USBLEGSUP register */
#define USB3_USBLEGSUP_HC_OS_OWNED_MASK                   0x01000000U
#define USB3_USBLEGSUP_HC_OS_OWNED_POS                    24U
#define USB3_USBLEGSUP_HC_BIOS_OWNED_MASK                 0x00010000U
#define USB3_USBLEGSUP_HC_BIOS_OWNED_POS                  16U
#define USB3_USBLEGSUP_NEXT_CAPABILITY_POINTER_MASK       0x0000FF00U
#define USB3_USBLEGSUP_NEXT_CAPABILITY_POINTER_POS        8U
#define USB3_USBLEGSUP_CAPABILITY_ID_MASK                 0x000000FFU
#define USB3_USBLEGSUP_CAPABILITY_ID_POS                  0U

/* Bit fields of USBLEGCTLSTS register */
#define USB3_USBLEGCTLSTS_SMI_ON_BAR_MASK                 0x80000000U
#define USB3_USBLEGCTLSTS_SMI_ON_BAR_POS                  31U
#define USB3_USBLEGCTLSTS_SMI_ON_PCI_MASK                 0x40000000U
#define USB3_USBLEGCTLSTS_SMI_ON_PCI_POS                  30U
#define USB3_USBLEGCTLSTS_SMI_ON_OS_MASK                  0x20000000U
#define USB3_USBLEGCTLSTS_SMI_ON_OS_POS                   29U
#define USB3_USBLEGCTLSTS_SMI_ON_HOST_MASK                0x00100000U
#define USB3_USBLEGCTLSTS_SMI_ON_HOST_POS                 20U
#define USB3_USBLEGCTLSTS_SMI_ON_EVENT_MASK               0x00010000U
#define USB3_USBLEGCTLSTS_SMI_ON_EVENT_POS                16U
#define USB3_USBLEGCTLSTS_SMI_ON_BAR_E_MASK               0x00008000U
#define USB3_USBLEGCTLSTS_SMI_ON_BAR_E_POS                15U
#define USB3_USBLEGCTLSTS_SMI_ON_PCI_E_MASK               0x00004000U
#define USB3_USBLEGCTLSTS_SMI_ON_PCI_E_POS                14U
#define USB3_USBLEGCTLSTS_SMI_ON_OS_E_MASK                0x00002000U
#define USB3_USBLEGCTLSTS_SMI_ON_OS_E_POS                 13U
#define USB3_USBLEGCTLSTS_SMI_ON_HOST_E_MASK              0x00000010U
#define USB3_USBLEGCTLSTS_SMI_ON_HOST_E_POS               4U
#define USB3_USBLEGCTLSTS_USB_SMI_ENABLE_MASK             0x00000001U
#define USB3_USBLEGCTLSTS_USB_SMI_ENABLE_POS              0U

/* Bit fields of SUPTPRT2_DW0 register */
#define USB3_SUPTPRT2_DW0_MAJOR_REVISION_MASK             0xFF000000U
#define USB3_SUPTPRT2_DW0_MAJOR_REVISION_POS              24U
#define USB3_SUPTPRT2_DW0_MINOR_REVISION_MASK             0x00FF0000U
#define USB3_SUPTPRT2_DW0_MINOR_REVISION_POS              16U
#define USB3_SUPTPRT2_DW0_NEXT_CAPABILITY_POINTER_MASK    0x0000FF00U
#define USB3_SUPTPRT2_DW0_NEXT_CAPABILITY_POINTER_POS     8U
#define USB3_SUPTPRT2_DW0_CAPABILITY_ID_MASK              0x000000FFU
#define USB3_SUPTPRT2_DW0_CAPABILITY_ID_POS               0U

/* Bit fields of SUPTPRT2_DW1 register */
#define USB3_SUPTPRT2_DW1_NAME_STRING_MASK                0xFFFFFFFFU
#define USB3_SUPTPRT2_DW1_NAME_STRING_POS                 0U

/* Bit fields of SUPTPRT2_DW2 register */
#define USB3_SUPTPRT2_DW2_PSIC_MASK                       0xF0000000U
#define USB3_SUPTPRT2_DW2_PSIC_POS                        28U
#define USB3_SUPTPRT2_DW2_MHD_MASK                        0x0E000000U
#define USB3_SUPTPRT2_DW2_MHD_POS                         25U
#define USB3_SUPTPRT2_DW2_BLC_MASK                        0x00100000U
#define USB3_SUPTPRT2_DW2_BLC_POS                         20U
#define USB3_SUPTPRT2_DW2_HLC_MASK                        0x00080000U
#define USB3_SUPTPRT2_DW2_HLC_POS                         19U
#define USB3_SUPTPRT2_DW2_IHI_MASK                        0x00040000U
#define USB3_SUPTPRT2_DW2_IHI_POS                         18U
#define USB3_SUPTPRT2_DW2_HSO_MASK                        0x00020000U
#define USB3_SUPTPRT2_DW2_HSO_POS                         17U
#define USB3_SUPTPRT2_DW2_L1C_MASK                        0x00010000U
#define USB3_SUPTPRT2_DW2_L1C_POS                         16U
#define USB3_SUPTPRT2_DW2_COMPATIBLE_PORT_COUNT_MASK      0x0000FF00U
#define USB3_SUPTPRT2_DW2_COMPATIBLE_PORT_COUNT_POS       8U
#define USB3_SUPTPRT2_DW2_COMPATIBLE_PORT_OFFSET_MASK     0x000000FFU
#define USB3_SUPTPRT2_DW2_COMPATIBLE_PORT_OFFSET_POS      0U

/* Bit fields of SUPTPRT2_DW3 register */
#define USB3_SUPTPRT2_DW3_PROTCL_SLT_TY_MASK              0x0000001FU
#define USB3_SUPTPRT2_DW3_PROTCL_SLT_TY_POS               0U

/* Bit fields of SUPTPRT3_DW0 register */
#define USB3_SUPTPRT3_DW0_MAJOR_REVISION_MASK             0xFF000000U
#define USB3_SUPTPRT3_DW0_MAJOR_REVISION_POS              24U
#define USB3_SUPTPRT3_DW0_MINOR_REVISION_MASK             0x00FF0000U
#define USB3_SUPTPRT3_DW0_MINOR_REVISION_POS              16U
#define USB3_SUPTPRT3_DW0_NEXT_CAPABILITY_POINTER_MASK    0x0000FF00U
#define USB3_SUPTPRT3_DW0_NEXT_CAPABILITY_POINTER_POS     8U
#define USB3_SUPTPRT3_DW0_CAPABILITY_ID_MASK              0x000000FFU
#define USB3_SUPTPRT3_DW0_CAPABILITY_ID_POS               0U

/* Bit fields of SUPTPRT3_DW1 register */
#define USB3_SUPTPRT3_DW1_NAME_STRING_MASK                0xFFFFFFFFU
#define USB3_SUPTPRT3_DW1_NAME_STRING_POS                 0U

/* Bit fields of SUPTPRT3_DW2 register */
#define USB3_SUPTPRT3_DW2_PSIC_MASK                       0xF0000000U
#define USB3_SUPTPRT3_DW2_PSIC_POS                        28U
#define USB3_SUPTPRT3_DW2_COMPATIBLE_PORT_COUNT_MASK      0x0000FF00U
#define USB3_SUPTPRT3_DW2_COMPATIBLE_PORT_COUNT_POS       8U
#define USB3_SUPTPRT3_DW2_COMPATIBLE_PORT_OFFSET_MASK     0x000000FFU
#define USB3_SUPTPRT3_DW2_COMPATIBLE_PORT_OFFSET_POS      0U

/* Bit fields of SUPTPRT3_DW3 register */
#define USB3_SUPTPRT3_DW3_PROTCL_SLT_TY_MASK              0x0000001FU
#define USB3_SUPTPRT3_DW3_PROTCL_SLT_TY_POS               0U

/* Bit fields of SUPTPRT3_DW4 register */
#define USB3_SUPTPRT3_DW4_PSIM_MASK                       0xFFFF0000U
#define USB3_SUPTPRT3_DW4_PSIM_POS                        16U
#define USB3_SUPTPRT3_DW4_LP_MASK                         0x0000C000U
#define USB3_SUPTPRT3_DW4_LP_POS                          14U
#define USB3_SUPTPRT3_DW4_PFD_MASK                        0x00000100U
#define USB3_SUPTPRT3_DW4_PFD_POS                         8U
#define USB3_SUPTPRT3_DW4_PLT_MASK                        0x000000C0U
#define USB3_SUPTPRT3_DW4_PLT_POS                         6U
#define USB3_SUPTPRT3_DW4_PSIE_MASK                       0x00000030U
#define USB3_SUPTPRT3_DW4_PSIE_POS                        4U
#define USB3_SUPTPRT3_DW4_PSIV_MASK                       0x0000000FU
#define USB3_SUPTPRT3_DW4_PSIV_POS                        0U

/* Bit fields of SUPTPRT3_DW5 register */
#define USB3_SUPTPRT3_DW5_PSIM_MASK                       0xFFFF0000U
#define USB3_SUPTPRT3_DW5_PSIM_POS                        16U
#define USB3_SUPTPRT3_DW5_LP_MASK                         0x0000C000U
#define USB3_SUPTPRT3_DW5_LP_POS                          14U
#define USB3_SUPTPRT3_DW5_PFD_MASK                        0x00000100U
#define USB3_SUPTPRT3_DW5_PFD_POS                         8U
#define USB3_SUPTPRT3_DW5_PLT_MASK                        0x000000C0U
#define USB3_SUPTPRT3_DW5_PLT_POS                         6U
#define USB3_SUPTPRT3_DW5_PSIE_MASK                       0x00000030U
#define USB3_SUPTPRT3_DW5_PSIE_POS                        4U
#define USB3_SUPTPRT3_DW5_PSIV_MASK                       0x0000000FU
#define USB3_SUPTPRT3_DW5_PSIV_POS                        0U

/* Bit fields of SUPTPRT3_DW6 register */

/* Bit fields of SUPTPRT3_DW7 register */

/* Bit fields of DCID register */
#define USB3_DCID_DCERSTMAX_MASK                  0x001F0000U
#define USB3_DCID_DCERSTMAX_POS                   16U
#define USB3_DCID_NEXT_CAPABILITY_POINTER_MASK    0x0000FF00U
#define USB3_DCID_NEXT_CAPABILITY_POINTER_POS     8U
#define USB3_DCID_CAPABILITY_ID_MASK              0x000000FFU
#define USB3_DCID_CAPABILITY_ID_POS               0U

/* Bit fields of DCDB register */
#define USB3_DCDB_DBTARGET_MASK                   0x0000FF00U
#define USB3_DCDB_DBTARGET_POS                    8U

/* Bit fields of DCERSTSZ register */
#define USB3_DCERSTSZ_ERS_TABLE_SIZE_MASK         0x0000FFFFU
#define USB3_DCERSTSZ_ERS_TABLE_SIZE_POS          0U

/* Bit fields of RSVD0 register */

/* Bit fields of DCERSTBA_LO register */
#define USB3_DCERSTBA_LO_ERS_TABLE_BAR_MASK      0xFFFFFFF0U
#define USB3_DCERSTBA_LO_ERS_TABLE_BAR_POS       4U

/* Bit fields of DCERSTBA_HI register */
#define USB3_DCERSTBA_HI_ERS_TABLE_BAR_MASK      0xFFFFFFFFU
#define USB3_DCERSTBA_HI_ERS_TABLE_BAR_POS       0U

/* Bit fields of DCERDP_LO register */
#define USB3_DCERDP_LO_DEQUEUE_POINTER_MASK      0xFFFFFFF0U
#define USB3_DCERDP_LO_DEQUEUE_POINTER_POS       4U
#define USB3_DCERDP_LO_DESI_MASK                 0x00000007U
#define USB3_DCERDP_LO_DESI_POS                  0U

/* Bit fields of DCERDP_HI register */
#define USB3_DCERDP_HI_DEQUEUE_POINTER_MASK      0xFFFFFFFFU
#define USB3_DCERDP_HI_DEQUEUE_POINTER_POS       0U

/* Bit fields of DCCTRL register */
#define USB3_DCCTRL_DCE_MASK                     0x80000000U
#define USB3_DCCTRL_DCE_POS                      31U
#define USB3_DCCTRL_DEVICE_ADDRESS_MASK          0x7F000000U
#define USB3_DCCTRL_DEVICE_ADDRESS_POS           24U
#define USB3_DCCTRL_DEBUG_MAX_BURST_SIZE_MASK    0x00FF0000U
#define USB3_DCCTRL_DEBUG_MAX_BURST_SIZE_POS     16U
#define USB3_DCCTRL_DRC_MASK                     0x00000010U
#define USB3_DCCTRL_DRC_POS                      4U
#define USB3_DCCTRL_HIT_MASK                     0x00000008U
#define USB3_DCCTRL_HIT_POS                      3U
#define USB3_DCCTRL_HOT_MASK                     0x00000004U
#define USB3_DCCTRL_HOT_POS                      2U
#define USB3_DCCTRL_LSE_MASK                     0x00000002U
#define USB3_DCCTRL_LSE_POS                      1U
#define USB3_DCCTRL_DCR_MASK                     0x00000001U
#define USB3_DCCTRL_DCR_POS                      0U

/* Bit fields of DCST register */
#define USB3_DCST_DEBUG_PORT_NUMBER_MASK         0xFF000000U
#define USB3_DCST_DEBUG_PORT_NUMBER_POS          24U
#define USB3_DCST_SBR_MASK                       0x00000002U
#define USB3_DCST_SBR_POS                        1U
#define USB3_DCST_ER_MASK                        0x00000001U
#define USB3_DCST_ER_POS                         0U

/* Bit fields of DCPORTSC register */
#define USB3_DCPORTSC_CEC_MASK                   0x00800000U
#define USB3_DCPORTSC_CEC_POS                    23U
#define USB3_DCPORTSC_PLC_MASK                   0x00400000U
#define USB3_DCPORTSC_PLC_POS                    22U
#define USB3_DCPORTSC_PRC_MASK                   0x00200000U
#define USB3_DCPORTSC_PRC_POS                    21U
#define USB3_DCPORTSC_CSC_MASK                   0x00020000U
#define USB3_DCPORTSC_CSC_POS                    17U
#define USB3_DCPORTSC_PORTSPEED_MASK             0x00003C00U
#define USB3_DCPORTSC_PORTSPEED_POS              10U
#define USB3_DCPORTSC_PLS_MASK                   0x000001E0U
#define USB3_DCPORTSC_PLS_POS                    5U
#define USB3_DCPORTSC_PR_MASK                    0x00000010U
#define USB3_DCPORTSC_PR_POS                     4U
#define USB3_DCPORTSC_PED_MASK                   0x00000002U
#define USB3_DCPORTSC_PED_POS                    1U
#define USB3_DCPORTSC_CCS_MASK                   0x00000001U
#define USB3_DCPORTSC_CCS_POS                    0U

/* Bit fields of RSVD1 register */

/* Bit fields of DCCP_LO register */
#define USB3_DCCP_LO_DCCPR_MASK               0xFFFFFFF0U
#define USB3_DCCP_LO_DCCPR_POS                4U

/* Bit fields of DCCP_HI register */
#define USB3_DCCP_HI_DCCPR_MASK               0xFFFFFFFFU
#define USB3_DCCP_HI_DCCPR_POS                0U

/* Bit fields of DCDDI1 register */
#define USB3_DCDDI1_VENDORID_MASK             0xFFFF0000U
#define USB3_DCDDI1_VENDORID_POS              16U
#define USB3_DCDDI1_DBCPROTOCOL_MASK          0x000000FFU
#define USB3_DCDDI1_DBCPROTOCOL_POS           0U

/* Bit fields of DCDDI2 register */
#define USB3_DCDDI2_DEVICEREV_MASK            0xFFFF0000U
#define USB3_DCDDI2_DEVICEREV_POS             16U
#define USB3_DCDDI2_PRODUCTID_MASK            0x0000FFFFU
#define USB3_DCDDI2_PRODUCTID_POS             0U

/* Bit fields of MFINDEX register */
#define USB3_MFINDEX_MICROFRAME_INDEX_MASK    0x00003FFFU
#define USB3_MFINDEX_MICROFRAME_INDEX_POS     0U

/* Bit fields of RsvdZ register */

/* Bit fields of IMAN register */
#define USB3_IMAN_IE_MASK                  0x00000002U
#define USB3_IMAN_IE_POS                   1U
#define USB3_IMAN_IP_MASK                  0x00000001U
#define USB3_IMAN_IP_POS                   0U

/* Bit fields of IMOD register */
#define USB3_IMOD_IMODC_MASK               0xFFFF0000U
#define USB3_IMOD_IMODC_POS                16U
#define USB3_IMOD_IMODI_MASK               0x0000FFFFU
#define USB3_IMOD_IMODI_POS                0U

/* Bit fields of ERSTSZ register */
#define USB3_ERSTSZ_ERS_TABLE_SIZE_MASK    0x0000FFFFU
#define USB3_ERSTSZ_ERS_TABLE_SIZE_POS     0U

/* Bit fields of RsvdP register */

/* Bit fields of ERSTBA_LO register */
#define USB3_ERSTBA_LO_ERS_TABLE_BAR_MASK                           0xFFFFFFC0U
#define USB3_ERSTBA_LO_ERS_TABLE_BAR_POS                            6U

/* Bit fields of ERSTBA_HI register */
#define USB3_ERSTBA_HI_ERS_TABLE_BAR_MASK                           0xFFFFFFFFU
#define USB3_ERSTBA_HI_ERS_TABLE_BAR_POS                            0U

/* Bit fields of ERDP_LO register */
#define USB3_ERDP_LO_ERD_PNTR_MASK                                  0xFFFFFFF0U
#define USB3_ERDP_LO_ERD_PNTR_POS                                   4U
#define USB3_ERDP_LO_EHB_MASK                                       0x00000008U
#define USB3_ERDP_LO_EHB_POS                                        3U
#define USB3_ERDP_LO_DESI_MASK                                      0x00000007U
#define USB3_ERDP_LO_DESI_POS                                       0U

/* Bit fields of ERDP_HI register */
#define USB3_ERDP_HI_ERD_PNTR_MASK                                  0xFFFFFFFFU
#define USB3_ERDP_HI_ERD_PNTR_POS                                   0U

/* Bit fields of DB register */
#define USB3_DB_DB_STREAM_ID_MASK                                   0xFFFF0000U
#define USB3_DB_DB_STREAM_ID_POS                                    16U
#define USB3_DB_DB_TARGET_MASK                                      0x000000FFU
#define USB3_DB_DB_TARGET_POS                                       0U

/* Bit fields of GSBUSCFG0 register */
#define USB3_GSBUSCFG0_DATRDREQINFO_MASK                            0xF0000000U
#define USB3_GSBUSCFG0_DATRDREQINFO_POS                             28U
#define USB3_GSBUSCFG0_DESRDREQINFO_MASK                            0x0F000000U
#define USB3_GSBUSCFG0_DESRDREQINFO_POS                             24U
#define USB3_GSBUSCFG0_DATWRREQINFO_MASK                            0x00F00000U
#define USB3_GSBUSCFG0_DATWRREQINFO_POS                             20U
#define USB3_GSBUSCFG0_DESWRREQINFO_MASK                            0x000F0000U
#define USB3_GSBUSCFG0_DESWRREQINFO_POS                             16U
#define USB3_GSBUSCFG0_DATBIGEND_MASK                               0x00000800U
#define USB3_GSBUSCFG0_DATBIGEND_POS                                11U
#define USB3_GSBUSCFG0_DESBIGEND_MASK                               0x00000400U
#define USB3_GSBUSCFG0_DESBIGEND_POS                                10U
#define USB3_GSBUSCFG0_INCR256BRSTENA_MASK                          0x00000080U
#define USB3_GSBUSCFG0_INCR256BRSTENA_POS                           7U
#define USB3_GSBUSCFG0_INCR128BRSTENA_MASK                          0x00000040U
#define USB3_GSBUSCFG0_INCR128BRSTENA_POS                           6U
#define USB3_GSBUSCFG0_INCR64BRSTENA_MASK                           0x00000020U
#define USB3_GSBUSCFG0_INCR64BRSTENA_POS                            5U
#define USB3_GSBUSCFG0_INCR32BRSTENA_MASK                           0x00000010U
#define USB3_GSBUSCFG0_INCR32BRSTENA_POS                            4U
#define USB3_GSBUSCFG0_INCR16BRSTENA_MASK                           0x00000008U
#define USB3_GSBUSCFG0_INCR16BRSTENA_POS                            3U
#define USB3_GSBUSCFG0_INCR8BRSTENA_MASK                            0x00000004U
#define USB3_GSBUSCFG0_INCR8BRSTENA_POS                             2U
#define USB3_GSBUSCFG0_INCR4BRSTENA_MASK                            0x00000002U
#define USB3_GSBUSCFG0_INCR4BRSTENA_POS                             1U
#define USB3_GSBUSCFG0_INCRBRSTENA_MASK                             0x00000001U
#define USB3_GSBUSCFG0_INCRBRSTENA_POS                              0U

/* Bit fields of GSBUSCFG1 register */
#define USB3_GSBUSCFG1_EXTDPIPETRANSLIMIT_MASK                      0x0001E000U
#define USB3_GSBUSCFG1_EXTDPIPETRANSLIMIT_POS                       13U
#define USB3_GSBUSCFG1_EN1KPAGE_MASK                                0x00001000U
#define USB3_GSBUSCFG1_EN1KPAGE_POS                                 12U
#define USB3_GSBUSCFG1_PIPETRANSLIMIT_MASK                          0x00000F00U
#define USB3_GSBUSCFG1_PIPETRANSLIMIT_POS                           8U

/* Bit fields of GTXTHRCFG register */
#define USB3_GTXTHRCFG_USBTXPKTCNTSEL_MASK                          0x04000000U
#define USB3_GTXTHRCFG_USBTXPKTCNTSEL_POS                           26U
#define USB3_GTXTHRCFG_USBTXPKTCNT_MASK                             0x03E00000U
#define USB3_GTXTHRCFG_USBTXPKTCNT_POS                              21U
#define USB3_GTXTHRCFG_USBMAXTXBURSTSIZE_MASK                       0x001F0000U
#define USB3_GTXTHRCFG_USBMAXTXBURSTSIZE_POS                        16U
#define USB3_GTXTHRCFG_USBTXTHRNUMPKTSEL_HS_PRD_MASK                0x00008000U
#define USB3_GTXTHRCFG_USBTXTHRNUMPKTSEL_HS_PRD_POS                 15U
#define USB3_GTXTHRCFG_USBTXTHRNUMPKT_HS_PRD_MASK                   0x00006000U
#define USB3_GTXTHRCFG_USBTXTHRNUMPKT_HS_PRD_POS                    13U
#define USB3_GTXTHRCFG_USBTXTHRNUMPKTSEL_PRD_MASK                   0x00000400U
#define USB3_GTXTHRCFG_USBTXTHRNUMPKTSEL_PRD_POS                    10U
#define USB3_GTXTHRCFG_USBTXTHRNUMPKT_PRD_MASK                      0x000003E0U
#define USB3_GTXTHRCFG_USBTXTHRNUMPKT_PRD_POS                       5U
#define USB3_GTXTHRCFG_USBMAXTXBURSTSIZE_PRD_MASK                   0x0000001FU
#define USB3_GTXTHRCFG_USBMAXTXBURSTSIZE_PRD_POS                    0U

/* Bit fields of GRXTHRCFG register */
#define USB3_GRXTHRCFG_USBRXPKTCNTSEL_MASK                          0x04000000U
#define USB3_GRXTHRCFG_USBRXPKTCNTSEL_POS                           26U
#define USB3_GRXTHRCFG_USBRXPKTCNT_MASK                             0x03E00000U
#define USB3_GRXTHRCFG_USBRXPKTCNT_POS                              21U
#define USB3_GRXTHRCFG_USBMAXRXBURSTSIZE_MASK                       0x001F0000U
#define USB3_GRXTHRCFG_USBMAXRXBURSTSIZE_POS                        16U
#define USB3_GRXTHRCFG_USBRXTHRNUMPKTSEL_HS_PRD_MASK                0x00008000U
#define USB3_GRXTHRCFG_USBRXTHRNUMPKTSEL_HS_PRD_POS                 15U
#define USB3_GRXTHRCFG_USBRXTHRNUMPKT_HS_PRD_MASK                   0x00006000U
#define USB3_GRXTHRCFG_USBRXTHRNUMPKT_HS_PRD_POS                    13U
#define USB3_GRXTHRCFG_USBRXTHRNUMPKTSEL_PRD_MASK                   0x00000400U
#define USB3_GRXTHRCFG_USBRXTHRNUMPKTSEL_PRD_POS                    10U
#define USB3_GRXTHRCFG_USBRXTHRNUMPKT_PRD_MASK                      0x000003E0U
#define USB3_GRXTHRCFG_USBRXTHRNUMPKT_PRD_POS                       5U
#define USB3_GRXTHRCFG_USBMAXRXBURSTSIZE_PRD_MASK                   0x0000001FU
#define USB3_GRXTHRCFG_USBMAXRXBURSTSIZE_PRD_POS                    0U

/* Bit fields of GCTL register */
#define USB3_GCTL_PWRDNSCALE_MASK                                   0xFFF80000U
#define USB3_GCTL_PWRDNSCALE_POS                                    19U
#define USB3_GCTL_MASTERFILTBYPASS_MASK                             0x00040000U
#define USB3_GCTL_MASTERFILTBYPASS_POS                              18U
#define USB3_GCTL_BYPSSETADDR_MASK                                  0x00020000U
#define USB3_GCTL_BYPSSETADDR_POS                                   17U
#define USB3_GCTL_U2RSTECN_MASK                                     0x00010000U
#define USB3_GCTL_U2RSTECN_POS                                      16U
#define USB3_GCTL_FRMSCLDWN_MASK                                    0x0000C000U
#define USB3_GCTL_FRMSCLDWN_POS                                     14U
#define USB3_GCTL_PRTCAPDIR_MASK                                    0x00003000U
#define USB3_GCTL_PRTCAPDIR_POS                                     12U
#define USB3_GCTL_CORESOFTRESET_MASK                                0x00000800U
#define USB3_GCTL_CORESOFTRESET_POS                                 11U
#define USB3_GCTL_U1U2TIMERSCALE_MASK                               0x00000200U
#define USB3_GCTL_U1U2TIMERSCALE_POS                                9U
#define USB3_GCTL_DEBUGATTACH_MASK                                  0x00000100U
#define USB3_GCTL_DEBUGATTACH_POS                                   8U
#define USB3_GCTL_RAMCLKSEL_MASK                                    0x000000C0U
#define USB3_GCTL_RAMCLKSEL_POS                                     6U
#define USB3_GCTL_SCALEDOWN_MASK                                    0x00000030U
#define USB3_GCTL_SCALEDOWN_POS                                     4U
#define USB3_GCTL_DISSCRAMBLE_MASK                                  0x00000008U
#define USB3_GCTL_DISSCRAMBLE_POS                                   3U
#define USB3_GCTL_U2EXIT_LFPS_MASK                                  0x00000004U
#define USB3_GCTL_U2EXIT_LFPS_POS                                   2U
#define USB3_GCTL_GBLHIBERNATIONEN_MASK                             0x00000002U
#define USB3_GCTL_GBLHIBERNATIONEN_POS                              1U
#define USB3_GCTL_DSBLCLKGTNG_MASK                                  0x00000001U
#define USB3_GCTL_DSBLCLKGTNG_POS                                   0U

/* Bit fields of GPMSTS register */
#define USB3_GPMSTS_PORTSEL_MASK                                    0xF0000000U
#define USB3_GPMSTS_PORTSEL_POS                                     28U
#define USB3_GPMSTS_U3WAKEUP_MASK                                   0x0001F000U
#define USB3_GPMSTS_U3WAKEUP_POS                                    12U
#define USB3_GPMSTS_U2WAKEUP_MASK                                   0x000003FFU
#define USB3_GPMSTS_U2WAKEUP_POS                                    0U

/* Bit fields of GSTS register */
#define USB3_GSTS_CBELT_MASK                                        0xFFF00000U
#define USB3_GSTS_CBELT_POS                                         20U
#define USB3_GSTS_HOST_IP_MASK                                      0x00000080U
#define USB3_GSTS_HOST_IP_POS                                       7U
#define USB3_GSTS_DEVICE_IP_MASK                                    0x00000040U
#define USB3_GSTS_DEVICE_IP_POS                                     6U
#define USB3_GSTS_CSRTIMEOUT_MASK                                   0x00000020U
#define USB3_GSTS_CSRTIMEOUT_POS                                    5U
#define USB3_GSTS_BUSERRADDRVLD_MASK                                0x00000010U
#define USB3_GSTS_BUSERRADDRVLD_POS                                 4U
#define USB3_GSTS_CURMOD_MASK                                       0x00000003U
#define USB3_GSTS_CURMOD_POS                                        0U

/* Bit fields of GUCTL1 register */
#define USB3_GUCTL1_DEV_DECOUPLE_L1L2_EVT_MASK                      0x80000000U
#define USB3_GUCTL1_DEV_DECOUPLE_L1L2_EVT_POS                       31U
#define USB3_GUCTL1_DS_RXDET_MAX_TOUT_CTRL_MASK                     0x40000000U
#define USB3_GUCTL1_DS_RXDET_MAX_TOUT_CTRL_POS                      30U
#define USB3_GUCTL1_FILTER_SE0_FSLS_EOP_MASK                        0x20000000U
#define USB3_GUCTL1_FILTER_SE0_FSLS_EOP_POS                         29U
#define USB3_GUCTL1_TX_IPGAP_LINECHECK_DIS_MASK                     0x10000000U
#define USB3_GUCTL1_TX_IPGAP_LINECHECK_DIS_POS                      28U
#define USB3_GUCTL1_DEV_TRB_OUT_SPR_IND_MASK                        0x08000000U
#define USB3_GUCTL1_DEV_TRB_OUT_SPR_IND_POS                         27U
#define USB3_GUCTL1_DEV_L1_EXIT_BY_HW_MASK                          0x01000000U
#define USB3_GUCTL1_DEV_L1_EXIT_BY_HW_POS                           24U
#define USB3_GUCTL1_IP_GAP_ADD_ON_MASK                              0x00E00000U
#define USB3_GUCTL1_IP_GAP_ADD_ON_POS                               21U
#define USB3_GUCTL1_HW_LPM_CAP_DISABLE_MASK                         0x00004000U
#define USB3_GUCTL1_HW_LPM_CAP_DISABLE_POS                          14U
#define USB3_GUCTL1_HW_LPM_HLE_DISABLE_MASK                         0x00002000U
#define USB3_GUCTL1_HW_LPM_HLE_DISABLE_POS                          13U
#define USB3_GUCTL1_DISUSB2REFCLKGTNG_MASK                          0x00001000U
#define USB3_GUCTL1_DISUSB2REFCLKGTNG_POS                           12U
#define USB3_GUCTL1_DISREFCLKGTNG_MASK                              0x00000800U
#define USB3_GUCTL1_DISREFCLKGTNG_POS                               11U
#define USB3_GUCTL1_RESUME_OPMODE_HS_HOST_MASK                      0x00000400U
#define USB3_GUCTL1_RESUME_OPMODE_HS_HOST_POS                       10U
#define USB3_GUCTL1_L1_SUSP_THRLD_EN_FOR_HOST_MASK                  0x00000100U
#define USB3_GUCTL1_L1_SUSP_THRLD_EN_FOR_HOST_POS                   8U
#define USB3_GUCTL1_L1_SUSP_THRLD_FOR_HOST_MASK                     0x000000F0U
#define USB3_GUCTL1_L1_SUSP_THRLD_FOR_HOST_POS                      4U
#define USB3_GUCTL1_HC_ERRATA_ENABLE_MASK                           0x00000008U
#define USB3_GUCTL1_HC_ERRATA_ENABLE_POS                            3U
#define USB3_GUCTL1_HC_PARCHK_DISABLE_MASK                          0x00000004U
#define USB3_GUCTL1_HC_PARCHK_DISABLE_POS                           2U
#define USB3_GUCTL1_LOA_FILTER_EN_MASK                              0x00000001U
#define USB3_GUCTL1_LOA_FILTER_EN_POS                               0U

/* Bit fields of USB31_IP_NAME register */
#define USB3_USB31_IP_NAME_SYNOPSYSIP_MASK                          0xFFFFFFFFU
#define USB3_USB31_IP_NAME_SYNOPSYSIP_POS                           0U

/* Bit fields of GGPIO register */
#define USB3_GGPIO_GPO_MASK                                         0xFFFF0000U
#define USB3_GGPIO_GPO_POS                                          16U
#define USB3_GGPIO_GPI_MASK                                         0x0000FFFFU
#define USB3_GGPIO_GPI_POS                                          0U

/* Bit fields of GUID register */
#define USB3_GUID_USERID_MASK                                       0xFFFFFFFFU
#define USB3_GUID_USERID_POS                                        0U

/* Bit fields of GUCTL register */
#define USB3_GUCTL_REFCLKPER_MASK                                   0xFFC00000U
#define USB3_GUCTL_REFCLKPER_POS                                    22U
#define USB3_GUCTL_NOEXTRDL_MASK                                    0x00200000U
#define USB3_GUCTL_NOEXTRDL_POS                                     21U
#define USB3_GUCTL_DMAIGNOREHCE_MASK                                0x00100000U
#define USB3_GUCTL_DMAIGNOREHCE_POS                                 20U
#define USB3_GUCTL_IGNOREHCETIMEOUT_MASK                            0x00080000U
#define USB3_GUCTL_IGNOREHCETIMEOUT_POS                             19U
#define USB3_GUCTL_EN_EXTD_TBC_CAP_MASK                             0x00040000U
#define USB3_GUCTL_EN_EXTD_TBC_CAP_POS                              18U
#define USB3_GUCTL_SPRSCTRLTRANSEN_MASK                             0x00020000U
#define USB3_GUCTL_SPRSCTRLTRANSEN_POS                              17U
#define USB3_GUCTL_RESBWHSEPS_MASK                                  0x00010000U
#define USB3_GUCTL_RESBWHSEPS_POS                                   16U
#define USB3_GUCTL_USBHSTINIMMRETRYEN_MASK                          0x00004000U
#define USB3_GUCTL_USBHSTINIMMRETRYEN_POS                           14U
#define USB3_GUCTL_EXTCAPSUPPTEN_MASK                               0x00001000U
#define USB3_GUCTL_EXTCAPSUPPTEN_POS                                12U
#define USB3_GUCTL_INSRTEXTRFSBODI_MASK                             0x00000800U
#define USB3_GUCTL_INSRTEXTRFSBODI_POS                              11U
#define USB3_GUCTL_DTOUT_MASK                                       0x000007FFU
#define USB3_GUCTL_DTOUT_POS                                        0U

/* Bit fields of GBUSERRADDRLO register */
#define USB3_GBUSERRADDRLO_BUSERRADDR_MASK                          0xFFFFFFFFU
#define USB3_GBUSERRADDRLO_BUSERRADDR_POS                           0U

/* Bit fields of GBUSERRADDRHI register */
#define USB3_GBUSERRADDRHI_BUSERRADDR_MASK                          0xFFFFFFFFU
#define USB3_GBUSERRADDRHI_BUSERRADDR_POS                           0U

/* Bit fields of GPRTBIMAPLO register */
#define USB3_GPRTBIMAPLO_BINUM8_MASK                                0xF0000000U
#define USB3_GPRTBIMAPLO_BINUM8_POS                                 28U
#define USB3_GPRTBIMAPLO_BINUM7_MASK                                0x0F000000U
#define USB3_GPRTBIMAPLO_BINUM7_POS                                 24U
#define USB3_GPRTBIMAPLO_BINUM6_MASK                                0x00F00000U
#define USB3_GPRTBIMAPLO_BINUM6_POS                                 20U
#define USB3_GPRTBIMAPLO_BINUM5_MASK                                0x000F0000U
#define USB3_GPRTBIMAPLO_BINUM5_POS                                 16U
#define USB3_GPRTBIMAPLO_BINUM4_MASK                                0x0000F000U
#define USB3_GPRTBIMAPLO_BINUM4_POS                                 12U
#define USB3_GPRTBIMAPLO_BINUM3_MASK                                0x00000F00U
#define USB3_GPRTBIMAPLO_BINUM3_POS                                 8U
#define USB3_GPRTBIMAPLO_BINUM2_MASK                                0x000000F0U
#define USB3_GPRTBIMAPLO_BINUM2_POS                                 4U
#define USB3_GPRTBIMAPLO_BINUM1_MASK                                0x0000000FU
#define USB3_GPRTBIMAPLO_BINUM1_POS                                 0U

/* Bit fields of GPRTBIMAPHI register */
#define USB3_GPRTBIMAPHI_BINUM15_MASK                               0x0F000000U
#define USB3_GPRTBIMAPHI_BINUM15_POS                                24U
#define USB3_GPRTBIMAPHI_BINUM14_MASK                               0x00F00000U
#define USB3_GPRTBIMAPHI_BINUM14_POS                                20U
#define USB3_GPRTBIMAPHI_BINUM13_MASK                               0x000F0000U
#define USB3_GPRTBIMAPHI_BINUM13_POS                                16U
#define USB3_GPRTBIMAPHI_BINUM12_MASK                               0x0000F000U
#define USB3_GPRTBIMAPHI_BINUM12_POS                                12U
#define USB3_GPRTBIMAPHI_BINUM11_MASK                               0x00000F00U
#define USB3_GPRTBIMAPHI_BINUM11_POS                                8U
#define USB3_GPRTBIMAPHI_BINUM10_MASK                               0x000000F0U
#define USB3_GPRTBIMAPHI_BINUM10_POS                                4U
#define USB3_GPRTBIMAPHI_BINUM9_MASK                                0x0000000FU
#define USB3_GPRTBIMAPHI_BINUM9_POS                                 0U

/* Bit fields of GHWPARAMS0 register */
#define USB3_GHWPARAMS0_GHWPARAMS0_31_24_MASK                       0xFF000000U
#define USB3_GHWPARAMS0_GHWPARAMS0_31_24_POS                        24U
#define USB3_GHWPARAMS0_GHWPARAMS0_23_16_MASK                       0x00FF0000U
#define USB3_GHWPARAMS0_GHWPARAMS0_23_16_POS                        16U
#define USB3_GHWPARAMS0_GHWPARAMS0_15_8_MASK                        0x0000FF00U
#define USB3_GHWPARAMS0_GHWPARAMS0_15_8_POS                         8U
#define USB3_GHWPARAMS0_GHWPARAMS0_7_6_MASK                         0x000000C0U
#define USB3_GHWPARAMS0_GHWPARAMS0_7_6_POS                          6U
#define USB3_GHWPARAMS0_GHWPARAMS0_5_3_MASK                         0x00000038U
#define USB3_GHWPARAMS0_GHWPARAMS0_5_3_POS                          3U
#define USB3_GHWPARAMS0_GHWPARAMS0_2_0_MASK                         0x00000007U
#define USB3_GHWPARAMS0_GHWPARAMS0_2_0_POS                          0U

/* Bit fields of GHWPARAMS1 register */
#define USB3_GHWPARAMS1_GHWPARAMS1_31_MASK                          0x80000000U
#define USB3_GHWPARAMS1_GHWPARAMS1_31_POS                           31U
#define USB3_GHWPARAMS1_GHWPARAMS1_30_MASK                          0x40000000U
#define USB3_GHWPARAMS1_GHWPARAMS1_30_POS                           30U
#define USB3_GHWPARAMS1_GHWPARAMS1_29_MASK                          0x20000000U
#define USB3_GHWPARAMS1_GHWPARAMS1_29_POS                           29U
#define USB3_GHWPARAMS1_GHWPARAMS1_28_MASK                          0x10000000U
#define USB3_GHWPARAMS1_GHWPARAMS1_28_POS                           28U
#define USB3_GHWPARAMS1_GHWPARAMS1_27_MASK                          0x08000000U
#define USB3_GHWPARAMS1_GHWPARAMS1_27_POS                           27U
#define USB3_GHWPARAMS1_GHWPARAMS1_26_MASK                          0x04000000U
#define USB3_GHWPARAMS1_GHWPARAMS1_26_POS                           26U
#define USB3_GHWPARAMS1_GHWPARAMS1_25_24_MASK                       0x03000000U
#define USB3_GHWPARAMS1_GHWPARAMS1_25_24_POS                        24U
#define USB3_GHWPARAMS1_GHWPARAMS1_23_MASK                          0x00800000U
#define USB3_GHWPARAMS1_GHWPARAMS1_23_POS                           23U
#define USB3_GHWPARAMS1_GHWPARAMS1_22_17_MASK                       0x007E0000U
#define USB3_GHWPARAMS1_GHWPARAMS1_22_17_POS                        17U
#define USB3_GHWPARAMS1_GHWPARAMS1_16_14_MASK                       0x0001C000U
#define USB3_GHWPARAMS1_GHWPARAMS1_16_14_POS                        14U
#define USB3_GHWPARAMS1_GHWPARAMS1_13_11_MASK                       0x00003800U
#define USB3_GHWPARAMS1_GHWPARAMS1_13_11_POS                        11U
#define USB3_GHWPARAMS1_GHWPARAMS1_10_8_MASK                        0x00000700U
#define USB3_GHWPARAMS1_GHWPARAMS1_10_8_POS                         8U
#define USB3_GHWPARAMS1_GHWPARAMS1_7_4_MASK                         0x000000F0U
#define USB3_GHWPARAMS1_GHWPARAMS1_7_4_POS                          4U
#define USB3_GHWPARAMS1_GHWPARAMS1_3_0_MASK                         0x0000000FU
#define USB3_GHWPARAMS1_GHWPARAMS1_3_0_POS                          0U

/* Bit fields of GHWPARAMS2 register */
#define USB3_GHWPARAMS2_GHWPARAMS2_31_0_MASK                        0xFFFFFFFFU
#define USB3_GHWPARAMS2_GHWPARAMS2_31_0_POS                         0U

/* Bit fields of GHWPARAMS3 register */
#define USB3_GHWPARAMS3_GHWPARAMS3_31_MASK                          0x80000000U
#define USB3_GHWPARAMS3_GHWPARAMS3_31_POS                           31U
#define USB3_GHWPARAMS3_GHWPARAMS3_30_23_MASK                       0x7F800000U
#define USB3_GHWPARAMS3_GHWPARAMS3_30_23_POS                        23U
#define USB3_GHWPARAMS3_GHWPARAMS3_22_18_MASK                       0x007C0000U
#define USB3_GHWPARAMS3_GHWPARAMS3_22_18_POS                        18U
#define USB3_GHWPARAMS3_GHWPARAMS3_17_12_MASK                       0x0003F000U
#define USB3_GHWPARAMS3_GHWPARAMS3_17_12_POS                        12U
#define USB3_GHWPARAMS3_GHWPARAMS3_11_MASK                          0x00000800U
#define USB3_GHWPARAMS3_GHWPARAMS3_11_POS                           11U
#define USB3_GHWPARAMS3_GHWPARAMS3_10_MASK                          0x00000400U
#define USB3_GHWPARAMS3_GHWPARAMS3_10_POS                           10U
#define USB3_GHWPARAMS3_GHWPARAMS3_9_8_MASK                         0x00000300U
#define USB3_GHWPARAMS3_GHWPARAMS3_9_8_POS                          8U
#define USB3_GHWPARAMS3_GHWPARAMS3_7_6_MASK                         0x000000C0U
#define USB3_GHWPARAMS3_GHWPARAMS3_7_6_POS                          6U
#define USB3_GHWPARAMS3_GHWPARAMS3_5_4_MASK                         0x00000030U
#define USB3_GHWPARAMS3_GHWPARAMS3_5_4_POS                          4U
#define USB3_GHWPARAMS3_GHWPARAMS3_3_2_MASK                         0x0000000CU
#define USB3_GHWPARAMS3_GHWPARAMS3_3_2_POS                          2U
#define USB3_GHWPARAMS3_GHWPARAMS3_1_0_MASK                         0x00000003U
#define USB3_GHWPARAMS3_GHWPARAMS3_1_0_POS                          0U

/* Bit fields of GHWPARAMS4 register */
#define USB3_GHWPARAMS4_GHWPARAMS4_31_28_MASK                       0xF0000000U
#define USB3_GHWPARAMS4_GHWPARAMS4_31_28_POS                        28U
#define USB3_GHWPARAMS4_GHWPARAMS4_27_23_MASK                       0x0F800000U
#define USB3_GHWPARAMS4_GHWPARAMS4_27_23_POS                        23U
#define USB3_GHWPARAMS4_GHWPARAMS4_22_MASK                          0x00400000U
#define USB3_GHWPARAMS4_GHWPARAMS4_22_POS                           22U
#define USB3_GHWPARAMS4_GHWPARAMS4_21_MASK                          0x00200000U
#define USB3_GHWPARAMS4_GHWPARAMS4_21_POS                           21U
#define USB3_GHWPARAMS4_GHWPARAMS4_20_17_MASK                       0x001E0000U
#define USB3_GHWPARAMS4_GHWPARAMS4_20_17_POS                        17U
#define USB3_GHWPARAMS4_GHWPARAMS4_16_13_MASK                       0x0001E000U
#define USB3_GHWPARAMS4_GHWPARAMS4_16_13_POS                        13U
#define USB3_GHWPARAMS4_GHWPARAMS4_12_6_MASK                        0x00001FC0U
#define USB3_GHWPARAMS4_GHWPARAMS4_12_6_POS                         6U
#define USB3_GHWPARAMS4_GHWPARAMS4_5_0_MASK                         0x0000003FU
#define USB3_GHWPARAMS4_GHWPARAMS4_5_0_POS                          0U

/* Bit fields of GHWPARAMS5 register */
#define USB3_GHWPARAMS5_GHWPARAMS5_31_29_MASK                       0xE0000000U
#define USB3_GHWPARAMS5_GHWPARAMS5_31_29_POS                        29U
#define USB3_GHWPARAMS5_GHWPARAMS5_28_23_MASK                       0x1F800000U
#define USB3_GHWPARAMS5_GHWPARAMS5_28_23_POS                        23U
#define USB3_GHWPARAMS5_GHWPARAMS5_22_17_MASK                       0x007E0000U
#define USB3_GHWPARAMS5_GHWPARAMS5_22_17_POS                        17U
#define USB3_GHWPARAMS5_GHWPARAMS5_16_11_MASK                       0x0001F800U
#define USB3_GHWPARAMS5_GHWPARAMS5_16_11_POS                        11U
#define USB3_GHWPARAMS5_GHWPARAMS5_10_5_MASK                        0x000007E0U
#define USB3_GHWPARAMS5_GHWPARAMS5_10_5_POS                         5U
#define USB3_GHWPARAMS5_GHWPARAMS5_4_0_MASK                         0x0000001FU
#define USB3_GHWPARAMS5_GHWPARAMS5_4_0_POS                          0U

/* Bit fields of GHWPARAMS6 register */
#define USB3_GHWPARAMS6_GHWPARAMS6_31_16_MASK                       0xFFFF0000U
#define USB3_GHWPARAMS6_GHWPARAMS6_31_16_POS                        16U
#define USB3_GHWPARAMS6_BUSFLTRSSUPPORT_MASK                        0x00008000U
#define USB3_GHWPARAMS6_BUSFLTRSSUPPORT_POS                         15U
#define USB3_GHWPARAMS6_GHWPARAMS6_14_10_MASK                       0x00007C00U
#define USB3_GHWPARAMS6_GHWPARAMS6_14_10_POS                        10U
#define USB3_GHWPARAMS6_GHWPARAMS6_9_8_MASK                         0x00000300U
#define USB3_GHWPARAMS6_GHWPARAMS6_9_8_POS                          8U
#define USB3_GHWPARAMS6_GHWPARAMS6_7_MASK                           0x00000080U
#define USB3_GHWPARAMS6_GHWPARAMS6_7_POS                            7U
#define USB3_GHWPARAMS6_GHWPARAMS6_6_MASK                           0x00000040U
#define USB3_GHWPARAMS6_GHWPARAMS6_6_POS                            6U
#define USB3_GHWPARAMS6_GHWPARAMS6_5_0_MASK                         0x0000003FU
#define USB3_GHWPARAMS6_GHWPARAMS6_5_0_POS                          0U

/* Bit fields of GHWPARAMS7 register */
#define USB3_GHWPARAMS7_GHWPARAMS7_31_16_MASK                       0xFFFF0000U
#define USB3_GHWPARAMS7_GHWPARAMS7_31_16_POS                        16U
#define USB3_GHWPARAMS7_GHWPARAMS7_15_0_MASK                        0x0000FFFFU
#define USB3_GHWPARAMS7_GHWPARAMS7_15_0_POS                         0U

/* Bit fields of GDBGFIFOSPACE register */
#define USB3_GDBGFIFOSPACE_SPACE_AVAILABLE_MASK                     0xFFFF0000U
#define USB3_GDBGFIFOSPACE_SPACE_AVAILABLE_POS                      16U
#define USB3_GDBGFIFOSPACE_FIFO_QUEUE_SELECT_MASK                   0x000001FFU
#define USB3_GDBGFIFOSPACE_FIFO_QUEUE_SELECT_POS                    0U

/* Bit fields of GBMUCTL register */
#define USB3_GBMUCTL_SEPARATE_PSQ_EN_MASK                           0x00000020U
#define USB3_GBMUCTL_SEPARATE_PSQ_EN_POS                            5U
#define USB3_GBMUCTL_AXI_STORDER_EN_MASK                            0x00000004U
#define USB3_GBMUCTL_AXI_STORDER_EN_POS                             2U
#define USB3_GBMUCTL_ACTIVE_ID_EN_MASK                              0x00000002U
#define USB3_GBMUCTL_ACTIVE_ID_EN_POS                               1U

/* Bit fields of GDBGBMU register */
#define USB3_GDBGBMU_BMU_BCU_MASK                                   0xFFFFFF00U
#define USB3_GDBGBMU_BMU_BCU_POS                                    8U
#define USB3_GDBGBMU_BMU_DCU_MASK                                   0x000000F0U
#define USB3_GDBGBMU_BMU_DCU_POS                                    4U
#define USB3_GDBGBMU_BMU_CCU_MASK                                   0x0000000FU
#define USB3_GDBGBMU_BMU_CCU_POS                                    0U

/* Bit fields of GDBGLSPMUX register */
#define USB3_GDBGLSPMUX_LOGIC_ANALYZER_TRACE_MASK                   0x00FF0000U
#define USB3_GDBGLSPMUX_LOGIC_ANALYZER_TRACE_POS                    16U
#define USB3_GDBGLSPMUX_LSPSELECT_MASK                              0x00007FFFU
#define USB3_GDBGLSPMUX_LSPSELECT_POS                               0U

/* Bit fields of GDBGLSP register */
#define USB3_GDBGLSP_LSPDEBUG_MASK                                  0xFFFFFFFFU
#define USB3_GDBGLSP_LSPDEBUG_POS                                   0U

/* Bit fields of GDBGEPINFO0 register */
#define USB3_GDBGEPINFO0_EPDEBUG_MASK                               0xFFFFFFFFU
#define USB3_GDBGEPINFO0_EPDEBUG_POS                                0U

/* Bit fields of GDBGEPINFO1 register */
#define USB3_GDBGEPINFO1_EPDEBUG_MASK                               0xFFFFFFFFU
#define USB3_GDBGEPINFO1_EPDEBUG_POS                                0U

/* Bit fields of GPRTBIMAP_HSLO register */
#define USB3_GPRTBIMAP_HSLO_BINUM8_MASK                             0xF0000000U
#define USB3_GPRTBIMAP_HSLO_BINUM8_POS                              28U
#define USB3_GPRTBIMAP_HSLO_BINUM7_MASK                             0x0F000000U
#define USB3_GPRTBIMAP_HSLO_BINUM7_POS                              24U
#define USB3_GPRTBIMAP_HSLO_BINUM6_MASK                             0x00F00000U
#define USB3_GPRTBIMAP_HSLO_BINUM6_POS                              20U
#define USB3_GPRTBIMAP_HSLO_BINUM5_MASK                             0x000F0000U
#define USB3_GPRTBIMAP_HSLO_BINUM5_POS                              16U
#define USB3_GPRTBIMAP_HSLO_BINUM4_MASK                             0x0000F000U
#define USB3_GPRTBIMAP_HSLO_BINUM4_POS                              12U
#define USB3_GPRTBIMAP_HSLO_BINUM3_MASK                             0x00000F00U
#define USB3_GPRTBIMAP_HSLO_BINUM3_POS                              8U
#define USB3_GPRTBIMAP_HSLO_BINUM2_MASK                             0x000000F0U
#define USB3_GPRTBIMAP_HSLO_BINUM2_POS                              4U
#define USB3_GPRTBIMAP_HSLO_BINUM1_MASK                             0x0000000FU
#define USB3_GPRTBIMAP_HSLO_BINUM1_POS                              0U

/* Bit fields of GPRTBIMAP_HSHI register */
#define USB3_GPRTBIMAP_HSHI_BINUM15_MASK                            0x0F000000U
#define USB3_GPRTBIMAP_HSHI_BINUM15_POS                             24U
#define USB3_GPRTBIMAP_HSHI_BINUM14_MASK                            0x00F00000U
#define USB3_GPRTBIMAP_HSHI_BINUM14_POS                             20U
#define USB3_GPRTBIMAP_HSHI_BINUM13_MASK                            0x000F0000U
#define USB3_GPRTBIMAP_HSHI_BINUM13_POS                             16U
#define USB3_GPRTBIMAP_HSHI_BINUM12_MASK                            0x0000F000U
#define USB3_GPRTBIMAP_HSHI_BINUM12_POS                             12U
#define USB3_GPRTBIMAP_HSHI_BINUM11_MASK                            0x00000F00U
#define USB3_GPRTBIMAP_HSHI_BINUM11_POS                             8U
#define USB3_GPRTBIMAP_HSHI_BINUM10_MASK                            0x000000F0U
#define USB3_GPRTBIMAP_HSHI_BINUM10_POS                             4U
#define USB3_GPRTBIMAP_HSHI_BINUM9_MASK                             0x0000000FU
#define USB3_GPRTBIMAP_HSHI_BINUM9_POS                              0U

/* Bit fields of GPRTBIMAP_FSLO register */
#define USB3_GPRTBIMAP_FSLO_BINUM8_MASK                             0xF0000000U
#define USB3_GPRTBIMAP_FSLO_BINUM8_POS                              28U
#define USB3_GPRTBIMAP_FSLO_BINUM7_MASK                             0x0F000000U
#define USB3_GPRTBIMAP_FSLO_BINUM7_POS                              24U
#define USB3_GPRTBIMAP_FSLO_BINUM6_MASK                             0x00F00000U
#define USB3_GPRTBIMAP_FSLO_BINUM6_POS                              20U
#define USB3_GPRTBIMAP_FSLO_BINUM5_MASK                             0x000F0000U
#define USB3_GPRTBIMAP_FSLO_BINUM5_POS                              16U
#define USB3_GPRTBIMAP_FSLO_BINUM4_MASK                             0x0000F000U
#define USB3_GPRTBIMAP_FSLO_BINUM4_POS                              12U
#define USB3_GPRTBIMAP_FSLO_BINUM3_MASK                             0x00000F00U
#define USB3_GPRTBIMAP_FSLO_BINUM3_POS                              8U
#define USB3_GPRTBIMAP_FSLO_BINUM2_MASK                             0x000000F0U
#define USB3_GPRTBIMAP_FSLO_BINUM2_POS                              4U
#define USB3_GPRTBIMAP_FSLO_BINUM1_MASK                             0x0000000FU
#define USB3_GPRTBIMAP_FSLO_BINUM1_POS                              0U

/* Bit fields of GPRTBIMAP_FSHI register */
#define USB3_GPRTBIMAP_FSHI_BINUM15_MASK                            0x0F000000U
#define USB3_GPRTBIMAP_FSHI_BINUM15_POS                             24U
#define USB3_GPRTBIMAP_FSHI_BINUM14_MASK                            0x00F00000U
#define USB3_GPRTBIMAP_FSHI_BINUM14_POS                             20U
#define USB3_GPRTBIMAP_FSHI_BINUM13_MASK                            0x000F0000U
#define USB3_GPRTBIMAP_FSHI_BINUM13_POS                             16U
#define USB3_GPRTBIMAP_FSHI_BINUM12_MASK                            0x0000F000U
#define USB3_GPRTBIMAP_FSHI_BINUM12_POS                             12U
#define USB3_GPRTBIMAP_FSHI_BINUM11_MASK                            0x00000F00U
#define USB3_GPRTBIMAP_FSHI_BINUM11_POS                             8U
#define USB3_GPRTBIMAP_FSHI_BINUM10_MASK                            0x000000F0U
#define USB3_GPRTBIMAP_FSHI_BINUM10_POS                             4U
#define USB3_GPRTBIMAP_FSHI_BINUM9_MASK                             0x0000000FU
#define USB3_GPRTBIMAP_FSHI_BINUM9_POS                              0U

/* Bit fields of GHMSOCBWOR register */
#define USB3_GHMSOCBWOR_OVRD_PORT_SOC_BW_MASK                       0x80000000U
#define USB3_GHMSOCBWOR_OVRD_PORT_SOC_BW_POS                        31U
#define USB3_GHMSOCBWOR_OVRD_COMMON_SOC_RD_WR_MASK                  0x40000000U
#define USB3_GHMSOCBWOR_OVRD_COMMON_SOC_RD_WR_POS                   30U
#define USB3_GHMSOCBWOR_OVRD_SOC_WR_UF_KB_BANDWIDTH_MASK            0x3FFF8000U
#define USB3_GHMSOCBWOR_OVRD_SOC_WR_UF_KB_BANDWIDTH_POS             15U
#define USB3_GHMSOCBWOR_OVRD_SOC_RD_UF_KB_BANDWIDTH_MASK            0x00007FFFU
#define USB3_GHMSOCBWOR_OVRD_SOC_RD_UF_KB_BANDWIDTH_POS             0U

/* Bit fields of USB31_VER_NUMBER register */
#define USB3_USB31_VER_NUMBER_VERSION_NUM_MASK                      0xFFFFFFFFU
#define USB3_USB31_VER_NUMBER_VERSION_NUM_POS                       0U

/* Bit fields of USB31_VER_TYPE register */
#define USB3_USB31_VER_TYPE_VERSIONTYPE_MASK                        0xFFFFFFFFU
#define USB3_USB31_VER_TYPE_VERSIONTYPE_POS                         0U

/* Bit fields of GSYSBLKWINCTRL register */
#define USB3_GSYSBLKWINCTRL_SYS_BLOCKING_OK_ALL_THE_TIME_MASK       0x80000000U
#define USB3_GSYSBLKWINCTRL_SYS_BLOCKING_OK_ALL_THE_TIME_POS        31U
#define USB3_GSYSBLKWINCTRL_DISABLE_NO_BLOCKING_WINDOW_MASK         0x40000000U
#define USB3_GSYSBLKWINCTRL_DISABLE_NO_BLOCKING_WINDOW_POS          30U
#define USB3_GSYSBLKWINCTRL_ERST_PREFETCHING_EN_MASK                0x20000000U
#define USB3_GSYSBLKWINCTRL_ERST_PREFETCHING_EN_POS                 29U
#define USB3_GSYSBLKWINCTRL_ERST_PREFETCHING_WATERMARK_MASK         0x1F000000U
#define USB3_GSYSBLKWINCTRL_ERST_PREFETCHING_WATERMARK_POS          24U
#define USB3_GSYSBLKWINCTRL_END_NO_BLOCKING_TIME_MASK               0x0000FF00U
#define USB3_GSYSBLKWINCTRL_END_NO_BLOCKING_TIME_POS                8U
#define USB3_GSYSBLKWINCTRL_BEGININING_NO_BLOCKING_TIME_MASK        0x000000FFU
#define USB3_GSYSBLKWINCTRL_BEGININING_NO_BLOCKING_TIME_POS         0U

/* Bit fields of GPCIEL1EXTLAT register */
#define USB3_GPCIEL1EXTLAT_PCIE_L1_EXIT_MODE_CTRL_MASK              0xC0000000U
#define USB3_GPCIEL1EXTLAT_PCIE_L1_EXIT_MODE_CTRL_POS               30U
#define USB3_GPCIEL1EXTLAT_PCIE_L1_EXIT_LATENCY_MASK                0x00000FFFU
#define USB3_GPCIEL1EXTLAT_PCIE_L1_EXIT_LATENCY_POS                 0U

/* Bit fields of GUSB2PHYCFG register */
#define USB3_GUSB2PHYCFG_PHYSOFTRST_MASK                            0x80000000U
#define USB3_GUSB2PHYCFG_PHYSOFTRST_POS                             31U
#define USB3_GUSB2PHYCFG_ULPI_LPM_WITH_OPMODE_CHK_MASK              0x20000000U
#define USB3_GUSB2PHYCFG_ULPI_LPM_WITH_OPMODE_CHK_POS               29U
#define USB3_GUSB2PHYCFG_HSIC_CON_WIDTH_ADJ_MASK                    0x18000000U
#define USB3_GUSB2PHYCFG_HSIC_CON_WIDTH_ADJ_POS                     27U
#define USB3_GUSB2PHYCFG_INV_SEL_HSIC_MASK                          0x04000000U
#define USB3_GUSB2PHYCFG_INV_SEL_HSIC_POS                           26U
#define USB3_GUSB2PHYCFG_OVRD_FSLS_DISC_TIME_MASK                   0x02000000U
#define USB3_GUSB2PHYCFG_OVRD_FSLS_DISC_TIME_POS                    25U
#define USB3_GUSB2PHYCFG_LSTRD_MASK                                 0x01C00000U
#define USB3_GUSB2PHYCFG_LSTRD_POS                                  22U
#define USB3_GUSB2PHYCFG_LSIPD_MASK                                 0x00380000U
#define USB3_GUSB2PHYCFG_LSIPD_POS                                  19U
#define USB3_GUSB2PHYCFG_ULPIEXTVBUSINDIACTOR_MASK                  0x00040000U
#define USB3_GUSB2PHYCFG_ULPIEXTVBUSINDIACTOR_POS                   18U
#define USB3_GUSB2PHYCFG_ULPIEXTVBUSDRV_MASK                        0x00020000U
#define USB3_GUSB2PHYCFG_ULPIEXTVBUSDRV_POS                         17U
#define USB3_GUSB2PHYCFG_ULPIAUTORES_MASK                           0x00008000U
#define USB3_GUSB2PHYCFG_ULPIAUTORES_POS                            15U
#define USB3_GUSB2PHYCFG_EUSB2OPMODE_MASK                           0x00004000U
#define USB3_GUSB2PHYCFG_EUSB2OPMODE_POS                            14U
#define USB3_GUSB2PHYCFG_USBTRDTIM_MASK                             0x00003C00U
#define USB3_GUSB2PHYCFG_USBTRDTIM_POS                              10U
#define USB3_GUSB2PHYCFG_XCVRDLY_MASK                               0x00000200U
#define USB3_GUSB2PHYCFG_XCVRDLY_POS                                9U
#define USB3_GUSB2PHYCFG_ENBLSLPM_MASK                              0x00000100U
#define USB3_GUSB2PHYCFG_ENBLSLPM_POS                               8U
#define USB3_GUSB2PHYCFG_PHYSEL_MASK                                0x00000080U
#define USB3_GUSB2PHYCFG_PHYSEL_POS                                 7U
#define USB3_GUSB2PHYCFG_SUSPENDUSB20_MASK                          0x00000040U
#define USB3_GUSB2PHYCFG_SUSPENDUSB20_POS                           6U
#define USB3_GUSB2PHYCFG_FSINTF_MASK                                0x00000020U
#define USB3_GUSB2PHYCFG_FSINTF_POS                                 5U
#define USB3_GUSB2PHYCFG_ULPI_UTMI_SEL_MASK                         0x00000010U
#define USB3_GUSB2PHYCFG_ULPI_UTMI_SEL_POS                          4U
#define USB3_GUSB2PHYCFG_PHYIF_MASK                                 0x00000008U
#define USB3_GUSB2PHYCFG_PHYIF_POS                                  3U
#define USB3_GUSB2PHYCFG_TOUTCAL_MASK                               0x00000007U
#define USB3_GUSB2PHYCFG_TOUTCAL_POS                                0U

/* Bit fields of GUSB2PHYACC_ULPI register */
#define USB3_GUSB2PHYACC_ULPI_DISUIPIDRVR_MASK                      0x04000000U
#define USB3_GUSB2PHYACC_ULPI_DISUIPIDRVR_POS                       26U
#define USB3_GUSB2PHYACC_ULPI_NEWREGREQ_MASK                        0x02000000U
#define USB3_GUSB2PHYACC_ULPI_NEWREGREQ_POS                         25U
#define USB3_GUSB2PHYACC_ULPI_VSTSDONE_MASK                         0x01000000U
#define USB3_GUSB2PHYACC_ULPI_VSTSDONE_POS                          24U
#define USB3_GUSB2PHYACC_ULPI_VSTSBSY_MASK                          0x00800000U
#define USB3_GUSB2PHYACC_ULPI_VSTSBSY_POS                           23U
#define USB3_GUSB2PHYACC_ULPI_REGWR_MASK                            0x00400000U
#define USB3_GUSB2PHYACC_ULPI_REGWR_POS                             22U
#define USB3_GUSB2PHYACC_ULPI_REGADDR_MASK                          0x003F0000U
#define USB3_GUSB2PHYACC_ULPI_REGADDR_POS                           16U
#define USB3_GUSB2PHYACC_ULPI_EXTREGADDR_MASK                       0x0000FF00U
#define USB3_GUSB2PHYACC_ULPI_EXTREGADDR_POS                        8U
#define USB3_GUSB2PHYACC_ULPI_REGDATA_MASK                          0x000000FFU
#define USB3_GUSB2PHYACC_ULPI_REGDATA_POS                           0U

/* Bit fields of GUSB3PIPECTL register */
#define USB3_GUSB3PIPECTL_PHYSOFTRST_MASK                           0x80000000U
#define USB3_GUSB3PIPECTL_PHYSOFTRST_POS                            31U
#define USB3_GUSB3PIPECTL_HSTPRTCMPL_MASK                           0x40000000U
#define USB3_GUSB3PIPECTL_HSTPRTCMPL_POS                            30U
#define USB3_GUSB3PIPECTL_U2P3OK_MASK                               0x20000000U
#define USB3_GUSB3PIPECTL_U2P3OK_POS                                29U
#define USB3_GUSB3PIPECTL_DISRXDETP3_MASK                           0x10000000U
#define USB3_GUSB3PIPECTL_DISRXDETP3_POS                            28U
#define USB3_GUSB3PIPECTL_UX_EXIT_IN_PX_MASK                        0x08000000U
#define USB3_GUSB3PIPECTL_UX_EXIT_IN_PX_POS                         27U
#define USB3_GUSB3PIPECTL_PING_ENHANCEMENT_EN_MASK                  0x04000000U
#define USB3_GUSB3PIPECTL_PING_ENHANCEMENT_EN_POS                   26U
#define USB3_GUSB3PIPECTL_U1U2EXITFAIL_TO_RECOV_MASK                0x02000000U
#define USB3_GUSB3PIPECTL_U1U2EXITFAIL_TO_RECOV_POS                 25U
#define USB3_GUSB3PIPECTL_REQUEST_P1P2P3_MASK                       0x01000000U
#define USB3_GUSB3PIPECTL_REQUEST_P1P2P3_POS                        24U
#define USB3_GUSB3PIPECTL_STARTRXDETU3RXDET_MASK                    0x00800000U
#define USB3_GUSB3PIPECTL_STARTRXDETU3RXDET_POS                     23U
#define USB3_GUSB3PIPECTL_DISRXDETU3RXDET_MASK                      0x00400000U
#define USB3_GUSB3PIPECTL_DISRXDETU3RXDET_POS                       22U
#define USB3_GUSB3PIPECTL_DELAYP1P2P3_MASK                          0x00380000U
#define USB3_GUSB3PIPECTL_DELAYP1P2P3_POS                           19U
#define USB3_GUSB3PIPECTL_DELAYP1TRANS_MASK                         0x00040000U
#define USB3_GUSB3PIPECTL_DELAYP1TRANS_POS                          18U
#define USB3_GUSB3PIPECTL_SUSPENDENABLE_MASK                        0x00020000U
#define USB3_GUSB3PIPECTL_SUSPENDENABLE_POS                         17U
#define USB3_GUSB3PIPECTL_DATWIDTH_MASK                             0x00018000U
#define USB3_GUSB3PIPECTL_DATWIDTH_POS                              15U
#define USB3_GUSB3PIPECTL_ABORTRXDETINU2_MASK                       0x00004000U
#define USB3_GUSB3PIPECTL_ABORTRXDETINU2_POS                        14U
#define USB3_GUSB3PIPECTL_SKIPRXDET_MASK                            0x00002000U
#define USB3_GUSB3PIPECTL_SKIPRXDET_POS                             13U
#define USB3_GUSB3PIPECTL_LFPSP0ALGN_MASK                           0x00001000U
#define USB3_GUSB3PIPECTL_LFPSP0ALGN_POS                            12U
#define USB3_GUSB3PIPECTL_P3P2TRANOK_MASK                           0x00000800U
#define USB3_GUSB3PIPECTL_P3P2TRANOK_POS                            11U
#define USB3_GUSB3PIPECTL_P3EXSIGP2_MASK                            0x00000400U
#define USB3_GUSB3PIPECTL_P3EXSIGP2_POS                             10U
#define USB3_GUSB3PIPECTL_LFPSFILTER_MASK                           0x00000200U
#define USB3_GUSB3PIPECTL_LFPSFILTER_POS                            9U
#define USB3_GUSB3PIPECTL_RX_DETECT_TO_POLLING_LFPS_CONTROL_MASK    0x00000100U
#define USB3_GUSB3PIPECTL_RX_DETECT_TO_POLLING_LFPS_CONTROL_POS     8U
#define USB3_GUSB3PIPECTL_TX_SWING_MASK                             0x00000040U
#define USB3_GUSB3PIPECTL_TX_SWING_POS                              6U
#define USB3_GUSB3PIPECTL_TX_MARGIN_MASK                            0x00000038U
#define USB3_GUSB3PIPECTL_TX_MARGIN_POS                             3U
#define USB3_GUSB3PIPECTL_SS_TX_DE_EMPHASIS_MASK                    0x00000006U
#define USB3_GUSB3PIPECTL_SS_TX_DE_EMPHASIS_POS                     1U
#define USB3_GUSB3PIPECTL_ELASTIC_BUFFER_MODE_MASK                  0x00000001U
#define USB3_GUSB3PIPECTL_ELASTIC_BUFFER_MODE_POS                   0U

/* Bit fields of GTXFIFOSIZ0 register */
#define USB3_GTXFIFOSIZ0_TXFSTADDR_N_MASK                           0xFFFF0000U
#define USB3_GTXFIFOSIZ0_TXFSTADDR_N_POS                            16U
#define USB3_GTXFIFOSIZ0_TXFDEP_N_MASK                              0x00007FFFU
#define USB3_GTXFIFOSIZ0_TXFDEP_N_POS                               0U

/* Bit fields of GTXFIFOSIZ1 register */
#define USB3_GTXFIFOSIZ1_TXFSTADDR_N_MASK                           0xFFFF0000U
#define USB3_GTXFIFOSIZ1_TXFSTADDR_N_POS                            16U
#define USB3_GTXFIFOSIZ1_TXFDEP_N_MASK                              0x00007FFFU
#define USB3_GTXFIFOSIZ1_TXFDEP_N_POS                               0U

/* Bit fields of GTXFIFOSIZ2 register */
#define USB3_GTXFIFOSIZ2_TXFSTADDR_N_MASK                           0xFFFF0000U
#define USB3_GTXFIFOSIZ2_TXFSTADDR_N_POS                            16U
#define USB3_GTXFIFOSIZ2_TXFDEP_N_MASK                              0x00007FFFU
#define USB3_GTXFIFOSIZ2_TXFDEP_N_POS                               0U

/* Bit fields of GTXFIFOSIZ3 register */
#define USB3_GTXFIFOSIZ3_TXFSTADDR_N_MASK                           0xFFFF0000U
#define USB3_GTXFIFOSIZ3_TXFSTADDR_N_POS                            16U
#define USB3_GTXFIFOSIZ3_TXFDEP_N_MASK                              0x00007FFFU
#define USB3_GTXFIFOSIZ3_TXFDEP_N_POS                               0U

/* Bit fields of GTXFIFOSIZ4 register */
#define USB3_GTXFIFOSIZ4_TXFSTADDR_N_MASK                           0xFFFF0000U
#define USB3_GTXFIFOSIZ4_TXFSTADDR_N_POS                            16U
#define USB3_GTXFIFOSIZ4_TXFDEP_N_MASK                              0x00007FFFU
#define USB3_GTXFIFOSIZ4_TXFDEP_N_POS                               0U

/* Bit fields of GTXFIFOSIZ5 register */
#define USB3_GTXFIFOSIZ5_TXFSTADDR_N_MASK                           0xFFFF0000U
#define USB3_GTXFIFOSIZ5_TXFSTADDR_N_POS                            16U
#define USB3_GTXFIFOSIZ5_TXFDEP_N_MASK                              0x00007FFFU
#define USB3_GTXFIFOSIZ5_TXFDEP_N_POS                               0U

/* Bit fields of GTXFIFOSIZ6 register */
#define USB3_GTXFIFOSIZ6_TXFSTADDR_N_MASK                           0xFFFF0000U
#define USB3_GTXFIFOSIZ6_TXFSTADDR_N_POS                            16U
#define USB3_GTXFIFOSIZ6_TXFDEP_N_MASK                              0x00007FFFU
#define USB3_GTXFIFOSIZ6_TXFDEP_N_POS                               0U

/* Bit fields of GTXFIFOSIZ7 register */
#define USB3_GTXFIFOSIZ7_TXFSTADDR_N_MASK                           0xFFFF0000U
#define USB3_GTXFIFOSIZ7_TXFSTADDR_N_POS                            16U
#define USB3_GTXFIFOSIZ7_TXFDEP_N_MASK                              0x00007FFFU
#define USB3_GTXFIFOSIZ7_TXFDEP_N_POS                               0U

/* Bit fields of GTXFIFOSIZ8 register */
#define USB3_GTXFIFOSIZ8_TXFSTADDR_N_MASK                           0xFFFF0000U
#define USB3_GTXFIFOSIZ8_TXFSTADDR_N_POS                            16U
#define USB3_GTXFIFOSIZ8_TXFDEP_N_MASK                              0x00007FFFU
#define USB3_GTXFIFOSIZ8_TXFDEP_N_POS                               0U

/* Bit fields of GTXFIFOSIZ9 register */
#define USB3_GTXFIFOSIZ9_TXFSTADDR_N_MASK                           0xFFFF0000U
#define USB3_GTXFIFOSIZ9_TXFSTADDR_N_POS                            16U
#define USB3_GTXFIFOSIZ9_TXFDEP_N_MASK                              0x00007FFFU
#define USB3_GTXFIFOSIZ9_TXFDEP_N_POS                               0U

/* Bit fields of GTXFIFOSIZ10 register */
#define USB3_GTXFIFOSIZ10_TXFSTADDR_N_MASK                          0xFFFF0000U
#define USB3_GTXFIFOSIZ10_TXFSTADDR_N_POS                           16U
#define USB3_GTXFIFOSIZ10_TXFDEP_N_MASK                             0x00007FFFU
#define USB3_GTXFIFOSIZ10_TXFDEP_N_POS                              0U

/* Bit fields of GTXFIFOSIZ11 register */
#define USB3_GTXFIFOSIZ11_TXFSTADDR_N_MASK                          0xFFFF0000U
#define USB3_GTXFIFOSIZ11_TXFSTADDR_N_POS                           16U
#define USB3_GTXFIFOSIZ11_TXFDEP_N_MASK                             0x00007FFFU
#define USB3_GTXFIFOSIZ11_TXFDEP_N_POS                              0U

/* Bit fields of GTXFIFOSIZ12 register */
#define USB3_GTXFIFOSIZ12_TXFSTADDR_N_MASK                          0xFFFF0000U
#define USB3_GTXFIFOSIZ12_TXFSTADDR_N_POS                           16U
#define USB3_GTXFIFOSIZ12_TXFDEP_N_MASK                             0x00007FFFU
#define USB3_GTXFIFOSIZ12_TXFDEP_N_POS                              0U

/* Bit fields of GTXFIFOSIZ13 register */
#define USB3_GTXFIFOSIZ13_TXFSTADDR_N_MASK                          0xFFFF0000U
#define USB3_GTXFIFOSIZ13_TXFSTADDR_N_POS                           16U
#define USB3_GTXFIFOSIZ13_TXFDEP_N_MASK                             0x00007FFFU
#define USB3_GTXFIFOSIZ13_TXFDEP_N_POS                              0U

/* Bit fields of GTXFIFOSIZ14 register */
#define USB3_GTXFIFOSIZ14_TXFSTADDR_N_MASK                          0xFFFF0000U
#define USB3_GTXFIFOSIZ14_TXFSTADDR_N_POS                           16U
#define USB3_GTXFIFOSIZ14_TXFDEP_N_MASK                             0x00007FFFU
#define USB3_GTXFIFOSIZ14_TXFDEP_N_POS                              0U

/* Bit fields of GTXFIFOSIZ15 register */
#define USB3_GTXFIFOSIZ15_TXFSTADDR_N_MASK                          0xFFFF0000U
#define USB3_GTXFIFOSIZ15_TXFSTADDR_N_POS                           16U
#define USB3_GTXFIFOSIZ15_TXFDEP_N_MASK                             0x00007FFFU
#define USB3_GTXFIFOSIZ15_TXFDEP_N_POS                              0U

/* Bit fields of GRXFIFOSIZ0 register */
#define USB3_GRXFIFOSIZ0_RXFSTADDR_N_MASK                           0xFFFF0000U
#define USB3_GRXFIFOSIZ0_RXFSTADDR_N_POS                            16U
#define USB3_GRXFIFOSIZ0_RXFDEP_N_MASK                              0x00007FFFU
#define USB3_GRXFIFOSIZ0_RXFDEP_N_POS                               0U

/* Bit fields of GRXFIFOSIZ1 register */
#define USB3_GRXFIFOSIZ1_RXFSTADDR_N_MASK                           0xFFFF0000U
#define USB3_GRXFIFOSIZ1_RXFSTADDR_N_POS                            16U
#define USB3_GRXFIFOSIZ1_RXFDEP_N_MASK                              0x00007FFFU
#define USB3_GRXFIFOSIZ1_RXFDEP_N_POS                               0U

/* Bit fields of GRXFIFOSIZ2 register */
#define USB3_GRXFIFOSIZ2_RXFSTADDR_N_MASK                           0xFFFF0000U
#define USB3_GRXFIFOSIZ2_RXFSTADDR_N_POS                            16U
#define USB3_GRXFIFOSIZ2_RXFDEP_N_MASK                              0x00007FFFU
#define USB3_GRXFIFOSIZ2_RXFDEP_N_POS                               0U

/* Bit fields of GRXFIFOSIZ3 register */
#define USB3_GRXFIFOSIZ3_RXFSTADDR_N_MASK                           0xFFFF0000U
#define USB3_GRXFIFOSIZ3_RXFSTADDR_N_POS                            16U
#define USB3_GRXFIFOSIZ3_RXFDEP_N_MASK                              0x00007FFFU
#define USB3_GRXFIFOSIZ3_RXFDEP_N_POS                               0U

/* Bit fields of GRXFIFOSIZ4 register */
#define USB3_GRXFIFOSIZ4_RXFSTADDR_N_MASK                           0xFFFF0000U
#define USB3_GRXFIFOSIZ4_RXFSTADDR_N_POS                            16U
#define USB3_GRXFIFOSIZ4_RXFDEP_N_MASK                              0x00007FFFU
#define USB3_GRXFIFOSIZ4_RXFDEP_N_POS                               0U

/* Bit fields of GRXFIFOSIZ5 register */
#define USB3_GRXFIFOSIZ5_RXFSTADDR_N_MASK                           0xFFFF0000U
#define USB3_GRXFIFOSIZ5_RXFSTADDR_N_POS                            16U
#define USB3_GRXFIFOSIZ5_RXFDEP_N_MASK                              0x00007FFFU
#define USB3_GRXFIFOSIZ5_RXFDEP_N_POS                               0U

/* Bit fields of GEVNTADRLO register */
#define USB3_GEVNTADRLO_EVNTADRLO_MASK                              0xFFFFFFFFU
#define USB3_GEVNTADRLO_EVNTADRLO_POS                               0U

/* Bit fields of GEVNTADRHI register */
#define USB3_GEVNTADRHI_EVNTADRHI_MASK                              0xFFFFFFFFU
#define USB3_GEVNTADRHI_EVNTADRHI_POS                               0U

/* Bit fields of GEVNTSIZ register */
#define USB3_GEVNTSIZ_EVNTINTRPTMASK_MASK                           0x80000000U
#define USB3_GEVNTSIZ_EVNTINTRPTMASK_POS                            31U
#define USB3_GEVNTSIZ_EVENTSIZ_MASK                                 0x0000FFFFU
#define USB3_GEVNTSIZ_EVENTSIZ_POS                                  0U

/* Bit fields of GEVNTCOUNT register */
#define USB3_GEVNTCOUNT_EVNT_HANDLER_BUSY_MASK                      0x80000000U
#define USB3_GEVNTCOUNT_EVNT_HANDLER_BUSY_POS                       31U
#define USB3_GEVNTCOUNT_EVNTCOUNT_MASK                              0x0000FFFFU
#define USB3_GEVNTCOUNT_EVNTCOUNT_POS                               0U

/* Bit fields of GHWPARAMS8 register */
#define USB3_GHWPARAMS8_GHWPARAMS8_32_0_MASK                        0xFFFFFFFFU
#define USB3_GHWPARAMS8_GHWPARAMS8_32_0_POS                         0U

/* Bit fields of GSMACCTL register */
#define USB3_GSMACCTL_DBG_TIS_INDEX_MASK                            0xC0000000U
#define USB3_GSMACCTL_DBG_TIS_INDEX_POS                             30U
#define USB3_GSMACCTL_DBG_PTL_ADDR_MASK                             0x3C000000U
#define USB3_GSMACCTL_DBG_PTL_ADDR_POS                              26U
#define USB3_GSMACCTL_HOSTIN_SIGNLE_EN_MASK                         0x00020000U
#define USB3_GSMACCTL_HOSTIN_SIGNLE_EN_POS                          17U
#define USB3_GSMACCTL_HOSTOUT_SINGLE_EN_MASK                        0x00010000U
#define USB3_GSMACCTL_HOSTOUT_SINGLE_EN_POS                         16U
#define USB3_GSMACCTL_SINGLE_PSQDIR_EN_MASK                         0x00000008U
#define USB3_GSMACCTL_SINGLE_PSQDIR_EN_POS                          3U
#define USB3_GSMACCTL_HOST_MASK_NUMP0_MASK                          0x00000004U
#define USB3_GSMACCTL_HOST_MASK_NUMP0_POS                           2U
#define USB3_GSMACCTL_IGNORE_BABBLE_MASK                            0x00000002U
#define USB3_GSMACCTL_IGNORE_BABBLE_POS                             1U
#define USB3_GSMACCTL_SINGLE_TBT_REQ_MASK                           0x00000001U
#define USB3_GSMACCTL_SINGLE_TBT_REQ_POS                            0U

/* Bit fields of GUCTL2 register */
#define USB3_GUCTL2_PERIODIC_UF_THR_MASK                            0xFE000000U
#define USB3_GUCTL2_PERIODIC_UF_THR_POS                             25U
#define USB3_GUCTL2_ASYNC_UF_THR_MASK                               0x01FC0000U
#define USB3_GUCTL2_ASYNC_UF_THR_POS                                18U
#define USB3_GUCTL2_PERIODIC_TXDMA_UF_THR_MASK                      0x0003F800U
#define USB3_GUCTL2_PERIODIC_TXDMA_UF_THR_POS                       11U
#define USB3_GUCTL2_SVC_OPP_PER_SSP_MASK                            0x00000600U
#define USB3_GUCTL2_SVC_OPP_PER_SSP_POS                             9U
#define USB3_GUCTL2_SVC_OPP_PER_SS_MASK                             0x00000180U
#define USB3_GUCTL2_SVC_OPP_PER_SS_POS                              7U
#define USB3_GUCTL2_SVC_OPP_PER_HS_MASK                             0x00000060U
#define USB3_GUCTL2_SVC_OPP_PER_HS_POS                              5U
#define USB3_GUCTL2_SVC_OPP_PER_FSLS_MASK                           0x00000018U
#define USB3_GUCTL2_SVC_OPP_PER_FSLS_POS                            3U
#define USB3_GUCTL2_MAX_REISU_CNT_MASK                              0x00000006U
#define USB3_GUCTL2_MAX_REISU_CNT_POS                               1U
#define USB3_GUCTL2_SCHEDDULE_LT_THR_MASK                           0x00000001U
#define USB3_GUCTL2_SCHEDDULE_LT_THR_POS                            0U

/* Bit fields of GUCTL3 register */
#define USB3_GUCTL3_CFGEP_CMD_SWITCHING_TIME_CTRL_MASK              0x01C00000U
#define USB3_GUCTL3_CFGEP_CMD_SWITCHING_TIME_CTRL_POS               22U
#define USB3_GUCTL3_BLOCK_CONCURRENT_IN_CTRL_XFERS_MASK             0x00200000U
#define USB3_GUCTL3_BLOCK_CONCURRENT_IN_CTRL_XFERS_POS              21U
#define USB3_GUCTL3_SSBI_SINGLE_EP_MODE_DISABLE_MASK                0x00100000U
#define USB3_GUCTL3_SSBI_SINGLE_EP_MODE_DISABLE_POS                 20U
#define USB3_GUCTL3_DISEXTBUSCLKGT_U1U2L1_MASK                      0x00080000U
#define USB3_GUCTL3_DISEXTBUSCLKGT_U1U2L1_POS                       19U
#define USB3_GUCTL3_DISEXTBUSCLKGT_MASK                             0x00040000U
#define USB3_GUCTL3_DISEXTBUSCLKGT_POS                              18U
#define USB3_GUCTL3_USB20_RETRY_DISABLE_MASK                        0x00010000U
#define USB3_GUCTL3_USB20_RETRY_DISABLE_POS                         16U
#define USB3_GUCTL3_SVC_OPP_PER_HS_SEP_MASK                         0x00001E00U
#define USB3_GUCTL3_SVC_OPP_PER_HS_SEP_POS                          9U
#define USB3_GUCTL3_BARB_BURST_ENABLE_MASK                          0x00000100U
#define USB3_GUCTL3_BARB_BURST_ENABLE_POS                           8U
#define USB3_GUCTL3_INTR_EP_PING_ENABLE_MASK                        0x00000080U
#define USB3_GUCTL3_INTR_EP_PING_ENABLE_POS                         7U
#define USB3_GUCTL3_PERIODIC_UF_THR_FSLS_MASK                       0x0000007FU
#define USB3_GUCTL3_PERIODIC_UF_THR_FSLS_POS                        0U

/* Bit fields of GTXFIFOPRIDEV register */
#define USB3_GTXFIFOPRIDEV_GTXFIFOPRIDEV_MASK                       0x0000FFFFU
#define USB3_GTXFIFOPRIDEV_GTXFIFOPRIDEV_POS                        0U

/* Bit fields of GTXFIFOPRIHST register */
#define USB3_GTXFIFOPRIHST_GTXFIFOPRIHST_MASK                       0x0000007FU
#define USB3_GTXFIFOPRIHST_GTXFIFOPRIHST_POS                        0U

/* Bit fields of GRXFIFOPRIHST register */
#define USB3_GRXFIFOPRIHST_GRXFIFOPRIHST_MASK                       0x0000003FU
#define USB3_GRXFIFOPRIHST_GRXFIFOPRIHST_POS                        0U

/* Bit fields of GFIFOPRIDBC register */
#define USB3_GFIFOPRIDBC_GFIFOPRIDBC_MASK                           0x00000003U
#define USB3_GFIFOPRIDBC_GFIFOPRIDBC_POS                            0U

/* Bit fields of GDMAHLRATIO register */
#define USB3_GDMAHLRATIO_HSTRXFIFO_MAC_MASK                         0x1F000000U
#define USB3_GDMAHLRATIO_HSTRXFIFO_MAC_POS                          24U
#define USB3_GDMAHLRATIO_HSTTXFIFO_MAC_MASK                         0x001F0000U
#define USB3_GDMAHLRATIO_HSTTXFIFO_MAC_POS                          16U
#define USB3_GDMAHLRATIO_HSTRXFIFO_DMA_MASK                         0x00001F00U
#define USB3_GDMAHLRATIO_HSTRXFIFO_DMA_POS                          8U
#define USB3_GDMAHLRATIO_HSTTXFIFO_DMA_MASK                         0x0000001FU
#define USB3_GDMAHLRATIO_HSTTXFIFO_DMA_POS                          0U

/* Bit fields of GOSTDDMA_ASYNC register */
#define USB3_GOSTDDMA_ASYNC_OSTDRX_ASYNC_MASK                       0xFF000000U
#define USB3_GOSTDDMA_ASYNC_OSTDRX_ASYNC_POS                        24U
#define USB3_GOSTDDMA_ASYNC_OSTDTX_ASYNC_ACTIVE_MASK                0x00FF0000U
#define USB3_GOSTDDMA_ASYNC_OSTDTX_ASYNC_ACTIVE_POS                 16U
#define USB3_GOSTDDMA_ASYNC_OSTDTX_ASYNC_INACTIVE_MASK              0x0000FF00U
#define USB3_GOSTDDMA_ASYNC_OSTDTX_ASYNC_INACTIVE_POS               8U
#define USB3_GOSTDDMA_ASYNC_OSTDTX_ASYNC_MASK                       0x000000FFU
#define USB3_GOSTDDMA_ASYNC_OSTDTX_ASYNC_POS                        0U

/* Bit fields of GOSTDDMA_PRD register */
#define USB3_GOSTDDMA_PRD_OSTDRX_PRD_MASK                           0xFF000000U
#define USB3_GOSTDDMA_PRD_OSTDRX_PRD_POS                            24U
#define USB3_GOSTDDMA_PRD_OSTDTX_PRD_ACTIVE_MASK                    0x00FF0000U
#define USB3_GOSTDDMA_PRD_OSTDTX_PRD_ACTIVE_POS                     16U
#define USB3_GOSTDDMA_PRD_OSTDTX_PRD_INACTIVE_MASK                  0x0000FF00U
#define USB3_GOSTDDMA_PRD_OSTDTX_PRD_INACTIVE_POS                   8U
#define USB3_GOSTDDMA_PRD_OSTDTX_PRD_MASK                           0x000000FFU
#define USB3_GOSTDDMA_PRD_OSTDTX_PRD_POS                            0U

/* Bit fields of GFLADJ register */
#define USB3_GFLADJ_GFLADJ_REFCLK_240MHZDECR_PLS1_MASK              0x80000000U
#define USB3_GFLADJ_GFLADJ_REFCLK_240MHZDECR_PLS1_POS               31U
#define USB3_GFLADJ_GFLADJ_REFCLK_240MHZ_DECR_MASK                  0x7F000000U
#define USB3_GFLADJ_GFLADJ_REFCLK_240MHZ_DECR_POS                   24U
#define USB3_GFLADJ_GFLADJ_REFCLK_LPM_SEL_MASK                      0x00800000U
#define USB3_GFLADJ_GFLADJ_REFCLK_LPM_SEL_POS                       23U
#define USB3_GFLADJ_GFLADJ_REFCLK_FLADJ_MASK                        0x003FFF00U
#define USB3_GFLADJ_GFLADJ_REFCLK_FLADJ_POS                         8U
#define USB3_GFLADJ_GFLADJ_30MHZ_SDBND_SEL_MASK                     0x00000080U
#define USB3_GFLADJ_GFLADJ_30MHZ_SDBND_SEL_POS                      7U
#define USB3_GFLADJ_GFLADJ_30MHZ_MASK                               0x0000003FU
#define USB3_GFLADJ_GFLADJ_30MHZ_POS                                0U

/* Bit fields of GUCTL4 register */
#define USB3_GUCTL4_SSP_BWD_OVHD_ADJ_MASK                           0x7C000000U
#define USB3_GUCTL4_SSP_BWD_OVHD_ADJ_POS                            26U
#define USB3_GUCTL4_LOA_EOP_CHECK_CLKS_WORD_MASK                    0x00180000U
#define USB3_GUCTL4_LOA_EOP_CHECK_CLKS_WORD_POS                     19U
#define USB3_GUCTL4_LOA_EOP_CHECK_CLKS_BYTE_MASK                    0x00060000U
#define USB3_GUCTL4_LOA_EOP_CHECK_CLKS_BYTE_POS                     17U
#define USB3_GUCTL4_CSR_TIMEOUT_VL_MASK                             0x0001FFFFU
#define USB3_GUCTL4_CSR_TIMEOUT_VL_POS                              0U

/* Bit fields of GUCTL5 register */

/* Bit fields of GUSB2RHBCTL register */
#define USB3_GUSB2RHBCTL_OVRD_FS_INT_PKT_DEL_MASK    0x000FF000U
#define USB3_GUSB2RHBCTL_OVRD_FS_INT_PKT_DEL_POS     12U
#define USB3_GUSB2RHBCTL_OVRD_HS_INT_PKT_DEL_MASK    0x00000FF0U
#define USB3_GUSB2RHBCTL_OVRD_HS_INT_PKT_DEL_POS     4U
#define USB3_GUSB2RHBCTL_OVRD_L1TIMEOUT_MASK         0x0000000FU
#define USB3_GUSB2RHBCTL_OVRD_L1TIMEOUT_POS          0U

/* Bit fields of DCFG register */
#define USB3_DCFG_IGNSTRMPP_MASK                     0x00800000U
#define USB3_DCFG_IGNSTRMPP_POS                      23U
#define USB3_DCFG_LPMCAP_MASK                        0x00400000U
#define USB3_DCFG_LPMCAP_POS                         22U
#define USB3_DCFG_NUMP_MASK                          0x003E0000U
#define USB3_DCFG_NUMP_POS                           17U
#define USB3_DCFG_INTRNUM_MASK                       0x0001F000U
#define USB3_DCFG_INTRNUM_POS                        12U
#define USB3_DCFG_DEVADDR_MASK                       0x000003F8U
#define USB3_DCFG_DEVADDR_POS                        3U
#define USB3_DCFG_DEVSPD_MASK                        0x00000007U
#define USB3_DCFG_DEVSPD_POS                         0U

/* Bit fields of DCTL register */
#define USB3_DCTL_RUN_STOP_MASK                      0x80000000U
#define USB3_DCTL_RUN_STOP_POS                       31U
#define USB3_DCTL_CSFTRST_MASK                       0x40000000U
#define USB3_DCTL_CSFTRST_POS                        30U
#define USB3_DCTL_HIRDTHRES_MASK                     0x1F000000U
#define USB3_DCTL_HIRDTHRES_POS                      24U
#define USB3_DCTL_LPM_NYET_THRES_MASK                0x00F00000U
#define USB3_DCTL_LPM_NYET_THRES_POS                 20U
#define USB3_DCTL_KEEPCONNECT_MASK                   0x00080000U
#define USB3_DCTL_KEEPCONNECT_POS                    19U
#define USB3_DCTL_L1HIBERNATIONEN_MASK               0x00040000U
#define USB3_DCTL_L1HIBERNATIONEN_POS                18U
#define USB3_DCTL_CRS_MASK                           0x00020000U
#define USB3_DCTL_CRS_POS                            17U
#define USB3_DCTL_CSS_MASK                           0x00010000U
#define USB3_DCTL_CSS_POS                            16U
#define USB3_DCTL_INITU2ENA_MASK                     0x00001000U
#define USB3_DCTL_INITU2ENA_POS                      12U
#define USB3_DCTL_ACCEPTU2ENA_MASK                   0x00000800U
#define USB3_DCTL_ACCEPTU2ENA_POS                    11U
#define USB3_DCTL_INITU1ENA_MASK                     0x00000400U
#define USB3_DCTL_INITU1ENA_POS                      10U
#define USB3_DCTL_ACCEPTU1ENA_MASK                   0x00000200U
#define USB3_DCTL_ACCEPTU1ENA_POS                    9U
#define USB3_DCTL_ULSTCHNGREQ_MASK                   0x000001E0U
#define USB3_DCTL_ULSTCHNGREQ_POS                    5U
#define USB3_DCTL_TSTCTL_MASK                        0x0000001EU
#define USB3_DCTL_TSTCTL_POS                         1U

/* Bit fields of DEVTEN register */
#define USB3_DEVTEN_LDMEVTEN_MASK                    0x00008000U
#define USB3_DEVTEN_LDMEVTEN_POS                     15U
#define USB3_DEVTEN_L1WKUPEVTEN_MASK                 0x00004000U
#define USB3_DEVTEN_L1WKUPEVTEN_POS                  14U
#define USB3_DEVTEN_VENDEVTSTRCVDEN_MASK             0x00001000U
#define USB3_DEVTEN_VENDEVTSTRCVDEN_POS              12U
#define USB3_DEVTEN_ERRTICERREVTEN_MASK              0x00000200U
#define USB3_DEVTEN_ERRTICERREVTEN_POS               9U
#define USB3_DEVTEN_L1SUSPEN_MASK                    0x00000100U
#define USB3_DEVTEN_L1SUSPEN_POS                     8U
#define USB3_DEVTEN_SOFTEVTEN_MASK                   0x00000080U
#define USB3_DEVTEN_SOFTEVTEN_POS                    7U
#define USB3_DEVTEN_U3L2L1SUSPEN_MASK                0x00000040U
#define USB3_DEVTEN_U3L2L1SUSPEN_POS                 6U
#define USB3_DEVTEN_HIBERNATIONREQEVTEN_MASK         0x00000020U
#define USB3_DEVTEN_HIBERNATIONREQEVTEN_POS          5U
#define USB3_DEVTEN_WKUPEVTEN_MASK                   0x00000010U
#define USB3_DEVTEN_WKUPEVTEN_POS                    4U
#define USB3_DEVTEN_ULSTCNGEN_MASK                   0x00000008U
#define USB3_DEVTEN_ULSTCNGEN_POS                    3U
#define USB3_DEVTEN_CONNECTDONEEVTEN_MASK            0x00000004U
#define USB3_DEVTEN_CONNECTDONEEVTEN_POS             2U
#define USB3_DEVTEN_USBRSTEVTEN_MASK                 0x00000002U
#define USB3_DEVTEN_USBRSTEVTEN_POS                  1U
#define USB3_DEVTEN_DISSCONNEVTEN_MASK               0x00000001U
#define USB3_DEVTEN_DISSCONNEVTEN_POS                0U

/* Bit fields of DSTS register */
#define USB3_DSTS_DCNRD_MASK                         0x20000000U
#define USB3_DSTS_DCNRD_POS                          29U
#define USB3_DSTS_SRE_MASK                           0x10000000U
#define USB3_DSTS_SRE_POS                            28U
#define USB3_DSTS_RSS_MASK                           0x02000000U
#define USB3_DSTS_RSS_POS                            25U
#define USB3_DSTS_SSS_MASK                           0x01000000U
#define USB3_DSTS_SSS_POS                            24U
#define USB3_DSTS_COREIDLE_MASK                      0x00800000U
#define USB3_DSTS_COREIDLE_POS                       23U
#define USB3_DSTS_DEVCTRLHLT_MASK                    0x00400000U
#define USB3_DSTS_DEVCTRLHLT_POS                     22U
#define USB3_DSTS_USBLNKST_MASK                      0x003C0000U
#define USB3_DSTS_USBLNKST_POS                       18U
#define USB3_DSTS_RXFIFOEMPTY_MASK                   0x00020000U
#define USB3_DSTS_RXFIFOEMPTY_POS                    17U
#define USB3_DSTS_SOFFN_MASK                         0x0001FFF8U
#define USB3_DSTS_SOFFN_POS                          3U
#define USB3_DSTS_CONNECTSPD_MASK                    0x00000007U
#define USB3_DSTS_CONNECTSPD_POS                     0U

/* Bit fields of DGCMDPAR register */
#define USB3_DGCMDPAR_PARAMETER_MASK                 0xFFFFFFFFU
#define USB3_DGCMDPAR_PARAMETER_POS                  0U

/* Bit fields of DGCMD register */
#define USB3_DGCMD_CMDSTATUS_MASK                    0x0000F000U
#define USB3_DGCMD_CMDSTATUS_POS                     12U
#define USB3_DGCMD_CMDACT_MASK                       0x00000400U
#define USB3_DGCMD_CMDACT_POS                        10U
#define USB3_DGCMD_CMDIOC_MASK                       0x00000100U
#define USB3_DGCMD_CMDIOC_POS                        8U
#define USB3_DGCMD_CMDTYP_MASK                       0x000000FFU
#define USB3_DGCMD_CMDTYP_POS                        0U

/* Bit fields of DCTL1 register */
#define USB3_DCTL1_EN_ENDXFER_ON_RJCT_STRM_MASK      0x00000004U
#define USB3_DCTL1_EN_ENDXFER_ON_RJCT_STRM_POS       2U
#define USB3_DCTL1_DIS_CLRSPR_SXFER_MASK             0x00000002U
#define USB3_DCTL1_DIS_CLRSPR_SXFER_POS              1U

/* Bit fields of DALEPENA register */
#define USB3_DALEPENA_USBACTEP_MASK                  0xFFFFFFFFU
#define USB3_DALEPENA_USBACTEP_POS                   0U

/* Bit fields of DLDMENA register */
#define USB3_DLDMENA_LDMADJ_MASK                     0xFFFF0000U
#define USB3_DLDMENA_LDMADJ_POS                      16U
#define USB3_DLDMENA_LDMDUR_MASK                     0x0000FF00U
#define USB3_DLDMENA_LDMDUR_POS                      8U
#define USB3_DLDMENA_NOLOWPWRDUR_MASK                0x000000F0U
#define USB3_DLDMENA_NOLOWPWRDUR_POS                 4U
#define USB3_DLDMENA_LDMRQS_MASK                     0x0000000EU
#define USB3_DLDMENA_LDMRQS_POS                      1U
#define USB3_DLDMENA_LDMENA_MASK                     0x00000001U
#define USB3_DLDMENA_LDMENA_POS                      0U

/* Bit fields of Rsvd register */

/* Bit fields of DEPCMDPAR2 register */
#define USB3_DEPCMDPAR2_PARAMETER_MASK                           0xFFFFFFFFU
#define USB3_DEPCMDPAR2_PARAMETER_POS                            0U

/* Bit fields of DEPCMDPAR1 register */
#define USB3_DEPCMDPAR1_PARAMETER_MASK                           0xFFFFFFFFU
#define USB3_DEPCMDPAR1_PARAMETER_POS                            0U

/* Bit fields of DEPCMDPAR0 register */
#define USB3_DEPCMDPAR0_PARAMETER_MASK                           0xFFFFFFFFU
#define USB3_DEPCMDPAR0_PARAMETER_POS                            0U

/* Bit fields of DEPCMD register */
#define USB3_DEPCMD_COMMANDPARAM_MASK                            0xFFFF0000U
#define USB3_DEPCMD_COMMANDPARAM_POS                             16U
#define USB3_DEPCMD_CMDSTATUS_MASK                               0x0000F000U
#define USB3_DEPCMD_CMDSTATUS_POS                                12U
#define USB3_DEPCMD_HIPRI_FORCERM_MASK                           0x00000800U
#define USB3_DEPCMD_HIPRI_FORCERM_POS                            11U
#define USB3_DEPCMD_CMDACT_MASK                                  0x00000400U
#define USB3_DEPCMD_CMDACT_POS                                   10U
#define USB3_DEPCMD_CMDIOC_MASK                                  0x00000100U
#define USB3_DEPCMD_CMDIOC_POS                                   8U
#define USB3_DEPCMD_CMDTYP_MASK                                  0x0000000FU
#define USB3_DEPCMD_CMDTYP_POS                                   0U

/* Bit fields of DEV_IMOD register */
#define USB3_DEV_IMOD_DEVICE_IMODC_MASK                          0xFFFF0000U
#define USB3_DEV_IMOD_DEVICE_IMODC_POS                           16U
#define USB3_DEV_IMOD_DEVICE_IMODI_MASK                          0x0000FFFFU
#define USB3_DEV_IMOD_DEVICE_IMODI_POS                           0U

/* Bit fields of rsvd0_reg register */
#define USB3_RSVD0_REG_RSVD_FIELD_MASK                           0xFFFFFFFFU
#define USB3_RSVD0_REG_RSVD_FIELD_POS                            0U

/* Bit fields of LU1LFPSRXTIM register */
#define USB3_LU1LFPSRXTIM_GEN2_U1_LFPS_EXIT_RX_CLK_MASK          0xFF000000U
#define USB3_LU1LFPSRXTIM_GEN2_U1_LFPS_EXIT_RX_CLK_POS           24U
#define USB3_LU1LFPSRXTIM_GEN2_U1_EXIT_RSP_RX_CLK_MASK           0x00FF0000U
#define USB3_LU1LFPSRXTIM_GEN2_U1_EXIT_RSP_RX_CLK_POS            16U
#define USB3_LU1LFPSRXTIM_GEN1_U1_LFPS_EXIT_RX_CLK_MASK          0x0000FF00U
#define USB3_LU1LFPSRXTIM_GEN1_U1_LFPS_EXIT_RX_CLK_POS           8U
#define USB3_LU1LFPSRXTIM_GEN1_U1_EXIT_RSP_RX_CLK_MASK           0x000000FFU
#define USB3_LU1LFPSRXTIM_GEN1_U1_EXIT_RSP_RX_CLK_POS            0U

/* Bit fields of LU1LFPSTXTIM register */
#define USB3_LU1LFPSTXTIM_GEN2_U1_EXIT_RESP_TX_CLK_MASK          0x3FFF0000U
#define USB3_LU1LFPSTXTIM_GEN2_U1_EXIT_RESP_TX_CLK_POS           16U
#define USB3_LU1LFPSTXTIM_GEN1_U1_EXIT_RSP_TX_CLK_MASK           0x00003FFFU
#define USB3_LU1LFPSTXTIM_GEN1_U1_EXIT_RSP_TX_CLK_POS            0U

/* Bit fields of LU2LFPSRXTIM register */
#define USB3_LU2LFPSRXTIM_GEN2_U2_LFPS_EXIT_RX_CLK_MASK          0xFF000000U
#define USB3_LU2LFPSRXTIM_GEN2_U2_LFPS_EXIT_RX_CLK_POS           24U
#define USB3_LU2LFPSRXTIM_GEN2_U2_EXIT_RSP_RX_CLK_MASK           0x00FF0000U
#define USB3_LU2LFPSRXTIM_GEN2_U2_EXIT_RSP_RX_CLK_POS            16U
#define USB3_LU2LFPSRXTIM_GEN1_U2_LFPS_EXIT_RX_CLK_MASK          0x0000FF00U
#define USB3_LU2LFPSRXTIM_GEN1_U2_LFPS_EXIT_RX_CLK_POS           8U
#define USB3_LU2LFPSRXTIM_GEN1_U2_EXIT_RSP_RX_CLK_MASK           0x000000FFU
#define USB3_LU2LFPSRXTIM_GEN1_U2_EXIT_RSP_RX_CLK_POS            0U

/* Bit fields of LU2LFPSTXTIM register */
#define USB3_LU2LFPSTXTIM_U2_EXIT_RSP_TX_US_MASK                 0x00003FFFU
#define USB3_LU2LFPSTXTIM_U2_EXIT_RSP_TX_US_POS                  0U

/* Bit fields of LU3LFPSRXTIM register */
#define USB3_LU3LFPSRXTIM_GEN2_U3_LFPS_EXIT_RX_CLK_MASK          0xFF000000U
#define USB3_LU3LFPSRXTIM_GEN2_U3_LFPS_EXIT_RX_CLK_POS           24U
#define USB3_LU3LFPSRXTIM_GEN2_U3_EXIT_RSP_RX_CLK_MASK           0x00FF0000U
#define USB3_LU3LFPSRXTIM_GEN2_U3_EXIT_RSP_RX_CLK_POS            16U
#define USB3_LU3LFPSRXTIM_GEN1_U3_LFPS_EXIT_RX_CLK_MASK          0x0000FF00U
#define USB3_LU3LFPSRXTIM_GEN1_U3_LFPS_EXIT_RX_CLK_POS           8U
#define USB3_LU3LFPSRXTIM_GEN1_U3_EXIT_RSP_RX_CLK_MASK           0x000000FFU
#define USB3_LU3LFPSRXTIM_GEN1_U3_EXIT_RSP_RX_CLK_POS            0U

/* Bit fields of LU3LFPSTXTIM register */
#define USB3_LU3LFPSTXTIM_GEN2_U3_EXIT_TX_CLK_MASK               0x3FFF0000U
#define USB3_LU3LFPSTXTIM_GEN2_U3_EXIT_TX_CLK_POS                16U
#define USB3_LU3LFPSTXTIM_GEN1_U3_EXIT_RSP_TX_CLK_MASK           0x00003FFFU
#define USB3_LU3LFPSTXTIM_GEN1_U3_EXIT_RSP_TX_CLK_POS            0U

/* Bit fields of LPINGLFPSTIM register */
#define USB3_LPINGLFPSTIM_GEN2_LFPS_PING_BURST_CLK_MASK          0xFC000000U
#define USB3_LPINGLFPSTIM_GEN2_LFPS_PING_BURST_CLK_POS           26U
#define USB3_LPINGLFPSTIM_GEN2_LFPS_PING_MAX_CLK_MASK            0x03F00000U
#define USB3_LPINGLFPSTIM_GEN2_LFPS_PING_MAX_CLK_POS             20U
#define USB3_LPINGLFPSTIM_GEN2_LFPS_PING_MIN_CLK_MASK            0x000F0000U
#define USB3_LPINGLFPSTIM_GEN2_LFPS_PING_MIN_CLK_POS             16U
#define USB3_LPINGLFPSTIM_GEN1_LFPS_PING_BURST_CLK_MASK          0x0000FC00U
#define USB3_LPINGLFPSTIM_GEN1_LFPS_PING_BURST_CLK_POS           10U
#define USB3_LPINGLFPSTIM_GEN1_LFPS_PING_MAX_CLK_MASK            0x000003F0U
#define USB3_LPINGLFPSTIM_GEN1_LFPS_PING_MAX_CLK_POS             4U
#define USB3_LPINGLFPSTIM_GEN1_LFPS_PING_MIN_CLK_MASK            0x0000000FU
#define USB3_LPINGLFPSTIM_GEN1_LFPS_PING_MIN_CLK_POS             0U

/* Bit fields of LPOLLLFPSTXTIM register */
#define USB3_LPOLLLFPSTXTIM_LFPS_POLL_SPACE_CLK_MASK             0x003FF800U
#define USB3_LPOLLLFPSTXTIM_LFPS_POLL_SPACE_CLK_POS              11U
#define USB3_LPOLLLFPSTXTIM_LFPS_POLL_BURST_CLK_MASK             0x000007FFU
#define USB3_LPOLLLFPSTXTIM_LFPS_POLL_BURST_CLK_POS              0U

/* Bit fields of LSKIPFREQ register */
#define USB3_LSKIPFREQ_U1_RESID_TIMER_US_MASK                    0x70000000U
#define USB3_LSKIPFREQ_U1_RESID_TIMER_US_POS                     28U
#define USB3_LSKIPFREQ_EN_PM_TIMER_US_MASK                       0x08000000U
#define USB3_LSKIPFREQ_EN_PM_TIMER_US_POS                        27U
#define USB3_LSKIPFREQ_PM_LC_TIMER_US_MASK                       0x07000000U
#define USB3_LSKIPFREQ_PM_LC_TIMER_US_POS                        24U
#define USB3_LSKIPFREQ_PM_ENTRY_TIMER_US_MASK                    0x00F00000U
#define USB3_LSKIPFREQ_PM_ENTRY_TIMER_US_POS                     20U
#define USB3_LSKIPFREQ_GEN2_SKP_FREQ_MASK                        0x000FF000U
#define USB3_LSKIPFREQ_GEN2_SKP_FREQ_POS                         12U
#define USB3_LSKIPFREQ_GEN1_SKP_FREQ_MASK                        0x00000FFFU
#define USB3_LSKIPFREQ_GEN1_SKP_FREQ_POS                         0U

/* Bit fields of LLUCTL register */
#define USB3_LLUCTL_INVERSE_SYNC_HEADER_MASK                     0x40000000U
#define USB3_LLUCTL_INVERSE_SYNC_HEADER_POS                      30U
#define USB3_LLUCTL_SUPPORT_P4_PG_MASK                           0x20000000U
#define USB3_LLUCTL_SUPPORT_P4_PG_POS                            29U
#define USB3_LLUCTL_SUPPORT_P4_MASK                              0x10000000U
#define USB3_LLUCTL_SUPPORT_P4_POS                               28U
#define USB3_LLUCTL_DELAY_TX_GEN1_DP_MASK                        0x0F000000U
#define USB3_LLUCTL_DELAY_TX_GEN1_DP_POS                         24U
#define USB3_LLUCTL_DISRXDET_LTSSM_TIMER_OVRRD_MASK              0x00800000U
#define USB3_LLUCTL_DISRXDET_LTSSM_TIMER_OVRRD_POS               23U
#define USB3_LLUCTL_FORCE_DPP_TRUNCATE_MASK                      0x00400000U
#define USB3_LLUCTL_FORCE_DPP_TRUNCATE_POS                       22U
#define USB3_LLUCTL_EN_DPP_TRUNCATE_MASK                         0x00200000U
#define USB3_LLUCTL_EN_DPP_TRUNCATE_POS                          21U
#define USB3_LLUCTL_PENDING_HP_TIMER_US_MASK                     0x001F0000U
#define USB3_LLUCTL_PENDING_HP_TIMER_US_POS                      16U
#define USB3_LLUCTL_EN_US_HP_TIMER_MASK                          0x00008000U
#define USB3_LLUCTL_EN_US_HP_TIMER_POS                           15U
#define USB3_LLUCTL_RING_BUF_D_DELAY_MASK                        0x00006000U
#define USB3_LLUCTL_RING_BUF_D_DELAY_POS                         13U
#define USB3_LLUCTL_U2P3CPMOK_MASK                               0x00001000U
#define USB3_LLUCTL_U2P3CPMOK_POS                                12U
#define USB3_LLUCTL_EN_RESET_PIPE_AFTER_PHY_MUX_MASK             0x00000800U
#define USB3_LLUCTL_EN_RESET_PIPE_AFTER_PHY_MUX_POS              11U
#define USB3_LLUCTL_FORCE_GEN1_MASK                              0x00000400U
#define USB3_LLUCTL_FORCE_GEN1_POS                               10U
#define USB3_LLUCTL_GEN2_LOOPBACK_ENTRY_MODE_MASK                0x00000200U
#define USB3_LLUCTL_GEN2_LOOPBACK_ENTRY_MODE_POS                 9U
#define USB3_LLUCTL_GEN1_LOOPBACK_ENTRY_MODE_MASK                0x00000100U
#define USB3_LLUCTL_GEN1_LOOPBACK_ENTRY_MODE_POS                 8U
#define USB3_LLUCTL_MASK_PIPE_RESET_MASK                         0x00000080U
#define USB3_LLUCTL_MASK_PIPE_RESET_POS                          7U
#define USB3_LLUCTL_DELAY_UX_AFTER_LPMA_MASK                     0x00000040U
#define USB3_LLUCTL_DELAY_UX_AFTER_LPMA_POS                      6U
#define USB3_LLUCTL_NO_UX_EXIT_P0_TRANS_MASK                     0x00000020U
#define USB3_LLUCTL_NO_UX_EXIT_P0_TRANS_POS                      5U
#define USB3_LLUCTL_TX_TS1_CNT_MASK                              0x0000001FU
#define USB3_LLUCTL_TX_TS1_CNT_POS                               0U

/* Bit fields of LPTMDPDELAY register */
#define USB3_LPTMDPDELAY_RX_PATH_DELAY_GEN2_MASK                 0xF8000000U
#define USB3_LPTMDPDELAY_RX_PATH_DELAY_GEN2_POS                  27U
#define USB3_LPTMDPDELAY_TX_PATH_DELAY_GEN2_MASK                 0x07C00000U
#define USB3_LPTMDPDELAY_TX_PATH_DELAY_GEN2_POS                  22U
#define USB3_LPTMDPDELAY_P3CPMP4_RESIDENCY_MASK                  0x003FFC00U
#define USB3_LPTMDPDELAY_P3CPMP4_RESIDENCY_POS                   10U
#define USB3_LPTMDPDELAY_RX_PATH_DELAY_MASK                      0x000003E0U
#define USB3_LPTMDPDELAY_RX_PATH_DELAY_POS                       5U
#define USB3_LPTMDPDELAY_TX_PATH_DELAY_MASK                      0x0000001FU
#define USB3_LPTMDPDELAY_TX_PATH_DELAY_POS                       0U

/* Bit fields of LSCDTIM1 register */
#define USB3_LSCDTIM1_SCD_BIT0_RPT_MAX_CLK_MASK                  0x00FFF000U
#define USB3_LSCDTIM1_SCD_BIT0_RPT_MAX_CLK_POS                   12U
#define USB3_LSCDTIM1_CD_BIT0_RPT_MIN_CLK_MASK                   0x00000FFFU
#define USB3_LSCDTIM1_CD_BIT0_RPT_MIN_CLK_POS                    0U

/* Bit fields of LSCDTIM2 register */
#define USB3_LSCDTIM2_SCD_BIT1_RPT_MAX_CLK_MASK                  0x00FFF000U
#define USB3_LSCDTIM2_SCD_BIT1_RPT_MAX_CLK_POS                   12U
#define USB3_LSCDTIM2_CD_BIT1_RPT_MIN_CLK_MASK                   0x00000FFFU
#define USB3_LSCDTIM2_CD_BIT1_RPT_MIN_CLK_POS                    0U

/* Bit fields of LSCDTIM3 register */
#define USB3_LSCDTIM3_LFPS_SCD_SPACE1_CLK_MASK                   0xFFF00000U
#define USB3_LSCDTIM3_LFPS_SCD_SPACE1_CLK_POS                    20U
#define USB3_LSCDTIM3_LFPS_SCD_SPACE0_CLK_MASK                   0x000FFF00U
#define USB3_LSCDTIM3_LFPS_SCD_SPACE0_CLK_POS                    8U
#define USB3_LSCDTIM3_LFPS_SCD_BURST_CLK_MASK                    0x000000FFU
#define USB3_LSCDTIM3_LFPS_SCD_BURST_CLK_POS                     0U

/* Bit fields of LSCDTIM4 register */
#define USB3_LSCDTIM4_LFPS_SCD_LAST_SPACE_MASK                   0x00000FFFU
#define USB3_LSCDTIM4_LFPS_SCD_LAST_SPACE_POS                    0U

/* Bit fields of LLPBMTIM1 register */
#define USB3_LLPBMTIM1_LFPS_LBPS1_BURST_MAX_CLK_MASK             0xFF000000U
#define USB3_LLPBMTIM1_LFPS_LBPS1_BURST_MAX_CLK_POS              24U
#define USB3_LLPBMTIM1_LFPS_LBPS1_BURST_MIN_CLK_MASK             0x00FF0000U
#define USB3_LLPBMTIM1_LFPS_LBPS1_BURST_MIN_CLK_POS              16U
#define USB3_LLPBMTIM1_LFPS_LBPS0_BURST_MAX_CLK_MASK             0x0000FF00U
#define USB3_LLPBMTIM1_LFPS_LBPS0_BURST_MAX_CLK_POS              8U
#define USB3_LLPBMTIM1_LFPS_LBPS0_BURST_MIN_CLK_MASK             0x000000FFU
#define USB3_LLPBMTIM1_LFPS_LBPS0_BURST_MIN_CLK_POS              0U

/* Bit fields of LLPBMTIM2 register */
#define USB3_LLPBMTIM2_LFPS_LBPM_TPWM_MAX_CLK_MASK               0x0003FE00U
#define USB3_LLPBMTIM2_LFPS_LBPM_TPWM_MAX_CLK_POS                9U
#define USB3_LLPBMTIM2_LFPS_LBPM_TPWM_MIN_CLK_MASK               0x000001FFU
#define USB3_LLPBMTIM2_LFPS_LBPM_TPWM_MIN_CLK_POS                0U

/* Bit fields of LLPBMTXTIM register */
#define USB3_LLPBMTXTIM_LFPS_LPBS_TPWM_CLK_MASK                  0x3FF00000U
#define USB3_LLPBMTXTIM_LFPS_LPBS_TPWM_CLK_POS                   20U
#define USB3_LLPBMTXTIM_LFPS_LBPS_BURST1_CLK_MASK                0x0003FF00U
#define USB3_LLPBMTXTIM_LFPS_LBPS_BURST1_CLK_POS                 8U
#define USB3_LLPBMTXTIM_LFPS_LBPS_BURST0_CLK_MASK                0x000000FFU
#define USB3_LLPBMTXTIM_LFPS_LBPS_BURST0_CLK_POS                 0U

/* Bit fields of LLINKERRINJ register */
#define USB3_LLINKERRINJ_PIPE_TXDATA_MASK                        0x80000000U
#define USB3_LLINKERRINJ_PIPE_TXDATA_POS                         31U
#define USB3_LLINKERRINJ_TX_INSERT_DEFER_MASK                    0x40000000U
#define USB3_LLINKERRINJ_TX_INSERT_DEFER_POS                     30U
#define USB3_LLINKERRINJ_TX_INSERT_DELAY_MASK                    0x20000000U
#define USB3_LLINKERRINJ_TX_INSERT_DELAY_POS                     29U
#define USB3_LLINKERRINJ_TX_TS2_MASK                             0x10000000U
#define USB3_LLINKERRINJ_TX_TS2_POS                              28U
#define USB3_LLINKERRINJ_TX_TS1_MASK                             0x08000000U
#define USB3_LLINKERRINJ_TX_TS1_POS                              27U
#define USB3_LLINKERRINJ_TX_TSEQ_MASK                            0x04000000U
#define USB3_LLINKERRINJ_TX_TSEQ_POS                             26U
#define USB3_LLINKERRINJ_TX_LFR_MASK                             0x02000000U
#define USB3_LLINKERRINJ_TX_LFR_POS                              25U
#define USB3_LLINKERRINJ_TX_DELAY_CREDIT_RL_MASK                 0x01000000U
#define USB3_LLINKERRINJ_TX_DELAY_CREDIT_RL_POS                  24U
#define USB3_LLINKERRINJ_TX_ONE_SRT_FRAME_SYBL_MASK              0x00800000U
#define USB3_LLINKERRINJ_TX_ONE_SRT_FRAME_SYBL_POS               23U
#define USB3_LLINKERRINJ_TX_ALL_END_FRAME_SYBL_MASK              0x00400000U
#define USB3_LLINKERRINJ_TX_ALL_END_FRAME_SYBL_POS               22U
#define USB3_LLINKERRINJ_TX_ONE_END_FRAME_SYBL_MASK              0x00200000U
#define USB3_LLINKERRINJ_TX_ONE_END_FRAME_SYBL_POS               21U
#define USB3_LLINKERRINJ_TX_ALL_FRAME_SYBL_MASK                  0x00100000U
#define USB3_LLINKERRINJ_TX_ALL_FRAME_SYBL_POS                   20U
#define USB3_LLINKERRINJ_TX_ONE_FRAME_SYBL_MASK                  0x00080000U
#define USB3_LLINKERRINJ_TX_ONE_FRAME_SYBL_POS                   19U
#define USB3_LLINKERRINJ_TX_CRC32_MASK                           0x00040000U
#define USB3_LLINKERRINJ_TX_CRC32_POS                            18U
#define USB3_LLINKERRINJ_TX_CRC16_MASK                           0x00020000U
#define USB3_LLINKERRINJ_TX_CRC16_POS                            17U
#define USB3_LLINKERRINJ_TX_CRC5_MASK                            0x00010000U
#define USB3_LLINKERRINJ_TX_CRC5_POS                             16U
#define USB3_LLINKERRINJ_RX_PIPE_RXDATA_MASK                     0x00008000U
#define USB3_LLINKERRINJ_RX_PIPE_RXDATA_POS                      15U
#define USB3_LLINKERRINJ_RX_INSERT_DEFER_MASK                    0x00004000U
#define USB3_LLINKERRINJ_RX_INSERT_DEFER_POS                     14U
#define USB3_LLINKERRINJ_RX_INSERT_DELAY_MASK                    0x00002000U
#define USB3_LLINKERRINJ_RX_INSERT_DELAY_POS                     13U
#define USB3_LLINKERRINJ_RX_TS2_MASK                             0x00001000U
#define USB3_LLINKERRINJ_RX_TS2_POS                              12U
#define USB3_LLINKERRINJ_RX_TS1_MASK                             0x00000800U
#define USB3_LLINKERRINJ_RX_TS1_POS                              11U
#define USB3_LLINKERRINJ_RX_TSEQ_MASK                            0x00000400U
#define USB3_LLINKERRINJ_RX_TSEQ_POS                             10U
#define USB3_LLINKERRINJ_RX_LFR_MASK                             0x00000200U
#define USB3_LLINKERRINJ_RX_LFR_POS                              9U
#define USB3_LLINKERRINJ_RX_ALL_START_FRAME_SYBL_MASK            0x00000100U
#define USB3_LLINKERRINJ_RX_ALL_START_FRAME_SYBL_POS             8U
#define USB3_LLINKERRINJ_RX_ONE_SRT_FRAME_SYBL_MASK              0x00000080U
#define USB3_LLINKERRINJ_RX_ONE_SRT_FRAME_SYBL_POS               7U
#define USB3_LLINKERRINJ_RX_ALL_END_FRAME_SYBL_MASK              0x00000040U
#define USB3_LLINKERRINJ_RX_ALL_END_FRAME_SYBL_POS               6U
#define USB3_LLINKERRINJ_RX_ONE_END_FRAME_SYBL_MASK              0x00000020U
#define USB3_LLINKERRINJ_RX_ONE_END_FRAME_SYBL_POS               5U
#define USB3_LLINKERRINJ_RX_ALL_FRAME_SYBL_MASK                  0x00000010U
#define USB3_LLINKERRINJ_RX_ALL_FRAME_SYBL_POS                   4U
#define USB3_LLINKERRINJ_RX_ONE_FRAME_SYBL_MASK                  0x00000008U
#define USB3_LLINKERRINJ_RX_ONE_FRAME_SYBL_POS                   3U
#define USB3_LLINKERRINJ_RX_CRC32_MASK                           0x00000004U
#define USB3_LLINKERRINJ_RX_CRC32_POS                            2U
#define USB3_LLINKERRINJ_RX_CRC16_MASK                           0x00000002U
#define USB3_LLINKERRINJ_RX_CRC16_POS                            1U
#define USB3_LLINKERRINJ_RX_CRC5_MASK                            0x00000001U
#define USB3_LLINKERRINJ_RX_CRC5_POS                             0U

/* Bit fields of LLINKERRINJEN register */
#define USB3_LLINKERRINJEN_DISABLE_INJ_ERR_CNT_MASK              0xFFFF0000U
#define USB3_LLINKERRINJEN_DISABLE_INJ_ERR_CNT_POS               16U
#define USB3_LLINKERRINJEN_B2B_ERR_CNT_MASK                      0x0000FFFFU
#define USB3_LLINKERRINJEN_B2B_ERR_CNT_POS                       0U

/* Bit fields of GDBGLTSSM register */
#define USB3_GDBGLTSSM_RXELECIDLE_MASK                           0x40000000U
#define USB3_GDBGLTSSM_RXELECIDLE_POS                            30U
#define USB3_GDBGLTSSM_LTDBTIMEOUT_MASK                          0x04000000U
#define USB3_GDBGLTSSM_LTDBTIMEOUT_POS                           26U
#define USB3_GDBGLTSSM_LTDBLINKSTATE_MASK                        0x03C00000U
#define USB3_GDBGLTSSM_LTDBLINKSTATE_POS                         22U
#define USB3_GDBGLTSSM_LTDBSUBSTATE_MASK                         0x003C0000U
#define USB3_GDBGLTSSM_LTDBSUBSTATE_POS                          18U
#define USB3_GDBGLTSSM_ELASTICBUFFERMODE_MASK                    0x00020000U
#define USB3_GDBGLTSSM_ELASTICBUFFERMODE_POS                     17U
#define USB3_GDBGLTSSM_TXELECLDLE_MASK                           0x00010000U
#define USB3_GDBGLTSSM_TXELECLDLE_POS                            16U
#define USB3_GDBGLTSSM_RXPOLARITY_MASK                           0x00008000U
#define USB3_GDBGLTSSM_RXPOLARITY_POS                            15U
#define USB3_GDBGLTSSM_TXDETRXLOOPBACK_MASK                      0x00004000U
#define USB3_GDBGLTSSM_TXDETRXLOOPBACK_POS                       14U
#define USB3_GDBGLTSSM_LTDBPHYCMDSTATE_MASK                      0x00003800U
#define USB3_GDBGLTSSM_LTDBPHYCMDSTATE_POS                       11U
#define USB3_GDBGLTSSM_POWERDOWN_MASK                            0x00000600U
#define USB3_GDBGLTSSM_POWERDOWN_POS                             9U
#define USB3_GDBGLTSSM_RXEQTRAIN_MASK                            0x00000100U
#define USB3_GDBGLTSSM_RXEQTRAIN_POS                             8U
#define USB3_GDBGLTSSM_TXDEEMPHASIS_MASK                         0x000000C0U
#define USB3_GDBGLTSSM_TXDEEMPHASIS_POS                          6U
#define USB3_GDBGLTSSM_LTDBCLKSTATE_MASK                         0x00000038U
#define USB3_GDBGLTSSM_LTDBCLKSTATE_POS                          3U
#define USB3_GDBGLTSSM_TXSWING_MASK                              0x00000004U
#define USB3_GDBGLTSSM_TXSWING_POS                               2U
#define USB3_GDBGLTSSM_RXTERMINATION_MASK                        0x00000002U
#define USB3_GDBGLTSSM_RXTERMINATION_POS                         1U
#define USB3_GDBGLTSSM_TXONESZEROS_MASK                          0x00000001U
#define USB3_GDBGLTSSM_TXONESZEROS_POS                           0U

/* Bit fields of GDBGLNMCC register */
#define USB3_GDBGLNMCC_LNMCC_LSERC_MASK                          0xFFFF0000U
#define USB3_GDBGLNMCC_LNMCC_LSERC_POS                           16U
#define USB3_GDBGLNMCC_LNMCC_BERC_MASK                           0x000001FFU
#define USB3_GDBGLNMCC_LNMCC_BERC_POS                            0U

/* Bit fields of LLINKDBGCTRL register */
#define USB3_LLINKDBGCTRL_RETRY_DP_MASK                          0x80000000U
#define USB3_LLINKDBGCTRL_RETRY_DP_POS                           31U
#define USB3_LLINKDBGCTRL_TRIGGER_END_STS_MASK                   0x40000000U
#define USB3_LLINKDBGCTRL_TRIGGER_END_STS_POS                    30U
#define USB3_LLINKDBGCTRL_TRIGGER_START_STS_MASK                 0x20000000U
#define USB3_LLINKDBGCTRL_TRIGGER_START_STS_POS                  29U
#define USB3_LLINKDBGCTRL_LINK_STATE_TRIGGER_DESCRAMBLED_MASK    0x10000000U
#define USB3_LLINKDBGCTRL_LINK_STATE_TRIGGER_DESCRAMBLED_POS     28U
#define USB3_LLINKDBGCTRL_LINK_STATE_TRIGGER_SCRAMBLED_MASK      0x08000000U
#define USB3_LLINKDBGCTRL_LINK_STATE_TRIGGER_SCRAMBLED_POS       27U
#define USB3_LLINKDBGCTRL_PIPE_TXDETECTRXLB_TRIGGER_MASK         0x04000000U
#define USB3_LLINKDBGCTRL_PIPE_TXDETECTRXLB_TRIGGER_POS          26U
#define USB3_LLINKDBGCTRL_PIPE_RXLECIDLE_TRIGGER_MASK            0x02000000U
#define USB3_LLINKDBGCTRL_PIPE_RXLECIDLE_TRIGGER_POS             25U
#define USB3_LLINKDBGCTRL_PIPE_PHYSTATUS_TRIGGER_MASK            0x01000000U
#define USB3_LLINKDBGCTRL_PIPE_PHYSTATUS_TRIGGER_POS             24U
#define USB3_LLINKDBGCTRL_SUB_STATE_TRIGGER_MASK                 0x00F00000U
#define USB3_LLINKDBGCTRL_SUB_STATE_TRIGGER_POS                  20U
#define USB3_LLINKDBGCTRL_LINK_STATE_TRIGGER_MASK                0x000F0000U
#define USB3_LLINKDBGCTRL_LINK_STATE_TRIGGER_POS                 16U
#define USB3_LLINKDBGCTRL_PERI_RSC_RXFIFO_NUMBER_MASK            0x0000F000U
#define USB3_LLINKDBGCTRL_PERI_RSC_RXFIFO_NUMBER_POS             12U
#define USB3_LLINKDBGCTRL_PERI_RSC_TXFIFO_NUMBER_MASK            0x00000F00U
#define USB3_LLINKDBGCTRL_PERI_RSC_TXFIFO_NUMBER_POS             8U
#define USB3_LLINKDBGCTRL_RXFIFO_NUMBER_MASK                     0x000000F0U
#define USB3_LLINKDBGCTRL_RXFIFO_NUMBER_POS                      4U
#define USB3_LLINKDBGCTRL_TXFIFO_NUMBER_MASK                     0x0000000FU
#define USB3_LLINKDBGCTRL_TXFIFO_NUMBER_POS                      0U

/* Bit fields of LLINKDBGCNTTRIG register */
#define USB3_LLINKDBGCNTTRIG_STP_CNT_MASK                        0xFFFF0000U
#define USB3_LLINKDBGCNTTRIG_STP_CNT_POS                         16U
#define USB3_LLINKDBGCNTTRIG_SRT_CNT_MASK                        0x0000FFFFU
#define USB3_LLINKDBGCNTTRIG_SRT_CNT_POS                         0U

/* Bit fields of LCSR_TX_DEEMPH register */
#define USB3_LCSR_TX_DEEMPH_CSR_TX_DEEMPH_FIELD_1_MASK           0x0003FFFFU
#define USB3_LCSR_TX_DEEMPH_CSR_TX_DEEMPH_FIELD_1_POS            0U

/* Bit fields of LCSR_TX_DEEMPH_1 register */
#define USB3_LCSR_TX_DEEMPH_1_CSR_TX_DEEMPH_1_FIELD_1_MASK       0x0003FFFFU
#define USB3_LCSR_TX_DEEMPH_1_CSR_TX_DEEMPH_1_FIELD_1_POS        0U

/* Bit fields of LCSR_TX_DEEMPH_2 register */
#define USB3_LCSR_TX_DEEMPH_2_CSR_TX_DEEMPH_2_FIELD_1_MASK       0x0003FFFFU
#define USB3_LCSR_TX_DEEMPH_2_CSR_TX_DEEMPH_2_FIELD_1_POS        0U

/* Bit fields of LCSR_TX_DEEMPH_3 register */
#define USB3_LCSR_TX_DEEMPH_3_CSR_TX_DEEMPH_3_FIELD_1_MASK       0x0003FFFFU
#define USB3_LCSR_TX_DEEMPH_3_CSR_TX_DEEMPH_3_FIELD_1_POS        0U

/* Bit fields of LCSRPTMDEBUG1 register */
#define USB3_LCSRPTMDEBUG1_LDM_T32_MASK                          0x3FFE0000U
#define USB3_LCSRPTMDEBUG1_LDM_T32_POS                           17U
#define USB3_LCSRPTMDEBUG1_LDM_T1_MASK                           0x0001FFFFU
#define USB3_LCSRPTMDEBUG1_LDM_T1_POS                            0U

/* Bit fields of LCSRPTMDEBUG2 register */
#define USB3_LCSRPTMDEBUG2_LDM_T4_MASK                           0x0001FFFFU
#define USB3_LCSRPTMDEBUG2_LDM_T4_POS                            0U

/* Bit fields of LPTMDPDELAY2 register */
#define USB3_LPTMDPDELAY2_LINK_RX_DELAY_GEN2_MASK                0x000F8000U
#define USB3_LPTMDPDELAY2_LINK_RX_DELAY_GEN2_POS                 15U
#define USB3_LPTMDPDELAY2_LINK_TX_DELAY_GEN2_MASK                0x00007C00U
#define USB3_LPTMDPDELAY2_LINK_TX_DELAY_GEN2_POS                 10U
#define USB3_LPTMDPDELAY2_LINK_RX_DELAY_GEN1_MASK                0x000003E0U
#define USB3_LPTMDPDELAY2_LINK_RX_DELAY_GEN1_POS                 5U
#define USB3_LPTMDPDELAY2_LINK_TX_DELAY_GEN1_MASK                0x0000001FU
#define USB3_LPTMDPDELAY2_LINK_TX_DELAY_GEN1_POS                 0U

/* Bit fields of BU31RHBDBG register */
#define USB3_BU31RHBDBG_TPCFG_TOUT_CTRL_MASK                     0x00000008U
#define USB3_BU31RHBDBG_TPCFG_TOUT_CTRL_POS                      3U
#define USB3_BU31RHBDBG_PCAP_MASK                                0x00000006U
#define USB3_BU31RHBDBG_PCAP_POS                                 1U
#define USB3_BU31RHBDBG_OVRCUR_MASK                              0x00000001U
#define USB3_BU31RHBDBG_OVRCUR_POS                               0U

/* Bit fields of BRAMHIADDR register */
#define USB3_BRAMHIADDR_RAM_SELECT_MASK                          0x001C0000U
#define USB3_BRAMHIADDR_RAM_SELECT_POS                           18U
#define USB3_BRAMHIADDR_RAMHIADDR_MASK                           0x0003F000U
#define USB3_BRAMHIADDR_RAMHIADDR_POS                            12U

/* Bit fields of BRSERRCNT register */
#define USB3_BRSERRCNT_RAM4SERRCNT_MASK                          0x3F000000U
#define USB3_BRSERRCNT_RAM4SERRCNT_POS                           24U
#define USB3_BRSERRCNT_RAM3SERRCNT_MASK                          0x00FC0000U
#define USB3_BRSERRCNT_RAM3SERRCNT_POS                           18U
#define USB3_BRSERRCNT_RAM2SERRCNT_MASK                          0x0003F000U
#define USB3_BRSERRCNT_RAM2SERRCNT_POS                           12U
#define USB3_BRSERRCNT_RAM1SERRCNT_MASK                          0x00000FC0U
#define USB3_BRSERRCNT_RAM1SERRCNT_POS                           6U
#define USB3_BRSERRCNT_RAM0SERRCNT_MASK                          0x0000003FU
#define USB3_BRSERRCNT_RAM0SERRCNT_POS                           0U

/* Bit fields of BRMERRCNT register */
#define USB3_BRMERRCNT_RAM4MERRCNT_MASK                          0x3F000000U
#define USB3_BRMERRCNT_RAM4MERRCNT_POS                           24U
#define USB3_BRMERRCNT_RAM3MERRCNT_MASK                          0x00FC0000U
#define USB3_BRMERRCNT_RAM3MERRCNT_POS                           18U
#define USB3_BRMERRCNT_RAM2MERRCNT_MASK                          0x0003F000U
#define USB3_BRMERRCNT_RAM2MERRCNT_POS                           12U
#define USB3_BRMERRCNT_RAM1MERRCNT_MASK                          0x00000FC0U
#define USB3_BRMERRCNT_RAM1MERRCNT_POS                           6U
#define USB3_BRMERRCNT_RAM0MERRCNT_MASK                          0x0000003FU
#define USB3_BRMERRCNT_RAM0MERRCNT_POS                           0U

/* Bit fields of BRAMECCERR register */
#define USB3_BRAMECCERR_RAMSERR_MASK                             0x00000800U
#define USB3_BRAMECCERR_RAMSERR_POS                              11U
#define USB3_BRAMECCERR_RAMMERR_MASK                             0x00000400U
#define USB3_BRAMECCERR_RAMMERR_POS                              10U
#define USB3_BRAMECCERR_RAMSERRVEC_MASK                          0x000003E0U
#define USB3_BRAMECCERR_RAMSERRVEC_POS                           5U
#define USB3_BRAMECCERR_RAMMERRVEC_MASK                          0x0000001FU
#define USB3_BRAMECCERR_RAMMERRVEC_POS                           0U

/* Bit fields of BRERRCTL register */
#define USB3_BRERRCTL_RSERRCLR_MASK                              0x00000002U
#define USB3_BRERRCTL_RSERRCLR_POS                               1U
#define USB3_BRERRCTL_RMERRCLR_MASK                              0x00000001U
#define USB3_BRERRCTL_RMERRCLR_POS                               0U

/* Bit fields of BRAM0ADDRERR register */
#define USB3_BRAM0ADDRERR_RAM0ERRLOC_MASK                        0x0000FFFFU
#define USB3_BRAM0ADDRERR_RAM0ERRLOC_POS                         0U

/* Bit fields of BRAM1ADDRERR register */
#define USB3_BRAM1ADDRERR_RAM1ERRLOC_MASK                        0x0000FFFFU
#define USB3_BRAM1ADDRERR_RAM1ERRLOC_POS                         0U

/* Bit fields of BRAM2ADDRERR register */
#define USB3_BRAM2ADDRERR_RAM2ERRLOC_MASK                        0x0000FFFFU
#define USB3_BRAM2ADDRERR_RAM2ERRLOC_POS                         0U

/* Bit fields of BRAM3ADDRERR register */
#define USB3_BRAM3ADDRERR_RAM3ERRLOC_MASK                        0x0000FFFFU
#define USB3_BRAM3ADDRERR_RAM3ERRLOC_POS                         0U

/* Bit fields of BRAM4ADDRERR register */
#define USB3_BRAM4ADDRERR_RAM4ERRLOC_MASK                        0x0000FFFFU
#define USB3_BRAM4ADDRERR_RAM4ERRLOC_POS                         0U

/* Bit fields of BLOOPBCKCTRL register */
#define USB3_BLOOPBCKCTRL_LOOPBACK_PRTNUM_MASK                   0x000000F0U
#define USB3_BLOOPBCKCTRL_LOOPBACK_PRTNUM_POS                    4U
#define USB3_BLOOPBCKCTRL_LOOPBACK_LEVEL_MASK                    0x0000000CU
#define USB3_BLOOPBCKCTRL_LOOPBACK_LEVEL_POS                     2U
#define USB3_BLOOPBCKCTRL_LOOPBACK_MODE_MASK                     0x00000002U
#define USB3_BLOOPBCKCTRL_LOOPBACK_MODE_POS                      1U
#define USB3_BLOOPBCKCTRL_LOOPBACK_MODE_EN_MASK                  0x00000001U
#define USB3_BLOOPBCKCTRL_LOOPBACK_MODE_EN_POS                   0U

/* Bit fields of BLOOPBCKTFERSZ register */
#define USB3_BLOOPBCKTFERSZ_LOOPBACK_XFER_SZ_MASK                0x00FFFFFFU
#define USB3_BLOOPBCKTFERSZ_LOOPBACK_XFER_SZ_POS                 0U

/* Bit fields of BBISTDATAPATSEED register */
#define USB3_BBISTDATAPATSEED_BIST_PATTERN_SEED_MASK             0xFFFFFFFFU
#define USB3_BBISTDATAPATSEED_BIST_PATTERN_SEED_POS              0U

/* Bit fields of BBISTCTRL register */
#define USB3_BBISTCTRL_START_BIST_TEST_MASK                      0x80000000U
#define USB3_BBISTCTRL_START_BIST_TEST_POS                       31U
#define USB3_BBISTCTRL_BIST_TEST_TYPE_MASK                       0x40000000U
#define USB3_BBISTCTRL_BIST_TEST_TYPE_POS                        30U
#define USB3_BBISTCTRL_FAIL_MASK                                 0x20000000U
#define USB3_BBISTCTRL_FAIL_POS                                  29U
#define USB3_BBISTCTRL_BIST_PATTERN_MASK                         0x07000000U
#define USB3_BBISTCTRL_BIST_PATTERN_POS                          24U
#define USB3_BBISTCTRL_BIST_ITERATION_CNT_MASK                   0x00FFFFFFU
#define USB3_BBISTCTRL_BIST_ITERATION_CNT_POS                    0U

/* Bit fields of BBISTXFERSTS0 register */
#define USB3_BBISTXFERSTS0_BIST_PENDING_TRANS_SIZE_MASK          0x00FFFFFFU
#define USB3_BBISTXFERSTS0_BIST_PENDING_TRANS_SIZE_POS           0U

/* Bit fields of BBISTXFERSTS1 register */
#define USB3_BBISTXFERSTS1_FAILED_PENDING_TRANS_SIZE_MASK        0x00FFFFFFU
#define USB3_BBISTXFERSTS1_FAILED_PENDING_TRANS_SIZE_POS         0U

/* Bit fields of BBISTXFERSTS2 register */
#define USB3_BBISTXFERSTS2_FAILED_ITERATION_MASK                 0x00FFFFFFU
#define USB3_BBISTXFERSTS2_FAILED_ITERATION_POS                  0U

/* Bit fields of BBISTXFERSTS3 register */
#define USB3_BBISTXFERSTS3_LOOPBACK_STATEMACHINE_MASK            0x0000000FU
#define USB3_BBISTXFERSTS3_LOOPBACK_STATEMACHINE_POS             0U

/* Bit fields of BBISTEXPDATASTS0 register */
#define USB3_BBISTEXPDATASTS0_EXP_DATA_MASK                      0xFFFFFFFFU
#define USB3_BBISTEXPDATASTS0_EXP_DATA_POS                       0U

/* Bit fields of BBISTEXPDATASTS1 register */
#define USB3_BBISTEXPDATASTS1_EXP_DATA_MASK                      0xFFFFFFFFU
#define USB3_BBISTEXPDATASTS1_EXP_DATA_POS                       0U

/* Bit fields of BBISTEXPDATASTS2 register */
#define USB3_BBISTEXPDATASTS2_EXP_DATA_MASK                      0xFFFFFFFFU
#define USB3_BBISTEXPDATASTS2_EXP_DATA_POS                       0U

/* Bit fields of BBISTEXPDATASTS3 register */
#define USB3_BBISTEXPDATASTS3_EXP_DATA_MASK                      0xFFFFFFFFU
#define USB3_BBISTEXPDATASTS3_EXP_DATA_POS                       0U

/* Bit fields of BBISTRCVDDATASTS0 register */
#define USB3_BBISTRCVDDATASTS0_RECEIVED_DATA_MASK                0xFFFFFFFFU
#define USB3_BBISTRCVDDATASTS0_RECEIVED_DATA_POS                 0U

/* Bit fields of BBISTRCVDDATASTS1 register */
#define USB3_BBISTRCVDDATASTS1_RECEIVED_DATA_MASK                0xFFFFFFFFU
#define USB3_BBISTRCVDDATASTS1_RECEIVED_DATA_POS                 0U

/* Bit fields of BBISTRCVDDATASTS2 register */
#define USB3_BBISTRCVDDATASTS2_RECEIVED_DATA_MASK                0xFFFFFFFFU
#define USB3_BBISTRCVDDATASTS2_RECEIVED_DATA_POS                 0U

/* Bit fields of BBISTRCVDDATASTS3 register */
#define USB3_BBISTRCVDDATASTS3_RECEIVED_DATA_MASK                0xFFFFFFFFU
#define USB3_BBISTRCVDDATASTS3_RECEIVED_DATA_POS                 0U

/* Bit fields of rsvd_reg register */
#define USB3_RSVD_REG_RSVD_FIELD_MASK                            0xFFFFFFFFU
#define USB3_RSVD_REG_RSVD_FIELD_POS                             0U

#endif

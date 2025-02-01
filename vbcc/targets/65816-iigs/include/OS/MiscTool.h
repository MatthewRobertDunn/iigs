/********************************************
; File: MiscTool.h
;
;
; Copyright Apple Computer, Inc.1986-89
; All Rights Reserved
;
********************************************/
#ifndef __TYPES__
#include <Types.h>
#endif

#ifndef __MISCTOOL__
#define __MISCTOOL__

#define badInputErr 0x0301 /*error - bad input parameter */
#define noDevParamErr 0x0302 /*error - no device for input parameter */
#define taskInstlErr 0x0303 /*error - task already installed error */
#define noSigTaskErr 0x0304 /*error - no signature in task header */
#define queueDmgdErr 0x0305 /*error - queue has been damaged error */
#define taskNtFdErr 0x0306 /*error - task was not found error */
#define firmTaskErr 0x0307 /*error - firmware task was unsuccessful */
#define hbQueueBadErr 0x0308 /*error - heartbeat queue damaged */
#define unCnctdDevErr 0x0309 /*error - attempted to dispatch to unconnected device */
#define idTagNtAvlErr 0x030B /*error - ID tag not available */
#define pdosUnClmdIntErr 0x0001 /*System Fail - ProDOS unclaimed interrupt error */
#define divByZeroErr 0x0004 /*System Fail - divide by zero error */
#define pdosVCBErr 0x000A /*System Fail - ProDOS VCB unusable */
#define pdosFCBErr 0x000B /*System Fail - ProDOS FCB unusable */
#define pdosBlk0Err 0x000C /*System Fail - ProDOS block zero allocated illegally */
#define pdosIntShdwErr 0x000D /*System Fail - ProDOS interrupt w/ shadowing off */
#define segLoader1Err 0x0015 /*System Fail - segment loader error */
#define sPackage0Err 0x0017 /*System Fail - can't load a package */
#define package1Err 0x0018 /*System Fail - can't load a package */
#define package2Err 0x0019 /*System Fail - can't load a package */
#define package3Err 0x001A /*System Fail - can't load a package */
#define package4Err 0x001B /*System Fail - can't load a package */
#define package5Err 0x001C /*System Fail - can't load a package */
#define package6Err 0x001D /*System Fail - can't load a package */
#define package7Err 0x001E /*System Fail - can't load a package */
#define package8Err 0x0020 /*System Fail - can't load a package */
#define package9Err 0x0021 /*System Fail - can't load a package */
#define package10Err 0x0022 /*System Fail - can't load a package */
#define package11Err 0x0023 /*System Fail - can't load a package */
#define package12Err 0x0024 /*System Fail - can't load a package */
#define outOfMemErr 0x0025 /*System Fail - out of memory error */
#define segLoader2Err 0x0026 /*System Fail - segment loader error */
#define fMapTrshdErr 0x0027 /*System Fail - file map trashed */
#define stkOvrFlwErr 0x0028 /*System Fail - stack overflow error */
#define psInstDiskErr 0x0030 /*System Fail - Please Insert Disk (file manager alert) */
#define memMgr1Err 0x0032 /*System Fail - memory manager error */
#define memMgr2Err 0x0033 /*System Fail - memory manager error */
#define memMgr3Err 0x0034 /*System Fail - memory manager error */
#define memMgr4Err 0x0035 /*System Fail - memory manager error */
#define memMgr5Err 0x0036 /*System Fail - memory manager error */
#define memMgr6Err 0x0037 /*System Fail - memory manager error */
#define memMgr7Err 0x0038 /*System Fail - memory manager error */
#define memMgr8Err 0x0039 /*System Fail - memory manager error */
#define memMgr9Err 0x003A /*System Fail - memory manager error */
#define memMgr10Err 0x003B /*System Fail - memory manager error */
#define memMgr11Err 0x003C /*System Fail - memory manager error */
#define memMgr12Err 0x003D /*System Fail - memory manager error */
#define memMgr13Err 0x003E /*System Fail - memory manager error */
#define memMgr14Err 0x003F /*System Fail - memory manager error */
#define memMgr15Err 0x0040 /*System Fail - memory manager error */
#define memMgr16Err 0x0041 /*System Fail - memory manager error */
#define memMgr17Err 0x0042 /*System Fail - memory manager error */
#define memMgr18Err 0x0043 /*System Fail - memory manager error */
#define memMgr19Err 0x0044 /*System Fail - memory manager error */
#define memMgr20Err 0x0045 /*System Fail - memory manager error */
#define memMgr21Err 0x0046 /*System Fail - memory manager error */
#define memMgr22Err 0x0047 /*System Fail - memory manager error */
#define memMgr23Err 0x0048 /*System Fail - memory manager error */
#define memMgr24Err 0x0049 /*System Fail - memory manager error */
#define memMgr25Err 0x004A /*System Fail - memory manager error */
#define memMgr26Err 0x004B /*System Fail - memory manager error */
#define memMgr27Err 0x004C /*System Fail - memory manager error */
#define memMgr28Err 0x004D /*System Fail - memory manager error */
#define memMgr29Err 0x004E /*System Fail - memory manager error */
#define memMgr30Err 0x004F /*System Fail - memory manager error */
#define memMgr31Err 0x0050 /*System Fail - memory manager error */
#define memMgr32Err 0x0051 /*System Fail - memory manager error */
#define memMgr33Err 0x0052 /*System Fail - memory manager error */
#define memMgr34Err 0x0053 /*System Fail - memory manager error */
#define stupVolMntErr 0x0100 /*System Fail - can't mount system startup volume */
#define p1PrntModem 0x0000 /*Battery Ram Parameter Ref Number -  */
#define p1LineLnth 0x0001 /*Battery Ram Parameter Ref Number -  */
#define p1DelLine 0x0002 /*Battery Ram Parameter Ref Number -  */
#define p1AddLine 0x0003 /*Battery Ram Parameter Ref Number -  */
#define p1Echo 0x0004 /*Battery Ram Parameter Ref Number -  */
#define p1Buffer 0x0005 /*Battery Ram Parameter Ref Number -  */
#define p1Baud 0x0006 /*Battery Ram Parameter Ref Number -  */
#define p1DtStpBits 0x0007 /*Battery Ram Parameter Ref Number -  */
#define p1Parity 0x0008 /*Battery Ram Parameter Ref Number -  */
#define p1DCDHndShk 0x0009 /*Battery Ram Parameter Ref Number -  */
#define p1DSRHndShk 0x000A /*Battery Ram Parameter Ref Number -  */
#define p1XnfHndShk 0x000B /*Battery Ram Parameter Ref Number -  */
#define p2PrntModem 0x000C /*Battery Ram Parameter Ref Number -  */
#define p2LineLnth 0x000D /*Battery Ram Parameter Ref Number -  */
#define p2DelLine 0x000E /*Battery Ram Parameter Ref Number -  */
#define p2AddLine 0x000F /*Battery Ram Parameter Ref Number -  */
#define p2Echo 0x0010 /*Battery Ram Parameter Ref Number -  */
#define p2Buffer 0x0011 /*Battery Ram Parameter Ref Number -  */
#define p2Baud 0x0012 /*Battery Ram Parameter Ref Number -  */
#define p2DtStpBits 0x0013 /*Battery Ram Parameter Ref Number -  */
#define p2Parity 0x0014 /*Battery Ram Parameter Ref Number -  */
#define p2DCDHndShk 0x0015 /*Battery Ram Parameter Ref Number -  */
#define p2DSRHndShk 0x0016 /*Battery Ram Parameter Ref Number -  */
#define p2XnfHndShk 0x0017 /*Battery Ram Parameter Ref Number -  */
#define dspColMono 0x0018 /*Battery Ram Parameter Ref Number -  */
#define dsp40or80 0x0019 /*Battery Ram Parameter Ref Number -  */
#define dspTxtColor 0x001A /*Battery Ram Parameter Ref Number -  */
#define dspBckColor 0x001B /*Battery Ram Parameter Ref Number -  */
#define dspBrdColor 0x001C /*Battery Ram Parameter Ref Number -  */
#define hrtz50or60 0x001D /*Battery Ram Parameter Ref Number -  */
#define userVolume 0x001E /*Battery Ram Parameter Ref Number -  */
#define bellVolume 0x001F /*Battery Ram Parameter Ref Number -  */
#define sysSpeed 0x0020 /*Battery Ram Parameter Ref Number -  */
#define slt1intExt 0x0021 /*Battery Ram Parameter Ref Number -  */
#define slt2intExt 0x0022 /*Battery Ram Parameter Ref Number -  */
#define slt3intExt 0x0023 /*Battery Ram Parameter Ref Number -  */
#define slt4intExt 0x0024 /*Battery Ram Parameter Ref Number -  */
#define slt5intExt 0x0025 /*Battery Ram Parameter Ref Number -  */
#define slt6intExt 0x0026 /*Battery Ram Parameter Ref Number -  */
#define slt7intExt 0x0027 /*Battery Ram Parameter Ref Number -  */
#define startupSlt 0x0028 /*Battery Ram Parameter Ref Number -  */
#define txtDspLang 0x0029 /*Battery Ram Parameter Ref Number -  */
#define kybdLang 0x002A /*Battery Ram Parameter Ref Number -  */
#define kyBdBuffer 0x002B /*Battery Ram Parameter Ref Number -  */
#define kyBdRepSpd 0x002C /*Battery Ram Parameter Ref Number -  */
#define kyBdRepDel 0x002D /*Battery Ram Parameter Ref Number -  */
#define dblClkTime 0x002E /*Battery Ram Parameter Ref Number -  */
#define flashRate 0x002F /*Battery Ram Parameter Ref Number -  */
#define shftCpsLCas 0x0030 /*Battery Ram Parameter Ref Number -  */
#define fstSpDelKey 0x0031 /*Battery Ram Parameter Ref Number -  */
#define dualSpeed 0x0032 /*Battery Ram Parameter Ref Number -  */
#define hiMouseRes 0x0033 /*Battery Ram Parameter Ref Number -  */
#define dateFormat 0x0034 /*Battery Ram Parameter Ref Number -  */
#define clockFormat 0x0035 /*Battery Ram Parameter Ref Number -  */
#define rdMinRam 0x0036 /*Battery Ram Parameter Ref Number -  */
#define rdMaxRam 0x0037 /*Battery Ram Parameter Ref Number -  */
#define langCount 0x0038 /*Battery Ram Parameter Ref Number -  */
#define lang1 0x0039 /*Battery Ram Parameter Ref Number -  */
#define lang2 0x003A /*Battery Ram Parameter Ref Number -  */
#define lang3 0x003B /*Battery Ram Parameter Ref Number -  */
#define lang4 0x003C /*Battery Ram Parameter Ref Number -  */
#define lang5 0x003D /*Battery Ram Parameter Ref Number -  */
#define lang6 0x003E /*Battery Ram Parameter Ref Number -  */
#define lang7 0x003F /*Battery Ram Parameter Ref Number -  */
#define lang8 0x0040 /*Battery Ram Parameter Ref Number -  */
#define layoutCount 0x0041 /*Battery Ram Parameter Ref Number -  */
#define layout1 0x0042 /*Battery Ram Parameter Ref Number -  */
#define layout2 0x0043 /*Battery Ram Parameter Ref Number -  */
#define layout3 0x0044 /*Battery Ram Parameter Ref Number -  */
#define layout4 0x0045 /*Battery Ram Parameter Ref Number -  */
#define layout5 0x0046 /*Battery Ram Parameter Ref Number -  */
#define layout6 0x0047 /*Battery Ram Parameter Ref Number -  */
#define layout7 0x0048 /*Battery Ram Parameter Ref Number -  */
#define layout8 0x0049 /*Battery Ram Parameter Ref Number -  */
#define layout9 0x004A /*Battery Ram Parameter Ref Number -  */
#define layout10 0x004B /*Battery Ram Parameter Ref Number -  */
#define layout11 0x004C /*Battery Ram Parameter Ref Number -  */
#define layout12 0x004D /*Battery Ram Parameter Ref Number -  */
#define layout13 0x004E /*Battery Ram Parameter Ref Number -  */
#define layout14 0x004F /*Battery Ram Parameter Ref Number -  */
#define layout15 0x0050 /*Battery Ram Parameter Ref Number -  */
#define layout16 0x0051 /*Battery Ram Parameter Ref Number -  */
#define aTalkNodeNo 0x0080 /*Battery Ram Parameter Ref Number -  */
#define irqIntFlag 0x0000 /*GetAddr Param Ref No -  */
#define irqDataReg 0x0001 /*GetAddr Param Ref No -  */
#define irqSerial1 0x0002 /*GetAddr Param Ref No -  */
#define irqSerial2 0x0003 /*GetAddr Param Ref No -  */
#define irqAplTlkHi 0x0004 /*GetAddr Param Ref No -  */
#define tickCnt 0x0005 /*GetAddr Param Ref No -  */
#define irqVolume 0x0006 /*GetAddr Param Ref No -  */
#define irqActive 0x0007 /*GetAddr Param Ref No -  */
#define irqSndData 0x0008 /*GetAddr Param Ref No -  */
#define brkVar 0x0009 /*GetAddr Param Ref No -  */
#define evMgrData 0x000A /*GetAddr Param Ref No -  */
#define mouseSlot 0x000B /*GetAddr Param Ref No -  */
#define mouseClamps 0x000C /*GetAddr Param Ref No -  */
#define absClamps 0x000D /*GetAddr Param Ref No -  */
#define sccIntFlag 0x000E /*GetAddr Param Ref No -  */
#define extVGCInt 0x0001 /*Hardware Interrupt Status - Returned by GetIRQEnable */
#define scanLineInt 0x0002 /*Hardware Interrupt Status - Returned by GetIRQEnable */
#define adbDataInt 0x0004 /*Hardware Interrupt Status - Returned by GetIRQEnable */
#define oneSecInt 0x0010 /*Hardware Interrupt Status - Returned by GetIRQEnable */
#define quartSecInt 0x0020 /*Hardware Interrupt Status - Returned by GetIRQEnable */
#define vbInt 0x0040 /*Hardware Interrupt Status - Returned by GetIRQEnable */
#define kbdInt 0x0080 /*Hardware Interrupt Status - Returned by GetIRQEnable */
#define kybdEnable 0x0000 /*Interrupt Ref Number - Parameter to IntSource */
#define kybdDisable 0x0001 /*Interrupt Ref Number - Parameter to IntSource */
#define vblEnable 0x0002 /*Interrupt Ref Number - Parameter to IntSource */
#define vblDisable 0x0003 /*Interrupt Ref Number - Parameter to IntSource */
#define qSecEnable 0x0004 /*Interrupt Ref Number - Parameter to IntSource */
#define qSecDisable 0x0005 /*Interrupt Ref Number - Parameter to IntSource */
#define oSecEnable 0x0006 /*Interrupt Ref Number - Parameter to IntSource */
#define oSecDisable 0x0007 /*Interrupt Ref Number - Parameter to IntSource */
#define adbEnable 0x000A /*Interrupt Ref Number - Parameter to IntSource */
#define adbDisable 0x000B /*Interrupt Ref Number - Parameter to IntSource */
#define scLnEnable 0x000C /*Interrupt Ref Number - Parameter to IntSource */
#define scLnDisable 0x000D /*Interrupt Ref Number - Parameter to IntSource */
#define exVCGEnable 0x000E /*Interrupt Ref Number - Parameter to IntSource */
#define exVCGDisable 0x000F /*Interrupt Ref Number - Parameter to IntSource */
#define mouseOff 0x0000 /*Mouse Mode Value -  */
#define transparent 0x0001 /*Mouse Mode Value -  */
#define transParnt 0x0001 /*Mouse Mode Value - (old name) */
#define moveIntrpt 0x0003 /*Mouse Mode Value -  */
#define bttnIntrpt 0x0005 /*Mouse Mode Value -  */
#define bttnOrMove 0x0007 /*Mouse Mode Value -  */
#define mouseOffVI 0x0008 /*Mouse Mode Value -  */
#define transParntVI 0x0009 /*Mouse Mode Value - (old name) */
#define transparentVI 0x0009 /*Mouse Mode Value -  */
#define moveIntrptVI 0x000B /*Mouse Mode Value -  */
#define bttnIntrptVI 0x000D /*Mouse Mode Value -  */
#define bttnOrMoveVI 0x000F /*Mouse Mode Value -  */
#define toolLoc1 0x0000 /*Vector Ref Number -  */
#define toolLoc2 0x0001 /*Vector Ref Number -  */
#define usrTLoc1 0x0002 /*Vector Ref Number -  */
#define usrTLoc2 0x0003 /*Vector Ref Number -  */
#define intrptMgr 0x0004 /*Vector Ref Number -  */
#define copMgr 0x0005 /*Vector Ref Number -  */
#define abortMgr 0x0006 /*Vector Ref Number -  */
#define _sysFailMgr 0x0007 /*Vector Ref Number -  */
#define aTalkIntHnd 0x0008 /*Vector Ref Number -  */
#define sccIntHnd 0x0009 /*Vector Ref Number -  */
#define scLnIntHnd 0x000A /*Vector Ref Number -  */
#define sndIntHnd 0x000B /*Vector Ref Number -  */
#define vblIntHnd 0x000C /*Vector Ref Number -  */
#define mouseIntHnd 0x000D /*Vector Ref Number -  */
#define qSecIntHnd 0x000E /*Vector Ref Number -  */
#define kybdIntHnd 0x000F /*Vector Ref Number -  */
#define adbRBIHnd 0x0010 /*Vector Ref Number -  */
#define adbSRQHnd 0x0011 /*Vector Ref Number -  */
#define deskAccHnd 0x0012 /*Vector Ref Number -  */
#define flshBufHnd 0x0013 /*Vector Ref Number -  */
#define kybdMicHnd 0x0014 /*Vector Ref Number -  */
#define oneSecHnd 0x0015 /*Vector Ref Number -  */
#define extVCGHnd 0x0016 /*Vector Ref Number -  */
#define otherIntHnd 0x0017 /*Vector Ref Number -  */
#define crsrUpdtHnd 0x0018 /*Vector Ref Number -  */
#define incBsyFlag 0x0019 /*Vector Ref Number -  */
#define decBsyFlag 0x001A /*Vector Ref Number -  */
#define bellVector 0x001B /*Vector Ref Number -  */
#define breakVector 0x001C /*Vector Ref Number -  */
#define traceVector 0x001D /*Vector Ref Number -  */
#define stepVector 0x001E /*Vector Ref Number -  */
#define ctlYVector 0x0028 /*Vector Ref Number -  */
#define proDOSVctr 0x002A /*Vector Ref Number -  */
#define osVector 0x002B /*Vector Ref Number -  */
#define msgPtrVctr 0x002C /*Vector Ref Number -  */
struct ClampRec {
   Word yMaxClamp; /*  */
   Word yMinClamp; /*  */
   Word xMaxClamp; /*  */
   Word xMinClamp; /*  */
} ;
typedef struct ClampRec ClampRec, *ClampRecPtr, **ClampRecHndl;
struct FWRec {
   Word yRegExit; /*  */
   Word xRegExit; /*  */
   Word aRegExit; /*  */
   Word status; /*  */
} ;
typedef struct FWRec FWRec, *FWRecPtr, **FWRecHndl;
struct MouseRec {
   Byte mouseMode; /*  */
   Byte mouseStatus; /*  */
   Word yPos; /*  */
   Word xPos; /*  */
} ;
typedef struct MouseRec MouseRec, *MouseRecPtr, **MouseRecHndl;
struct InterruptStateRec {
   Word irq_A; /*   */
   Word irq_X; /*   */
   Word irq_Y; /*   */
   Word irq_S; /*   */
   Word irq_D; /*   */
   Byte irq_P; /*   */
   Byte irq_DB; /*   */
   Byte irq_e; /*   */
   Byte irq_K; /*   */
   Word irq_PC; /*   */
   Byte irq_state; /*   */
   Word irq_shadow; /*   */
   Byte irq_mslot; /*   */
} ;
typedef struct InterruptStateRec InterruptStateRec, *InterruptStateRecPtr, **InterruptStateRecHndl;
extern pascal void MTBootInit () inline(0x0103,dispatcher);
extern pascal void MTStartUp () inline(0x0203,dispatcher);
extern pascal void MTShutDown () inline(0x0303,dispatcher);
extern pascal Word MTVersion () inline(0x0403,dispatcher);
extern pascal void MTReset () inline(0x0503,dispatcher);
extern pascal Boolean MTStatus () inline(0x0603,dispatcher);
extern pascal void ClampMouse () inline(0x1C03,dispatcher);
extern pascal void ClearMouse () inline(0x1B03,dispatcher);
extern pascal void ClrHeartBeat () inline(0x1403,dispatcher);
extern pascal void DeleteID () inline(0x2103,dispatcher);
extern pascal void DelHeartBeat () inline(0x1303,dispatcher);
extern pascal FWRec FWEntry () inline(0x2403,dispatcher);
extern pascal ClampRec GetAbsClamp () inline(0x2B03,dispatcher);
extern pascal Pointer GetAddr () inline(0x1603,dispatcher);
extern pascal Word GetIRQEnable () inline(0x2903,dispatcher);
extern pascal ClampRec GetMouseClamp () inline(0x1D03,dispatcher);
extern pascal Word GetNewID () inline(0x2003,dispatcher);
extern pascal LongWord __GetTick () inline(0x2503,dispatcher);
#define GetTick() __GetTick(0l)
extern pascal Pointer GetVector () inline(0x1103,dispatcher);
extern pascal void HomeMouse () inline(0x1A03,dispatcher);
extern pascal void InitMouse () inline(0x1803,dispatcher);
extern pascal void IntSource () inline(0x2303,dispatcher);
extern pascal Word Munger () inline(0x2803,dispatcher);
extern pascal Word PackBytes () inline(0x2603,dispatcher);
extern pascal void PosMouse () inline(0x1E03,dispatcher);
extern pascal void ReadAsciiTime () inline(0x0F03,dispatcher);
extern pascal Word ReadBParam () inline(0x0C03,dispatcher);
extern pascal void ReadBRam () inline(0x0A03,dispatcher);
extern pascal MouseRec ReadMouse () inline(0x1703,dispatcher);
extern pascal TimeRec __ReadTimeHex () inline(0x0D03,dispatcher);
#define ReadTimeHex() __ReadTimeHex(0l,0l);
extern pascal Word ServeMouse () inline(0x1F03,dispatcher);
extern pascal void SetAbsClamp () inline(0x2A03,dispatcher);
extern pascal void SetHeartBeat () inline(0x1203,dispatcher);
extern pascal void SetMouse () inline(0x1903,dispatcher);
extern pascal void SetVector () inline(0x1003,dispatcher);
extern pascal void StatusID () inline(0x2203,dispatcher);
extern pascal void SysBeep () inline(0x2C03,dispatcher);
extern pascal void SysFailMgr () inline(0x1503,dispatcher);
extern pascal Word UnPackBytes () inline(0x2703,dispatcher);
extern pascal void WriteBParam () inline(0x0B03,dispatcher);
extern pascal void WriteBRam () inline(0x0903,dispatcher);
extern pascal void WriteTimeHex () inline(0x0E03,dispatcher);
extern pascal void AddToQueue () inline(0x2E03,dispatcher);
extern pascal void DeleteFromQueue () inline(0x2F03,dispatcher);
extern pascal void SetInterruptState () inline(0x3003,dispatcher);
extern pascal void GetInterruptState () inline(0x3103,dispatcher);
extern pascal Word GetIntStateRecSize () inline(0x3203,dispatcher);
extern MouseRec ReadMouse2();
extern pascal ProcPtr GetCodeResConverter () inline(0x3403,dispatcher);
extern pascal Pointer GetRomResource () inline(0x3503,dispatcher);
#endif

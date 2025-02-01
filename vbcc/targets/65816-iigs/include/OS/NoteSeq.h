/********************************************
; File: NoteSeq.h
;
;
; Copyright Apple Computer, Inc.1986-89
; All Rights Reserved
;
********************************************/
#ifndef __TYPES__
#include <Types.h>
#endif

#ifndef __NOTESEQ__
#define __NOTESEQ__

#define pitchBend 0x0L /*Command -  */
#define tempo 0x00000001L /*Command -  */
#define turnNotesOff 0x00000002L /*Command -  */
#define jump 0x00000003L /*Command -  */
#define setVibratoDepth 0x00000004L /*Command -  */
#define programChange 0x00000005L /*Command -  */
#define setRegister 0x00000006L /*Command -  */
#define ifGo 0x00000007L /*Command -  */
#define incRegister 0x00000008L /*Command -  */
#define decRegister 0x00000009L /*Command -  */
#define midiNoteOff 0x0000000AL /*Command -  */
#define midiNoteOn 0x0000000BL /*Command -  */
#define midiPolyKey 0x0000000CL /*Command -  */
#define midiCtlChange 0x0000000DL /*Command -  */
#define midiProgChange 0x0000000EL /*Command -  */
#define midiChnlPress 0x0000000FL /*Command -  */
#define midiPitchBend 0x00000010L /*Command -  */
#define midiSelChnlMode 0x00000011L /*Command -  */
#define midiSysExclusive 0x00000012L /*Command -  */
#define midiSysCommon 0x00000013L /*Command -  */
#define midiSysRealTime 0x00000014L /*Command -  */
#define midiSetSysExl 0x00000015L /*Command -  */
#define commandMask 0x0000007FL /*Command -  */
#define volumeMask 0x0000007FL /*Command -  */
#define chord 0x00000080L /*Command -  */
#define val1Mask 0x00007F00L /*Command -  */
#define toneMask 0x00007F00L /*Command -  */
#define noteMask 0x00008000L /*Command -  */
#define lByte 0x00FF0000L /*Command - meaning depends on midi command */
#define durationMask 0x07FF0000L /*Command -  */
#define trackMask 0x78000000L /*Command -  */
#define delayMask 0x80000000L /*Command -  */
#define hByte 0xFF000000L /*Command -  */
#define noRoomMidiErr 0x1A00 /*error -  */
#define noCommandErr 0x1A01 /*error - can't understand the current SeqItem */
#define noRoomErr 0x1A02 /*error - sequence is more than twelve levels deep */
#define startedErr 0x1A03 /*error - Note Sequencer is already started */
#define noNoteErr 0x1A04 /*error - can't find the note to be turned off by the current SeqItem */
#define noStartErr 0x1A05 /*error - Note Sequencer not started yet */
#define instBndsErr 0x1A06 /*error - Instrument number out of Instrument boundary range */
#define nsWrongVer 0x1A07 /*error - incompatible versions of NoteSequencer and NoteSynthesizer */
struct LocRec {
   Word curPhraseItem; /*  */
   Word curPattItem; /*  */
   Word curLevel; /*  */
} ;
typedef struct LocRec LocRec, *LocRecPtr, **LocRecHndl;
extern pascal void SeqBootInit () inline(0x011A,dispatcher);
extern pascal void SeqStartUp () inline(0x021A,dispatcher);
extern pascal void SeqShutDown () inline(0x031A,dispatcher);
extern pascal Word SeqVersion () inline(0x041A,dispatcher);
extern pascal void SeqReset () inline(0x051A,dispatcher);
extern pascal Boolean SeqStatus () inline(0x061A,dispatcher);
extern pascal void SeqAllNotesOff () inline(0x0D1A,dispatcher);
extern pascal Word ClearIncr () inline(0x0A1A,dispatcher);
extern pascal LocRec GetLoc () inline(0x0C1A,dispatcher);
extern pascal Word GetTimer () inline(0x0B1A,dispatcher);
extern pascal void SetIncr () inline(0x091A,dispatcher);
extern pascal void SetInstTable () inline(0x121A,dispatcher);
extern pascal void SetTrkInfo () inline(0x0E1A,dispatcher);
extern pascal void StartInts () inline(0x131A,dispatcher);
extern pascal void StartSeq () inline(0x0F1A,dispatcher);
extern pascal void StepSeq () inline(0x101A,dispatcher);
extern pascal void StopInts () inline(0x141A,dispatcher);
extern pascal void StopSeq () inline(0x111A,dispatcher);
extern pascal void StartSeqRel () inline(0x151A,dispatcher);
#endif

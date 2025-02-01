/********************************************
; File: Midi.h
;
;
; Copyright Apple Computer, Inc.1986-89
; All Rights Reserved
;
********************************************/
#ifndef __TYPES__
#include <Types.h>
#endif

#ifndef __MIDI__
#define __MIDI__

#define miToolNum 0x0020 /*Midi - the tool number of the MIDI Tool Set */
#define miDrvrFileType 0x00BB /*Midi - filetype of MIDI device driver */
#define miNSVer 0x0102 /*Midi - minimum version of Note Synthesizer required by MIDI Tool Set */
#define miSTVer 0x0203 /*Midi - minimum version of Sound Tools needed by MIDI Tool Set */
#define miDrvrAuxType 0x0300 /*Midi - aux type of MIDI device driver */
#define miStartUpErr 0x2000 /*Midi - MIDI Tool Set is not started  */
#define miPacketErr 0x2001 /*Midi - incorrect length for a received MIDI command */
#define miArrayErr 0x2002 /*Midi - a designated array had an insufficient or illegal size */
#define miFullBufErr 0x2003 /*Midi - input buffer overflow */
#define miToolsErr 0x2004 /*Midi - the required tools were not started up or had insufficient versions */
#define miOutOffErr 0x2005 /*Midi - MIDI output must first be enabled */
#define miNoBufErr 0x2007 /*Midi - no buffer is currently allocated */
#define miDriverErr 0x2008 /*Midi - the designated file is not a legal MIDI device driver */
#define miBadFreqErr 0x2009 /*Midi - the MIDI clock cannot attain the requested frequency */
#define miClockErr 0x200A /*Midi - the MIDI clock value wrapped to zero */
#define miConflictErr 0x200B /*Midi - conflicting processes for MIDI input */
#define miNoDevErr 0x200C /*Midi - no MIDI device driver loaded */
#define miDevNotAvail 0x2080 /*Midi - the requested device is not available */
#define miDevSlotBusy 0x2081 /*Midi - requested slot is already in use */
#define miDevBusy 0x2082 /*Midi - the requested device is already in use */
#define miDevOverrun 0x2083 /*Midi - device overrun by incoming MIDI data */
#define miDevNoConnect 0x2084 /*Midi - no connection to MIDI */
#define miDevReadErr 0x2085 /*Midi - framing error in received MIDI data */
#define miDevVersion 0x2086 /*Midi - ROM version is incompatible with device driver */
#define miDevIntHndlr 0x2087 /*Midi - conflicting interrupt handler is installed */
#define miSetClock 0x0000 /*MidiClock - set time stamp clock */
#define miStartClock 0x0001 /*MidiClock - start time stamp clock */
#define miStopClock 0x0002 /*MidiClock - stop time stamp clock */
#define miSetFreq 0x0003 /*MidiClock - set clock frequency */
#define miRawMode 0x00000000L /*MidiControl - raw mode for MIDI input and output */
#define miSetRTVec 0x0000 /*MidiControl - set real-time message vector */
#define miPacketMode 0x00000001L /*MidiControl - packet mode for MIDI input and output */
#define miSetErrVec 0x0001 /*MidiControl - set real-time error vector */
#define miStandardMode 0x00000002L /*MidiControl - standard mode for MIDI input and output */
#define miSetInBuf 0x0002 /*MidiControl - set input buffer information */
#define miSetOutBuf 0x0003 /*MidiControl - set output buffer information */
#define miStartInput 0x0004 /*MidiControl - start MIDI input */
#define miStartOutput 0x0005 /*MidiControl - start MIDI output */
#define miStopInput 0x0006 /*MidiControl - stop MIDI input */
#define miStopOutput 0x0007 /*MidiControl - stop MIDI output */
#define miFlushInput 0x0008 /*MidiControl - discard contents of input buffer */
#define miFlushOutput 0x0009 /*MidiControl - discard contents of output buffer */
#define miFlushPacket 0x000A /*MidiControl - discard next input packet */
#define miWaitOutput 0x000B /*MidiControl - wait for output buffer to empty */
#define miSetInMode 0x000C /*MidiControl - set input mode */
#define miSetOutMode 0x000D /*MidiControl - set output mode */
#define miClrNotePad 0x000E /*MidiControl - clear all notes marked on in the note pad */
#define miSetDelay 0x000F /*MidiControl - set minimum delay between output packets */
#define miOutputStat 0x0010 /*MidiControl - enable/disable output of running-status */
#define miIgnoreSysEx 0x0011 /*MidiControl - ignore system exclusive input */
#define miSelectDrvr 0x0000 /*MidiDevice - display device driver selection dialog */
#define miLoadDrvr 0x0001 /*MidiDevice - load and initialize device driver */
#define miUnloadDrvr 0x0002 /*MidiDevice - shutdown MIDI device, unload driver */
#define miNextPktLen 0x0 /*MidiInfo - return length of next packet */
#define miInputChars 0x0001 /*MidiInfo - return number of characters in input buffer */
#define miOutputChars 0x0002 /*MidiInfo - return number of characters in output buffer */
#define miMaxInChars 0x0003 /*MidiInfo - return maximum number of characters in input buffer */
#define miMaxOutChars 0x0004 /*MidiInfo - return maximum number of characters in output buffer */
#define miRecordAddr 0x0005 /*MidiInfo - return current MidiRecordSeq address */
#define miPlayAddr 0x0006 /*MidiInfo - return current MidiPlaySeq address */
#define miClockValue 0x0007 /*MidiInfo - return current time stamp clock value */
#define miClockFreq 0x0008 /*MidiInfo - return number of clock ticks per second */
#define midiInputPoll 0x00E101B2L /*MidiInputChannel - vector to poll MIDI input channel */

struct MiBufInfo {
   Word bufSize; /* size of buffer (0 for default) */
   Pointer address; /* address of buffer (0 for auto-allocation) */
} ;
typedef struct MiBufInfo MiBufInfo;
struct MiDriverInfo {
   Word slot; /* device slot */
   Word external; /* slot internal (=0) / external (=1) */
   Byte pathname[65]; /* device driver pathname */
} ;
typedef struct MiDriverInfo MiDriverInfo;
extern pascal void MidiBootInit () inline(0x0120,dispatcher);
extern pascal void MidiStartUp () inline(0x0220,dispatcher);
extern pascal void MidiShutDown () inline(0x0320,dispatcher);
extern pascal Word MidiVersion () inline(0x0420,dispatcher);
extern pascal void MidiReset () inline(0x0520,dispatcher);
extern pascal Boolean MidiStatus () inline(0x0620,dispatcher);
extern pascal void MidiClock () inline(0x0B20,dispatcher);
extern pascal void MidiControl () inline(0x0920,dispatcher);
extern pascal void MidiDevice () inline(0x0A20,dispatcher);
extern pascal LongWord MidiInfo () inline(0x0C20,dispatcher);
#define MidiInputPoll() asm { jsl 0xE11DD8} /* Not a true tool call. Made through its own vector */
extern pascal Word MidiReadPacket () inline(0x0D20,dispatcher);
extern pascal Word MidiWritePacket () inline(0x0E20,dispatcher);
#endif

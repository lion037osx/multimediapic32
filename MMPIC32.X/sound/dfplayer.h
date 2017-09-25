/* 
 * File:   dfplayer.h
 * Author: leo
 *
 * Created on September 24, 2017, 8:51 PM
 */

#ifndef DFPLAYER_H
#define	DFPLAYER_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define CMD_FOLDER_DFP   0x0F
#define NAME_FOLDER_DFP   0x01
#define NAME_FILE_DFP   0x01
#define CMD_END_DFP   0xEF    
#define CMD_START_BYTE_DFP 0x7E
#define CMD_VERSION_DFP 0xFF
#define CMD_N_BYTES_DFP 0x06
#define CMD_NEXT_DFP 0x1
#define CMD_PREVIOUS_DFP 0x2
#define CMD_SPECIFY_TRACKING_DFP 0x3
#define CMD_INCREASE_VOL_DFP 0x4
#define CMD_DECREASE_VOL_DFP 0x5    
#define CMD_SPECIFY_VOL_DFP 0x6
#define CMD_SPECIFY_EQUALIZER_DFP 0x7
#define CMD_SPECIFY_PLAYBACK_MODE_DFP 0x8    
#define CMD_SPECIFY_PLAYBACK_SOURCE_DFP 0x9
#define CMD_STBY_DFP 0xA    
#define CMD_NORMAL_WORK_DFP 0xB
#define CMD_RESET_MODULE_DFP 0xC    

    
void playDfp(void);
void playFolderDfp(void);


#ifdef	__cplusplus
}
#endif

#endif	/* DFPLAYER_H */


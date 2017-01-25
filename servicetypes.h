
#ifndef MOVGRAB_SERVICETYPES_H
#define MOVGRAB_SERVICETYPES_H

#include "common.h"

typedef enum {TYPE_NONE, TYPE_GENERIC, TYPE_YOUTUBE, TYPE_YOUTUBE_SHORT, TYPE_METACAFE, TYPE_DAILYMOTION, TYPE_BREAK_COM, TYPE_EHOW,  TYPE_VIMEO, TYPE_TED, TYPE_YALE, TYPE_REUTERS, TYPE_LIVELEAK, TYPE_PHOTOBUCKET,TYPE_WASHINGTONPOST,TYPE_CBSNEWS,TYPE_FRANCE24,TYPE_EURONEWS,TYPE_METATUBE,TYPE_GUARDIAN,TYPE_REDORBIT, TYPE_UCTV, TYPE_ROYALSOCIETY, TYPE_DOTSUB,TYPE_ASTRONOMYCOM, TYPE_DISCOVERY, TYPE_BLOOMBERG,TYPE_NATGEO,TYPE_VIDEOBASH,TYPE_SMH,TYPE_ANIMEHERE,TYPE_FUNNYORDIE,TYPE_IGN,TYPE_EBAUMSWORLD,
/*Following ones are not real types, but used by internal processes */
TYPE_BREAK_STAGE2, TYPE_VIMEO_STAGE2, TYPE_VIMEO_STAGE3, TYPE_CLIPSHACK_STAGE2, TYPE_CLIPSHACK_STAGE3, TYPE_VIDEOEMO_STAGE2,TYPE_MYVIDO1_STAGE2, TYPE_REFERENCE, TYPE_REDORBIT_STAGE2, TYPE_ASTRONOMYCOM_STAGE2,TYPE_CONTAINERFILE, TYPE_ANIMEHERE_STAGE2, TYPE_GOOGLE_URL, TYPE_YOUTUBE_PLAYLIST, TYPE_ROYALSOCIETY_STAGE2, TYPE_IGN_STAGE2, TYPE_M3U8_STREAM, TYPE_CONTAINERFILE_M3U8, TYPE_CONTAINERFILE_PLS, TYPE_CONTAINERFILE_ASX} TDT;

extern char *DownloadTypes[], *DownloadNames[], *TestLinks[];

int IdentifyServiceType(const char *Path);
char *SiteSpecificPreprocessing(char *RetBuf, char *Path, char *Proto, char *Server, int Port, char *Doc, int *Type, char **Title, int *Post);
int GetNextURL(int Type, char *Server, int Post, ListNode *Vars);
int ExtractItemInfo(STREAM *S, int Type, char *URL, char *Title, int Post);


#endif

#ifndef LIBUSEFUL_DATA_PROCESSING_H
#define LIBUSEFUL_DATA_PROCESSING_H

#include "includes.h"



#ifdef __cplusplus
extern "C" {
#endif


typedef struct t_dpmod TProcessingModule;

typedef int (*DATA_PROCESS_INIT_FUNC)(TProcessingModule *Mod, const char *Args);
typedef int (*DATA_PROCESS_RW_FUNC)(TProcessingModule *, const char *Data, int len, char **OutBuff, int *OutBuffLen, int Flush);
typedef int (*DATA_PROCESS_CLOSE_FUNC)(TProcessingModule *Mod);
typedef void (*DATA_PROGRESS_CALLBACK)(const char *Path, int bytes, int total);

#define DPM_READ_FINAL 1
#define DPM_WRITE_FINAL 2
#define DPM_NOPAD_DATA 4
#define DPM_PROGRESS 8

struct t_dpmod
{
char *Name;
char *Args;
int Flags;
char *ReadBuff, *WriteBuff;
int ReadSize, WriteSize;
int ReadUsed, WriteUsed;
int ReadMax, WriteMax;
ListNode *Values;
DATA_PROCESS_INIT_FUNC Init;
DATA_PROCESS_RW_FUNC Read;
DATA_PROCESS_RW_FUNC Write;
DATA_PROCESS_CLOSE_FUNC Close;
void *Data;
};


TProcessingModule *StandardDataProcessorCreate(const char *Class, const char *Name, const char *Arg);
int DataProcessorInit(TProcessingModule *ProcMod, const char *Key, const char *InputVector);
void DataProcessorDestroy(void *ProcMod);
char *DataProcessorGetValue(TProcessingModule *M, const char *Name);
void DataProcessorSetValue(TProcessingModule *M, const char *Name, const char *Value);


void InitialiseEncryptionComponents(const char *Args, char **CipherName, char **InputVector, int *InputVectorLen, char **Key, int *KeyLen, int *Flags);


int STREAMAddDataProcessor(STREAM *S, TProcessingModule *Mod, const char *Args);
int DataProcessorAvailable(const char *Class, const char *Name);
int STREAMAddStandardDataProcessor(STREAM *S, const char *Class, const char *Name, const char *Args);
int STREAMAddProgressCallback(STREAM *S, DATA_PROGRESS_CALLBACK CallBack);
void STREAMClearDataProcessors(STREAM *S);
int STREAMDeleteDataProcessor(STREAM *S, char *Class, char *Name);


#ifdef __cplusplus
}
#endif



#endif

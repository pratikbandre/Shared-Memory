#include "systemcalls.h"
#include "mmu.h"
#include <stdio.h>

int
shmget(int key, int size, int shmflg)
{
    // check whether the shared memory segment already exist or not
    // and if exist obtain the identifier of a previously created shared memory segment
    //and then
    if(shmflg==0 && key != IPC_PRIVATE){
        //return identifier
    }
    else if(key == IPC_PRIVATE){
        //create a segment of size PGROUNDUP(size)
    }
    else if(key != IPC_PRIVATE || shmflg == IPC_CREAT){
        //the segment corresponding to key does not exist
    }
    else if(shmflg == (IPC_CREAT | IPC_EXCL) && /*shared memory segment already exixts for key*/){
       // errno == EEXIST
    }
}

void*
shmat(int shmid, void* shmaddr, int shmflg)
{
    if(shmaddr == NULL){

    }
    else if((shmaddr != NULL) && (shmflg == SHM_RND)){
        //the attach occurs at the address equal to shmaddr rounded down to the nearest multiple of SHMLBA.
    }
    else{
        //shmaddr must be a page-aligned address at which the attach occurs.
    }
}

int
shmdt(void* shmaddr)
{
    if(shmaddr == /*value returned by the attaching shmat() call*/){
        //detach the shared memory segment located at the address specified by shmaddr from the address space of the calling process
    }
}

int
shmctl(int shmid, int cmd, struct shmid_ds *buf){
    if(cmd == IPC_STAT && /*the caller have read permisson on the shared memory segment*/){
        //Copy information from the kernel data structure associated with shmid into the shmid_ds structure pointed to by buf.
    }
    else if(cmd == IPC_SET){

    }
    else if(cmd == IPC_RMID){

    }
}

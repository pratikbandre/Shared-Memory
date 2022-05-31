#define IPC_CREAT 01000  //Create key if key does not exist.
#define IPC_EXCL 02000  //Fail if key exists.

#define IPC_PRIVATE 0

#define SHM_RDONLY  010000  //Read only permission during shmat()
#define	SHM_RND		020000	// round attach address to SHMLBA boundary
#define	SHM_REMAP	040000	// take-over region on attach
#define	SHM_EXEC	0100000	// execution access

#define IPC_RMID 0  //Remove identifier.
#define IPC_SET 1  //Set `ipc_perm' options.
#define IPC_STAT 2  //Get `ipc_perm' options.
#define IPC_INFO 3  //See ipcs.

#define SHMMAX 40960  //(40KB)Maximum size in bytes for a shared memory segment.
#define SHMMIN 1  //Minimum size in bytes for a shared memory segment(effectively 4096 B because page size is 4096 B)
#define SHMMNI 1024  //Minimum size in bytes for a shared memory segment(effectively 4096 B because page size is 4096 B)
#define SHMSEG 16  //Maximum number of segments that a process can attach
#define SHMALL 10240  //System-wide limit on the total amount of shared memory, measured in units of page size.

struct ipc_perm{
  int key;
  int rem;
  unsigned short mode;  //Permissions + SHM_DEST and SHM_LOCKED flags
};

struct shminformation{
  unsigned int shmmax;  // Maximum segment size
  unsigned int shmmin;  // Minimum segment size; always equal to 1
  unsigned int shmmaxseg;  // Maximum number of segments
  unsigned int shmseg;  // Maximum number of segments that a process can attach
  unsigned int shmall;  // Maximum number of pages of shared memory, system-wide
};

struct shmid_ds{
  struct ipc_perm shm_perm;  //Ownership and permissions
  struct shminformation shminfo;  //system wide shared memory limits
  int shm_segsz; //Size of segment (bytes)
  int shm_cpid;  //PID of creator
  int shm_lpid;  //PID of last shmat(2)/shmdt(2)
  int shm_nattch;  //No. of current attaches
};

struct global_shm{
  int key;
  int shmid;
  void * mem[10];
  struct shmid_ds shmid_ds;
}global_shm[SHMMNI];

int shmget(int key, int size, int shmflg);
void* shmat(int shmid, void* shmaddr, int shmflg);
int shmdt(void* shmaddr);
int shmctl(int shmid, int cmd, struct shmid_ds *buf);
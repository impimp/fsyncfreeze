#define _GNU_SOURCE

#include <stdio.h>
#include <dlfcn.h>
#include <unistd.h>
#define SLEEP_TIME 30

typedef int (*orig_fsync_int_type)(int fd);
typedef int (*orig_fdatasync_int_type)(int fd);


int fsync(int fd) {
	usleep( SLEEP_TIME * 1000000 );

	orig_fsync_int_type fsync_;
    fsync_ = (orig_fsync_int_type)dlsym(RTLD_NEXT,"fsync");
    return fsync_(fd);

}

int fdatasync(int fd) {
	usleep( SLEEP_TIME * 1000000 );

	orig_fdatasync_int_type fdatasync_;
    fdatasync_ = (orig_fdatasync_int_type)dlsym(RTLD_NEXT,"fdatasync");
    return fsync_(fd);

}


#ifndef _BGCC_MUTEX_H_
#define _BGCC_MUTEX_H_

#ifdef _WIN32
#include <Windows.h>
#else
#include <pthread.h>
#include <limits.h>
#endif

#include "bgcc_stdint.h"

#ifdef _WIN32
#define BGCC_MUTEX_WAIT_INFINITE INFINITE
#define bgcc_mutex_t HANDLE
#else
#define BGCC_MUTEX_WAIT_INFINITE UINT_MAX
#define bgcc_mutex_t pthread_mutex_t
#endif

namespace bgcc {

    class Mutex {
    public:
       
        Mutex();

    
        ~Mutex();

        int32_t lock(uint32_t millisecond = BGCC_MUTEX_WAIT_INFINITE);

      
        int32_t try_lock();

        int32_t unlock();

    protected:
     
        Mutex(const Mutex&);

     
        Mutex& operator=(const Mutex&);

    private:
        bgcc_mutex_t _mutex;

    }; // end of class Mutex

}

#endif // _BGCC_MUTEX_H_


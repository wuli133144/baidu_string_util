/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include "thread_manager.h"

//SharedPointer<Runnable> 就是智能引用指针
//防止内存泄露
namespace bgcc {

    SharedPointer<Thread> ThreadManager::createThread(SharedPointer<Runnable> pr) {
        SharedPointer<Thread> t(new Thread(pr));
        bool bOk = t->start();//运行
        return bOk ? t : SharedPointer<Thread>(NULL);
    }

}


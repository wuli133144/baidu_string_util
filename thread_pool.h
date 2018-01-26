/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_THREADPOOL_H_
#define _BGCC_THREADPOOL_H_

#include "runnable.h"
#include "sync_vector.h"
#include "thread_group.h"
#include "shareable.h"

namespace bgcc {

    /**
     * @class ThreadPool
     * @brief Ïß³Ì³ØÎ¬»¤Ò»×éÔ¤ÏÈ´´½¨ºÃµÄÏß³Ì¼°Ò»¸öÈÎÎñ¶ÓÁĞ¡£Ïß³ÌÒÀ´ÎÖ´ĞĞÈÎÎñ¶ÓÁĞÖĞµÄÈÎÎñ¡£
     */
     //ThreadPoolå…·æœ‰åŸå­æ€§ 
    class ThreadPool : public Shareable {
    private:
        class ThreadPoolRunner;
    public:
        /**
         * @class state_t
         * @brief Ïß³Ì³Ø×´Ì¬
         */
        enum state_t {
            UNINITIALIZED, INITIALIZED
        };

        /**
         * @brief   ¹¹Ôìº¯Êı
         * @param   
         * @return  
         */
        ThreadPool();

        /**
         * @brief   Îö¹¹º¯Êı
         * @param   
         * @return  
         */
        ~ThreadPool();

        /** Ïß³Ì³ØÖĞÄ¬ÈÏÏß³Ì¸öÊı */
        static const int DEFAULT_THREADS_NUM = 10;

        /**
         * @brief   ³õÊ¼»¯Ïß³Ì³Ø£¬´´½¨¹æ¶¨¸öÊıµÄÏß³Ì
         * @param   nThreads ´´½¨Ïß³ÌµÄ¸öÊı
         * @return  ³É¹¦·µ»Ø0
         */
        int init(int nThreads = DEFAULT_THREADS_NUM);

        /**
         * @brief   ÏòÈÎÎñ¶ÓÁĞÖĞÌí¼ÓÈÎÎñ
         * @param   pr ´ıÌí¼ÓµÄÈÎÎñ
         * @return  ³É¹¦·µ»Øtrue
         */
        bool addTask(RunnableSharedPointer pr);

        /**
         * @brief  µÈ´ıËùÓĞÏß³ÌÖ´ĞĞÍê±Ï¡£Çë²»Òªµ÷ÓÃ´Ë·½·¨£¬Ïß³Ì³ØÖĞµÄÏß³ÌÓÀÔ¶²»»á×Ô¶¯Ö´ĞĞ½áÊø
         * @param   
         * @return  
         */
        bool join();

        /**
         * @brief   »ñÈ¡Ïß³Ì¸öÊı
         * @param   
         * @return  µ±Ç°Ïß³Ì³ØÖĞÏß³Ì¸öÊı
         */
        size_t size();

        /**
         * @brief   ÖÕÖ¹ËùÓĞÏß³ÌµÄÖ´ĞĞ
         * @param   
         * @return  
         */
        bool terminate();
    private:
        /*
        * addWorker: ÏòÏß³Ì³ØÖĞÌí¼ÓnWorker¸öÏß³Ì
        */
        int addWorker(int nWorker);

        friend class ThreadPoolRunner;

        /* Ìí¼Óµ½Ïß³Ì³ØÖĞµÄÈÎÎñ */
        SyncVector<RunnableSharedPointer> _tasks;

        /* Ïß³Ì×é */
        ThreadGroup _threadGroup; //çº¿ç¨‹ç»„
        state_t _state;
    };
}

#endif // _BGCC_THREADPOOL_H_


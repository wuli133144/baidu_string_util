/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_GUARD_H_
#define _BGCC2_GUARD_H_

#include <stdlib.h>

namespace bgcc {

    /**
     * @brief 
     *
     * @tparam LockType
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012Äê05ÔÂ30ÈÕ 19Ê±19·Ö33Ãë
     */
    template <typename LockType>
        class Guard {
        public:
            /**
             * @brief Guard ¹¹Ôìº¯Êı£¬¶ÔMutex¼ÓËø
             *
             * @param lock ´ı¼ÓËøÖ¸Õë
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012Äê05ÔÂ30ÈÕ 19Ê±26·Ö09Ãë
             */
            Guard(LockType* lock) : _locked(false), _lock(lock) {
                if (NULL != _lock) {
                    if (0 == _lock->lock()) {
                        _locked = true;
                    }
                }
            }

            /**
             * @brief is_locked ¼ì²â¼ÓËøÊÇ·ñ³É¹¦
             *
             * @return ¼ÓËø³É¹¦·µ»Øtrue£»·ñÔò·µ»Øfalse
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012Äê05ÔÂ30ÈÕ 19Ê±26·Ö33Ãë
             */
            bool is_locked() const {
                return _locked;
            }

            /**
             * @brief ~Guard Îö¹¹º¯Êı£¬¶ÔMutex½âËø
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012Äê05ÔÂ30ÈÕ 19Ê±27·Ö12Ãë
             */
            ~Guard() {
                if (NULL != _lock) {
                    if (0 == _lock->unlock()) { //ä»£ç é£æ ¼ä¸é”™
                        _locked = false;
                    }
                }
            }
        private:
            mutable bool _locked; //åŠ é”
            LockType* _lock;      //é”æœºåˆ¶
        };
}

#endif // _BGCC2_GUARD_H_


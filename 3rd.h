#ifndef _RD_H
#define _RD_H

 
namespace util {

   #define  nullptr              NULL
   #define  CHECK_ISVALID(parm)  ((parm)==0)?true:false 
   #define  CHECK_PTR(ptr)       ((ptr)==(nullptr))?true:false
   

   #define   CONSTRUCTOR_DEFAULT(typename)       \
	          typename();                        \
	          ~typename();   
   


};// util

#endif // 3RD_H


 

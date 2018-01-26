				
				
				
			
                #include <iostream>   
                #include <string>    
	              #include <vector>
                #include <pthread.h>
                #include "base.h"
                #include "imple.h"
                #include "string_utils.h"
                #include "shareable.h"
                #include "guard.h"
                #include "mutex.h"
                #include "time_util.h"
                #include "thread_pool.h"
                #include "log.h"

                //#include ""
               
                
                #include "./smart_ptr/detail/spinlock.hpp"
                using namespace sofa::pbrpc;

                using namespace sofa::pbrpc::detail;
                using namespace bgcc;
                //#include "./base.h"
               
                using namespace test;
	              using namespace __model__;
                
                #define MAX_THREAD_NUM     10  

                int g_test=0,i=0;
                
                spinlock LOCK;

                typedef Guard<Mutex> scope_guard_t;
                Mutex mutex;

                //scope_guard_t Guard_dog(new Mutex());

                void * add(void * temp)
                {   
                          
                          int a=*(int*)(temp);
                          //LOCK.lock();
                          //Guard_dog;
                          //  scope_guard_t dog(new Mutex()); 
                          //while(i<10000) {
                              /* code */
                             //g_test++;

                          //   i++;
                          mutex.lock();
                          i++;
                          mutex.unlock();

                          cout<<"thread:"<<pthread_self()<<"i:"<<i<<endl;
                          // LOCK.unlock();
                          //}
                         
                         
                          return NULL;
                }

        
        //测试运行函数机制
         class  print_test_task: public Runnable
         {
             public:
                  print_test_task()
                  {}
                  ~print_test_task()
                  {}
                  virtual int32_t operator()(void *parm=NULL){
                         cout<<"hell worldxxxxxx wuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu"<<endl;
                         return -1;
                  }
         };


        	int main(int argc, char const *argv[])
        	{
             



              //log_open("bgcc.cfg");



        	/* code */
        	
        	// base * b=new base();
        	// if(b==NULL)
        	// {
        	// std::cout<<"new error"<<std::endl;
        	// return 1;
        	// }



        	//std::cout<<"new success"<<std::endl;

                string str("");
                str+="wuyujie";

                std::cout<<str<<endl; 

                int pos=str.find("yu",0);
                if(pos!=std::string::npos)
                {
                	/* code */
                	std::cout<<"yes "<<std::endl;
                 
                 //GCC_NOTICE(__LINE__,"find string %d");
                //BGCC_NOTICE("bgcc.cfg");
                }else
                {
                	 std::cout<<"no"<<std::endl;
                }

                //base * p=new base();
                //ase *b=new base();
                //base()

                base *p=new base();

                p->adduser(12);
                p->adduser(13);
                p->adduser(14);
                p->adduser(15);
                p->adduser(16);
                p->adduser(17);
                p->adduser(18);
                p->listuserinfo();

                p->removeuser(14);

                p->listuserinfo();

                //getuserinfo();
                //setname();
                
                userinfo *user=new userinfo();
                user->display();



                shared_ptr<userinfo>puser(user);

                puser->display();
                

                //userinfo *usr=new userinfo();
                 shared_ptr<userinfo>user_ptr(new userinfo);
                 cout<<"userinfo ref count:"<<user_ptr.use_count()<<endl;

                 shared_ptr<userinfo>user_ptr_cp=user_ptr;
                 cout<<"userinfo ref count:"<<user_ptr.use_count()<<endl;
                 

                 shared_ptr<string> pstr=make_shared<string>(MAX_THREAD_NUM,'a');

                 //cout<<*pstr<<endl;
                 cout<<"make_shared count:"<<pstr.use_count()<<endl;

                 shared_ptr<string>pstr_cp=make_shared<string>(MAX_THREAD_NUM,'b');

                 cout<<"make_shared  copy count:"<<pstr_cp.use_count()<<endl;
                 
                 pstr=pstr_cp;
                 cout<<" change make_shared count:"<<pstr.use_count()<<endl;
                 cout<<"change make_shared  copy count:"<<pstr_cp.use_count()<<endl;
                 
                 //cout<<pstr.unique()<<endl;

                 cout<<"change make_shared count:"<<pstr.unique()<<endl;
                 cout<<"change make_shared  cp count:"<<pstr_cp.unique()<<endl;



                 int *a=new int[100];

                 shared_ptr<int>sp1(a);
                 //shared_ptr<int>sp2(a);//error
                 string str_util("FAFDSFASD:fasdf:fasdkfjsadlkfj:fjksdfjxxx");
                 cout<<StringUtils::to_lower(str_util)<<endl;
                 
                 std::vector<string> m_vectorstr;
                 
                 string del(":");

                 StringUtils::split(str_util,del,&m_vectorstr);

                  if(m_vectorstr.empty())
                  {
                        cout<<"error string is empty()"<<endl;
                  }
                                
                  for(auto iter=m_vectorstr.begin();iter!=m_vectorstr.end();iter++)
                  {
                                cout<<*iter<<endl;
                  }
                  

                  //test replace

                  string str_util1("fdasfsda@fdskf#fjsdklf#j");

                  string oldstr("#f");         
                  string newstr("&&&&");
                  cout<<"replace str"<<StringUtils::replace(str_util1,oldstr,newstr)<<endl;
                  
                 


                  #ifndef  __linux__
                  
                  pthread_t pid[MAX_THREAD_NUM];

                  for(auto i=0;i<MAX_THREAD_NUM;i++)
                  {
                         pthread_create(&pid[i],NULL,add,&g_test);
                  }


                  for(auto i=0;i<MAX_THREAD_NUM;i++)
                  {
                        pthread_join(pid[i],NULL);
                  }

                  #endif 

                  
                  ThreadPool pool;
                  pool.init(MAX_THREAD_NUM);
                  //BGCC_NOTICE("find string %d",__LINE__);
                  for(int i=0;i<100;i++){

                    pool.addTask(RunnableSharedPointer(new print_test_task()));
                  }
                  //BGCC_NOTICE("find string %d",__LINE__);
                  //pool.addTask(new print_test_task());
                  //pool.addTask(new print_test_task());
                  //pool.addTask(new print_test_task());
                    pool.join();
                     

                    //cout<<">>>>>>>>>>>>end() main>>>>>>>>>>>>>>"<<endl;




                  return 0;
                                
        }
                                
                                
				
				
		
				

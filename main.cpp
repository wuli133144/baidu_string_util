				
				
				
			
                #include <iostream>   
                #include <string>    
	        #include <vector>
                #include "base.h"
                #include "imple.h"
                #include "string_utils.h"
                
                using namespace sofa::pbrpc;
                //#include "./base.h"
               
                using namespace test;
	        using namespace __model__;




		
				 

        	
        	int main(int argc, char const *argv[])
        	{



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
                 

                 shared_ptr<string> pstr=make_shared<string>(10,'a');

                 //cout<<*pstr<<endl;
                 cout<<"make_shared count:"<<pstr.use_count()<<endl;

                 shared_ptr<string>pstr_cp=make_shared<string>(10,'b');

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
                  return 0;
                                
        }
                                
                                
				
				
		
				

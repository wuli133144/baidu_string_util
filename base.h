			
			
			
			#ifndef BASE_H
			#define BASE_H
	        #ifdef  __cplusplus
		  
			#include <vector>
            #include <memory>
            #include <map>
            #include <algorithm>
            #include <hash_map>
            #include <cassert>
            #include "3rd.h"
            #else 
 
				#ifndef __cplusplus 
				#include <unistd.h>
				#include "errno.h"
				#endif 
            #endif 
            using namespace std;
            using namespace util;

			namespace test{
            
            // class userinfo:enable_from_this<userinfo>
            // {
            // public:
            // 	userinfo();
            // 	~userinfo();
            // private:
            // 	int user_id;
            // 	string user_name;
            // };
              
            
            class userinfo:public std::enable_shared_from_this<userinfo>
            {
            public:
            	userinfo(){}
            	~userinfo(){}

            	void func()
            	{

            		 shared_ptr<userinfo>ptest=shared_from_this();
            		 if(CHECK_PTR(ptest))
            		 { 
            		 	cout<<"this ==NULL"<<endl;
            		 	return;
            		 }
            		 ptest->display();

            	}
            	
            	// userinfo * get()
            	// {
            	// 	return shared_from_this();
            	// }
                //display()
            	void display()
            	{
            		cout<<"display"<<endl;
            	}   

            private:
            	typedef shared_ptr<userinfo> userinfo_ptr;
            	int user_Id;
            	string user_name;

            	
            };

            
            template<typename T>
            class Vector {
            private:
            	std::vector<T>m_vector;
            	/* data */
            public:
            	Vector(/* args */){}
            	~Vector(){
                       m_vector.clear();
            	}

                void push_back(T &data)
                {
                       m_vector.push_back(data);
                }

                int size()
                {
                	return m_vector.size();
                }

              #ifdef  _WIN32
                T &find(T &data)
                { 
                	 for(auto i=m_vector.begin();i!=m_vector.end();i++)
                	 {
                	 	 if((*i)==data)
                	 	 {
                	 	 	return data;//bug
                	 	 }
                	 }
                	 return -1;

                }
             #endif

                bool empty()
                {
                	return m_vector.empty();
                }
                
                void erase(T &data)
                {
                	return m_vector.erase(data);
                }
                
                T & operator[](int index)
                {
                	 int sz=size();
                	 //assert(index < 0 || index >= sz);
                	 return m_vector[index];

                }



            };

			class base
			{
			public:
					base(){}
					~base(){}
					//get userinfo
					std::vector<int>& getuserinfo()
					{
					    return m_userinfo;
					} 
					void setuserinfo(std::vector<int> v)
					{
						m_userinfo=v;
					}

					virtual void adduser(int userid)
					{
                             m_userinfo.push_back(userid);
					}

					virtual int removeuser(int userid)
					{
						      if(m_userinfo.empty())
						      {
                                      return 1;
						      }
						      vector<int>::iterator iter=find(m_userinfo.begin(),m_userinfo.end(),userid);
						      if(iter==m_userinfo.end())
						      {
						      	 return 1;
						      }
						      m_userinfo.erase(iter);
						      return 0;

					}
					void listuserinfo()const
					{
						 if(m_userinfo.empty())
						 {
						 	//fprintf(stderr, "%s\n", "[info] user info is empty");
						 	std::cout<<"user info is empty "<<endl;
						 	return;
						 }
                         
                         for(auto iter=m_userinfo.begin();iter!=m_userinfo.end();iter++)
                         {
                         	 std::cout<<"user:"<<*iter<<std::endl;
                         }
                           

					}

			private:
			
			       vector<int> m_userinfo;
			       typedef  map<int/*user id*/,string/*user name*/> userinfo_map_t;
			       typedef  map<int/*user id */,string /*user info*/>keyuserinfo_map_t; 

			
			};
			

			//test shared_ptr


			
			

			
			
			#endif // BASE_H
			
			
};			
			
			
			
			
			
			
			
			
			
			
			
			
			
			

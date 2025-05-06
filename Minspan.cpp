#include<iostream>
using namespace std;

class snode
{ 
  public:        
   char u1,u2;
   int wt;
};

class test
{
	 int n,m,x;
	 snode arr[10],res[10];
public:
	test()
	{
		n=0;
		m=1;
	}
   
     void inputsparse();
     void displaysparse();
     void bsort();
     void prims();
     void dispmst();
};

void test::dispmst()    
{
    for(int i=0;i<m;i++)
     {
         cout<<res[i].u1<<" "<<res[i].u2<<" "<<res[i].wt<<endl;
     }
}

 void test::prims()
{
	int cnt=0;
	int flag1,flag2,i;
     res[0]=arr[0];
     m=1;
    cnt=1;
 
 	do
 	{
         for(i=1; i<n  ; i++) 
         {
            flag1=0;
            flag2=0;
	        for(int j=0;j<m;j++)
	         {  			 
		      if((arr[i].u1==res[j].u1 || arr[i].u1==res[j].u2 ) && flag1==0) 
		      {
		          flag1++;		
		      }
		      if((arr[i].u2==res[j].u1 || arr[i].u2==res[j].u2 ) && flag2==0) 
		      {
		          flag2++;		        
		      }
		 	}		
		 			 
			if(flag1!=1  ^ flag2 !=1) 
			{

				 	res[m++]=arr[i];
				 			 				
			}		 		 		 	
			 
		 	
            }
            cnt = x-1;
    }while(m!=cnt)       ;
}           
           
         
 
 void test::inputsparse()
 {
 
 cout<<"Enter no. of edges: ";
 cin>>n;
 cout<<"Enter no. of vertices: ";
 cin>>x;
  for(int i=0;i<n;i++)
  {
      	cout<<"Enter 1st vertex: ";
     	cin>>arr[i].u1;
       	cout<<"Enter 2nd vertex: ";
      	cin>>arr[i].u2;
       	cout<<"Enter weight: ";
      	cin>>arr[i].wt;
      	cout<<endl;
    }  
    bsort();
 }

void test::displaysparse()
{
       for(int i=0;i<n;i++)
     {
         cout<<arr[i].u1<<" "<<arr[i].u2<<" "<<arr[i].wt<<endl;
     }
}

void test::bsort()
{
  snode temp;
     for(int i=0;i<n-1;i++)
     {
           for(int j=0;j<n-1-i;j++)
           {
               if(arr[j].wt>arr[j+1].wt)
               {
                   temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
           }
     }

}


int main()
{
   test obj;
   obj.inputsparse();
   obj.displaysparse();
   obj.prims();
   cout<<"Result:"<<endl;
   obj.dispmst();
return 0;
}

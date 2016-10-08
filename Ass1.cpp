//============================================================================
// Name        : Assignment_1.cpp
// Author      : 2453
// Version     : 1.0
// Copyright   : copyrights reserved by the author
// Description : Sets in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class set{
  //declare variables- these are by default private
	int tot_size,cric_size,bad_size,tot[40],cricket[20],badminton[20],res[40],i,j,r,size/*z[20],s[20],s3[20],*/;
	/*maximum size of set cricket and badminton is 20*/

  public:
    char ch;//ch set as public so that main() can use it as well.
 
  /*---because all functions are defined withing the scope of the class,
      there is no need for formal arguments, hence
      a lot of memory space is saved.----*/


  public:                 //declare functions as public so that main() has access
	void accept(){
        //accept total number of students, students playing cricket and badminton
		cout<<"Enter the total number of students:"<<endl
	    ;cin>>tot_size;
		cout<<"Enter students playing badminton:\n";
		cin>>bad_size;
		cout<<"Enter students playing cricket:\n";
		cin>>cric_size;
 
       total();//method total of the same class invoked, to make program more user-friendly and to avoid duplicate values in the universal set.

		cout<<"\nEnter roll numbers of students playing badminton and press enter key:\n";
		for( i=0;i<bad_size;i++){
              overwriting_duplicate_value_bad_array:           //the label allows overwriting of duplicate value, without incrementation of index i of badminton array.
              cin>>badminton[i];                              //data is input
              for(j=0;j<i;j++){
                   if(badminton[j]==badminton[i]){           //checks all the previous values with the current set value
                    goto jump;                             //if condition is satisfied then goes to label "jump" without exiting the 
                   }                                       //loop and without incrementing i value.
              }
         }
  
        jump:  
        if(i<bad_size){                     //verifies if i size does not exceed the badminton array size. 
            cout<<"\nERROR!! Duplicate input is not valid. Please re-enter the value and press enter key:";
            goto overwriting_duplicate_value_bad_array;   // if we do not put lines 50 & 51 in a condition statement, then the loop at line 38 goes on infinitely
        }

			/*	if(i!=0){
							if(badminton[i]==badminton[i--]){
								cout<<"redundant data!! Please input again";
								;cin>>badminton[i];//long syntactical error will occur if u put<<
							}
							}*/
	 
           /*-----------------------------------------------------------------------------
                         if you enter more numbers than bad_size,it gets saved to cricket array.Find a soln
            ------------------------------------------------------------------------------*/
		cout<<"Enter roll numbers of students playing cricket:\n";
	   for( i=0;i<cric_size;i++){
         overwriting_duplicate_value_cric_array:            //the label allows overwriting of duplicate value, without incrementation of index i of cric_array.
         cin>>cricket[i];                                  //data is input
         for(j=0;j<i;j++){
          if(cricket[j]==cricket[i]){                   //checks all the previous values with the current set value
          goto jump_to;                              //if condition is satisfied then goes to label "jump_to" without exiting the 
          }                                           //loop and without incrementing i value.
         }
       }
  
    jump_to:  
    if(i<cric_size){                     //verifies if i size does not exceed the cricket array size. 
    cout<<"\nERROR!! Duplicate input is not valid. Please re-enter the value and press enter key:";
    goto overwriting_duplicate_value_cric_array;   // if we do not put lines 77 & 78 in a condition statement, then the loop at line 65 goes on infinitely
    }






  }
	void display(){

		cout<<"Total students:"<<tot_size<<endl<<"Playing badminton:"<<bad_size<<endl;
		cout<<"Playing cricket:"<<cric_size<<endl;
        
        cout<<"Student roll numbers for badminton:";
       	for( i=0;i<bad_size;i++){
					cout<<badminton[i]<<" ";
				}
        cout<<"\nStudent roll numbers for cricket:";
				for( i=0;i<cric_size;i++){
					cout<<cricket[i]<<" ";
						}
  }
	void display_array(){
        //separately defined to enable resuability in order to display the result set based on conditions.
		  	cout<<"array is:";
        for( int m=0;m<r;m++){
					cout<<res[m]<<" ";
			   }  
	} 
  void final_display(){ //checks if result set is empty else sends data to display_array()

    if(r!=0){
            display_array();
     }//displaying the resultant set by invoking function display_array() of the same class
     else{
       cout<<"null"; //incase the result set has zero elements, it displays null
     }
  }
	void intersect(){
		int flag=0;
		r=0;//r is the counter for resulting array
		for(i=0;i<cric_size;i++){
			for(j=0;j<bad_size;j++){

                 if(cricket[i]==badminton[j]){  //condition to set flag=1 in the inner loop
                	flag=1;                      //since cricket is in the outer loop, badminton is compared with it
                	break;                      //while one value of i is kept constant
                  //breaks the inner loop, @ flag=1, as further comparison isn't necessary.
                }

			}
			if(flag==1){
		     res[r]=cricket[i];     //checks for flag==1 in the outer loop
			 r++;
			 flag=0;                // resets flag to zero for next value of i, or the next loop cycle
			}

		}


		 cout<<"\nResult set for intersection ";
	  final_display();
	}
	void union_set(){
		int flag=0;

		for(r=0;r<bad_size;r++){
			     res[r]=badminton[r];//the set which is taken in the inner loop of the nested loops is 
		}                           //first copied into resultant set.This is because inner loop index 
                                   //values keep changing over one loop cycle.

		r=bad_size;//to continue giving input after last filled index of res[]

		for(i=0;i<cric_size;i++){
			for(j=0;j<bad_size;j++){
                   if(cricket[i]==badminton[j]){

                	                          flag=1;
                	                          break; //escapes to outer loop, as further comparison isn't necessary.
                    }
			}
                  if(flag==0){
                                res[r]=cricket[i];//cricket is in the outer loop as we will 
                	            r++;             //set result values for the index which 
                                                //remains fixed over one loop cycle, here i<cric_size is that index.
                    }
			       flag=0; //resets flag=0 for next loop cycle

		}
        cout<<"\nFor union_of_sets  ";
		    display_array();      /*defined display_array function,with size of result set as formal argument,
                                 in the same class and invoked it again*/
        //displays the final array,its max size =r
  }
  void diff_cric_bad(){
    	int flag=0;
    	r=0;
    	for(i=0;i<cric_size;i++){//outer loop is the matrix from which common values are subtracted.
    		for(j=0;j<bad_size;j++){

    			if(cricket[i]==badminton[j]){
    				flag=1;  //on the detection of common values, program sets flag variable to 1
    				break;  // thus, breaking the inner loop, as further comparison isn't necessary.
    			}

    		}

    		if(flag==0){
    		    		res[r]=cricket[i];//sets value of result as element from matrix of outer loop when flag!=1
    		    		r++;
    		}
    		flag=0;//resets flag to 0, for the next loop cycle.
    	}
    	cout<<"\nFor set of cricket - badminton ";
      final_display();
  }
  void diff_bad_cric(){
    	int flag=0;
    	    	r=0;
    	    	for(i=0;i<bad_size;i++){//outer loop is the matrix from which common values are subtracted.
    	    		for(j=0;j<cric_size;j++){

    	    			if(cricket[i]==badminton[j]){
    	    				flag=1;//on the detection of common values, program sets flag variable to 1
    	    				break;// thus, breaking the inner loop, as further comparison isn't necessary.
    	    			}

    	    		}

    	    		if(flag==0){
    	    		    				res[r]=badminton[i];
    	    		    				r++;
    	    		    			}
    	    		flag=0;//resets flag to 0, for the next loop cycle.
    	    	}
    	    	cout<<"\nFor set of badminton - cricket ";

    	    	final_display();
  }
    
  void union_of_sets(){ 
      //method similar to union has been defined in order to 
     // invoke it again in the neither() method
      int flag=0;

      for(r=0;r<bad_size;r++){
            res[r]=badminton[r];
      }


      r=bad_size;//to continue giving input after last filled index of res[]

      for(i=0;i<cric_size;i++){
            for(j=0;j<bad_size;j++){
                   if(cricket[i]==badminton[j]){
                                              flag=1;
                                              break; //escapes to outer loop
                    }
            }
            if(flag==0){
                                res[r]=cricket[i];
                                r++;
            }
            flag=0; //resets flag=0 for next loop cycle

      }
  }
  void neither(){
    	int flag=0;
      int R=0;
    	union_of_sets();//this method writes union values of given two sets to 
                     //the set with which comparison is to be done.
    	int Result[40];//decides the max possible size of the resultant set as 40.

    	for(i=0;i<tot_size;i++){//tot_size is the net strength of the class.
    		for(j=0;j<r;j++){
    			if(tot[i]==res[j]){
                   flag=1;
                   break;
    		  }
    		}
    	    if(flag==0){
    			Result[R]=tot[i];//the vaues that are not common to class array 
                          //and union array are set in the array of neither
                         //that is the resultant set.
    			R++;

    		}
    	    flag=0;
    	}
    	cout<<"\nFor neither badminton nor cricket array is:";

    	for( int m=0;m<R;m++){
    		 cout<<Result[m]<<" ";
    	}

        cout<<"\nSize of array for neither Badminton nor Cricket is:";
        cout<<R;//The net size of the resultant array is printed.
  }
  void total(){

        /*---this method or function makes the program user friendly. 
          ---The user must enter only the starting roll number and the program
          ---increments and sets the array for total students by itself.
          ---hence,reducing the efforts of the user.
        */

          //the array representing all the roll numbers of the class is denoted by tot[]
        int sum;
        cout<<"Do the roll numbers increment by one?y/n";
        cin>>ch;// ch is used by main() as well as the member functions of the class set.
        if(ch=='y'){
            cout<<"Enter first roll number:";
            cin>>tot[0]; //the first element of tot[] is set by the user.
            sum=tot[0]; //this is copied to a variable that is incremented by 1 in every loop cycle.

                      for(i=1;i<tot_size;i++){
                          sum=sum+1;
                          tot[i]=sum;        
                      }
         }  
         else{
            int count;
            cout<<"Enter the difference between two consecutive roll numbers:";
            cin>>count; //count is the total incrementation required between two consecutive roll numbers.
            cout<<"Enter first roll number:";
            cin>>tot[0];
            sum=tot[0];
                      for(i=1;i<tot_size;i++){
                          sum=sum+count; //sum is the current roll number of the student,incremented by count with every loop cycle,
                          tot[i]=sum;   //which is set to the ith position of tot[]         
                    }

         }
        cout<<"\n Total student roll numbers in class are:\n";
            for(i=0;i<tot_size;i++){
                          cout<<tot[i]<<" ";             
            } 
  }
};


int main() {
	
      set obj;
	  do{
         obj.accept();
         obj.display();//function call using object of class set
         obj.intersect();
         obj.union_set();
         obj.diff_bad_cric();
         obj.diff_cric_bad();
         obj.neither();
         cout<<"\n do you want to continue?y/n";
         cin>>obj.ch;
	
      }while(obj.ch=='y');
	return 0;
}
/*
OutPut:
Enter the total number of students:
14
Enter students playing badminton:
1 
Enter students playing cricket:
5
Do the roll numbers increment by one?y/ny
Enter first roll number:1

 Total student roll numbers in class are:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 
Enter roll numbers of students playing badminton and press enter key:
5
Enter roll numbers of students playing cricket:
4
8
9
0
1
Total students:14
Playing badminton:1
Playing cricket:5
Student roll numbers for badminton:5 
Student roll numbers for cricket:4 8 9 0 1 
Result set for intersection null
For union_of_sets  array is:5 4 8 9 0 1 
For set of badminton - cricket array is:5 
For set of cricket - badminton array is:4 8 9 0 1 
For neither badminton nor cricket array is:2 3 6 7 10 11 12 13 14 
Size of array for neither Badminton nor Cricket is:9
 do you want to continue?y/nn
 Enter the total number of students:
12
Enter students playing badminton:
4
Enter students playing cricket:
6
Do the roll numbers increment by one?y/ny
Enter first roll number:1

 Total student roll numbers in class are:
1 2 3 4 5 6 7 8 9 10 11 12 
Enter roll numbers of students playing badminton and press enter key:
2
3
6
2

ERROR!! Duplicate input is not valid. Please re-enter the value and press enter key:7
Enter roll numbers of students playing cricket:
3
8
9
2
1
12
Total students:12
Playing badminton:4
Playing cricket:6
Student roll numbers for badminton:2 3 6 7 
Student roll numbers for cricket:3 8 9 2 1 12 
Result set for intersection array is:3 2 
For union_of_sets  array is:2 3 6 7 8 9 1 12 
For set of badminton - cricket array is:3 6 
For set of cricket - badminton array is:8 9 1 12 
For neither badminton nor cricket array is:4 5 10 11 
Size of array for neither Badminton nor Cricket is:4
 do you want to continue?y/n
 */

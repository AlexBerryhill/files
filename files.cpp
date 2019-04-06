/*************************************************************************
* Program:                                                                 
*    Assignment 26, Files                                                  
*    Brother Ridges, CS124                                                 
* Author:                                                                  
*    Alexander Berryhill                                                   
* Summary:                                                                 
*    This program will ask the user for a file name, then find the average
*    of the 10 numbers in that file.                                       
*                                                                          
*                                                                          
*                                                                          
*    Estimated:  0.5 hrs                                                   
*    Actual:     6.5 hrs                                                   
*      The most difficult part was learning how to get fin and my loop     
*      to work. Then finding a way to make my program less adaptable.      
*************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/*************************************************************************
 * getFileName will prompt the user for the files name and return it.      
 ************************************************************************/
void getFileName(char fileName[])
{
   int numOfNum;
   int nextNum;

   cout << "Please enter the filename: ";
      cin >> fileName;
   ifstream fin;
   fin.open(fileName);
   if (fin.fail())
   {
      cout << "Error reading file \"" << fileName << "\"\n";
   }
   else
   {
      while (fin >> nextNum)
      {
         numOfNum++;
      }
      if (numOfNum != 10)
      {
         cout << "Error reading file \"" << fileName << "\"\n";
      }
   }
   fin.close();
   return;
}

/*************************************************************************
 * readFile will find the 10 numbers in the file and return the average.   
 ************************************************************************/
float readFile(char fileName[])
{
   int numOfNum = 0;
   float totalNum = 0;
   ifstream fin;
   fin.open(fileName);

    float nextNum;
    while (fin >> nextNum)
   {
      totalNum += nextNum;
      numOfNum++;
   }
   if (numOfNum != 10)
   {
      return -100;
   }
   fin.close();

   return totalNum / numOfNum;
}

/*************************************************************************
 * display will display the average.                                       
 ************************************************************************/
void display(float average)
{
   if (average != -100)
   {
      cout.setf(ios::fixed);
      cout.precision(0);
      cout << "Average Grade: " << average << "%\n";
   }
   return;
}

/*************************************************************************
 * main will assign fileName to getFileName, have readFile fill in average
 * then have display display the average.                                  
 ************************************************************************/
int main()
{
   char fileName[256] = "failed";
   getFileName(fileName);
   if (fileName == "failed")
   {
      return 0;
   }
   float average = readFile(fileName);
   display(average);

   return 0;
}
# MPP-week-1-SecondAssignment

This project was written as Second Assignment for Modern Programing Paradigm course 

Consider the following function:
void alignArray ( int* array, int size, int barrier )
{
  for ( int i=0; i<size; i++ )
  {
    if ( array[i] < barrier ) array[i] += 2;  
    else if ( array[i] > barrier ) array[i] -= 2;
  }
}

Using this function as a basis, write a function template
that can work with arrays of any type.
• Declare a class that satisfies the requirements on actual
types from your template.
• Write an example: declare the array of class objects and
pass it to the function. Show both initial and final states of
the array.

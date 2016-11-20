// Program 6.4
int SequenceSearch(int search_key, int array[], int array_size)
{
    int p;
    int index = -1;
    // -1 means record is not found
    for(p=0; p<array_size; p++)
    {
        if(search_key == array[p])
       {
           index = p; // assign current array index
           break; // terminate searching
       } // end if
    } // end for
    return index; // return location of value
} // end function
